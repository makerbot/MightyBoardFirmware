/*
 * Copyright 2010 by Adam Mayer	 <adam@makerbot.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/atomic.h>
#include "Motherboard.hh"
#include "Configuration.hh"
#include "Steppers.hh"
#include "Planner.hh"
#include "Command.hh"
#include "Interface.hh"
#include "Commands.hh"
#include "Eeprom.hh"
#include "EepromMap.hh"
#include "SoftI2cManager.hh"
#include "Piezo.hh"
#include "RGB_LED.hh"
#include "Errors.hh"
#include <avr/eeprom.h>
#include <util/delay.h>


/// Set up the stepper pins on board creation
StepperInterface Motherboard::stepper[STEPPER_COUNT] = {
#if STEPPER_COUNT > 0
	StepperInterface(X_DIR_PIN,
	                 X_STEP_PIN,
	                 X_ENABLE_PIN,
	                 X_MAX_PIN,
	                 X_MIN_PIN,
	                 X_POT_PIN,
	                 eeprom_offsets::AXIS_INVERSION),
#endif
#if STEPPER_COUNT > 1
	StepperInterface(Y_DIR_PIN,
	                 Y_STEP_PIN,
	                 Y_ENABLE_PIN,
	                 Y_MAX_PIN,
	                 Y_MIN_PIN,
	                 Y_POT_PIN,
	                 eeprom_offsets::AXIS_INVERSION),
#endif
#if STEPPER_COUNT > 2
	StepperInterface(Z_DIR_PIN,
	                 Z_STEP_PIN,
	                 Z_ENABLE_PIN,
	                 Z_MAX_PIN,
	                 Z_MIN_PIN,
	                 Z_POT_PIN,
	                 eeprom_offsets::AXIS_INVERSION),
#endif
#if STEPPER_COUNT > 3
	StepperInterface(A_DIR_PIN,
	                 A_STEP_PIN,
	                 A_ENABLE_PIN,
	                 NullPin,
	                 NullPin,
	                 A_POT_PIN,
	                 eeprom_offsets::AXIS_INVERSION),
#endif
#if STEPPER_COUNT > 4
	StepperInterface(B_DIR_PIN,
	                 B_STEP_PIN,
	                 B_ENABLE_PIN,
	                 NullPin,
	                 NullPin,
	                 B_POT_PIN,
	                 eeprom_offsets::AXIS_INVERSION),
#endif
};

/// Instantiate static motherboard instance
Motherboard Motherboard::motherboard;

const Pin Ex1_Pwr = EX1_PWR;
const Pin Ex2_Pwr = EX2_PWR;

const Pin Ex1_Fan = EX1_FAN;
const Pin Ex2_Fan = EX2_FAN;

const Pin ThermocoupleCS1 = THERMOCOUPLE_CS1;
const Pin ThermocoupleCS2 = THERMOCOUPLE_CS2;

/// Create motherboard object
Motherboard::Motherboard() :
	lcd(),
	interfaceBoard(buttonArray,
	    lcd,
	    &mainMenu,
	    &monitorMode,
	    &messageScreen),
	platform_thermistor(PLATFORM_PIN,0),
	platform_heater(platform_thermistor, platform_element, SAMPLE_INTERVAL_MICROS_THERMISTOR,
	                eeprom_offsets::T0_DATA_BASE + toolhead_eeprom_offsets::HBP_PID_BASE, false), //TRICKY: HBP is only and anways on T0 for this machine
	using_platform(true),
	Extruder_One(0, Ex1_Pwr, Ex1_Fan, ThermocoupleCS1, eeprom_offsets::T0_DATA_BASE),
	Extruder_Two(1, Ex2_Pwr, Ex2_Fan, ThermocoupleCS2, eeprom_offsets::T1_DATA_BASE)
{
}

/// Reset the motherboard to its initial state.
/// This only resets the board, and does not send a reset
/// to any attached toolheads.
void Motherboard::reset(bool hard_reset) {
	indicateError(0); // turn on blinker

	// Configure the debug pins.
	DEBUG_PIN.setDirection(true);
	DEBUG_PIN1.setDirection(true);
	DEBUG_PIN2.setDirection(true);
	DEBUG_PIN3.setDirection(true);	

	// Init steppers
	uint8_t axis_invert = eeprom::getEeprom8(eeprom_offsets::AXIS_INVERSION, 0);
	SoftI2cManager::getI2cManager().init();
	// Z holding indicates that when the Z axis is not in
	// motion, the machine should continue to power the stepper
	// coil to ensure that the Z stage does not shift.
	// Bit 7 of the AXIS_INVERSION eeprom setting
	// indicates whether or not to use z holding; 
	// the bit is active low. (0 means use z holding,
	// 1 means turn it off.)
	bool hold_z = (axis_invert & (1<<7)) == 0;
	steppers::setHoldZ(hold_z);

	for (int i = 0; i < STEPPER_COUNT; i++) {
		stepper[i].init(i);
	}

	// Defaults are for the Replicator -Rob
	//X 94.1397046
	planner::setAxisStepsPerMM(eeprom::getEepromFixed32(eeprom_offsets::STEPS_PER_MM+ 0, 94.139704), 0);
	//Y 94.1397046             
	planner::setAxisStepsPerMM(eeprom::getEepromFixed32(eeprom_offsets::STEPS_PER_MM+ 4, 94.139704), 1);
	//Z 2560.0                 
	planner::setAxisStepsPerMM(eeprom::getEepromFixed32(eeprom_offsets::STEPS_PER_MM+ 8, 400.0), 2);
	//A 100.470957613814818    
	planner::setAxisStepsPerMM(eeprom::getEepromFixed32(eeprom_offsets::STEPS_PER_MM+12, 96.2752018), 3);
	//B 100.470957613814818    
	planner::setAxisStepsPerMM(eeprom::getEepromFixed32(eeprom_offsets::STEPS_PER_MM+16, 96.2752018), 4);


	// Master acceleraion
	planner::setAcceleration(eeprom::getEeprom32(eeprom_offsets::MASTER_ACCELERATION_RATE, DEFAULT_ACCELERATION));


	//X -- default conservative
	planner::setAxisAcceleration(eeprom::getEeprom32(eeprom_offsets::AXIS_ACCELERATION_RATES+ 0, DEFAULT_X_ACCELERATION), 0);
	//Y -- default conservative            
	planner::setAxisAcceleration(eeprom::getEeprom32(eeprom_offsets::AXIS_ACCELERATION_RATES+ 4, DEFAULT_Y_ACCELERATION), 1);
	//Z -- default conservative            
	planner::setAxisAcceleration(eeprom::getEeprom32(eeprom_offsets::AXIS_ACCELERATION_RATES+ 8, DEFAULT_Z_ACCELERATION), 2);
	//A -- default conservative            
	planner::setAxisAcceleration(eeprom::getEeprom32(eeprom_offsets::AXIS_ACCELERATION_RATES+12, DEFAULT_A_ACCELERATION), 3);
	//B -- default conservative            
	planner::setAxisAcceleration(eeprom::getEeprom32(eeprom_offsets::AXIS_ACCELERATION_RATES+16, DEFAULT_B_ACCELERATION), 4);


#ifdef CENTREPEDAL
	// uses the same eeprom address as the X/Y junction jerk~
	planner::setJunctionDeviation(eeprom::getEepromFixed32(eeprom_offsets::AXIS_JUNCTION_JERK+ 0, DEFAULT_JUNCTION_DEVIATION));
#else
	planner::setMaxXYJerk(eeprom::getEepromFixed32(eeprom_offsets::AXIS_JUNCTION_JERK+ 0, DEFAULT_MAX_XY_JERK));
#endif
	planner::setMaxAxisJerk(eeprom::getEepromFixed32(eeprom_offsets::AXIS_JUNCTION_JERK+ 4, DEFAULT_MAX_Z_JERK), 2);
	planner::setMaxAxisJerk(eeprom::getEepromFixed32(eeprom_offsets::AXIS_JUNCTION_JERK+ 8, DEFAULT_MAX_A_JERK), 3);
	planner::setMaxAxisJerk(eeprom::getEepromFixed32(eeprom_offsets::AXIS_JUNCTION_JERK+12, DEFAULT_MAX_B_JERK), 4);

	planner::setMinimumPlannerSpeed(eeprom::getEepromFixed32(eeprom_offsets::MINIMUM_PLANNER_SPEED, DEFAULT_MINIMUM_PLANNER_SPEED));

	// Initialize the host and slave UARTs
	UART::getHostUART().enable(true);
	UART::getHostUART().in.reset();

// initialize the extruders
	Extruder_One.reset();
	Extruder_Two.reset();

	Extruder_One.getExtruderHeater().set_target_temperature(0);
	Extruder_Two.getExtruderHeater().set_target_temperature(0);
	platform_heater.set_target_temperature(0);
		
	// Reset and configure timer 0, the piezo buzzer timer
	// Mode: Phase-correct PWM with OCRnA (WGM2:0 = 101)
	// Prescaler: set on call by piezo function
	TCCR0A = 0b01;//0b00000011; ////// default mode off / phase correct piezo   
	TCCR0B = 0b01;//0b00001001; //default pre-scaler 1/1
	OCR0A = 0;
	OCR0B = 0;
	TIMSK0 = 0b00000000; //interrupts default to off   

	// Reset and configure timer 3, the microsecond and stepper
	// interrupt timer.
	TCCR3A = 0x00;
	TCCR3B = 0x09;
	TCCR3C = 0x00;
	OCR3A = INTERVAL_IN_MICROSECONDS * 16;
	TIMSK3 = 0x02; // turn on OCR3A match interrupt

	// Reset and configure timer 2, the debug LED flasher timer.
	TCCR2A = 0x00;
	TCCR2B = 0x07; // prescaler at 1/1024
	TIMSK2 = 0x01; // OVF flag on

	// reset and configure timer 5, the HBP PWM timer
	// not currently being used
	TCCR5A = 0b00000000;  
	TCCR5B = 0b00000010; /// set to PWM mode
	OCR5A = 0;
	OCR5B = 0;
	TIMSK5 = 0b00000000; // no interrupts needed

	// reset and configure timer 1, the Extruder Two PWM timer
	// Mode: Phase-correct PWM with OCRnA(WGM3:0 = 1011), cycle freq= 976 Hz
	// Prescaler: 1/64 (250 KHz)
	TCCR1A = 0b00000011;  
	TCCR1B = 0b00010011; /// set to PWM mode
	OCR1A = 0;
	OCR1B = 0;
	TIMSK1 = 0b00000000; // no interrupts needed

	// reset and configure timer 4, the Extruder One PWM timer
	// Mode: Phase-correct PWM with OCRnA (WGM3:0 = 1011), cycle freq= 976 Hz
	// Prescaler: 1/64 (250 KHz)
	TCCR4A = 0b00000011;  
	TCCR4B = 0b00010011; /// set to PWM mode
	OCR4A = 0;
	OCR4B = 0;
	TIMSK4 = 0b00000000; // no interrupts needed

	// Check if the interface board is attached
	hasInterfaceBoard = interface::isConnected();

	if (hasInterfaceBoard) {
		// Make sure our interface board is initialized
		interfaceBoard.init();

	// start with welcome script if the first boot flag is not set
		if(eeprom::getEeprom8(eeprom_offsets::FIRST_BOOT_FLAG, 0) == 0)
			interfaceBoard.pushScreen(&welcomeScreen);
		else
	// otherwise start with the splash screen.
			interfaceBoard.pushScreen(&splashScreen);

		if(hard_reset)
			_delay_us(3000000);


        // Finally, set up the interface
        interface::init(&interfaceBoard, &lcd);

        interface_update_timeout.start(interfaceBoard.getUpdateRate());
    }
    
    // interface LEDs default to full ON
    interfaceBlink(0,0);
    
    // only call the piezo buzzer on full reboot start up
    // do not clear heater fail messages, though the user should not be able to soft reboot from heater fail
    if(hard_reset)
	{
		RGB_LED::init();
		
		Piezo::startUpTone();
		
		heatShutdown = false;
		heatFailMode = HEATER_FAIL_NONE;
		cutoff.init();
	} 		

	RGB_LED::setDefaultColor(); 
	HBP_HEAT.setDirection(true);
	platform_thermistor.init();
	platform_heater.reset();
	buttonWait = false;	

}

/// Get the number of microseconds that have passed since
/// the board was booted.
micros_t Motherboard::getCurrentMicros() {
	micros_t micros_snapshot;
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
		micros_snapshot = micros;
	}
	return micros_snapshot;
}

/// Run the motherboard interrupt
void Motherboard::doInterrupt() {

	micros += INTERVAL_IN_MICROSECONDS;
	// Do not move steppers if the board is in a paused state
	if (command::isPaused()) return;
	steppers::doInterrupt();
	
    // if cutoff trigger line is high
	if(cutoff.isCutoffActive())
	{
        // call noise response routine.  This will return true if the 
        // cutoff trigger is persistent and not a spike
		if(!cutoff.noiseResponse()){
			heatShutdown = true;
			heatFailMode = HEATER_FAIL_HARDWARE_CUTOFF;
		}
	}	
}
bool connectionsErrorTriggered = false;
void Motherboard::heaterFail(HeaterFailMode mode){

    // record heat fail mode
	heatFailMode = mode;
    
	if(heatFailMode == HEATER_FAIL_NOT_PLUGGED_IN)
	{
		// if single tool, one heater is not plugged in on purpose
		// do not trigger a heatFail message unless both heaters are unplugged 
		if(!platform_heater.has_failed() && eeprom::isSingleTool() && 
			(!(Extruder_One.getExtruderHeater().has_failed() && Extruder_Two.getExtruderHeater().has_failed())))
				return;
        // only fire the heater not connected error once.  The user should be able to dismiss this one
		else if (connectionsErrorTriggered)
			return;
		else
			connectionsErrorTriggered =true;
	}
    
    // flag heat shutdown response
	heatShutdown = true;
}

// Motherboard class waits for a button press from the user
// used for firmware initiated error reporting
void Motherboard::startButtonWait(){
    // blink the interface LEDs
	interfaceBlink(25,15);
    
	interfaceBoard.waitForButton(0xFF);
	buttonWait = true;

}

// set an error message on the interface and wait for user button press
void Motherboard::errorResponse(char msg[]){
	interfaceBoard.errorMessage(msg);
	startButtonWait();
}

bool triggered = false;
// main motherboard loop
void Motherboard::runMotherboardSlice() {
    
    // check for user button press
    // update interface screen as necessary
	if (hasInterfaceBoard) {
		interfaceBoard.doInterrupt();
		if (interface_update_timeout.hasElapsed()) {
                        interfaceBoard.doUpdate();
                        interface_update_timeout.start(interfaceBoard.getUpdateRate());
		}
	}
        
    if(isUsingPlatform()) {
            // manage heating loops for the HBP
			   platform_heater.manage_temperature();
		}
	
    // if waiting on button press
	if(buttonWait)
	{
        // if user presses enter
		if (interfaceBoard.buttonPushed()) {
                // set interface LEDs to solid
				interfaceBlink(0,0);
                // restore default LED behavior
				RGB_LED::setDefaultColor();
                //clear error messaging
				buttonWait = false;
				interfaceBoard.popScreen();
				triggered = false;
		}
		
	}
	
	// if no user input for USER_INPUT_TIMEOUT, shutdown heaters and warn user
    // don't do this if a heat failure has occured ( in this case heaters are already shutdown and separate error messaging used)
	if(user_input_timeout.hasElapsed() && !heatShutdown)
	{
        // clear timeout
		user_input_timeout.clear();
		
		// alert user if heaters are not already set to 0
		if((Extruder_One.getExtruderHeater().get_set_temperature() > 0) ||
			(Extruder_Two.getExtruderHeater().get_set_temperature() > 0) ||
			(platform_heater.get_set_temperature() > 0)){
				interfaceBoard.errorMessage("Heaters shutdown    due to inactivity");//37
				startButtonWait();
                // turn LEDs blue
				RGB_LED::setColor(0,0,255, true);
		}
        // set tempertures to 0
		Extruder_One.getExtruderHeater().set_target_temperature(0);
		Extruder_Two.getExtruderHeater().set_target_temperature(0);
		platform_heater.set_target_temperature(0);
	}
	
    // respond to heatshutdown.  response only needs to be called once
	if(heatShutdown && !triggered && !Piezo::isPlaying())
	{
        triggered = true;
		// rgb led response
		interfaceBlink(10,10);
        // set all heater temperatures to zero
        Extruder_One.getExtruderHeater().set_target_temperature(0);
		Extruder_Two.getExtruderHeater().set_target_temperature(0);
		platform_heater.set_target_temperature(0);
		/// error message
		switch (heatFailMode){
			case HEATER_FAIL_SOFTWARE_CUTOFF:
				interfaceBoard.errorMessage("Extruder Overheat!  Software Temp Limit Reached! Please     Shutdown or Restart");//,79);
				break;
			case HEATER_FAIL_HARDWARE_CUTOFF:
				interfaceBoard.errorMessage("Extruder Overheat!  Safety Cutoff       Triggered! Please   Shutdown or Restart");//,79);
				break;
			case HEATER_FAIL_NOT_HEATING:
				interfaceBoard.errorMessage("Heating Failure!    My extruders are notheating properly.   Check my connections");//,79);
				break;
			case HEATER_FAIL_DROPPING_TEMP:
				interfaceBoard.errorMessage("Heating Failure!    My extruders are    losing temperature.  Check my connections");//,79);
				break;
			case HEATER_FAIL_NOT_PLUGGED_IN:
				interfaceBoard.errorMessage("Heater Error!       My temperature reads are failing! PleaseCheck my connections");//,79);
				startButtonWait();
				heatShutdown = false;
				return;
		}
        // blink LEDS red
		RGB_LED::errorSequence();
		// disable command processing and steppers
		host::heatShutdown();
		command::heatShutdown();
		interfaceBoard.lock();
		planner::abort();
		for(int i = 0; i < STEPPER_COUNT; i++)
			steppers::enableAxis(i, false);
	}
		       
	// Temperature monitoring thread
	Extruder_One.runExtruderSlice();
	Extruder_Two.runExtruderSlice();
}

// reset user timeout to start from zero
void Motherboard::resetUserInputTimeout(){
	user_input_timeout.start(USER_INPUT_TIMEOUT);
}


/// Timer one comparator match interrupt
ISR(TIMER3_COMPA_vect) {
	Motherboard::getBoard().doInterrupt();
}

/// Number of times to blink the debug LED on each cycle
volatile uint8_t blink_count = 0;

/// number of cycles to hold on and off in each interface LED blink
uint8_t interface_on_time = 0;
uint8_t interface_off_time = 0;

/// The current state of the debug LED
enum {
	BLINK_NONE,
	BLINK_ON,
	BLINK_OFF,
	BLINK_PAUSE
};

/// state trackers for blinking LEDS
int blink_state = BLINK_NONE;
int interface_blink_state = BLINK_NONE;

/// Write an error code to the debug pin.
void Motherboard::indicateError(int error_code) {
	if (error_code == 0) {
		blink_state = BLINK_NONE;
		DEBUG_PIN.setValue(false);
	}
	else if (blink_count != error_code) {
		blink_state = BLINK_OFF;
	}
	blink_count = error_code;
}

// set on / off period for blinking interface LEDs
// if both times are zero, LEDs are full on, if just on-time is zero, LEDs are full OFF
void Motherboard::interfaceBlink(int on_time, int off_time){
	
	if(off_time == 0){
		interface_blink_state = BLINK_NONE;
		interface::setLEDs(true);
	}else if(on_time == 0){
		interface_blink_state = BLINK_NONE;
		interface::setLEDs(false);
	} else{
		interface_on_time = on_time;
		interface_off_time = off_time;
		interface_blink_state = BLINK_ON;
	}

}

/// Get the current error code.
uint8_t Motherboard::getCurrentError() {
	return blink_count;
}

/// Timer2 overflow cycles that the LED remains on while blinking
#define OVFS_ON 18
/// Timer2 overflow cycles that the LED remains off while blinking
#define OVFS_OFF 18
/// Timer2 overflow cycles between flash cycles
#define OVFS_PAUSE 80

/// Number of overflows remaining on the current blink cycle
int blink_ovfs_remaining = 0;
/// Number of blinks performed in the current cycle
int blinked_so_far = 0;
/// Number of overflows remaining on the current overflow blink cycle
int interface_ovfs_remaining = 0;

/// Timer 2 overflow interrupt
ISR(TIMER2_OVF_vect) {
	/// Debug LEDS on Motherboard
	if (blink_ovfs_remaining > 0) {
		blink_ovfs_remaining--;
	} else {
		if (blink_state == BLINK_ON) {
			blinked_so_far++;
			blink_state = BLINK_OFF;
			blink_ovfs_remaining = OVFS_OFF;
			DEBUG_PIN.setValue(false);
		} else if (blink_state == BLINK_OFF) {
			if (blinked_so_far >= blink_count) {
				blink_state = BLINK_PAUSE;
				blink_ovfs_remaining = OVFS_PAUSE;
			} else {
				blink_state = BLINK_ON;
				blink_ovfs_remaining = OVFS_ON;
				DEBUG_PIN.setValue(true);
			}
		} else if (blink_state == BLINK_PAUSE) {
			blinked_so_far = 0;
			blink_state = BLINK_ON;
			blink_ovfs_remaining = OVFS_ON;
			DEBUG_PIN.setValue(true);
		}
	}
	/// Interface Board LEDs
	if( interface_ovfs_remaining > 0){
		interface_ovfs_remaining--;
	} else {
		if (interface_blink_state == BLINK_ON) {
			interface_blink_state = BLINK_OFF;
			interface_ovfs_remaining = interface_on_time;
			interface::setLEDs(true);
		} else if (interface_blink_state == BLINK_OFF) {
			interface_blink_state = BLINK_ON;
			interface_ovfs_remaining = interface_off_time;
			interface::setLEDs(false);
		}
	} 
}

// piezo buzzer update
// this interrupt gets garbled with the much more rapid stepper interrupt
ISR(TIMER0_COMPA_vect)
{
  Piezo::doInterrupt();
}

// HBP PWM
void pwmHBP_On(bool on) {
	if (on) {
		TCCR5A |= 0b00100000; /// turn on OC5B PWM output
	} else {
		TCCR5A &= 0b11001111; /// turn off OC5B PWM output
	}
}


void Motherboard::setUsingPlatform(bool is_using) {
  using_platform = is_using;
}

void Motherboard::setValve(bool on) {
  	ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
		//setUsingPlatform(false);
		//pwmHBP_On(false);
		EXTRA_FET.setDirection(true);
		EXTRA_FET.setValue(on);
	}
}

void BuildPlatformHeatingElement::setHeatingElement(uint8_t value) {
	// This is a bit of a hack to get the temperatures right until we fix our
	// PWM'd PID implementation.  We reduce the MV to one bit, essentially.
	// It works relatively well.
  	ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
		pwmHBP_On(false);
		HBP_HEAT.setValue(value != 0);
	}
  
}




 /** Copyright 2010 by Adam Mayer <adam@makerbot.com>
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

#include "EepromMap.hh"
#include "Eeprom.hh"
#include <avr/eeprom.h>
#include <util/delay.h>

//for thermistor generation
#include "TemperatureTable.hh"

// for sound definition
#include "Piezo.hh"

// for LED definition
#include "RGB_LED.hh"

// for cooling fan definition
#include "CoolingFan.hh"

namespace eeprom {

#define DEFAULT_P_VALUE  (9.0f)
#define DEFAULT_I_VALUE  (0.250f)
#define DEFAULT_D_VALUE  (10.0f)


#define THERM_R0_DEFAULT_VALUE (100000)
#define THERM_T0_DEFAULT_VALUE (25)
#define THERM_BETA_DEFAULT_VALUE (4067)


/**
 *
 * @param eeprom_base start of eeprom map of cooling settings
 */
void setDefaultCoolingFan(uint16_t eeprom_base){

	uint8_t fan_settings[] = {1, DEFAULT_COOLING_FAN_SETPOINT_C};
  eeprom_write_block( fan_settings, (uint8_t*)(eeprom_base + cooler_eeprom_offsets::ENABLE),2);
}


/**
 * Start of PID block of EEPROM. Can be extruder or HPB
 * @param eeprom_base
 */
void setDefaultPID(uint16_t eeprom_base)
{
	setEepromFixed16(( eeprom_base + pid_eeprom_offsets::P_TERM ), DEFAULT_P_VALUE);
	setEepromFixed16(( eeprom_base + pid_eeprom_offsets::I_TERM ), DEFAULT_I_VALUE);
	setEepromFixed16(( eeprom_base + pid_eeprom_offsets::D_TERM ), DEFAULT_D_VALUE);
}


/**
 *
 * @param index
 * @param eeprom_base start of this extruder's data in the eeprom
 */
void setDefaultsExtruder(int index,uint16_t eeprom_base)
{
	uint8_t featuresT0 = eeprom_info::HEATER_0_PRESENT | eeprom_info::HEATER_0_THERMISTOR | eeprom_info::HEATER_0_THERMOCOUPLE;
	uint8_t featuresT1 = eeprom_info::HEATER_1_PRESENT | eeprom_info::HEATER_1_THERMISTOR | eeprom_info::HEATER_1_THERMOCOUPLE;
	if( index == 0 ){
		uint8_t slaveId = 12;
	  eeprom_write_byte( (uint8_t*)(eeprom_base + toolhead_eeprom_offsets::FEATURES),featuresT0);
		eeprom_write_byte( (uint8_t*)eeprom_base +toolhead_eeprom_offsets::SLAVE_ID,slaveId);
	}
	else{
		uint8_t slaveId = 32;
		eeprom_write_byte( (uint8_t*)(eeprom_base + toolhead_eeprom_offsets::FEATURES),featuresT1);
		eeprom_write_byte( (uint8_t*)eeprom_base +toolhead_eeprom_offsets::SLAVE_ID,slaveId);
	}
	setDefaultPID((eeprom_base + toolhead_eeprom_offsets::EXTRUDER_PID_BASE) );
  setDefaultPID((eeprom_base + toolhead_eeprom_offsets::HBP_PID_BASE) );
  setDefaultCoolingFan(eeprom_base + toolhead_eeprom_offsets::COOLING_FAN_SETTINGS);

  eeprom_write_word((uint16_t*)(eeprom_base + toolhead_eeprom_offsets::BACKOFF_FORWARD_TIME),500);
  eeprom_write_word((uint16_t*)(eeprom_base + toolhead_eeprom_offsets::BACKOFF_STOP_TIME),5);
  eeprom_write_word((uint16_t*)(eeprom_base + toolhead_eeprom_offsets::BACKOFF_REVERSE_TIME),500);
  eeprom_write_word((uint16_t*)(eeprom_base + toolhead_eeprom_offsets::BACKOFF_TRIGGER_TIME),300);
}


/**
 * Set thermal table offsets
 * @param eeprom_base
 */
void SetDefaultsThermal(uint16_t eeprom_base)
{
	eeprom_write_dword( (uint32_t*)(eeprom_base + therm_eeprom_offsets::THERM_R0), THERM_R0_DEFAULT_VALUE);
	eeprom_write_dword( (uint32_t*)(eeprom_base + therm_eeprom_offsets::THERM_T0), THERM_T0_DEFAULT_VALUE);
	eeprom_write_dword( (uint32_t*)(eeprom_base + therm_eeprom_offsets::THERM_BETA), THERM_BETA_DEFAULT_VALUE);

}

typedef struct Color {
	int8_t red;
	int8_t green;
	int8_t blue;
} Color;
        


/**
 *
 * @param eeprom_base start of Led effects table
 */
void setDefaultLedEffects(uint16_t eeprom_base)
{
	Color colors;

	// default color is white
	eeprom_write_byte((uint8_t*)(eeprom_base + blink_eeprom_offsets::BASIC_COLOR), LED_DEFAULT_WHITE);
	eeprom_write_byte((uint8_t*)(eeprom_base + blink_eeprom_offsets::LED_HEAT_ON), 1);
    
	colors.red=0xFF; colors.green =colors.blue =0x00;
	eeprom_write_block((void*)&colors,(uint8_t*)(eeprom_base + blink_eeprom_offsets::CUSTOM_COLOR),sizeof(colors));
}
    /**
     *
     * @param red value
     * @param green value
     * @param blue value
     */

void setCustomColor(uint8_t red, uint8_t green, uint8_t blue){
	
	Color colors;

  ATOMIC_BLOCK(ATOMIC_RESTORESTATE){  	
	eeprom_write_byte((uint8_t*)(eeprom_offsets::LED_STRIP_SETTINGS + blink_eeprom_offsets::BASIC_COLOR), LED_DEFAULT_CUSTOM);
	
	colors.red=red; colors.green = green; colors.blue =blue;
	eeprom_write_block((void*)&colors,(uint8_t*)(eeprom_offsets::LED_STRIP_SETTINGS + blink_eeprom_offsets::CUSTOM_COLOR),sizeof(colors));
}
}

    /**
     *
     * @param sound desired
     * @param dest in eeprom
     */   
void eeprom_write_sound(Sound sound, uint16_t dest)
{
	eeprom_write_word((uint16_t*)dest, 	sound.freq);
	eeprom_write_word((uint16_t*)dest + 2, sound.durationMs);
}

/**
 *
 * @param eeprom_base start of buzz effects table
 */
void setDefaultBuzzEffects(uint16_t eeprom_base)
{
	eeprom_write_byte((uint8_t*)(eeprom_base + buzz_eeprom_offsets::SOUND_ON), 1);
}
    
/**
 *
 * @param eeprom_base start of preheat settings table
 */
void setDefaultsPreheat(uint16_t eeprom_base)
{
    eeprom_write_word((uint16_t*)(eeprom_base + preheat_eeprom_offsets::PREHEAT_RIGHT_TEMP), 230);
    eeprom_write_word((uint16_t*)(eeprom_base + preheat_eeprom_offsets::PREHEAT_LEFT_TEMP), 230);
    eeprom_write_word((uint16_t*)(eeprom_base + preheat_eeprom_offsets::PREHEAT_PLATFORM_TEMP), 110);
    eeprom_write_byte((uint8_t*)(eeprom_base + preheat_eeprom_offsets::PREHEAT_ON_OFF), (1<<HEAT_MASK_RIGHT) + (1<<HEAT_MASK_PLATFORM));
}


/**
 *
 * break with the form here as eeprom_base is available in class and we
 * want to cleanly call this function externally
 */
void setDefaultsAcceleration()
{

    eeprom_write_byte((uint8_t *) (eeprom_offsets::ACCELERATION_SETTINGS + acceleration_eeprom_offsets::ACCELERATION_ACTIVE), 0x01);
 
    eeprom_write_word((uint16_t *)(eeprom_offsets::ACCELERATION_SETTINGS + acceleration_eeprom_offsets::MAX_ACCELERATION_AXIS + sizeof(uint16_t)*0), DEFAULT_MAX_ACCELERATION_AXIS_X);
    eeprom_write_word((uint16_t *)(eeprom_offsets::ACCELERATION_SETTINGS + acceleration_eeprom_offsets::MAX_ACCELERATION_AXIS + sizeof(uint16_t)*1), DEFAULT_MAX_ACCELERATION_AXIS_Y);
    eeprom_write_word((uint16_t *)(eeprom_offsets::ACCELERATION_SETTINGS + acceleration_eeprom_offsets::MAX_ACCELERATION_AXIS + sizeof(uint16_t)*2), DEFAULT_MAX_ACCELERATION_AXIS_Z);
    eeprom_write_word((uint16_t *)(eeprom_offsets::ACCELERATION_SETTINGS + acceleration_eeprom_offsets::MAX_ACCELERATION_AXIS + sizeof(uint16_t)*3), DEFAULT_MAX_ACCELERATION_AXIS_A);
    eeprom_write_word((uint16_t *)(eeprom_offsets::ACCELERATION_SETTINGS + acceleration_eeprom_offsets::MAX_ACCELERATION_AXIS + sizeof(uint16_t)*4), DEFAULT_MAX_ACCELERATION_AXIS_B);
 
    eeprom_write_word((uint16_t *)(eeprom_offsets::ACCELERATION_SETTINGS + acceleration_eeprom_offsets::MAX_ACCELERATION_NORMAL_MOVE),   DEFAULT_MAX_ACCELERATION_NORMAL_MOVE);
    eeprom_write_word((uint16_t *)(eeprom_offsets::ACCELERATION_SETTINGS + acceleration_eeprom_offsets::MAX_ACCELERATION_EXTRUDER_MOVE), DEFAULT_MAX_ACCELERATION_EXTRUDER_MOVE);
 
    eeprom_write_word((uint16_t *)(eeprom_offsets::ACCELERATION_SETTINGS + acceleration_eeprom_offsets::MAX_SPEED_CHANGE + sizeof(uint16_t)*0), DEFAULT_MAX_SPEED_CHANGE_X);
    eeprom_write_word((uint16_t *)(eeprom_offsets::ACCELERATION_SETTINGS + acceleration_eeprom_offsets::MAX_SPEED_CHANGE + sizeof(uint16_t)*1), DEFAULT_MAX_SPEED_CHANGE_Y);
    eeprom_write_word((uint16_t *)(eeprom_offsets::ACCELERATION_SETTINGS + acceleration_eeprom_offsets::MAX_SPEED_CHANGE + sizeof(uint16_t)*2), DEFAULT_MAX_SPEED_CHANGE_Z);
    eeprom_write_word((uint16_t *)(eeprom_offsets::ACCELERATION_SETTINGS + acceleration_eeprom_offsets::MAX_SPEED_CHANGE + sizeof(uint16_t)*3), DEFAULT_MAX_SPEED_CHANGE_A);
    eeprom_write_word((uint16_t *)(eeprom_offsets::ACCELERATION_SETTINGS + acceleration_eeprom_offsets::MAX_SPEED_CHANGE + sizeof(uint16_t)*4), DEFAULT_MAX_SPEED_CHANGE_B);
 
    eeprom_write_dword((uint32_t *)(eeprom_offsets::ACCELERATION2_SETTINGS + acceleration2_eeprom_offsets::JKN_ADVANCE_K),  DEFAULT_JKN_ADVANCE_K);
    eeprom_write_dword((uint32_t *)(eeprom_offsets::ACCELERATION2_SETTINGS + acceleration2_eeprom_offsets::JKN_ADVANCE_K2), DEFAULT_JKN_ADVANCE_K2);
 
    eeprom_write_word((uint16_t *)(eeprom_offsets::ACCELERATION2_SETTINGS + acceleration2_eeprom_offsets::EXTRUDER_DEPRIME_STEPS + sizeof(uint16_t)*0), DEFAULT_EXTRUDER_DEPRIME_STEPS_A);
    eeprom_write_word((uint16_t *)(eeprom_offsets::ACCELERATION2_SETTINGS + acceleration2_eeprom_offsets::EXTRUDER_DEPRIME_STEPS + sizeof(uint16_t)*1), DEFAULT_EXTRUDER_DEPRIME_STEPS_B);
 
    eeprom_write_byte((uint8_t *) (eeprom_offsets::ACCELERATION2_SETTINGS + acceleration2_eeprom_offsets::SLOWDOWN_FLAG), DEFAULT_SLOWDOWN_FLAG);
 
    eeprom_write_byte((uint8_t *) (eeprom_offsets::ACCELERATION_SETTINGS + acceleration_eeprom_offsets::DEFAULTS_FLAG), _BV(ACCELERATION_INIT_BIT));
}  

/// Writes to EEPROM the default toolhead 'home' values to idicate toolhead offset
/// from idealized point-center of the toolhead
void setDefaultAxisHomePositions()
{
	uint32_t homes[5] = {replicator_axis_offsets::DUAL_X_OFFSET_STEPS,replicator_axis_offsets::DUAL_Y_OFFSET_STEPS,0,0,0};
	if(isSingleTool()){
		homes[0] = replicator_axis_offsets::SINGLE_X_OFFSET_STEPS;
		homes[1] = replicator_axis_offsets::SINGLE_Y_OFFSET_STEPS;
	}
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE){  
    eeprom_write_block((uint8_t*)&(homes[0]),(uint8_t*)(eeprom_offsets::AXIS_HOME_POSITIONS_MM), 20 );
  }
} 
    
/// Does a factory reset (resets all defaults except home/endstops, axis direction and tool count)
void factoryResetEEPROM() {

	// Default: enstops inverted, Z axis inverted
	uint8_t endstop_invert = 0b10011111; // all endstops inverted

	uint8_t home_direction = 0b11011; // X,Y Max, Z min  (AB max - to never halt on edge in stepper interface)

	uint8_t vRefBase[] = {118,118,40,118,118};  //(XYAB maxed out)

  setDefaultMachineName();

ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
#ifdef MODEL_REPLICATOR	
  uint16_t vidPid[] = {0x23C1, 0xB404};		/// PID/VID for the MightyBoard!
#elif MODEL_REPLICATOR2
  uint16_t vidPid[] = {0x23C1, 0xB404};		/// PID/VID for the MightyBoard!
#endif
  eeprom_write_block(&(vRefBase[0]),(uint8_t*)(eeprom_offsets::DIGI_POT_SETTINGS), 5 );
  eeprom_write_byte((uint8_t*)eeprom_offsets::ENDSTOP_INVERSION, endstop_invert);
  eeprom_write_byte((uint8_t*)eeprom_offsets::AXIS_HOME_DIRECTION, home_direction);
    
  eeprom_write_byte((uint8_t*)eeprom_offsets::HEATER_TIMEOUT_ON_CANCEL, 0);
  setDefaultAxisHomePositions();

  eeprom_write_byte((uint8_t*)eeprom_offsets::STOP_HEIGHT_VALUE, 0);
  
  /// store the default axis lengths for the machine
  eeprom_write_block((uint8_t*)&(replicator_axis_lengths::axis_lengths[0]), (uint8_t*)(eeprom_offsets::AXIS_LENGTHS_MM), 20);
 
  /// store the default axis steps per mm for the machine
  eeprom_write_block((uint8_t*)&(replicator_axis_steps_per_mm::axis_steps_per_mm[0]), (uint8_t*)(eeprom_offsets::AXIS_STEPS_PER_MM), 20);

  /// store the default axis max feedrates for the machine
  eeprom_write_block((uint8_t*)&(replicator_axis_max_feedrates::axis_max_feedrates[0]), (uint8_t*)(eeprom_offsets::AXIS_MAX_FEEDRATES), 10);

  setDefaultsAcceleration();

  // set build time to zero
  eeprom_write_word((uint16_t*)(eeprom_offsets::TOTAL_BUILD_TIME + build_time_offsets::HOURS), 0);
  eeprom_write_byte((uint8_t*)(eeprom_offsets::TOTAL_BUILD_TIME + build_time_offsets::MINUTES), 0);

  eeprom_write_byte((uint8_t*)eeprom_offsets::FILAMENT_HELP_TEXT_ON, 1);

  /// Preheat heater settings
  setDefaultsPreheat(eeprom_offsets::PREHEAT_SETTINGS);

  /// write MightyBoard VID/PID. Only after verification does production write
  /// a proper 'The Replicator' PID/VID to eeprom, and to the USB chip
  eeprom_write_block(&(vidPid[0]),(uint8_t*)eeprom_offsets::VID_PID_INFO,4);

  /// Write 'extruder 0' settings
  setDefaultsExtruder(0,eeprom_offsets::T0_DATA_BASE);

  /// Write 'extruder 1' stttings
  setDefaultsExtruder(1,eeprom_offsets::T1_DATA_BASE);

  /// write blink and buzz defaults
  setDefaultLedEffects(eeprom_offsets::LED_STRIP_SETTINGS);
  setDefaultBuzzEffects(eeprom_offsets::BUZZ_SETTINGS);
  
  // startup script flag is cleared
  eeprom_write_byte((uint8_t*)eeprom_offsets::FIRST_BOOT_FLAG, 0);
}
}

void setDefaultMachineName(){
ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
#ifdef SPECIFIC_REP2
  eeprom_write_block("Replicator 2", (uint8_t*)eeprom_offsets::MACHINE_NAME,16);
#elif SPECIFIC_REP2X
  eeprom_write_block("Replicator 2X", (uint8_t*)eeprom_offsets::MACHINE_NAME,16);
#elif MODEL_REPLICATOR	
  eeprom_write_block("The Replicator", (uint8_t*)eeprom_offsets::MACHINE_NAME,16);
#elif MODEL_REPLICATOR2
  if(isSingleTool()){
    eeprom_write_block("Replicator 2", (uint8_t*)eeprom_offsets::MACHINE_NAME,16);
  }
  else {
    eeprom_write_block("Replicator 2X", (uint8_t*)eeprom_offsets::MACHINE_NAME,16);
  }
#endif
}
}

// this is a complete hack because it not worth screwing with the machine name system 
// at this point.  changes here affect behavior all the way up the stack. 
// we want the machine to toggle between 2 and 2X names when the tool count changes
// normally this would happen with a factory reset - but we want it to happen right away
// so folks in production don't get nervous.
// we're checking if the stored name is the same as the default and returning true or false
bool hasDefaultMachineName(){

#ifdef MODEL_REPLICATOR
	char default_name[] = "The Replicator";
	for(int i = 0; i < 14; i++){
		if((getEeprom8(eeprom_offsets::MACHINE_NAME + i,0)) == default_name[i]){
			return false;
		}
	}
#else
	char default_name[] = "Replicator 2";
	for(int i = 0; i < 12; i++){
		if((getEeprom8(eeprom_offsets::MACHINE_NAME + i,0)) != default_name[i]){
			return false;
		}
	}

#endif

	return true;
}

void setToolHeadCount(uint8_t count){
	
ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
	// update toolhead count
	eeprom_write_byte((uint8_t*)eeprom_offsets::TOOL_COUNT, count);
	
	// update XY axis offsets to match tool head settings
	setDefaultAxisHomePositions();
}
	
}

    // check single / dual tool status
bool isSingleTool(){
	return (getEeprom8(eeprom_offsets::TOOL_COUNT, 1) == 1);
}

bool hasHBP(){
	return (getEeprom8(eeprom_offsets::HBP_PRESENT, 1) == 1);
}


// reset the settings that can be changed via the onboard UI to defaults
void setDefaultSettings(){
   
 ATOMIC_BLOCK(ATOMIC_RESTORESTATE){  
    /// write blink and buzz defaults
    setDefaultLedEffects(eeprom_offsets::LED_STRIP_SETTINGS);
    setDefaultBuzzEffects(eeprom_offsets::BUZZ_SETTINGS);
    setDefaultsPreheat(eeprom_offsets::PREHEAT_SETTINGS);
    eeprom_write_byte((uint8_t*)eeprom_offsets::FILAMENT_HELP_TEXT_ON, 1);
    eeprom_write_byte((uint8_t*)(eeprom_offsets::ACCELERATION_SETTINGS + acceleration_eeprom_offsets::ACCELERATION_ACTIVE), 0x01);
    setToolHeadCount(1);
    eeprom_write_byte((uint8_t*)eeprom_offsets::HEATER_TIMEOUT_ON_CANCEL, 0);
    eeprom_write_byte((uint8_t*)eeprom_offsets::STOP_HEIGHT_VALUE, 0);
    // HBP settings
  #ifdef MODEL_REPLICATOR
    eeprom_write_byte((uint8_t*)eeprom_offsets::HBP_PRESENT, 1);
  #else
    eeprom_write_byte((uint8_t*)eeprom_offsets::HBP_PRESENT, 0);
  #endif
}
}

//
void storeToolheadToleranceDefaults(){
	
 ATOMIC_BLOCK(ATOMIC_RESTORESTATE){ 
	// assume t0 to t1 distance is in specifications (0 steps tolerance error)
#ifdef MODEL_REPLICATOR
  uint32_t offsets[3] = {33L*1000,0,0};
#else
  #ifdef MODEL_REPLICATOR2
    uint32_t offsets[3] = {35L*1000,0,0};
  #else
    //This was put here for future debugging, it can be removed if necessary
    uint32_t offsets[3] = {99L*1000,0,0};
  #endif
#endif
	eeprom_write_block((uint8_t*)&(offsets[0]),(uint8_t*)(eeprom_offsets::TOOLHEAD_OFFSET_SETTINGS_MM), 12 );
}
	
}

void updateBuildTime(uint8_t new_hours, uint8_t new_minutes){
	
	uint16_t hours = eeprom::getEeprom16(eeprom_offsets::TOTAL_BUILD_TIME + build_time_offsets::HOURS,0);
	uint8_t minutes = eeprom::getEeprom8(eeprom_offsets::TOTAL_BUILD_TIME + build_time_offsets::MINUTES,0);
	
	uint8_t total_minutes = new_minutes + minutes;
	minutes = total_minutes % 60;
	
	// increment hours if minutes are over 60
	if(total_minutes > 60){
		hours++;
	}

 ATOMIC_BLOCK(ATOMIC_RESTORESTATE){  	
	// update build time
	eeprom_write_word((uint16_t*)(eeprom_offsets::TOTAL_BUILD_TIME + build_time_offsets::HOURS), hours + new_hours);
	eeprom_write_byte((uint8_t*)(eeprom_offsets::TOTAL_BUILD_TIME + build_time_offsets::MINUTES), minutes);
}
}

enum BOTSTEP_TYPE{
  BOTSTEP_16_STEP = 1,
  BOTSTEP_8_STEP = 2,
};

/// Initialize entire eeprom map, including factor-set settings
void fullResetEEPROM() {
	
	factoryResetEEPROM();

	// axis inversion settings
	uint8_t axis_invert = 0b10111; // invert XYBZ
  uint8_t heater_calibrate[] = {0,0,0};
 ATOMIC_BLOCK(ATOMIC_RESTORESTATE){  
	eeprom_write_byte((uint8_t*)eeprom_offsets::AXIS_INVERSION, axis_invert);
	
	// tool count settings
	eeprom_write_byte((uint8_t*)eeprom_offsets::TOOL_COUNT, 1);
	
	// toolhead offset defaults
	storeToolheadToleranceDefaults();
	
	// HBP settings
#ifdef MODEL_REPLICATOR
	eeprom_write_byte((uint8_t*)eeprom_offsets::HBP_PRESENT, 1);
#else
	eeprom_write_byte((uint8_t*)eeprom_offsets::HBP_PRESENT, 0);
#endif
	
  // store the botstep type
	eeprom_write_byte((uint8_t*)(eeprom_offsets::BOTSTEP_TYPE), BOTSTEP_16_STEP);

  /// store the heater calibration bytes
  eeprom_write_block((uint8_t*)&(heater_calibrate[0]), (uint8_t*)(eeprom_offsets::HEATER_CALIBRATION), 3);

  eeprom_write_byte((uint8_t*)(eeprom_offsets::VERSION7_UPDATE_FLAG), VERSION7_FLAG);
 
 }
}
// we changed the way things are stored in EEPROM.  we need to make sure bots update accordingly
void eepromResetv7(){
  
  uint8_t heater_calibrate[] = {0,0,0};
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
    /// store the default axis lengths for the machine
    eeprom_write_block((uint8_t*)&(replicator_axis_lengths::axis_lengths[0]), (uint8_t*)(eeprom_offsets::AXIS_LENGTHS_MM), 20);
   
    /// store the default axis steps per mm for the machine
    eeprom_write_block((uint8_t*)&(replicator_axis_steps_per_mm::axis_steps_per_mm[0]), (uint8_t*)(eeprom_offsets::AXIS_STEPS_PER_MM), 20);

    /// store the default axis max feedrates for the machine
    eeprom_write_block((uint8_t*)&(replicator_axis_max_feedrates::axis_max_feedrates[0]), (uint8_t*)(eeprom_offsets::AXIS_MAX_FEEDRATES), 10);

    setDefaultsAcceleration();

    setDefaultAxisHomePositions();

    // store the botstep type
    eeprom_write_byte((uint8_t*)(eeprom_offsets::BOTSTEP_TYPE), BOTSTEP_16_STEP);

    /// store the heater calibration bytes
    eeprom_write_block((uint8_t*)&(heater_calibrate[0]), (uint8_t*)(eeprom_offsets::HEATER_CALIBRATION), 3);

    eeprom_write_byte((uint8_t*)(eeprom_offsets::VERSION7_UPDATE_FLAG), VERSION7_FLAG);
  }
  // we are storing offsets in mm now.....
  int32_t x_nozzle_offset = getEeprom32(eeprom_offsets::TOOLHEAD_OFFSET_SETTINGS, 0);
  /// check to see if offsets are in 5.5 and earlier state (< 1mm) or 6.0 state (~33mm)
  /// ACK what a mess

  if(x_nozzle_offset  < 3L * replicator_axis_steps_per_mm::axis_steps_per_mm[0] * 10){
    //Add the full toolhead offset.  This was formerly stored in RepG  
    // add 33mm to get the complete distance
    x_nozzle_offset =  33L * 1000 + ((x_nozzle_offset * 100) / replicator_axis_steps_per_mm::axis_steps_per_mm[0]);
  } else {
    // take out the dependence on steps per mm.  and multiply by 100 (for a final scaling factor of 1000)
    x_nozzle_offset =  100 * (x_nozzle_offset /replicator_axis_steps_per_mm::axis_steps_per_mm[0]); 
  }
    
	// toolhead offset defaults
	storeToolheadToleranceDefaults();
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE){  
    eeprom_write_block((uint8_t*)&(x_nozzle_offset),(uint8_t*)(eeprom_offsets::TOOLHEAD_OFFSET_SETTINGS_MM), 4 );
  }
        
}


}

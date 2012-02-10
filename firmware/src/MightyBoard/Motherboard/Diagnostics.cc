/*
 * Copyright 2012 by Alison Leonard	 <alison@makerbot.com>
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
 
 #include "Steppers.hh"
 #include "Interface.hh"
#include <util/delay.h>
#include "Timeout.hh"
#include "Point.hh"
#include "Interface.hh"
#include "Motherboard.hh"
#include "Diagnostics.hh"

#define FAN_TEST_TEMP  70
#define HEAT_TEMP 225
#define FAN_TIMEOUT 240000000
#define HEAT_TIMEOUT 240000000
#define CUTOFF_TEMP 370
#define CUTOFF_TIMEOUT 600000000 //10 minutes


namespace testing{
	
	uint8_t motor_test[5] = {0,0,0,0,0};
    uint16_t exOneTemp, exTwoTemp;
	TestMenu testScreen;
    MessageScreen msgScreen;
    Timeout heatTimer;
    bool fanFail = false;
    bool singleTest = false;
    bool extrudeReverseSingle = false;
    bool secondTimer = false;
    
    heatMode_t testMode;
    
void reset(void){
    testMode = HEAT_TEST_OFF;
    singleTest = false;
    heatTimer = Timeout();
    extrudeReverseSingle = false;
    fanFail = false;
    exOneTemp = exTwoTemp = 0;
 //   msgScreen.clearMessage();
 //   Motherboard::getBoard().getInterfaceBoard().clearButtonWait();
}


void motorSpin(void){
	
	int32_t interval = 2000;

	Point position = steppers::getPosition();
	steppers::abort();
	
		for(int k = 0; k < STEPPER_COUNT; k++)
			position[k] += interval*2;
			
		steppers::setTarget(position, interval);

}
	
void messageWait(char msg[]){
    msgScreen.clearMessage();
    msgScreen.addMessage(msg, true);
    Motherboard::getBoard().interfaceBlink(25,15);
    Motherboard::getBoard().getInterfaceBoard().waitForButton(0x01);
}

void setHeatTestMode(heatMode_t mode, bool single){
 
    reset();
    testMode = mode;
    singleTest = single;
    interface::pushScreen(&msgScreen);
    switch(testMode){
        case FAN_TEST:
            Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().set_target_temperature(0);
            Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().set_target_temperature(FAN_TEST_TEMP);
            msgScreen.clearMessage();
            msgScreen.addMessage("Heating up for Fan  test", true);
            heatTimer.start(FAN_TIMEOUT);
            break;
        case EXTRUDE_REVERSE:
            testMode = HEAT_TEST_TEMP;
            extrudeReverseSingle = true;
        case HEAT_TEST_TEMP:
            Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().set_target_temperature(HEAT_TEMP);
            Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().set_target_temperature(HEAT_TEMP);
            
            heatTimer.clear();
            heatTimer.start(HEAT_TIMEOUT);
            msgScreen.clearMessage();
            msgScreen.addMessage("Heating up", true);
            break;
    }
}
    
void runHeaterTestsSlice(void){
    
    if(testMode == HEAT_TEST_OFF)
        return;
        
    if (testMode == HEAT_TEST_BEGIN){
    
            msgScreen.clearMessage();
            msgScreen.addMessage("Testing Connections", true);
            
            exOneTemp = Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().get_current_temperature();
            exTwoTemp = Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().get_current_temperature();
            
            Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().set_target_temperature(exTwoTemp + 20);
            Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().set_target_temperature(0);
            heatTimer.start(30000000); // 30 second timeout
            
            testMode = HEAT_TEST_CONNECTION_WAIT; 
    }
    if (testMode == HEAT_TEST_CONNECTION_WAIT){
        
        // wrong heater is heating up
        if(Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().get_current_temperature() > exOneTemp + 10){
            messageWait("FAIL: CONNECT TEST  Extruders are not   plugged in correctlyPlease Try Again."); 
            
            testMode = HEAT_TEST_FAIL;
        }
        else if(Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().get_current_temperature() > exTwoTemp + 10){
            if(singleTest){
                messageWait("PASS!               Connections OK!");
                testMode = HEAT_TEST_FAIL;
            }else{
                msgScreen.clearMessage();
                msgScreen.addMessage("PASS: CONNECT TEST                                             Testing Fan", true);           
                
                Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().set_target_temperature(0);
                Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().set_target_temperature(FAN_TEST_TEMP);
            
                testMode = FAN_TEST;
                heatTimer.clear();
                heatTimer.start(FAN_TIMEOUT);
            }
        }
        else if(heatTimer.hasElapsed()){
            messageWait("FAIL: CONNECT TEST  Extruders are not   heating up          Please Try Again."); 
            
            testMode = HEAT_TEST_FAIL;
        }
    }
    if(testMode == FAN_TEST){
        if(Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().has_reached_target_temperature() &&
           (Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().get_current_temperature() < 40)){
            
            testScreen.newTest("Is the Left Fan On?");
            interface::pushScreen(&testScreen);
            
            testMode = FAN_TEST_WAIT;
        }
        else if(heatTimer.hasElapsed()){
            messageWait("FAIL: FAN TEST      Extruders are not   heating up          Please Try Again."); 
            
            testMode = HEAT_TEST_FAIL;
        }
    }
   if(testMode == FAN_TEST_WAIT){
        if(testScreen.userResponse()){
            if(testScreen.testOK()){
                msgScreen.clearMessage();
                msgScreen.addMessage("PASS: FAN TEST  ", false);                                              
            }
            else{
                msgScreen.clearMessage();
                msgScreen.addMessage("FAIL: FAN TEST      Re-Label Fan Leads", false);   
                fanFail = true;
            }
            
            if(singleTest){
                msgScreen.addMessage(" ", true); 
                Motherboard::getBoard().interfaceBlink(25,15);
                Motherboard::getBoard().getInterfaceBoard().waitForButton(0x01);

                testMode = HEAT_TEST_FAIL;
            }
            else{
           
                msgScreen.addMessage("                        Testing Heat Level", true);  
                    
                Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().set_target_temperature(HEAT_TEMP);
                Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().set_target_temperature(HEAT_TEMP);
                
                heatTimer.clear();
                heatTimer.start(HEAT_TIMEOUT);
                
                
                testMode = HEAT_TEST_TEMP;
            }
        }
    }
    if(testMode == HEAT_TEST_TEMP){
        if(Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().has_reached_target_temperature() &&
          (Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().has_reached_target_temperature() || singleTest)){
            if(extrudeReverseSingle)
                testMode = EXTRUDE_RUN;
            else{
                messageWait("PASS: HEAT TEST       Press M to start    extrude test"); 
                testMode = EXTRUDE_TEST;
            }
        }
        else if(heatTimer.hasElapsed()){
            messageWait("FAIL: HEAT TEST     Extruders are not   heating up          Please Try Again."); 
            
            testMode = HEAT_TEST_FAIL;   
        }
    }
    if(testMode == EXTRUDE_TEST){
        if (Motherboard::getBoard().getInterfaceBoard().buttonPushed()) {
            Motherboard::getBoard().interfaceBlink(0,0);            
                
            // set relative point, extruder steppers to run for 5 minutes
            int32_t interval = 300000000;
            int32_t steps = -interval / 6250;
            Point target = Point(0,0,0, steps, steps);
            steppers::setTargetNew(target, interval, 0x1f);
            heatTimer.clear();
            heatTimer.start(300000000);
            messageWait("Extruders running.  When finished       testing, Press M forfilament reversal.");
            
            testMode = EXTRUDE_RUN;
        }
        
    }
    if(testMode == EXTRUDE_RUN){
        if (Motherboard::getBoard().getInterfaceBoard().buttonPushed() || extrudeReverseSingle) {
            Motherboard::getBoard().interfaceBlink(0,0);
            
            steppers::abort();
         
            // set relative point, extruder steppers to reverse for 2 minutes
            int32_t interval = 120000000;
            int32_t steps = interval / 6250;
            Point target = Point(0,0,0, steps, steps);
            steppers::setTargetNew(target, interval, 0x1f);
            heatTimer.clear();
            heatTimer.start(120000000);
            messageWait("Extruders reversing.When finished, press M to stop.");
            
            testMode = EXTRUDE_REVERSE;
        }
        else if (heatTimer.hasElapsed()){
            steppers::abort();
            testMode = HEAT_TEST_DONE;
        }
    }
    if(testMode == EXTRUDE_REVERSE){
        if (Motherboard::getBoard().getInterfaceBoard().buttonPushed() || heatTimer.hasElapsed()) {
            Motherboard::getBoard().interfaceBlink(0,0);
            
            steppers::abort();
            testMode = HEAT_TEST_DONE;
        }
    }
    if(testMode == HEAT_TEST_DONE){
        
        steppers::abort();
        for(int i = 0; i < STEPPER_COUNT; i++)
			steppers::enableAxis(i, false);
        
        Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().set_target_temperature(0);
        Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().set_target_temperature(0);
        
        if(fanFail)
            messageWait("Heat Tests Complete!Press M to exit.     Remember to re-labelfan leads");
        else
            messageWait("Heat Tests Complete!Press M to exit.");
        
       testMode = HEAT_TEST_QUIT;
        
    }
    if(testMode == HEAT_TEST_FAIL){
        
        Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().set_target_temperature(0);
        Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().set_target_temperature(0);
        
        testMode = HEAT_TEST_QUIT;
        
    }
    if(testMode == HEAT_TEST_QUIT){
        
        if (Motherboard::getBoard().getInterfaceBoard().buttonPushed()){
            Motherboard::getBoard().interfaceBlink(0,0);
            interface::popScreen();
            testMode = HEAT_TEST_OFF;
        }
    } 
    if(testMode == CUTOFF_TEST_START){
		msgScreen.clearMessage();
		 msgScreen.addMessage("Heating up Extrudersto test safety      cutoff ", true);  
                    
		Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().set_target_temperature(CUTOFF_TEMP);
		Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().set_target_temperature(CUTOFF_TEMP);
		
		heatTimer.clear();
		heatTimer.start(CUTOFF_TIMEOUT);
		
		secondTimer = false;
		testMode = CUTOFF_TEST_WAIT;
	}       
	if(testMode == CUTOFF_TEST_WAIT){
		
		if(!secondTimer && (Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().has_reached_target_temperature() ||
			Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().has_reached_target_temperature())){
			
			heatTimer.clear();
			heatTimer.start(60000000); //1 minute
			secondTimer = true;
			}
		else if(heatTimer.hasElapsed()){
			
			if(secondTimer)
				messageWait("Cutoff Failed to     Trigger!  ");
			else
				messageWait("Heaters not heating to 370 degrees.     FAIL!");
			
			testMode = HEAT_TEST_FAIL;
		}
	}
}

void motorTest(void){

	Point position = steppers::getPosition();
	steppers::abort();
	
	int32_t interval = 1000;
	
	// spin X motor
	testScreen.newTest("X Motor turning OK?");
	interface::pushScreen (&testScreen);
	while (!testScreen.userResponse()){
		position[0] += 1000;
		steppers::setTarget(position, interval);
	}
	if(testScreen.testOK())
		motor_test[0] = 1;
	steppers::abort();
	
	// spin Y motor
	testScreen.newTest("Y Motor turning OK?");
	interface::pushScreen (&testScreen);
	while (!testScreen.userResponse()){
		position[1] += 1000;
		steppers::setTarget(position, interval);
	}
	if(testScreen.testOK())
		motor_test[1] = 1;
	steppers::abort();
	
	// spin Z motor
	testScreen.newTest("Z Motor turning OK?");
	interface::pushScreen (&testScreen);
	while (!testScreen.userResponse()){
		position[2] += 1000;
		steppers::setTarget(position, interval);
	}
	if(testScreen.testOK())
		motor_test[2] = 1;
	steppers::abort();
	
	// spin A motor
	testScreen.newTest("A Motor turning OK?");
	interface::pushScreen (&testScreen);
	while (!testScreen.userResponse()){
		position[3] += 1000;
		steppers::setTarget(position, interval);
	}
	if(testScreen.testOK())
		motor_test[3] = 1;
	steppers::abort();
	
	// spin B motor
	testScreen.newTest("B Motor turning OK?");
	interface::pushScreen (&testScreen);
	while (!testScreen.userResponse()){
		position[4] += 1000;
		steppers::setTarget(position, interval);
	}
	if(testScreen.testOK())
		motor_test[4] = 1;
	steppers::abort();
	
}
}

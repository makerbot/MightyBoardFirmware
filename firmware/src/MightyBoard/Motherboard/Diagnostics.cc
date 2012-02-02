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

#define FAN_TEST_TEMP  70



namespace testing{
	
	uint8_t motor_test[5] = {0,0,0,0,0};
	TestMenu scr;
    
enum {
    HEAT_TEST_BEGIN,
    HEAT_TEST_BUTTON_WAIT,
    HEAT_TEST_CONNECTION_WAIT,
    FAN_TEST,
    HEAT_TEST_FAIL
} testMode = HEAT_TEST_BEGIN;


void motorSpin(void){
	
	int32_t interval = 2000;

	Point position = steppers::getPosition();
	steppers::abort();
	
		for(int k = 0; k < STEPPER_COUNT; k++)
			position[k] += interval*2;
			
		steppers::setTarget(position, interval);

}
	
void messageWait(char [] msg){
    msgScreen.clearMessage();
    msgScreen.addMessage(msg, true);
    interfaceBlink(25,15);
    interfaceBoard.waitForButton(0xFF);
}
    
void HeaterTestsDual(void){
        
    if(testMode == HEAT_TEST_BEGIN)   {
        messageWait("Push M to Begin     Extruder Tests");
        interface::pushScreen(&msgScreen);

        testMode = HEAT_TEST_BUTTON_WAIT;
    }
    if (testMode == HEAT_TEST_BUTTON_WAIT){
        if (interfaceBoard.buttonPushed()) {
            interfaceBlink(0,0);
            buttonWait = false;
            msgScreen.clearMessage();
            msgScreen.addMessage("Testing Connections", true);
            
            exOneTemp = Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().get_current_temperature();
            exTwoTemp = Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().get_current_temperature();
            
            Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().set_target_temperature(exTwoTemp + 20);
            Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().set_target_temperature(0);
            heatTimer.start(30000000); // 30 second timeout
            
            testMode = HEAT_TEST_CONNECTION_WAIT; 
        }
    }
    if (testMode == HEAT_TEST_CONNECTION_WAIT){
        
        // wrong heater is heating up
        if(Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().get_current_temperature() > exOneTemp + 10){
            messageWait("FAIL: TEST ONE      Extruders are not   plugged in correctlyPlease Try Again."); 
            
            testMode = HEAT_TEST_FAIL;
        }
        else if(Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().get_current_temperature() > exTwoTemp + 10){
            msgScreen.clearMessage();
            msgScreen.addMessage("PASS: TEST ONE      Testing Fan", true);           
            
            Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().set_target_temperature(0);
            Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().set_target_temperature(FAN_TEST_TEMP);
            
            testMode = FAN_TEST;
        }
        else if(heatTimer.hasElapsed()){
            messageWait("FAIL: TEST ONE      Extruders are not   heating up          Please Try Again."); 
            
            testMode = HEAT_TEST_FAIL;
        }
    }
    if(testMode == FAN_TEST){
        if(Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().has_reached_target_temperature() &&
           (Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().get_current_temperature() < 40)){
            
            testScreen.newTest("Is the Left Fan On?");
            interface::pushScreen(testScreen);
            
            testMode = FAN_TEST_WAIT;
        }
    }
 ****   if(testMode == FAN_TEST_WAIT){
        if(testScreen.userResponse()){
            if(testScreen.testOK()){
                msgScreen.clearMessage();
                msgScreen.addMessage("PASS: TEST Two      Testing Fan", true);           
                
                Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().set_target_temperature(0);
                Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().set_target_temperature(FAN_TEST_TEMP);
                
                testMode = FAN_TEST;
            }
            else{
                
            }
                
        }
    }
    if(testMode == HEAT_TEST_FAIL){
        
        Motherboard::getBoard().getExtruderBoard(0).getExtruderHeater().set_target_temperature(0);
        Motherboard::getBoard().getExtruderBoard(1).getExtruderHeater().set_target_temperature(0);
        
        if (interfaceBoard.buttonPushed())
            interface::popScreen();
        
    }
    
// part one plugged in correctly test
    /// record initial temperature
    
    /// initialize heater
    
    /// set timeout
    
    
// part two fans plugged correctly test
    
// part three heating up test
    
// part four extrude test
    
// part five cutoff test
    
}

void motorTest(void){

	Point position = steppers::getPosition();
	steppers::abort();
	
	int32_t interval = 1000;
	
	// spin X motor
	scr.newTest("X Motor turning OK?");
	interface::pushScreen(&scr);
	while (!scr.userResponse()){
		position[0] += 1000;
		steppers::setTarget(position, interval);
	}
	if(scr.testOK())
		motor_test[0] = 1;
	steppers::abort();
	
	// spin Y motor
	scr.newTest("Y Motor turning OK?");
	interface::pushScreen(&scr);
	while (!scr.userResponse()){
		position[1] += 1000;
		steppers::setTarget(position, interval);
	}
	if(scr.testOK())
		motor_test[1] = 1;
	steppers::abort();
	
	// spin Z motor
	scr.newTest("Z Motor turning OK?");
	interface::pushScreen(&scr);
	while (!scr.userResponse()){
		position[2] += 1000;
		steppers::setTarget(position, interval);
	}
	if(scr.testOK())
		motor_test[2] = 1;
	steppers::abort();
	
	// spin A motor
	scr.newTest("A Motor turning OK?");
	interface::pushScreen(&scr);
	while (!scr.userResponse()){
		position[3] += 1000;
		steppers::setTarget(position, interval);
	}
	if(scr.testOK())
		motor_test[3] = 1;
	steppers::abort();
	
	// spin B motor
	scr.newTest("B Motor turning OK?");
	interface::pushScreen(&scr);
	while (!scr.userResponse()){
		position[4] += 1000;
		steppers::setTarget(position, interval);
	}
	if(scr.testOK())
		motor_test[4] = 1;
	steppers::abort();
	
}
}

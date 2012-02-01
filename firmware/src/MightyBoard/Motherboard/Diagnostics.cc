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

namespace testing{
	
	uint8_t motor_test[5] = {0,0,0,0,0};
	TestMenu scr;

void motorSpin(void){
	
	int32_t interval = 1000;

	Point position = steppers::getPosition();
	steppers::abort();
	
	for (int i = 0; i < 3; i++){
		for(int k = 0; k < STEPPER_COUNT; k++)
			position[k] += 1000;
			
		steppers::setTarget(position, interval);
	}
//	while(steppers::isRunning());
	
//	for (int i = 0; i < 10; i++){
//		for(int k = 0; k < 5; k++)
//			position[k] -= 1000;
			
//		steppers::setTarget(position, interval);
//	}

//	while(steppers::isRunning());

//	for(int i = 0; i < STEPPER_COUNT; i++)
//			steppers::enableAxis(i, false);
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

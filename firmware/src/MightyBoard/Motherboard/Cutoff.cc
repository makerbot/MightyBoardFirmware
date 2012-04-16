/*
 * Copyright 2011 by Alison Leonard	 <alison@makerbot.com>
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

#include "Cutoff.hh"
#include "Pin.hh"
#include "Piezo.hh"

// Avoid repeatedly creating temp objects
const Pin Cutoff_Reset = CUTOFF_RESET;
const Pin Cutoff_Test = CUTOFF_TEST;
const Pin Cutoff_SR_Check = CUTOFF_SR_CHECK;

void Cutoff::init()
{
	// reset pin is an output, default low
	Cutoff_Reset.setValue(false);
	Cutoff_Reset.setDirection(true);
	
	// SR Check pin is an input, checks if safety cutoff is active
	Cutoff_SR_Check.setValue(false);
	Cutoff_SR_Check.setDirection(false);
 
	if (CUTOFF_PRESENT)
		enable();
	else
		disable();
		
	noiseCount = 0;
	cutoffCount = 0;
	alarmRun = false;
}
bool Cutoff::isCutoffActive()
{
	// if cutoff test pin is high or if cutoff output is latched high, flag as cutoff active
	if(Cutoff_Test.getValue() || Cutoff_SR_Check.getValue())
		return true;
	else
		return false;
}

void Cutoff::enable()
{
	// cutoff test pin is an input
	Cutoff_Test.setValue(false);
	Cutoff_Test.setDirection(false);
	
	// set enabled flag
	cutoff_enabled = true;
	
	// if output is shut off (high when off), toggle reset pin
	if(Cutoff_SR_Check.getValue())
		resetCutoff();
	
	// set reset line to default value (low)
	Cutoff_Reset.setValue(false);
	
}
void Cutoff::disable()
{
	// cutoff test pin is an output and pulled down
	Cutoff_Test.setValue(false);
	Cutoff_Test.setDirection(true);
	
	cutoff_enabled = false;
	// if output is shut off (high when off), toggle reset pin
	if(Cutoff_SR_Check.getValue())
		resetCutoff();
	
	// set reset line to default value (low)
	Cutoff_Reset.setValue(false);
	
}

void Cutoff::resetCutoff(){
	
	//Timeout resetTimeout;

	// abort if cutoff test is high
	if(Cutoff_Test.getValue())
		return;
		
	// toggle reset pin	
	Cutoff_Reset.setValue(true);
	
	// ensure that reset worked
	// if not, enable hardware circuit
	if(Cutoff_SR_Check.getValue())
		disable();
	// if reset OK, return reset line to default (pulled down)
	else
		Cutoff_Reset.setValue(false);
}

// call piezo alarm in cutoff is triggered
void Cutoff::setAlarm()
{
	if(!alarmRun)
	{
		Piezo::errorTone(5);
		alarmRun = true;
	}
}

// this circuit is called once a microsecond by the motherboard if the 
// safety cutoff is triggered.  
// if cutoff signal is low and has one microsecond has passed
// we expect that a spike in power has occured thus we should reset the
// cutoff circuit
bool Cutoff::noiseResponse(){
	
		// not noise if cutoff has been high for longer than cutoff limit
		if(cutoffCount > CUTOFF_COUNT_LIMIT)
		{
			setAlarm();
			return false;
		}
			
		// if cutoff test line is high do nothing / clear cutoffCount
		if(Cutoff_Test.getValue())
		{
			noiseCount = 0;
			cutoffCount++;
		}
		// if cutoff test line is low, reset circuit - check low 5 times
		// before resetting.  
		else{
			if(noiseCount > NOISE_COUNT_LIMIT){
					resetCutoff();
					noiseCount = 0;
			}
			noiseCount++;
			cutoffCount = 0;
		}
		
		return true;
}



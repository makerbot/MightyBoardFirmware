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

#include "Main.hh"
#include "DebugPacketProcessor.hh"
#include "Host.hh"
#include "Command.hh"
#include <avr/interrupt.h>
#include <util/atomic.h>
#include <avr/wdt.h>
#include "Timeout.hh"
#include "Steppers.hh"
#include "Motherboard.hh"
#include "SDCard.hh"
#include "Eeprom.hh"
#include "EepromMap.hh"
#include "TemperatureTable.hh"
#include <util/delay.h>
#include "UtilityScripts.hh"
#include "Piezo.hh"

void reset(bool hard_reset) {
	ATOMIC_BLOCK(ATOMIC_FORCEON) {
		
		bool brown_out = false;
		uint8_t resetFlags = MCUSR & 0x0f;
		// check for brown out reset flag and report if true
		if(resetFlags & (1 << 2)){
			brown_out = true;
		}
		
    // clear watch dog timer and re-enable
		if(hard_reset)
		{ 
      // ATODO: remove disable
			wdt_disable();
			MCUSR = 0x0;
			wdt_enable(WDTO_8S); // 8 seconds is max timeout
		}
		
		// initialize major classes
		Motherboard& board = Motherboard::getBoard();	
    sdcard::reset();
    Piezo::reset();
		utility::reset();
		command::reset();
		eeprom::init();
		steppers::abort();
		steppers::reset();
	  TemperatureTable::initThermistorTables();
		board.reset(hard_reset);

	// brown out occurs on normal power shutdown, so this is not a good message		
	//	if(brown_out)
	//	{
	//		board.getInterfaceBoard().errorMessage("Brown-Out Reset     Occured", 27);
	//		board.startButtonWait();
	//	}
	}
}

int main() {

	Motherboard& board = Motherboard::getBoard();
#ifdef REVG
  INTERFACE_POWER.setDirection(true);
  INTERFACE_POWER.setValue(false);
#endif
	reset(true);
	steppers::init();
	sei();
	    
	while (1) {
		// Host interaction thread.
		host::runHostSlice();	
    DEBUG_PIN1.setValue(true);
		// Command handling thread.
		command::runCommandSlice();
    DEBUG_PIN2.setValue(true);
    
		// Motherboard slice
		board.runMotherboardSlice();
    DEBUG_PIN3.setValue(true);
    // check for new tones
    Piezo::runPiezoSlice();
    DEBUG_PIN4.setValue(true);
    // reset the watch dog timer
		wdt_reset();

    DEBUG_PIN1.setValue(false);
    DEBUG_PIN2.setValue(false);
    DEBUG_PIN3.setValue(false);
    DEBUG_PIN4.setValue(false);
		
	}
	return 0;
}

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
#ifdef STACK_PAINT
#include "Menu_locales.hh"
#endif

#define DEBUG_SRAM_MONITOR

#define NUMBER_OF_ERROR_MESSAGES 26

#if defined(STACK_PAINT) && defined(DEBUG_SRAM_MONITOR)
	bool stackAlertLockout = false;
	uint16_t stackAlertCounter = 0;
#endif


#ifdef STACK_PAINT

        //Stack checking
        //http://www.avrfreaks.net/index.php?name=PNphpBB2&file=viewtopic&t=52249
        extern uint8_t _end;
        extern uint8_t __stack;

        #define STACK_CANARY 0xc5

        void StackPaint(void) __attribute__ ((naked)) __attribute__ ((section (".init1")));

        void StackPaint(void)
        {
                #if 0
                        uint8_t *p = &_end;

                        while(p <= &__stack)
                        {
                                *p = STACK_CANARY;
                                p++;
                        }
                #else
                        __asm volatile ("    ldi r30,lo8(_end)\n"
                                        "    ldi r31,hi8(_end)\n"
                                        "    ldi r24,lo8(0xc5)\n" /* STACK_CANARY = 0xc5 */
                                        "    ldi r25,hi8(__stack)\n"
                                        "    rjmp .cmp\n"
                                        ".loop:\n"
                                        "    st Z+,r24\n"
                                        ".cmp:\n"
                                        "    cpi r30,lo8(__stack)\n"
                                        "    cpc r31,r25\n"
                                        "    brlo .loop\n"
                                        "    breq .loop"::);
                #endif
        }


        uint16_t StackCount(void)
        {
                const uint8_t *p = &_end;
                uint16_t       c = 0;

                while(*p == STACK_CANARY && p <= &__stack)
                {
                        p++;
                        c++;
                }

                return c;
        }

#endif

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
		steppers::init();
		steppers::abort();
		steppers::reset();
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
	board.init();
	reset(true);
	sei();

	unsigned char* message_pointer [NUMBER_OF_ERROR_MESSAGES] = { FAIL_MSG,
						HEATER_ERROR_MSG,
						READY_SS_MSG,
						PUSH_HARDER_MSG,
						KEEP_GOING_MSG,
						FINISH_MSG,
						TIMEOUT_MSG,
						STATICFAIL_MSG,
						CARDSIZE_MSG,
						HEATER_FAIL_SOFTWARE_CUTOFF_MSG,
						HEATER_FAIL_NOT_HEATING_MSG,
						HEATER_FAIL_DROPPING_TEMP_MSG,
						HEATER_FAIL_NOT_PLUGGED_IN_MSG,
						HEATER_FAIL_READ_TEMP_OUT_OF_RANGE_MSG,
						HEATER_FAIL_READ_CH1_MSG,
						HEATER_FAIL_READ_CH2_MSG,
						TIMED_OUT_OF_CHANGE_FILAMENT,
						ERROR_STREAM_VERSION,
						ERROR_BOT_TYPE_REP1,
						ERROR_BOT_TYPE_REP2,
						ERROR_SRAM,
						ERROR_PLATFORM_HEATING_TIMEOUT,
						ERROR_HEATING_TIMEOUT,
						ERROR_TEMP_RESET_EXTERNALLY,
						ERROR_INVALID_PLATFORM,
						ERROR_INVALID_TOOL };

	InterfaceBoard& interfaceBoard = board.getInterfaceBoard();
	interfaceBoard.init();


	uint8_t msg_ptr_index = 0;

	    
	while (1) {
		// Host interaction thread.
		host::runHostSlice();	
		// Command handling thread.
		command::runCommandSlice();
		// Motherboard slice
		board.runMotherboardSlice();
		//Alert if SRAM/stack has been corrupted by running out of SRAM
#if defined(STACK_PAINT) && defined(DEBUG_SRAM_MONITOR)
		stackAlertCounter ++;
		if ( stackAlertCounter >= 5000 ) {
			if (( StackCount() == 0 )) {  //( ! stackAlertLockout ) && 
				board.errorResponse(ERROR_SRAM);
				stackAlertLockout = true;
			}
			stackAlertCounter = 0;
		}
#endif
		// check for new tones
		Piezo::runPiezoSlice();

		// Display screen to check for proper display of characters and lines
		if (interfaceBoard.buttonPushed()) {
			if (msg_ptr_index < NUMBER_OF_ERROR_MESSAGES - 1) {
				board.errorResponse(message_pointer[msg_ptr_index], false);
				msg_ptr_index++;
			}
		}

		// reset the watch dog timer
		wdt_reset();


	}
	return 0;
}

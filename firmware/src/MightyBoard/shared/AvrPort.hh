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

#ifndef SHARED_AVR_PORT_HH_
#define SHARED_AVR_PORT_HH_

#include <stdint.h>
#include <util/atomic.h>

#if defined (__AVR_ATmega168__) \
    || defined (__AVR_ATmega328__) \
    || defined (__AVR_ATmega644P__)

    typedef uint8_t port_base_t;
    #define NULL_PORT 0xff

#elif defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__)

    typedef uint16_t port_base_t;
    #define NULL_PORT 0xffff

#endif

#include <avr/io.h>

// The AVR port and pin mapping is based on a convention that has held true for all ATMega chips
// released so far: that the ports begin in sequence from register 0x00 from A onwards, and are
// arranged:
// 0 PINx
// 1 DDRx
// 2 PORTx
// This is verified true for the 168/328/644p/1280/2560.

// We support three platforms: Atmega168 (1 UART), Atmega644, and Atmega1280/2560
#if defined (__AVR_ATmega168__)     \
    || defined (__AVR_ATmega328__)  \
    || defined (__AVR_ATmega644P__) \
    || defined (__AVR_ATmega1280__) \
    || defined (__AVR_ATmega2560__)
#else
    #error UART not implemented on this processor type!
#endif


#define PINx _SFR_MEM8(port_base+0)
#define DDRx _SFR_MEM8(port_base+1)
#define PORTx _SFR_MEM8(port_base+2)

/// The port module represents an eight bit, digital IO port on the
/// AVR microcontroller. This library creates static
///
/// Porting notes:
/// Be sure to define all of the ports supported by your processor, and to
/// verify that the port registers follow the same convention as the 168.
/// \ingroup HardwareLibraries
class AvrPort {
private:
	const port_base_t port_base;
	friend class Pin;
public:
        AvrPort() :
	    port_base(NULL_PORT) {};
        AvrPort(port_base_t port_base_in) :
	    port_base(port_base_in) {
	};
        bool isNull() const {
	    return port_base == NULL_PORT;
	};
        void setPinDirectionOut(uint8_t pin_mask) const {
	        ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
			DDRx |= (uint8_t)pin_mask;
		}
	};
        void setPinDirectionIn(uint8_t pin_mask_inverted) const {
	        ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
			DDRx &= (uint8_t)pin_mask_inverted;
		}
	};
        bool getPin(uint8_t pin_mask) const {
	        return (uint8_t)((uint8_t)PINx & (uint8_t)pin_mask) != 0;
	};
        void setPinOn(uint8_t pin_mask) const {
	        ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { 
			PORTx |= (uint8_t)pin_mask;
		}
	};
        void setPinOff(uint8_t pin_mask_inverted) const {
	        ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
			PORTx &= (uint8_t)pin_mask_inverted;
		}
	};
};


#if defined(__AVR_ATmega644P__) || \
	defined(__AVR_ATmega1280__) || \
	defined(__AVR_ATmega2560__)
static const AvrPort PortA(0x20);
#endif // __AVR_ATmega644P__
static const AvrPort PortB(0x23);
static const AvrPort PortC(0x26);
static const AvrPort PortD(0x29);
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__)
static const AvrPort PortE(0x2C);
static const AvrPort PortF(0x2F);
static const AvrPort PortG(0x32);
static const AvrPort PortH(0x100);
static const AvrPort PortJ(0x103);
static const AvrPort PortK(0x106);
static const AvrPort PortL(0x109);
#endif //__AVR_ATmega1280__

static const AvrPort NullPort;

#endif // SHARED_AVR_PORT_HH_


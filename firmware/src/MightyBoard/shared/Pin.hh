#ifndef PIN_HH
#define PIN_HH

#include "AvrPort.hh"
#include "Pin.hh"

/// \ingroup HardwareLibraries
class Pin {
private:
	// const AvrPort port;
	const port_base_t port_base;
	const bool is_null;
	const uint8_t pin_index;
	const uint8_t pin_mask;
	const uint8_t pin_mask_inverted;
public:
	Pin() : port_base(NullPort.port_base), is_null(true), pin_index(0), pin_mask(0), pin_mask_inverted((uint8_t)~0) {}
	
	Pin(const AvrPort& port_in, uint8_t pin_index_in) : port_base(port_in.port_base), is_null(false), pin_index(pin_index_in), pin_mask((uint8_t)_BV(pin_index_in)), pin_mask_inverted((uint8_t)~_BV(pin_index_in)) {}
	
	bool isNull() const { return is_null; }
	
	void setDirection(bool out) const {
		// if (is_null)
		// 	return;
		uint8_t oldSREG = SREG;
                cli();
		if (out) {
			DDRx |= (uint8_t)pin_mask;
		} else {
			DDRx &= (uint8_t)pin_mask_inverted;
		}
		SREG = oldSREG;
	}

	bool getValue() const {
		if (is_null)
			return false; // null pin is always low ... ?
		return (uint8_t)((uint8_t)PINx & (uint8_t)pin_mask) != 0;
	}
	
	void setValue(bool on) const {
		// if (is_null)
		// 	return;
		uint8_t oldSREG = SREG;
                cli();
		if (on) {
			PORTx |= pin_mask;
		} else {
			PORTx &= pin_mask_inverted;
		}
		SREG = oldSREG;
	}
	// currently not used:
	//const uint8_t getPinIndex() const { return pin_index; }
};

static const Pin NullPin;

#endif // PIN_HH

#ifndef PIN_HH
#define PIN_HH

#include "AvrPort.hh"
#include "Pin.hh"

/// \ingroup HardwareLibraries
class Pin {
private:
	port_base_t port_base;
	bool is_null;
	uint8_t pin_index;
	uint8_t pin_mask;
	uint8_t pin_mask_inverted;

public:
	Pin();
	Pin(const AvrPort& port_in, uint8_t pin_index_in);
  Pin(const Pin& other_pin);
	bool isNull() const;
	void setDirection(bool out) const;

  void setValue(bool value) const;
  bool getValue() const;
};

static const Pin NullPin(NullPort, 0);

#endif // PIN_HH

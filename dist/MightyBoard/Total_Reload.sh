#!/bin/bash
# To run from the command line:
# >> ./Total_Reload.sh <REQUIRED firmware> <optional serial port> <optional 8U2 bootloader> <optional 1280 bootloader>


if test -z "$1"
	then
		echo "Please Specify a firmware file"
		exit
	else
		FILENAME = $1
fi

if test -z "$2" 
	then
		PORT=/dev/ttyACM0
	else
  		PORT=$2
fi

if test -z "$3"
	then
		8U2FIRMWARE=Makerbot-usbserial-revH-rep2.hex
	else
		8U2FIRMWARE = $3
fi

if test -z "$4" 
	then
		1280BOOTLOADER = ATmegaBOOT_168_atmega1280.hex
	else
		1280BOOTLOADER = $4
fi

# Store state of pass/fail variables
FAIL8U2="8U2 Bootloader PASS"
FAIL1280="1280 Bootloader PASS"
FAILUSB="USB Program PASS"

# Main loop to process forever
while true; do
	Do8U2upload()
	Do1280bootloader()
	Do1280firmware()
	if [ "$FAILUSB" == "USB Program FAIL" ]
		then
			echo "Programing the 1280 over USB has FAILED!"
			Do8U2reflash()
	fi
	echo "Process complete! If all operations passed, then this board is done. On to the next!"

Do8U2upload(){
	echo "Connect the AVRIPSmkII to the 8U2 Programing header"
	echo "Press Enter to begin 8U2 firmware upload"
	read
	# Upload 8u2 firmware and set fuses
	avrdude -p at90usb82 -F -P usb -c avrispmkii -U flash:w:$8U2FIRMWARE -U hfuse:w:0xD9:m -U efuse:w:0xF4:m -U lock:w:0x0F:m
	if [ $? -ne 0 ]
		then
			FAIL8U2="8U2 Bootloader FAIL"
	fi
	echo FAIL8U2
}

Do1280bootloader() {
	echo "Disconnect the AVRISPmkII from the 8U2, and re-connect it to the 1280 programming header"
	echo "Press Enter to begin 1280 bootloader upload"
	read
	avrdude -p m1280 -F -P usb -c avrispmkii -U flash:w:$1280BOOTLOADER -U lfuse:w:0xFF:m -U hfuse:w:0xDA:m -U efuse:w:0xF4:m -U lock:w:0x0F:m
	if [ $? -ne 0 ]
		then
			FAIL1280="1280 Bootloader FAIL"
	fi
	echo FAIL1280
}

Do1280firmware() {
	echo "Connect USB cable to mightyboard's USB port"
	echo "Press Enter to begin 1280 firmware upload, $FILENAME will be sent to $PORT"
	read
	# upload 1280 firmware via USB
	echo avrdude -F -p m1280 -P $PORT -c stk500v1 -b 57600 -U flash:w:$FILENAME
	if [ $? -ne 0 ]
		then
			FAILUSB="USB Program FAIL"
	fi
}

Do8U2reflash() {
	read -p "Re-flash the 8U2 and its fuses again? [Y/n] " -n 1 -r
	echo    # (optional) move to a new line
	if [[ $REPLY =~ ^[Yy]$ ]]
		then
			read "Connect the AVRIPSmkII to the 8U2 Programing header"
			read "Press enter to begin 8U2 rehabilitation"
			echo "Flashing firmware"
			avrdude -p at90usb82 -F -P usb -c avrispmkii -U flash:w:$8U2FIRMWARE
			echo "Flashing Fuses"
			avrdude -p at90usb82 -F -P usb -c avrispmkii -U lfuse:w:0xFF:m -U hfuse:w:0xD9:m -U efuse:w:0xF4:m -U lock:w:0x0F:m
			echo "Flashing Firmware Again"
			avrdude -p at90usb82 -F -P usb -c avrispmkii -U flash:w:$8U2FIRMWARE
	fi

}
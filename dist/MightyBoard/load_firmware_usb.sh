#!/bin/bash

# to run from the command line:   ./load_firmware_usb.sh firmware_filename port

# default firmware_filename is mighty_two_v7.2.1.hex
# default port is /dev/ttyACM0
# NB : On Mac OS X you can use /dev/tty.usbmodem* as a port

#cd $( dirname $( readlink -f "${BASH_SOURCE[0]}" ))

if test -z "$1"
then
  FILENAME=mighty_two_v7.2.1.hex
else
  FILENAME=$1
fi

if test -z "$2" 
then
  PORT=/dev/ttyACM0
else
  PORT=$2
fi

while true; do

FAILUSB="USB Program PASS"

   echo "Press Enter to upload 1280 firmware"
   read 

   # Upload firmware via usb
   avrdude -F -p m1280 -P $PORT -c stk500v1 -b 57600 -U flash:w:$FILENAME

   if [ $? -ne 0 ]
    then
       FAILUSB="USB Program FAIL"
    fi

	echo $FAILUSB
done

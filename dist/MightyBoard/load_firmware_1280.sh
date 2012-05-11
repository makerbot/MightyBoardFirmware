#!/bin/bash

cd $( dirname $( readlink -f "${BASH_SOURCE[0]}" ))

while true; do

FAILUSB="USB Program PASS"

    echo "Press Enter to Start"
    read
 
   # Upload firmware via usb
   avrdude -p m1280 -P usb -c avrispmkii
   avrdude -F -V -p m1280 -P /dev/ttyACM0 -c stk500v1 -b 57600 -U flash:w:Mighty-mb40-v5.2.hex

   if [ $? -ne 0 ]
    then
       FAILUSB="USB Program FAIL"
    fi

	echo $FAILUSB
done

#!/bin/bash




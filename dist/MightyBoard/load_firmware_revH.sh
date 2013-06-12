#!/bin/bash

# to run from the command line:   ./load_firmware_single.sh firmware_filename port

# default firmware_filename is mighty_two_v5.5.hex
# default port is /dev/ttyACM0

#cd $( dirname $( readlink -f "${BASH_SOURCE[0]}" ))

if test -z "$1"
then
  FILENAME=mighty_two_v6.0.0.hex
else
  FILENAME=$1
fi

if test -z "$2" 
then
  PORT=/dev/ttyACM0
else
  PORT=$2
fi

if test -z "$3"
then
  echo "This script requires a third argument of bot type ('REP2' or 'REP2X')"
  echo "ABORTING"
  exit
else
  BOT_TYPE=$3
fi

echo "$FILENAME" | grep -q 'mighty_two'
if [ $? -eq 0 ]
then
  if [ "$BOT_TYPE" == "REP2" ]
  then
    BOOT8U2=Makerbot-usbserial-revH-rep2.hex
  else
    if [ "$BOT_TYPE" == "REP2X" ]
    then
      BOOT8U2=Makerbot-usbserial-revH-rep2X.hex
    else
      echo "bot type specified is not 'REP2' or 'REP2X'"
      echo "ABORTING"
      exit
    fi
  fi
else
  echo "This script requires a mighty_two firmware file"
  echo "ABORTING"
  exit
fi

echo $BOOT8U2

while true; do

FAIL8U2="8U2 Bootloader PASS"
FAIL1280="1280 Bootloader PASS"
FAILUSB="USB Program PASS"

    echo "Press Enter upload 8U2 firmware"
    read

    # Upload fuses and lock bit first since if they are uploaded at the same time as the
    # firmare the 8u2 firmware fails to function properly
    avrdude -p at90usb82 -F -P usb -c avrispmkii -U lfuse:w:0xFF:m -U hfuse:w:0xD9:m -U efuse:w:0xF4:m -U lock:w:0x0F:m
    # Upload bootloader via isp
    avrdude -p at90usb82 -F -P usb -c avrispmkii -U flash:w:$BOOT8U2

    if [ $? -ne 0 ]
    then
     FAIL8U2="8U2 Bootloader FAIL"
    fi


   echo "Press Enter upload 1280 bootloader"
    read

    # Upload bootloader via isp
    avrdude -p m1280 -F -P usb -c avrispmkii -U flash:w:ATmegaBOOT_168_atmega1280.hex -U lfuse:w:0xFF:m -U hfuse:w:0xDA:m -U efuse:w:0xF4:m -U lock:w:0x0F:m

    if [ $? -ne 0 ]
     then
      FAIL1280="1280 Bootloader FAIL"
    # else
    #  sleep 10
    fi
  
   echo "Press Enter to upload 1280 firmware"
   read 

   # Upload firmware via usb
   avrdude -F -p m1280 -P $PORT -c stk500v1 -b 57600 -U flash:w:$FILENAME

   if [ $? -ne 0 ]
    then
       FAILUSB="USB Program FAIL"
    fi

	echo $FAIL8U2
	echo $FAIL1280
	echo $FAILUSB
done

#!/bin/bash




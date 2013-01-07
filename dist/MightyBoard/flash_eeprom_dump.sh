#!/bin/bash

# to run from the command line:   ./load_firmware_usb.sh firmware_filename port

# default firmware_filename is mighty_two_v5.5.hex
# default port is /dev/ttyACM0

#cd $( dirname $( readlink -f "${BASH_SOURCE[0]}" ))

if test -z "$1"
then
  FILENAME_F=flash_dump.hex
else
  FILENAME_F=$1
fi

if test -z "$2"
then
  FILENAME_E=eeprom_dump.hex
else
  FILENAME_E=$2
fi

if test -z "$3" 
then
  PORT=/dev/ttyACM0
else
  PORT=$3
fi

while true; do

FAILFLASH="Flash dump Success"
FAILEEPROM="Eeprom dump Success"

   echo "Press Enter to dump 1280 flash and eeprom"
   read 

   # dump flash
   avrdude -F -p m1280 -P $PORT -c stk500v1 -b 57600 -U flash:r:$FILENAME_F:i

   if [ $? -ne 0 ]
    then
       FAILFLASH="Flash dump FAIL"
    fi

   # dump eeprom
   avrdude -F -p m1280 -P $PORT -c stk500v1 -b 57600 -U eeprom:r:$FILENAME_E:i

   if [ $? -ne 0 ]
    then
       FAILEEPROM="Eeprom dump FAIL"
    fi

	echo $FAILFLASH
  echo $FAILEEPROM
done

#!/bin/bash




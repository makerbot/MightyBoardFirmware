#!/bin/bash


# read firmware + bootloader from atmega1280
avrdude  -v -p m1280 -c avrispmkii -b57600 -U flash:r:motor_test.hex:i -P usb

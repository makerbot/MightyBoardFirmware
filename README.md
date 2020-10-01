MEGA MIGHTY Replicator MightyBoard Firmware
===============================

This is the firmware repository for the Replicator, Replicator Dual, Replicator 2 & 2X desktop 3D-printing machines.

If you're getting started, please begin by reading the documentation for
the firmware:
http://wiki.makerbot.com/v2-firmware

This project contains the following subdirectories:
* firmware - this is the firmware, where active development takes place.
       See http://wiki.makerbot.com/v2-firmware for details on how to
       build and install the code.
* bootloader - this contains the bootloaders for the MCUs on the Mightyboard
* dist - this directory contains tools and scripts for quickly installing
       bootloaders and board images for the MightyBoard
* tests - this directory contains tests using the s3g driver and development testing data
* docs - info about command handling and firmware details

N.B. to generate the french version of the firmware, add the LOCALE=fr env
variable before compiling

To use the tests in s3g_tests, you must initialize the s3g submodule by running
git submodule init
git submodule update

Build the latest firmware version
===

___These instructions only apply to Mac OS X for now.___

You must first install `SCons` and `avr-libc` if you don't have it :

    $ brew install scons

Then :

    $ brew tap larsimmisch/avr
    $ brew install avr-libc --env=std

If you wish to upload, you must install `avrdude` if it is not yet present :

    $ brew install avrdude

> NB : if you haven't got `brew` installed, see http://mxcl.github.io/homebrew/ .

Make sure that you have installed the command line tools from Xcode. If you run into any problem while compiling, it may mean that you need to update your developer folder :

    $ sudo xcode-select -switch /Applications/Xcode.app/Contents/Developer/

If everything is fine, you should be able to run `xcrun -find gcc` and have the following output :

    $ xcrun -find gcc
    /Applications/Xcode.app/Contents/Developer/usr/bin/gcc

And at least these packages :

    $ brew list 
    [...] avr-binutils  avrdude  avr-gcc   avr-libc  libmpc  mpfr  scons [...]

To create the documentation, you will also need `doxygen` (and `graphviz` for nice vizualisations) :

    $ brew install doxygen
    $ brew install graphviz

Then, run :

    $ ./firmware/build_and_upload.sh

You will be prompted for the Replicator type (A or B for `mighty_one` or `mighty_two`, default: `mighty_two`) and the locale to use (available : `fr` and `en`, default : `en`). The script will build the firmware from the sources in the given locale and ask to upload to the connected Replicator.

> NB : A build output log is generated in `./firmware/build_and_upload.log`

Cleaning up
===

You can clean up a previously built version with :

    $ ./firmware/cleanup.sh [-f]

The `-f` option cleans up without prompting for confirmation.

Uploading only
===

To upload a new firmware to a Replicator via USB :

    $ ./dist/MightyBoard/load_firmware_usb.sh mighty_two_v7.3.10.hex /dev/tty.usbmodem*

where `mighty_two_v7.3.10.hex` is the corresponding firmware HEX file and `/dev/tty.usbmodem*` the port to use (this is the default port for all USB connectors on a Mac).

- - -
 
Credits 
=======

  - French localization ( < 7.2 ) : guyzmo (CKAB)
  - French localization ( > 7.2 ) : tchapi (CKAB)
  - Scripts improvements, updates and fixes : tchapi (CKAB) - 2013

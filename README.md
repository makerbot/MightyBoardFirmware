Replicator MightyBoard Firmware
===============================

This is the firmware repository for the Replicator, Replicator Dual, Replicator 2 & 2X desktop 3D-printing machines.

Build the latest firmware version
===

___These instructions only apply to Mac OS X for now.___

You must first install `SCons` if you don't have it :

    brew install scons

> NB : if you haven't got `brew` installed, see http://mxcl.github.io/homebrew/ .

To create the documentation, you will also need `doxygen` (and `graphviz` for nice vizualisations) :

    brew install doxygen
    brew install graphviz

Then, run :

    ./firmware/src/build_and_upload.sh

You will be prompted for the Replicator type (`mighty_one` or `mighty_two`, default: `mighty_two`) and the locale to use (available : `fr` and `en`, default : `en`). The script will build the firmware from the sources in the given locale and upload to the connected Replicator.

> NB : A build output log is generated in `./firmware/src/build_and_upload.log`

Cleaning up
===

You can clean up a previously built version with :

    ./firmware/src/cleanup.sh [-f]

The `-f` option cleans up without prompting for confirmation.

Upload
===

You must first install `avr-libc` :

    brew tap larsimmisch/avr
    brew install avr-libc

To upload a new firmware to a Replicator via USB :

    ./dist/MightyBoard/load_firmware_usb.sh mighty_two_v7.3.10.hex /dev/tty.usbmodem*

where `mighty_two_v7.3.10.hex` is the corresponding firmware HEX file and `/dev/tty.usbmodem*` the port to use.

- - -
 
Credits 
=======

  - French localization ( < 7.2 ) : guyzmo (CKAB)
  - French localization ( > 7.2 ) : tchapi (CKAB)
  - Scripts improvements, updates and fixes : tchapi (CKAB) - 2013
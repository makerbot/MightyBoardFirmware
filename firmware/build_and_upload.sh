#!/bin/bash

# ***
# Build script for the MightyBoard firmware. Takes no arguments.
# ***

# Common color helpers
RED='\033[01;31m' # bold red
GREEN='\033[01;32m' # green
RESET='\033[00;00m' # normal white

# Yeah.
BASEDIR=$(dirname $0)

# Paths
SCONS=${BASEDIR}"/SConstruct"
LOG_FILE=${BASEDIR}"/build_and_upload.log"

# Default locale and board
LOCALE="en"
BOARD="mighty_two"

function echo_fail {
    echo -e ${RED}"Failure"${RESET}
}
function echo_success {
    echo -e ${GREEN}"Success"${RESET}
}

function build_firmware {

    scons_file=$1

    echo -n " - Building firmware ($LOCALE) for $BOARD... "

    echo -e "\n\n" >> ${LOG_FILE}
    echo "Building firmware ($LOCALE) for $BOARD" >> ${LOG_FILE}

    scons -f ${scons_file} platform=${BOARD} locale=${LOCALE} >> ${LOG_FILE} 2>&1 

    if [ "$?" -ne "0" ]; then
        echo_fail
    else
        echo_success
    fi

}

function upload {

    echo ""
    echo -e ${RED}"   / \   "${RESET}" Make sure your Replicator is connected via USB"
    echo -e ${RED}"  / ! \  "${RESET}" and press "${RED}"Enter"${RESET}" to upload the built firmware"
    echo -e ${RED}" /_____\ "${RESET}" onto the machine .."
    read

    echo -n " - Uploading ... "

    avrdude -F -p m1280 -P /dev/tty.usbmodem* -c stk500v1 -b 57600 -U flash:w:${HEX_FILE}

    if [ "$?" -ne "0" ]; then
        echo_fail
    else
        echo_success
    fi

}

# Running :

echo ""

echo "Building latest version :"
echo "-------------------------"

echo -e "What board should we build for ?"
echo -e " A) Replicator and Replicator Dual Family"
echo -e " B) Replicator 2 and 2X Family "${GREEN}"[default]"${RESET}
read locale
case $locale in
    [aA] ) 
        BOARD="mighty_one"
        ;;
    [bB] ) 
        BOARD="mighty_two"
        ;;
    * ) 
        ;;
esac

echo -e "What locale should we build in ('en' or 'fr') ? ["${GREEN}"en"${RESET}"] : "
read locale
case $locale in
    fr|FR ) 
        LOCALE="fr"
        ;;
    en|EN )
        ;;
    * ) 
        ;;
esac

echo "Building firmware with locale : $LOCALE" >> ${LOG_FILE}

build_firmware ${SCONS}


HEX_FILE=`find ./build -type f -name "*.hex" -print`

if [ "$HEX_FILE" = "" ]; then 
    echo_fail
    exit 1
fi

echo ""
echo "Uploading :"
echo "-----------"

echo -e "The firmware has successfully been compiled in '"${GREEN}"$HEX_FILE"${RESET}"'."
echo -e "Do you wish to upload now via USB ? ["${GREEN}"no"${RESET}"] : "
read confirm
case $confirm in
    [Yy]* ) 
        upload
        ;;
    * ) 
        ;;
esac

echo ""

exit 0

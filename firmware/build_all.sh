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
LOG_FILE=${BASEDIR}"/build_all.log"
DOXYGEN_CONF=${BASEDIR}"/../MightyBoardFirmware.doxyfile"

# Platforms to build on
PLATFORMS=( rrmbv12 mb24 mb24-2560 mb40 ecv22 ecv34 )

function echo_fail {
    echo -e ${RED}"Failure"${RESET}
}
function echo_success {
    echo -e ${GREEN}"Success"${RESET}
}

function build_firmwares {

    platform_list_name="$1[*]"
    platform_list=(${!platform_list_name})
    scons_file=$2

    for platform in ${platform_list[@]}
    do
        echo -n " - Building firmware for $platform... "

        echo -e "\n\n\n\n" >> ${LOG_FILE}
        echo "Building firmware for $platform" >> ${LOG_FILE}

        scons -f ${scons_file} platform=${platform} >> ${LOG_FILE} 2>&1 

        if [ "$?" -ne "0" ]; then
            echo_fail
        else
            echo_success
        fi
    done

}

function build_documentation {

    echo -n " - Running Doxygen... "

    echo "Running Doxygen" >> ${LOG_FILE}
    echo -e "\n\n\n\n" >> ${LOG_FILE}
    doxygen ${DOXYGEN_CONF} >> ${LOG_FILE} 2>&1
    
    if [ "$?" -ne "0" ]; then
        echo_fail
    else
        echo_success
    fi

}

# Running :

echo ""

echo "Building all firmware :"
echo "-----------------------"

echo "Building all firmware" >> ${LOG_FILE}

build_firmwares PLATFORMS ${SCONS}

echo ""
echo "Building Documentation :"
echo "------------------------"
echo "Building documentation" >> ${LOG_FILE}

build_documentation

echo ""

exit 0

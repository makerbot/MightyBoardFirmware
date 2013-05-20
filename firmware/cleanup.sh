#!/bin/bash

# ***
# Cleanup script Takes no arguments.
# ***

# Common color helpers
RED='\033[01;31m' # bold red
GREEN='\033[01;32m' # green
RESET='\033[00;00m' # normal white

# Yeah.
BASEDIR=$(dirname $0)

# Force ?
FORCE=FALSE
while getopts f OPTION
do
    case ${OPTION} in
        f) FORCE=TRUE;;
    esac
done

function cleanup {

  # Deletes all .o
  if [ $FORCE == TRUE ]; then
    confirm="yes"
  else
    echo -e "Do you want to delete all *.o files ? ["${GREEN}"no"${RESET}"] : "
    read confirm
  fi

  case $confirm in
    [Yy]* ) find . -type f -name '*.o' -exec rm '{}' ';'
      ;;
    *)
      ;;
  esac

  # Deletes all build files
  if [ $FORCE == TRUE ]; then
    confirm="yes"
  else
    echo -e "Do you want to delete the build folder ? ["${GREEN}"no"${RESET}"] : "
    read confirm
  fi

  case $confirm in
    [Yy]* ) find . -type d \( -name 'build' -o -name '*_build' \) -exec rm -rf '{}' ';'
      ;;
    *)
      ;;
  esac

  # Deletes the build log
  if [ $FORCE == TRUE ]; then
    confirm="yes"
  else
    echo -e "Do you want to delete the build log ('build_*.log') ? ["${GREEN}"no"${RESET}"] : "
    read confirm
  fi

  case $confirm in
    [Yy]* ) find . -type f -name 'build_*.log' -exec rm '{}' ';'
      ;;
    *)
      ;;
  esac

  # Deletes the prevous .map file
  if [ $FORCE == TRUE ]; then
    confirm="yes"
  else
    echo -e "Do you want to delete the previous .map file ? ["${GREEN}"no"${RESET}"] : "
    read confirm
  fi

  case $confirm in
    [Yy]* ) find . -type f -name '*.map' -exec rm '{}' ';'
      ;;
    *)
      ;;
  esac

}

echo ""
if [ $FORCE == TRUE ]; then
  echo -e ${RED}"FORCE"${RESET}" Cleaning up stuff :"
  echo "-------------------------"
else
  echo "Cleaning up stuff :"
  echo "-------------------"
fi

cleanup

echo -e ${GREEN}"done."${RESET}
echo ""

exit 0

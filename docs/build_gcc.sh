#! /bin/sh
# vim:ai:ff=unix:sw=4:ts=4:

set -x
set -e

PREFIX=${HOME}/opt/avr/
export PREFIX

if -d ${PREFIX}
then
	echo Cannot find ${PREFIX}, exiting
	return
fi

PATH=${PREFIX}bin:${PATH}

BINUTILS_VERSION=2.21.1
MPC_VERSION=0.9
GCC_VERSION=4.6.2
AVR_LIBC_VERSION=1.8.0
AVRDUDE_VERSION=5.10

MPC_PREFIX=${HOME}/opt/mpc-${MPC_VERSION}

echo "########################"
echo apt-geting GMP, MPFR, MPC, Scons, avrdude
echo "########################"
sudo apt-get install libgmp-dev libmpfr-dev libmpc-dev scons avrdude
echo DONE

wget -N -P incoming http://ftp.gnu.org/gnu/binutils/binutils-${BINUTILS_VERSION}.tar.bz2
if test ! -d binutils-${BINUTILS_VERSION}
then
	bzip2 -dc incoming/binutils-${BINUTILS_VERSION}.tar.bz2 | tar xf -
	cd binutils-${BINUTILS_VERSION}
	mkdir obj-avr
	cd obj-avr
	../configure --prefix=${PREFIX} --target=avr --disable-nls --enable-install-libbfd
	make
	make install
	cd ../..
fi

# wget -N -P incoming http://www.multiprecision.org/mpc/download/mpc-${MPC_VERSION}.tar.gz
# if test ! -d mpc-${MPC_VERSION}
# then
# 	gzip -dc incoming/mpc-${MPC_VERSION}.tar.gz | tar xf -
# 	cd mpc-${MPC_VERSION}
# 	./configure --prefix=${MPC_PREFIX}
# 	make
# 	make install
# 	cd ..
# fi

# export LD_LIBRARY_PATH=${MPC_PREFIX}/lib/

wget -N -P incoming http://ftp.gnu.org/gnu/gcc/gcc-${GCC_VERSION}/gcc-core-${GCC_VERSION}.tar.bz2
wget -N -P incoming http://ftp.gnu.org/gnu/gcc/gcc-${GCC_VERSION}/gcc-g++-${GCC_VERSION}.tar.bz2
if test ! -d gcc-${GCC_VERSION}
then
	bzip2 -dc incoming/gcc-core-${GCC_VERSION}.tar.bz2 | tar xf -
	bzip2 -dc incoming/gcc-g++-${GCC_VERSION}.tar.bz2 | tar xf -
	cd gcc-${GCC_VERSION}
	mkdir obj-avr
	cd obj-avr
	../configure --prefix=$PREFIX --target=avr --enable-languages=c,c++ --enable-lto --disable-nls --disable-libssp --with-dwarf2 # --with-mpc=${MPC_PREFIX}
	make
	make install
	cd ../..
fi

wget -N -P incoming download.savannah.gnu.org/releases/avr-libc/avr-libc-${AVR_LIBC_VERSION}.tar.bz2

if test ! -d avr-libc-${AVR_LIBC_VERSION}
then
	bzip2 -dc incoming/avr-libc-${AVR_LIBC_VERSION}.tar.bz2 | tar xf -
	if test -f incoming/avr-libc-${AVR_LIBC_VERSION}-gcc-${GCC_VERSION}.patch
	then
		patch -p0 < incoming/avr-libc-${AVR_LIBC_VERSION}-gcc-${GCC_VERSION}.patch
		# cd avr-libc-${AVR_LIBC_VERSION}
		# autoreconf
		# cd ..
	fi
	cd avr-libc-${AVR_LIBC_VERSION}
	./configure --prefix=${PREFIX} --build=$(./config.guess) --host=avr
	make
	make install
	cd ..
fi

# if test ! -d avrdude-${AVRDUDE_VERSION}
# then
# 	gzip -dc incoming/avrdude-${AVRDUDE_VERSION}.tar.gz | tar xf -
# 	cd avrdude-${AVRDUDE_VERSION}
# 	./configure --prefix=${HOME}/opt/avrdude-${AVRDUDE_VERSION}
# 	make
# 	make install
# 	cd ..
# fi

echo "#################################################################"
echo NB: "[avr-]gcc/g++" has been built to ${HOME}/opt/avr/bin.
echo To permanently add ${HOME}/opt/avr/bin to your PATH, please edit
echo ~/.bashrc and prefix PATH with ${HOME}/opt/avr/bin.
echo "#################################################################"


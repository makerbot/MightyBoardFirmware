#! /bin/sh
# vim:ai:ff=unix:sw=4:ts=4:

set -x
set -e

USRNAME=`whoami`
PREFIX=/home/${USRNAME}/opt/avr/
export PREFIX

PATH=${PREFIX}bin:${PATH}

BINUTILS_VERSION=2.22
MPC_VERSION=0.9
MPFR_VERSION=3.1.1
GCC_VERSION=4.6.3
AVR_LIBC_VERSION=1.7.1
AVRDUDE_VERSION=5.10

MPC_PREFIX=/home/${USRNAME}/opt/mpc-${MPC_VERSION}

if test ! -d binutils-${BINUTILS_VERSION}
then
	wget -N -P incoming http://ftp.gnu.org/gnu/binutils/binutils-${BINUTILS_VERSION}.tar.bz2
	bzip2 -dc incoming/binutils-${BINUTILS_VERSION}.tar.bz2 | tar xf -
fi
if test ! -d binutils-${BINUTILS_VERSION}/obj-avr
then
	cd binutils-${BINUTILS_VERSION}
	mkdir obj-avr
	cd obj-avr
	../configure --prefix=${PREFIX} --target=avr --disable-nls --enable-install-libbfd
	make
	make install
	cd ../..
fi

#if test ! -d  mpfr-${MPFR_VERSION}
#then
#	wget -N -P incoming http://www.mpfr.org/mpfr-current/mpfr-${MPFR_VERSION}.tar.bz2
#	bzip2 -dc incoming/mpfr-${MPFR_VERSION}.tar.bz2 | tar xf -
#fi

#if test ! -d mpfr-${MPFR_VERSION}/obj-avr
#	cd mpfr-${MPFR_VERSION}
#	configure --prefix=${PREFIX} 
#exit

if test ! -d mpc-${MPC_VERSION}
then
	wget -N -P incoming http://www.multiprecision.org/mpc/download/mpc-${MPC_VERSION}.tar.gz
 	gzip -dc incoming/mpc-${MPC_VERSION}.tar.gz | tar xf -
 	cd mpc-${MPC_VERSION}
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/me/local/lib
	#apt-get install  libgmp4-dev # may be needed for gmp.h header
 	./configure --prefix=${MPC_PREFIX} 
 	make
 	make install
 	cd ..
fi

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

wget -N -P incoming http://download.savannah.gnu.org/releases/avr-libc/avr-libc-1.7.1.tar.bz2
if test ! -d avr-libc-${AVR_LIBC_VERSION}
then
	bzip2 -dc incoming/avr-libc-${AVR_LIBC_VERSION}.tar.bz2 | tar xf -
	if test -f incoming/avr-libc-${AVR_LIBC_VERSION}-gcc-${GCC_VERSION}.patch
	then
		cd avr-libc-${AVR_LIBC_VERSION}
		patch -p1 < ../incoming/avr-libc-${AVR_LIBC_VERSION}-gcc-${GCC_VERSION}.patch
		# autoreconf
		cd ..
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
# 	./configure --prefix=/home/mws/opt/avrdude-${AVRDUDE_VERSION}
# 	make
# 	make install
# 	cd ..
# fi

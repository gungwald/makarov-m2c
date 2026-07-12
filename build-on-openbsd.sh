#!/bin/ksh

if [ ! -f /usr/include/libucontext/ucontext.h ] || [ ! -f /usr/lib/libucontext.a ]
then
    echo Run build-libucontext.sh or build/install libucontext first.
    exit
fi

# OpenBSD inappropriately installs all its prebuilt packages into /usr/local
# but we're stuck with that unless we force the user to update PATH and
# specify the includes and libs on every command...

PREFIX=/usr/local
BINDIR="$PREFIX"/bin
LIBDIR="$PREFIX"/libdata/m2c
MAN1DIR="$PREFIX"/man/man1
INCLUDEDIR="$PREFIX"/include
DOCDIR="$PREFIX"/share/doc/m2c
LDFLAGS='-L/usr/lib/libucontext -lucontext'

. ./build-common.sh

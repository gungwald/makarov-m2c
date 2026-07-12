#!/bin/sh

PREFIX=/usr/local
BINDIR="$PREFIX"/bin
LIBDIR="$PREFIX"/lib/m2c
MAN1DIR="$PREFIX"/share/man/man1
INCLUDEDIR="$PREFIX"/include
CC=x86_64-w64-mingw32-gcc

# Only run configure if Makefile.tmpl has been updated or it has not been run yet.
if [ ! -f Makefile ] || [ Makefile.tmpl -nt Makefile ]
then
    ./configure +cc="$CC" || exit
fi

if [ $# -gt 0 ]
then
  make CC="$CC" \
      bindir="$BINDIR" \
      libdir="$LIBDIR" \
      man1dir="$MAN1DIR" \
      includedir="$INCLUDEDIR" \
      "$1"
  exit
fi

make CC="$CC" \
    bindir="$BINDIR" \
    libdir="$LIBDIR" \
    includedir="$INCLUDEDIR" \
    man1dir="$MAN1DIR" || exit

sudo make install CC="$CC" \
    bindir="$BINDIR" \
    libdir="$LIBDIR" \
    includedir="$INCLUDEDIR" \
    man1dir="$MAN1DIR" || exit

make CC="$CC" \
    bindir="$BINDIR" \
    libdir="$LIBDIR" \
    includedir="$INCLUDEDIR" \
    man1dir="$MAN1DIR" \
    release


#!/bin/sh

PREFIX=/usr/local
BINDIR="$PREFIX"/bin
LIBDIR="$PREFIX"/lib/m2c
MAN1DIR="$PREFIX"/share/man/man1
INCLUDEDIR="$PREFIX"/include
CC=cl65

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

./configure +cc="$CC" || exit

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


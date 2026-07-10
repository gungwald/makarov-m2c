#!/bin/sh

BINDIR=/usr/local/bin
LIBDIR=/usr/local/lib/m2c
MAN1DIR=/usr/local/share/man/man1
INCLUDEDIR=/usr/local/include

if [ $# -gt 0 ]
then
  make CC=gcc \
      bindir="$BINDIR" \
      libdir="$LIBDIR" \
      man1dir="$MAN1DIR" \
      includedir="$INCLUDEDIR" \
      "$1"
  exit
fi

./configure +cc=gcc

make CC=gcc \
    bindir="$BINDIR" \
    libdir="$LIBDIR" \
    includedir="$INCLUDEDIR" \
    man1dir="$MAN1DIR"

sudo make install CC=gcc \
    bindir="$BINDIR" \
    libdir="$LIBDIR" \
    includedir="$INCLUDEDIR" \
    man1dir="$MAN1DIR"

make CC=gcc \
    bindir="$BINDIR" \
    libdir="$LIBDIR" \
    includedir="$INCLUDEDIR" \
    man1dir="$MAN1DIR" \
    release


#!/bin/ksh

# OpenBSD inappropriately installs all its prebuilt packages into /usr/local
# so we want to put it somewhere other than /usr/local because this is not
# package installed with pkg_add.

PREFIX=/opt/makarov/m2c
BINDIR="$PREFIX"/bin
LIBDIR="$PREFIX"/lib/m2c
MAN1DIR="$PREFIX"/share/man/man1
INCLUDEDIR="$PREFIX"/include
CC=gcc

# I don't know OpenBSD renames gcc to egcc
alias gcc=egcc

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


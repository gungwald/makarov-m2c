# makarov-m2c

This is the Modula-2 to C translator written by Vladimir N. Makarov. 
It is based on the language as defined in the 4th edition of Wirth's book,
*Programming in Modula-2*, a.k.a. *PIM4*. It also supports the third 
edition of the book, *PIM3*. High portability is achieved 
through intermediate translation into C99. POSIX-based systems are the 
target platform.

## Build Instructions

### Run the configure script

To specify where to find the sources, as an argument +srcdir to
configure:

     ../m2c-0.7/configure +srcdir=../m2c-0.7

You can use option `+cc' if you wish that configure will not ask
about C compiler name. For example:

      configure +cc=gcc

This program and its files, unless otherwise noted, were originally
licensed under the original GPL.

### Run make

The ```configure```-script generated Makefile understands the variables:
```bindir```, ```libdir```, ```man1dir```, and ```prefix```. Use only the
full path name for directories.

           make install prefix=/usr/users/VHDL/mak
 
                           or

           make install bindir=/usr/users/VHDL/mak/bin\
                libdir=/usr/users/VHDL/mak/lib\
                /usr/users/VHDL/mak/man/man1

### Run make install
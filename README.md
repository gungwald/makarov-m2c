# makarov-m2c

This is the Modula-2 to C translator written by Vladimir N. Makarov. 
It is based on the language as defined in the 4th edition of Wirth's book,
*Programming in Modula-2*, a.k.a. *PIM4*. It also supports the third 
edition of the book, *PIM3*. High portability is achieved 
through intermediate translation into C99. POSIX-based systems are the 
target platform.

## License

This program and its files, are licensed under the GPL2. See the COPYING 
file for details.

## Advantages Over the GNU Modula-2 Compiler (gm2)

* It compiles in a few seconds, while gm2 takes many hours or days on
older hardware.
* It is more portable because it only requires a C99 compiler, while
gm2 only supports certain platforms.
* It is easier to install because it does not require a large number 
of dependencies, while gm2 requires many libraries and tools.
* It is easier to get it to compile successfully.

No disrespect to the GNU Modula-2 Compiler. It is a good compiler.

## History

See the [ChangeLog](ChangeLog) file or git history for a detailed
history of the project.

| Year      | Person    |
|:---:|:--:|
| 2026      | Bill Chatfield |
| 2016      | Xin Wang |
| 2014-2015 | D. E. Evans |
| 2014      | Peter De Wachter |
| 1991-1997 | Vladimir N. Makarov |

## Build Instructions

### Requirements

* A C compiler that supports C99, such as TCC or GCC 4.9 or later.
* GNU Make or compatible version. BSD Make has not been tested.
* Archive utility (ar) for creating static libraries.

### Overview

1. ./configure +cc=<compiler_name>
2. make CC=<compiler> prefix=<install_path>
3. make install prefix=<install_path>

### Details

#### Run the configure script

The configure script argument `+srcdir`, which specifies 
where to find the sources, causes the build to fail, so
avoid using it until it is fixed.

Use option `+cc` to prevent configure from asking
about C compiler name. For example:

    ./configure +cc=gcc

#### Run make

The ```configure```-script generated Makefile understands the variables:
```bindir```, ```libdir```, ```man1dir```, and ```prefix```. Use only the
full path name for directories.

    make CC=gcc prefix=/usr/local

                           or

    make CC=gcc \
        bindir=/usr/local/bin \
        libdir=/usr/local/lib/m2c \
        man1dir=/usr/local/man/man1 \
        includedir=/usr/local/include/m2c

#### Run make install

    sudo make install prefix=/usr/local

                           or

    sudo make install CC=gcc \
        bin=/usr/local/bin \
        lib=/usr/local/lib/m2c \
        man1=/usr/local/man/man1 \
        includedir=/usr/local/include/m2c


## Binary Distribution

* Fedora Linux (latest version only)

    * Setup [RPM Sphere](https://rpmsphere.github.io/)
    * Install the package `m2c`

      ```
      sudo dnf install m2c
      ``` 

* Any Linux - download
  the latest release from the [Releases](https://github.com/gungwald/makarov-m2c/releases) page.

## Documentation

* A very good [Modula-2 Tutor](doc/modula-2-tutor-by-g-dodrill.pdf) by Gordon Dodrill in PDF format.
* Nicholas Wirth's [Programming in Modula-2](https://freepages.modula2.org/report4/modula-2.html),
4th edition (PIM4), which is the exact version of the language that this compiler
implements. It has been converted to HTML so it is a good on-line reference.
The original PDF is also available from the same site.

## Code

```modula-2
MODULE HelloWorld;

FROM InOut IMPORT WriteString, WriteLn;

BEGIN
    WriteString("Hello world!");
    WriteLn;
END HelloWorld.
```

## Compiling

Structure:
```
m2c -o <output_executable_name> -make <modula2_source_file>
```

Example:
```bash
$ m2c -o helloworld -make HelloWorld.mod
$ ./helloworld 
Hello world!
```

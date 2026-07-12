SELF=`basename "$0"`

fail()
{
    echo "$SELF": $* 1>&2
    exit 1
}

getCompiler()
{
    if [ -n "$CC" ]
    then
        echo $CC
    elif type gcc > /dev/null
    then
        echo gcc
    elif type egcc > /dev/null
    then
        echo egcc
    elif [ `uname -s` = 'OpenBSD' ]
    then
        fail Install egcc and try again, nimwit.
    else
        fail Try installing a real compiler.
    fi
}

getAdminCommand()
{
    if type sudo > /dev/null
    then
        echo sudo
    elif type doas > /dev/null
    then
        echo doas
    else
        fail Neither the \"sudo\" nor the \"doas\" command exists. Fix it. Aborting.
    fi
}

runMake()
{
    unset AS_ADMIN ARGS
    for ARG in "$@"
    do
        if [ "$ARG" = asAdmin ]
        then
            AS_ADMIN=`getAdminCommand`
        else
            ARGS="$ARGS $ARG"
        fi
    done
    # It is required that the same directories are always used, for example for install and uninstall.
    $AS_ADMIN make CC=`getCompiler` EXTERN_LDFLAGS="$EXTERN_LDFLAGS" \
        bindir="$BINDIR" \
        libdir="$LIBDIR" \
        man1dir="$MAN1DIR" \
        includedir="$INCLUDEDIR" \
        docdir="$DOCDIR" \
        $ARGS
}

# Only run configure if Makefile.tmpl has been updated or it has not been run yet.
if [ ! -f Makefile ] || [ Makefile.tmpl -nt Makefile ]
then
    ./configure +cc="$CC" || exit
fi

if [ $# -gt 0 ]
then
    runMake "$@"
    exit
fi

runMake 
runMake asAdmin install 
runMake release


AC_INIT([ccalc], [1.0])                                                                                                                 
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([ccalc.c])
AC_CONFIG_HEADERS([config.h])

LT_INIT
AC_ENABLE_SHARED
AC_ENABLE_STATIC

# Checks for programs.
AC_PROG_CC
AC_PROG_RANLIB

# Common compiler flags
CFLAGS="-Wall -O2"

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h termios.h])

AC_CONFIG_FILES([Makefile
                 complex/Makefile])
AC_OUTPUT

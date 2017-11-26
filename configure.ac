AC_INIT([ccalc], [1.0])                                                                                                                 
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([ccalc.c])
AC_CONFIG_HEADERS([config.h])

LT_INIT([static])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_LN_S
AC_PROG_LIBTOOL

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h termios.h])

AC_CONFIG_FILES([Makefile
                 complex/Makefile])
AC_OUTPUT

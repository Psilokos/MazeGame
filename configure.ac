dnl Autoconf settings for MazeGame

AC_PREREQ(2.69)
AC_INIT(mazegame, 0.1)

AM_INIT_AUTOMAKE
AC_CONFIG_HEADERS([config.h])

dnl
dnl  Check for tools
dnl

AC_PROG_CC_STDC
AC_PROG_CC_C_O
AC_PROG_CXX
AC_PROG_CPP

dnl  Libtool
LT_INIT

dnl
dnl  Check for compiler properties
dnl

AC_C_INLINE
AC_C_RESTRICT

dnl
dnl  Check for libdl
dnl

dnl
dnl  Compiler flags
dnl

AX_APPEND_COMPILE_FLAGS([-Wall -Wextra -Werror], [CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wall -Wextra -Werror], [CXXFLAGS])

dnl  C/C++ preprocessor flags
CPPFLAGS = '-isystem $(top_srcdir)/include ${CPPFLAGS}'

dnl
dnl  Configuration is finished
dnl

AC_CONFIG_FILES([
  Makefile
  bin/Makefile
  src/Makefile
  plugins/Makefile
])

dnl  Generate makefiles
AC_OUTPUT

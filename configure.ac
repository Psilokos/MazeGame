dnl Autoconf settings for MazeGame

AC_PREREQ(2.69)
AC_INIT(mazegame, 0.1)

AC_CONFIG_MACRO_DIRS([m4])

AM_INIT_AUTOMAKE
AC_CONFIG_HEADERS([config.h])

dnl
dnl  Check for tools
dnl

AC_PROG_CC_STDC
AC_PROG_CC_C_O
AC_PROG_CXX
AC_PROG_CPP

dnl
dnl  Libtool
dnl

LT_INIT
LT_LANG([C++])

dnl
dnl  Check for compiler properties
dnl

AC_C_INLINE
AC_C_RESTRICT

dnl
dnl  Check for OpenGL
dnl

PKG_CHECK_MODULES([GL], [gl], [], [AC_MSG_ERROR([OpenGL is required.])])
PKG_CHECK_MODULES([GLEW], [glew])

dnl Check for Magick++
PKG_CHECK_MODULES([MAGICK], [Magick++])

dnl
dnl  Compiler flags
dnl

AX_APPEND_COMPILE_FLAGS([-Wall -Wextra -Werror], [CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wall -Wextra -Werror], [CXXFLAGS])

dnl
dnl  Configuration is finished
dnl

AC_CONFIG_FILES([
  Makefile
  bin/Makefile
  src/Makefile
  engines/Makefile
  engines/graphics_rendering_engine/Makefile
])

dnl Generate makefiles
AC_OUTPUT

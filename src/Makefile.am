###########
# Headers #
###########

noinst_HEADERS = \
	$(top_srcdir)/include/Image.hpp

####################
# Building libcore #
####################

libcore_la_SOURCES = \
	Image.cpp \
	Plugin.cpp
libcore_la_CXXFLAGS = $(AM_CXXFLAGS) $(LD_CFLAGS)
libcore_la_LDFLAGS = $(LD_LIBS)

lib_LTLIBRARIES = libcore.la

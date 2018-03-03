###########
# Headers #
###########

noinst_HEADERS = \
	$(top_srcdir)/include/CompileTime.hpp \
	$(top_srcdir)/include/Image.hpp

####################
# Building libcore #
####################

lib_LTLIBRARIES = libcore.la

libcore_la_SOURCES = \
	Image.cpp
libcore_la_CXXFLAGS = -I $(top_srcdir)/include $(MAGICK_CFLAGS)
libcore_la_LDFLAGS = $(MAGICK_LIBS)

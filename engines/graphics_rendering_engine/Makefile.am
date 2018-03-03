GREdir = $(enginesdir)/graphics_rendering_engine

libGRE_la_SOURCES = \
	Texture.cpp
libGRE_la_CXXFLAGS = -I $(top_srcdir)/include $(GL_CFLAGS) $(GLEW_CFLAGS) $(MAGICK_CFLAGS)
libGRE_la_LDFLAGS = $(GL_LIBS) $(GLEW_LIBS)

GRE_LTLIBRARIES = libGRE.la

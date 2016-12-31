AM_CPPFLAGS =

lib_LTLIBRARIES = libmipjson.la

libmipjson_la_LDFLAGS = -L$(libdir) -lmiptknzr -version-info 1:0:0

libmipjson_la_SOURCES = \
   config.h \
   mip_unicode.h \
   mip_json_obj.h \
   mip_exception.h \
   mip_json_parser.h \
   mip_json_obj.cc \
   mip_json_parser.cc 

AM_CXXFLAGS = $(INTI_CFLAGS) \
   -std=c++14 \
   -I$(top_srcdir)/include \
   -I$(top_srcdir)/mip/miptknzr/include


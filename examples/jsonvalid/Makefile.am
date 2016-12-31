SUBDIRS =
sbin_PROGRAMS = 

AM_CPPFLAGS = \
   -g \
   -I$(top_srcdir)/include \
   -I$(top_srcdir)/mip/miptknzr/include

jsonvalid_CXXFLAGS = \
   -std=c++14 \
   -g 

jsonvalid_SOURCES = \
   jsonvalid.cc

AM_CXXFLAGS = ${jsonvalid_CXXFLAGS}

jsonvalid_LDADD = \
   -L../../lib/.libs/ -L../../mip/miptknzr/lib/.libs -lmipjson -lmiptknzr

sbin_PROGRAMS += \
   jsonvalid 


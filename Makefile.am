ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libpath-respect-wrapper.la

libpath_respect_wrapper_la_SOURCES = src/path-respect-wrapper.c
libpath_respect_wrapper_la_CPPFLAGS = $(PROCPS_CFLAGS) $(SYSTEMD_JOURNAL_CFLAGS)
libpath_respect_wrapper_la_LIBADD = $(PROCPS_LIBS) $(SYSTEMD_JOURNAL_LIBS)
libpath_respect_wrapper_la_LDFLAGS = -version-info 0:0:0

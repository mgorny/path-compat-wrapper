ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libpath-compat-wrapper.la

libpath_compat_wrapper_la_SOURCES = src/path-compat-wrapper.c
libpath_compat_wrapper_la_CPPFLAGS = $(PROCPS_CFLAGS) $(SYSTEMD_JOURNAL_CFLAGS)
libpath_compat_wrapper_la_LIBADD = $(PROCPS_LIBS) $(SYSTEMD_JOURNAL_LIBS)
libpath_compat_wrapper_la_LDFLAGS = -version-info 0:1:0

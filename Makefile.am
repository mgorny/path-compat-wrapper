ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libpath-compat-wrapper.la

libpath_compat_wrapper_la_SOURCES = src/path-compat-wrapper.c
libpath_compat_wrapper_la_CPPFLAGS = $(PROCPS_CFLAGS) $(SYSTEMD_JOURNAL_CFLAGS)
libpath_compat_wrapper_la_LIBADD = $(PROCPS_LIBS) $(SYSTEMD_JOURNAL_LIBS)
libpath_compat_wrapper_la_LDFLAGS = -version-info 0:1:0

bin_SCRIPTS = src/path-compat-mkwrap

EXTRA_DIST = src/path-compat-mkwrap.in
CLEANFILES = $(bin_SCRIPTS)

SUFFIXES = .in

.in:
	rm -f $@ $@.tmp
	@SED@ -e "s|[@]CC@|${CC}|" -e "s|[@]CFLAGS@|${CFLAGS}|" \
		-e "s|[@]LDFLAGS@|${LDFLAGS}|" ${srcdir}/$@.in > $@.tmp
	chmod a-w,+x $@.tmp
	mv $@.tmp $@

EXTRA_DIST += NEWS
NEWS: configure.ac Makefile.am
	git for-each-ref refs/tags --sort '-*committerdate' \
		--format '# %(tag) (%(*committerdate:short))%0a%(contents:body)' \
		> NEWS

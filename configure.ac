AC_PREREQ([2.60])
AC_INIT([path-respect-wrapper], [0.1.1])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([1.8 foreign dist-bzip2 subdir-objects])

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES])

AC_PROG_CC
AC_USE_SYSTEM_EXTENSIONS

LT_INIT([disable-static])

AC_ARG_ENABLE([systemd-journal],
	[AS_HELP_STRING([--disable-systemd-journal],
		[Disable use of systemd-journal])])
AS_IF([test x"$enable_systemd_journal" != x"no"], [
	PKG_CHECK_MODULES([SYSTEMD_JOURNAL], [libsystemd-journal],[
		AC_DEFINE([HAVE_SYSTEMD_JOURNAL], [1], [Define if you have systemd-journal])
	],)
])

AC_CONFIG_HEADER([config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT

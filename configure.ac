AC_PREREQ([2.60])
AC_INIT([path-respect-wrapper], [0.1])
AC_CONFIG_AUX_DIR([build-aux])

AM_INIT_AUTOMAKE([1.8 foreign dist-bzip2 subdir-objects])

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES])

AC_PROG_CC
AC_USE_SYSTEM_EXTENSIONS

PKG_CHECK_MODULES([PROCPS], [libprocps],, [
	AC_CHECK_LIB([proc], [readproc],,
		[AC_MSG_ERROR([Error: required library proc not found! Please install procps.])])
])

AC_CONFIG_HEADER([config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT

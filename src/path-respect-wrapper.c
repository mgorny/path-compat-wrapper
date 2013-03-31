/**
 * Wrapper checking whether apps respect PATH and not hardcode paths.
 * (c) 2013 Michał Górny
 * 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <syslog.h>
#include <unistd.h>

extern const char* real_name;
extern const char* real_path;

void complain()
{
	const char* parent_name;
	char buf[256];
	FILE* f;

	snprintf(buf, sizeof(buf), "/proc/%d/cmdline", getppid());
	f = fopen(buf, "r");
	if (f)
	{
		size_t rd = fread(buf, 1, sizeof(buf), f);
		size_t i;

		/* join parameters with spaces */
		for (i = 0; i < rd; ++i)
		{
			if (!buf[i])
				buf[i] = ' ';
		}

		fclose(f);

		if (rd > 0)
		{
			/* and null-terminate */
			buf[rd-1] = 0;
			parent_name = buf;
		}
	}
	else
		parent_name = "[unable to read /proc]";

	/* Use journal if available. Fallback to syslog. */
#ifdef HAVE_SYSTEMD_JOURNAL
	if (sd_journal_print(LOG_WARNING,
				"%s run with no respect to $PATH by %d (%s)",
				real_name, getppid(), parent_name))
	{
#endif

	openlog("path-respect-wrapper", LOG_CONS, LOG_USER);
	syslog(LOG_WARNING, "%s run with no respect to $PATH by %d (%s)",
			real_name, getppid(), parent_name);
	closelog();

#ifdef HAVE_SYSTEMD_JOURNAL
	}
#endif
}

int main(int argc, char* argv[])
{
	complain();

	execv(real_path, argv);

	fprintf(stderr, "execv(%s) failed: %s\n", real_path, strerror(errno));
	return 127;
}

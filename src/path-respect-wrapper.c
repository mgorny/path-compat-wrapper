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

#include <proc/readproc.h>

extern const char* real_name;
extern const char* real_path;

void complain()
{
	pid_t pids[2] = { getppid(), 0 };
	PROCTAB* proc = openproc(PROC_FILLCOM | PROC_PID, pids, 1);
	const char* parent_name;

	if (proc)
	{
		proc_t p;
		memset(&p, 0, sizeof(p));
		if (readproc(proc, &p))
			parent_name = p.cmdline[0];
		else
			parent_name = "[unable to read procfs]";
	}
	else
		parent_name = "[unable to open procfs]";

	openlog("path-respect-wrapper", LOG_CONS, LOG_USER);
	syslog(LOG_WARNING, "%s run with no respect to $PATH by %d (%s)",
			real_name, getppid(), parent_name);
	closelog();

	if (proc)
		closeproc(proc);
}

int main(int argc, char* argv[])
{
	complain();

	execv(real_path, argv);

	fprintf(stderr, "execv(%s) failed: %s\n", real_path, strerror(errno));
	return 127;
}

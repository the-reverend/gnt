#include <stdio.h>
#include <unistd.h>
#include <libcgi.h>

#include "private.h"

#define LOGWEB "/webdir/gnt/helpers/logweb"


global void logweb(char *prog, char *str)
  { int pid = fork(); /* ignore fork/exec errors */
    if (pid == 0)
      { close(1); close(2);	/* close stdout, stderr */
	execl(LOGWEB, "logweb", prog, str, NULL);
	_exit(255);
      }
  }


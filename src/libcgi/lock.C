#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <libcgi.h>

#include "private.h"

#ifndef notdef
#include <errno.h>
#endif


global bool lock_database(char *lfn)
  { int lfd = -1, ntries = 0;
    while (lfd < 0 && ntries < 10)
      { lfd = open(lfn, O_CREAT | O_EXCL, 0);
	if (lfd < 0) sleep(1);
	ntries++;
      }
    if (lfd >= 0) close(lfd);
    return (lfd >= 0);
  }

global void unlock_database(char *lfn)
  { unlink(lfn);
  }


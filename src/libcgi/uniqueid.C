#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <libcgi.h>

#include "private.h"


/* Returns a unique non-zero 7-digit number associated with this process
   Format is:  DHppppp
   where:  D = day number in week (0=Sun .. 6=Sat)
	   H = decidays (0 .. 9)
	   p = pid
*/

static int uid = 0;

global int uniqueid()
  { if (uid == 0)
      { /* calc only once, in case time changes between calls! */
	int w = (time(NULL) / 8640 + 40) % 70;
	int p = getpid();
	if (p <= 0 || p > 99999) abort();
	uid = (w * 100000) + p;
      }
    return uid;
  }


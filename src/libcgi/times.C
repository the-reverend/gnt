#include <string.h>
#include <bits/time.h>
#include <sys/times.h>

#include <libcgi.h>

#include "private.h"

global ftimes getftimes()
  { tms t;
    int irt = times(&t);
    int ict = t.tms_utime + t.tms_cutime + t.tms_stime + t.tms_cstime;
    return ftimes((float) irt / (float) CLOCKS_PER_SEC,
		  (float) ict / (float) CLOCKS_PER_SEC);
  }

global ftimes operator - (ftimes ft1, ftimes ft2)
  { return ftimes(ft1.rt - ft2.rt, ft1.ct - ft2.ct);
  }


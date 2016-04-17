#include <stdio.h>
#include <sys/stat.h>
#include <libcgi.h>

#include "private.h"

global unsigned int filemode(char *fn)
  { struct stat statbuf;
    int code = stat(fn, &statbuf);
    return (code == 0) ? (statbuf.st_mode & 0xffff) : 0;
  }

global int filetime(char *fn)
  { struct stat statbuf;
    int code = stat(fn, &statbuf);
    return (code == 0) ? statbuf.st_mtime : 0;
  }

global int filesize(char *fn)
  { struct stat statbuf;
    int code = stat(fn, &statbuf);
    return (code == 0) ? statbuf.st_size : 0;
  }


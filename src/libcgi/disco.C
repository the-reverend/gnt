#include <stdio.h>
#include <libcgi.h>

#include "private.h"


global void discard_output()
  { /* discard output so far */
    #ifdef __linux__
	stdout -> _IO_write_ptr = stdout -> _IO_write_base;
    #else
	stdout -> _ptr -= stdout -> _cnt;
	stdout -> _cnt = 0;
    #endif
  }


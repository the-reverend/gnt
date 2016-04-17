#include <stdio.h>
#include <stdlib.h>
#include <libcgi.h>

#include "private.h"


global void cgi_fatal(char *msg, char *p1)  /* for private use by library */
  { discard_output();
    printf("Content-type: text/html\n\n");
    printf("<HTML>\n");
    printf("<h2> Error! </h2>\n");
    printf(msg, p1); printf(" <br>\n");
    exit(0);
  }


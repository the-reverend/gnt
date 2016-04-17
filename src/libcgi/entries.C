#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libcgi.h>

#include "private.h"

#define MAXENTRIES  40
#define MAXSTR	    1440

global entry entries[MAXENTRIES];
global int numentries;

static char *query;
static int qptr;

static void decodequery();
static char *xgetenv(char*);
static char *makeword(char*);
static int gethex();
static char *copystring(char*);
static char *getifset(char *nam);


global void getentries()
  { char *ms = xgetenv("REQUEST_METHOD");
    if (seq(ms, "POST"))
      { int clen = atoi(xgetenv("CONTENT_LENGTH"));
	query = new char[clen+1];
	int nc = 0;
	while (nc < clen)
	  { int ch = getchar();
	    if (ch < 0) break;
	    query[nc++] = ch;
	  }
	query[nc] = '\0';
	decodequery();
	delete query;
      }
    else if (seq(ms, "GET"))
      { query = xgetenv("QUERY_STRING");
	decodequery();
      }
    else cgi_fatal("You can't use this script like that!  Seek help.");
  }

static void decodequery()
  { qptr = 0;
    until (query[qptr] == '\0' || numentries >= MAXENTRIES)
      { entries[numentries].nam = makeword("=&");
	if (query[qptr] == '=') qptr++;
	entries[numentries].val = makeword("&");
	if (query[qptr] == '&') qptr++;
	numentries++;
      }
    unless (query[qptr] == '\0') cgi_fatal("Bug: too many entries; seek help.");
  }

static char *xgetenv(char *s)
  { char *val = getenv(s);
    if (val == NULL) cgi_fatal("Bug: parameter ``%s'' is not set.", s);
    return val;
  }

static char *makeword(char *stop)
  { char vec[MAXSTR+1]; int p = 0;
    until (strchr(stop, query[qptr]) != NULL || p >= MAXSTR)
      { if (query[qptr] == '+')
	  { vec[p++] = ' ';
	    qptr++;
	  }
	else if (query[qptr] == '%' && query[qptr+1] != '\0' && query[qptr+2] != '\0')
	  { qptr++;
	    vec[p++] = gethex();
	  }
	else vec[p++] = query[qptr++];
      }
    while (p > 0 && vec[p-1] == ' ') p--;
    vec[p] = '\0';
    if (strchr(stop, query[qptr]) == NULL) cgi_fatal("Parameter too big!");
    return copystring(vec);
  }

static int gethex()
  { int n = 0;
    for (int i = 0; i < 2; i++)
      { int c = query[qptr++] & 0xff;
	int k = (c >= '0' && c <= '9') ? (c-'0') :
		(c >= 'A' && c <= 'F') ? (c-'A') + 10 :
		(c >= 'a' && c <= 'f') ? (c-'a') + 10 : 0;	/* ignore errors */
	n = (n << 4) | k;
      }
    return n;
  }

static char *copystring(char *s)
  { int len = strlen(s);
    return strcpy(new char[len+1], s);
  }

global char *getval(char *nam)
  { char *val = getifset(nam);
    if (val == NULL) cgi_fatal("Key ``%s'' is not set.", nam);
    return val;
  }

global bool isset(char *nam)
  { return (getifset(nam) != NULL);
  }

static char *getifset(char *nam)
  { int i = 0;
    until (i >= numentries || seq(entries[i].nam, nam)) i++;
    return (i < numentries) ? entries[i].val : NULL;
  }


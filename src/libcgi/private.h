#include <string.h>

#define global
#define unless(x)   if(!(x))
#define until(x)    while(!(x))

extern void cgi_fatal(char*, char* = NULL);	/* for private use by library */

inline bool seq(char *s1, char *s2) { return strcmp(s1,s2) == 0; }


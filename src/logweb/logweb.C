#include <stdio.h>
#include <string.h>
#include <pwd.h>

#define global
#define unless(x)   if(!(x))
#define until(x)    while(!(x))

typedef unsigned int uint;

extern "C"
  { char *getenv(char*), *ctime(int*);
    void umask(uint), exit(int);
    int time(void*), geteuid();
  };

#define NSLOOKUP "/usr/bin/nslookup"

static void usage();
static char *whoami(), *getaddress(), *lookuphost(char*);
static bool getline(char*, FILE*);
static void giveup(char *msg, char *p1 = NULL);

inline bool starts(char *s1, char *s2) { return strncmp(s1, s2, strlen(s2)) == 0; }
inline char *check(char *s)	       { return (s != NULL) ? s : (char *)"???";          }


global main(int argc, char **argv)
  { unless (argc == 3) usage();
    umask(066);
    char *fn = argv[1];
    if (strpbrk(fn, "./") != NULL) giveup("bad log filename! %s", fn); /* fn mustn't contain '.' or '/' */
    char *who = whoami();
    char path[256]; sprintf(path, "/www/usr/%s/logs/%s", who, fn);
    int clock = time(NULL); char *ctim = ctime(&clock); ctim[24] = '\0'; /* delete nl */
    char *addr = getaddress();
    char *host = lookuphost(addr);
    FILE *fi = fopen(path, "a");
    if (fi == NULL) giveup("can't append to log file %s", path);
    fprintf(fi, "%s %s (%s) : %s\n", &ctim[4], check(host), check(addr), argv[2]);
    fclose(fi);
    exit(0);
  }

static void usage()
  { fprintf(stderr, "Usage: logweb logfn 'msg'\n");
    exit(2);
  }

static char *whoami()
  { passwd *pwd = getpwuid(geteuid());
    if (pwd == NULL) giveup("whoami failed");
    char *who = pwd -> pw_name;
    if (who == NULL) giveup("whoami failed");
    return who;
  }

static char *getaddress()
  { char *addr = getenv("HTTP_X_FORWARDED_FOR");        /* set if request came via proxy */
    if (addr == NULL) addr = getenv("REMOTE_ADDR");     /* direct request */
    return addr;
  }

static char *lookuphost(char *addr)
  { /* given IP address, determine host name */
    char *host = NULL;
    unless (addr == NULL)
      { int n = strspn(addr, ".0123456789");    /* must check before using as arg to popen */
	if (addr[n] == '\0')
	  { char cmd[256];
	    sprintf(cmd, "%s %s", NSLOOKUP, addr);
	    FILE *fi = popen(cmd, "r");
	    if (fi != NULL)
	      { char line[256];
		bool ok = getline(line, fi);
		while (ok)  /* continue reading to eof */
		  { if (starts(line, "Name:"))
		      { int p = 0;
			until (line[p] == ' ' || line[p] == '\t' || line[p] == '\0') p++;
			while (line[p] == ' ' || line[p] == '\t') p++;
			unless (line[p] == '\0')
			  { host = strdup(&line[p]);
			    if (host == NULL) giveup("no room!");
			  }
		      }
		    ok = getline(line, fi);
		  }
		int code = pclose(fi);
		if (code != 0) host = NULL;
	      }
	  }
      }
    return host;
  }

static bool getline(char *line, FILE *fi)
  { int ch = getc(fi);
    int n = 0;
    until (ch == '\n' || ch < 0 || n >= 255)
      { unless (ch == '\r') line[n++] = ch;
	ch = getc(fi);
      }
    line[n] = '\0';
    until (ch == '\n' || ch < 0) ch = getc(fi);
    bool eof = (ch < 0 && n == 0);
    return !eof;
  }

static void giveup(char *msg, char *p1)
  { fprintf(stderr, "logweb: ");
    fprintf(stderr, msg, p1); putc('\n', stderr);
    exit(1);
  }


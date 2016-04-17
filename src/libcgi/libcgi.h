/*** entries ***/

struct entry
  { char *nam;
    char *val;
  };

extern entry entries[];
extern int numentries;

extern void getentries();
extern char *getval(char*);
extern bool isset(char*);

/*** times ***/

struct ftimes
  { ftimes(float r, float c) { rt = r; ct = c; }
    float rt;	/* real time (secs) */
    float ct;	/* cpu time (secs)  */
  };

extern ftimes getftimes();
extern ftimes operator - (ftimes, ftimes);

/*** fstat ***/

extern unsigned int filemode(char*);
extern int filetime(char*), filesize(char*);

/*** logweb ***/

extern void logweb(char*, char*);

/* uniqueid */

extern int uniqueid();

/*** lock ***/

extern bool lock_database(char*);
extern void unlock_database(char*);

/*** disco ***/

extern void discard_output();



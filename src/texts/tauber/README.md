# Greek New Testament

James Tauber's GNT file is at:
http://www.znet.com/~broman/tauber-morph.zip

Files in this directory:

* gnt-morph.txt   Tauber's description of his file
* ajf-changes	   A list of changes made by me (A.J. Fisher)
* gnt-morph.3.gz  Tauber's file, with my corrections incorporated

## convert to sql

1. gzip -d gnt-morph.3.gz
1. source ./make.sh gnt-morph.3
1. sqlite3 -init gnt-morph.3.sql gnt-morph.3.sqlite

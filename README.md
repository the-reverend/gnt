# Building and Installing the Greek New Testament Web service

Original Author: Tony Fisher, Department of Computer Science, University of York, York, UK

## Conditions of Use

You are free to install and use this software for non-profit making purposes on condition that you retain the attribution to the original author of the software.

## Procedure

This software was not originally developed with the intention of being easily distributed, so we have had to massage it a bit to make it as straightforward as we reasonably can, but the procedure is still some way from being fully automated.

The installation directory for GNT on your Web server defaults to /webdir/gnt, with a URL of http://your.web.server/webdirforurl/gnt.  The following instructions contain details of instances of this pathname and URL that you will need to change.

This has been tested on Slackware 10 Linux with the 2.6 kernel.  If you encounter problems with installing it under another operating system then we are afraid you will have to figure those out for yourself.

1. Obtain and unpack the file gnt.tar.gz, which creates a subdirectory gnt.  You must have done this already if you are reading this file!
2. Obtain the current version of libgd from http://www.boutell.com/gd/ and install under the gnt/src/libgd directory.  This should just require unpacking it, and typing "configure" then "make" in its source directory.  
copy ./libs/libgd.a to gnt/src/lib/libgd.a  
copy gd.h, gdfx.h and gd_io.h to the gnt/src/include directory.  
alternatively follow instructions here: http://libgd.bitbucket.org/pages/faq.html on ubuntu, use apt-get: sudo apt-get install libgd2-xpm-dev
3. cd gnt/src/logweb  
edit Makefile: change pathname for WEBDIR.  
type "make", then "make install".
4. cd gnt/src/libcgi  
edit logweb.C: change the pathname for LOGWEB.  
type "make".
5. cd /gnt/src/gnt  
edit Makefile: change pathname for WEBDIR.  
edit gnt.h: change GNTPROG to the URL where the CGI script will live (which might or might not be under /webdir/gnt, depending on your Web server).  This should be the same as the value of webdir/cgi-bin set in Makefile.  change the URLs for ATWORKGIF and GNTHOME, and the pathname for LOCKFILE.  
edit common.C: change the pathnames for ZIPFILE, BINFILE and CACHEDIR, and the URL in CACHEURL.  
type "make", then "make install".
6. cd /gnt/src/html  
edit chapters.html: modify the URLs to the CGI executable  
edit correct.html: modify the URLS on lines 7 and 16  
edit search.html: modify the URL on line 9  
edit text.html: modify the URL on line 25
7. cd /gnt/src  
edit Makefile: change pathname for WEBDIR  
type "make install".

## Note

This program generates a cache of gif files under /webdir/gnt/cachedir, and our experience has been that over time this cache becomes very large (many thousands of files), to the extent that it can cause the parent filesystem to run out of inodes.

Please be aware of this, and be prepared to clear out the cache directory from time to time.

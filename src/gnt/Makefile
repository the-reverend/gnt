WEBDIR = /webdir/gnt

bindir = ${WEBDIR}/cgi-bin
libdir = ../lib
incdir = ../include

CXXFLAGS = -O -c -I${incdir} -Wno-deprecated
CC = g++

objs   = main.o search.o translit.o morph.o common.o util.o

all:		gnt

install:
		test -d ${bindir} || mkdir ${bindir}
		mv gnt ${bindir}/gnt

gnt:		${objs} ${libdir}/libcgi.a
		${CC} ${objs} -o gnt -L${libdir} -lcgi -lgd -lm -lpng -lz

clean:
		rm -f ${objs}


common.C:	gnt.h ${incdir}/libcgi.h ${incdir}/gd.h
main.C:		gnt.h ${incdir}/libcgi.h ${incdir}/gd.h
morph.C:	gnt.h ${incdir}/libcgi.h ${incdir}/gd.h
search.C:	gnt.h ${incdir}/libcgi.h ${incdir}/gd.h
translit.C:	gnt.h ${incdir}/libcgi.h ${incdir}/gd.h
util.C:		gnt.h ${incdir}/libcgi.h ${incdir}/gd.h

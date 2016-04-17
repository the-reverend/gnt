libdir = ../lib
incdir = ../include

CXXFLAGS = -O -I${incdir}

objs = entries.o times.o fstat.o logweb.o uniqueid.o lock.o fatal.o disco.o

all:		    ${incdir}/libcgi.h ${libdir}/libcgi.a

${libdir}/libcgi.a:   ${objs}
		    rm -f ${libdir}/libcgi.a
		    ar cr ${libdir}/libcgi.a ${objs}

${incdir}/libcgi.h:   libcgi.h
		    cp libcgi.h ${incdir}/libcgi.h


disco.C:	${incdir}/libcgi.h private.h
entries.C:	${incdir}/libcgi.h private.h
fatal.C:	${incdir}/libcgi.h private.h
fstat.C:	${incdir}/libcgi.h private.h
lock.C:		${incdir}/libcgi.h private.h
logweb.C:	${incdir}/libcgi.h private.h
times.C:	${incdir}/libcgi.h private.h
uniqueid.C:	${incdir}/libcgi.h private.h

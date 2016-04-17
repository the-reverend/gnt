
WEBDIR = /webdir/gnt

bindir	 = ${WEBDIR}/helpers

CXXFLAGS = -O

all: logweb

install: 
		test -d ${WEBDIR} || mkdir ${WEBDIR}
		test -d ${bindir} || mkdir ${bindir}
		mv logweb ${bindir}/logweb
		chmod 755 ${bindir}/logweb


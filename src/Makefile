WEBDIR = /webdir/gnt

install:
	test -d ${WEBDIR} || mkdir ${WEBDIR}
	cp html/*.html ${WEBDIR}
	test -d ${WEBDIR}/cachedir || mkdir ${WEBDIR}/cachedir
	test -d ${WEBDIR}/chargifs || (mkdir ${WEBDIR}/chargifs && cp chargifs/* ${WEBDIR}/chargifs)
	test -d ${WEBDIR}/etc || (mkdir ${WEBDIR}/etc && cp etc/* ${WEBDIR}/etc)
	test -d ${WEBDIR}/icons || (mkdir ${WEBDIR}/icons && cp icons/* ${WEBDIR}/icons)
	test -d ${WEBDIR}/texts || mkdir ${WEBDIR}/texts
	test -d ${WEBDIR}/texts/tauber || (mkdir ${WEBDIR}/texts/tauber && cp texts/tauber/* ${WEBDIR}/texts/tauber)

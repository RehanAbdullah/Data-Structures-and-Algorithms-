ifdef NDEBUG
  ndebug=-DNDEBUG
else
  ndebug=
endif

ifndef INSTALLROOT
  INSTALLROOT=${HOME}
endif

sources = set.h set.c makefile any.h README
derived = set.o
CLIST_DIR = ../clist

all: set.o

set.o: set.h set.c any.h
	gcc -g -c -I${CLIST_DIR} ${ndebug} set.c 

clean:
	/bin/rm -f $(derived) *.o

install:
	make clean
	make all
	if [ ! -d "${INSTALLROOT}/include" ]; then mkdir ${INSTALLROOT}/include; fi
	if [ ! -f "${INSTALLROOT}/include/any.h" ]; then /bin/cp any.h ${INSTALLROOT}/include; fi
	if [ ! -d "${INSTALLROOT}/lib" ]; then mkdir ${INSTALLROOT}/lib; fi
	/bin/cp set.h ${INSTALLROOT}/include
	ar rcs ${INSTALLROOT}/lib/liblist_sets.a set.o
	
zip:
	/bin/rm -rf ds
	mkdir ds
	mkdir ds/set
	cp $(sources) ds/set
	tar cvf ds.set.tar ds
	/bin/rm -f ds.set.tar.gz
	gzip ds.set.tar
	/bin/rm -rf ds


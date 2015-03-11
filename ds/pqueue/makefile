ifdef NDEBUG
  ndebug=-DNDEBUG
else
  ndebug=
endif

ifndef INSTALLROOT
  INSTALLROOT=${HOME}
endif

sources = pqueue.h array_pqueue.c linked_pqueue.c makefile any.h README
derived = array_pqueue.o linked_pqueue.o

all: array_pqueue.o \
     linked_pqueue.o

array_pqueue.o: pqueue.h array_pqueue.c any.h
	gcc -c ${ndebug} array_pqueue.c

linked_pqueue.o: pqueue.h linked_pqueue.c any.h
	gcc -c ${ndebug} linked_pqueue.c

clean:
	/bin/rm -f $(derived) *.o

install:
	make clean
	make all
	if [ ! -d "${INSTALLROOT}/include" ]; then mkdir ${INSTALLROOT}/include; fi
	if [ ! -f "${INSTALLROOT}/include/any.h" ]; then /bin/cp any.h ${INSTALLROOT}/include; fi
	if [ ! -d "${INSTALLROOT}/lib" ]; then mkdir ${INSTALLROOT}/lib; fi
	/bin/cp pqueue.h ${INSTALLROOT}/include
	ar rcs ${INSTALLROOT}/lib/libarray_pqueues.a array_pqueue.o
	ar rcs ${INSTALLROOT}/lib/liblinked_pqueues.a linked_pqueue.o
	
zip:
	/bin/rm -rf ds
	mkdir ds
	mkdir ds/pqueue
	cp $(sources) ds/pqueue
	tar cvf ds.pqueue.tar ds
	/bin/rm -f ds.pqueue.tar.gz
	gzip ds.pqueue.tar
	/bin/rm -rf ds


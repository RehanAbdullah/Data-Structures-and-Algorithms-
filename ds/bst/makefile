ifdef NDEBUG
  ndebug=-DNDEBUG
else
  ndebug=
endif

ifndef INSTALLROOT
  INSTALLROOT=${HOME}
endif

sources = bst_header.sh bst.sh makefile any.h README
derived = bst_any.h bst_any.c \
          bst_long.h bst_long.c \
          bst_int.h bst_int.c \
          bst_short.h bst_short.c \
          bst_char.h bst_char.c \
          bst_float.h bst_float.c \
          bst_double.h bst_double.c
          
all: bst_any.o \
     bst_long.o \
     bst_int.o \
     bst_short.o \
     bst_char.o \
     bst_float.o \
     bst_double.o

bst_any.h: bst_header.sh any.h
	./bst_header.sh any

bst_long.h: bst_header.sh
	./bst_header.sh long

bst_int.h: bst_header.sh
	./bst_header.sh int

bst_short.h: bst_header.sh
	./bst_header.sh short

bst_char.h: bst_header.sh
	./bst_header.sh char

bst_float.h: bst_header.sh
	./bst_header.sh float

bst_double.h: bst_header.sh
	./bst_header.sh double

bst_any.o: bst.sh bst_any.h any.h
	./bst.sh any
	gcc -g -c ${ndebug} bst_any.c

bst_long.o: bst.sh bst_long.h
	./bst.sh long
	gcc -g -c ${ndebug} bst_long.c

bst_int.o: bst.sh bst_int.h
	./bst.sh int
	gcc -g -c ${ndebug} bst_int.c

bst_short.o: bst.sh bst_short.h
	./bst.sh short
	gcc -g -c ${ndebug} bst_short.c

bst_char.o: bst.sh bst_char.h
	./bst.sh char
	gcc -g -c ${ndebug} bst_char.c

bst_float.o: bst.sh bst_float.h
	./bst.sh float
	gcc -g -c ${ndebug} bst_float.c

bst_double.o: bst.sh bst_double.h
	./bst.sh double
	gcc -g -c ${ndebug} bst_double.c

clean:
	/bin/rm -f $(derived) *.o

install:
	make clean
	make all
	if [ ! -d "${INSTALLROOT}/include" ]; then mkdir ${INSTALLROOT}/include; fi
	if [ ! -f "${INSTALLROOT}/include/any.h" ]; then /bin/cp any.h ${INSTALLROOT}/include; fi
	if [ ! -d "${INSTALLROOT}/lib" ]; then mkdir ${INSTALLROOT}/lib; fi
	/bin/cp bst*.h ${INSTALLROOT}/include
	ar rcs ${INSTALLROOT}/lib/liblinked_bsts.a bst*.o
	
zip:
	/bin/rm -rf ds
	mkdir ds
	mkdir ds/bst
	cp $(sources) ds/bst
	tar cvf ds.bst.tar ds
	/bin/rm -f ds.bst.tar.gz
	gzip ds.bst.tar
	/bin/rm -rf ds



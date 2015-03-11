ifdef NDEBUG
  ndebug=-DNDEBUG
else
  ndebug=
endif

ifndef INSTALLROOT
  INSTALLROOT=${HOME}
endif

sources = ss_header.sh ss.sh makefile any.h README
derived = ss_any.h ss_any.c \
          ss_long.h ss_long.c \
          ss_int.h ss_int.c \
          ss_short.h ss_short.c \
          ss_char.h ss_char.c \
          ss_float.h ss_float.c \
          ss_double.h ss_double.c
          
all: ss_any.o \
     ss_long.o \
     ss_int.o \
     ss_short.o \
     ss_char.o \
     ss_float.o \
     ss_double.o

ss_any.h: ss_header.sh any.h
	./ss_header.sh any

ss_long.h: ss_header.sh
	./ss_header.sh long

ss_int.h: ss_header.sh
	./ss_header.sh int

ss_short.h: ss_header.sh
	./ss_header.sh short

ss_char.h: ss_header.sh
	./ss_header.sh char

ss_float.h: ss_header.sh
	./ss_header.sh float

ss_double.h: ss_header.sh
	./ss_header.sh double

ss_any.o: ss.sh ss_any.h any.h
	./ss.sh any
	gcc -g -c ${ndebug} ss_any.c

ss_long.o: ss.sh ss_long.h
	./ss.sh long
	gcc -g -c ${ndebug} ss_long.c

ss_int.o: ss.sh ss_int.h
	./ss.sh int
	gcc -g -c ${ndebug} ss_int.c

ss_short.o: ss.sh ss_short.h
	./ss.sh short
	gcc -g -c ${ndebug} ss_short.c

ss_char.o: ss.sh ss_char.h
	./ss.sh char
	gcc -g -c ${ndebug} ss_char.c

ss_float.o: ss.sh ss_float.h
	./ss.sh float
	gcc -g -c ${ndebug} ss_float.c

ss_double.o: ss.sh ss_double.h
	./ss.sh double
	gcc -g -c ${ndebug} ss_double.c

clean:
	/bin/rm -f $(derived) *.o

install:
	make clean
	make all
	if [ ! -d "${INSTALLROOT}/include" ]; then mkdir ${INSTALLROOT}/include; fi
	if [ ! -f "${INSTALLROOT}/include/any.h" ]; then /bin/cp any.h ${INSTALLROOT}/include; fi
	if [ ! -d "${INSTALLROOT}/lib" ]; then mkdir ${INSTALLROOT}/lib; fi
	/bin/cp ss*.h ${INSTALLROOT}/include
	ar rcs ${INSTALLROOT}/lib/libss.a ss*.o
	
zip:
	/bin/rm -rf ds
	mkdir ds
	mkdir ds/ss
	cp $(sources) ds/ss
	tar cvf ds.ss.tar ds
	/bin/rm -f ds.ss.tar.gz
	gzip ds.ss.tar
	/bin/rm -rf ds



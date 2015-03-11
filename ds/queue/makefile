ifdef NDEBUG
  ndebug=-DNDEBUG
else
  ndebug=
endif

ifndef INSTALLROOT
  INSTALLROOT=${HOME}
endif

sources = queue_header.sh array_queue.sh linked_queue.sh makefile any.h README
derived = queue_any.h array_queue_any.c linked_queue_any.c \
          queue_long.h array_queue_long.c linked_queue_long.c \
          queue_int.h array_queue_int.c linked_queue_int.c \
          queue_short.h array_queue_short.c linked_queue_short.c \
          queue_char.h array_queue_char.c linked_queue_char.c \
          queue_float.h array_queue_float.c linked_queue_float.c \
          queue_double.h array_queue_double.c linked_queue_double.c
          
all: array_queue_any.o \
     array_queue_long.o \
     array_queue_int.o \
     array_queue_short.o \
     array_queue_char.o \
     array_queue_float.o \
     array_queue_double.o \
     linked_queue_any.o \
     linked_queue_long.o \
     linked_queue_int.o \
     linked_queue_short.o \
     linked_queue_char.o \
     linked_queue_float.o \
     linked_queue_double.o

queue_any.h: queue_header.sh any.h
	./queue_header.sh any

queue_long.h: queue_header.sh
	./queue_header.sh long

queue_int.h: queue_header.sh
	./queue_header.sh int

queue_short.h: queue_header.sh
	./queue_header.sh short

queue_char.h: queue_header.sh
	./queue_header.sh char

queue_float.h: queue_header.sh
	./queue_header.sh float

queue_double.h: queue_header.sh
	./queue_header.sh double

array_queue_any.o: array_queue.sh queue_any.h any.h
	./array_queue.sh any
	gcc -c ${ndebug} array_queue_any.c

array_queue_long.o: array_queue.sh queue_long.h
	./array_queue.sh long
	gcc -c ${ndebug} array_queue_long.c

array_queue_int.o: array_queue.sh queue_int.h
	./array_queue.sh int
	gcc -c ${ndebug} array_queue_int.c

array_queue_short.o: array_queue.sh queue_short.h
	./array_queue.sh short
	gcc -c ${ndebug} array_queue_short.c

array_queue_char.o: array_queue.sh queue_char.h
	./array_queue.sh char
	gcc -c ${ndebug} array_queue_char.c

array_queue_float.o: array_queue.sh queue_float.h
	./array_queue.sh float
	gcc -c ${ndebug} array_queue_float.c

array_queue_double.o: array_queue.sh queue_double.h
	./array_queue.sh double
	gcc -c ${ndebug} array_queue_double.c

linked_queue_any.o: linked_queue.sh queue_any.h any.h
	./linked_queue.sh any
	gcc -c ${ndebug} linked_queue_any.c

linked_queue_long.o: linked_queue.sh queue_long.h
	./linked_queue.sh long
	gcc -c ${ndebug} linked_queue_long.c

linked_queue_int.o: linked_queue.sh queue_int.h
	./linked_queue.sh int
	gcc -c ${ndebug} linked_queue_int.c

linked_queue_short.o: linked_queue.sh queue_short.h
	./linked_queue.sh short
	gcc -c ${ndebug} linked_queue_short.c

linked_queue_char.o: linked_queue.sh queue_char.h
	./linked_queue.sh char
	gcc -c ${ndebug} linked_queue_char.c

linked_queue_float.o: linked_queue.sh queue_float.h
	./linked_queue.sh float
	gcc -c ${ndebug} linked_queue_float.c

linked_queue_double.o: linked_queue.sh queue_double.h
	./linked_queue.sh double
	gcc -c ${ndebug} linked_queue_double.c

clean:
	/bin/rm -f $(derived) *.o

install:
	make clean
	make all
	if [ ! -d "${INSTALLROOT}/include" ]; then mkdir ${INSTALLROOT}/include; fi
	if [ ! -f "${INSTALLROOT}/include/any.h" ]; then /bin/cp any.h ${INSTALLROOT}/include; fi
	if [ ! -d "${INSTALLROOT}/lib" ]; then mkdir ${INSTALLROOT}/lib; fi
	/bin/cp *queue*.h ${INSTALLROOT}/include
	ar rcs ${INSTALLROOT}/lib/libarray_queues.a array_queue*.o
	ar rcs ${INSTALLROOT}/lib/liblinked_queues.a linked_queue*.o

zip:
	/bin/rm -rf ds
	mkdir ds
	mkdir ds/queue
	cp $(sources) ds/queue
	tar cvf ds.queue.tar ds
	/bin/rm -f ds.queue.tar.gz
	gzip ds.queue.tar
	/bin/rm -rf ds


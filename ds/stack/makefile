ifdef NDEBUG
  ndebug=-DNDEBUG
else
  ndebug=
endif

ifndef INSTALLROOT
  INSTALLROOT=${HOME}
endif

sources = stack_header.sh array_stack.sh linked_stack.sh makefile any.h README
derived = stack_any.h array_stack_any.c linked_stack_any.c \
          stack_long.h array_stack_long.c linked_stack_long.c \
          stack_int.h array_stack_int.c linked_stack_int.c \
          stack_short.h array_stack_short.c linked_stack_short.c \
          stack_char.h array_stack_char.c linked_stack_char.c \
          stack_float.h array_stack_float.c linked_stack_float.c \
          stack_double.h array_stack_double.c linked_stack_double.c
          
all: array_stack_any.o \
     array_stack_long.o \
     array_stack_int.o \
     array_stack_short.o \
     array_stack_char.o \
     array_stack_float.o \
     array_stack_double.o \
     linked_stack_any.o \
     linked_stack_long.o \
     linked_stack_int.o \
     linked_stack_short.o \
     linked_stack_char.o \
     linked_stack_float.o \
     linked_stack_double.o

stack_any.h: stack_header.sh any.h
	./stack_header.sh any

stack_long.h: stack_header.sh
	./stack_header.sh long

stack_int.h: stack_header.sh
	./stack_header.sh int

stack_short.h: stack_header.sh
	./stack_header.sh short

stack_char.h: stack_header.sh
	./stack_header.sh char

stack_float.h: stack_header.sh
	./stack_header.sh float

stack_double.h: stack_header.sh
	./stack_header.sh double

array_stack_any.o: array_stack.sh stack_any.h any.h
	./array_stack.sh any
	gcc -c ${ndebug} array_stack_any.c

array_stack_long.o: array_stack.sh stack_long.h
	./array_stack.sh long
	gcc -c ${ndebug} array_stack_long.c

array_stack_int.o: array_stack.sh stack_int.h
	./array_stack.sh int
	gcc -c ${ndebug} array_stack_int.c

array_stack_short.o: array_stack.sh stack_short.h
	./array_stack.sh short
	gcc -c ${ndebug} array_stack_short.c

array_stack_char.o: array_stack.sh stack_char.h
	./array_stack.sh char
	gcc -c ${ndebug} array_stack_char.c

array_stack_float.o: array_stack.sh stack_float.h
	./array_stack.sh float
	gcc -c ${ndebug} array_stack_float.c

array_stack_double.o: array_stack.sh stack_double.h
	./array_stack.sh double
	gcc -c ${ndebug} array_stack_double.c

linked_stack_any.o: linked_stack.sh stack_any.h any.h
	./linked_stack.sh any
	gcc -c ${ndebug} linked_stack_any.c

linked_stack_long.o: linked_stack.sh stack_long.h
	./linked_stack.sh long
	gcc -c ${ndebug} linked_stack_long.c

linked_stack_int.o: linked_stack.sh stack_int.h
	./linked_stack.sh int
	gcc -c ${ndebug} linked_stack_int.c

linked_stack_short.o: linked_stack.sh stack_short.h
	./linked_stack.sh short
	gcc -c ${ndebug} linked_stack_short.c

linked_stack_char.o: linked_stack.sh stack_char.h
	./linked_stack.sh char
	gcc -c ${ndebug} linked_stack_char.c

linked_stack_float.o: linked_stack.sh stack_float.h
	./linked_stack.sh float
	gcc -c ${ndebug} linked_stack_float.c

linked_stack_double.o: linked_stack.sh stack_double.h
	./linked_stack.sh double
	gcc -c ${ndebug} linked_stack_double.c

clean:
	/bin/rm -f $(derived) *.o

install:
	make clean
	make all
	if [ ! -d "${INSTALLROOT}/include" ]; then mkdir ${INSTALLROOT}/include; fi
	if [ ! -f "${INSTALLROOT}/include/any.h" ]; then /bin/cp any.h ${INSTALLROOT}/include; fi
	if [ ! -d "${INSTALLROOT}/lib" ]; then mkdir ${INSTALLROOT}/lib; fi
	/bin/cp *stack*.h ${INSTALLROOT}/include
	ar rcs ${INSTALLROOT}/lib/libarray_stacks.a array_stack*.o
	ar rcs ${INSTALLROOT}/lib/liblinked_stacks.a linked_stack*.o
	
zip:
	/bin/rm -rf ds
	mkdir ds
	mkdir ds/stack
	cp $(sources) ds/stack
	tar cvf ds.stack.tar ds
	/bin/rm -f ds.stack.tar.gz
	gzip ds.stack.tar
	/bin/rm -rf ds



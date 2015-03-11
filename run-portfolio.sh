#!/bin/bash
# Script: run-portfolio.sh
# Author: drs

# Script to run portfolio coursework files
# Put this in the directory ABOVE your portfolio directory

N=0
INFO="...."
OK="yes "
BAD="NO  "
FILES="pfstack.c    \
       pfqueue.c    \
       pfpq.c       \
       pfclist.c    \
       clist.c      \
       pfbst.c      \
       pfbst_char.h \
       pfbst_char.c"

echo "$INFO Checking if portfolio dir exists at this level"
if [ -d portfolio ]; then
    echo "$OK portfolio exists"
else
    echo "$BAD portfolio does not exist"
    exit
fi
cd portfolio

for f in $FILES; do
    echo "$INFO Checking if $f exists"
    if [ -f $f ]; then
        echo "$OK $f exists"
    else
        echo "$BAD $f does not exist"
        exit
    fi
done

echo "$INFO Compiling pfstack"
gcc -I$HOME/include -L$HOME/lib pfstack.c -o pfstack -larray_stacks
if [ $? -ne 0 ]
then
    echo "$NO pfstack.c compilation failed!"
else
    echo "$OK pfstack.c compiled"
    N=$((N+1))
fi


echo "$INFO Compiling pfqueue"
gcc -I$HOME/include -L$HOME/lib pfqueue.c -o pfqueue -larray_queues
if [ $? -ne 0 ]
then
    echo "$NO pfqueue.c compilation failed!"
else
    echo "$OK pfqueue.c compiled"
    N=$((N+1))
fi


echo "$INFO Compiling pfpq"
gcc -I$HOME/include -L$HOME/lib pfpq.c -o pfpq -larray_pqueues
if [ $? -ne 0 ]
then
    echo "$NO pfpq.c compilation failed!"
else
    echo "$OK pfpq.c compiled"
    N=$((N+1))
fi

echo "$INFO Compiling clist.c"
gcc -I$HOME/include clist.c -c
if [ $? -ne 0 ]
then
    echo "$NO clist.c compilation failed!"
else
    echo "$OK clist.c compiled"
fi

echo "$INFO Compiling pfclist"
gcc -I$HOME/include clist.o pfclist.c -o pfclist
if [ $? -ne 0 ]
then
    echo "$NO pfclist.c compilation failed!"
else
    echo "$OK pfclist.c compiled"
    N=$((N+1))
fi


echo "$INFO Compiling pfbst_char.c"
gcc -I$HOME/include pfbst_char.c -c
if [ $? -ne 0 ]
then
    echo "$NO pfbst_char.c compilation failed!"
else
    echo "$OK pfbst_char.c compiled"
fi
 
echo "$INFO Compiling pfbst"
gcc -I$HOME/include pfbst_char.o pfbst.c -o pfbst -lm
if [ $? -ne 0 ]
then
    echo "$NO pfbst.c compilation failed!"
else
    echo "$OK pfbst.c compiled"
    N=$((N+1))
fi

echo "$INFO Compiled $N"

echo $INFO Portfolio questions are:
case $(( $RANDOM % 20 )) in
0)  echo $INFO Stacks THEN Queues                       ;;
1)  echo $INFO Stacks THEN Priority Queues              ;;
2)  echo $INFO Stacks THEN Circular Lists               ;;
3)  echo $INFO Stacks THEN Binary Search Trees          ;;
4)  echo $INFO Queues THEN Stacks                       ;;
5)  echo $INFO Queues THEN Priority Queues              ;;
6)  echo $INFO Queues THEN Circular Lists               ;;
7)  echo $INFO Queues THEN Binary Search Trees          ;;
8)  echo $INFO Priority Queues THEN Stacks              ;;
9)  echo $INFO Priority Queues THEN Queues              ;;
10) echo $INFO Priority Queues THEN Circular Lists      ;;
11) echo $INFO Priority Queues THEN Binary Search Trees ;;
12) echo $INFO Circular Lists THEN Stacks               ;;
13) echo $INFO Circular Lists THEN Queues               ;;
14) echo $INFO Circular Lists THEN Priority Queues      ;;
15) echo $INFO Circular Lists THEN Binary Search Trees  ;;
16) echo $INFO Binary Search Trees THEN Stacks          ;;
17) echo $INFO Binary Search Trees THEN Queues          ;;
18) echo $INFO Binary Search Trees THEN Priority Queues ;;
19) echo $INFO Binary Search Trees THEN Circular Lists  ;;
esac

# return to original directory
cd -

# End of Script: run-portfolio.sh
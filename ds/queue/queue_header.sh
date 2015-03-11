# Shell script to generate a queue header file
# Author: drs
# Usage: ./queue_header.sh int
#        creates an int queue header file:  queue_int.h

item=$1
queue=queue_${item}
target=${queue}.h


echo "#ifndef QUEUE_${item}_H"                                               > ${target}
echo "#define QUEUE_${item}_H"                                              >> ${target}
echo                                                                        >> ${target}
echo "// Auto-generated header file for a queue of ${item}"                 >> ${target}
echo "// values.  This queue has no exception handling but"                 >> ${target}
echo "// prints a message on stdout and calls exit(1)."                     >> ${target}
echo "// Author: drs."                                                      >> ${target}
echo                                                                        >> ${target}
echo "typedef struct ${queue}_implementation ${queue};"                     >> ${target}
if [ "$item" = "any" ]; then
    echo "#include \"any.h\""                                               >> ${target}
fi
echo                                                                        >> ${target}
echo "${queue} * new_bounded_${queue}(int max);"                            >> ${target}
echo "${queue} * new_unbounded_${queue}();"                                 >> ${target}
echo "int ${queue}_isempty(${queue} *q);"                                   >> ${target}
echo "int ${queue}_isfull(${queue} *q);"                                    >> ${target}
echo "int ${queue}_size(${queue} *q);"                                      >> ${target}
echo "void ${queue}_enqueue(${queue} *q, ${item} x);"                       >> ${target}
echo "${item} ${queue}_dequeue(${queue} *q);"                               >> ${target}
echo "${item} ${queue}_front(${queue} *q);"                                 >> ${target}
echo "void ${queue}_print(${queue} *q, void (* item_print)(${item} item));" >> ${target}
echo "void ${queue}_release(${queue} *q);"                                  >> ${target}
echo                                                                        >> ${target}
echo "#endif"                                                               >> ${target}

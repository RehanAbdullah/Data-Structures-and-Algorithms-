# Shell script to generate a stack header file
# Author: drs
# Usage: ./stack_header.sh int
#        creates an int stack header file:  stack_int.h

item=$1
stack=stack_${item}
target=${stack}.h


echo "#ifndef STACK_${item}_H"                                               > ${target}
echo "#define STACK_${item}_H"                                              >> ${target}
echo                                                                        >> ${target}
echo "// Auto-generated header file for a stack of ${item}"                 >> ${target}
echo "// values.  This stack has no exception handling but"                 >> ${target}
echo "// prints a message on stdout and calls exit(1)."                     >> ${target}
echo "// Author: drs."                                                      >> ${target}
echo                                                                        >> ${target}
echo "typedef struct ${stack}_implementation ${stack};"                     >> ${target}
if [ "$item" = "any" ]; then
    echo "#include \"any.h\""                                               >> ${target}
fi
echo                                                                        >> ${target}
echo "${stack} * new_bounded_${stack}(int max);"                            >> ${target}
echo "${stack} * new_unbounded_${stack}();"                                 >> ${target}
echo "int ${stack}_isempty(${stack} *s);"                                   >> ${target}
echo "int ${stack}_isfull(${stack} *s);"                                    >> ${target}
echo "int ${stack}_size(${stack} *s);"                                      >> ${target}
echo "void ${stack}_push(${stack} *s, ${item} x);"                          >> ${target}
echo "${item} ${stack}_pop(${stack} *s);"                                   >> ${target}
echo "${item} ${stack}_top(${stack} *s);"                                   >> ${target}
echo "void ${stack}_print(${stack} *s, void (* item_print)(${item} item));" >> ${target}
echo "void ${stack}_release(${stack} *s);"                                  >> ${target}
echo                                                                        >> ${target}
echo "#endif"                                                               >> ${target}

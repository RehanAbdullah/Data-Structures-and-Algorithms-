# Shell script to generate a bst header file
# Author: drs
# Usage: ./bst_header.sh int
#        creates an int bst header file:  bst_int.h

item=$1
bst=bst_${item}
target=${bst}.h

echo "#ifndef BST_${item}_H"                                                       > ${target}
echo "#define BST_${item}_H"                                                      >> ${target}
echo                                                                              >> ${target}
echo "// Auto-generated header file for a bst of ${item}"                         >> ${target}
echo "// values.  This bst has no exception handling but"                         >> ${target}
echo "// prints a message on stdout and calls exit(1)."                           >> ${target}
echo "// Author: drs."                                                            >> ${target}
echo                                                                              >> ${target}
echo "typedef struct ${bst}_implementation ${bst};"                               >> ${target}
if [ "$item" = "any" ]; then                                                     
    echo "#include \"any.h\""                                                     >> ${target}
    echo "typedef int (*rel_fun)(any a, any b);"                                  >> ${target}
    echo                                                                          >> ${target}
    echo "${bst} * new_${bst}(rel_fun lt);"                                       >> ${target}
else                                                                             
    echo                                                                          >> ${target}
    echo "${bst} * new_${bst}();"                                                 >> ${target}
fi                                                                               
echo "int  ${bst}_isempty(${bst} *t);"                                            >> ${target}
echo "int  ${bst}_isfull(${bst} *t);"                                             >> ${target}
echo "int  ${bst}_size(${bst} *t);"                                               >> ${target}
echo "int  ${bst}_depth(${bst} *t);"                                              >> ${target}
echo "void ${bst}_insert(${bst} *t, ${item} x);"                                  >> ${target}
echo "void ${bst}_delete(${bst} *t, ${item} x);"                                  >> ${target}
echo "int  ${bst}_contains(${bst} *t, ${item} x);"                                >> ${target}
echo "void ${bst}_preorder_print(${bst} *t, void (* item_print)(${item} item));"  >> ${target}
echo "void ${bst}_inorder_print(${bst} *t, void (* item_print)(${item} item));"   >> ${target}
echo "void ${bst}_postorder_print(${bst} *t, void (* item_print)(${item} item));" >> ${target}
echo "void ${bst}_simple_print(${bst} *t, void (* item_print)(${item} item));"    >> ${target}
if [ "$item" = "char" ]; then
    echo "void ${bst}_pretty_print(${bst} *t);"                                   >> ${target}
    echo                                                                          >> ${target}
else
    echo                                                                          >> ${target}
fi
echo "void ${bst}_release(${bst} *t);"                                            >> ${target}
echo "#endif"                                                                     >> ${target}

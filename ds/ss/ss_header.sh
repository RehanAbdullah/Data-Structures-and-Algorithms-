# Shell script to generate search/sort header file
# Author: drs
# Usage: ./ss_header.sh int
#        creates an int ss header file:  ss_int.h

item=$1
target=ss_${item}.h

echo "#ifndef SS_${item}_H"                                                                > ${target}
echo "#define SS_${item}_H"                                                               >> ${target}
echo                                                                                      >> ${target}
echo "// Auto-generated header file for a search/sort library of"                         >> ${target}
echo "// ${item}  values."                                                                >> ${target}
echo "// Author: drs."                                                                    >> ${target}
echo                                                                                      >> ${target}
if [ "$item" = "any" ]; then                                                              
    echo "#include \"any.h\""                                                             >> ${target}
fi                                                                                        
echo                                                                                      >> ${target}
echo "typedef int (*comparator)(${item} a, ${item} b);"                                   >> ${target}
echo                                                                                      >> ${target}
echo "int ${item}_linearsearch(${item} a[], ${item} k, int N);"                           >> ${target}
echo "int ${item}_binarysearch(${item} a[], ${item} k, int N);"                           >> ${target}
echo "int ${item}_linearsearch_with(comparator compare, ${item} a[], ${item} k, int N);"  >> ${target}
echo "int ${item}_binarysearch_with(comparator compare, ${item} a[], ${item} k, int N);"  >> ${target}
echo "int ${item}_linearsearchX(${item} a[], ${item} k, int N);"                          >> ${target}
echo "int ${item}_linearsearchX_with(comparator compare, ${item} a[], ${item} k, int N);" >> ${target}
echo                                                                                      >> ${target}
echo "void ${item}_bubblesort(${item} a[], int N);"                                       >> ${target}
echo "void ${item}_selectsort(${item} a[], int N);"                                       >> ${target}
echo "void ${item}_insertsort(${item} a[], int N);"                                       >> ${target}
echo "void ${item}_heapsort(  ${item} a[], int N);"                                       >> ${target}
echo "void ${item}_quicksort( ${item} a[], int N);"                                       >> ${target}
echo "void ${item}_bubblesort_with(comparator compare, ${item} a[], int N);"              >> ${target}
echo "void ${item}_selectsort_with(comparator compare, ${item} a[], int N);"              >> ${target}
echo "void ${item}_insertsort_with(comparator compare, ${item} a[], int N);"              >> ${target}
echo "void ${item}_heapsort_with(  comparator compare, ${item} a[], int N);"              >> ${target}
echo "void ${item}_quicksort_with( comparator compare, ${item} a[], int N);"              >> ${target}
echo "#endif"                                                                             >> ${target}

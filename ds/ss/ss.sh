# Shell script to generate search/sort header file
# Author: drs
# Usage: ./ss_header.sh int
#        creates an int ss header file:  ss_int.h

item=$1
target=ss_${item}.c

echo                                                                               > ${target}
echo "// Auto-generated impl. file for a search/sort library of"                  >> ${target}
echo "// ${item}  values."                                                        >> ${target}
echo "// Author: drs."                                                            >> ${target}
echo                                                                              >> ${target}
cat << EOI >>${target}
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "ss_${item}.h"

/** SWAP performs a swap within an array at the index values provided.
 *  Precondition:  the array exists and indexes j and k are within the
 *                 defined array
 *  postcondition: the array will be unchanged at all indexes other than j and k
 *                 but the values at positions i and j will have been swapped
 *                 i.e.  a'[j] = a[k]  and  a'[k] = a[i]
 *                       where a' stands for the array at the end of the function
 */
inline void SWAP(${item} *a, int j, int k)
{
    ${item} temp = a[j];  a[j] = a[k];  a[k] = temp;
}

int default_comparator(${item} a, ${item} b)
{
    return (a < b) ? -1 : ( (a > b) ? 1 : 0 );
}

int ${item}_linearsearch(${item} a[], ${item} k, int N)
{
    return ${item}_linearsearch_with(default_comparator,a,k,N);
}

int ${item}_binarysearch(${item} a[], ${item} k, int N)
{
    return ${item}_binarysearch_with(default_comparator,a,k,N);
}

int ${item}_linearsearchX(${item} a[], ${item} k, int N)
{
    return ${item}_linearsearchX_with(default_comparator,a,k,N);
}

void ${item}_bubblesort(${item} a[], int N) { ${item}_bubblesort_with(default_comparator,a,N); }
void ${item}_selectsort(${item} a[], int N) { ${item}_selectsort_with(default_comparator,a,N); }
void ${item}_insertsort(${item} a[], int N) { ${item}_insertsort_with(default_comparator,a,N); }
void ${item}_heapsort(  ${item} a[], int N) { ${item}_heapsort_with(  default_comparator,a,N); }
void ${item}_quicksort( ${item} a[], int N) { ${item}_quicksort_with( default_comparator,a,N); }

int ${item}_linearsearch_with(comparator compare, ${item} a[], $item k, int N)
{
    int i = 0;
    while ((i < N) && (compare(a[i],k) != 0))
        i++;
    return (i < N) ? i : -1;   
}

int ${item}_linearsearchX_with(comparator compare, ${item} a[], $item k, int N)
{
    int i = 0;
    a[N] = k;
    while (compare(a[i],k) != 0)
        i++;
    return (i < N) ? i : -1;   
}

int ${item}_binarysearch_with(comparator compare, ${item} a[], $item k, int N)
{
    int L=0, R=N-1, mid;
    while (L < R) {
        mid = (L + R) / 2;

        if (compare(a[mid],k) < 0)
            L = mid+1;
        else
            R = mid;
    }
    return ((R<N) && (compare(a[R],k) == 0)) ? R : -1;
}

/******************************************************************************************
* Bubble sort                                                                             *
******************************************************************************************/

void ${item}_bubblesort_with(comparator compare, ${item} a[], int N)
{
    int i,j;
    for (i=N-1; i>0; i--)
        for (j=0; j<i; j++)
            if (compare(a[j],a[j+1]) > -1)
                SWAP(a,j,j+1);
}

/******************************************************************************************
* Seletcion sort                                                                          *
******************************************************************************************/
/**
 * Find the index of the smallest element in the array a with size N
 * The search begins at location lo.  This private function is used
 * by the selection sort algorithm
 */
int smallest(comparator compare, ${item} a[], int lo, int N)
{
    int s = lo, i;
    for (i=lo+1; i<N; i++)
        if (compare(a[i], a[s]) < 0)
           s = i;
    return s;
}
void ${item}_selectsort_with(comparator compare, ${item} a[], int N)
{
    int p,s;
    for (p=0; p<N; p++) {
        s = smallest(compare,a,p,N);
        SWAP(a,p,s);
    }
}

/******************************************************************************************
* Insertion sort                                                                          *
******************************************************************************************/
/**
 * Insert the element x in (ascending) order in the array 'a' within
 * the prefix portion 0..p.  This private function is used by the
 * insertion sort algorithm
 */
void insert(comparator compare, ${item} a[], ${item} x, int p)
{
    int i = 0, j;
    while ((i<p) && (compare(a[i],x) < 0))
        i++;
    /* i is the insertion position (i may be p: the last possible location)
       Before inserting at i make room by shunting: a[i..p-1] -> a[i+1..p]
     */
    for (j=p; j>i; j--) a[j] = a[j-1];
    a[i] = x;
}

void ${item}_insertsort_with(comparator compare, ${item} a[], int N)
{
    int p,s;
    for (p=1; p<N; p++)
        insert(compare,a,a[p],p);
}

/******************************************************************************************
* Heap sort                                                                               *
* The heapsort algorithm superimposes a balanced binary tree onto the array.              *
******************************************************************************************/

#define LCHILD(i) (((i+1)*2)-1)
#define RCHILD(i)  ((i+1)*2)

/**
 * The main component of heapsort is the sift-down algorithm that allows a node to travel
 * down a path in the tree and find its rightful place - thus re-establishing a heap.
 */
void siftDown(comparator compare, ${item} a[], int k, int N)
{
    int parent=k;
    int child;
    while(1) {
       child = LCHILD(parent);
       if (child >= N)                      /* no children - we are at a leaf node */
           break;                                 /* so exit the loop, we are done */
       else {
           if (child+1 < N                           /* are there two children?    */
               && compare(a[child+1], a[child]) > 0) /* and is r-child is greater? */
               child++;                              /* then set child to r-child  */
               
           /* so now child is the index of the largest (or only) child */
           
           if (compare(a[parent], a[child]) > 0)     /* then nothing else to do    */
               break;
           else {
               SWAP(a,parent,child);
               parent = child;                       /* and sift down from here... */
           }
       }
    }
}

void makeHeap(comparator compare, ${item} a[], int N)
{
    int k = (N-1) / 2;
    while (k>=0) {
        siftDown(compare,a,k,N);
        k--;
    }
}

void ${item}_heapsort_with(comparator compare, ${item} a[], int N)
{
    int k = N-1;
    makeHeap(compare,a,N);
    while (k>0) {
        SWAP(a, 0, k);                  /* largest is now at the end */
        siftDown(compare,a,0,k);        /* find rightful place for swapped item */
        k--;
    }
}

/******************************************************************************************
* Quick sort                                                                              *
******************************************************************************************/
void q_sort(comparator compare, ${item} *a, int left, int right, int N)
{
    int i, last, pivot;
    if (left >= right)
        return;
    pivot = (left+right)/2;
    SWAP(a, left, pivot);
    last = left;
    for( i=left+1; i<=right; i++ )
        if (compare(a[i], a[left]) < 0)
            SWAP(a, ++last, i);
    SWAP(a, left, last);
    q_sort(compare, a, left, last-1, N);
    q_sort(compare, a, last+1, right, N);
}

void ${item}_quicksort_with(comparator compare, ${item} a[], int N)
{
    q_sort(compare,a,0,N-1,N);
}

EOI



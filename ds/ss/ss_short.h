#ifndef SS_short_H
#define SS_short_H

// Auto-generated header file for a search/sort library of
// short  values.
// Author: drs.


typedef int (*comparator)(short a, short b);

int short_linearsearch(short a[], short k, int N);
int short_binarysearch(short a[], short k, int N);
int short_linearsearch_with(comparator compare, short a[], short k, int N);
int short_binarysearch_with(comparator compare, short a[], short k, int N);
int short_linearsearchX(short a[], short k, int N);
int short_linearsearchX_with(comparator compare, short a[], short k, int N);

void short_bubblesort(short a[], int N);
void short_selectsort(short a[], int N);
void short_insertsort(short a[], int N);
void short_heapsort(  short a[], int N);
void short_quicksort( short a[], int N);
void short_bubblesort_with(comparator compare, short a[], int N);
void short_selectsort_with(comparator compare, short a[], int N);
void short_insertsort_with(comparator compare, short a[], int N);
void short_heapsort_with(  comparator compare, short a[], int N);
void short_quicksort_with( comparator compare, short a[], int N);
#endif

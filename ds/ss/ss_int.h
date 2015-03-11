#ifndef SS_int_H
#define SS_int_H

// Auto-generated header file for a search/sort library of
// int  values.
// Author: drs.


typedef int (*comparator)(int a, int b);

int int_linearsearch(int a[], int k, int N);
int int_binarysearch(int a[], int k, int N);
int int_linearsearch_with(comparator compare, int a[], int k, int N);
int int_binarysearch_with(comparator compare, int a[], int k, int N);
int int_linearsearchX(int a[], int k, int N);
int int_linearsearchX_with(comparator compare, int a[], int k, int N);

void int_bubblesort(int a[], int N);
void int_selectsort(int a[], int N);
void int_insertsort(int a[], int N);
void int_heapsort(  int a[], int N);
void int_quicksort( int a[], int N);
void int_bubblesort_with(comparator compare, int a[], int N);
void int_selectsort_with(comparator compare, int a[], int N);
void int_insertsort_with(comparator compare, int a[], int N);
void int_heapsort_with(  comparator compare, int a[], int N);
void int_quicksort_with( comparator compare, int a[], int N);
#endif

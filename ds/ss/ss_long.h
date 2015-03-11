#ifndef SS_long_H
#define SS_long_H

// Auto-generated header file for a search/sort library of
// long  values.
// Author: drs.


typedef int (*comparator)(long a, long b);

int long_linearsearch(long a[], long k, int N);
int long_binarysearch(long a[], long k, int N);
int long_linearsearch_with(comparator compare, long a[], long k, int N);
int long_binarysearch_with(comparator compare, long a[], long k, int N);
int long_linearsearchX(long a[], long k, int N);
int long_linearsearchX_with(comparator compare, long a[], long k, int N);

void long_bubblesort(long a[], int N);
void long_selectsort(long a[], int N);
void long_insertsort(long a[], int N);
void long_heapsort(  long a[], int N);
void long_quicksort( long a[], int N);
void long_bubblesort_with(comparator compare, long a[], int N);
void long_selectsort_with(comparator compare, long a[], int N);
void long_insertsort_with(comparator compare, long a[], int N);
void long_heapsort_with(  comparator compare, long a[], int N);
void long_quicksort_with( comparator compare, long a[], int N);
#endif

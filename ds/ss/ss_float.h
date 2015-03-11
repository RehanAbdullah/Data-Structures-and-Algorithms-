#ifndef SS_float_H
#define SS_float_H

// Auto-generated header file for a search/sort library of
// float  values.
// Author: drs.


typedef int (*comparator)(float a, float b);

int float_linearsearch(float a[], float k, int N);
int float_binarysearch(float a[], float k, int N);
int float_linearsearch_with(comparator compare, float a[], float k, int N);
int float_binarysearch_with(comparator compare, float a[], float k, int N);
int float_linearsearchX(float a[], float k, int N);
int float_linearsearchX_with(comparator compare, float a[], float k, int N);

void float_bubblesort(float a[], int N);
void float_selectsort(float a[], int N);
void float_insertsort(float a[], int N);
void float_heapsort(  float a[], int N);
void float_quicksort( float a[], int N);
void float_bubblesort_with(comparator compare, float a[], int N);
void float_selectsort_with(comparator compare, float a[], int N);
void float_insertsort_with(comparator compare, float a[], int N);
void float_heapsort_with(  comparator compare, float a[], int N);
void float_quicksort_with( comparator compare, float a[], int N);
#endif

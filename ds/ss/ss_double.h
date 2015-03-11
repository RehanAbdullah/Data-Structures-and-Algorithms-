#ifndef SS_double_H
#define SS_double_H

// Auto-generated header file for a search/sort library of
// double  values.
// Author: drs.


typedef int (*comparator)(double a, double b);

int double_linearsearch(double a[], double k, int N);
int double_binarysearch(double a[], double k, int N);
int double_linearsearch_with(comparator compare, double a[], double k, int N);
int double_binarysearch_with(comparator compare, double a[], double k, int N);
int double_linearsearchX(double a[], double k, int N);
int double_linearsearchX_with(comparator compare, double a[], double k, int N);

void double_bubblesort(double a[], int N);
void double_selectsort(double a[], int N);
void double_insertsort(double a[], int N);
void double_heapsort(  double a[], int N);
void double_quicksort( double a[], int N);
void double_bubblesort_with(comparator compare, double a[], int N);
void double_selectsort_with(comparator compare, double a[], int N);
void double_insertsort_with(comparator compare, double a[], int N);
void double_heapsort_with(  comparator compare, double a[], int N);
void double_quicksort_with( comparator compare, double a[], int N);
#endif

#ifndef SS_any_H
#define SS_any_H

// Auto-generated header file for a search/sort library of
// any  values.
// Author: drs.

#include "any.h"

typedef int (*comparator)(any a, any b);

int any_linearsearch(any a[], any k, int N);
int any_binarysearch(any a[], any k, int N);
int any_linearsearch_with(comparator compare, any a[], any k, int N);
int any_binarysearch_with(comparator compare, any a[], any k, int N);
int any_linearsearchX(any a[], any k, int N);
int any_linearsearchX_with(comparator compare, any a[], any k, int N);

void any_bubblesort(any a[], int N);
void any_selectsort(any a[], int N);
void any_insertsort(any a[], int N);
void any_heapsort(  any a[], int N);
void any_quicksort( any a[], int N);
void any_bubblesort_with(comparator compare, any a[], int N);
void any_selectsort_with(comparator compare, any a[], int N);
void any_insertsort_with(comparator compare, any a[], int N);
void any_heapsort_with(  comparator compare, any a[], int N);
void any_quicksort_with( comparator compare, any a[], int N);
#endif

#ifndef SS_char_H
#define SS_char_H

// Auto-generated header file for a search/sort library of
// char  values.
// Author: drs.


typedef int (*comparator)(char a, char b);

int char_linearsearch(char a[], char k, int N);
int char_binarysearch(char a[], char k, int N);
int char_linearsearch_with(comparator compare, char a[], char k, int N);
int char_binarysearch_with(comparator compare, char a[], char k, int N);
int char_linearsearchX(char a[], char k, int N);
int char_linearsearchX_with(comparator compare, char a[], char k, int N);

void char_bubblesort(char a[], int N);
void char_selectsort(char a[], int N);
void char_insertsort(char a[], int N);
void char_heapsort(  char a[], int N);
void char_quicksort( char a[], int N);
void char_bubblesort_with(comparator compare, char a[], int N);
void char_selectsort_with(comparator compare, char a[], int N);
void char_insertsort_with(comparator compare, char a[], int N);
void char_heapsort_with(  comparator compare, char a[], int N);
void char_quicksort_with( comparator compare, char a[], int N);
#endif

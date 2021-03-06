// A hash table abstract data type
// Author: drs

#ifndef HT_H
#define HT_H

#include "any.h"

#define LINEAR_PROBING 1
#define QUADRATIC_PROBING 2
#define SECONDARY_HASHING 3

typedef struct ht_implementation ht;
typedef int (*getkeyfun)(any a);
typedef int (*hashfun)(int a);

ht * new_ht(int max, hashfun h1, getkeyfun getkey);
void  ht_use_quadratic_probing(ht *t, int c1, int c2);
void  ht_use_double_hashing(ht *t, hashfun h2);
int   ht_isempty(ht *t);
int   ht_isfull(ht *t);
int   ht_size(ht *t);
float ht_loadfactor(ht *t);
int   ht_insert(ht *t, any x);
int   ht_delete(ht *t, int k);
any   ht_lookup(ht *t, int k);
void  ht_profile(ht *t);
void  ht_display(ht *t, int lo, int hi);
void  ht_release(ht *t);

#endif

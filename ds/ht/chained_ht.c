// A hash table using chaining to resolve collisions. We use a doubly linked list to store
// the collisions because that speeds up deletion times.  Note that we do not maintain the
// list in order because we do not expect the lists to become very large.  However, should
// large numbers of collisions be anticipated then we could re-implement with a binary
// search tree (or a height-balanced search tree - such as an avl tree).
// Author: drs

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "any.h"
#include "clist.h"
#include "ht.h"

struct ht_implementation
{
    clist **items;    // array of linked lists
    int size;         // current number of objects stored in the table
    hashfun h1;       // user-supplied primary hash function
    getkeyfun getkey; // user-supplied function to extract a key from an object
    int max;          // user-supplied maximum table size
};

ht * new_ht(int max, hashfun h1, getkeyfun getkey)
{
    int i;
    ht * t = (ht*)malloc(sizeof(ht));
    t->items = (clist**)malloc(max * sizeof(clist*));
    t->size = 0;
    t->h1 = h1;
    t->getkey = getkey;
    t->max = max;
    for (i=0; i<max; i++)
        t->items[i] = new_clist();
    return t;
}

void  ht_use_quadratic_probing(ht *t, int c1, int c2)
{
    printf("ignored: ht_use_quadratic_probing - not used in chained implementation\n");
}

void ht_use_double_hashing(ht *t, hashfun h2)
{
    printf("ignored: ht_use_double_hashing - not used in chained implementation\n");
}

int ht_isempty(ht *t)
{
    assert(t!=NULL);
    return (t->size == 0);
}
    
int  ht_isfull(ht *t)
{
    assert(t!=NULL);
    return t->size==t->max;
}
    
int  ht_size(ht *t)
{
    assert(t!=NULL);
    return t->size;
}

float ht_loadfactor(ht *t)
{
    assert(t!=NULL);
    return ((float)(t->size) / (float)(t->max));
}

int ht_insert(ht *t, any x)
{
    assert(t!=NULL);
    int j;
    int k = t->getkey(x);
    j = t->h1(k);
    clist_goto_last(t->items[j]);
    clist_ins_after(t->items[j], x);
    (t->size)++;
    return 1;           // insertion always succeeds
}

int ht_delete(ht *t, int k)
{
    assert(t!=NULL);
    int j;
    j =  t->h1(k);
    clist_goto_head(t->items[j]);
    while (clist_cursor_inlist(t->items[j])) {
        if (t->getkey(clist_get_item(t->items[j])) == k) {
            clist_delete(t->items[j]);
            (t->size)--;
            return 1;
        }
        else
            clist_goto_next(t->items[j]);
    }
    return 0;           // report failed delete
}

any ht_lookup(ht *t, int k)
{
    assert(t!=NULL);
    int j;
    any a;
    j =  t->h1(k);
    clist_goto_head(t->items[j]);
    while (clist_cursor_inlist(t->items[j]))
        if (t->getkey(a = clist_get_item(t->items[j])) == k)
            return a;
        else
            clist_goto_next(t->items[j]);
    
    return NULL;        // report failed lookup
}

void ht_profile(ht *t)
{
    assert(t!=NULL);
    int i,j;
    printf("\n");
    for (i=0; i < t->max; i++) {
        printf("%4i: ",i);
        for (j=0; j < clist_size(t->items[i]); j++)
            printf("X");
        printf("\n");
    }
    printf("Load Factor = %f\n", ht_loadfactor(t));
}

void ht_display(ht *t, int lo, int hi)
{
    int i,j;
    assert(0 <= lo && lo <= hi && hi < t->max);
    printf("Displaying hash table from %i to %i\n", lo, hi);
    for (i=0; i < t->max; i++) {
        printf("%8i: ",i);
        clist_goto_head(t->items[i]);
        while(clist_cursor_inlist(t->items[i])) {
            printf("%i <--> ", t->getkey(clist_get_item(t->items[i])));
            clist_goto_next(t->items[i]);
        }
        printf("!\n");
    }
}

void ht_release(ht *t)
{
    assert(t!=NULL);
    int i;
    clist * l;
    for (i=0; i < t->max; i++) {
        l = t->items[i];
        clist_goto_head(l);
        while (!clist_isempty(l))
            clist_delete(l);
        clist_release(l);
    }
    free(t);
}


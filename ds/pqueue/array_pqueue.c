// array implementation of a priority pqueue
// Author: drs

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"

struct pqueue_implementation
{
    any * items;
    int size;
    le_fun le;
    int max;
};

pqueue * new_bounded_pqueue(int max, le_fun le)
{
    pqueue * q = (pqueue*)malloc(sizeof(pqueue));
    q->items = (any*)malloc(max * sizeof(any));
    q->size = 0;
    q->le = le;
    q->max = max;
    return q;
}

pqueue * new_unbounded_pqueue(le_fun le)
{
    printf("new_unbounded_pqueue error: not available for array implementation\n");
    exit(1);
}

int  pqueue_isempty(pqueue *q)
{
    assert(q!=NULL);
    return (q->size == 0);
}
    
int  pqueue_isfull(pqueue *q)
{
    assert(q!=NULL);
    return q->size==q->max;
}
    
int  pqueue_size(pqueue *q)
{
    assert(q!=NULL);
    return q->size;
}

void pqueue_insert(pqueue *q, any x)
{
    assert(q!=NULL);
    int i,j;
    if (pqueue_isfull(q)) {
        printf("pqueue_insert error: pqueue is full\n");
        exit(1);
    }
    else {
        i = 0;
        while(i < (q->size) && !(q->le(x,q->items[i])))
            i++;
        for(j=q->size; j>i; j--)
            q->items[j] = q->items[j-1];
        q->items[i] = x;
        (q->size)++;
    }
}

any pqueue_dequeue(pqueue *q)
{
    assert(q!=NULL);
    any x;
    if (pqueue_isempty(q)) {
        printf("pqueue_depqueue error: pqueue is empty\n");
        exit(1);
    }
    else {
        x = q->items[(q->size)-1];
        (q->size)--;
        return x;
    }
}

any pqueue_front(pqueue *q)
{
    assert(q!=NULL);
    if (pqueue_isempty(q)) {
        printf("pqueue_front error: pqueue is empty\n");
        exit(1);
    }
    else
        return q->items[(q->size)-1];
}

void pqueue_print(pqueue *q, void (* item_print)(any item))
{
    assert(q!=NULL);
    int i=(q->size)-1;;
    printf("PrQ<<[ ");
    if (!pqueue_isempty(q)) {
        while (i>0) {
            item_print(q->items[i]);
            printf(", ");
            i--;
        }
        item_print(q->items[i]);
    }
    printf(" ]");
}

void pqueue_release(pqueue *q)
{
    assert(q!=NULL);
    free(q->items);
    free(q);
}


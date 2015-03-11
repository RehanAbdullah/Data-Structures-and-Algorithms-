// A priority queue abstract data type
// Author: drs

#ifndef PQUEUE_H
#define PQUEUE_H

#include "any.h"

typedef struct pqueue_implementation pqueue;
typedef int (*le_fun)(any a, any b);

pqueue * new_bounded_pqueue(int max, le_fun le);
pqueue * new_unbounded_pqueue(le_fun le);
int  pqueue_isempty(pqueue *q);
int  pqueue_isfull(pqueue *q);
int  pqueue_size(pqueue *q);
void pqueue_insert(pqueue *q, any x);
any  pqueue_dequeue(pqueue *q);
any  pqueue_front(pqueue *q);
void pqueue_print(pqueue *q, void (* item_print)(any item));
void pqueue_release(pqueue *q);

#endif

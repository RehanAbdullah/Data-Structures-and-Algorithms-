#ifndef QUEUE_any_H
#define QUEUE_any_H

// Auto-generated header file for a queue of any
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct queue_any_implementation queue_any;
#include "any.h"

queue_any * new_bounded_queue_any(int max);
queue_any * new_unbounded_queue_any();
int queue_any_isempty(queue_any *q);
int queue_any_isfull(queue_any *q);
int queue_any_size(queue_any *q);
void queue_any_enqueue(queue_any *q, any x);
any queue_any_dequeue(queue_any *q);
any queue_any_front(queue_any *q);
void queue_any_print(queue_any *q, void (* item_print)(any item));
void queue_any_release(queue_any *q);

#endif

#ifndef QUEUE_int_H
#define QUEUE_int_H

// Auto-generated header file for a queue of int
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct queue_int_implementation queue_int;

queue_int * new_bounded_queue_int(int max);
queue_int * new_unbounded_queue_int();
int queue_int_isempty(queue_int *q);
int queue_int_isfull(queue_int *q);
int queue_int_size(queue_int *q);
void queue_int_enqueue(queue_int *q, int x);
int queue_int_dequeue(queue_int *q);
int queue_int_front(queue_int *q);
void queue_int_print(queue_int *q, void (* item_print)(int item));
void queue_int_release(queue_int *q);

#endif

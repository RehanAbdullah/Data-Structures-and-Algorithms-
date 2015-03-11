#ifndef QUEUE_long_H
#define QUEUE_long_H

// Auto-generated header file for a queue of long
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct queue_long_implementation queue_long;

queue_long * new_bounded_queue_long(int max);
queue_long * new_unbounded_queue_long();
int queue_long_isempty(queue_long *q);
int queue_long_isfull(queue_long *q);
int queue_long_size(queue_long *q);
void queue_long_enqueue(queue_long *q, long x);
long queue_long_dequeue(queue_long *q);
long queue_long_front(queue_long *q);
void queue_long_print(queue_long *q, void (* item_print)(long item));
void queue_long_release(queue_long *q);

#endif

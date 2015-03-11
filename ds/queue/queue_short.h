#ifndef QUEUE_short_H
#define QUEUE_short_H

// Auto-generated header file for a queue of short
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct queue_short_implementation queue_short;

queue_short * new_bounded_queue_short(int max);
queue_short * new_unbounded_queue_short();
int queue_short_isempty(queue_short *q);
int queue_short_isfull(queue_short *q);
int queue_short_size(queue_short *q);
void queue_short_enqueue(queue_short *q, short x);
short queue_short_dequeue(queue_short *q);
short queue_short_front(queue_short *q);
void queue_short_print(queue_short *q, void (* item_print)(short item));
void queue_short_release(queue_short *q);

#endif

#ifndef QUEUE_float_H
#define QUEUE_float_H

// Auto-generated header file for a queue of float
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct queue_float_implementation queue_float;

queue_float * new_bounded_queue_float(int max);
queue_float * new_unbounded_queue_float();
int queue_float_isempty(queue_float *q);
int queue_float_isfull(queue_float *q);
int queue_float_size(queue_float *q);
void queue_float_enqueue(queue_float *q, float x);
float queue_float_dequeue(queue_float *q);
float queue_float_front(queue_float *q);
void queue_float_print(queue_float *q, void (* item_print)(float item));
void queue_float_release(queue_float *q);

#endif

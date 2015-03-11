#ifndef QUEUE_double_H
#define QUEUE_double_H

// Auto-generated header file for a queue of double
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct queue_double_implementation queue_double;

queue_double * new_bounded_queue_double(int max);
queue_double * new_unbounded_queue_double();
int queue_double_isempty(queue_double *q);
int queue_double_isfull(queue_double *q);
int queue_double_size(queue_double *q);
void queue_double_enqueue(queue_double *q, double x);
double queue_double_dequeue(queue_double *q);
double queue_double_front(queue_double *q);
void queue_double_print(queue_double *q, void (* item_print)(double item));
void queue_double_release(queue_double *q);

#endif

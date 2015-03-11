// Auto-generated impl. file for a queue of double
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue_double.h"

struct queue_double_implementation
{
    double * items;
    int front;
    int back;
    int size;
    int max;
};

queue_double * new_bounded_queue_double(int max)
{
    queue_double * q = (queue_double*)malloc(sizeof(queue_double));
    q->items = (double*)malloc(max * sizeof(double));
    q->front = 0;
    q->back = 0;
    q->size = 0;
    q->max = max;
    return q;
}

queue_double * new_unbounded_queue_double()
{
    printf("new_unbounded_queue_double error: not available for array implementation\n");
    exit(1);
}

int queue_double_isempty(queue_double *q)
{
    assert(q!=NULL);
    return (q->size == 0);
}
    
int queue_double_isfull(queue_double *q)
{
    assert(q!=NULL);
    return (q->size == q->max);
}
    
int queue_double_size(queue_double *q)
{
    assert(q!=NULL);
    return q->size;
}

void queue_double_enqueue(queue_double *q, double x)
{
    assert(q!=NULL);
    if (queue_double_isfull(q)) {
        printf("queue_double_enqueue error: queue is full\n");
        exit(1);
    }
    else {
        q->items[q->back] = x;
        q->back = (q->back + 1) % (q->max);
        (q->size)++;
    }
}

double queue_double_dequeue(queue_double *q)
{
    assert(q!=NULL);
    double x;
    if (queue_double_isempty(q)) {
        printf("queue_double_dequeue error: queue is empty\n");
        exit(1);
    }
    else {
        x = q->items[q->front];
        q->front = (q->front + 1) % (q->max);
        (q->size)--;
        return x;
    }
}

double queue_double_front(queue_double *q)
{
    assert(q!=NULL);
    if (queue_double_isempty(q)) {
        printf("queue_double_front error: queue is empty\n");
        exit(1);
    }
    else
        return (q->items[q->front]);
}

void queue_double_print(queue_double *q, void (* item_print)(double item))
{
    assert(q!=NULL);
    int i=0;
    int j=q->front;
    printf("Q<<[ ");
    if (!queue_double_isempty(q)) {
        while (i<(q->size - 1)) {
            item_print(q->items[j]);
            printf(", ");
            j = (j+1) % (q->max);
            i++;
        }
        item_print(q->items[j]);
    }
    printf(" ]");
}

void queue_double_release(queue_double *q)
{
    assert(q!=NULL);
    free(q->items);
    free(q);
}

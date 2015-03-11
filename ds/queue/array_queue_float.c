// Auto-generated impl. file for a queue of float
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue_float.h"

struct queue_float_implementation
{
    float * items;
    int front;
    int back;
    int size;
    int max;
};

queue_float * new_bounded_queue_float(int max)
{
    queue_float * q = (queue_float*)malloc(sizeof(queue_float));
    q->items = (float*)malloc(max * sizeof(float));
    q->front = 0;
    q->back = 0;
    q->size = 0;
    q->max = max;
    return q;
}

queue_float * new_unbounded_queue_float()
{
    printf("new_unbounded_queue_float error: not available for array implementation\n");
    exit(1);
}

int queue_float_isempty(queue_float *q)
{
    assert(q!=NULL);
    return (q->size == 0);
}
    
int queue_float_isfull(queue_float *q)
{
    assert(q!=NULL);
    return (q->size == q->max);
}
    
int queue_float_size(queue_float *q)
{
    assert(q!=NULL);
    return q->size;
}

void queue_float_enqueue(queue_float *q, float x)
{
    assert(q!=NULL);
    if (queue_float_isfull(q)) {
        printf("queue_float_enqueue error: queue is full\n");
        exit(1);
    }
    else {
        q->items[q->back] = x;
        q->back = (q->back + 1) % (q->max);
        (q->size)++;
    }
}

float queue_float_dequeue(queue_float *q)
{
    assert(q!=NULL);
    float x;
    if (queue_float_isempty(q)) {
        printf("queue_float_dequeue error: queue is empty\n");
        exit(1);
    }
    else {
        x = q->items[q->front];
        q->front = (q->front + 1) % (q->max);
        (q->size)--;
        return x;
    }
}

float queue_float_front(queue_float *q)
{
    assert(q!=NULL);
    if (queue_float_isempty(q)) {
        printf("queue_float_front error: queue is empty\n");
        exit(1);
    }
    else
        return (q->items[q->front]);
}

void queue_float_print(queue_float *q, void (* item_print)(float item))
{
    assert(q!=NULL);
    int i=0;
    int j=q->front;
    printf("Q<<[ ");
    if (!queue_float_isempty(q)) {
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

void queue_float_release(queue_float *q)
{
    assert(q!=NULL);
    free(q->items);
    free(q);
}

// Auto-generated impl. file for a queue of long
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue_long.h"

struct queue_long_implementation
{
    long * items;
    int front;
    int back;
    int size;
    int max;
};

queue_long * new_bounded_queue_long(int max)
{
    queue_long * q = (queue_long*)malloc(sizeof(queue_long));
    q->items = (long*)malloc(max * sizeof(long));
    q->front = 0;
    q->back = 0;
    q->size = 0;
    q->max = max;
    return q;
}

queue_long * new_unbounded_queue_long()
{
    printf("new_unbounded_queue_long error: not available for array implementation\n");
    exit(1);
}

int queue_long_isempty(queue_long *q)
{
    assert(q!=NULL);
    return (q->size == 0);
}
    
int queue_long_isfull(queue_long *q)
{
    assert(q!=NULL);
    return (q->size == q->max);
}
    
int queue_long_size(queue_long *q)
{
    assert(q!=NULL);
    return q->size;
}

void queue_long_enqueue(queue_long *q, long x)
{
    assert(q!=NULL);
    if (queue_long_isfull(q)) {
        printf("queue_long_enqueue error: queue is full\n");
        exit(1);
    }
    else {
        q->items[q->back] = x;
        q->back = (q->back + 1) % (q->max);
        (q->size)++;
    }
}

long queue_long_dequeue(queue_long *q)
{
    assert(q!=NULL);
    long x;
    if (queue_long_isempty(q)) {
        printf("queue_long_dequeue error: queue is empty\n");
        exit(1);
    }
    else {
        x = q->items[q->front];
        q->front = (q->front + 1) % (q->max);
        (q->size)--;
        return x;
    }
}

long queue_long_front(queue_long *q)
{
    assert(q!=NULL);
    if (queue_long_isempty(q)) {
        printf("queue_long_front error: queue is empty\n");
        exit(1);
    }
    else
        return (q->items[q->front]);
}

void queue_long_print(queue_long *q, void (* item_print)(long item))
{
    assert(q!=NULL);
    int i=0;
    int j=q->front;
    printf("Q<<[ ");
    if (!queue_long_isempty(q)) {
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

void queue_long_release(queue_long *q)
{
    assert(q!=NULL);
    free(q->items);
    free(q);
}

// Auto-generated impl. file for a queue of short
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue_short.h"

struct queue_short_implementation
{
    short * items;
    int front;
    int back;
    int size;
    int max;
};

queue_short * new_bounded_queue_short(int max)
{
    queue_short * q = (queue_short*)malloc(sizeof(queue_short));
    q->items = (short*)malloc(max * sizeof(short));
    q->front = 0;
    q->back = 0;
    q->size = 0;
    q->max = max;
    return q;
}

queue_short * new_unbounded_queue_short()
{
    printf("new_unbounded_queue_short error: not available for array implementation\n");
    exit(1);
}

int queue_short_isempty(queue_short *q)
{
    assert(q!=NULL);
    return (q->size == 0);
}
    
int queue_short_isfull(queue_short *q)
{
    assert(q!=NULL);
    return (q->size == q->max);
}
    
int queue_short_size(queue_short *q)
{
    assert(q!=NULL);
    return q->size;
}

void queue_short_enqueue(queue_short *q, short x)
{
    assert(q!=NULL);
    if (queue_short_isfull(q)) {
        printf("queue_short_enqueue error: queue is full\n");
        exit(1);
    }
    else {
        q->items[q->back] = x;
        q->back = (q->back + 1) % (q->max);
        (q->size)++;
    }
}

short queue_short_dequeue(queue_short *q)
{
    assert(q!=NULL);
    short x;
    if (queue_short_isempty(q)) {
        printf("queue_short_dequeue error: queue is empty\n");
        exit(1);
    }
    else {
        x = q->items[q->front];
        q->front = (q->front + 1) % (q->max);
        (q->size)--;
        return x;
    }
}

short queue_short_front(queue_short *q)
{
    assert(q!=NULL);
    if (queue_short_isempty(q)) {
        printf("queue_short_front error: queue is empty\n");
        exit(1);
    }
    else
        return (q->items[q->front]);
}

void queue_short_print(queue_short *q, void (* item_print)(short item))
{
    assert(q!=NULL);
    int i=0;
    int j=q->front;
    printf("Q<<[ ");
    if (!queue_short_isempty(q)) {
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

void queue_short_release(queue_short *q)
{
    assert(q!=NULL);
    free(q->items);
    free(q);
}

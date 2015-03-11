// Auto-generated impl. file for a queue of int
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue_int.h"

struct queue_int_implementation
{
    int * items;
    int front;
    int back;
    int size;
    int max;
};

queue_int * new_bounded_queue_int(int max)
{
    queue_int * q = (queue_int*)malloc(sizeof(queue_int));
    q->items = (int*)malloc(max * sizeof(int));
    q->front = 0;
    q->back = 0;
    q->size = 0;
    q->max = max;
    return q;
}

queue_int * new_unbounded_queue_int()
{
    printf("new_unbounded_queue_int error: not available for array implementation\n");
    exit(1);
}

int queue_int_isempty(queue_int *q)
{
    assert(q!=NULL);
    return (q->size == 0);
}
    
int queue_int_isfull(queue_int *q)
{
    assert(q!=NULL);
    return (q->size == q->max);
}
    
int queue_int_size(queue_int *q)
{
    assert(q!=NULL);
    return q->size;
}

void queue_int_enqueue(queue_int *q, int x)
{
    assert(q!=NULL);
    if (queue_int_isfull(q)) {
        printf("queue_int_enqueue error: queue is full\n");
        exit(1);
    }
    else {
        q->items[q->back] = x;
        q->back = (q->back + 1) % (q->max);
        (q->size)++;
    }
}

int queue_int_dequeue(queue_int *q)
{
    assert(q!=NULL);
    int x;
    if (queue_int_isempty(q)) {
        printf("queue_int_dequeue error: queue is empty\n");
        exit(1);
    }
    else {
        x = q->items[q->front];
        q->front = (q->front + 1) % (q->max);
        (q->size)--;
        return x;
    }
}

int queue_int_front(queue_int *q)
{
    assert(q!=NULL);
    if (queue_int_isempty(q)) {
        printf("queue_int_front error: queue is empty\n");
        exit(1);
    }
    else
        return (q->items[q->front]);
}

void queue_int_print(queue_int *q, void (* item_print)(int item))
{
    assert(q!=NULL);
    int i=0;
    int j=q->front;
    printf("Q<<[ ");
    if (!queue_int_isempty(q)) {
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

void queue_int_release(queue_int *q)
{
    assert(q!=NULL);
    free(q->items);
    free(q);
}

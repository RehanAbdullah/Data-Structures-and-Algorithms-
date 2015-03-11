// Auto-generated impl. file for a queue of any
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue_any.h"

struct queue_any_implementation
{
    any * items;
    int front;
    int back;
    int size;
    int max;
};

queue_any * new_bounded_queue_any(int max)
{
    queue_any * q = (queue_any*)malloc(sizeof(queue_any));
    q->items = (any*)malloc(max * sizeof(any));
    q->front = 0;
    q->back = 0;
    q->size = 0;
    q->max = max;
    return q;
}

queue_any * new_unbounded_queue_any()
{
    printf("new_unbounded_queue_any error: not available for array implementation\n");
    exit(1);
}

int queue_any_isempty(queue_any *q)
{
    assert(q!=NULL);
    return (q->size == 0);
}
    
int queue_any_isfull(queue_any *q)
{
    assert(q!=NULL);
    return (q->size == q->max);
}
    
int queue_any_size(queue_any *q)
{
    assert(q!=NULL);
    return q->size;
}

void queue_any_enqueue(queue_any *q, any x)
{
    assert(q!=NULL);
    if (queue_any_isfull(q)) {
        printf("queue_any_enqueue error: queue is full\n");
        exit(1);
    }
    else {
        q->items[q->back] = x;
        q->back = (q->back + 1) % (q->max);
        (q->size)++;
    }
}

any queue_any_dequeue(queue_any *q)
{
    assert(q!=NULL);
    any x;
    if (queue_any_isempty(q)) {
        printf("queue_any_dequeue error: queue is empty\n");
        exit(1);
    }
    else {
        x = q->items[q->front];
        q->front = (q->front + 1) % (q->max);
        (q->size)--;
        return x;
    }
}

any queue_any_front(queue_any *q)
{
    assert(q!=NULL);
    if (queue_any_isempty(q)) {
        printf("queue_any_front error: queue is empty\n");
        exit(1);
    }
    else
        return (q->items[q->front]);
}

void queue_any_print(queue_any *q, void (* item_print)(any item))
{
    assert(q!=NULL);
    int i=0;
    int j=q->front;
    printf("Q<<[ ");
    if (!queue_any_isempty(q)) {
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

void queue_any_release(queue_any *q)
{
    assert(q!=NULL);
    free(q->items);
    free(q);
}

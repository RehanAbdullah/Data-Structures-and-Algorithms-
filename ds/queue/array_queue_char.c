// Auto-generated impl. file for a queue of char
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue_char.h"

struct queue_char_implementation
{
    char * items;
    int front;
    int back;
    int size;
    int max;
};

queue_char * new_bounded_queue_char(int max)
{
    queue_char * q = (queue_char*)malloc(sizeof(queue_char));
    q->items = (char*)malloc(max * sizeof(char));
    q->front = 0;
    q->back = 0;
    q->size = 0;
    q->max = max;
    return q;
}

queue_char * new_unbounded_queue_char()
{
    printf("new_unbounded_queue_char error: not available for array implementation\n");
    exit(1);
}

int queue_char_isempty(queue_char *q)
{
    assert(q!=NULL);
    return (q->size == 0);
}
    
int queue_char_isfull(queue_char *q)
{
    assert(q!=NULL);
    return (q->size == q->max);
}
    
int queue_char_size(queue_char *q)
{
    assert(q!=NULL);
    return q->size;
}

void queue_char_enqueue(queue_char *q, char x)
{
    assert(q!=NULL);
    if (queue_char_isfull(q)) {
        printf("queue_char_enqueue error: queue is full\n");
        exit(1);
    }
    else {
        q->items[q->back] = x;
        q->back = (q->back + 1) % (q->max);
        (q->size)++;
    }
}

char queue_char_dequeue(queue_char *q)
{
    assert(q!=NULL);
    char x;
    if (queue_char_isempty(q)) {
        printf("queue_char_dequeue error: queue is empty\n");
        exit(1);
    }
    else {
        x = q->items[q->front];
        q->front = (q->front + 1) % (q->max);
        (q->size)--;
        return x;
    }
}

char queue_char_front(queue_char *q)
{
    assert(q!=NULL);
    if (queue_char_isempty(q)) {
        printf("queue_char_front error: queue is empty\n");
        exit(1);
    }
    else
        return (q->items[q->front]);
}

void queue_char_print(queue_char *q, void (* item_print)(char item))
{
    assert(q!=NULL);
    int i=0;
    int j=q->front;
    printf("Q<<[ ");
    if (!queue_char_isempty(q)) {
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

void queue_char_release(queue_char *q)
{
    assert(q!=NULL);
    free(q->items);
    free(q);
}

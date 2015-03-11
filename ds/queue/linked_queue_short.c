// Auto-generated impl. file for a queue of short
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue_short.h"

struct node
{
    short item;
    struct node * next;
};

struct queue_short_implementation
{
    struct node * front;
    struct node * back;
    int size;
};

queue_short * new_bounded_queue_short(int max)
{
    printf("new_bounded_queue_short error: not available for linked implementation\n");
    exit(1);
}

queue_short * new_unbounded_queue_short()
{
    queue_short * q = (queue_short*)malloc(sizeof(queue_short));
    q->front = NULL;
    q->back = NULL;
    q->size = 0;
    return q;
}

int queue_short_isempty(queue_short *q)
{
    assert(q!=NULL);
    return (q->size == 0);
}
    
int queue_short_isfull(queue_short *q)
{
    assert(q!=NULL);
    return 0;
}
    
int queue_short_size(queue_short *q)
{
    assert(q!=NULL);
    return q->size;
}

void queue_short_enqueue(queue_short *q, short x)
{
    assert(q!=NULL);
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n==NULL) {
        printf("queue_short_enqueue error: OS failed to allocate memory\n");
        exit(1);
    }
    else {
        n->item = x;
        n->next = NULL;
        if (q->back==NULL) {
            q->front = n;
            q->back = n;
        }
        else {
            q->back->next = n;
            q->back = n;
        }
        (q->size)++;
    }
}

short queue_short_dequeue(queue_short *q)
{
    assert(q!=NULL);
    struct node * n;
    short x;
    if (queue_short_isempty(q)) {
        printf("queue_short_dequeue error: queue is empty\n");
        exit(1);
    }
    else {
        n = q->front;
        x = n->item;
        q->front = q->front->next;
        if (q->front == NULL) q->back = NULL;
        (q->size)--;
        free(n);
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
        return (q->front->item);
}

void queue_short_print(queue_short *q, void (* item_print)(short item))
{
    assert(q!=NULL);
    struct node *p = q->front;
    printf("Q<<[ ");
    if (p!=NULL) {
        while (p->next!=NULL) {
            item_print(p->item);
            printf(", ");
            p = p->next;
        }
        item_print(p->item);
    }
    printf(" ]");    
}

void queue_short_release(queue_short *q)
{
    assert(q!=NULL);
    free(q);
}

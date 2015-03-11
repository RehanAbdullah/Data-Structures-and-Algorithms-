// Auto-generated impl. file for a queue of long
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue_long.h"

struct node
{
    long item;
    struct node * next;
};

struct queue_long_implementation
{
    struct node * front;
    struct node * back;
    int size;
};

queue_long * new_bounded_queue_long(int max)
{
    printf("new_bounded_queue_long error: not available for linked implementation\n");
    exit(1);
}

queue_long * new_unbounded_queue_long()
{
    queue_long * q = (queue_long*)malloc(sizeof(queue_long));
    q->front = NULL;
    q->back = NULL;
    q->size = 0;
    return q;
}

int queue_long_isempty(queue_long *q)
{
    assert(q!=NULL);
    return (q->size == 0);
}
    
int queue_long_isfull(queue_long *q)
{
    assert(q!=NULL);
    return 0;
}
    
int queue_long_size(queue_long *q)
{
    assert(q!=NULL);
    return q->size;
}

void queue_long_enqueue(queue_long *q, long x)
{
    assert(q!=NULL);
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n==NULL) {
        printf("queue_long_enqueue error: OS failed to allocate memory\n");
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

long queue_long_dequeue(queue_long *q)
{
    assert(q!=NULL);
    struct node * n;
    long x;
    if (queue_long_isempty(q)) {
        printf("queue_long_dequeue error: queue is empty\n");
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

long queue_long_front(queue_long *q)
{
    assert(q!=NULL);
    if (queue_long_isempty(q)) {
        printf("queue_long_front error: queue is empty\n");
        exit(1);
    }
    else
        return (q->front->item);
}

void queue_long_print(queue_long *q, void (* item_print)(long item))
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

void queue_long_release(queue_long *q)
{
    assert(q!=NULL);
    free(q);
}

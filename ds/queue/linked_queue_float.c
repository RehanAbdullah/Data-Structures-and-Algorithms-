// Auto-generated impl. file for a queue of float
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue_float.h"

struct node
{
    float item;
    struct node * next;
};

struct queue_float_implementation
{
    struct node * front;
    struct node * back;
    int size;
};

queue_float * new_bounded_queue_float(int max)
{
    printf("new_bounded_queue_float error: not available for linked implementation\n");
    exit(1);
}

queue_float * new_unbounded_queue_float()
{
    queue_float * q = (queue_float*)malloc(sizeof(queue_float));
    q->front = NULL;
    q->back = NULL;
    q->size = 0;
    return q;
}

int queue_float_isempty(queue_float *q)
{
    assert(q!=NULL);
    return (q->size == 0);
}
    
int queue_float_isfull(queue_float *q)
{
    assert(q!=NULL);
    return 0;
}
    
int queue_float_size(queue_float *q)
{
    assert(q!=NULL);
    return q->size;
}

void queue_float_enqueue(queue_float *q, float x)
{
    assert(q!=NULL);
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n==NULL) {
        printf("queue_float_enqueue error: OS failed to allocate memory\n");
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

float queue_float_dequeue(queue_float *q)
{
    assert(q!=NULL);
    struct node * n;
    float x;
    if (queue_float_isempty(q)) {
        printf("queue_float_dequeue error: queue is empty\n");
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

float queue_float_front(queue_float *q)
{
    assert(q!=NULL);
    if (queue_float_isempty(q)) {
        printf("queue_float_front error: queue is empty\n");
        exit(1);
    }
    else
        return (q->front->item);
}

void queue_float_print(queue_float *q, void (* item_print)(float item))
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

void queue_float_release(queue_float *q)
{
    assert(q!=NULL);
    free(q);
}

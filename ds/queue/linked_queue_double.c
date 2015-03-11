// Auto-generated impl. file for a queue of double
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue_double.h"

struct node
{
    double item;
    struct node * next;
};

struct queue_double_implementation
{
    struct node * front;
    struct node * back;
    int size;
};

queue_double * new_bounded_queue_double(int max)
{
    printf("new_bounded_queue_double error: not available for linked implementation\n");
    exit(1);
}

queue_double * new_unbounded_queue_double()
{
    queue_double * q = (queue_double*)malloc(sizeof(queue_double));
    q->front = NULL;
    q->back = NULL;
    q->size = 0;
    return q;
}

int queue_double_isempty(queue_double *q)
{
    assert(q!=NULL);
    return (q->size == 0);
}
    
int queue_double_isfull(queue_double *q)
{
    assert(q!=NULL);
    return 0;
}
    
int queue_double_size(queue_double *q)
{
    assert(q!=NULL);
    return q->size;
}

void queue_double_enqueue(queue_double *q, double x)
{
    assert(q!=NULL);
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n==NULL) {
        printf("queue_double_enqueue error: OS failed to allocate memory\n");
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

double queue_double_dequeue(queue_double *q)
{
    assert(q!=NULL);
    struct node * n;
    double x;
    if (queue_double_isempty(q)) {
        printf("queue_double_dequeue error: queue is empty\n");
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

double queue_double_front(queue_double *q)
{
    assert(q!=NULL);
    if (queue_double_isempty(q)) {
        printf("queue_double_front error: queue is empty\n");
        exit(1);
    }
    else
        return (q->front->item);
}

void queue_double_print(queue_double *q, void (* item_print)(double item))
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

void queue_double_release(queue_double *q)
{
    assert(q!=NULL);
    free(q);
}

// Auto-generated impl. file for a queue of int
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue_int.h"

struct node
{
    int item;
    struct node * next;
};

struct queue_int_implementation
{
    struct node * front;
    struct node * back;
    int size;
};

queue_int * new_bounded_queue_int(int max)
{
    printf("new_bounded_queue_int error: not available for linked implementation\n");
    exit(1);
}

queue_int * new_unbounded_queue_int()
{
    queue_int * q = (queue_int*)malloc(sizeof(queue_int));
    q->front = NULL;
    q->back = NULL;
    q->size = 0;
    return q;
}

int queue_int_isempty(queue_int *q)
{
    assert(q!=NULL);
    return (q->size == 0);
}
    
int queue_int_isfull(queue_int *q)
{
    assert(q!=NULL);
    return 0;
}
    
int queue_int_size(queue_int *q)
{
    assert(q!=NULL);
    return q->size;
}

void queue_int_enqueue(queue_int *q, int x)
{
    assert(q!=NULL);
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n==NULL) {
        printf("queue_int_enqueue error: OS failed to allocate memory\n");
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

int queue_int_dequeue(queue_int *q)
{
    assert(q!=NULL);
    struct node * n;
    int x;
    if (queue_int_isempty(q)) {
        printf("queue_int_dequeue error: queue is empty\n");
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

int queue_int_front(queue_int *q)
{
    assert(q!=NULL);
    if (queue_int_isempty(q)) {
        printf("queue_int_front error: queue is empty\n");
        exit(1);
    }
    else
        return (q->front->item);
}

void queue_int_print(queue_int *q, void (* item_print)(int item))
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

void queue_int_release(queue_int *q)
{
    assert(q!=NULL);
    free(q);
}

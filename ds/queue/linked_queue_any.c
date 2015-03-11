// Auto-generated impl. file for a queue of any
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue_any.h"

struct node
{
    any item;
    struct node * next;
};

struct queue_any_implementation
{
    struct node * front;
    struct node * back;
    int size;
};

queue_any * new_bounded_queue_any(int max)
{
    printf("new_bounded_queue_any error: not available for linked implementation\n");
    exit(1);
}

queue_any * new_unbounded_queue_any()
{
    queue_any * q = (queue_any*)malloc(sizeof(queue_any));
    q->front = NULL;
    q->back = NULL;
    q->size = 0;
    return q;
}

int queue_any_isempty(queue_any *q)
{
    assert(q!=NULL);
    return (q->size == 0);
}
    
int queue_any_isfull(queue_any *q)
{
    assert(q!=NULL);
    return 0;
}
    
int queue_any_size(queue_any *q)
{
    assert(q!=NULL);
    return q->size;
}

void queue_any_enqueue(queue_any *q, any x)
{
    assert(q!=NULL);
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n==NULL) {
        printf("queue_any_enqueue error: OS failed to allocate memory\n");
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

any queue_any_dequeue(queue_any *q)
{
    assert(q!=NULL);
    struct node * n;
    any x;
    if (queue_any_isempty(q)) {
        printf("queue_any_dequeue error: queue is empty\n");
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

any queue_any_front(queue_any *q)
{
    assert(q!=NULL);
    if (queue_any_isempty(q)) {
        printf("queue_any_front error: queue is empty\n");
        exit(1);
    }
    else
        return (q->front->item);
}

void queue_any_print(queue_any *q, void (* item_print)(any item))
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

void queue_any_release(queue_any *q)
{
    assert(q!=NULL);
    free(q);
}

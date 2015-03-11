// Linked implementation of priority pqueue
// Author: drs

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"

struct node
{
    any item;
    struct node * next;
};

struct pqueue_implementation
{
    struct node * front;
    struct node * back;
    int size;
    le_fun le;
};

pqueue * new_bounded_pqueue(int max, le_fun le)
{
    printf("new_bounded_pqueue error: not available for linked implementation\n");
    exit(1);
}

pqueue * new_unbounded_pqueue(le_fun le)
{
    pqueue * q = (pqueue*)malloc(sizeof(pqueue));
    q->back = NULL;
    q->front = NULL;
    q->size = 0;
    q->le = le;
    return q;
}

int  pqueue_isempty(pqueue *q)
{
    assert(q!=NULL);
    return (q->size == 0);
}
    
int  pqueue_isfull(pqueue *q)
{
    return 0;
}
    
int  pqueue_size(pqueue *q)
{
    assert(q!=NULL);
    return q->size;
}

void pqueue_insert(pqueue *q, any x)
{
    assert(q!=NULL);
    struct node *p, *prev_p, *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->item = x;
    
    if (n==NULL) {
        printf("pqueue_insert error: OS failed to allocate memory\n");
        exit(1);
    }
    else if (pqueue_isempty(q)) {
        n->next = NULL;
        q->front = n;
        q->back = n;
    }
    else {
        prev_p = NULL;
        p = q->front;
        while(p!=NULL && q->le(n->item,p->item)) {
            prev_p = p;
            p = p->next;
        }
        if (prev_p==NULL) { // insert at front
            n->next = q->front;
            q->front = n;
        }
        else {
            n->next = p;
            prev_p->next = n;
        }
    }
    (q->size)++;
}

any pqueue_dequeue(pqueue *q)
{
    assert(q!=NULL);
    struct node *p, *n;
    any x;
    if (pqueue_isempty(q)) {
        printf("pqueue_depqueue error: pqueue is empty\n");
        exit(1);
    }
    else {
        x = q->front->item;
        n = q->front;
        q->front = q->front->next;
        if(q->front==NULL)
            q->back=NULL;
        free(n);
        (q->size)--;
        return x;
    }
}

any pqueue_front(pqueue *q)
{
    assert(q!=NULL);
    if (pqueue_isempty(q)) {
        printf("pqueue_front error: pqueue is empty\n");
        exit(1);
    }
    else
        return q->front->item;
}

void pqueue_print(pqueue *q, void (* item_print)(any item))
{
    assert(q!=NULL);
    struct node *p = q->front;
    printf("PrQ<<[ ");
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

void pqueue_release(pqueue *q)
{
    assert(q!=NULL);
    free(q);
}


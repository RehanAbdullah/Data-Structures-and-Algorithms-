// Auto-generated impl. file for a queue of char
// values.  This queue has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue_char.h"

struct node
{
    char item;
    struct node * next;
};

struct queue_char_implementation
{
    struct node * front;
    struct node * back;
    int size;
};

queue_char * new_bounded_queue_char(int max)
{
    printf("new_bounded_queue_char error: not available for linked implementation\n");
    exit(1);
}

queue_char * new_unbounded_queue_char()
{
    queue_char * q = (queue_char*)malloc(sizeof(queue_char));
    q->front = NULL;
    q->back = NULL;
    q->size = 0;
    return q;
}

int queue_char_isempty(queue_char *q)
{
    assert(q!=NULL);
    return (q->size == 0);
}
    
int queue_char_isfull(queue_char *q)
{
    assert(q!=NULL);
    return 0;
}
    
int queue_char_size(queue_char *q)
{
    assert(q!=NULL);
    return q->size;
}

void queue_char_enqueue(queue_char *q, char x)
{
    assert(q!=NULL);
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n==NULL) {
        printf("queue_char_enqueue error: OS failed to allocate memory\n");
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

char queue_char_dequeue(queue_char *q)
{
    assert(q!=NULL);
    struct node * n;
    char x;
    if (queue_char_isempty(q)) {
        printf("queue_char_dequeue error: queue is empty\n");
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

char queue_char_front(queue_char *q)
{
    assert(q!=NULL);
    if (queue_char_isempty(q)) {
        printf("queue_char_front error: queue is empty\n");
        exit(1);
    }
    else
        return (q->front->item);
}

void queue_char_print(queue_char *q, void (* item_print)(char item))
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

void queue_char_release(queue_char *q)
{
    assert(q!=NULL);
    free(q);
}

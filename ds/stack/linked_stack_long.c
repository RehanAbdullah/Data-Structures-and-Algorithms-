// Auto-generated impl. file for a stack of long
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack_long.h"

struct node
{
    long item;
    struct node * next;
};

struct stack_long_implementation
{
    struct node * top;
    int size;
};

stack_long * new_bounded_stack_long(int max)
{
    printf("new_bounded_stack_long error: not available for linked implementation\n");
    exit(1);
}

stack_long * new_unbounded_stack_long()
{
    stack_long * s = (stack_long*)malloc(sizeof(stack_long));
    s->top = NULL;
    s->size = 0;
    return s;
}

int stack_long_isempty(stack_long *s)
{
    assert(s!=NULL);
    return (s->size == 0);
}
    
int stack_long_isfull(stack_long *s)
{
    return 0;
}
    
int  stack_long_size(stack_long *s)
{
    assert(s!=NULL);
    return s->size;
}

void stack_long_push(stack_long *s, long x)
{
    assert(s!=NULL);
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n==NULL) {
        printf("stack_long_push error: OS failed to allocate memory\n");
        exit(1);
    }
    else {
        n->item = x;
        n->next = s->top;
        s->top  = n;
        (s->size)++;
    }
}

long stack_long_pop(stack_long *s)
{
    assert(s!=NULL);
    struct node * n;
    long x;
    if (stack_long_isempty(s)) {
        printf("stack_long_pop error: stack is empty\n");
        exit(1);
    }
    else {
        n = s->top;
        x = n->item;
        s->top = s->top->next;
        free(n);
        (s->size)--;
        return x;
    }
}

long  stack_long_top(stack_long *s)
{
    assert(s!=NULL);
    if (stack_long_isempty(s)) {
        printf("stack_long_top error: stack is empty\n");
        exit(1);
    }
    else
        return (s->top->item);
}

void stack_long_print(stack_long *s, void (* item_print)(long item))
{
    assert(s!=NULL);
    struct node *p = s->top;
    printf("STK<<[ ");
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

void stack_long_release(stack_long *s)
{
    assert(s!=NULL);
    free(s);
}

// Auto-generated impl. file for a stack of short
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack_short.h"

struct node
{
    short item;
    struct node * next;
};

struct stack_short_implementation
{
    struct node * top;
    int size;
};

stack_short * new_bounded_stack_short(int max)
{
    printf("new_bounded_stack_short error: not available for linked implementation\n");
    exit(1);
}

stack_short * new_unbounded_stack_short()
{
    stack_short * s = (stack_short*)malloc(sizeof(stack_short));
    s->top = NULL;
    s->size = 0;
    return s;
}

int stack_short_isempty(stack_short *s)
{
    assert(s!=NULL);
    return (s->size == 0);
}
    
int stack_short_isfull(stack_short *s)
{
    return 0;
}
    
int  stack_short_size(stack_short *s)
{
    assert(s!=NULL);
    return s->size;
}

void stack_short_push(stack_short *s, short x)
{
    assert(s!=NULL);
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n==NULL) {
        printf("stack_short_push error: OS failed to allocate memory\n");
        exit(1);
    }
    else {
        n->item = x;
        n->next = s->top;
        s->top  = n;
        (s->size)++;
    }
}

short stack_short_pop(stack_short *s)
{
    assert(s!=NULL);
    struct node * n;
    short x;
    if (stack_short_isempty(s)) {
        printf("stack_short_pop error: stack is empty\n");
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

short  stack_short_top(stack_short *s)
{
    assert(s!=NULL);
    if (stack_short_isempty(s)) {
        printf("stack_short_top error: stack is empty\n");
        exit(1);
    }
    else
        return (s->top->item);
}

void stack_short_print(stack_short *s, void (* item_print)(short item))
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

void stack_short_release(stack_short *s)
{
    assert(s!=NULL);
    free(s);
}

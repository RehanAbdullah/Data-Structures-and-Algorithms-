// Auto-generated impl. file for a stack of long
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack_long.h"

struct stack_long_implementation
{
    long * items;
    int top;
    int max;
};

stack_long * new_bounded_stack_long(int max)
{
    stack_long * s = (stack_long*)malloc(sizeof(stack_long));
    s->items = (long*)malloc(max * sizeof(long));
    s->top = 0;
    s->max = max;
    return s;
}

stack_long * new_unbounded_stack_long()
{
    printf("new_unbounded_stack_long error: not available for array implementation\n");
    exit(1);
}

int stack_long_isempty(stack_long *s)
{
    assert(s!=NULL);
    return (s->top == 0);
}
    
int stack_long_isfull(stack_long *s)
{
    assert(s!=NULL);
    return (s->top == s->max);
}
    
int stack_long_size(stack_long *s)
{
    assert(s!=NULL);
    return s->top;
}

void stack_long_push(stack_long *s, long x)
{
    assert(s!=NULL);
    if (stack_long_isfull(s)) {
        printf("stack_long_push error: stack is full\n");
        exit(1);
    }
    else {
        s->items[s->top] = x;
        (s->top)++;
    }
}

long stack_long_pop(stack_long *s)
{
    assert(s!=NULL);
    if (stack_long_isempty(s)) {
        printf("stack_long_pop error: stack is empty\n");
        exit(1);
    }
    else {
        (s->top)--;
        return (s->items[s->top]);
    }
}

long stack_long_top(stack_long *s)
{
    assert(s!=NULL);
    if (stack_long_isempty(s)) {
        printf("stack_long_top error: stack is empty\n");
        exit(1);
    }
    else
        return (s->items[(s->top)-1]);
}

void stack_long_print(stack_long *s, void (* item_print)(long item))
{
    assert(s!=NULL);
    int i=0;
    printf("STK<<[ ");
    if (!stack_long_isempty(s)) {
        while (i<((s->top)-1)) {
            item_print(s->items[i]);
            printf(", ");
            i++;
        }
        item_print(s->items[i]);
    }
    printf(" ]");
}

void stack_long_release(stack_long *s)
{
    assert(s!=NULL);
    free(s);
}

// Auto-generated impl. file for a stack of short
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack_short.h"

struct stack_short_implementation
{
    short * items;
    int top;
    int max;
};

stack_short * new_bounded_stack_short(int max)
{
    stack_short * s = (stack_short*)malloc(sizeof(stack_short));
    s->items = (short*)malloc(max * sizeof(short));
    s->top = 0;
    s->max = max;
    return s;
}

stack_short * new_unbounded_stack_short()
{
    printf("new_unbounded_stack_short error: not available for array implementation\n");
    exit(1);
}

int stack_short_isempty(stack_short *s)
{
    assert(s!=NULL);
    return (s->top == 0);
}
    
int stack_short_isfull(stack_short *s)
{
    assert(s!=NULL);
    return (s->top == s->max);
}
    
int stack_short_size(stack_short *s)
{
    assert(s!=NULL);
    return s->top;
}

void stack_short_push(stack_short *s, short x)
{
    assert(s!=NULL);
    if (stack_short_isfull(s)) {
        printf("stack_short_push error: stack is full\n");
        exit(1);
    }
    else {
        s->items[s->top] = x;
        (s->top)++;
    }
}

short stack_short_pop(stack_short *s)
{
    assert(s!=NULL);
    if (stack_short_isempty(s)) {
        printf("stack_short_pop error: stack is empty\n");
        exit(1);
    }
    else {
        (s->top)--;
        return (s->items[s->top]);
    }
}

short stack_short_top(stack_short *s)
{
    assert(s!=NULL);
    if (stack_short_isempty(s)) {
        printf("stack_short_top error: stack is empty\n");
        exit(1);
    }
    else
        return (s->items[(s->top)-1]);
}

void stack_short_print(stack_short *s, void (* item_print)(short item))
{
    assert(s!=NULL);
    int i=0;
    printf("STK<<[ ");
    if (!stack_short_isempty(s)) {
        while (i<((s->top)-1)) {
            item_print(s->items[i]);
            printf(", ");
            i++;
        }
        item_print(s->items[i]);
    }
    printf(" ]");
}

void stack_short_release(stack_short *s)
{
    assert(s!=NULL);
    free(s);
}

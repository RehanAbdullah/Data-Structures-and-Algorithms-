// Auto-generated impl. file for a stack of any
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack_any.h"

struct stack_any_implementation
{
    any * items;
    int top;
    int max;
};

stack_any * new_bounded_stack_any(int max)
{
    stack_any * s = (stack_any*)malloc(sizeof(stack_any));
    s->items = (any*)malloc(max * sizeof(any));
    s->top = 0;
    s->max = max;
    return s;
}

stack_any * new_unbounded_stack_any()
{
    printf("new_unbounded_stack_any error: not available for array implementation\n");
    exit(1);
}

int stack_any_isempty(stack_any *s)
{
    assert(s!=NULL);
    return (s->top == 0);
}
    
int stack_any_isfull(stack_any *s)
{
    assert(s!=NULL);
    return (s->top == s->max);
}
    
int stack_any_size(stack_any *s)
{
    assert(s!=NULL);
    return s->top;
}

void stack_any_push(stack_any *s, any x)
{
    assert(s!=NULL);
    if (stack_any_isfull(s)) {
        printf("stack_any_push error: stack is full\n");
        exit(1);
    }
    else {
        s->items[s->top] = x;
        (s->top)++;
    }
}

any stack_any_pop(stack_any *s)
{
    assert(s!=NULL);
    if (stack_any_isempty(s)) {
        printf("stack_any_pop error: stack is empty\n");
        exit(1);
    }
    else {
        (s->top)--;
        return (s->items[s->top]);
    }
}

any stack_any_top(stack_any *s)
{
    assert(s!=NULL);
    if (stack_any_isempty(s)) {
        printf("stack_any_top error: stack is empty\n");
        exit(1);
    }
    else
        return (s->items[(s->top)-1]);
}

void stack_any_print(stack_any *s, void (* item_print)(any item))
{
    assert(s!=NULL);
    int i=0;
    printf("STK<<[ ");
    if (!stack_any_isempty(s)) {
        while (i<((s->top)-1)) {
            item_print(s->items[i]);
            printf(", ");
            i++;
        }
        item_print(s->items[i]);
    }
    printf(" ]");
}

void stack_any_release(stack_any *s)
{
    assert(s!=NULL);
    free(s);
}

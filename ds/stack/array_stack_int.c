// Auto-generated impl. file for a stack of int
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack_int.h"

struct stack_int_implementation
{
    int * items;
    int top;
    int max;
};

stack_int * new_bounded_stack_int(int max)
{
    stack_int * s = (stack_int*)malloc(sizeof(stack_int));
    s->items = (int*)malloc(max * sizeof(int));
    s->top = 0;
    s->max = max;
    return s;
}

stack_int * new_unbounded_stack_int()
{
    printf("new_unbounded_stack_int error: not available for array implementation\n");
    exit(1);
}

int stack_int_isempty(stack_int *s)
{
    assert(s!=NULL);
    return (s->top == 0);
}
    
int stack_int_isfull(stack_int *s)
{
    assert(s!=NULL);
    return (s->top == s->max);
}
    
int stack_int_size(stack_int *s)
{
    assert(s!=NULL);
    return s->top;
}

void stack_int_push(stack_int *s, int x)
{
    assert(s!=NULL);
    if (stack_int_isfull(s)) {
        printf("stack_int_push error: stack is full\n");
        exit(1);
    }
    else {
        s->items[s->top] = x;
        (s->top)++;
    }
}

int stack_int_pop(stack_int *s)
{
    assert(s!=NULL);
    if (stack_int_isempty(s)) {
        printf("stack_int_pop error: stack is empty\n");
        exit(1);
    }
    else {
        (s->top)--;
        return (s->items[s->top]);
    }
}

int stack_int_top(stack_int *s)
{
    assert(s!=NULL);
    if (stack_int_isempty(s)) {
        printf("stack_int_top error: stack is empty\n");
        exit(1);
    }
    else
        return (s->items[(s->top)-1]);
}

void stack_int_print(stack_int *s, void (* item_print)(int item))
{
    assert(s!=NULL);
    int i=0;
    printf("STK<<[ ");
    if (!stack_int_isempty(s)) {
        while (i<((s->top)-1)) {
            item_print(s->items[i]);
            printf(", ");
            i++;
        }
        item_print(s->items[i]);
    }
    printf(" ]");
}

void stack_int_release(stack_int *s)
{
    assert(s!=NULL);
    free(s);
}

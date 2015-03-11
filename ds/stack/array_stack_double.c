// Auto-generated impl. file for a stack of double
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack_double.h"

struct stack_double_implementation
{
    double * items;
    int top;
    int max;
};

stack_double * new_bounded_stack_double(int max)
{
    stack_double * s = (stack_double*)malloc(sizeof(stack_double));
    s->items = (double*)malloc(max * sizeof(double));
    s->top = 0;
    s->max = max;
    return s;
}

stack_double * new_unbounded_stack_double()
{
    printf("new_unbounded_stack_double error: not available for array implementation\n");
    exit(1);
}

int stack_double_isempty(stack_double *s)
{
    assert(s!=NULL);
    return (s->top == 0);
}
    
int stack_double_isfull(stack_double *s)
{
    assert(s!=NULL);
    return (s->top == s->max);
}
    
int stack_double_size(stack_double *s)
{
    assert(s!=NULL);
    return s->top;
}

void stack_double_push(stack_double *s, double x)
{
    assert(s!=NULL);
    if (stack_double_isfull(s)) {
        printf("stack_double_push error: stack is full\n");
        exit(1);
    }
    else {
        s->items[s->top] = x;
        (s->top)++;
    }
}

double stack_double_pop(stack_double *s)
{
    assert(s!=NULL);
    if (stack_double_isempty(s)) {
        printf("stack_double_pop error: stack is empty\n");
        exit(1);
    }
    else {
        (s->top)--;
        return (s->items[s->top]);
    }
}

double stack_double_top(stack_double *s)
{
    assert(s!=NULL);
    if (stack_double_isempty(s)) {
        printf("stack_double_top error: stack is empty\n");
        exit(1);
    }
    else
        return (s->items[(s->top)-1]);
}

void stack_double_print(stack_double *s, void (* item_print)(double item))
{
    assert(s!=NULL);
    int i=0;
    printf("STK<<[ ");
    if (!stack_double_isempty(s)) {
        while (i<((s->top)-1)) {
            item_print(s->items[i]);
            printf(", ");
            i++;
        }
        item_print(s->items[i]);
    }
    printf(" ]");
}

void stack_double_release(stack_double *s)
{
    assert(s!=NULL);
    free(s);
}

// Auto-generated impl. file for a stack of float
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack_float.h"

struct stack_float_implementation
{
    float * items;
    int top;
    int max;
};

stack_float * new_bounded_stack_float(int max)
{
    stack_float * s = (stack_float*)malloc(sizeof(stack_float));
    s->items = (float*)malloc(max * sizeof(float));
    s->top = 0;
    s->max = max;
    return s;
}

stack_float * new_unbounded_stack_float()
{
    printf("new_unbounded_stack_float error: not available for array implementation\n");
    exit(1);
}

int stack_float_isempty(stack_float *s)
{
    assert(s!=NULL);
    return (s->top == 0);
}
    
int stack_float_isfull(stack_float *s)
{
    assert(s!=NULL);
    return (s->top == s->max);
}
    
int stack_float_size(stack_float *s)
{
    assert(s!=NULL);
    return s->top;
}

void stack_float_push(stack_float *s, float x)
{
    assert(s!=NULL);
    if (stack_float_isfull(s)) {
        printf("stack_float_push error: stack is full\n");
        exit(1);
    }
    else {
        s->items[s->top] = x;
        (s->top)++;
    }
}

float stack_float_pop(stack_float *s)
{
    assert(s!=NULL);
    if (stack_float_isempty(s)) {
        printf("stack_float_pop error: stack is empty\n");
        exit(1);
    }
    else {
        (s->top)--;
        return (s->items[s->top]);
    }
}

float stack_float_top(stack_float *s)
{
    assert(s!=NULL);
    if (stack_float_isempty(s)) {
        printf("stack_float_top error: stack is empty\n");
        exit(1);
    }
    else
        return (s->items[(s->top)-1]);
}

void stack_float_print(stack_float *s, void (* item_print)(float item))
{
    assert(s!=NULL);
    int i=0;
    printf("STK<<[ ");
    if (!stack_float_isempty(s)) {
        while (i<((s->top)-1)) {
            item_print(s->items[i]);
            printf(", ");
            i++;
        }
        item_print(s->items[i]);
    }
    printf(" ]");
}

void stack_float_release(stack_float *s)
{
    assert(s!=NULL);
    free(s);
}

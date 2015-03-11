// Auto-generated impl. file for a stack of float
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack_float.h"

struct node
{
    float item;
    struct node * next;
};

struct stack_float_implementation
{
    struct node * top;
    int size;
};

stack_float * new_bounded_stack_float(int max)
{
    printf("new_bounded_stack_float error: not available for linked implementation\n");
    exit(1);
}

stack_float * new_unbounded_stack_float()
{
    stack_float * s = (stack_float*)malloc(sizeof(stack_float));
    s->top = NULL;
    s->size = 0;
    return s;
}

int stack_float_isempty(stack_float *s)
{
    assert(s!=NULL);
    return (s->size == 0);
}
    
int stack_float_isfull(stack_float *s)
{
    return 0;
}
    
int  stack_float_size(stack_float *s)
{
    assert(s!=NULL);
    return s->size;
}

void stack_float_push(stack_float *s, float x)
{
    assert(s!=NULL);
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n==NULL) {
        printf("stack_float_push error: OS failed to allocate memory\n");
        exit(1);
    }
    else {
        n->item = x;
        n->next = s->top;
        s->top  = n;
        (s->size)++;
    }
}

float stack_float_pop(stack_float *s)
{
    assert(s!=NULL);
    struct node * n;
    float x;
    if (stack_float_isempty(s)) {
        printf("stack_float_pop error: stack is empty\n");
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

float  stack_float_top(stack_float *s)
{
    assert(s!=NULL);
    if (stack_float_isempty(s)) {
        printf("stack_float_top error: stack is empty\n");
        exit(1);
    }
    else
        return (s->top->item);
}

void stack_float_print(stack_float *s, void (* item_print)(float item))
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

void stack_float_release(stack_float *s)
{
    assert(s!=NULL);
    free(s);
}

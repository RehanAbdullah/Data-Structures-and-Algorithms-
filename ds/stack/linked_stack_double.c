// Auto-generated impl. file for a stack of double
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack_double.h"

struct node
{
    double item;
    struct node * next;
};

struct stack_double_implementation
{
    struct node * top;
    int size;
};

stack_double * new_bounded_stack_double(int max)
{
    printf("new_bounded_stack_double error: not available for linked implementation\n");
    exit(1);
}

stack_double * new_unbounded_stack_double()
{
    stack_double * s = (stack_double*)malloc(sizeof(stack_double));
    s->top = NULL;
    s->size = 0;
    return s;
}

int stack_double_isempty(stack_double *s)
{
    assert(s!=NULL);
    return (s->size == 0);
}
    
int stack_double_isfull(stack_double *s)
{
    return 0;
}
    
int  stack_double_size(stack_double *s)
{
    assert(s!=NULL);
    return s->size;
}

void stack_double_push(stack_double *s, double x)
{
    assert(s!=NULL);
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n==NULL) {
        printf("stack_double_push error: OS failed to allocate memory\n");
        exit(1);
    }
    else {
        n->item = x;
        n->next = s->top;
        s->top  = n;
        (s->size)++;
    }
}

double stack_double_pop(stack_double *s)
{
    assert(s!=NULL);
    struct node * n;
    double x;
    if (stack_double_isempty(s)) {
        printf("stack_double_pop error: stack is empty\n");
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

double  stack_double_top(stack_double *s)
{
    assert(s!=NULL);
    if (stack_double_isempty(s)) {
        printf("stack_double_top error: stack is empty\n");
        exit(1);
    }
    else
        return (s->top->item);
}

void stack_double_print(stack_double *s, void (* item_print)(double item))
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

void stack_double_release(stack_double *s)
{
    assert(s!=NULL);
    free(s);
}

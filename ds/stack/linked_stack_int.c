// Auto-generated impl. file for a stack of int
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack_int.h"

struct node
{
    int item;
    struct node * next;
};

struct stack_int_implementation
{
    struct node * top;
    int size;
};

stack_int * new_bounded_stack_int(int max)
{
    printf("new_bounded_stack_int error: not available for linked implementation\n");
    exit(1);
}

stack_int * new_unbounded_stack_int()
{
    stack_int * s = (stack_int*)malloc(sizeof(stack_int));
    s->top = NULL;
    s->size = 0;
    return s;
}

int stack_int_isempty(stack_int *s)
{
    assert(s!=NULL);
    return (s->size == 0);
}
    
int stack_int_isfull(stack_int *s)
{
    return 0;
}
    
int  stack_int_size(stack_int *s)
{
    assert(s!=NULL);
    return s->size;
}

void stack_int_push(stack_int *s, int x)
{
    assert(s!=NULL);
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n==NULL) {
        printf("stack_int_push error: OS failed to allocate memory\n");
        exit(1);
    }
    else {
        n->item = x;
        n->next = s->top;
        s->top  = n;
        (s->size)++;
    }
}

int stack_int_pop(stack_int *s)
{
    assert(s!=NULL);
    struct node * n;
    int x;
    if (stack_int_isempty(s)) {
        printf("stack_int_pop error: stack is empty\n");
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

int  stack_int_top(stack_int *s)
{
    assert(s!=NULL);
    if (stack_int_isempty(s)) {
        printf("stack_int_top error: stack is empty\n");
        exit(1);
    }
    else
        return (s->top->item);
}

void stack_int_print(stack_int *s, void (* item_print)(int item))
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

void stack_int_release(stack_int *s)
{
    assert(s!=NULL);
    free(s);
}

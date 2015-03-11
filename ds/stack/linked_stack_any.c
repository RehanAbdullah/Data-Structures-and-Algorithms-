// Auto-generated impl. file for a stack of any
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack_any.h"

struct node
{
    any item;
    struct node * next;
};

struct stack_any_implementation
{
    struct node * top;
    int size;
};

stack_any * new_bounded_stack_any(int max)
{
    printf("new_bounded_stack_any error: not available for linked implementation\n");
    exit(1);
}

stack_any * new_unbounded_stack_any()
{
    stack_any * s = (stack_any*)malloc(sizeof(stack_any));
    s->top = NULL;
    s->size = 0;
    return s;
}

int stack_any_isempty(stack_any *s)
{
    assert(s!=NULL);
    return (s->size == 0);
}
    
int stack_any_isfull(stack_any *s)
{
    return 0;
}
    
int  stack_any_size(stack_any *s)
{
    assert(s!=NULL);
    return s->size;
}

void stack_any_push(stack_any *s, any x)
{
    assert(s!=NULL);
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n==NULL) {
        printf("stack_any_push error: OS failed to allocate memory\n");
        exit(1);
    }
    else {
        n->item = x;
        n->next = s->top;
        s->top  = n;
        (s->size)++;
    }
}

any stack_any_pop(stack_any *s)
{
    assert(s!=NULL);
    struct node * n;
    any x;
    if (stack_any_isempty(s)) {
        printf("stack_any_pop error: stack is empty\n");
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

any  stack_any_top(stack_any *s)
{
    assert(s!=NULL);
    if (stack_any_isempty(s)) {
        printf("stack_any_top error: stack is empty\n");
        exit(1);
    }
    else
        return (s->top->item);
}

void stack_any_print(stack_any *s, void (* item_print)(any item))
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

void stack_any_release(stack_any *s)
{
    assert(s!=NULL);
    free(s);
}

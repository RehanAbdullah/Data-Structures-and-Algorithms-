// Auto-generated impl. file for a stack of char
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack_char.h"

struct node
{
    char item;
    struct node * next;
};

struct stack_char_implementation
{
    struct node * top;
    int size;
};

stack_char * new_bounded_stack_char(int max)
{
    printf("new_bounded_stack_char error: not available for linked implementation\n");
    exit(1);
}

stack_char * new_unbounded_stack_char()
{
    stack_char * s = (stack_char*)malloc(sizeof(stack_char));
    s->top = NULL;
    s->size = 0;
    return s;
}

int stack_char_isempty(stack_char *s)
{
    assert(s!=NULL);
    return (s->size == 0);
}
    
int stack_char_isfull(stack_char *s)
{
    return 0;
}
    
int  stack_char_size(stack_char *s)
{
    assert(s!=NULL);
    return s->size;
}

void stack_char_push(stack_char *s, char x)
{
    assert(s!=NULL);
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n==NULL) {
        printf("stack_char_push error: OS failed to allocate memory\n");
        exit(1);
    }
    else {
        n->item = x;
        n->next = s->top;
        s->top  = n;
        (s->size)++;
    }
}

char stack_char_pop(stack_char *s)
{
    assert(s!=NULL);
    struct node * n;
    char x;
    if (stack_char_isempty(s)) {
        printf("stack_char_pop error: stack is empty\n");
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

char  stack_char_top(stack_char *s)
{
    assert(s!=NULL);
    if (stack_char_isempty(s)) {
        printf("stack_char_top error: stack is empty\n");
        exit(1);
    }
    else
        return (s->top->item);
}

void stack_char_print(stack_char *s, void (* item_print)(char item))
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

void stack_char_release(stack_char *s)
{
    assert(s!=NULL);
    free(s);
}

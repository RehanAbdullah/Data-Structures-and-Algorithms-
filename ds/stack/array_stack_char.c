// Auto-generated impl. file for a stack of char
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack_char.h"

struct stack_char_implementation
{
    char * items;
    int top;
    int max;
};

stack_char * new_bounded_stack_char(int max)
{
    stack_char * s = (stack_char*)malloc(sizeof(stack_char));
    s->items = (char*)malloc(max * sizeof(char));
    s->top = 0;
    s->max = max;
    return s;
}

stack_char * new_unbounded_stack_char()
{
    printf("new_unbounded_stack_char error: not available for array implementation\n");
    exit(1);
}

int stack_char_isempty(stack_char *s)
{
    assert(s!=NULL);
    return (s->top == 0);
}
    
int stack_char_isfull(stack_char *s)
{
    assert(s!=NULL);
    return (s->top == s->max);
}
    
int stack_char_size(stack_char *s)
{
    assert(s!=NULL);
    return s->top;
}

void stack_char_push(stack_char *s, char x)
{
    assert(s!=NULL);
    if (stack_char_isfull(s)) {
        printf("stack_char_push error: stack is full\n");
        exit(1);
    }
    else {
        s->items[s->top] = x;
        (s->top)++;
    }
}

char stack_char_pop(stack_char *s)
{
    assert(s!=NULL);
    if (stack_char_isempty(s)) {
        printf("stack_char_pop error: stack is empty\n");
        exit(1);
    }
    else {
        (s->top)--;
        return (s->items[s->top]);
    }
}

char stack_char_top(stack_char *s)
{
    assert(s!=NULL);
    if (stack_char_isempty(s)) {
        printf("stack_char_top error: stack is empty\n");
        exit(1);
    }
    else
        return (s->items[(s->top)-1]);
}

void stack_char_print(stack_char *s, void (* item_print)(char item))
{
    assert(s!=NULL);
    int i=0;
    printf("STK<<[ ");
    if (!stack_char_isempty(s)) {
        while (i<((s->top)-1)) {
            item_print(s->items[i]);
            printf(", ");
            i++;
        }
        item_print(s->items[i]);
    }
    printf(" ]");
}

void stack_char_release(stack_char *s)
{
    assert(s!=NULL);
    free(s);
}

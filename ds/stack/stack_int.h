#ifndef STACK_int_H
#define STACK_int_H

// Auto-generated header file for a stack of int
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct stack_int_implementation stack_int;

stack_int * new_bounded_stack_int(int max);
stack_int * new_unbounded_stack_int();
int stack_int_isempty(stack_int *s);
int stack_int_isfull(stack_int *s);
int stack_int_size(stack_int *s);
void stack_int_push(stack_int *s, int x);
int stack_int_pop(stack_int *s);
int stack_int_top(stack_int *s);
void stack_int_print(stack_int *s, void (* item_print)(int item));
void stack_int_release(stack_int *s);

#endif

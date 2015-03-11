#ifndef STACK_long_H
#define STACK_long_H

// Auto-generated header file for a stack of long
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct stack_long_implementation stack_long;

stack_long * new_bounded_stack_long(int max);
stack_long * new_unbounded_stack_long();
int stack_long_isempty(stack_long *s);
int stack_long_isfull(stack_long *s);
int stack_long_size(stack_long *s);
void stack_long_push(stack_long *s, long x);
long stack_long_pop(stack_long *s);
long stack_long_top(stack_long *s);
void stack_long_print(stack_long *s, void (* item_print)(long item));
void stack_long_release(stack_long *s);

#endif

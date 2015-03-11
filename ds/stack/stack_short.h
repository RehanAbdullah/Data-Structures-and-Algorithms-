#ifndef STACK_short_H
#define STACK_short_H

// Auto-generated header file for a stack of short
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct stack_short_implementation stack_short;

stack_short * new_bounded_stack_short(int max);
stack_short * new_unbounded_stack_short();
int stack_short_isempty(stack_short *s);
int stack_short_isfull(stack_short *s);
int stack_short_size(stack_short *s);
void stack_short_push(stack_short *s, short x);
short stack_short_pop(stack_short *s);
short stack_short_top(stack_short *s);
void stack_short_print(stack_short *s, void (* item_print)(short item));
void stack_short_release(stack_short *s);

#endif

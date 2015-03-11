#ifndef STACK_float_H
#define STACK_float_H

// Auto-generated header file for a stack of float
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct stack_float_implementation stack_float;

stack_float * new_bounded_stack_float(int max);
stack_float * new_unbounded_stack_float();
int stack_float_isempty(stack_float *s);
int stack_float_isfull(stack_float *s);
int stack_float_size(stack_float *s);
void stack_float_push(stack_float *s, float x);
float stack_float_pop(stack_float *s);
float stack_float_top(stack_float *s);
void stack_float_print(stack_float *s, void (* item_print)(float item));
void stack_float_release(stack_float *s);

#endif

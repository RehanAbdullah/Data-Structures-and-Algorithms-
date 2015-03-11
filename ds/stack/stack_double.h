#ifndef STACK_double_H
#define STACK_double_H

// Auto-generated header file for a stack of double
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct stack_double_implementation stack_double;

stack_double * new_bounded_stack_double(int max);
stack_double * new_unbounded_stack_double();
int stack_double_isempty(stack_double *s);
int stack_double_isfull(stack_double *s);
int stack_double_size(stack_double *s);
void stack_double_push(stack_double *s, double x);
double stack_double_pop(stack_double *s);
double stack_double_top(stack_double *s);
void stack_double_print(stack_double *s, void (* item_print)(double item));
void stack_double_release(stack_double *s);

#endif

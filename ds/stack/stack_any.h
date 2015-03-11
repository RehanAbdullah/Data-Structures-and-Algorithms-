#ifndef STACK_any_H
#define STACK_any_H

// Auto-generated header file for a stack of any
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct stack_any_implementation stack_any;
#include "any.h"

stack_any * new_bounded_stack_any(int max);
stack_any * new_unbounded_stack_any();
int stack_any_isempty(stack_any *s);
int stack_any_isfull(stack_any *s);
int stack_any_size(stack_any *s);
void stack_any_push(stack_any *s, any x);
any stack_any_pop(stack_any *s);
any stack_any_top(stack_any *s);
void stack_any_print(stack_any *s, void (* item_print)(any item));
void stack_any_release(stack_any *s);

#endif

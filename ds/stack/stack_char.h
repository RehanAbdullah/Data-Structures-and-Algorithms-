#ifndef STACK_char_H
#define STACK_char_H

// Auto-generated header file for a stack of char
// values.  This stack has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct stack_char_implementation stack_char;

stack_char * new_bounded_stack_char(int max);
stack_char * new_unbounded_stack_char();
int stack_char_isempty(stack_char *s);
int stack_char_isfull(stack_char *s);
int stack_char_size(stack_char *s);
void stack_char_push(stack_char *s, char x);
char stack_char_pop(stack_char *s);
char stack_char_top(stack_char *s);
void stack_char_print(stack_char *s, void (* item_print)(char item));
void stack_char_release(stack_char *s);

#endif

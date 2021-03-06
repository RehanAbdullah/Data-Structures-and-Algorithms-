/*
shunt2.c

We extend the shunt program by adding a right-associative exponentiation operator (^)
and a right-associative unary negation operator (~).  A little more of Dijkstra's
shunting algorithm is implemented to facilitate these extra features.

Once again we have made a number of hard-wired simplifications in order to highlight
the algorithm and the use of stacks rather than producing a fully general-purpose
expression parser.

The operators we allow are the standard C arithmetic operators + - * / %,
an exponentiation operator ^, and a unary negation operator ~.

The variables we permit are only the lower-case characters 'a' .. 'z'.

*/

#include <stdio.h>
#include <string.h>
#include "stack_char.h"
#define MAX_EXPR_LEN    1024
#define DEMO_EXPR       "a-b^~(c+d*e)^~f-~g*(h/~~(i%j))"

void printchar(char c)
{
	printf("%c", c);
}
int isopen(char c)
{
	return (c=='(');
}
int isvar(char c)
{
	return (c>='a' && c<='z');
}
int isoperator(char c) 
{
	switch(c)
	{
	case '~' : 
	case '^' : 
	case '*' : 
	case '/' : 
	case '%' : 
	case '+' : 
	case '-' : return 1;
	default  : return 0;
	}
}
int prec(char c)
{
	switch(c)
	{
	case '~' : return 9;
	case '^' : return 6;
	case '*' :
	case '/' : return 5;
	case '%' : return 5;
	case '+' :
	case '-' : return 4;
	default  : return 0;
	}
}
int isleftassoc(char c)
{
	switch(c)
	{
	case '~' : return 0;
	case '^' : return 0;
	default  : return 1;
	}
}

int main(int argc, char **argv)
{
	char infix[MAX_EXPR_LEN];
	char postfix[MAX_EXPR_LEN];
	strcpy(infix, (argc>1) ? argv[1] : DEMO_EXPR);
	stack_char * s = new_unbounded_stack_char();
	int i = 0, j = 0;
	while (infix[i] != '\0') {
		postfix[j] = '\0';
		printf("\n%40s\t%20s    ",infix+i,postfix);
		stack_char_print(s,printchar);
		switch (infix[i]) {
		case ' ':
			break;
		case '(':
			stack_char_push(s,infix[i]);
			break;
		case '~':
		case '^':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
			while (!stack_char_isempty(s) && isoperator(stack_char_top(s)) &&
				((isleftassoc(infix[i]) && prec(infix[i]) <= prec(stack_char_top(s)))
					||                       prec(infix[i]) <  prec(stack_char_top(s))
					)
				) postfix[j++] = stack_char_pop(s);
				stack_char_push(s,infix[i]);
				break;
			case ')':
				while (!isopen(stack_char_top(s)))
					postfix[j++] = stack_char_pop(s);
				stack_char_pop(s);
				break;
			default:
				postfix[j++] = infix[i];
		}
		i++;
	}
	while (!stack_char_isempty(s))
		postfix[j++] = stack_char_pop(s);
	postfix[j] = '\0';
	printf("\n%s\n",infix);
	printf("\n%s\n",postfix);
}

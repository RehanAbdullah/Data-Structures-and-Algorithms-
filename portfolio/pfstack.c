#include <stdio.h>
#include <string.h>
#include "stack_char.h"
#define MAX_EXPR_LEN 	80
#define DEMO_EXPR		"(a+b^g)h^j*(c-d^f)/e^k"

void printchar(char c) {
	printf("'%c'", c);
}

int isopen(char c) {
	return (c=='(');
}

int isvar(char c) {
	return (c>='a' && c<='z');
}

int isoperator(char c) { 
	
	switch(c)
	{
	case '^':
	case '*':
	case '/':
	case '+':
	case '-': return 1;
	default : return 0;
	}
	
}

int prec(char c) {
	// return (c=='+' || c=='-') ? 4 : 5; 
	
	if(c=='+') {
		return 4;
	}
	else if(c=='^') {
		return 6;
	}
	else if(c=='-') {
		return 5;
	}
}

int isleftaasoc(char c)

{
	switch(c)
	{
	case'^': return 0;
	default: return 1;
	}
}


int main(int argc, char **argv) {
	char infix[MAX_EXPR_LEN];
	char postfix[MAX_EXPR_LEN];
	
	strcpy(infix, (argc>1) ? argv[1] : DEMO_EXPR);
	// stack_char * s = new_unbounded_stack_char(MAX_EXPR_LEN)
	stack_char * s = new_bounded_stack_char(MAX_EXPR_LEN);
	
	int i = 0, j = 0;
	while (infix[i] != '\0') {
		postfix[j] = '\0';
		printf("\n%30s\t%20s ",infix+i,postfix);
		stack_char_print(s,&printchar);
		switch (infix[i]) {
		case ' ':
			break;
		case '(':
			stack_char_push(s,infix[i]);
			break;
		case '+':
		case '-':
		case '^':
		case '*':
		case '/':
			while (!stack_char_isempty(s) &&
				isoperator(stack_char_top(s)) &&
			prec(infix[i]) <= prec(stack_char_top(s)))
			
			postfix[j++] = stack_char_pop(s);
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
	
	printf("\n%s\n",postfix);
}
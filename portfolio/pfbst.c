#include <stdlib.h>
#include <stdio.h>
#include "any.h"
#include "pfbst_char.h"
#define NEWLINE printf("\n");

void print_char(char c)
{
	putchar(c);
}


int main()
{
	bst_char *t = new_bst_char();
	char a, c;
	bst_char_insert(t,'N');
	bst_char_insert(t,'T');
	bst_char_insert(t,'Q');
	bst_char_insert(t,'P');
	bst_char_insert(t,'D');
	bst_char_insert(t,'C');
	bst_char_insert(t,'F');
	// bst_char_simple_print(t,print_char);
	bst_char_pretty_print(t);
	printf("Action? [(a)dd; (i)sbalanced; (t)raverse; (d)elete; ([)prefix; (-)infix; (])postfix (q)uit; ] ");
	scanf(" %c", &a);
	while (a != 'q') {
		switch (a) {
		case 'a' : scanf(" %c", &c);
			bst_char_insert(t, c);
			break;
		case 'd' : scanf(" %c", &c);
			bst_char_delete(t, c);
			break;

		case '[' : printf("Prefix traversal: ");
			bst_char_preorder_print(t,print_char);
			putchar('\n');
			break;
	
		case '-' : printf("Infix traversal: ");
			bst_char_inorder_print(t,print_char);
			putchar('\n');
			break;
		case ']' : printf("Postfix traversal: ");
			bst_char_postorder_print(t,print_char);
			putchar('\n');
			break;
		case 'q': break;
		default : printf("???\n");
		}
		// bst_char_simple_print(t,print_char);
		bst_char_pretty_print(t);
		printf("Action? [(a)dd; (d)elete; (i)sbalanced; (t)raverse; (<)prefix; (-)infix; (>)postfix (q)uit; ] ");
		scanf(" %c", &a);
	}
	NEWLINE
}

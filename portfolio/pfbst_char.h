#ifndef BST_char_H
#define BST_char_H
// Auto-generated header file for a bst of char
// values. This bst has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.
typedef struct bst_char_implementation bst_char;
bst_char * new_bst_char();
int bst_char_isempty(bst_char *t);
int bst_char_isfull(bst_char *t);
int bst_char_size(bst_char *t);
int bst_char_depth(bst_char *t);
void bst_char_insert(bst_char *t, char x);
void bst_char_delete(bst_char *t, char x);
int bst_char_contains(bst_char *t, char x);
int bst_char_isbalanced(bst_char *t);

void bst_char_preorder_print(bst_char *t, void (* item_print)(char item));
void bst_char_inorder_print(bst_char *t, void (* item_print)(char item));
void bst_char_postorder_print(bst_char *t, void (* item_print)(char item));
void bst_char_simple_print(bst_char *t, void (* item_print)(char item));
void bst_char_pretty_print(bst_char *t);
void bst_char_release(bst_char *t);
#endif

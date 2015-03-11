#ifndef BST_int_H
#define BST_int_H

// Auto-generated header file for a bst of int
// values.  This bst has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct bst_int_implementation bst_int;

bst_int * new_bst_int();
int  bst_int_isempty(bst_int *t);
int  bst_int_isfull(bst_int *t);
int  bst_int_size(bst_int *t);
int  bst_int_depth(bst_int *t);
void bst_int_insert(bst_int *t, int x);
void bst_int_delete(bst_int *t, int x);
int  bst_int_contains(bst_int *t, int x);
void bst_int_preorder_print(bst_int *t, void (* item_print)(int item));
void bst_int_inorder_print(bst_int *t, void (* item_print)(int item));
void bst_int_postorder_print(bst_int *t, void (* item_print)(int item));
void bst_int_simple_print(bst_int *t, void (* item_print)(int item));

void bst_int_release(bst_int *t);
#endif

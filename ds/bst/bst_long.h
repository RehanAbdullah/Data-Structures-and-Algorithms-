#ifndef BST_long_H
#define BST_long_H

// Auto-generated header file for a bst of long
// values.  This bst has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct bst_long_implementation bst_long;

bst_long * new_bst_long();
int  bst_long_isempty(bst_long *t);
int  bst_long_isfull(bst_long *t);
int  bst_long_size(bst_long *t);
int  bst_long_depth(bst_long *t);
void bst_long_insert(bst_long *t, long x);
void bst_long_delete(bst_long *t, long x);
int  bst_long_contains(bst_long *t, long x);
void bst_long_preorder_print(bst_long *t, void (* item_print)(long item));
void bst_long_inorder_print(bst_long *t, void (* item_print)(long item));
void bst_long_postorder_print(bst_long *t, void (* item_print)(long item));
void bst_long_simple_print(bst_long *t, void (* item_print)(long item));

void bst_long_release(bst_long *t);
#endif

#ifndef BST_double_H
#define BST_double_H

// Auto-generated header file for a bst of double
// values.  This bst has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct bst_double_implementation bst_double;

bst_double * new_bst_double();
int  bst_double_isempty(bst_double *t);
int  bst_double_isfull(bst_double *t);
int  bst_double_size(bst_double *t);
int  bst_double_depth(bst_double *t);
void bst_double_insert(bst_double *t, double x);
void bst_double_delete(bst_double *t, double x);
int  bst_double_contains(bst_double *t, double x);
void bst_double_preorder_print(bst_double *t, void (* item_print)(double item));
void bst_double_inorder_print(bst_double *t, void (* item_print)(double item));
void bst_double_postorder_print(bst_double *t, void (* item_print)(double item));
void bst_double_simple_print(bst_double *t, void (* item_print)(double item));

void bst_double_release(bst_double *t);
#endif

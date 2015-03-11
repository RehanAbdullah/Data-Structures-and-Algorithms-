#ifndef BST_float_H
#define BST_float_H

// Auto-generated header file for a bst of float
// values.  This bst has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct bst_float_implementation bst_float;

bst_float * new_bst_float();
int  bst_float_isempty(bst_float *t);
int  bst_float_isfull(bst_float *t);
int  bst_float_size(bst_float *t);
int  bst_float_depth(bst_float *t);
void bst_float_insert(bst_float *t, float x);
void bst_float_delete(bst_float *t, float x);
int  bst_float_contains(bst_float *t, float x);
void bst_float_preorder_print(bst_float *t, void (* item_print)(float item));
void bst_float_inorder_print(bst_float *t, void (* item_print)(float item));
void bst_float_postorder_print(bst_float *t, void (* item_print)(float item));
void bst_float_simple_print(bst_float *t, void (* item_print)(float item));

void bst_float_release(bst_float *t);
#endif

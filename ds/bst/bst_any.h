#ifndef BST_any_H
#define BST_any_H

// Auto-generated header file for a bst of any
// values.  This bst has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct bst_any_implementation bst_any;
#include "any.h"
typedef int (*rel_fun)(any a, any b);

bst_any * new_bst_any(rel_fun lt);
int  bst_any_isempty(bst_any *t);
int  bst_any_isfull(bst_any *t);
int  bst_any_size(bst_any *t);
int  bst_any_depth(bst_any *t);
void bst_any_insert(bst_any *t, any x);
void bst_any_delete(bst_any *t, any x);
int  bst_any_contains(bst_any *t, any x);
void bst_any_preorder_print(bst_any *t, void (* item_print)(any item));
void bst_any_inorder_print(bst_any *t, void (* item_print)(any item));
void bst_any_postorder_print(bst_any *t, void (* item_print)(any item));
void bst_any_simple_print(bst_any *t, void (* item_print)(any item));

void bst_any_release(bst_any *t);
#endif

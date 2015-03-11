#ifndef BST_short_H
#define BST_short_H

// Auto-generated header file for a bst of short
// values.  This bst has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

typedef struct bst_short_implementation bst_short;

bst_short * new_bst_short();
int  bst_short_isempty(bst_short *t);
int  bst_short_isfull(bst_short *t);
int  bst_short_size(bst_short *t);
int  bst_short_depth(bst_short *t);
void bst_short_insert(bst_short *t, short x);
void bst_short_delete(bst_short *t, short x);
int  bst_short_contains(bst_short *t, short x);
void bst_short_preorder_print(bst_short *t, void (* item_print)(short item));
void bst_short_inorder_print(bst_short *t, void (* item_print)(short item));
void bst_short_postorder_print(bst_short *t, void (* item_print)(short item));
void bst_short_simple_print(bst_short *t, void (* item_print)(short item));

void bst_short_release(bst_short *t);
#endif

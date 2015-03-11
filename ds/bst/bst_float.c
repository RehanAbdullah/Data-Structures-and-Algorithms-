// Auto-generated impl. file for a bst of float
// values.  This bst has no exception handling but
// prints a message on stdout and calls exit(1).
// Author: drs.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bst_float.h"

struct node
{
    float item;
    struct node * left;
    struct node * right;
};

struct bst_float_implementation
{
    struct node * root;
    int size;
};

bst_float * new_bst_float()
{
    bst_float * t = (bst_float*)malloc(sizeof(bst_float));
    t->root = NULL;
    t->size = 0;
    return t;
}

#define LT(A,B)   A < B

int  bst_float_isempty(bst_float *t)
{
    assert(t!=NULL);
    return (t->size == 0);
}
    
int  bst_float_isfull(bst_float *t)
{
    return 0;
}
    
int  bst_float_size(bst_float *t)
{
    assert(t!=NULL);
    return t->size;
}
    
int  get_depth(struct node *p)
{
    int l,r;
    if (p==NULL)
       return 0;
    else {
       l = 1 + get_depth(p->left);
       r = 1 + get_depth(p->right);
       return (l>r) ? l : r;
    }
}

int bst_float_depth(bst_float *t)
{
    assert(t!=NULL);
    return get_depth(t->root);
}

struct node * ins(bst_float *t, float x, struct node *p)
{
    if (p==NULL) {
        p = (struct node *)malloc(sizeof(struct node));
        if (p==NULL) {
            printf("bst_floatinsert (ins): failed to allocate memory\n");
            exit(1);
        }
        p->left = p->right = NULL;
        p->item = x;
        (t->size)++;
    }
    else if (LT(x,p->item))
        p->left = ins(t, x, p->left);
        
    else if (LT(p->item,x))
        p->right = ins(t, x, p->right);
        
    return p;
}       

void bst_float_insert(bst_float *t, float x)
{
    assert(t!=NULL);
    t->root = ins(t, x, t->root);
}

struct node * findmin(struct node *p)
{
    if (p==NULL)
        printf("error: (bst_float) findmin: empty tree\n");
        
    else if (p->left == NULL)
        return p;
    
    else
        return findmin(p->left);
}

struct node * del(bst_float *t, float x, struct node *p)
{
    struct node * n;
    
    if (p == NULL)
        ;                                       // do nothing - data not in tree
        
    else if (LT(x,p->item)) 
        p->left = del(t, x, p->left);
        
    else if (LT(p->item,x))
        p->right = del(t, x, p->right);
    
    else if (p->left!=NULL && p->right!=NULL) { // found and has two children
        n = findmin(p->right);                  // get smallest in right tree
        p->item = n->item;                      // overwrite the item to be deleted
        p->right = del(t, p->item, p->right);   // del the duplicate item in right tree
    }
    
    else {                                      // found and has at most one child
        n = p;
        if(p->left == NULL)
            p = p->right;                       // promote the right tree
            
        else if (p->right == NULL)              // or...
            p = p->left;                        // promote the left tree

        (t->size)--;                            // reduce the count
        free(n);                                // reclaim memory
    }
    return p;
}

void bst_float_delete(bst_float *t, float x)
{
    assert(t!=NULL);
    t->root = del(t, x, t->root);
}

int isin(bst_float *t, float x, struct node *p)
{
    if (p==NULL)
        return 0;
        
    else if (LT(x,p->item))
        return isin(t, x, p->left);
        
    else if (LT(p->item,x))
        return isin(t, x, p->right);
        
    else 
        return 1;
}

int bst_float_contains(bst_float *t, float x)
{
    assert(t!=NULL);
    return isin(t,x,t->root);
}

void preorder(struct node *p, void (* item_print)(float item))
{
    if (p!=NULL) {
        item_print(p->item);
        preorder(p->left,item_print);
        preorder(p->right,item_print);
    }
}
void inorder(struct node *p, void (* item_print)(float item))
{
    if (p!=NULL) {
        inorder(p->left,item_print);
        item_print(p->item);
        inorder(p->right,item_print);
    }
}
void postorder(struct node *p, void (* item_print)(float item))
{
    if (p!=NULL) {
        postorder(p->left,item_print);
        postorder(p->right,item_print);
        item_print(p->item);
    }
}

void bst_float_preorder_print(bst_float *t, void (* item_print)(float item))
{
    assert(t!=NULL);
    preorder(t->root, item_print);
}

void bst_float_inorder_print(bst_float *t, void (* item_print)(float item))
{
    assert(t!=NULL);
    inorder(t->root, item_print);
}

void bst_float_postorder_print(bst_float *t, void (* item_print)(float item))
{
    assert(t!=NULL);
    postorder(t->root, item_print);
}

void simple_print(struct node *p, int ind, void (* item_print)(float item))
{
    int i;
    
    if (p!=NULL) {
        simple_print(p->right,ind+4,item_print);
        for(i=0;i<ind;i++) putchar(' ');
        item_print(p->item);
        printf(" .... %p", p);
        putchar('\n');
        simple_print(p->left,ind+4,item_print);
    }
    else {
       for(i=0;i<ind;i++) putchar(' ');
       printf("%p\n", p);
    }
}

void bst_float_simple_print(bst_float *t, void (* item_print)(float item))
{
    assert(t!=NULL);
    simple_print(t->root,0,item_print);
}

void bst_float_release(bst_float *t)
{
    assert(t!=NULL);
    free(t);
}

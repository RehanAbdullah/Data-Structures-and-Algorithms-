# Shell script to generate a bst implementation file
# Author: drs
# Usage: ./linked_bst.sh int
#        creates an int bst implementation file:  linked_bst_int.c

item=$1
bst=bst_${item}
target=${bst}.c

echo "// Auto-generated impl. file for a bst of ${item}"   > ${target}
echo "// values.  This bst has no exception handling but" >> ${target}
echo "// prints a message on stdout and calls exit(1)."   >> ${target} 
echo "// Author: drs."                                    >> ${target} 

cat << EOI >>${target}

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "${bst}.h"

struct node
{
    ${item} item;
    struct node * left;
    struct node * right;
};

struct ${bst}_implementation
{
    struct node * root;
    int size;
EOI

if [ "$item" = "any" ]; then  
    echo "    rel_fun lt;"                                       >> ${target}
    echo "};"                                                    >> ${target}
    echo                                                         >> ${target}
    echo "${bst} * new_${bst}(rel_fun lt)"                       >> ${target}
    echo "{"                                                     >> ${target}
    echo "    ${bst} * t = (${bst}*)malloc(sizeof(${bst}));"     >> ${target}
    echo "    t->root = NULL;"                                   >> ${target}
    echo "    t->size = 0;"                                      >> ${target}
    echo "    t->lt = lt;"                                       >> ${target}
    echo "    return t;"                                         >> ${target}
    echo "}"                                                     >> ${target}
    echo                                                         >> ${target}
    echo "#define LT(A,B) t->lt(A,B)"                            >> ${target}
    echo                                                         >> ${target}
else                                                
    echo "};"                                                    >> ${target}
    echo                                                         >> ${target}
    echo "${bst} * new_${bst}()"                                 >> ${target}
    echo "{"                                                     >> ${target}
    echo "    ${bst} * t = (${bst}*)malloc(sizeof(${bst}));"     >> ${target}
    echo "    t->root = NULL;"                                   >> ${target} 
    echo "    t->size = 0;"                                      >> ${target}
    echo "    return t;"                                         >> ${target}
    echo "}"                                                     >> ${target}
    echo                                                         >> ${target}
    echo "#define LT(A,B)   A < B"                               >> ${target}
    echo                                                         >> ${target}
fi                                                                               


cat << EOI >>${target}
int  ${bst}_isempty(${bst} *t)
{
    assert(t!=NULL);
    return (t->size == 0);
}
    
int  ${bst}_isfull(${bst} *t)
{
    return 0;
}
    
int  ${bst}_size(${bst} *t)
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

int ${bst}_depth(${bst} *t)
{
    assert(t!=NULL);
    return get_depth(t->root);
}

struct node * ins(${bst} *t, ${item} x, struct node *p)
{
    if (p==NULL) {
        p = (struct node *)malloc(sizeof(struct node));
        if (p==NULL) {
            printf("${bst}insert (ins): failed to allocate memory\n");
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

void ${bst}_insert(${bst} *t, ${item} x)
{
    assert(t!=NULL);
    t->root = ins(t, x, t->root);
}

struct node * findmin(struct node *p)
{
    if (p==NULL)
        printf("error: ($bst) findmin: empty tree\n");
        
    else if (p->left == NULL)
        return p;
    
    else
        return findmin(p->left);
}

struct node * del(${bst} *t, ${item} x, struct node *p)
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

void ${bst}_delete(${bst} *t, ${item} x)
{
    assert(t!=NULL);
    t->root = del(t, x, t->root);
}

int isin(${bst} *t, ${item} x, struct node *p)
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

int ${bst}_contains(${bst} *t, ${item} x)
{
    assert(t!=NULL);
    return isin(t,x,t->root);
}

void preorder(struct node *p, void (* item_print)(${item} item))
{
    if (p!=NULL) {
        item_print(p->item);
        preorder(p->left,item_print);
        preorder(p->right,item_print);
    }
}
void inorder(struct node *p, void (* item_print)(${item} item))
{
    if (p!=NULL) {
        inorder(p->left,item_print);
        item_print(p->item);
        inorder(p->right,item_print);
    }
}
void postorder(struct node *p, void (* item_print)(${item} item))
{
    if (p!=NULL) {
        postorder(p->left,item_print);
        postorder(p->right,item_print);
        item_print(p->item);
    }
}

void ${bst}_preorder_print(${bst} *t, void (* item_print)(${item} item))
{
    assert(t!=NULL);
    preorder(t->root, item_print);
}

void ${bst}_inorder_print(${bst} *t, void (* item_print)(${item} item))
{
    assert(t!=NULL);
    inorder(t->root, item_print);
}

void ${bst}_postorder_print(${bst} *t, void (* item_print)(${item} item))
{
    assert(t!=NULL);
    postorder(t->root, item_print);
}

void simple_print(struct node *p, int ind, void (* item_print)(${item} item))
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

void ${bst}_simple_print(${bst} *t, void (* item_print)(${item} item))
{
    assert(t!=NULL);
    simple_print(t->root,0,item_print);
}

void ${bst}_release(${bst} *t)
{
    assert(t!=NULL);
    free(t);
}
EOI

if [ "$item" = "char" ]; then
cat << EOI >>${target}

int tabwidth(int bot_up_level)
{
    return (int)pow(2,bot_up_level+1) - 1;
}

int indent(int bot_up_level)
{
    return tabwidth(bot_up_level) / 2;
}

int maxwidth(int bot_up_level, int depth)
{
    int tab = tabwidth(bot_up_level);
    int ind = indent(bot_up_level);
    int maxnodes = (int)pow(2,(depth - bot_up_level) );
    return (maxnodes *(tab + 1)) - ind - 1;
}

void populate(char * arraytree, int size, int index, struct node* p)
{
    if (p==NULL) {
       if (index < size)
          arraytree[index] = ' ';
    }
    else {
       arraytree[index] = p->item;
       populate(arraytree, size, index*2,   p->left);
       populate(arraytree, size, index*2+1, p->right);
    }
}

void spaces(int i)
{
    while (i>0) {
       printf(" ");
       i--;
    }
}

void putchars(int i, char c)
{
    while (i>0) {
       putchar(c);
       i--;
    }
}

void ${bst}_pretty_print(${bst} *t)
{
    char * arraytree;
    int k,r,n;
    int tab, ind;
    int space;
    int depth    = ${bst}_depth(t);
    int maxnodes = (int)pow(2,depth) - 1;
    int pictrows = depth * 2 - 1;
    
    arraytree = (char*)malloc((maxnodes+1) * sizeof(char));
    
    for (k=0; k<=maxnodes; k++)
        arraytree[k] = ' ';
      
    populate(arraytree, maxnodes+1, 1, t->root);
    
    k = 1;                   // index to the root of the tree within arraytree
    r = pictrows - 1;        // root level of the picture
    printf("BST {\n");
    while (r >=0) {
       int tab = tabwidth(r/2+1);
       int ind = indent(r/2+1);

       if (r % 2 == 0) {     // if r is an even row number then we are printing data...
          spaces(ind);
          for(n=k; n<2*k-1; n++) {
             putchar(arraytree[n]);
             spaces(tab);
          }
          putchar(arraytree[n]);  
          putchar('\n');
          k = k*2;                                // move index to left subtree
       }
       else {                // if r is an odd row number then we are drawing lines...
          spaces(ind);
          for(n=k; n<2*k; n++) {
             if ( n%2 == 0 ) {                    // must be a left node
                if (arraytree[n] == ' ')          // node is empty
                   spaces(tab/2+1);
                else {                            // node is not empty
                   putchar('.');
                   putchars(tab/2,'-');
                }
                if (arraytree[n] == ' ' && arraytree[n+1] == ' ')
                    putchar(' ');
                else
                    putchar('^');
                }
             else {                               // must be a right node
                if (arraytree[n] == ' ')          // node is empty
                   spaces(tab/2+1);
                else {                            // node is not empty
                   putchars(tab/2,'-');
                   putchar('.');
                }
             
                if (n == 2*k - 1)                 // only if we are at the end of the row...
                   putchar('\n');
                else                              // otherwise fill in the blanks
                     spaces(tab);
             }
          }
       }
       r--;                                       // move down to next row of picture
    }
    printf("}\n");
    free(arraytree);
}
EOI
else
  echo
fi


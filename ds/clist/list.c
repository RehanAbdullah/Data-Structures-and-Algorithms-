// Linked implementation of a circular list with a sentinel node
// Author: drs

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

struct node
{
    any item;
    struct node * next;
    struct node * prev;
};

struct list_implementation
{
    struct node * sentinel;
    struct node * cursor;
    int size;
    compare compare_item;
};

list * new_list(compare compare_item)
{
    list * c = (list *)malloc(sizeof(list));
    if (c==NULL) {
        printf("new_list: malloc failure.\n");
        exit(1);
    }
    c->size = 0;
    c->sentinel = (struct node *) malloc(sizeof(struct node));
    if (c->sentinel==NULL) {
        printf("new_list(sentinel): malloc failure.\n");
        exit(1);
    }
    c->sentinel->item = NULL;
    c->sentinel->next = c->sentinel;
    c->sentinel->prev = c->sentinel;
    c->cursor = c->sentinel;
    c->compare_item = compare_item;
    return c;
}
 
int list_size(list *c)
{
    assert(c!=NULL);
    return c->size;
}
 
int list_isempty(list *c)
{
    assert(c!=NULL);
    return c->size == 0;
}

void list_goto_head(list *c)
{
    assert(c!=NULL);
    c->cursor = c->sentinel->next;
}

void list_goto_last(list *c)
{
    assert(c!=NULL);
    c->cursor = c->sentinel->prev;
}

void list_goto_next(list *c)
{
    assert(c!=NULL);
    c->cursor = c->cursor->next;
}

void list_goto_prev(list *c)
{
    assert(c!=NULL);
    c->cursor = c->cursor->prev;
}

int list_cursor_inlist(list *c)
{
    assert(c!=NULL);
    return c->cursor != c->sentinel;
}

any list_get_item(list *c)
{
    assert(c!=NULL);
    return (list_cursor_inlist(c)) ? c->cursor->item : NULL;
}

void list_ins_before(list *c, any  item)
{
    assert(c!=NULL);
    struct node * n = (struct node *) malloc(sizeof(struct node));
    if (n==NULL) {
        printf("list_ins_before: malloc failure.\n");
        exit(1);
    }
    n->item = item;
    n->next = c->cursor;
    n->prev = c->cursor->prev;
    c->cursor->prev->next = n;
    c->cursor->prev = n;
    c->size++;
}

void list_ins_after(list *c, any  item)
{
    assert(c!=NULL);
    struct node * n = (struct node *) malloc(sizeof(struct node));
    if (n==NULL) {
        printf("list_ins_after: malloc failure.\n");
        exit(1);
    }
    n->item = item;
    n->prev = c->cursor;
    n->next = c->cursor->next;
    c->cursor->next->prev = n;
    c->cursor->next = n;
    c->size++;
}

any list_delete(list *c)
{
    any t;
    assert(c!=NULL);
    struct node * p = c->cursor;
    if (list_cursor_inlist(c))
    {
        t = c->cursor->item;
        c->cursor = c->cursor->next;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
        c->size--;
        return t;
    }
    else
        return NULL;
}

void list_iterate(list *c, modify f)
{
    assert(c!=NULL);
    struct node * n = c->cursor;
    list_goto_head(c);
    while (list_cursor_inlist(c))
    {
        f(c->cursor->item);
        list_goto_next(c);
    }
    c->cursor = n;
}

int list_locate_item(list *c, any item) // from current cursor position
{
    assert(c!=NULL);
    while (list_cursor_inlist(c) && (c->compare_item(c->cursor->item,item) != 0))
        list_goto_next(c);
    return list_cursor_inlist(c);    
}

int list_filter(list *c, pred p) // from current cursor position
{
    assert(c!=NULL);
    while (list_cursor_inlist(c) && (!p(c->cursor->item)))
        list_goto_next(c);
    return list_cursor_inlist(c);    
}

list * list_deep_copy(list * c, any (* data_copy) (any d))
{   
    list * clone = new_list(c->compare_item);
    struct node * p = c->sentinel->next;
    while (p != c->sentinel)
    {
        list_ins_after(clone, data_copy(p->item));
        p = p->next;
    }
    return clone;
}

void list_print(list *c, void (* item_print)(any item))
{
    assert(c!=NULL);
    struct node * n = c->cursor;
    printf("CL[");
    list_goto_head(c);
    if (list_cursor_inlist(c)) {
        item_print(c->cursor->item);
        list_goto_next(c);
        while (list_cursor_inlist(c)) {
            printf(", ");
            item_print(c->cursor->item);
            list_goto_next(c);
        }
    }
    printf("]");
    c->cursor = n;
}

void list_print2(list *c, void (* item_print)(any item)) // alt printer
{
    assert(c!=NULL);
    printf("CL[");
    list_iterate( c, item_print);
    printf("]");
}

void list_release(list *c)
{
    assert(c!=NULL);
    free(c->sentinel);
    free(c);
}


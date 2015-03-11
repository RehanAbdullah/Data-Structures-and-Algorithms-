// A set implementation using a list
// Author: drs

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "set.h"

struct set_implementation
{
    list *     items;
    printer    print_item;
    compare    compare_item;
};

set * new_set(printer print_item, compare compare_item)
{
    set * s = (set *) malloc (sizeof(set));
    assert (s!=NULL);
    s->items = new_list(compare_item);
    s->print_item = print_item;
    s->compare_item = compare_item;
    return s;
}

int set_isempty(set *s)
{
    assert(s!=NULL);
    return list_isempty(s->items);
}

int set_isSubset(set *s, set * t)
{
    assert(s!=NULL);
    list_goto_head(s->items);
    while (list_cursor_inlist(s->items))
        if (!set_isin(t,list_get_item(s->items)))
            return 0; // if not in t then not a subset
        else
            list_goto_next(s->items);
    return set_count(s) < set_count(t); // all in t, but check t is larger than s
}

int set_isEqualTo(set *s, set * t)
{
    assert(s!=NULL);
    return set_isSubsetEq(s,t) && set_isSubsetEq(t,s);
}

int set_isSubsetEq(set *s, set * t)
{
    assert(s!=NULL);
    list_goto_head(s->items);
    while (list_cursor_inlist(s->items))
        if (!set_isin(t,list_get_item(s->items)))
            return 0; // if not in t then not a subset
        else
            list_goto_next(s->items);
    return 1;
}

int set_count(set *s)
{
    assert(s!=NULL);
    return list_size(s->items);
}

int set_isin(set *s, any x)
{
    assert(s!=NULL);
    list_goto_head(s->items);
    return list_locate_item(s->items, x);
}

void set_insertInto(set *s, any x)      // s = s u {x}
{
    assert(s!=NULL);
    list_goto_head(s->items);
    if (!list_locate_item(s->items, x))
        list_ins_before(s->items,x);
}

void set_removeFrom(set *s, any x)      // s = s \ {x}
{
    assert(s!=NULL);
    list_goto_head(s->items);
    if (list_locate_item(s->items, x))
        list_delete(s->items);
}

any set_choose_item(set *s) // for some x: s = s \ {x}
{
    any x;
    assert(s!=NULL);
    list_goto_head(s->items);
    if (list_cursor_inlist(s->items))
    {
        x = list_get_item(s->items);
        list_delete(s->items);
        return x;
    }
}

void set_intersectWith(set *s, set * t) // s = s n t    t is unchanged
{
    assert(s!=NULL);
    list_goto_head(s->items);
    while(list_cursor_inlist(s->items))
    {
        if (!set_isin(t,list_get_item(s->items)))
            list_delete(s->items);
        else
            list_goto_next(s->items);
    }
}

void set_unionWith(set *s, set * t)     // s = s u t    t is unchanged
{
    assert(s!=NULL);
    list_goto_head(t->items);
    while(list_cursor_inlist(t->items))
    {
        set_insertInto(s,list_get_item(t->items));
        list_goto_next(t->items);
    }
}

void set_minusWith(set *s, set * t)     // s = s \ t    t is unchanged
{
    assert(s!=NULL);
    list_goto_head(t->items);
    while(list_cursor_inlist(t->items))
    {
        set_removeFrom(s,list_get_item(t->items));
        list_goto_next(t->items);
    }
}

void set_print(set *s)
{
    assert(s!=NULL);
    printf("{");
    list_goto_head(s->items);
    if (list_cursor_inlist(s->items)) {
        s->print_item(list_get_item(s->items));
        list_goto_next(s->items);
        while (list_cursor_inlist(s->items)) {
            printf(", ");
            s->print_item(list_get_item(s->items));
            list_goto_next(s->items);
        }
    }
    printf("}");
}

void set_release(set *s)
{
    assert(s!=NULL);
    assert(list_isempty(s->items));
    list_release(s->items);
    free(s);
}

int compare_set(any s, any t)
{
    if (set_isEqualTo((set*)s,(set*)t))
        return 0;
    else if (set_isSubset((set*)s,(set*)t))
        return -1;
    else
        return 1;
}

void print_set(any s)
{
    set_print((set*)s);
}


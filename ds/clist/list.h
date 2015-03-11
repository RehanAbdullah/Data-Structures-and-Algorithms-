// Linked implementation of a circular list with a sentinel node
// Author: drs

#ifndef LIST_H
#define LIST_H

#include "any.h"

typedef struct list_implementation list;
typedef void (*modify)(any a);
typedef int (*pred)(any a);
typedef int  (*compare)(any x, any y);  // x==y->0; x<y -> -1; x>y -> 1
         
list *  new_list           (compare compare_item);
int     list_size          (list *c);
int     list_isempty       (list *c);
void    list_goto_head     (list *c);
void    list_goto_last     (list *c);
void    list_goto_next     (list *c);
void    list_goto_prev     (list *c);
int     list_cursor_inlist (list *c);
any     list_get_item      (list *c);
void    list_ins_before    (list *c, any  item);
void    list_ins_after     (list *c, any  item);
any     list_delete        (list *c);
void    list_iterate       (list *c, modify f);
int     list_locate_item   (list *c, any item); // from current cursor position
int     list_filter        (list *c, pred p);   // from current cursor position
list *  list_deep_copy     (list * c, any (* data_copy) (any d));
void    list_print         (list *c, void (* item_print)(any item));
void    list_print2        (list *c, void (* item_print)(any item)); // alt printer
void    list_release       (list *c);

#endif


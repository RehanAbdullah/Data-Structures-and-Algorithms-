// A set data structure
// Author: drs

#ifndef SET_H
#define SET_H

#include "any.h"

typedef struct set_implementation set;
typedef void (*printer)(any x);        // outputs item x on stdout

#ifndef LIST_H
typedef int  (*compare)(any x, any y); // x==y->0; x<y -> -1; x>y -> 1
#endif

set* new_set           (printer print_item, compare compare_item);
int  set_isempty       (set *s);
int  set_isSubset      (set *s, set * t);
int  set_isEqualTo     (set *s, set * t);
int  set_isSubsetEq    (set *s, set * t);
int  set_count         (set *s);
int  set_isin          (set *s, any x);
void set_insertInto    (set *s, any x);     // s = s u {x}
void set_removeFrom    (set *s, any x);     // s = s \ {x}
any  set_choose_item   (set *s);// for some x: s = s \ {x}
void set_intersectWith (set *s, set * t);   // s = s n t    t is unchanged
void set_unionWith     (set *s, set * t);   // s = s u t    t is unchanged
void set_minusWith     (set *s, set * t);   // s = s \ t    t is unchanged
void set_print         (set *s);
void set_release       (set *s);

int  compare_set       (any s, any t);      // in case of creating sets of sets
void print_set         (any s);             // these cover functions please the typechecker

#endif


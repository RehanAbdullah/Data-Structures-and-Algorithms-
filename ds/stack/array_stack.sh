# Shell script to generate a stack implementation file
# Author: drs
# Usage: ./array_stack.sh int
#        creates an int stack implementation file:  array_stack_int.c

item=$1
stack=stack_${item}
target=array_${stack}.c

echo "// Auto-generated impl. file for a stack of ${item}"   > ${target}
echo "// values.  This stack has no exception handling but" >> ${target}
echo "// prints a message on stdout and calls exit(1)."     >> ${target} 
echo "// Author: drs."                                      >> ${target} 

cat << EOI >>${target}

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "${stack}.h"

struct ${stack}_implementation
{
    ${item} * items;
    int top;
    int max;
};

${stack} * new_bounded_${stack}(int max)
{
    ${stack} * s = (${stack}*)malloc(sizeof(${stack}));
    s->items = (${item}*)malloc(max * sizeof(${item}));
    s->top = 0;
    s->max = max;
    return s;
}

${stack} * new_unbounded_${stack}()
{
    printf("new_unbounded_${stack} error: not available for array implementation\n");
    exit(1);
}

int ${stack}_isempty(${stack} *s)
{
    assert(s!=NULL);
    return (s->top == 0);
}
    
int ${stack}_isfull(${stack} *s)
{
    assert(s!=NULL);
    return (s->top == s->max);
}
    
int ${stack}_size(${stack} *s)
{
    assert(s!=NULL);
    return s->top;
}

void ${stack}_push(${stack} *s, ${item} x)
{
    assert(s!=NULL);
    if (${stack}_isfull(s)) {
        printf("${stack}_push error: stack is full\n");
        exit(1);
    }
    else {
        s->items[s->top] = x;
        (s->top)++;
    }
}

${item} ${stack}_pop(${stack} *s)
{
    assert(s!=NULL);
    if (${stack}_isempty(s)) {
        printf("${stack}_pop error: stack is empty\n");
        exit(1);
    }
    else {
        (s->top)--;
        return (s->items[s->top]);
    }
}

${item} ${stack}_top(${stack} *s)
{
    assert(s!=NULL);
    if (${stack}_isempty(s)) {
        printf("${stack}_top error: stack is empty\n");
        exit(1);
    }
    else
        return (s->items[(s->top)-1]);
}

void ${stack}_print(${stack} *s, void (* item_print)(${item} item))
{
    assert(s!=NULL);
    int i=0;
    printf("STK<<[ ");
    if (!${stack}_isempty(s)) {
        while (i<((s->top)-1)) {
            item_print(s->items[i]);
            printf(", ");
            i++;
        }
        item_print(s->items[i]);
    }
    printf(" ]");
}

void ${stack}_release(${stack} *s)
{
    assert(s!=NULL);
    free(s);
}
EOI


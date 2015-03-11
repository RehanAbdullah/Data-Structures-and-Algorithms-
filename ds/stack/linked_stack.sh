# Shell script to generate a stack implementation file
# Author: drs
# Usage: ./linked_stack.sh int
#        creates an int stack implementation file:  linked_stack_int.c

item=$1
stack=stack_${item}
target=linked_${stack}.c

echo "// Auto-generated impl. file for a stack of ${item}"   > ${target}
echo "// values.  This stack has no exception handling but" >> ${target}
echo "// prints a message on stdout and calls exit(1)."     >> ${target} 
echo "// Author: drs."                                      >> ${target} 

cat << EOI >>${target}

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "${stack}.h"

struct node
{
    ${item} item;
    struct node * next;
};

struct ${stack}_implementation
{
    struct node * top;
    int size;
};

${stack} * new_bounded_${stack}(int max)
{
    printf("new_bounded_${stack} error: not available for linked implementation\n");
    exit(1);
}

${stack} * new_unbounded_${stack}()
{
    ${stack} * s = (${stack}*)malloc(sizeof(${stack}));
    s->top = NULL;
    s->size = 0;
    return s;
}

int ${stack}_isempty(${stack} *s)
{
    assert(s!=NULL);
    return (s->size == 0);
}
    
int ${stack}_isfull(${stack} *s)
{
    return 0;
}
    
int  ${stack}_size(${stack} *s)
{
    assert(s!=NULL);
    return s->size;
}

void ${stack}_push(${stack} *s, ${item} x)
{
    assert(s!=NULL);
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n==NULL) {
        printf("${stack}_push error: OS failed to allocate memory\n");
        exit(1);
    }
    else {
        n->item = x;
        n->next = s->top;
        s->top  = n;
        (s->size)++;
    }
}

${item} ${stack}_pop(${stack} *s)
{
    assert(s!=NULL);
    struct node * n;
    ${item} x;
    if (${stack}_isempty(s)) {
        printf("${stack}_pop error: stack is empty\n");
        exit(1);
    }
    else {
        n = s->top;
        x = n->item;
        s->top = s->top->next;
        free(n);
        (s->size)--;
        return x;
    }
}

${item}  ${stack}_top(${stack} *s)
{
    assert(s!=NULL);
    if (${stack}_isempty(s)) {
        printf("${stack}_top error: stack is empty\n");
        exit(1);
    }
    else
        return (s->top->item);
}

void ${stack}_print(${stack} *s, void (* item_print)(${item} item))
{
    assert(s!=NULL);
    struct node *p = s->top;
    printf("STK<<[ ");
    if (p!=NULL) {
        while (p->next!=NULL) {
            item_print(p->item);
            printf(", ");
            p = p->next;
        }
        item_print(p->item);
    }
    printf(" ]");    
}

void ${stack}_release(${stack} *s)
{
    assert(s!=NULL);
    free(s);
}
EOI


# Shell script to generate a queue implementation file
# Author: drs
# Usage: ./linked_queue.sh int
#        creates an int queue implementation file:  linked_queue_int.c

item=$1
queue=queue_${item}
target=linked_${queue}.c

echo "// Auto-generated impl. file for a queue of ${item}"   > ${target}
echo "// values.  This queue has no exception handling but" >> ${target}
echo "// prints a message on stdout and calls exit(1)."     >> ${target} 
echo "// Author: drs."                                      >> ${target} 

cat << EOI >>${target}

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "${queue}.h"

struct node
{
    ${item} item;
    struct node * next;
};

struct ${queue}_implementation
{
    struct node * front;
    struct node * back;
    int size;
};

${queue} * new_bounded_${queue}(int max)
{
    printf("new_bounded_${queue} error: not available for linked implementation\n");
    exit(1);
}

${queue} * new_unbounded_${queue}()
{
    ${queue} * q = (${queue}*)malloc(sizeof(${queue}));
    q->front = NULL;
    q->back = NULL;
    q->size = 0;
    return q;
}

int ${queue}_isempty(${queue} *q)
{
    assert(q!=NULL);
    return (q->size == 0);
}
    
int ${queue}_isfull(${queue} *q)
{
    assert(q!=NULL);
    return 0;
}
    
int ${queue}_size(${queue} *q)
{
    assert(q!=NULL);
    return q->size;
}

void ${queue}_enqueue(${queue} *q, ${item} x)
{
    assert(q!=NULL);
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n==NULL) {
        printf("${queue}_enqueue error: OS failed to allocate memory\n");
        exit(1);
    }
    else {
        n->item = x;
        n->next = NULL;
        if (q->back==NULL) {
            q->front = n;
            q->back = n;
        }
        else {
            q->back->next = n;
            q->back = n;
        }
        (q->size)++;
    }
}

${item} ${queue}_dequeue(${queue} *q)
{
    assert(q!=NULL);
    struct node * n;
    ${item} x;
    if (${queue}_isempty(q)) {
        printf("${queue}_dequeue error: queue is empty\n");
        exit(1);
    }
    else {
        n = q->front;
        x = n->item;
        q->front = q->front->next;
        if (q->front == NULL) q->back = NULL;
        (q->size)--;
        free(n);
        return x;
    }
}

${item} ${queue}_front(${queue} *q)
{
    assert(q!=NULL);
    if (${queue}_isempty(q)) {
        printf("${queue}_front error: queue is empty\n");
        exit(1);
    }
    else
        return (q->front->item);
}

void ${queue}_print(${queue} *q, void (* item_print)(${item} item))
{
    assert(q!=NULL);
    struct node *p = q->front;
    printf("Q<<[ ");
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

void ${queue}_release(${queue} *q)
{
    assert(q!=NULL);
    free(q);
}
EOI


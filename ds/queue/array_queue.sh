# Shell script to generate a queue implementation file
# Author: drs
# Usage: ./array_queue.sh int
#        creates an int queue implementation file:  array_queue_int.c

item=$1
queue=queue_${item}
target=array_${queue}.c

echo "// Auto-generated impl. file for a queue of ${item}"   > ${target}
echo "// values.  This queue has no exception handling but" >> ${target}
echo "// prints a message on stdout and calls exit(1)."     >> ${target} 
echo "// Author: drs."                                      >> ${target} 

cat << EOI >>${target}

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "${queue}.h"

struct ${queue}_implementation
{
    ${item} * items;
    int front;
    int back;
    int size;
    int max;
};

${queue} * new_bounded_${queue}(int max)
{
    ${queue} * q = (${queue}*)malloc(sizeof(${queue}));
    q->items = (${item}*)malloc(max * sizeof(${item}));
    q->front = 0;
    q->back = 0;
    q->size = 0;
    q->max = max;
    return q;
}

${queue} * new_unbounded_${queue}()
{
    printf("new_unbounded_${queue} error: not available for array implementation\n");
    exit(1);
}

int ${queue}_isempty(${queue} *q)
{
    assert(q!=NULL);
    return (q->size == 0);
}
    
int ${queue}_isfull(${queue} *q)
{
    assert(q!=NULL);
    return (q->size == q->max);
}
    
int ${queue}_size(${queue} *q)
{
    assert(q!=NULL);
    return q->size;
}

void ${queue}_enqueue(${queue} *q, ${item} x)
{
    assert(q!=NULL);
    if (${queue}_isfull(q)) {
        printf("${queue}_enqueue error: queue is full\n");
        exit(1);
    }
    else {
        q->items[q->back] = x;
        q->back = (q->back + 1) % (q->max);
        (q->size)++;
    }
}

${item} ${queue}_dequeue(${queue} *q)
{
    assert(q!=NULL);
    ${item} x;
    if (${queue}_isempty(q)) {
        printf("${queue}_dequeue error: queue is empty\n");
        exit(1);
    }
    else {
        x = q->items[q->front];
        q->front = (q->front + 1) % (q->max);
        (q->size)--;
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
        return (q->items[q->front]);
}

void ${queue}_print(${queue} *q, void (* item_print)(${item} item))
{
    assert(q!=NULL);
    int i=0;
    int j=q->front;
    printf("Q<<[ ");
    if (!${queue}_isempty(q)) {
        while (i<(q->size - 1)) {
            item_print(q->items[j]);
            printf(", ");
            j = (j+1) % (q->max);
            i++;
        }
        item_print(q->items[j]);
    }
    printf(" ]");
}

void ${queue}_release(${queue} *q)
{
    assert(q!=NULL);
    free(q->items);
    free(q);
}
EOI


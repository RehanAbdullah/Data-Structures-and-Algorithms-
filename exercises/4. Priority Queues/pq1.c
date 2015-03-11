#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"

struct item
{
	int priority;
	char data[8];
};
void print_item(any i)
{
	printf("(%i,’%s’)",
		((struct item*)i)->priority,
		((struct item*)i)->data);
}
int le_item(any i, any j)
{
	printf( "HERE\n" );
	return ((struct item*)i)->data[0] <= ((struct item*)j)->data[0];
	//return ((struct item*)i)->priority >= ((struct item*)j)->priority;
}
int main(int argc, char **argv)
{
	pqueue *pq = new_bounded_pqueue(5,le_item);
	struct item *it;
	int i;
	for(i=0; i<5; i++) {
		it = (struct item*)malloc(sizeof(struct item));
 		pqueue_insert(pq,it);
		pqueue_print(pq,print_item);
		printf("\n\n");
	}
	for(i=0; i<5; i++) {
		pqueue_dequeue(pq);
		pqueue_print(pq,print_item);
		printf("\n\n");
	}
}

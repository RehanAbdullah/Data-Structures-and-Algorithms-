#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"

struct track
{
	char artist[20];
	char title[20];
	int rating;
};


void print_track(any i)
{
	printf("('%i','%s','%s')",
		((struct track*)i)->rating,
		((struct track*)i)->title,
		((struct track*)i)->artist);
	
}
int le_track(any i, any j)
{
	return ((struct track*)i)->rating <= ((struct track*)j)->rating;
}
int de_track(any i, any j)
{
	return ((struct track*)i)->rating > ((struct track*)j)->rating;
}

int ar_track(any i, any j)
{
	return ((struct track*)i)->artist[0] >= ((struct track*)j)->artist[0];
	
}


void is_dot(any i)
{
	if (((struct track*)i)->artist[0] == '.')
	{
		printf("\n\n\nYou have decided to leave the program!\n");
		return exit(1);
	}
	
}

int main(int argc, char **argv)
{
	int choice,i;
	char order;
	struct track *tr;
	pqueue *pf;
	
	while(1)
	{
		printf("Enter the choice of the order of the PQ\n");
		printf("1. Ascending order\n");
		printf("2. Descending order\n");
		printf("3. By artist \n");
		printf("Or enter . in artist to leave program \n");
		
		
		scanf("%d", &choice);
		
		switch(choice)
		{
			
		case 1:
			{	
				pf = new_bounded_pqueue(5,le_track);
				for(i=0; i<5; i++) {
					tr = (struct track*)malloc(sizeof(struct track));
					
					printf("Rating, Title and Artist?"); scanf("%i %s %s", &(tr->rating), tr->title, tr->artist);
					is_dot(tr->artist);
					pqueue_insert(pf,tr);
					pqueue_print(pf,print_track);
					printf("\n\n");
				}
				for(i=0; i<5; i++) {
					pqueue_dequeue(pf);
					pqueue_print(pf,print_track);
					printf("\n\n");
				}
			}
			break;
			
		case 2:
			{
				pf = new_bounded_pqueue(5,de_track);
				for(i=0; i<5; i++) {
					tr = (struct track*)malloc(sizeof(struct track));
					
					printf("Rating, Title and Artist?"); scanf("%i %s %s", &(tr->rating), tr->title, tr->artist);
					is_dot(tr->artist);
					pqueue_insert(pf,tr);
					pqueue_print(pf,print_track);
					printf("\n\n");
				}
				for(i=0; i<5; i++) {
					pqueue_dequeue(pf);
					pqueue_print(pf,print_track);
					printf("\n\n");
				}
			}
			break;
			
		case 3:
			{
				
				pf = new_bounded_pqueue(5,ar_track);
				for(i=0; i<5; i++) {
					tr = (struct track*)malloc(sizeof(struct track));
					
					printf("Rating, Title and Artist?"); scanf("%i %s %s", &(tr->rating), tr->title, tr->artist);
					is_dot(tr->artist);
					pqueue_insert(pf,tr);
					pqueue_print(pf,print_track);
					printf("\n\n");
				}
				for(i=0; i<5; i++) {
					pqueue_dequeue(pf);
					pqueue_print(pf,print_track);
					printf("\n\n");
				}
			}
			break;
			
		}
	}
}

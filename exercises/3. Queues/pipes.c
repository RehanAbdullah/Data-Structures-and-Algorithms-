#include <stdio.h>
#include <stdlib.h>
#include "queue_int.h"
#define RAND_NO_SEED 128475
#define MAX_BUFF_LEN 2
#define P1_SND 0
#define P2_RLY 1
#define P3_RCV 2
static int P1_suspended = 0;
static int P2_suspended = 0;
static int P3_suspended = 0;
int simulated_activity()
{
	int r = rand()%99;
	if (r < 33)
		return P1_SND;
	else if (r < 66)
		return P2_RLY;
	else
		return P3_RCV;
}
static int item = 1;
int next_item() { return item++; }
void printint(int i) { printf("%i",i); }
int main(int argc, char **argv)
{
	queue_int *buff_12 = new_unbounded_queue_int();
	queue_int *buff_23 = new_unbounded_queue_int();
	srand(RAND_NO_SEED);
	int a;
	while(1) {
		sleep(3);
		if (P1_suspended) printf("\nP1 suspended\n");
		else printf("\nP1 active\n");
		printf("buff_12: "); queue_int_print(buff_12,printint);
		
		if (P2_suspended) printf("\nP2 suspended\n");
		else printf("\nP2 active\n");
		printf("buff_23: "); queue_int_print(buff_23,printint);
		if (P3_suspended) printf("\nP3 suspended\n");
		else printf("\nP3 active\n");
		a = simulated_activity();
		printf("\n\nSimulated activity: ");
		if (a==P1_SND) printf("P1_SND\n");
		else if (a==P2_RLY) printf("P2_RLY\n");
		else if (a==P3_RCV) printf("P3_RCV\n");
		switch( a ) {
		case P1_SND:
			if (queue_int_isfull(buff_12))
				P1_suspended = 1;
			else {
				P1_suspended = 0;
				queue_int_enqueue(buff_12,next_item());
			}
			break;
		case P2_RLY:
			if (queue_int_isempty(buff_12) || queue_int_isfull(buff_23))
				P2_suspended = 1;
			else {
				P2_suspended = 0;
				queue_int_enqueue(buff_23, queue_int_dequeue(buff_12));
			}
			break;
		case P3_RCV:
			if (queue_int_isempty(buff_23))
				P3_suspended = 1;
			else {
				P3_suspended = 0;
				queue_int_dequeue(buff_23);
			}
			break;
		}
	}
}

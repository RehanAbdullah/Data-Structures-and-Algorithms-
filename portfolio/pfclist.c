/* Program: cl_demo1
* Function: Demonstrating the use of the clist data structure
* Author: drs
*/
#include <stdlib.h>
#include <stdio.h>
#include "any.h"
#include "clist.h"
#define MAX_INTS 100
#define NEWLINE printf("\n");
/*************************************************************************************
* Functions that operate on references to int values
************************************************************************************/
int even_int( any d ) // even(d) ?
{
	return ((*(int*)d) % 2) == 0;
}
void double_int( any d ) // d *= 2
{
	*(int *)d = *(int *)d * 2;
}
/*************************************************************************************
* Functions to display the contents of a list
************************************************************************************/
void show_int( any d )
{
	printf("%3i", *(int *)d);
}
void show_list(clist * cl, char * caption) {
	any d;
	printf("\nCAPTION: \"%s\"",caption);
	printf("\n clist_size: %3i", clist_size(cl));
	printf("\n clist_isempty: %3i", clist_isempty(cl));
	printf("\n clist_cursor_inlist: %3i", clist_cursor_inlist(cl));
	printf("\n item at cursor: ");
	d = clist_get_item(cl);
	if (d==NULL)
		printf(" NULL");
	else
		show_int( d );
	printf("\n clist_print: ");
	clist_print(cl, &show_int);
	NEWLINE
}

int main()
{
	clist *xs;
	any j;
	/*************************************************************************************
	* A pool of data values is needed to be placed into the list during various
	* test cases. A simple approach is to create an array of ints in which the
	* index is equal to the value. The required "pointer to an integer" can then
	* be obtained by using the address of a particular array element.
	* Be careful though: these are mutable objects (having reference semantics)
	* and each new test case should re-initialise the array to avoid previous
	* modifications affecting behaviour (e.g. as would happen with a call to the
	* iterate function).
	************************************************************************************/
	int i, d[MAX_INTS];
	for (i=0;i<MAX_INTS;i++) d[i]=i;
	xs = new_clist();
	show_list(xs, "Empty"); // print out the empty list
	NEWLINE
	clist_ins_before( xs, &d[1] );
	clist_ins_before( xs, &d[2] );
	clist_ins_before( xs, &d[3] );
	clist_ins_before( xs, &d[4] );
	show_list(xs, "Inserted four integers before cursor");
	NEWLINE
	clist_ins_after( xs, &d[5] );
	clist_ins_after( xs, &d[6] );
	clist_ins_after( xs, &d[7] );
	clist_ins_after( xs, &d[8] );
	show_list(xs, "Inserted four integers after cursor");
	NEWLINE
	
	//------------------------------------------------------------------
	//portfolio code
	printf("\nportfolio code");
	clist_goto_prev( xs );
	clist_goto_prev( xs );
	clist_goto_prev( xs );
	//clist_goto_last( xs );
	clist_backspace(xs);
	show_list(xs, "Go to the last and delete previous item");
	
	//-----------------------------------------------------------------
	
	clist_find( xs, even_int );
	clist_delete( xs );
	clist_find_next( xs, even_int );
	clist_delete( xs );
	clist_find_next( xs, even_int );
	clist_delete( xs );
	clist_find_next( xs, even_int );
	clist_delete( xs );
	show_list(xs, "Located and deleted the even numbers");
	NEWLINE
	clist_iterate( xs, double_int );
	show_list(xs, "Doubled all the numbers in the list");
	NEWLINE
	clist_goto_last( xs );
	
	
	clist_goto_prev( xs );
	printf("Deleting value %i\n", clist_delete( xs ));
	show_list(xs, "Deleted penultimate value in the list");
	NEWLINE
	clist_goto_head( xs );
	clist_delete( xs );
	clist_delete( xs );
	clist_delete( xs );
	show_list(xs, "Emptied the list");
	NEWLINE
	clist_release( xs );
	return 0;
}

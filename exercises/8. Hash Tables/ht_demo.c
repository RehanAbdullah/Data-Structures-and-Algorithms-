#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "any.h"
#include "ht.h"
#define TABLE_SIZE 49
#define NEWLINE printf("\n");
struct motorway {
	int number; // M????
	int length; // miles
};
int get_key(any m)
{
	assert (m != NULL);
	return ((struct motorway*)m)->number;
}
int hash(int key)
{
	return key % TABLE_SIZE;
}
struct motorway * create_mway(int no, int len)
{
	struct motorway * m;
	m = (struct motorway *) malloc(sizeof(struct motorway));
	m->number = no;
	m->length = len;
	return m;
}
int main()
{
	ht * table = new_ht(TABLE_SIZE, hash, get_key);
	struct motorway * m;
	ht_display(table,0,TABLE_SIZE-1);
	ht_insert(table,create_mway(1,193));
	ht_insert(table,create_mway(25,117));
	ht_insert(table,create_mway(8,60));
	ht_insert(table,create_mway(62,107));
	ht_insert(table,create_mway(69,16));
	ht_insert(table,create_mway(181,2));
	ht_insert(table,create_mway(74,40));
	ht_insert(table,create_mway(90,30));
	ht_insert(table,create_mway(77,20));
	ht_insert(table,create_mway(3,59));
	ht_insert(table,create_mway(275,2));
	ht_insert(table,create_mway(56,33));
	ht_insert(table,create_mway(606,3));
	ht_insert(table,create_mway(898,1));
	ht_insert(table,create_mway(40,89));
	ht_insert(table,create_mway(4,192));
	ht_insert(table,create_mway(6,232));
	ht_insert(table,create_mway(53,19));
	ht_insert(table,create_mway(55,11));
	ht_insert(table,create_mway(48,12));
	ht_display(table,0,TABLE_SIZE-1);
}

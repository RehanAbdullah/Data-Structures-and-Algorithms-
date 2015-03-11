#include <stdio.h>
#include "any.h"
#include "list.h"
#include "set.h"
void intprn(any x)
{
	printf("%li", (long)x);
}
int intcmp(any x, any y)
{
	if ((long)x < (long)y)
		return -1;
	else if ((long)x > (long)y)
		return 1;
	else
		return 0;
	
}
int main()
{
	set * s, *t, *u, *v;
	long i,j,k;
	s = new_set(intprn,intcmp);
	t = new_set(intprn,intcmp);
	u = new_set(intprn,intcmp);
	v = new_set(intprn,intcmp);
	for(i=1; i<=10; i++)
		set_insertInto(s,(any)i);
	for(i=5; i<=15; i++)
		set_insertInto(t,(any)i);
	set_unionWith(u,s);
	set_intersectWith(u,t);
	set_unionWith(v,u);
	set_unionWith(v,t);
	set_unionWith(v,s);
	set_unionWith(v,s);
	set_unionWith(v,s);
	printf("s = ");set_print(s);printf("\n");
	printf("t = ");set_print(t);printf("\n");
	printf("u = ");set_print(u);printf("\n");
	printf("v = ");set_print(u);printf("\n");
	while(!set_isempty(s))
	{
		i = (long)set_choose_item(s);
		printf("Selected %li, s = ",i);set_print(s);printf("\n");
	}
}


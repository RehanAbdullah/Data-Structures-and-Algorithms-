#include <stdio.h>
int main()
{
	int array[10] = {3,6,9,12,15,18,21,24,27,30};
	int *pa, temp = 0;
	pa = &array[0];
	
	printf("\n\n");
		*pa= temp;
		printf("temp = %10d \t\t *pa = %10d\t\t pa =%10p\n\n", temp, *pa, pa);

}


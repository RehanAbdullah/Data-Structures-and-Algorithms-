#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "ss_int.h"
#define DEFAULT_SIZE 100
#define LINEAR1 0
#define LINEAR2 1
#define BINARY1 2
/*
* Author: drs
* Version: 3.3
* arg1 = size of array
* arg2 = random number seed
*/
void printArray(int * a, int N)
{
	int i = 0;
	while (i < N)
	{
		if ( i % 10 == 0 ) printf("\n%7i ]", i);
		printf("%7i", a[i]);
		i++;
	}
	printf("\n");
}
main(int argc, char ** argv)
{
	int N; /* how many numbers */
	int modulo;
	int *values; /* where are they ? */
	int i; /* loop counter */
	clock_t t0, t1;
	int fun;
	int idx,key;
	char search_method[80];
	int (* search[3])(int *, int, int);
	search[LINEAR1] = &int_linearsearch;
	search[LINEAR2] = &int_linearsearchX;
	search[BINARY1] = &int_binarysearch;
	N = (argc > 1) ? atoi(argv[1]) : DEFAULT_SIZE;
	srand((argc > 2) ? atoi(argv[2]) : clock());
	modulo = (int)(pow(10, (floor(log10(N))+1)));
	printf("Generating %i random numbers modulo %i\n", N, modulo);
	
	values = (int*) malloc(sizeof(int)*(N+1));
	for(i=0; i<N; i++) values[i] = rand() % modulo;
	int_heapsort(values,N);
	printf("\nInitial values:\n");
	printArray(values, N);
	printf("Search for ? (-1 to quit, -2 to print table) \n");
	scanf(" %i", &key);
	while(key != -1) {
		if (key == -2)
			printArray(values, N);
		else {
			strcpy(search_method,"linear1");fun = LINEAR1;
			printf("Running %s search\n", search_method);
			t0 = clock(); idx = search[fun](values,key,N); t1 = clock();
			if(idx == -1)
			printf("Key %i NOT found (elapsed %9.3f thousandths sec.)\n\n",
				key, ((double) (t1 - t0)) / CLOCKS_PER_SEC * 1000);
			else
			printf("Key %i found at index %i (elapsed %9.3f thousandths sec.)\n\n",
				key, idx, ((double) (t1 - t0)) / CLOCKS_PER_SEC * 1000);
			strcpy(search_method,"linear2") ;fun = LINEAR2;
			printf("Running %s search\n", search_method);
			t0 = clock(); idx = search[fun](values,key,N); t1 = clock();
			if(idx == -1)
			printf("Key %i NOT found (elapsed %9.3f thousandths sec.)\n\n",
				key, ((double) (t1 - t0)) / CLOCKS_PER_SEC * 1000);
			else
			printf("Key %i found at index %i (elapsed %9.3f thousandths sec.)\n\n",
				key, idx, ((double) (t1 - t0)) / CLOCKS_PER_SEC * 1000);
			strcpy(search_method,"binary1") ;fun = BINARY1;
			printf("Running %s search\n", search_method);
			t0 = clock(); idx = search[fun](values,key,N); t1 = clock();
			if(idx == -1)
			printf("Key %i NOT found (elapsed %9.3f thousandths sec.)\n\n",
				key, ((double) (t1 - t0)) / CLOCKS_PER_SEC * 1000);
			else
			printf("Key %i found at index %i (elapsed %9.3f thousandths sec.)\n\n",
				key, idx, ((double) (t1 - t0)) / CLOCKS_PER_SEC * 1000);
		}
		printf("Search for ? (-1 to quit, -2 to print table) \n");
		scanf(" %i", &key);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define PRINT_ARR(p, start, end) \
do{ \
		typeof(p) tmp_xxx = &p[start];\
		int i = start;            \
		while ( i++ < end + 1){\
			printf("%d ", *tmp_xxx++);}\
		puts("\n");} while(0)


static int most = 0; /*mark the most bit*/

/**
 * s, the p length
 */
int radix_sort(int *p, int s) 
{
	static int bit = 1; /*store the current sort bit*/

	int *result = NULL;
	int *swap = NULL;
	int i = 0;
	int tmp = 0;

	result = malloc(sizeof(result) * s);
	swap = malloc(sizeof(swap) * 10); /*0~9 each bit*/

	memset(swap, 0, sizeof(swap) * 10);

	for(i = 0; i < s; i++){
		tmp = p[i] / bit % 10;
		swap[tmp] += 1;
		printf("tmp %d\n", tmp);
	}
	
	PRINT_ARR(swap, 0, 9);
	for(i = 1; i < 10; i++){
		swap[i] += swap[i-1];
	}

	PRINT_ARR(swap, 0, 9);
	for(i = 0; i < s; i++){
		tmp = swap[p[i] / bit % 10];

		if (tmp)
			most = 1;


		result[tmp - 1] = p[i];
		swap[p[i] / bit % 10] -= 1;
	}

	PRINT_ARR(result, 0, s - 1);

	bit *= 10;

	free(result);
	free(swap);
	return 0;
}

int radix(int *p, int s)
{
	int i = 3;
	while(i){
	printf("test\n");	
		radix_sort(p, s);
		i--;
	}
	return 0;
}

int main()
{
	int a[] = {101, 812, 204, 334, 110};
	radix(a, sizeof(a)/sizeof(a[0]));
	return 0;
}

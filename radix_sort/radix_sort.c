#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINT_ARR(p, start, end) \
	do{ \
		typeof(p) tmp = &p[start];\
		int i = start;            \
		while ( i++ < end + 1){\
			printf("%d ", *tmp++);}\
		puts("\n");} while(0)

void count_sort(int *a, int length, int order)
{
	int *c;
	int *b;
	int i = 0;
	int j = 0;

	b = malloc(sizeof(*b) * length);
	c = malloc(sizeof(*c) * 10);

	for (i = 0; i < 10; i++)
		c[i] = 0;

	for (i = 0; i < length; i++){
		j = (a[i]/order) % 10;
		c[j] = c[j] + 1;
	}

	PRINT_ARR(c, 0, 9);
	for (i = 1; i < 10; i++)
		c[i] = c[i-1] + c[i];

	PRINT_ARR(c, 0, 9);
	for (i = 0; i < length; i++){
		j = (a[i]/order) % 10;
		b[c[j] - 1] = a[i];
		c[j] -= 1;
	}

	
	for (i = 0; i < length; i++){
		a[i] = b[i];
	}


	PRINT_ARR(b, 0, length - 1);
}


void radix_sort(int *p, int length)
{
	int i = 0;
	int order = 1;
	while (i < 3){
		count_sort(p, length, order);
		order = order * 10;
		i++;
	}
	PRINT_ARR(p, 0, length - 1);
}

int main(){
	int a[] = { 731, 349, 407, 183, 944};
	radix_sort(a, sizeof(a)/sizeof(a[0]));

	return 0;
}









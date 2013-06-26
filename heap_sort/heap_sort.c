#include <stdio.h>
#include <stdlib.h>


#define PRINT_ARR(p, start, end) \
	do{ \
		typeof(p) tmp = &p[start];\
		int i = start;            \
		while ( i++ < end + 1){\
			printf("%d ", *tmp++);}\
		puts("\n");} while(0)

#define LEFT(x)  (2 * (x) + 1)
#define RIGHT(x) (2 * (x) + 2)
#define PARENT(x) ((x - 1)/2)


void max_heapify(int *p, int x, int length)
{
	int tmp = 0;

	int largest = x;

	if ((LEFT(x) < length) && (p[LEFT(x)] > p[largest])){
		largest = LEFT(x);
	}
	if ((RIGHT(x) < length) && (p[RIGHT(x)] > p[largest])){
		largest = RIGHT(x);
	}

	if (largest != x){
		tmp = p[x];
		p[x] = p[largest];
		p[largest] = tmp;
		max_heapify(p, largest, length);
	}
}

void build_max_heap(int *p, int length)
{
	int i = 0;

	for (i = length/2; i > -1; i--){
		max_heapify(p, i, length);
	}
}

void heap_sort(int *p, int length)
{
	int i = 0;
	int tmp = 0;
	for ( i = length - 1 ; i > 0; i--){
		tmp = p[i];
		p[i] = p[0];
		p[0] = tmp;
		length -= 1;
		max_heapify(p, 0, length);
	}
}
		
		

int main(){
	int a[] = {4, 5, 7, 8, 3, 2, 1};
	int *p = a;
	
	build_max_heap(p, sizeof(a)/sizeof(a[0]));
	PRINT_ARR(p, 0, sizeof(a)/sizeof(a[0]) - 1);

	heap_sort(p, sizeof(a)/sizeof(a[0]));
	PRINT_ARR(p, 0, sizeof(a)/sizeof(a[0]) - 1);
	return 0;
}

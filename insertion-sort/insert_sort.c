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
int insert_array(int *p, int end)
{
	int *tmp = &p[end - 1];
	int key = *(p + end);
	for (; end >= 0; end--){
		if (*tmp > key){
		*(tmp+1) = *tmp;
		tmp--;
		}
		*(tmp+1) = key;
	}
	return 0;
}

int insert_recursion(int *p, int end)
{
	if ( end > 0 ){
		insert_recursion(p, end - 1);
		insert_array(p, end);
	}
	return 0;
}

int main(){
	int end;
	int *p;
	int a[]={300, 200, 100, 89, 101, 301, 5};
	insert_recursion(a, sizeof(a)/sizeof(a[0]) - 1);
	end = sizeof(a)/sizeof(a[0]) - 1;
	p = a;
	PRINT_ARR(p, 0, end);
	return 0;
}


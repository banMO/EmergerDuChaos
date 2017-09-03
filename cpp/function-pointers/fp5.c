#include <stdlib.h>
#include <stdio.h>

int cmp_int(const void* a, const void* b)
{
	int x = *((int*) a);
	int y = *((int*) b);

	// if (x > y)
	// 	return 1;
	// if (x < y)
	// 	return -1;

	// return 0;
	return x - y;
}

int main()
{
	int n[] = {6, 9, 2, 0, 4};
	qsort(n, 5, sizeof(int), cmp_int);

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", n[i]);
	}
}
#include <stdio.h>

int div(int a, int b, int* c) {
	if (b == 0)
		return 0;

	*c = a/b;
	return 1;
}

int main()
{
	int x = 10;
	int y = 2;
	int r;

	int res = div(x, y, &r);

	if (!res)
		puts("Division entre 0");
	else
		printf("%d\n", r);

	return 0;
}
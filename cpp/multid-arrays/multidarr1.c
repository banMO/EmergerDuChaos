#include <stdio.h>

void print_a(int* p, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d ", *(p + (i * cols) + j));
		}
		puts("");
	}
}

int main()
{
	int s[2][2];

	s[0][0] = 2; 
	s[0][1] = 8; 
	s[1][0] = 2;

	int* m = (int*)s;
	*(m + (1 * 2) + 1) = 123;

	print_a(m, 2, 2);

	return 0;
}
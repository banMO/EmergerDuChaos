#include <stdio.h>

int f(int n, const char** s) {
	if (n < 0)
		return 0;

	if (n % 2)
		*s = "impar";
	else
		*s = "par";

	return 1;
}

int main()
{
	const char* q = "hola";
	int r = f(3, &q);
	if (r)
		puts(q);

	return 0;
}
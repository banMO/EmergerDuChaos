// libreria
#include <stdio.h>
#include "mylibs.h"
#include "mylibs.h"

int main() {
	int a = 6, b = 14;
	// %d es para enteros
	printf("%d\n", a);
	printf("%d\n", b);
	
	int c = sum(a, b);

	printf("%d\n", c);

	return 0;
}
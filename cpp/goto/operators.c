#include <stdio.h>

int main() {
	int a = 0;

	// begin es una etiqueta, puede tener cualquier nombre
	// esto puede usarse como el try catch finally de java
	// se sigue usando mucho
	begin:
		printf("%d\n", a++);
		
		if (a < 10)
			goto begin;

		puts("bye");

		return 0;
}


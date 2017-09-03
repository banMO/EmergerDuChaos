#include <stdio.h>

// Es necesario pasar el tamanio del array
void show(char* x, size_t h) {

	for (int i = 0; i < h; i++)
	{
		printf("%c\n", x[i]);
	}
}

int main(int argc, char const *argv[])
{
	char s[] = {'h', 'o', 'l', 'a', 's'};
	// Imprimir cantidad de elementos del array
	printf("%u\n", sizeof(s)/sizeof(char));
	show(s, 5);
	return 0;
}
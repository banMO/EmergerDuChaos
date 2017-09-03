#include <stdio.h>

int main(int argc, char const *argv[])
{
	int f = 25;
	int* pf = &f;

	printf("%d\n", *pf);

	// qf guarda la direccion de memoria de f. Pero qf no sabe el tipo de valor que esta almacenado.
	// No podemos hacer aritmetica de punteros.
	void* qf = &f;
	// No podemos acceder al valor directamente usando *qf. No compila
	printf("%d\n", *qf);
}
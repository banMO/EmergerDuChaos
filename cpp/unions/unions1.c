#include <stdio.h>
#include <string.h>

/**
 * A union allows to store different data types in the same memory location.
 */

typedef union
{
	int b;
	int i;
	double d;
	char c[18];
} Values;

int main()
{
	Values h;
	// we access member variables using the dot (.)
	// strcpy(h.c, "HOLA");
	// puts(h.c);

	h.i = 0x30313233;
	// puts(h.c);

	// h.d = 3.14159;
	printf("%d\n", h.i);

	// size of union is taken according the size of the largest member in union.
	printf("%d\n", sizeof(h));

	// Porque es la misma direccion? 
	// La memoria reservada para toda la union es del tamaño del miembro con mayor tamanio.
	// Se reserva un mismo espacio de memoria que comparten los 3 tipos.
	printf("%p\n", &h.i);
	// printf("%p\n", &h.c);
}

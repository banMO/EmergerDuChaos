#include <stdio.h>

int main(int argc, char const *argv[])
{
	// Esto es un array de caracteres.
	// Solo es de lectura. No podemos modificar el strings.
	// El contenido de la direccion de memoria que apunta p es constante.
	// Todas las cadenas tienen al final el caracter \0  que indica la terminacion de la cadena.
	const char* p = "hola";
	// Esto es ilegal porque no podemos modificar el string p.
	// p[0] = 'p';
	puts(p);


	// Este array esta en el stack. Es posible modificarlo.
	char x[] = "julio";
	// Al introducir este caracter le decimos al compilador que ahi termina la cadena.
	x[1] = '\0';
	x[2] = 'n'; // Esto es lo mismo *(x+2) = 'n'
	x[5] = 's';
	puts(x);

	return 0;
}
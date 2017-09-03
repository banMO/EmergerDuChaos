#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	// queremos reservar 10 espacios de memoria de tamanio 10*sizeof(int).
	int* ps = (int*) malloc(10*sizeof(int));
	// realloc internamente no limpia la memoria. porq usa malloc internamente y no calloc.
	ps = (int*) realloc(ps, 20*sizeof(int));
	// por eso debemos limpiar la memoria manualmente.
	memset(ps+10, 0, 10*sizeof(int));
	// Siempre que usamos realloc debemos guardar el nuevo puntero.         
	ps = (int*) realloc(ps, 30*sizeof(int));
	return 0;
}
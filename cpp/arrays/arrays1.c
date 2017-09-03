#include <stdio.h>

// Son colecciones de elementos del mismo tipo.
// Tienen tamanio fijo
// Los elementos de acceden con un indice que comienza en cero.

// Caracteristicas de arreglos en C:
// No almacenan su tamanio

int main() {
	// Declaramos un arreglo que puede almacenar 3 enteros.
	int a[3];
	a[0] = 25; 
	a[1] = 50;
	a[2] = 75;
	a[100] = 100;

	int b[] = {25, 50, 75};

	for (int i = 0; i < 1000000; i++) {
		printf("%d\n", a[i]);
	}
}


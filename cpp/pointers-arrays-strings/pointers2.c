#include <stdio.h>

int* p() {
	int x = 12345;
	// Warning - No se puede retornar la direccion de una variable local. La variable x muere al terminar
	// de ejecutarse la funcion.
	return &x;
}
 
int main() {
	// el compilador ha reservedo espacio de memoria para esta variable.
	int z;
	int* pz;

	// Este operador & nos devuelve la direccion de memoria.
	pz = &z;

	printf("%p\n", pz);


	// Estamos accediendo al valor del espacio de memoria y le estamos asignando otro valor.            
	*pz = 1234567890;
	printf("%d\n", z);


	int* x = p();
	printf("%d\n", *x);

	return 0;
}
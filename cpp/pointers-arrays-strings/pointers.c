#include <stdio.h>

int main() {
	// el valor de p es basura.
	// es mala practica dejar sin inicializar.
	int* p;

	// %p es para imprimir punteros
	printf("%p\n", p);


	// si no ponemos (int*) el compilador se queja.
	// (int*) hace un cast.
	// Este es un dangling pointer.
	// int* a = (int*) 0xCAFE; // descomentar esta linea para probar
	// printf("%p\n", a);
	// Si usamos el operator * el pointer devuelve el valor que contiene.
	// Porque se crashea?? Esta fuera del espacio de direcciones del proceso. No podemos alterar el contenido de otro proceso.
	// cualquier acceso de memoria a una espacion de direcciones del proceso que tenemos asignado causa un crash.
	// printf("%d\n", *a);


	// Esto es igual que poner char* q = 0;
	char* q = NULL;

	// Esto es lo mismo que "if (!q)"
	if (q == NULL)
		puts("Error");


	return 0;
}
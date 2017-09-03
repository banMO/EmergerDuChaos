#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* fn;
	char* ln;
	int id;
} person3;

char* new_string(const char* s) {
	// calculamos el numero de byes que necesitamos reservar.
	size_t n = strlen(s);
	// reservamos los bytes. El +1 es por el byte para el /0.
	char* r = (char*) malloc(n + 1);
	// para cadenas largas es mejor usar memcpy en lugar de strcpy.
	memcpy(r, s, n + 1);
	// strcpy(r, s);
	return r;
}

void init_p3(person3* p, const char* name, const char* lastname, int id) {
	// Esto se tira, por que?
	// strcpy(p->fn, name);
	p->fn = new_string(name);
	p->ln = new_string(lastname);
	p->id = id;
}

void free_p3(person3* p) {
	if (p == NULL)
		return;

	// liberamos los espacios de memoria creados con malloc.
	free(p->fn);
	free(p->ln);
}

int main() {
	person3* p4;
	p4 = (person3*) malloc(sizeof(person3));
	// aqui ya no usamos ampersand porq p4 ya es un puntero a una direccion de memoria.
	init_p3(p4, "Romulo", "Rojas", 666);
	puts(p4->ln);
	// aqui ya no usamos ampersand porq p4 ya es un puntero a una direccion de memoria.
	free_p3(p4);
	free(p4);
}
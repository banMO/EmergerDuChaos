#include <stdio.h>

int main() {
	// char s = 'm';
	// char* ps = &s;

	// printf("%p\n", ps);
	// printf("%c\n", *ps);
	// // Ahora el puntero apunta a la siguiente direccion de memoria. mueve el puntero
	// ps++;
	// // Primero devuelve el valor de ps y luego incrementa el valor.
	// *ps++;
	// // Incrementa valor
	// (*ps)++;
	// printf("%p\n", ps);
	// printf("%c\n", *ps);


	int h = 0xDEADBEEF;
	int* ph = &h;
	
	// casteamos a char para movernos de byte en byte
	char* phh = (char*) &h;
	printf("*phh++: %x\n", *phh++); // 44
	printf("*phh++: %x\n", *phh++); // 44
	printf("*phh++: %x\n", *phh++); // 44
	printf("*phh++: %x\n", *phh++); // 44


	printf("%p\n", ph); // 44
	// %x es para hexadecimales
	printf("%x\n", *ph);
	ph++;
	printf("%p\n", ph); // 48
	printf("%x\n", *ph);

}
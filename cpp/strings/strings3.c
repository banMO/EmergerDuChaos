#include <stdio.h>
// Esta libreria nos ayuda a manejar cadenas
#include <strings.h>

// copiar los caracteres de s en h, pero invertido.
// void invertir(char* h, const char* source) {
// 	while (*source) {
// 		source++;
// 	}

// 	puts(source - 1);

// 	while(*source) {
// 		*h = *source;
// 		source--;
// 		h++;
// 	}
// 	*h = '\0';
// }

void invertir(char* d, const char* s) {
	const char* ini = s;
	const char* aux = s + strlen(s) - 1;

	while (aux != ini) {
		*d++ = *aux--;
	}

	*d = *aux;
	*(d+1) = 0;
}

void convertir_a_str(char* aux, int x) {
	int aux = x % 10;

	while (x % 10 < 10) {
		
		*aux = '0' + x%10;
		aux++;
	}
}

int main(int argc, char const *argv[])
{
	// j is a pointer. We can modify j but the object pointed to cannot be modified.
	const char* j = "Jueves";
	const char* k = "Viernes";

	char aux[20];
	printf("%d\n", strlen(j));
	// copia el valor de j a aux
	strcpy(aux, j);
	puts(aux);
	// concatenar k a aux
	strcat(aux, k);
	puts(aux);

	const char* s = "hoy es dia de la bandera boliviana";
	// strstr nos devuelve un puntero hacia la posicion de la primera ocurrencia
	// si no encuentra nos devuelve un puntero NULL
	char* p = strstr(s, "bandero");
	// verificamos si p es igual a NULL
	if (p)
		puts(p);
	else
		puts("Cadena no encontrada");

	char aux2[10];
	// copia el 2do argumento al primer argumento, pero solo el numero de caracteres indicado
	// en el tercer parametro.
	strncpy(aux2, s+7, 3);
	puts(aux2);

	const char* s2 = "Fundacion Jala";
	char h[30];
	invertir(h, s2);
	puts(h);

	int x = 1248;
	char aux3[20];
	convertir_a_str(aux3, x);
	// puts(aux3);
}
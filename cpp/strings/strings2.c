#include <stdio.h>

size_t calc_length(char* word) {
	// int i = 0;

	const char* aux = word;

	if (word == NULL)
		return 0;

	while (*word != '\0') { // esto es lo mismo que while (*word)
 		// i++;
		word++;
	}
	return word - aux;
	// return i;
}

void copy_string(char* dest, char* origen) {
	while (*origen) {
		// *dest = *origen;
		// origen++;
		// dest++;

		// Esto equivale a las tres operaciones de arriba.
		*dest++ = *origen++;

	}
	*dest = '\0';
}

void concat_string(char* dest, char* source) {
	// size_t len = calc_length(dest);
	// copy_string(dest + len, source);

	while (*dest) {
		dest++;
	}

	*dest = ' ';
	dest++;

	while (*source) {
		*dest = *source;
		source++;
		dest++;
	}
	*dest = '\0';
}

int main(int argc, char const *argv[])
{
	// Esto es un puntero
	char* f = "hello world";
	// char* f = "hello";

	size_t len = calc_length(f);
	printf("%d\n", len);

	char f2[100];
	copy_string(f2, f);
	puts(f2);

	concat_string(f2, "of C programming");
	puts(f2);

	return 0;
}
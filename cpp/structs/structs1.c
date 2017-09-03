#include <stdio.h>
#include <string.h>

// esta forma de declaracion es peligrosa
struct person {
	// Esta mal declarar asi
	const char* fn;
	const char* ln;
	size_t id;
};

// esta es otra forma, pero tiene problemas con el tamanio de los arrays.
typedef struct {
	char fn[32];
	char ln[32];
	size_t id;
} person2;

// Esta funcion actua como un constructor.
// Porque hay que recibir un puntero en x??
void init_person(person2* x, const char* fn, const char* ln, size_t id) {
	// strcpy((*x).fn, fn);
	// esto es lo mismo q la linea anterior.
	strcpy(x->fn, fn); 

	// strcpy((*x).ln, ln);
	strcpy(x->ln, ln);
	(*x).id = id;
}

// Como no vamos a cambiar los valores de p, debemos declararla como const.
void print_person(const person2* p) {
	puts(p->fn);
	puts(p->ln);
}

// typedef creates an alias that can be used anywhere in place of a (possible complex) type name. 
typedef struct {
	char dd;
	char mm;
	short yy;
} date;

int main()
{
	// Esto es valido en c++, pero no en C
	// person p;

	// con esta instruccions creamos las instancias
	struct person p;
	date d;

	// acceso a los campos
	p.fn = "Juan";
	p.ln = "Valdez";
	p.id = 3678901;

	puts(p.ln);

	printf("%p\n", &(p.fn));

	char q[] = "Juan";
	p.fn = q;
	p.ln = "Perez";
	p.id = 865;

	q[0] = 'I';
	q[1] = 'v';

	puts(p.fn);

	// Otra prueba

	struct person p2;
	
	{
		char s[] = "hola";
		p2.fn = s;
	}

	{
		char z[] = "Jonas";
	}

	puts(p2.fn);

	
	// Otra prueba usando person2

	person2 a;
	// Esto no funciona. Por que??
	// init_person(a, "Juan", "Perez", 654);

	init_person(&a, "Juan", "Perez", 654);
	// en esta parametro estamos enviando una copia de person.
	// es mejor enviar directamente la direccion de memoria y acceder a travez de un puntero.
	print_person(&a);

	
	// Otra prueba usando arrays

	person2 c[2];

	init_person(c, "Jorge", "Lopez", 123);
	init_person(c+1, "Jorge", "Wilsterman", 666);
	// Esto es lo mismo que lo de arriba.
	// init_person(&(*(c+1)), "Jorge", "Marquez", 123);
	print_person(c);
	print_person(c+1);
	
	return 0;
}
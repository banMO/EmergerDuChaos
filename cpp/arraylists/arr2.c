#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	// 
	char** data;
	size_t n;
} StringList;

void slist_init(StringList* p) {
	// ????
	p->data = (char**) malloc(0);
	p->n = 0;
}

void slist_add(StringList* p, const char* s) 
{	
	p->data = (char**) realloc(p->data, (p->n + 1)*sizeof(char*));

	size_t len = strlen(s);
	char* str = (char*) malloc(len + 1);
	// +1 para el \0
	memcpy(str, s, len + 1);
	p->data[p->n++] = str;
}

// liberamos los espacios de memoria creados con malloc.
void slist_release(StringList* s) {
	// primero liberamos las cadenas del array
	for (int i = 0; i < s->n; i++) 
		free(s->data[i]);

	free(s->data);
	// setting unsued pointers to null is a defensive style, protecting agains dangling pointer bug. If a
	// dangling pointer is accessed after it is freed, you may read or overwrite random memory. If a null pointer
	s->data = NULL;
	s->n = 0;
}

int main() {
	StringList aryasList;
	slist_init(&aryasList);
	
	slist_add(&aryasList, "Cersei Lannister");
	slist_add(&aryasList, "Melisandre");
	slist_add(&aryasList, "Thoros of Myr");

	for (int i = 0; i < aryasList.n; i++) {
		puts(aryasList.data[i]);
	}

	slist_release(&aryasList);
}
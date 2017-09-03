#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* p;
	size_t n;
} Arraylist;

void alist_init(Arraylist* ptr) {
	// ????
	ptr->p = (int*) malloc(0);
	ptr->n = 0;
}

void alist_add(Arraylist* s, int num) {
	// ???
	s->p = (int*) realloc(s->p, (s->n + 1)*sizeof(int));
	s->p[s->n++] = num;
}

// liberamos los espacios de memoria creados con malloc.
void alist_release(Arraylist*s) {
	free(s->p);
	s->p = NULL;
	s->n = 0;
}

int main() {
	Arraylist x;
	alist_init(&x);

	for (int i = 0; i < 1000000; i++) {
		alist_add(&x, i*8);
	}

	for (int i = 0; i < x.n; i++) {
		printf("%d\n", x.p[i]);
	}

	alist_release(&x);
}
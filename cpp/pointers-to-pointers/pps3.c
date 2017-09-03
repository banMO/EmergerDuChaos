#include <stdio.h>


// usando una function de esta manera, podemos conseguir polimorfismo.
// void* n recibe un puntero de cualquier tipo: int, double, etc.
void print(const void* n, int type) {
	switch (type) {
		case 0:
			// nosotros sabemos que si el tipo es 0, la function recibe un int.
			// int* hace el casteo
			printf("%d\n", *((int*)n));
			break;

		case 1:
			printf("%f\n", *((double*)n));
			break;
	}
}

int main(int argc, char const *argv[])
{
	int p = 1234;
	double q = 3.1415926;

	print(&p, 0);
	print(&q, 1);

	return 0;
}
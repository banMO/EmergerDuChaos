#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int d, m, y;
} date;

void print_date(const date* d) {
	printf("%d %d %d\n", d->d, d->m, d->y);
}

int main()
{
	date d;
	date e = {10, 2, 1985};
	int n = 25;
	
	// calloc hace la limpieza de los los valores de los espacios de memoria por nosotros. los pone a todos en 0
	date* fs = (date*) calloc(n, sizeof(date));

	// Si usamos malloc es buena practica verificar si se ha asignado la memoria correctamente.
	if (fs == NULL)
		return -10;

	fs[24].d = 14;
	fs[24].m = 3;
	fs[24].y = 2016;

	// usando flechita accedemos directamente al elemento que esta apuntando el puntero.
	fs->d = 20;
	fs->m = 20;
	fs->y = 20;

	// enviamos la direccion de memoria del date de la posicion 24
	print_date(&fs[24]);
	// 
	print_date(&fs[10]);
	// tenemos que devolver la memoria prestada
	free(fs);
	// es buena practica asignar null
	fs = NULL;
	// free(fs);

	return 0;
}
#include <stdio.h>

/**
 * Un function pointer es un puntero que apunta a una direccion de memoria. Pero no apunta a un dato
 * sino a una function.
 * La funcion tiene que tener un signature (tipo de retorno y tipos de parametros).
 */

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    // Asi se declara un puntero a una function.
    int(*p)(int, int);
    // No podemos cambiar el valor que guarda la direccion de memoria. Solo es de lectura.
    p = sum;

    printf("%d\n", p(8, 16));
}
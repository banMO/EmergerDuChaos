#include <stdio.h>

/**
 * Un function pointer es un puntero que apunta a una direccion de memoria. Pero no apunta a un dato
 * sino a una function.
 * La funcion tiene que tener un signature (tipo de retorno y tipos de parametros).
 */

typedef struct
{
    // Esta es la declaracion de un puntero a una function que retorna void y no recibe parametros.
    void (*say)();
} Animal;

void say_dog()
{
    puts("Guau");
}

void say_cat()
{
    puts("Miau");
}

void init_dog(Animal* a)
{
    a->say = say_dog;
}

void init_cat(Animal* a)
{
    a->say = say_cat;
}


int main()
{
    Animal p, g;
    init_dog(&p);
    init_cat(&g);

    p.say();
    g.say();
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void save()
{
    // opaque pointers
    // w = wt (modo escritura)
    // si no puede abrir devuelve un puntero NULL.
	FILE* f = fopen("nombres.txt", "w");

    // http://en.cppreference.com/w/cpp/error/errno
    if (f == NULL) {
        exit(-1);
        return;
    }

    const char* nombres[] = {"Nicolas", "Maria", "Roger"};

    for (int i = 0; i < 3; i++)
    {
        fprintf(f, "%s\n", nombres[i]);
    }

    // tenemos que cerrar el archivo
    fclose(f);
}

void load()
{
    FILE* g = fopen("nombres.txt", "r");

    if (g == NULL) {
        puts("Error");
        exit(-2);
        return;
    }

    char line[100];
    char* r;

    while ((r = fgets(line, 100, g)) != NULL)
    {
        // numero de bytes reservados para esta cadena
        // char line[100];
        // leer linea de texto
        // char* r = fgets(line, 100, g);

        // if (r == NULL)
            // break;

        size_t len = strlen(line);
        // borrarmos el salto de linea
        line[len - 1] = '\0';

        puts(line);
    }
}

void save2()
{
    FILE* h = fopen("nums.txt", "w");

    for (int i = 0; i < 3; i++)
    {
        fprintf(h, "%d\n", i);
        puts("press enter");
        // limpia el buffer, es costoso porque crea muchos accesos al disco
        fflush(h);
        getchar();
    }
    fclose(h);
}

int main()
{
    // save();
    // load();
    save2();
}

// estudiar: 
// fgets
// fscanf
// fputs
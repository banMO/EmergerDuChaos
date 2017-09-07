#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Para usar rchivos binarios, esta estructura debe ser un POD (Plain Old Data):
// primitivos
// arrays de PODs
// structs de PODs
// No se puede usar punteros
typedef struct
{
    char name[32];
    int old;
} person;

void load_bin()
{
    person* x = malloc(0);
    FILE* g = fopen("ps.bin", "rb");

    if (!g)
        exit(-2);

    int n = 0;

    while (1)
    {
        x = realloc(x, (n + 1) * sizeof(person));
        // devuelvo el numero de objectos de el tamanio especificado que puede leer
        int r = fread(x + n, 1, sizeof(person), g);

        if (!r)
            break;

        n++;
    }

    for (int i = 0; i < n; i++)
    {
        puts(x[i].name);
    }

    fclose(g);
    free(x);
}

void load_bin_mejorado()
{
    FILE* m = fopen("ps.bin", "rb");

    if (!m)
        exit(-3);

    // SEEK_END APUNTO AL FINAL DEL ARCHIVO
    // SEEK_SET APUNTA AL PRINCIPIO DEL ARCHIVO
    // SEEK_CUR POSICION ACTUAL
    fseek(m, 0, SEEK_END);
    
    // Nos dice cuantos bytes han pasado desde el principio del archivo
    size_t len = ftell(m);

    size_t n = len/sizeof(person);

    person* p =  (person*) malloc(n * sizeof(person));

    // tenemos q volver al principio
    fseek(m, 0, SEEK_SET);

    fread(p, n, sizeof(person), m);

    fclose(m);

    for (int i = 0; i < n; i++)
    {
        puts(p[i].name);
    }

    free(p);
}

int main()
{
    // load_bin();
    load_bin_mejorado();
}
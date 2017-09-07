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
    person x[2];
    FILE* g = fopen("ps.bin", "rb");
    if (!g)
        exit(-2);

    fread(x, 2, sizeof(person), g);
    fclose(g);

    for (int i = 0; i < 2; i++)
    {
        puts(x[i].name);
    }
}

int main()
{
    load_bin();
}
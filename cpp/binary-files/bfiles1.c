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

void save_bin()
{
    person a, b;
    
    strcpy(a.name, "Jorge Lopez");
    a.old = 97;

    strcpy(b.name, "Davor");
    b.old = 50;

    // la extension no importante.
    // Si el archivo no existe, lo crea.
    // wb: es para escritura de binarios.
    FILE* f = fopen("ps.bin", "wb");
    
    if (!f)
        exit(-1);

    // se le pasa una direccion de memoria.
    // Desde &a quiero grabar 1 elemento, el elemento mide sizeof(person) y quiero grabarlo en el archivo f
    fwrite(&a, 1, sizeof(person), f);
    fwrite(&b, 1, sizeof(b), f);
    fclose(f);
}

int main()
{
    save_bin();
}
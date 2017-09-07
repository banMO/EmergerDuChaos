#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char data[32];
} my_string;

void disklist_add(FILE* f, const char* s)
{
    my_string ms;

    strcpy(ms.data, s);
    fwrite(&ms, 1, sizeof(my_string), f);
}

size_t disklist_size(FILE* f)
{
    fseek(f, 0, SEEK_END);
    size_t len = ftell(f);
    return len / sizeof(my_string);
}

void disklist_get(FILE* f, size_t index, my_string* s)
{
    fseek(f, index*sizeof(my_string), SEEK_SET);
    fread(s, 1, sizeof(my_string), f);
}

int main()
{
    FILE* f = fopen("strs.dat", "w");

    disklist_add(f, "Lunes");
    disklist_add(f, "Martes");
    disklist_add(f, "Miercoles");
    disklist_add(f, "Jueves");
    disklist_add(f, "Viernes");
    disklist_add(f, "Sabado");
    disklist_add(f, "Domingo");

    fclose(f);

    f = fopen("strs.dat", "rb");
    size_t len = disklist_size(f);

    // leemos del final para adelante
    for (int i = len - 1; i >= 0;  i--)
    {
        my_string aux;
        disklist_get(f, i, &aux);
        puts(aux.data);
    }

    fclose(f);
}
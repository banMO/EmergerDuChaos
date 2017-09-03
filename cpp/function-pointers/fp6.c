#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int cmp_str(const void* a, const void* b)
{
    const char** x = (const char**) a;
    const char** y = (const char**) b;

    return strcmp(*x, *y);
}

int main()
{
    // Recuerda que el array guarda punteros.
    const char* m[] = {"vivaldi", "opera", "chrome", "edge", "firefox"};
    qsort(m, 5, sizeof(char*), cmp_str);

    for (int i = 0; i < 5; i++)
    {
        puts(m[i]);
    }
}
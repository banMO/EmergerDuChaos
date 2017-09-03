#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union
{
	int n;
	char* s;
} Data;

typedef enum
{
	INT,
	STRING
} DataType;

typedef struct
{
	Data data;
	DataType type;
} Variant;

Variant get_int(int x)
{
	Variant val;
	val.data.n = x;
	val.type = INT;

	return val;
}

Variant get_string(const char* s)
{
	Variant val;
	// 
	size_t len = strlen(s);
	char* ns = (char*) malloc(len + 1);
	memcpy(ns, s, len + 1);

	val.data.s = ns;
	val.type = STRING;

	return val;
}

void print_variant(const Variant* s)
{
	if (s->type == STRING)
		puts(s->data.s);
	else
		printf("%d\n", s->data.n);
}

void release_variant(Variant* v) {
	if (v->type == STRING)
		free(v->data.s);

	v->data.s = NULL;
}

int main()
{
	Variant h = get_int(128);
	Variant j = get_string("Littlefinger");

	print_variant(&h);
	print_variant(&j);

	release_variant(&h);
	release_variant(&j);
}
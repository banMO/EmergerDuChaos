#include <stdio.h>

typedef enum
{
	CL_RED,
	CL_GREEN = 10,
	CL_BLUE,
	CL_BLACK,
	CL_WHITE
} Color;

typedef enum
{
	SV_RED,
	SV_GREEN
} Severity;

int main()
{
	Color r = CL_BLACK;
	printf("%d\n", r);

	// ???
	Severity s = 248;
	printf("%d\n", s);
}
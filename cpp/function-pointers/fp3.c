#include <time.h>
#include <stdio.h>

void flash(void(*p)())
{
	clock_t a0 = clock();
	clock_t a1 = a0;

	while (1)
	{
		a1 = clock();
		if (a1 > a0 + 5000)
			break;
	}
	p();
}

void msg_me()
{
	puts("that's all");
}

int main()
{
	flash(msg_me);

	return 0;
}
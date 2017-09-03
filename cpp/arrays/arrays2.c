#include <stdio.h>

int main(int argc, char const *argv[])
{
	char s[] = {'h', 'o', 'l', 'a'};

	// no es necesario usar el operador &
	char* ps = s;

	for (int i = 0; i < 4; i++)
	{
		// pi apuntar a donde apunta ps + i
		// Esto es lo mismo char* pi = ps + i; 
		// Esto tambien char pi = *(i + ps); 
		char pi = i[ps];
		printf("%c\n", pi);
		// printf("%c\n", *pi); 
	}

	return 0;
}
// si no esta definido. A estas directives se les llama INCLUDE_GUARDS
// #ifndef _MYLIBS_H
// definirlo
// #define _MYLIBS_H

// en lugar de poner lo de arriba podemos poner esto
// pero esta directiva no es parte del estandard
#pragma once

	// A estas declaraciones se les llama prototypes
	// no ponemos los nombres de las variables porque eso no le interesa al compilador
	int sum(int, int);

	struct X {};

// #endif
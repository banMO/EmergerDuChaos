// Es una directiva del preprocesador
// las librerias standard se ponen entre <>
// las librerias propias van entre ""
#include <stdio.h>

// main es la entrada al programa. En c++ el main tiene que devolver siempre un entero
// pero en c puede devolver void
int main() {
	// imprime linea de texto en la salida standard. agrega el salto de linea en el final
	// solo imprime texto. En c no existe sobrecarga de metodos
	puts("hello world");
	return 45;
}
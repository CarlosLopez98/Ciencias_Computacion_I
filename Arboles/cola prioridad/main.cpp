#include <iostream>
#include "monticulo.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Monticulo ejemplo;

	ejemplo.insertar(100);
	ejemplo.insertar(90);
	ejemplo.insertar(10);
	ejemplo.insertar(200);
	ejemplo.insertar(500);
	ejemplo.insertar(5);

	ejemplo.imprimir();

	ejemplo.atender();

	ejemplo.imprimir();

	return 0;
}
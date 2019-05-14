#include<iostream>
#include"ArbolArreglo.h"

using namespace std;

int main(){

	ArbolArreglo arbol(12);

	arbol.insertar(200);
	arbol.insertar(100);
	arbol.insertar(300);
	arbol.insertar(80);
	arbol.insertar(150);
	arbol.insertar(250);
	arbol.insertar(330);
	arbol.insertar(340);
	arbol.insertar(310);
	arbol.insertar(315);

	arbol.imprimir();

	arbol.eliminar(200);

	arbol.imprimir();


	return 0;
}
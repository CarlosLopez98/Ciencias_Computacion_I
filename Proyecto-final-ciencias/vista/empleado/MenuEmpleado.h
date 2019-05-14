#include"../general/Header.h"

#ifndef MENUEMPLEADO_H
#define MENUEMPLEADO_H

using namespace std;

class MenuEmpleado {

	public:
		MenuEmpleado();
		~MenuEmpleado();

		static void mostrar(string&, string&);
};

MenuEmpleado::MenuEmpleado(){}
MenuEmpleado::~MenuEmpleado(){}

void MenuEmpleado::mostrar(string& controlador, string& accion){
	Header::mostrar();

	cout << "Consultas para empleados" << endl;

	int opc;
	cin >> opc;

	controlador = "general";
	accion = "menuPrinciapal";
}

#endif
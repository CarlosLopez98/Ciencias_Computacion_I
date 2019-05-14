#include"Header.h"

#ifndef MENUGENERAL_H
#define MENUGENERAL_H

using namespace std;

class MenuGeneral {
	private:

	public:
		MenuGeneral();
		~MenuGeneral();

		static void menuPrincipal(string&, string&);
		static void menuConsulta(string&, string&);
		static void menuRegistro(string&, string&);
};

MenuGeneral::MenuGeneral(){}
MenuGeneral::~MenuGeneral(){}

void MenuGeneral::menuPrincipal(string& controlador, string& accion){
	Header::mostrar();

	cout << "Menu principal" << endl;
	cout << "[1] Consultas." << endl;
	cout << "[2] Registros." << endl;
	cout << "[0] Salir." << endl;

	int opc;
	cin >> opc;

	switch(opc){
		case 1:
			controlador = "general";
			accion = "menuConsulta";
			break;
		case 2:
			controlador = "general";
			accion = "menuRegistro";
			break;
		case 0:
			controlador = "";
			accion = "";
			break;
		default:
			controlador = "general";
			accion = "menuPrincipal";
	}
}

void MenuGeneral::menuConsulta(string& controlador, string& accion){
	Header::mostrar();

	cout << "Menu de consultas" << endl;
	cout << "[1] Consultar empleados." << endl;
	cout << "[2] Consultar sucursal." << endl;
	cout << "[0] Volver." << endl;

	int opc;
	cin >> opc;

	switch(opc){
		case 1:
			controlador = "empleado";
			accion = "menu";
			break;
		case 2:
			controlador = "sucursal";
			accion = "menu";
			break;
		case 0:
			controlador = "general";
			accion = "menuPrincipal";
			break;
		default:
			controlador = "general";
			accion = "menuConsulta";
	}
}

void MenuGeneral::menuRegistro(string& controlador, string& accion){
	Header::mostrar();

	cout << "Menu de registro\n" << endl;
	cout << "Empleados" << endl;
	cout << "[1] Registrar empleado." << endl;
	cout << "[2] Actualizar empleado." << endl;
	cout << "[3] Eliminar empleado." << endl;

	cout << endl;

	cout << "Sucursales" << endl;
	cout << "[4] Registrar sucursal." << endl;
	cout << "[5] Actualizar sucursal." << endl;
	cout << "[6] Eliminar sucursal." << endl;

	cout << endl;
	cout << "[0] Volver." << endl;

	int opc;
	cin >> opc;

	switch(opc){
		case 1:
			controlador = "empleado";
			accion = "registrar";
			break;
		case 2:
			controlador = "empleado";
			accion = "actualizar";
			break;
		case 3:
			controlador = "empleado";
			accion = "eliminar";
			break;
		case 4:
			controlador = "sucursal";
			accion = "registrar";
			break;
		case 5:
			controlador = "sucursal";
			accion = "actualizar";
			break;
		case 6:
			controlador = "sucursal";
			accion = "eliminar";
			break;
		case 0:
			controlador = "general";
			accion = "menuPrincipal";
			break;
		default:
			controlador = "general";
			accion = "menuRegistro";
	}
}

#endif
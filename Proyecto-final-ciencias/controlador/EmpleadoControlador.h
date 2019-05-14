//#include"../modelo/Empleado.h"
#include"../vista/empleado/MenuEmpleado.h"
#include"../vista/empleado/MenuRegistro.h"

#ifndef EMPLEADOCONTROLADOR_H
#define EMPLEADOCONTROLADOR_H

using namespace std;

class EmpleadoControlador {
	public:
		EmpleadoControlador();
		~EmpleadoControlador();
		
		void menu(string&, string&);
		void menuRegistro(string&, string&);

		void registrar(string*);
		void actualizar();
		void eliminar();
};

EmpleadoControlador::EmpleadoControlador(){}
EmpleadoControlador::~EmpleadoControlador(){}

void EmpleadoControlador::menu(string& controlador, string& accion){
	MenuEmpleado::mostrar(controlador, accion);
}

void EmpleadoControlador::menuRegistro(string& controlador, string& accion){
	MenuRegistro::mostrar(controlador, accion);
}

void EmpleadoControlador::registrar(string *datos){
	
}

#endif
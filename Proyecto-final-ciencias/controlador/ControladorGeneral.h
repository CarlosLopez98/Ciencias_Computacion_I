#include"../vista/general/MenuGeneral.h"

#ifndef CONTROLADORGENERAL_H
#define CONTROLADORGENERAL_H

using namespace std;

class ControladorGeneral {
	private:

	public:
		ControladorGeneral();
		~ControladorGeneral();

		void menuPrincipal(string&, string&);
		void menuConsulta(string&, string&);
		void menuRegistro(string&, string&);
};

ControladorGeneral::ControladorGeneral(){}
ControladorGeneral::~ControladorGeneral(){}

void ControladorGeneral::menuPrincipal(string& controlador, string& accion){
	MenuGeneral::menuPrincipal(controlador, accion);
}

void ControladorGeneral::menuConsulta(string& controlador, string& accion){
	MenuGeneral::menuConsulta(controlador, accion);
}

void ControladorGeneral::menuRegistro(string& controlador, string& accion){
	MenuGeneral::menuRegistro(controlador, accion);
}

#endif
#include<cstdlib>
#include<iostream>
#include<string.h>

#include"datos/DB.h"
#include"modelo/Helper.h"

// Controladores
#include"controlador/EmpleadoControlador.h"
#include"controlador/SucursalControlador.h"
#include"controlador/ControladorGeneral.h"
// Modelos
#include"modelo/Empresa.h"
#include"modelo/Empleado.h"
#include"modelo/Sucursal.h"
#include"modelo/Hijo.h"

using namespace std;

int main(int argc, char *argv[ ], char *envp[ ]){

	// Cargar informacion en las estructuras
	Empresa miEmpresa;
	miEmpresa.cargarDatos();

	string controlador = "general";
	string accion = "menuPrincipal";

	while(controlador != "" && accion != ""){
		if(controlador == "general"){
			ControladorGeneral con;

			if(accion == "menuPrincipal") con.menuPrincipal(controlador, accion);
			else if(accion == "menuConsulta") con.menuConsulta(controlador, accion);
			else if(accion == "menuRegistro") con.menuRegistro(controlador, accion);
			else accion = "menuPrincipal";

		}else if(controlador == "empleado"){
			EmpleadoControlador con;

			if(accion == "menu") con.menu(controlador, accion);
			else if(accion == "registrar") con.menuRegistro(controlador, accion);
			else accion = "menu";

		}else if(controlador == "sucursal"){
			SucursalControlador con;
		}else{
			controlador = "general";
			accion = "menuPrincipal";
		}
	}

	return 0;
}
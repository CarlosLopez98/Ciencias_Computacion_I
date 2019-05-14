//#include"../datos/DB.h"
/*#include"Sucursal.h"
#include"Hijo.h"
#include"Empleado.h"*/

#ifndef EMPRESA_H
#define EMPRESA_H

class Empresa {

	DB db;

	Sucursal sucursales;
	Empleado empleados;
	Hijo hijos;

	public:
		Empresa();
		~Empresa(){}

		// Cargar datos
		void cargarDatos();

		//Consultas

};

Empresa::Empresa(){
	
}

void Empresa::cargarDatos(){
	string **datosArchivo;

	db.setArchivo("Empleados.txt");
	datosArchivo = db.leer_todo();
	for(int i=1; i<db.getNumLineas(); i++)
		empleados.insertarEmpleado(datosArchivo[i]);


	db.setArchivo("Hijos.txt");
	datosArchivo = db.leer_todo();
	hijos.insertarHijo(datosArchivo[1]);
	int cab = 1;
	for(int i=2; i<db.getNumLineas(); i++){
		if(datosArchivo[i][3] == datosArchivo[i-1][3])
			hijos.insertarHijo(datosArchivo[i], cab);
		else{
			hijos.insertarHijo(datosArchivo[i]);
			cab = i;
		}
	}

	db.setArchivo("Sucursales.txt");
	datosArchivo = db.leer_todo();
	/*for(int i=1; i<db.getNumLineas(); i++)
		sucursales.insertarSucursal(datosArchivo[i]);*/
}

#endif
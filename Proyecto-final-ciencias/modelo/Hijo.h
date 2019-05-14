//#include"../datos/DB.h"
//#include"Helper.h"

#ifndef HIJO_H
#define HIJO_H

class Hijo {
	struct datos{
		string nombre;
		string fecha_naci;
		int edad;

		int sigNombre;
		int sigEdad;
		int sigHermano;
	};

	/*
	Cabezas
	[0] nombre
	Edad
	[1] 0-5
	[2] 6-10
	[3] 11-15
	[4] 16-
	*/

	int *arregloCabezas;
	datos **arregloHijos;

	int tam;
	int posAct;
	
	DB db;

	public:
		Hijo();
		~Hijo();

		void insertarNombre(string);
		void insertarEdad(int);
		void insertarHermano(int);

		bool insertarHijo(string*, int);
		void borrarHijo(int);
		bool vacia();
		bool llena();
};

Hijo::Hijo(){
	db.setArchivo("Hijos.txt");
	string **datosArchivo = db.leer_todo(); //Se obtienen los datos del archivo Sucursales.txt

	tam = db.getNumLineas() * 2; // el tamaño del arreglo es igual a el numero de lineas del archivo * 2

	arregloHijos = new datos*[tam];  // Se instancia el arreglo
	posAct = 0;

	arregloCabezas = new int[5];
	for(int i=0; i<5; i++){
		arregloCabezas[i] = 0; // Se llena el arreglo de las cabezas con ceros
	}

	// Creacion nodo de control
	datos *cabecera = new datos; // nodo de control
	// Se llena el nodo(datos) con datos de control para la insercion posterior
	cabecera->nombre = "zz";
	cabecera->fecha_naci = "zz";
	cabecera->edad = 100;
	cabecera->sigNombre = -1;
	cabecera->sigEdad = -1;
	cabecera->sigHermano = -1;
	
	arregloHijos[0] = cabecera; // se inserta en el arreglo
	
	posAct = 1; // inicia en 1 para empezar a insertar despues de la pos de control
}

Hijo::~Hijo(){}

bool Hijo::insertarHijo(string *hijo, int cabeza=0){
	datos *nuevo = new datos;
	nuevo->nombre = hijo[1];
	nuevo->fecha_naci = hijo[2];
	char buffer[10]; strcpy(buffer, hijo[2].c_str());
	nuevo->edad = Helper::calcularEdad(buffer);

	if(!llena()){

		arregloHijos[posAct] = new datos;
		arregloHijos[posAct] = nuevo;

		insertarNombre(nuevo->nombre);
		insertarEdad(nuevo->edad);
		if(cabeza == 0){
			arregloHijos[posAct]->sigHermano = 0;
		}else{
			insertarHermano(cabeza);
		}

		posAct++;
		return posAct-1;
	}

	return false;
}

void Hijo::insertarNombre(string nombre){
	int ant = 0; // posicion anterior a la nueva
	int sig = arregloCabezas[0]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(nombre > arregloHijos[sig]->nombre){
		ant = sig;
		sig = arregloHijos[sig]->sigNombre;
		pri = false;
	}
	
	arregloHijos[posAct]->sigNombre = sig;
	
	if(pri){		
		arregloCabezas[0] = posAct;
	}else{
		arregloHijos[ant]->sigNombre = posAct;
	}
}

void Hijo::insertarEdad(int edad){
	int pos_edad;
	if(edad >= 0 && edad <= 5){
		pos_edad = 1;
	}else if(edad >= 6 && edad <= 10){
		pos_edad = 2;
	}else if(edad >= 11 && edad <= 15){
		pos_edad = 3;
	}else{
		pos_edad = 4;
	}

	int ant = 0; // posicion anterior a la nueva
	int sig = arregloCabezas[pos_edad]; // posicion siguiente a la nueva

	if(sig == 0){
		arregloCabezas[pos_edad] = posAct;
		arregloHijos[posAct]->sigEdad = 0;
	}else{
		while(sig != 0){
			ant = sig;
			sig = arregloHijos[sig]->sigEdad;
		}

		arregloHijos[ant]->sigEdad = posAct;
		arregloHijos[posAct]->sigEdad = 0;
	}
}

void Hijo::insertarHermano(int cabeza){
	int ant = 0; // posicion anterior a la nueva
	int sig = cabeza; // posicion siguiente a la nueva

	while(sig != 0){
		ant = sig;
		sig = arregloHijos[sig]->sigHermano;
	}

	arregloHijos[ant]->sigHermano = posAct;
	arregloHijos[posAct]->sigHermano = 0;
}

bool Hijo::vacia(){
	return posAct == 0;
}

bool Hijo::llena(){
	return posAct == tam;
}

#endif
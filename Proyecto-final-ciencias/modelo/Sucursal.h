//#include"datos/DB.h"

class Sucursal {
	struct datos{
		string nombre;
		string direccion;
		string barrio;
		int nombre_gerente;

		int sigNombre;
		int sigDireccion;
		int sigBarrio;
		int sigNombre_gerente;

		int sigPosLibre;
	};

	/*
	Cabezas
	[0] nombre
	[1] direccion
	[2] barrio
	[3] nombre gerente
	*/

	int *arregloCabezas;
	datos **arregloSucursales;

	int tam;
	int posAct;
	

	DB db;

	public:
		Sucursal();
		~Sucursal();
		
		void insertarNombre(string);
		void insertarDireccion(string);
		void insertarBarrio(string);
		void insertarNombre_gerente(int);

		bool insertarSucursal(string*);
		void borrarSucursal(int);
		bool vacia();
		bool llena();
		string* obtenerRegistro(int);

		string** getDatos();

		void imprimir(){
			for(int i=0; i<posAct; i++){
				cout << i << " ";
				cout << arregloSucursales[i]->nombre << " ";
				cout << arregloSucursales[i]->direccion << " ";
				cout << arregloSucursales[i]->barrio << " ";
				cout << arregloSucursales[i]->nombre_gerente << " ";
				cout << arregloSucursales[i]->sigNombre << " ";
				cout << arregloSucursales[i]->sigDireccion << " ";
				cout << arregloSucursales[i]->sigBarrio << " ";
				cout << arregloSucursales[i]->sigNombre_gerente << " ";
				cout << endl;
			}
		}
};

Sucursal::Sucursal(){
	db.setArchivo("Sucursales.txt");
	string **datosArchivo = db.leer_todo(); //Se obtienen los datos del archivo Sucursales.txt

	tam = db.getNumLineas() * 2; // el tamaño del arreglo es igual a el numero de lineas del archivo * 2

	arregloSucursales = new datos*[tam];  // Se instancia el arreglo
	posAct = 0;

	arregloCabezas = new int[4];
	for(int i=0; i<4; i++){
		arregloCabezas[i] = 0; // Se llena el arreglo de las cabezas con ceros
	}

	// Creacion nodo de control
	datos *cabecera = new datos; // nodo de control
	// Se llena el nodo(datos) con datos de control para la insercion posterior
	cabecera->nombre = "zz";
	cabecera->direccion = "zz";
	cabecera->barrio = "zz";
	cabecera->nombre_gerente = 0;
	cabecera->sigNombre = -1;
	cabecera->sigDireccion = -1;
	cabecera->sigBarrio = -1;
	cabecera->sigNombre_gerente = -1;
	
	arregloSucursales[0] = cabecera; // se inserta en el arreglo
	
	posAct = 1; // inicia en 1 para empezar a insertar despues de la pos de control

	
	// Se guardan los datos del archivo en la estructura
	for(int i=0; i<db.getNumLineas(); i++){
		//llamar funcion insertar
	}
}

Sucursal::~Sucursal(){}

string** Sucursal::getDatos(){
	return db.leer_todo();
}

// Pasar arreglo de tam 4
bool Sucursal::insertarSucursal(string *registro){
	datos *nuevo = new datos;
	nuevo->nombre = registro[1];
	nuevo->direccion = registro[2];
	nuevo->barrio = registro[3];
	nuevo->nombre_gerente = atoi(registro[4].c_str());

	if(!llena()){

		arregloSucursales[posAct] = new datos;
		arregloSucursales[posAct] = nuevo;

		insertarNombre(nuevo->nombre);
		insertarDireccion(nuevo->direccion);
		insertarBarrio(nuevo->barrio);
		insertarNombre_gerente(nuevo->nombre_gerente);

		posAct++;
		return true;
	}

	return false;
}

void Sucursal::insertarNombre(string nombre){
	int ant = 0; // posicion anterior a la nueva
	int sig = arregloCabezas[0]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(nombre > arregloSucursales[sig]->nombre){
		ant = sig;
		sig = arregloSucursales[sig]->sigNombre;
		pri = false;
	}
	
	arregloSucursales[posAct]->sigNombre = sig;
	
	if(pri){		
		arregloCabezas[0] = posAct;
	}else{
		arregloSucursales[ant]->sigNombre = posAct;
	}
}

void Sucursal::insertarDireccion(string direccion){
	int ant = 0; // posicion anterior a la nueva
	int sig = arregloCabezas[1]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(direccion > arregloSucursales[sig]->direccion){
		ant = sig;
		sig = arregloSucursales[sig]->sigDireccion;
		pri = false;
	}
	
	arregloSucursales[posAct]->sigDireccion = sig;
	
	if(pri){		
		arregloCabezas[1] = posAct;
	}else{
		arregloSucursales[ant]->sigDireccion = posAct;
	}
}

void Sucursal::insertarBarrio(string barrio){
	int ant = 0; // posicion anterior a la nueva
	int sig = arregloCabezas[2]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(barrio > arregloSucursales[sig]->barrio){
		ant = sig;
		sig = arregloSucursales[sig]->sigBarrio;
		pri = false;
	}
	
	arregloSucursales[posAct]->sigBarrio = sig;
	
	if(pri){		
		arregloCabezas[2] = posAct;
	}else{
		arregloSucursales[ant]->sigBarrio = posAct;
	}
}

void Sucursal::insertarNombre_gerente(int nombre_gerente){
	int ant = 0; // posicion anterior a la nueva
	int sig = arregloCabezas[3]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(nombre_gerente > arregloSucursales[sig]->nombre_gerente){
		ant = sig;
		sig = arregloSucursales[sig]->sigNombre_gerente;
		pri = false;
	}
	
	arregloSucursales[posAct]->sigNombre_gerente = sig;
	
	if(pri){		
		arregloCabezas[3] = posAct;
	}else{
		arregloSucursales[ant]->sigNombre_gerente = posAct;
	}
}

void Sucursal::borrarSucursal(int pos){

}

bool Sucursal::vacia(){
	return posAct == 0;
}

bool Sucursal::llena(){
	return posAct == tam;
}
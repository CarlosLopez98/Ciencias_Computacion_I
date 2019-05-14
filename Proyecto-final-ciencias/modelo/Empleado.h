//#include"../datos/DB.h"
//#include"Helper.h"

#ifndef EMPLEADO_H
#define EMPLEADO_H


class Empleado {
	struct datos{
		string nombre;
		string apellido;
		string tipo_id;
		double num_id;
		string sexo;
		int celular;
		int telefono;
		string email;
		string fecha_naci;
		int edad; // calcular a partir de la fecha
		string ciudad_naci;
		string pais_naci;
		string ciudad;
		string direccion;
		string barrio;
		string actividad_lab;
		string tiene_hijos;
		int num_hijos;
		int hijos;
		int nom_sucursal;

		int sigNombre;
		int sigApellido;

		int sigTipo_id;
		int sigNum_id;

		int sigSexo;

		int sigEmail;
		int sigFecha_naci;
		int sigEdad;
		int sigCiudad_naci;
		int sigPais_naci;
		int sigCiudad;
		int sigBarrio;

		int sigActividad;

		int sigTiene_hijos;
		int sigNum_hijos;

		int sigSucursal;
	};

	/*
	Cabezas

	Nombre
	[0] nombre
	[1] apellido

	Tipo id
	[0] CC
	[1] CE
	[2] TI
	[3] identificacion

	Sexo
	[0] Masculino
	[1] Femenino
	
	Informacion
	[0] email
	[1] fecha_nacimiento
	[2] edad
	[3] ciudad_nacimiento
	[4] pais_nacimiento
	[5] ciudad
	[6] barrio

	Actividad laboral
	[0] Ingenieria
	[1] Ciencias
	[2] Artes
	[3] Otros
	
	Hijos
	[0] Con hijos
	[1] Sin hijos
	[2] Numero de hijos
	[3] Hijos
	
	Sucursales
	[0] Sucursal 1 
	[1] Sucursal 2
	[2] Sucursal 3
	[3] Sucursal 4
	[4] Sucursal 5
	[5] Sucursal 6
	[6] Sucursal 7
	[7] Sucursal 8
	[8] Sucursal 9
	[9] Sucursal 10
	*/
 
	int *cabezaNombre;
	int *cabezaId;
	int *cabezaSexo;
	int *cabezaInformacion;
	int *cabezaActividad;
	int *cabezaHijos;
	int *cabezaSucursales;

	datos **arregloEmpleados;

	int tam;
	int posAct;
	

	DB db;

	public:
		Empleado();
		~Empleado();
		
		void insertarNombre(string);
		void insertarApellido(string);

		void insertarTipo_id(string);
		void insertarNum_id(int);

		void insertarSexo(string);

		void insertarEmail(string);
		void insertarFecha_nacimiento(string);
		void insertarEdad(int);
		void insertarCiudad_nacimiento(string);
		void insertarPais_nacimiento(string);
		void insertarCiudad(string);
		void insertarBarrio(string);

		void insertarActividad(string);

		//void insertarHijo(string**); No es necesario

		void insertarSucursal(int);

		bool insertarEmpleado(string*);
		void borrarEmpleado(int);
		bool vacia();
		bool llena();
		string* obtenerRegistro(int);

		string** getDatos();

		int* llenarCabezas(int *arreglo, int tam){
			for(int i=0; i<tam; i++)
				arreglo[i] = 0;

			return arreglo;
		}

		/*void imprimir(){
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
		}*/
};

Empleado::Empleado(){
	db.setArchivo("Empleados.txt");
	string **datosArchivo = db.leer_todo(); //Se obtienen los datos del archivo Sucursales.txt

	tam = db.getNumLineas() * 2; // el tamaño del arreglo es igual a el numero de lineas del archivo * 2

	arregloEmpleados = new datos*[tam];  // Se instancia el arreglo
	posAct = 0;

	// Instanciacion de las cabezas
	cabezaNombre = new int[2];
	cabezaNombre = llenarCabezas(cabezaNombre, 2);
	cabezaId = new int[4];
	cabezaId = llenarCabezas(cabezaId, 4);
	cabezaSexo = new int[2];
	cabezaSexo = llenarCabezas(cabezaSexo, 2);
	cabezaInformacion = new int[7];
	cabezaInformacion = llenarCabezas(cabezaInformacion, 7);
	cabezaActividad = new int[4];
	cabezaActividad = llenarCabezas(cabezaActividad, 4);
	cabezaHijos = new int[4];
	cabezaHijos = llenarCabezas(cabezaHijos, 4);
	cabezaSucursales = new int[10];
	cabezaSucursales = llenarCabezas(cabezaSucursales, 10);


	// Creacion nodo de control
	datos *cabecera = new datos; // nodo de control
	// Se llena el nodo(datos) con datos de control para la insercion posterior
	cabecera->nombre = "zz";
	cabecera->apellido = "zz";
	cabecera->tipo_id = "CC";
	cabecera->num_id = 9999999999;
	cabecera->sexo = 'M';
	cabecera->email = "zz";
	cabecera->fecha_naci = "00/00/0000";
	cabecera->edad = 100;
	cabecera->ciudad_naci = "zz";
	cabecera->pais_naci = "zz";
	cabecera->ciudad = "zz";
	cabecera->barrio = "zz";
	cabecera->actividad_lab = "zz";
	cabecera->tiene_hijos = 'N';
	cabecera->num_hijos = 0;
	cabecera->hijos = 0;
	cabecera->nom_sucursal = 0;

	cabecera->sigNombre = -1;
	cabecera->sigApellido = -1;
	cabecera->sigTipo_id = -1;
	cabecera->sigNum_id = -1;
	cabecera->sigSexo = -1;
	cabecera->sigEmail = -1;
	cabecera->sigFecha_naci = -1;
	cabecera->sigEdad = -1;
	cabecera->sigCiudad_naci = -1;
	cabecera->sigPais_naci = -1;
	cabecera->sigCiudad = -1;
	cabecera->sigBarrio = -1;
	cabecera->sigActividad = -1;
	cabecera->sigTiene_hijos = -1;
	cabecera->sigNum_hijos = -1;
	cabecera->sigSucursal = -1;
	
	arregloEmpleados[0] = cabecera; // se inserta en el arreglo
	
	posAct = 1; // inicia en 1 para empezar a insertar despues de la pos de control

	
	// Se guardan los datos del archivo en la estructura
	for(int i=0; i<db.getNumLineas(); i++){
		//llamar funcion insertar
	}
}

Empleado::~Empleado(){}

string** Empleado::getDatos(){
	return db.leer_todo();
}

// Pasar arreglo de tam 4
bool Empleado::insertarEmpleado(string *registro){
	datos *nuevo = new datos;
	nuevo->nombre = registro[1];
	nuevo->apellido = registro[2];
	nuevo->tipo_id = registro[3];
	nuevo->num_id = atoi(registro[4].c_str());
	nuevo->sexo = registro[5];
	nuevo->celular = atoi(registro[6].c_str());
	nuevo->telefono = atoi(registro[7].c_str());
	nuevo->email = registro[8];
	nuevo->fecha_naci = registro[9];
	char buffer[10]; strcpy(buffer, registro[9].c_str());
	nuevo->edad = Helper::calcularEdad(buffer);
	nuevo->ciudad_naci = registro[10];
	nuevo->pais_naci = registro[11];
	nuevo->ciudad = registro[12];
	nuevo->direccion = registro[13];
	nuevo->barrio = registro[14];
	nuevo->actividad_lab = registro[15];
	nuevo->tiene_hijos = registro[16];
	nuevo->num_hijos = atoi(registro[17].c_str());
	nuevo->hijos = atoi(registro[18].c_str());
	nuevo->nom_sucursal = atoi(registro[19].c_str());

	if(!llena()){

		arregloEmpleados[posAct] = new datos;
		arregloEmpleados[posAct] = nuevo;
		insertarNombre(nuevo->nombre);
		insertarApellido(nuevo->apellido);

		insertarTipo_id(nuevo->tipo_id);
		insertarNum_id(nuevo->num_id);

		insertarSexo(nuevo->sexo);

		insertarEmail(nuevo->email);
		//insertarFecha_nacimiento(nuevo->fecha_naci); No es necesaria
		insertarEdad(nuevo->edad);
		insertarCiudad_nacimiento(nuevo->ciudad_naci);
		insertarPais_nacimiento(nuevo->pais_naci);
		insertarCiudad(nuevo->ciudad);
		insertarBarrio(nuevo->barrio);

		insertarActividad(nuevo->actividad_lab);

		insertarSucursal(nuevo->nom_sucursal);

		posAct++;
		delete nuevo;
		return true;
	}
	delete nuevo;
	return false;
}

void Empleado::insertarNombre(string nombre){
	int ant = 0; // posicion anterior a la nueva
	int sig = cabezaNombre[0]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(nombre > arregloEmpleados[sig]->nombre){
		ant = sig;
		sig = arregloEmpleados[sig]->sigNombre;
		pri = false;
	}
	
	arregloEmpleados[posAct]->sigNombre = sig;
	
	if(pri){		
		cabezaNombre[0] = posAct;
	}else{
		arregloEmpleados[ant]->sigNombre = posAct;
	}
}

void Empleado::insertarApellido(string apellido){
	int ant = 0; // posicion anterior a la nueva
	int sig = cabezaNombre[1]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(apellido > arregloEmpleados[sig]->apellido){
		ant = sig;
		sig = arregloEmpleados[sig]->sigApellido;
		pri = false;
	}
	
	arregloEmpleados[posAct]->sigApellido = sig;
	
	if(pri){		
		cabezaNombre[1] = posAct;
	}else{
		arregloEmpleados[ant]->sigApellido = posAct;
	}
}

void Empleado::insertarTipo_id(string tipo_id){
	int pos_tipo;
	if(tipo_id == "CC"){
		pos_tipo = 0;
	}else if(tipo_id == "CE"){
		pos_tipo = 1;
	}else{
		pos_tipo = 2;
	}

	int ant = 0; // posicion anterior a la nueva
	int sig = cabezaId[pos_tipo]; // posicion siguiente a la nueva

	if(sig == 0){
		cabezaId[pos_tipo] = posAct;
		arregloEmpleados[posAct]->sigTipo_id = 0;
	}else{
		while(sig != 0){
			ant = sig;
			sig = arregloEmpleados[sig]->sigTipo_id;
		}

		arregloEmpleados[ant]->sigTipo_id = posAct;
		arregloEmpleados[posAct]->sigTipo_id = 0;
	}

}

void Empleado::insertarNum_id(int num_id){
	int ant = 0; // posicion anterior a la nueva
	int sig = cabezaId[3]; // posicion siguiente a la nueva
	bool pri = true;
	
	while(num_id > arregloEmpleados[sig]->num_id){
		ant = sig;
		sig = arregloEmpleados[sig]->sigNum_id;
		pri = false;
	}
	
	arregloEmpleados[posAct]->sigNum_id = sig;
	
	if(pri){		
		cabezaId[3] = posAct;
	}else{
		arregloEmpleados[ant]->sigNum_id = posAct;
	}
}

void Empleado::insertarSexo(string sexo){
	int pos_sexo;
	if(sexo == "M"){
		pos_sexo = 0;
	}else if(sexo == "F"){
		pos_sexo = 1;
	}

	int ant = 0; // posicion anterior a la nueva
	int sig = cabezaSexo[pos_sexo]; // posicion siguiente a la nueva

	if(sig == 0){
		cabezaSexo[pos_sexo] = posAct;
		arregloEmpleados[posAct]->sigSexo = 0;
	}else{
		while(sig != 0){
			ant = sig;
			sig = arregloEmpleados[sig]->sigSexo;
		}

		arregloEmpleados[ant]->sigSexo = posAct;
		arregloEmpleados[posAct]->sigSexo = 0;
	}

}

void Empleado::insertarEmail(string email){
	int ant = 0; // posicion anterior a la nueva
	int sig = cabezaInformacion[0]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(email > arregloEmpleados[sig]->email){
		ant = sig;
		sig = arregloEmpleados[sig]->sigEmail;
		pri = false;
	}
	
	arregloEmpleados[posAct]->sigEmail = sig;
	
	if(pri){		
		cabezaInformacion[0] = posAct;
	}else{
		arregloEmpleados[ant]->sigEmail = posAct;
	}
}

void Empleado::insertarFecha_nacimiento(string fecha_nacimiento){
	int ant = 0; // posicion anterior a la nueva
	int sig = cabezaInformacion[1]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(fecha_nacimiento > arregloEmpleados[sig]->fecha_naci){
		ant = sig;
		sig = arregloEmpleados[sig]->sigFecha_naci;
		pri = false;
	}
	
	arregloEmpleados[posAct]->sigFecha_naci = sig;
	
	if(pri){		
		cabezaInformacion[1] = posAct;
	}else{
		arregloEmpleados[ant]->sigFecha_naci = posAct;
	}
}

void Empleado::insertarEdad(int edad){
	int ant = 0; // posicion anterior a la nueva
	int sig = cabezaInformacion[2]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(edad > arregloEmpleados[sig]->edad){
		ant = sig;
		sig = arregloEmpleados[sig]->sigEdad;
		pri = false;
	}
	
	arregloEmpleados[posAct]->sigEdad = sig;
	
	if(pri){
		cabezaInformacion[2] = posAct;
	}else{
		arregloEmpleados[ant]->sigEdad = posAct;
	}
}

void Empleado::insertarCiudad_nacimiento(string ciudad_naci){
	int ant = 0; // posicion anterior a la nueva
	int sig = cabezaInformacion[3]; // posicion siguiente a la nueva
	bool pri = true;
	
	while(ciudad_naci > arregloEmpleados[sig]->ciudad_naci){
		ant = sig;
		sig = arregloEmpleados[sig]->sigCiudad_naci;
		pri = false;
	}
	
	arregloEmpleados[posAct]->sigCiudad_naci = sig;
	
	if(pri){		
		cabezaInformacion[3] = posAct;
	}else{
		arregloEmpleados[ant]->sigCiudad_naci = posAct;
	}
}

void Empleado::insertarPais_nacimiento(string pais_naci){
	int ant = 0; // posicion anterior a la nueva
	int sig = cabezaInformacion[4]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(pais_naci > arregloEmpleados[sig]->pais_naci){
		ant = sig;
		sig = arregloEmpleados[sig]->sigPais_naci;
		pri = false;
	}
	
	arregloEmpleados[posAct]->sigPais_naci = sig;
	
	if(pri){		
		cabezaInformacion[4] = posAct;
	}else{
		arregloEmpleados[ant]->sigPais_naci = posAct;
	}
}

void Empleado::insertarCiudad(string ciudad){
	int ant = 0; // posicion anterior a la nueva
	int sig = cabezaInformacion[5]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(ciudad > arregloEmpleados[sig]->ciudad){
		ant = sig;
		sig = arregloEmpleados[sig]->sigCiudad;
		pri = false;
	}
	
	arregloEmpleados[posAct]->sigCiudad = sig;
	
	if(pri){		
		cabezaInformacion[5] = posAct;
	}else{
		arregloEmpleados[ant]->sigCiudad = posAct;
	}
}

void Empleado::insertarBarrio(string barrio){
	int ant = 0; // posicion anterior a la nueva
	int sig = cabezaInformacion[6]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(barrio > arregloEmpleados[sig]->barrio){
		ant = sig;
		sig = arregloEmpleados[sig]->sigBarrio;
		pri = false;
	}
	
	arregloEmpleados[posAct]->sigBarrio = sig;
	
	if(pri){		
		cabezaInformacion[6] = posAct;
	}else{
		arregloEmpleados[ant]->sigBarrio = posAct;
	}
}

void Empleado::insertarActividad(string actividad){
	int pos_actividad;
	if(actividad == "Ingenieria"){
		pos_actividad = 0;
	}else if(actividad == "Ciencias"){
		pos_actividad = 1;
	}else if(actividad == "Artes"){
		pos_actividad = 2;
	}else{
		pos_actividad = 3;
	}

	int ant = 0; // posicion anterior a la nueva
	int sig = cabezaActividad[pos_actividad]; // posicion siguiente a la nueva

	if(sig == 0){
		cabezaActividad[pos_actividad] = posAct;
		arregloEmpleados[posAct]->sigActividad = 0;
	}else{
		while(sig != 0){
			ant = sig;
			sig = arregloEmpleados[sig]->sigActividad;
		}

		arregloEmpleados[ant]->sigActividad = posAct;
		arregloEmpleados[posAct]->sigActividad = 0;
	}

}

void Empleado::insertarSucursal(int sucursal){
	int pos_sucursal = sucursal - 1;

	int ant = 0; // posicion anterior a la nueva
	int sig = cabezaSucursales[pos_sucursal]; // posicion siguiente a la nueva
	if(sig == 0){
		cabezaSucursales[pos_sucursal] = posAct;
		arregloEmpleados[posAct]->sigSucursal = 0;
	}else{

		while(sig != 0){
			ant = sig;
			sig = arregloEmpleados[sig]->sigSucursal;
		}


		arregloEmpleados[ant]->sigSucursal = posAct;
		arregloEmpleados[posAct]->sigSucursal = 0;
	}
}

void Empleado::borrarEmpleado(int pos){

}

bool Empleado::vacia(){
	return posAct == 0;
}

bool Empleado::llena(){
	return posAct == tam;
}

#endif
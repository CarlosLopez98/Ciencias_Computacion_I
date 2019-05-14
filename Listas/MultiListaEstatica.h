#ifndef MULTILISTAESTETICA_H
#define MULTILISTAESTETICA_H

/** Libreria para multilistas dinamicas
*/

using namespace std;

struct Datos{
	char *nombre;
	char *carrera;
	char *hobby;
	int edad;
	
	int sigNombre;
	int sigCarrera;
	int sigHobby;
	int sigEdad;
};

/* orden del arreglo de cabezas
0	nombre
1	IS
2	IE
3	II
4	IC
5	Danza
6	Natacion
7	Beisbol
8	Basket
9	Edad
*/

class MultiListaEstatica{
	private:
		int *arregloCabezas;
		Datos **arregloDatos;
		int tam;
		int tamSis, tamEle, tamInd, tamCa;
		int tamDan, tamNat, tamBei, tamBas;
		int posAct;
		
		void insertarNombre(char*);
		void insertarCarrera(char*, int);
		void insertarHobby(char*, int);
		void insertarEdad(int);
	
	public:
		MultiListaEstatica(int);
		~MultiListaEstatica();
		
		bool insertarElemento(char*, char*, char*, int);
		void borrarElemento(int, int);
		bool vacia();
		bool llena();
		 obtenerElemento(int, int);
		int lenght(string);
};

MultiListaEstatica::MultiListaEstatica(int tamano=20){
	tam = tamano+1; // Se agrega una posicion de mas, para control de los datos
	tamSis = tamEle = tamInd = tamCa = tamDan = tamNat = tamBei = tamBas = 0;
	
	arregloCabezas = new int[10];
	for(int i=0; i<10; i++){
		arregloCabezas[i] = 0; // Se llena el arreglo de las cabezas con ceros
	}
		
	arregloDatos = new Datos*[tam];
	Datos *cabecera = new Datos; // nodo de control
	// Se llena el nodo(Datos) con datos de control para la insercion posterior
	char nom[] = "zz", car[] = "", hob[] = "";
	cabecera->nombre = nom;
	cabecera->carrera = car;
	cabecera->hobby = hob;
	cabecera->edad = 0;
	cabecera->sigNombre = -1;
	cabecera->sigCarrera = -1;
	cabecera->sigHobby = -1;
	cabecera->sigEdad = -1;
	
	arregloDatos[0] = cabecera; // se inserta en el arreglo
	
	posAct = 1; // inicia en 1 para empezar a insertar despues de la pos de control
}

MultiListaEstatica::~MultiListaEstatica(){
	delete []arregloCabezas;
	delete []arregloDatos;
}

void MultiListaEstatica::insertarNombre(char *nombre){
	int ant = 0; // posicion anterior a la nueva
	int sig = arregloCabezas[0]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(strcmp(nombre,arregloDatos[sig]->nombre) > 0){
		ant = sig;
		sig = arregloDatos[sig]->sigNombre;
		pri = false;
	}
	
	arregloDatos[posAct]->sigNombre = sig;
	
	if(pri){		
		arregloCabezas[0] = posAct;
	}else{
		arregloDatos[ant]->sigNombre = posAct;
	}
}

void MultiListaEstatica::insertarCarrera(char *carrera, int tipo){
	int ant = 0;
	int sig = arregloCabezas[tipo];
	
	if(sig == 0){
		arregloCabezas[tipo] = posAct;
		arregloDatos[posAct]->sigCarrera = 0;
	}else{
		while(sig != 0){
			ant = sig;
			sig = arregloDatos[sig]->sigCarrera;
		}

		arregloDatos[ant]->sigCarrera = posAct;
		arregloDatos[posAct]->sigCarrera = 0;
	}
}

void MultiListaEstatica::insertarHobby(char *hobby, int tipo){
	arregloDatos[posAct]->sigHobby = arregloCabezas[tipo];
	arregloCabezas[tipo] = posAct;
}

void MultiListaEstatica::insertarEdad(int edad){
	int ant = 0; // posicion anterior a la nueva
	int sig = arregloCabezas[9]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(edad < arregloDatos[sig]->edad){
		ant = sig;
		sig = arregloDatos[sig]->sigEdad;
		pri = false;
	}
	
	arregloDatos[posAct]->sigEdad = sig;
	
	if(pri){		
		arregloCabezas[9] = posAct;
	}else{
		arregloDatos[ant]->sigEdad = posAct; 
	}
}

bool MultiListaEstatica::insertarElemento(char *nombre, char *carrera, char *hobby, int edad){
	// Se llena la estructura con los datos
	Datos *nuevo = new Datos;
	nuevo->nombre = nombre;
	nuevo->carrera = carrera;
	nuevo->hobby = hobby; 	
	nuevo->edad = edad;
	
	if(!llena()){
		arregloDatos[posAct] = new Datos;
		arregloDatos[posAct] = nuevo;
		
		insertarNombre(nombre);
		
		int tipo;
		if(strcmp(carrera,"IS") == 0){ 
			tipo = 1;
			tamSis++;
		}
		if(strcmp(carrera,"IE") == 0){
			tipo = 2;
			tamEle++;
		}
		if(strcmp(carrera,"II") == 0){ 
			tipo = 3;
			tamInd++;
		}
		if(strcmp(carrera,"IC") == 0){ 
			tipo = 4;
			tamCa++;
		}
		insertarCarrera(carrera, tipo);
		
		if(strcmp(hobby,"Natacion") == 0){
			tipo = 6;
			tamNat++;
		}
		if(strcmp(hobby,"Danza") == 0){
			tipo = 5;
			tamDan++;
		}
		if(strcmp(hobby,"Beisbol") == 0){
			tipo = 7;
			tamBei++;
		}
		if(strcmp(hobby,"Basquet") == 0){
			tipo = 8;
			tamBas++;
		}
		insertarHobby(hobby, tipo);
		
		insertarEdad(edad);
		
		posAct++;
		return true;
	}else{
		return false;
	}
	return true;
}

void MultiListaEstatica::borrarElemento(int lista, int pos){
	/*int aux = arregloCabezas[lista];
	
	for(int i=1; i<pos && arregloDatos[aux]->sigNombre != 0; i++){
		aux = arregloDatos[aux]->sigNombre;
	}
	
	// se tiene la posicion que se va a eliminar del arreglo
	
	// se obtiene la primera posicion de cada lista
	int nombre = arregloCabezas[0];
	
	// como no se sabe a que lista de carrera y hobby pertenece el elemento se hace esto para averiguarlo
	int carrera;
	if(strcmp(arregloDatos[aux]->carrera,"IS") == 0) carrera = 1;
	if(strcmp(arregloDatos[aux]->carrera,"IE") == 0) carrera = 2;
	if(strcmp(arregloDatos[aux]->carrera,"II") == 0) carrera = 3;
	if(strcmp(arregloDatos[aux]->carrera,"IC") == 0) carrera = 4;
	carrera = arregloCabezas[carrera];
	
	int hobby;
	if(strcmp(arregloDatos[aux]->hobby,"Natacion") == 0) hobby = 6;
	if(strcmp(arregloDatos[aux]->hobby,"Danza") == 0) hobby = 5;
	if(strcmp(arregloDatos[aux]->hobby,"Beisbol") == 0) hobby = 7;
	if(strcmp(arregloDatos[aux]->hobby,"Basquet") == 0) hobby = 8;
	hobby = arregloCabezas[hobby];
	
	int edad = arregloCabezas[9];
	
	int ant = 0;
	bool pri = true;
	while(nombre != aux){
		ant = nombre;
		nombre = arregloDatos[nombre]->sigNombre;
		pri = false;
	}
	*/
}

bool MultiListaEstatica::vacia(){
	return posAct==0;
}

bool MultiListaEstatica::llena(){
	return posAct == tam;
}

/*Datos MultiListaEstatica::primero(){

}*/

char* MultiListaEstatica::obtenerElemento(int lista, int pos){
	int dato = arregloCabezas[lista];
		
	for(int i=1; i<pos ; i++){
		if(lista == 0) dato = arregloDatos[dato]->sigNombre;
		if(lista > 0 && lista < 5) dato = arregloDatos[dato]->sigCarrera;
		if(lista > 4 && lista < 9) dato = arregloDatos[dato]->sigHobby;
		if(lista == 9) dato = arregloDatos[dato]->sigEdad;
	}
	
	return arregloDatos[dato]->nombre;
}

int MultiListaEstatica::lenght(string tipo){
	if(tipo == "nombre" || tipo == "edad") return posAct-1;
	if(tipo == "sistemas") return tamSis;
	if(tipo == "electronica") return tamEle;
	if(tipo == "industrial") return tamInd;
	if(tipo == "catastral") return tamCa;
	if(tipo == "danza") return tamDan;
	if(tipo == "natacion") return tamNat;
	if(tipo == "beisbol") return tamBei;
	if(tipo == "basquet") return tamBas;
}


#endif

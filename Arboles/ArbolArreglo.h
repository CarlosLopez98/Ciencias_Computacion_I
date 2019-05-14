#ifndef ARBOLARREGLO_H
#define ARBOLARREGLO_H

#include"cola.h"
#include"pila.h"

using namespace std;

struct nodo{
	int clave;
	int der, izq;
};

class ArbolArreglo {

	private:
		int tam;
		nodo **arbol;

		cola salida;
		pila entrada;

		void eliminarNoHijos(int, int);
		void eliminarUnHijos(int, int);
		void eliminarDosHijos(int, int);

	public:
		ArbolArreglo(int);
		~ArbolArreglo();

		bool insertar(int);
		bool eliminar(int);
		void inorden();
		bool buscar(int, int);
		bool buscarEliminar(int, int&, int&);
		void rotar(int);
		bool vacio();
		bool lleno();

		// Funcion provisional para ver los datos
		void imprimir(){
			cout << "c izq der" << endl;
			for(int i=0; i<tam+1; i++){
				cout << arbol[i]->clave << " ";
				cout << arbol[i]->izq << " ";
				cout << arbol[i]->der << endl; 
			}
			cout << endl;
		}
};

ArbolArreglo::ArbolArreglo(int max){
	tam = max;
	arbol = new nodo*[tam+1];

	for(int i=0; i<tam+1; i++){
		arbol[i] = new nodo;

		arbol[i]->clave = 0;
		arbol[i]->izq = 0;
		if(i != tam){
			arbol[i]->der = i+1;
		}else{
			arbol[i]->der = 0;
		}
	}
}

ArbolArreglo::~ArbolArreglo(){
	for(int i=0; i<tam+1; i++){
		delete arbol[i];
	}
	delete arbol;
}

bool ArbolArreglo::insertar(int v){
	int pos;
	pos = arbol[0]->der;

	if(!lleno()){
		arbol[pos]->clave = v; // valor a la nuevo pos
		arbol[0]->der = arbol[pos]->der; // se copia la posicion vacia al nodo 0
		arbol[pos]->der = 0; // se deja la derecha e izquierda igual a 0
		arbol[pos]->izq = 0;

		int aux_act = 0;
		int aux_sig = arbol[0]->izq;
		int lado = 1; // 1 izq, 0 der

		while(aux_sig != 0){
			aux_act = aux_sig;
			if(v < arbol[aux_sig]->clave){
				aux_sig = arbol[aux_sig]->izq;
				lado = 1;
			}else{
				aux_sig = arbol[aux_sig]->der;
				lado = 0;
			}
		}

		if(lado){
			arbol[aux_act]->izq = pos;
		}else{
			arbol[aux_act]->der = pos;
		}

		return true;

	}else{
		return false;
	}
}

void ArbolArreglo::inorden(){

}

bool ArbolArreglo::buscarEliminar(int dato, int& padre, int& hijo){
	if(hijo == 0) hijo = arbol[0]->izq;

	if(arbol[hijo]->clave == dato){
		return true;
	}else{
		if(dato < arbol[hijo]->clave && arbol[hijo]->izq != 0){
			padre = hijo;
			hijo = arbol[hijo]->izq;
			return buscarEliminar(dato, padre, hijo);
		}else if(dato > arbol[hijo]->clave && arbol[hijo]->der != 0){
			padre = hijo;
			hijo = arbol[hijo]->der;
			return buscarEliminar(dato, padre, hijo);
		}
	}
	return false;
}

bool ArbolArreglo::eliminar(int clave){
	int padre = 0;
	int hijo = arbol[0]->izq;

	if(buscarEliminar(clave, padre, hijo)){
		if(arbol[hijo]->der == 0 && arbol[hijo]->izq == 0){
			eliminarNoHijos(padre, hijo);
			return true;
		}
		if(arbol[hijo]->der != 0 && arbol[hijo]->izq != 0){
			eliminarDosHijos(padre, hijo);
			return true;
		}
		if(arbol[hijo]->der != 0 || arbol[hijo]->izq != 0){
			eliminarUnHijos(padre, hijo);
			return true;
		}
	}	

	return false;

}

void ArbolArreglo::eliminarNoHijos(int padre, int hijo){
	if(arbol[padre]->izq == hijo){
		arbol[padre]->izq = 0;
	}else{
		arbol[padre]->der = 0;
	}

	arbol[hijo]->der = arbol[0]->der;
	arbol[0]->der = hijo;

	arbol[hijo]->clave = 0;
}

void ArbolArreglo::eliminarUnHijos(int padre, int hijo){
	if(arbol[padre]->izq == hijo){
		if(arbol[hijo]->izq != 0){
			arbol[padre]->izq = arbol[hijo]->izq;
		}else{
			arbol[padre]->izq = arbol[hijo]->der;
		}		
	}else{
		if(arbol[hijo]->izq != 0){
			arbol[padre]->der = arbol[hijo]->izq;
		}else{
			arbol[padre]->der = arbol[hijo]->der;
		}
	}
	
	arbol[hijo]->der = arbol[0]->der;
	arbol[0]->der = hijo;

	arbol[hijo]->clave = 0;
}

void ArbolArreglo::eliminarDosHijos(int padre, int hijo){
	int padre_r = hijo;
	int hijo_r = arbol[hijo]->der; // derecha mas a la izquierda

	while(arbol[hijo_r]->izq != 0){
		padre_r = hijo_r;
		hijo_r = arbol[hijo_r]->izq;
	}

	// Criterio de hijos
	if(arbol[hijo_r]->der == 0 && arbol[hijo_r]->izq == 0){
		if(arbol[padre_r]->izq == hijo_r){
			arbol[padre_r]->izq = 0;
		}else{
			arbol[padre_r]->der = 0;
		}
	}
	if(arbol[hijo_r]->der != 0){
		if(arbol[padre_r]->izq == hijo_r){
			arbol[padre_r]->izq = arbol[hijo_r]->der;
		}else{
			arbol[padre_r]->der = arbol[hijo_r]->der;
		}
	}

	// Padre conecta con reemplazo
	if(arbol[padre]->izq == hijo){
		arbol[padre]->izq = hijo_r;
	}else{
		arbol[padre]->der = hijo_r;
	}

	// Nodo reemplazo copiar hijos del borrado
	arbol[hijo_r]->izq = arbol[hijo]->izq;
	arbol[hijo_r]->der = arbol[hijo]->der;

	// nodo borrado a la lista de libres
	arbol[hijo]->der = arbol[0]->der;
	arbol[0]->der = hijo;

	arbol[hijo]->clave = 0;

}



bool ArbolArreglo::buscar(int dato, int pos=0){
	if(pos == 0) pos = arbol[0]->izq;

	if(arbol[pos]->clave == dato){
		return true;
	}else{
		if(dato < arbol[pos]->clave && arbol[pos]->izq != 0){
			return buscar(dato, arbol[pos]->izq);
		}else if(dato > arbol[pos]->clave && arbol[pos]->der != 0){
			return buscar(dato, arbol[pos]->der);
		}
	}

	return false;
}

void ArbolArreglo::rotar(int pos){
	
}

bool ArbolArreglo::vacio(){
	return arbol[0]->izq == 0;
}

bool ArbolArreglo::lleno(){
	return arbol[0]->der == 0;
}

#endif
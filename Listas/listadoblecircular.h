#ifndef LISTADOBLECIRCULAR_H
#define LISTADOBLECIRCULAR_H

template <class T>
struct nodo{
	T info;
	nodo<T> *ant, *sig;
};

template <class T>
class ListaDobleCircular{
	private:
		nodo<T> *cab;
		//nodo<T> *cola;
		int tam;

	public:
		ListaDobleCircular();
		~ListaDobleCircular();

		bool lista_vacia();
		int lenght();
		void insertar_pos(T, int);
		T eliminar_pos(int);
		T revisar_pos(int);
		T revisar_ant(int);
		T revisar_sig(int);
};

template <class T>
ListaDobleCircular<T>::ListaDobleCircular(){
	cab = new nodo<T>;
	//cola = new nodo<T>;
	
	cab->ant = cab;
	cab->sig = cab;

	//cola->ant = cab;
	//cola->sig = NULL;

	tam = 0;
}

template <class T>
ListaDobleCircular<T>::~ListaDobleCircular(){
	delete cab;
	//delete cola;
}

template <class T>
bool ListaDobleCircular<T>::lista_vacia(){
	return (cab->sig == cab);
}

template <class T>
int ListaDobleCircular<T>::lenght(){
	return tam;
}

template <class T>
void ListaDobleCircular<T>::insertar_pos(T dato, int pos){
	// Se crea nuevo nodo a insertar
	nodo<T> *nuevo = new nodo<T>;
	nuevo->info = dato;
	
	// Nodo auxiliar para recorrer la lista
	nodo<T> *aux = cab;
	for(int i=1; i<pos && aux->sig != cab; i++){
		// Si el siguiente de auxiliar es la cabeza quiere decir llego al final
		// por lo tanto aux queda en la posicion del ultimo elemento
		aux = aux->sig;
	}
	
	nuevo->sig = aux->sig;
	aux->sig->ant = nuevo;
	aux->sig = nuevo;
	nuevo->ant = aux;
	
	tam++;
}

template <class T>
T ListaDobleCircular<T>::eliminar_pos(int pos){
	T dato;
	// Nodo auxiliar para recorrer la lista
	nodo<T> *aux = cab;
	
	for(int i=1; i<=pos && aux->sig != cab; i++){
		aux = aux->sig;
	}
	
	aux->ant->sig = aux->sig;
	aux->sig->ant = aux->ant;
	
	// Se retorna el dato que tenia el nodo borrado
	dato = aux->info;
	
	delete aux;
	tam--;
	return dato;
}

template <class T>
T ListaDobleCircular<T>::revisar_pos(int pos){
	// Nodo auxiliar para recorrer la lista
	nodo<T> *aux = cab;
	
	for(int i=1; i<=pos && aux->sig != cab; i++){
		aux = aux->sig;
	}
	
	return aux->info;
}

template <class T>
T ListaDobleCircular<T>::revisar_ant(int pos){
	nodo<T> *aux = cab->sig;
	
	if(pos==1)
		return aux->ant->ant->info;

	for(int i=1; i<pos && aux->sig != cab; i++){
		aux = aux->sig;
	}

	return aux->ant->info;

}



template <class T>

T ListaDobleCircular<T>::revisar_sig(int pos){
	nodo<T> *aux = cab->sig;

	for(int i=1; i<pos && aux!=NULL; i++){
		aux = aux->sig;
	}

	if(pos==tam)
		return aux->sig->sig->info;
	else
		return aux->sig->info;

}

#endif

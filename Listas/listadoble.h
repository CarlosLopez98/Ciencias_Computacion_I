#ifndef LISTADOBLE_H
#define LISTADOBLE_H

template<class T>
struct nodo{
	T info;
	nodo<T> *ant, *sig;	
};

template<class T>

class ListaDoble{
	private:
		nodo<T> *cab;
		nodo<T> *z;
		int tam;
	
	public:
		ListaDoble();
		~ListaDoble();
		
		bool lista_vacia();
		int lenght();
		void insertar_pos(T, int);
		T eliminar_pos(int);
		T revisar_pos(int);
		T revisar_ant(int);
		T revisar_sig(int);	
};


template <class T>
ListaDoble<T>::ListaDoble(){
	// Se crean los nodos cabeza y cola
	cab = new nodo<T>;
	z = new nodo<T>;
	
	cab->ant = NULL;
	cab->sig = z;
	
	z->ant = cab;
	z->sig = NULL;
	
	tam = 0;
}

template<class T>
ListaDoble<T>::~ListaDoble(){
	delete cab;
	delete z;
}

template<class T>
bool ListaDoble<T>::lista_vacia(){
	return (cab->sig == z);		
}

template <class T>
int ListaDoble<T>::lenght(){
	return tam;
}

template<class T>
void ListaDoble<T>::insertar_pos(T dato, int pos){
	nodo<T> *nuevo = new nodo<T>;
	nuevo->info = dato;
	
	nodo<T> *aux = cab;
	
	for(int i=1; i<pos && aux->sig != z; i++){
		aux = aux->sig;
	}
	
	nuevo->sig = aux->sig;
	aux->sig->ant = nuevo;
	aux->sig = nuevo;
	nuevo->ant = aux;
	
	tam++;	
}

template<class T>
T ListaDoble<T>::eliminar_pos(int pos){
	T dato;
	// Nodo auxiliar para recorrer la lista
	nodo<T> *aux = cab;
	
	for(int i=1; i<=pos && aux->sig != z; i++){
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

template<class T>
T ListaDoble<T>::revisar_pos(int pos){
	nodo<T> *aux = cab->sig;
	
	for(int i=1; i<pos && aux->sig != z; i++){
		aux = aux->sig;
	}
	
	return aux->info;
}

template <class T>
T ListaDoble<T>::revisar_ant(int pos){
	nodo<T> *aux = cab->sig;
	
	for(int i=1; i<pos && aux != z; i++){
		aux = aux->sig;
	}
	
	return aux->ant->info;
}


template <class T>
T ListaDoble<T>::revisar_sig(int pos){
	nodo<T> *aux = cab;
	
	for(int i=1; i<=pos && aux != z; i++){
		aux = aux->sig;
	}
	
	return aux->sig->info;
}

#endif

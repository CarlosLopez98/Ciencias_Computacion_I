#ifndef LISTADINAMICA_H
#define LISTADINAMICA_H

template<class T>
struct nodo{
	T dato;
	nodo<T> *sig;
};

template<class T>
class ListaDinamica{

	private:
		nodo<T> *cab;
		nodo<T> *fin;
		int tam;

	public:
		ListaDinamica(T datoAux){
			// cabecera
			cab = new nodo<T>;
			cab->dato = datoAux;
			cab->sig = NULL;
			fin = cab;
			tam = 0;
		}

		~ListaDinamica(){
			delete cab;
			delete fin;
		}

		bool listaVacia(){
			if(cab->sig == NULL){
				return true;
			}else{
				return false;
			}
		}

		bool insertar(T dato){
			// se crea el nuevo nodo a agregar
			nodo<T> *nuevo;
			nuevo = new nodo<T>;
			nuevo->dato = dato;
			nuevo->sig = NULL;
			
			// se agrega al final de la lista
			fin->sig = nuevo;
			fin = nuevo;

			tam++;
			return true;
		}
		
		bool insertar(T dato, int pos){
			// se crea el nuevo nodo a agregar
			nodo<T> *nuevo = new nodo<T>;
			nuevo->dato = dato;
			nuevo->sig = NULL;
			
			nodo<T> *ant = cab;
			nodo<T> *sig = cab->sig;
			
			for(int i=1; i<pos && sig != NULL; i++){
				ant = ant->sig;
				sig = ant->sig;
			}
			if(pos < 1 || pos > tam+1){
				return false;
			}else{
				ant->sig = nuevo;
				nuevo->sig = sig;
				
				tam++;
				return true;
			}
		}
		
		bool borrar(int pos){
			// se crean nodo anterior y siguiente que empiezan en la cabecera y su siguiente
			nodo<T> *ant = cab;
			nodo<T> *sig = cab->sig;
			
			// recorre la lista hasta que sig es el nodo a borrar	
			for(int i=1; i<pos && sig != NULL; i++){
				ant = ant->sig;
				sig = ant->sig;
			}
				
			if(sig == NULL || pos < 1){
				// si sig es nulo no borra nada
				return false;
			}else{
				ant->sig = sig->sig;
				delete sig;
				tam--;
				return true;
			}
		}
		
		bool borrar_ant(int pos){
			pos--;
			borrar(pos);
		}
		
		T retornar(int pos){
			nodo<T> *aux = cab;
			
			for(int i=1; i<=pos && aux->sig != NULL; i++){
				aux = aux->sig;	
			}
			
			// si la lista esta vacia, retorna el dato auxiliar de la cabecera
			// si la posicion esta fuera de rango, retorna el ultimo dato de la lista
			return aux->dato;
		}
		
		int lenght(){
			return tam;
		}
};

#endif

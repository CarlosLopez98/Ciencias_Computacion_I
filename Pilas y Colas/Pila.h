using namespace std;

template<class T>
class Pila {
	private:
		struct nodo {
			T clave;
			struct nodo *siguiente;
		};
		struct nodo *cabeza, *z;

	public:
		Pila();
		~Pila();

		void meter(char V);
		T sacar();
		int vacia();

};

template<class T>
Pila<T>::Pila(){
	cabeza = new nodo;
	z = new nodo;
	cabeza->siguiente = z;
	z->siguiente = z;
}

template<class T>
Pila<T>::~Pila(){
	struct nodo *t = cabeza;
	while(t != z){
		cabeza = t;
		t = t->siguiente;
		delete cabeza;
	}
}

template<class T>
void Pila<T>::meter(char v){
	struct nodo *t = new nodo;
	t->clave = v;
	t->siguiente = cabeza->siguiente;
	cabeza->siguiente = t;
}

template<class T>
T Pila<T>::sacar(){
	T x;
	struct nodo *t = cabeza->siguiente;
	cabeza->siguiente = t->siguiente;
	x = t->clave;
	delete t;
	return x;
}

template<class T>
int Pila<T>::vacia(){
	return cabeza->siguiente == z;
}

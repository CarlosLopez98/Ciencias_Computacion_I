#ifndef LISTA_H
#define LISTA_H

template<class T>

class Lista{
	private:
		int tam, posAct;
		T *arr;
	
	public:
		Lista(int tamano=20){
			tam = tamano;
			arr = new T[tam];
			posAct = 0;
		}
		
		~Lista(){
			delete []arr;
		}
		
		bool listaLlena(){
			if(posAct > tam){
				return true;
			}else{
				return false;
			}
		}	
		
		bool listaVacia(){
			if(posAct == 0){
				return true;
			}else{
				return false;
			}
		}
		
		bool insertar(T dato){
			if(!listaLlena()){
				arr[posAct] = dato;
				posAct++;
				return true;
			}else{
				return false;
			}
		}
		
		T retornar(int pos){
			if(pos < posAct){
				return arr[pos];
			}else{
				return arr[posAct];
			}
		}
		
		T borrarPos(int pos){
			T aux = arr[pos];
			while(pos < posAct-1){
				arr[pos] = arr[pos+1];
				pos++;
			}
			posAct--;
			return aux;
		}
};
#endif

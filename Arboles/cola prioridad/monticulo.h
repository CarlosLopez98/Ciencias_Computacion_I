#ifndef MONTICULO_H
#define MONTICULO_H

#include<iostream>
using namespace std;

class Monticulo {

	private:
		int tam;
		int pos_act;
		int *cola;

	public:
		Monticulo(int);
		~Monticulo();

		bool insertar(int);
		int atender();
		bool vacio();
		bool lleno();
		void imprimir();
};

Monticulo::Monticulo(int max=20){
	tam = max;
	pos_act = 0;
	cola = new int[tam];
}

Monticulo::~Monticulo(){
	delete cola;
}

bool Monticulo::insertar(int dato){
	if(!lleno()){
		pos_act++;
		int padre = pos_act/2,
			hijo = pos_act,
			aux;
			cola[pos_act] = dato;
		while (padre!=0 && dato > cola[padre]){
			aux = cola[padre];
			cola[padre] = cola [hijo];
			cola[hijo] = aux;
			hijo = padre;
			padre /= 2;
		}
	return true;
	}
	return false;
}

int Monticulo::atender(){
	int atendido = cola[1];

	cola[1] = cola[pos_act];
	pos_act--;

	int pos = 1, aux, hijo1, hijo2, mayor;
	do{
		hijo1 = 2*pos;
		hijo2 = 2*pos+1;

		if(cola[hijo1] > cola[hijo2]){
			mayor = hijo1;
		}else{
			mayor = hijo2;
		}

		if(cola[pos] < cola[mayor]){
			aux = cola[pos];
			cola[pos] = cola[mayor];
			cola[mayor] = aux; 
		}

		pos = mayor;

	}while(hijo1 <= pos_act || hijo2 <= pos_act);

	return atendido; 
}

bool Monticulo::lleno(){
	return tam == pos_act;
}

void Monticulo::imprimir(){
	for (int i = 1; i <= pos_act ; ++i){
		cout<<cola[i]<< " ";
	};
	cout << endl;
}

#endif
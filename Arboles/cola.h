#include <cstdlib>
#include <iostream>
#include "estructura.h"

#ifndef COLA_H
#define COLA_H

using namespace std;

class cola{
	nodo1 *cab,*fin;

    public:
		cola(){
			cab=fin=NULL;
		}
	    void InsCola(char i);
	    char AtenderCola();
	    void ImprimirCola();
		bool ColaVacia();
	    ~cola();
 };

void cola::InsCola(char i){
     nodo1 *nuevo;
     nuevo= new nodo1;
     nuevo->dato=i;
     nuevo->sig= NULL;
     if (cab==NULL){
		 cab=nuevo;
	 }else{
		 fin->sig = nuevo;
	 }
     fin=nuevo;
}

char cola::AtenderCola(){
	char x;
    nodo1 *aux = cab;
    cab=aux->sig;
    x=aux->dato;
    delete aux;
    return x;
}

void cola::ImprimirCola(){
	nodo1 *aux;
	aux=cab;
	while(aux!=NULL){
		cout<<aux->dato<<" ";
		aux=aux->sig;
	}
}

bool cola::ColaVacia(){
	return (cab==NULL);
}

cola::~cola(){
	nodo1 *aux;
	while(cab!=NULL){
		aux= cab;
		cab=aux->sig;
		delete aux;
	}
	delete cab;
}

#endif

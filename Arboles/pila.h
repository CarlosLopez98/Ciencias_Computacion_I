#ifndef PILA_H
#define PILA_H
#include "estructura.h"

class pila{
    nodo1 *cab;

    public:
        pila(){
            cab= new nodo1;
            cab->dato=' ';
            cab->sig=NULL;
        }
        void Push(char v);
        char Pop();
        bool PilaVacia();
        ~pila();
};

void pila::Push(char v){
    nodo1 *t = new nodo1;
    t->dato=v;
    t->sig=cab->sig;
    cab->sig= t;
}

char pila::Pop(){
    char x;
    nodo1 *t= cab->sig;
    cab->sig= t->sig;
    x=t->dato;
    delete t;
    return x;
}

bool pila::PilaVacia(){
    return cab->sig== NULL;
}

pila::~pila(){
    nodo1 *t=cab;
    while (t!=NULL){
        cab=t;
        t=t->sig;
        delete cab;
    }
}

#endif

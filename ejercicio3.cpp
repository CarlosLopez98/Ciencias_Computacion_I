#include<iostream>
#include<cstdlib>

using namespace std;

struct nodo{
	int x, y;
	nodo *sig;
};

int main(){
	int n, i;
	nodo *cab = NULL, *aux;
	
	cin >> n;
	
	int cont = 0;
	
	cont += sizeof(n);
	cont += sizeof(i);
	cont += sizeof(cab);
	cont += sizeof(aux);
	
	for(i=0; i<n; i++){
		aux = new nodo;
		aux->x = i;
		aux->y = n-i;
		aux->sig = cab;
		
		cont += sizeof(aux->x);
		cont += sizeof(aux->y);
		cont += sizeof(aux->sig);
		
		cab = aux;
	}
	
	//while(aux != NULL){
	//	cout << aux->x << " " << aux->y << endl;
	//	aux = aux->sig;
	//}
	
	for(aux=cab->sig; aux!=NULL; aux=aux->sig){
		delete cab;
		cab = aux;
	}
	delete cab;
	
	cout << cont << endl;
	
	return 0;
}


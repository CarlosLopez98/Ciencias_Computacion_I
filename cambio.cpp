#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void devolverCambio(int, int*);
void imprimir(int*);

unsigned t0, t1;

int main(){
	int n, *s;
	s = new int[24];
	
	cout << "Introduzca la cantidad: " << endl;
	cin >> n;
	
	t0 = clock();
	
	devolverCambio(n, s);
	imprimir(s);
	
	t1 = clock();
	
	double time = (double(t1 - t0) / CLK_TCK);
	cout << "Tiempo de ejecucion: " << time << endl;
	
	delete s;
	return 0;
}

void devolverCambio(int n, int *s){
	int c[] = {1000, 500, 200, 100, 50, 10};//Candidatos
	int z = 0;//Suma de los elementos de S
	int x;
	int cont = 0;
	
	for(int i=0; i<24; i++){
		s[i] = 0;
	}
	
	for(int i=0; i<6; i++){
		x = c[i];
		while(z + x <= n){
			s[cont] = x;
			z += x;
			cont++;
		}
	}
	if(z != n){
		s[0] = 0;	
	}
}

void imprimir(int *s){
	if(s[0] == 0){
		cout << "No hay solucion..." << endl;
	}else{
		cout << "Su cambio es: " << endl;
		for(int i=0; i<24; i++){
			if(s[i] != 0){
				cout << s[i] << " ";
			}
		}
	}
	cout << endl;
}

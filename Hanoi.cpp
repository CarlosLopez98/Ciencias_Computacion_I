#include<iostream>
#include<cstdlib>
#include<fstream>
#include<windows.h>

using namespace std;

// Prototipos
void Mover_Torres(int, int, int, int);
double performancecounter_diff(LARGE_INTEGER*, LARGE_INTEGER*);

int main(){
	int Discos;
	ofstream archivo;
	LARGE_INTEGER iniTime, endTime;
	
	archivo.open("Hanoi.txt",ios::out);
	
	for(int j=1; j<=64; j++){
		Discos = j;
		
		// Codigo a medir
		QueryPerformanceCounter(&iniTime);
		
		Mover_Torres( Discos, 1, 2, 3);
		
		QueryPerformanceCounter(&endTime);
		//
		
		cout << j << ": " << performancecounter_diff(&endTime, &iniTime) << " segundos" << endl;
		archivo << j << ": " << performancecounter_diff(&endTime, &iniTime) << " segundos" << endl;
	}
	
	archivo.close();
	
	return 0;
}

void Mover_Torres(int N, int Origen, int Intermedio, int Destino){ 
	if ( N > 1 ){
		Mover_Torres( N - 1, Origen, Destino, Intermedio);
		
		//cout <<"\nMueve el disco " <<  N  << " de " << Origen << " a " <<  Destino << endl;
		Mover_Torres( N - 1, Intermedio, Origen, Destino);
	}
	
	// El caso limite mas sencillo se resuelve directamente
	
	//if ( 1 == N )
	//cout << "\nMueve el disco 1 de " << Origen << " a " << Destino << endl;

}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}

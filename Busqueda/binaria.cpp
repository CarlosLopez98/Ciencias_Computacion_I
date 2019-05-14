#include<iostream>
#include<cstdlib>
#include<windows.h>

using namespace std;

// Prototipos
bool binaria(int*, int, int);
double performancecounter_diff(LARGE_INTEGER*, LARGE_INTEGER*);

int main(){
	
	int n, *a, b;
	LARGE_INTEGER iniTime, endTime;
	
	for(int j=10; j<=500; j+=10){
		n = j;
		
		a =  new int[n];
		
		for(int i=0; i<n; i++){
			a[i] = i+1;
		}
		
		b = n;
		
		QueryPerformanceCounter(&iniTime);
		
		// Codigo
		binaria(a, n, b);
		
		QueryPerformanceCounter(&endTime);
		 
		cout << j << ": " << performancecounter_diff(&endTime, &iniTime) << " segundos" << endl;
		
		delete []a;
	}
	
	return 0;
}

bool binaria(int *a, int n, int b){
	int mitad, inicio, fin;
	bool encontrado = false;
	
	inicio = 0;
	fin = n-1;
	
	while(inicio <= fin && !encontrado){
		mitad = (inicio + fin) / 2;
		if(a[mitad] == b){
			encontrado = true;
		}else{
			if(b < a[mitad]){
				fin = mitad - 1;	
			}else{
				inicio = mitad + 1;
			}
		}	
	}
	
	return encontrado;
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}

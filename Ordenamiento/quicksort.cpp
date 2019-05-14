#include<iostream>
#include<cstdlib>
#include<windows.h>

using namespace std;

// Prototipo
void intercambio(int*, int, int);
void quicksort(int*, int, int);
double performancecounter_diff(LARGE_INTEGER*, LARGE_INTEGER*);

int main(){
	int n, *a, i, j;
	LARGE_INTEGER iniTime, endTime;
	
	for(j=10; j<=500; j+=10){
		n = j;
	
		a = new int[n];
	
		for(i=0; i<n; i++){
			a[i] = n - i;
		}
		
		//Codigo a medir
		QueryPerformanceCounter(&iniTime);
		
		quicksort(a, 0, n-1);
		
		QueryPerformanceCounter(&endTime);
		//
		
		cout << i << ": " << performancecounter_diff(&endTime, &iniTime) << " Segundos" << endl;
		
		delete []a;
	}

	return 0;
}

void intercambio(int *a, int i, int j){
	int aux;
	aux = a[i];
	a[i] = a[j];
	a[j] = aux;
}

void quicksort(int *a, int izq, int der){
	int i, j, v;
	if(der > izq){
		v = a[der];
		i = izq - 1;
		j = der;
		for(;;){
			while(a[++i] < v);
			while(a[--j] > v);
			if(i >= j) break;
			intercambio(a, i, j); 
		}
		intercambio(a, i, der);
		quicksort(a, izq, i-1);
		quicksort(a, i+1, der);
	}
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}

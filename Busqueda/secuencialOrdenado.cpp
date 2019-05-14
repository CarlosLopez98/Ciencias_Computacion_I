#include<iostream>
#include<cstdlib>
#include<windows.h>

using namespace std;

// Prototipos
bool secuencial(int*, int, int);
double performancecounter_diff(LARGE_INTEGER*, LARGE_INTEGER*);

int main(){
	
	int n, *a, b;
	LARGE_INTEGER iniTime, endTime;
	
	for(int j=10; j<=500; j+=10){
		n = j;
		
		a = new int[n];
		
		for(int i=0; i<n; i++){
			// Llenado del arreglo en orden
			a[i] = i+1;
		}
		b = a[n-1]+1;
		
		QueryPerformanceCounter(&iniTime);
		
		// Codigo
		secuencial(a, n, b);
		
		QueryPerformanceCounter(&endTime);
		
		cout << j << ": " << performancecounter_diff(&endTime, &iniTime) << " segundos" << endl;
		
		delete []a;
	}
	
	return 0;
}

bool secuencial(int *a, int n, int b){
	int i;
	for(i=0; i<n; i++){
		if(a[i] == b) return true;
		if(a[i] > b) return false;
	}
	return false;
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}

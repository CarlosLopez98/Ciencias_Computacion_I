#include<iostream>
#include<cstdlib>
#include<windows.h>

using namespace std;

// Prototipos
void ordenshell(int*, int);
double performancecounter_diff(LARGE_INTEGER*, LARGE_INTEGER*);

int main(){
	
	int n, *a, i;
	LARGE_INTEGER iniTime, endTime;
	
	for(int j=50; j<=500; j+=10){
		n = j;
		a = new int[n];
		
		for(i=0; i<n; i++){
			a[i] = n-i;
		}
			
		QueryPerformanceCounter(&iniTime);
		
		ordenshell(a, n);
		
		QueryPerformanceCounter(&endTime);
		
		cout << n << ": " << performancecounter_diff(&endTime, &iniTime) << " Segundos" << endl;
		
		delete []a;
	}
	
	return 0;
}

void ordenshell(int *a, int n){
	int i, j, h, v;
	
	for(h=1; h<=n/9; h=3*h+1);
	for(; h>0; h/=3)
	for(i=h; i<n; i++){
		v = a[i];
		j = i;
		while(j >= h && a[j-h] > v){
			a[j] = a[j-h];
			j -= h;
		}
		a[j] = v;
	}
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}

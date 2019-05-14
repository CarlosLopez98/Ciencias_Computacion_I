#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>

using namespace std;

// Prototipos
void multiplicar(int**, int**, int**, int);
double performancecounter_diff(LARGE_INTEGER*, LARGE_INTEGER*);

int main(){
	int n, **a, **b, **c;
	int i, j, k;
	LARGE_INTEGER iniTime, endTime;
	
	srand(time(NULL));
	
	for(k=2; k<=100; k+=2){
		n = k;
		
		a = new int *[n];
		b = new int *[n];
		c = new int *[n];
		for(i=0; i<n; i++){
			a[i] = new int[n];
			b[i] = new int[n];
			c[i] = new int[n];
			for(j=0; j<n; j++){
				a[i][j] = rand()%10;
				b[i][j] = rand()%10;
			}
		}
		
		// Codigo a medir
		QueryPerformanceCounter(&iniTime);
		
		multiplicar(a, b, c, n);
		
		QueryPerformanceCounter(&endTime);
		//
		
		cout << k << ": " << performancecounter_diff(&endTime, &iniTime) << " Segundos" << endl;
		
		for(i=0; i<n; i++){
			delete a[i];
			delete b[i];
			delete c[i];
		}
		delete []a;
		delete []b;
		delete []c;
	}
	
	return 0;
}

void multiplicar(int **a, int **b, int **c, int n){
	int i, j, k;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			c[i][j] = 0;
			for(k=0; k<n; k++){
				c[i][j] += a[i][k] * b[k][j];
			}	
		}
	}
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}

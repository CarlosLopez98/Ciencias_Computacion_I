#include<iostream>
#include<cstdlib>
#include<windows.h>

using namespace std;

// Prototipos
void mergesort(int*, int, int);
void mergelist(int*, int, int, int, int);
double performancecounter_diff(LARGE_INTEGER*, LARGE_INTEGER*);

int main(){
	
	int n, *a, i, j;
	LARGE_INTEGER iniTime, endTime;
	
	for(j=10; j<=500; j+=10){
		n = j;
		
		a = new int[n];
		
		for(i=0; i<n; i++){
			a[i] = n-1;
		}
		
		// Codigo a medir
		QueryPerformanceCounter(&iniTime);
	
		mergesort(a, 0, n-1);
		
		QueryPerformanceCounter(&endTime);	
		//
		
		cout << j << ": " << performancecounter_diff(&endTime, &iniTime) << " segundos" << endl;
		
		delete []a;
	}
	
	return 0;
}

void mergesort(int* lista, int first, int last){
	int middle;
	if(first < last){
		middle = (first + last) / 2;
		mergesort(lista, first, middle);
		mergesort(lista, middle+1, last);
		mergelist(lista, first, middle, middle+1, last);
	}
}

void mergelist(int* lista, int start1, int end1, int start2, int end2){
		int finalStart, finalEnd, indexC, *result, i;
		finalStart = start1;
		finalEnd = end2;
		indexC = 1;
		result = new int[end2];
		while(start1 <= end1 && start2 <= end2){
			if(lista[start1] < lista[start2]){
				result[indexC] = lista[start1];
				start1++;
			}else{
				result[indexC] = lista[start2];
				start2++;
			}
			indexC++;
		}
		
		if(start1 <= end1){
			for(i=start1; i<=end1; i++){
				result[indexC] = lista[i];
				indexC++;
			}
		}else{
			for(i=start2; i<=end2; i++){
				result[indexC] = lista[i];
				indexC++;
			}
		}
		
		indexC = 1;
		for(i=finalStart; i<=finalEnd; i++){
			lista[i] = result[indexC];
			indexC++;
		}
		
		delete []result;
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}


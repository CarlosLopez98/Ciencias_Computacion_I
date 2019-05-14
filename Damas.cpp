#include<cstdlib>
#include<iostream>
#include<fstream>
#include<windows.h>

using namespace std;

int DIMENSION = 4;

// Prototipos
bool colocarReina (int **t, int fila);
void imprimir(int **lab);
bool amenazada(int **t, int fila, int columna);
double performancecounter_diff(LARGE_INTEGER*, LARGE_INTEGER*);


int main(int argc, char *argv[]){
	int **t, i, j, k;
	ofstream archivo;
	LARGE_INTEGER iniTime, endTime;
	
	archivo.open("tiempos.txt",ios::out);
	
	for(k=4; k<=50; k++){
		DIMENSION = k;
		t= new int*[DIMENSION];
	 	for (i=0; i< DIMENSION; i++){
	      	t[i]= new int[DIMENSION];
	      	for(j=0; j<DIMENSION; j++)
	      		t[i][j] = 0;
		}
		
		QueryPerformanceCounter(&iniTime);
		
		colocarReina(t,0);
		
		QueryPerformanceCounter(&endTime);
		
		cout << DIMENSION << ": " << performancecounter_diff(&endTime, &iniTime) << " segundos" << endl;
		archivo << DIMENSION << ": " << performancecounter_diff(&endTime, &iniTime) << " segundos" << endl;
		
		//imprimir(t);
		
		for(i=0; i<DIMENSION; i++){
			delete t[i];
		}
		delete []t;
	}
	
	archivo.close();
	
	system("PAUSE");
	return EXIT_SUCCESS;
}

bool colocarReina (int **t, int fila){
	bool tmp;
	if(fila == DIMENSION){
		//cout<< "soluci\ufffdn encontrada \n";
    	//imprimir(t);
    	return true;
	}

	for(int columna=0; columna<DIMENSION; columna++){  
		if (!amenazada(t, fila, columna)){
			t[fila][columna]= fila + 1; // reina i-esima
			tmp= colocarReina(t, fila+1);
			if (tmp==true) return true;
			//borra soluci\ufffdn invalida
	    	t[fila][columna]=0;
    	}
 	}
 	return false;
}

void imprimir(int **lab){
	for (int i =0; i<DIMENSION; i++){
		for (int j =0; j<DIMENSION; j++)
        	cout << lab[i][j] << " ";
     	cout<<endl;
	}
}

bool amenazada(int **t, int fila, int columna){
	int i,f,c;
	// revisa fila y columna
	for (i=0; i< DIMENSION; i++){
		if(t[fila][i] != 0 || t[i][columna] !=0) return true;
	}

	// arriba a la izquierda  
 	for (f=fila, c=columna; f>=0&& c>=0; f--,c--){
	 	if(t[f][c] !=0 ) return true;
 	}  
	//arriba a la derecha
 	for (f=fila, c=columna; f>=0&& c<DIMENSION; f--,c++) {
		if(t[f][c]!=0) return true; 
 	}
 	//abajo a la izquierda
 	for (f=fila, c=columna; f<DIMENSION&& c>=0; f++,c--){
		if(t[f][c]!=0) return true;
	}
	//abajo derecha
	for (f=fila, c=columna; f<DIMENSION&& c<DIMENSION; f++,c++){
		if(t[f][c]!=0) return true;
	}

	return false;
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}

#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

// Prototipos
void escribir();

int main(){
	escribir();
	
	return 0;
}

void escribir(){
	ofstream archivo;
	
	archivo.open("prueba.txt", ios::out);
	
	if(archivo.fail()){
		cout << "No se pudo abrir el archivo" << endl;
		exit(1);
	}
	
	archivo << "Hola mundo";
	
	archivo.close();
}


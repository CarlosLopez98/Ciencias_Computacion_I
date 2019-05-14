#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct nodo{
	string nombre;
	int edad;
	float salario;
};

int main(int argc, char *argv[]){
	int edad,j,i=0;
	float salario;
	string nombre;
	nodo arr[10];

	ifstream archEntrada("empleados.txt", ios::in);
	ofstream archsalida1("nuevoSalario.txt",ios::out|ios::trunc);

	if(!archEntrada.good()){
		cerr << "No se pudo abrir el archivo empleados" << endl;
		exit(1);
	}
	if(!archsalida1.good()){
		cerr << "No se pudo abrir el archivo nuevo salario" << endl;
		exit(1);
	}

	// lectura del archivo y creacion del arreglo
	while(!archEntrada.eof()){
		archEntrada >> nombre;
		arr[i].nombre=nombre;
		archEntrada >> edad;
		arr[i].edad=edad;
		archEntrada >> salario;
		arr[i].salario=salario;
		i++;
	}

	archEntrada.close();
	cout<<"los datos leidos fueron: "<<endl;

	for(j=0;j<i;j++){
		cout<<setw(10)<<arr[j].nombre<<setw(5)<<arr[j].edad<<setw(8)<<arr[j].salario<<endl;
	}

	cout<<"\ny quedaron almacenados en el archivo \"nuevoSalario.txt\"\n\n";

	for(j=0;j<i;j++){
		arr[j].salario *= 1.58;
	}


	j=0;
	while (j<i){
		archsalida1<<setw(10)<<arr[j].nombre <<setw(5)<< arr[j].edad <<setw(20)<<arr[j].salario<<"\n";
		j++;
	}

	archsalida1.close();

	system("PAUSE");
	return EXIT_SUCCESS;
}
#include"../general/Header.h"

#ifndef MENUREGISTRO_H
#define MENUREGISTRO_H

using namespace std;

class MenuRegistro {

	public:
		MenuRegistro();
		~MenuRegistro();

		static void mostrar(string&, string&);
};

MenuRegistro::MenuRegistro(){}
MenuRegistro::~MenuRegistro(){}

void MenuRegistro::mostrar(string& controlador, string& accion){
	Header::mostrar();

	cout << "Formulario de registro\n" << endl;

	cout << "Nombre: ";
	string nombre;
	cin >> nombre;

	cout << "Apellido: ";
	string apellido;
	cin >> apellido;

	cout << "Tipo id:";
	string tipoid;
	cin >> tipoid;

	cout << "Identificacion:";
	string id;
	cin >> id;

	cout << "Sexo:";
	string sexo;
	cin >> sexo;

	cout << "Celular:";
	string celular;
	cin >> celular;

	cout << "Telefono:";
	string telefono;
	cin >> telefono;

	cout << "Email:";
	string email;
	cin >> email;

	cout << "Fecha de nacimmiento (DD/MM/AAAA):";
	string fecha_n;
	cin >> fecha_n;

	cout << "Ciudad de nacimiento:";
	string ciudad_n;
	cin >> ciudad_n;

	cout << "Pais de nacimiento:";
	string pais_n;
	cin >> pais_n;

	cout << "Ciudad de residencia:";
	string ciudad_r;
	cin >> ciudad_r;

	cout << "Direccion:";
	string direccion;
	cin >> direccion;

	cout << "Barrio:";
	string barrio;
	cin >> barrio;

	cout << "Actividad laboral:";
	string actividad;
	cin >> actividad;

	cout << "Tiene hijos?:";
	string tiene_hijos;
	cin >> tiene_hijos;

	cout << "Numero de hijos:";
	string num_hijos;
	cin >> num_hijos;

	cout << "Sucursal:";
	string sucursal;
	cin >> sucursal;




	controlador = "general";
	accion = "menuRegistro";

}

#endif
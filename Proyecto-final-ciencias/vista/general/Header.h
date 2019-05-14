#ifndef HEADER_H
#define HEADER_H

using namespace std;

class Header {
	public:
		Header();
		~Header();

		static void mostrar();
};

Header::Header(){}
Header::~Header(){}

void Header::mostrar(){
	system("clear");
	cout << "\tSistema de gestion de Empleados\n" << endl;
}

#endif
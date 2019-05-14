#include<string.h>
#include<ctime>

#ifndef HELPER_H
#define HELPER_H

class Helper {

	public:
		Helper(){}
		~Helper(){}

		static int calcularEdad(char*);
};

int Helper::calcularEdad(char *fecha){
	int fecha_int[3];
	string aux = "";
	int cont = 0;

	for(int i=0; i<strlen(fecha); i++){
		if(fecha[i] == '/'){
			fecha_int[cont++] = atoi(aux.c_str());
			aux = "";
		}else{
			aux += fecha[i];
		}
	}
	fecha_int[cont] = atoi(aux.c_str());

	// Fecha del sistema
	time_t now = time(0);
	tm *time = localtime(&now);

	int fecha_act[3] = {
		time->tm_mday,
		time->tm_mon+1,
		time->tm_year+1900
	};

	int edad = fecha_act[2] - fecha_int[2];

	if(fecha_int[1] > fecha_act[1]){
		edad--;
	}else if(fecha_int[1] == fecha_act[1]){
		if(fecha_int[0] > fecha_act[0]){
			edad--;
		}
	}

	return edad;
}

#endif
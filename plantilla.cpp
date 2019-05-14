#include<iostream>

using namespace std;

template <class T>
T cuadrado(T num){
	return num*num;
}

int main(){

	int a = 5;
	float b = 4.2;
	double c = 3.2346432;
	char d = 'c';

	cout << cuadrado(a) << endl;
	cout << cuadrado(b) << endl;
	cout << cuadrado(c) << endl;
	cout << cuadrado(d) << endl;

	return 0;
}

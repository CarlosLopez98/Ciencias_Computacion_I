#include<iostream>

using namespace std;

template <class T>
void imprimir(const T *arr, const int c){
	for(int i=0; i<c; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){

	int a[] = {1,2,3,4};
	char b[] = {'a','b','c'};

	imprimir(a, 4);
	imprimir(b, 3);

	return 0;
}
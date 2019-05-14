#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
	int n, i, j, **a;
	
	cin >> n;
	
	int cont = 0;
	
	cont += sizeof(n);
	cont += sizeof(i);
	cont += sizeof(j);
	cont += sizeof(a);
	
	a = new int *[n];
	
	for(i=0; i<n; i++){
		a[i] = new int [n];
		cont += sizeof(a[i]);
		for(j=0; j<n; j++){
			a[i][j] = i*j;
			cont += sizeof(a[i][j]);
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			//cout << a[i][j] << " ";
		}
		//cout << endl;
		delete a[i];
	}
	delete []a;
	
	cout << cont << endl;
	
	return 0;
}


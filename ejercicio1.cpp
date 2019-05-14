#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
	int n, i, j, *a;
	
	cin >> n;
	
	int cont=0;
	cont += sizeof(n);
	cont += sizeof(i);
	cont += sizeof(j);
	cont += sizeof(a);
	
	for(i=0; i<n; i++){
		a = new int[n];	
		for(j=0; j<n; j++){
			a[j] = i*j;
			//cout << a[j] << " ";
		}
		cont += sizeof(a[i]);
		delete []a;
	}
	
	cout << cont << endl;
	cout << endl;
	return 0;
}


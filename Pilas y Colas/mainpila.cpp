#include<iostream>
#include"Pila.h"

using namespace std;

int main(){

    char c;
    Pila<char> guardar;

    // (5*(((10+8)*(4*6))+7))
    cin.get(c);
    while(c != '\n'){
        while(c >= '0' && c <= '9'){
            cout.put(c);
            cin.get(c);
        }

        if(c == ')'){
            cout.put(guardar.sacar());
        }
        if(c == '+'){
            guardar.meter(c);
        }
        if(c == '*'){
            guardar.meter(c);
        }
        if(c == '('){
            cout << ' ';
        }

        cin.get(c);
    }

    cout << "hola" << endl;

    return 0;
}

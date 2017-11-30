#include <iostream>
#include "../Pila/Pila.h"
using  namespace std;

bool verificar(string);

int main() {
    std::cout << "Ejercicio 03/04\n" << std::endl;
    string funcion;

    cout<<"Ingrese una función"<<endl;
    fflush(stdin);
    getline(cin, funcion);
    fflush(stdin);

    if(verificar(funcion))
        cout<<"La función es correcta"<<endl;
    else
        cout<<"La función NO es correcta"<<endl;

    return 0;
}

bool verificar(string f){
    Pila<char> miPila;
    for(int i = 0; i < f.length(); i++){
        if(f[i] == '(' || f[i] == '[' || f[i] == '{')
            miPila.push(f[i]);
        if(f[i] == ')' || f[i] == ']' || f[i] == '}'){
            if(miPila.esVacia())
                return false;
            else
                if(f[i] == '}' && miPila.peek() == '{' || f[i] == ']' && miPila.peek() == '[' || f[i] == ')' && miPila.peek() == '(')
                    miPila.pop();
                else
                    return false;
        }
    }
    return miPila.esVacia();
}
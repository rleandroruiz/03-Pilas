#include <iostream>
#include <string>
#include "../Pila/Pila.h"


int main() {
    std::cout << "Ejercicio 03/01\n" << std::endl;
    char palabra[50];
    Pila<char> miPila;
    int i = 0;

    std::cout<<"Ingrese una palabra"<<std::endl;
    std::gets(palabra);
    std::cout<<palabra<<std::endl;
    while(palabra[i] != ('\n')){
        miPila.push(palabra[i]);
        i++;
    }
    while(!miPila.esVacia()){
        std::cout<<miPila.pop();
    }

    return 0;
}
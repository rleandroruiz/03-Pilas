#include <iostream>
#include <string>
#include "../Pila/Pila.h"


int main() {
    std::cout << "Ejercicio 03/01\n" << std::endl;
    char *palabra;

    std::cout<<"Ingrese una palabra"<<std::endl;
    std::getline(std::cin, palabra);
    std::cout<<palabra<<std::endl;

    return 0;
}
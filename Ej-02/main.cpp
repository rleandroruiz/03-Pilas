#include <iostream>
#include "../Pila/Pila.h"

int main() {
    std::cout << "Ejercicio 03/02\n" << std::endl;

    Pila<int> a, b;

    a.push(1);
    b.push(3);


    int s = 1;

    while((!a.esVacia() || !b.esVacia()) && s == 1) {

        if (a.pop() != b.pop())
            s = 0;

    }

    if(s = 1)
        std::cout << "Las pilas son iguales" << std::endl;

    else
        std::cout << "Las pilas NO son iguales" << std::endl;

    return 0;
}
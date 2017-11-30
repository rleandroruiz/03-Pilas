#include <iostream>
#include "../Pila/Pila.h"
using namespace std;

string postfija(string);

int prioridad(char);

int main() {
    std::cout << "Ejercicio 03/05\n" << std::endl;
    string funcion;

    cout<<"Ingrese una función"<<endl;
    fflush(stdin);
    getline(cin, funcion);
    fflush(stdin);

    cout<<postfija(funcion)<<endl;

    return 0;
}

string postfija(string f){
    Pila<char> miPila;
    string fpostfija;
    bool desapila;

    for(int i = 0; i < f.length(); i++){
        f[i] = toupper(f[i]);
        if((f[i] >= 'A' && f[i] <= 'Z') || (f[i] >= 0 && f[i] <= 9))
            fpostfija += f[i];
        else if(f[i] != ')'){
            desapila = true;
            while(desapila){
                if(miPila.esVacia() || prioridad(f[i]) > prioridad(miPila.peek())){
                    miPila.push(f[i]);
                    desapila = false;
                }else if(prioridad(f[i]) <= prioridad(miPila.peek())){
                    fpostfija += miPila.pop();
                    desapila = true;
                }
            }

        }
        else{
            do{
                fpostfija += miPila.pop();
            }while(miPila.peek() != '(');
            miPila.pop();
        }
    }
    while(!miPila.esVacia())
        fpostfija += miPila.pop();

    return  fpostfija;
}

int prioridad(char o){
    int p;
    switch (o){
        case '^': {
            p = 3;
            break;
        }
        case '*': case '/': {
            p = 2;
            break;
        }
        case '+': case '-': {
            p = 1;
            break;
        }
        case '(': {
            p = 0;
            break;
        }
    }

    return p;
}

/* 
 * File:   estructurasDatos00060917.cpp
 * Author: Cesar
 *
 * Created on 30 de agosto de 2019, 06:53 PM
 */

#include <iostream>
using namespace std;

bool esPar(int num) {
    if (num % 2 == 0) return true;
    return false;
}

struct Nodo {
    int dato;
    Nodo *sig;
};

class Pila {
private:
    Nodo *inicio;
public:

    Pila() {
        inicio = NULL;
    }

    Nodo* crearNodo(int dato) {
        Nodo *nuevo = new (Nodo);
        nuevo->dato = dato;
        nuevo->sig = NULL;
        return nuevo;
    }

    void push(int dato) {
        Nodo *nuevo = crearNodo(dato);
        nuevo->sig = inicio;
        inicio = nuevo;
    }

    void pop() {
        Nodo *aux = inicio;
        if (inicio) inicio = inicio->sig;
        else cout << "La pila esta vacia" << endl;
        delete(aux);
    }

    void mostrarPila() {
        Nodo *aux = inicio;
        if (!inicio) {
            cout << "Pila vacia" << endl;
        } else {
            while (aux) {
                cout << aux->dato << "\t";
                aux = aux->sig;
            }
            cout << "\n";
        }
    }

    int size() {
        Nodo *aux = inicio;
        int cont = 0;
        if (!inicio) {
            return 0;
        } else
            while (aux) {
                cont++;
                aux = aux->sig;
            }
        return cont;
    }
};

int main() {
    int cant = 0, num;
    Pila pilaPares, pilaImpares;
    cout << "Ingrese la cantidad de numeros a ingresar: ";
    cin >> cant;
    for (int i = 1; i <= cant; i++) {
        cout << "Ingrese un numero: ";
        cin >> num;
        if (esPar(num)) pilaPares.push(num);
        else pilaImpares.push(num);
    }
    cout << "\nPila de pares: " << endl;
    pilaPares.mostrarPila();
    cout << "\nPila de impares: " << endl;
    pilaImpares.mostrarPila();
    if (pilaPares.size() == pilaImpares.size()) cout << "\nLas dos pilas tienen la misma cantidad de elementos"<<endl;
    else cout << "\nLas pilas tienen diferente longitud" << endl;
    return 0;
}
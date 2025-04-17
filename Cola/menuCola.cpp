#include <iostream>
#include "cola.h"
using namespace std;

// Constructor: inicializa punteros en nullptr
Cola::Cola() {
    frente = nullptr;
    final = nullptr;
}

// Destructor: libera la memoria
Cola::~Cola() {
    while (!estaVacia()) {
        desencolar();
    }
}

// Agrega un nuevo nodo al final de la cola
void Cola::encolar(int dato) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = dato;
    nuevo->siguiente = nullptr;

    if (estaVacia()) {
        frente = final = nuevo;
    }
    else {
        final->siguiente = nuevo;
        final = nuevo;
    }

    cout << "Elemento encolado correctamente.\n";
}

// Elimina el nodo del frente de la cola
void Cola::desencolar() {
    if (estaVacia()) {
        cout << "La cola est� vac�a.\n";
        return;
    }

    Nodo* temp = frente;
    frente = frente->siguiente;
    delete temp;

    if (frente == nullptr) {
        final = nullptr;
    }

    cout << "Elemento desencolado correctamente.\n";
}

// Retorna el valor del frente
int Cola::verFrente() {
    if (estaVacia()) {
        cout << "La cola est� vac�a.\n";
        return -1;
    }
    return frente->dato;
}

// Verifica si la cola est� vac�a
bool Cola::estaVacia() {
    return frente == nullptr;
}

// Muestra todos los elementos de la cola
void Cola::mostrar() {
    if (estaVacia()) {
        cout << "La cola est� vac�a.\n";
        return;
    }

    Nodo* actual = frente;
    cout << "Elementos de la cola:\n";
    while (actual != nullptr) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

// Submen� para la estructura Cola
void Cola::menuCola() {
    int opcion;
    int valor;

    do {
        cout << "\n----- Men� Estructura Cola -----\n";
        cout << "1. Encolar\n";
        cout << "2. Desencolar\n";
        cout << "3. Ver frente\n";
        cout << "4. Mostrar cola\n";
        cout << "5. Verificar si est� vac�a\n";
        cout << "6. Salir al men� principal\n";
        cout << "Ingrese opci�n: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese un valor: ";
            cin >> valor;
            encolar(valor);
            break;
        case 2:
            desencolar();
            break;
        case 3:
            cout << "Elemento en el frente: " << verFrente() << endl;
            break;
        case 4:
            mostrar();
            break;
        case 5:
            cout << (estaVacia() ? "Cola vac�a\n" : "Cola NO vac�a\n");
            break;
        case 6:
            cout << "Regresando al men� principal...\n";
            break;
        default:
            cout << "Opci�n inv�lida. Intente de nuevo.\n";
        }

    } while (opcion != 6);
}

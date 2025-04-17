#include <iostream>
#include "pila.h"
using namespace std;

void menuPila() {
    Pila pila;
    int opcion;
    int valor;

    do {
        cout << "\n====== SUBMENU - PILA ======" << endl;
        cout << "1. Insertar elemento (push)" << endl;
        cout << "2. Eliminar elemento (pop)" << endl;
        cout << "3. Mostrar elemento superior (top)" << endl;
        cout << "4. Mostrar todos los elementos" << endl;
        cout << "5. Volver al menu principal" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingresa un valor para insertar: ";
            cin >> valor;
            pila.push(valor);
            break;
        case 2:
            pila.pop();
            break;
        case 3:
            pila.mostrarTop();
            break;
        case 4:
            pila.mostrarPila();
            break;
        case 5:
            cout << "Volviendo al menu principal...\n";
            break;
        default:
            cout << "Opcion invalida. Intenta de nuevo.\n";
        }

    } while (opcion != 5);
}

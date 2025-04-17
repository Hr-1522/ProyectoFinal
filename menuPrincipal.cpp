#include <iostream>
using namespace std;

// Declaraciones de funciones para submen�s de cada estructura
void menuPila();
void menuCola();
void menuListaSimple();
void menuListaDoble();
void menuListaCircular();
void menuArbolBinario();
void menuArbolAVL();
void menuTablaHash();

int main() {
    int opcion;

    do {
        cout << "----- Men� Principal de Estructuras -----" << endl;
        cout << "1. Pila" << endl;
        cout << "2. Cola" << endl;
        cout << "3. Lista Simple" << endl;
        cout << "4. Lista Doble" << endl;
        cout << "5. Lista Circular" << endl;
        cout << "6. �rbol Binario" << endl;
        cout << "7. �rbol AVL" << endl;
        cout << "8. Tabla Hash" << endl;
        cout << "9. Salir" << endl;
        cout << "Ingrese una opci�n: ";
        cin >> opcion;

        // Validaci�n b�sica de entrada
        if (cin.fail() || opcion < 1 || opcion > 9) {
            cin.clear(); // limpiar error de entrada
            cin.ignore(1000, '\n'); // descartar entrada inv�lida
            cout << "  Opci�n inv�lida. Intente de nuevo.\n" << endl;
            continue;
        }

        switch (opcion) {
        case 1: menuPila(); break;
        case 2: menuCola(); break;
        case 3: menuListaSimple(); break;
        case 4: menuListaDoble(); break;
        case 5: menuListaCircular(); break;
        case 6: menuArbolBinario(); break;
        case 7: menuArbolAVL(); break;
        case 8: menuTablaHash(); break;
        case 9:
            char confirmar;
            cout << "  Al salir se perder�n todos los cambios. �Desea continuar? (s/n): ";
            cin >> confirmar;
            if (confirmar == 's' || confirmar == 'S') {
                cout << "Saliendo del programa..." << endl;
                return 0;
            }
            break;
        }

        cout << endl;

    } while (true);

    return 0;
}

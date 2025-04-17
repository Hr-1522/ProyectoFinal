#include <iostream>
using namespace std;

int main() {
    int numeros[5];

    // Pedir los datos
    cout << "Ingresa 5 numeros enteros:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Numero " << (i + 1) << ": ";
        cin >> numeros[i];
    }

    // Mostrar los datos
    cout << "\nLos numeros que ingresaste son:\n";
    for (int i = 0; i < 5; i++) {
        cout << numeros[i] << " ";
    }

    cout << endl;
    return 0;
}

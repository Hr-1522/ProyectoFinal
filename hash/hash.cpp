#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY = -1;
const int DELETED = -2;

class HashTable {
private:
    int table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = EMPTY;
        }
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != EMPTY && table[index] != DELETED) {
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex) {
                cout << "Tabla llena. No se pudo insertar.\n";
                return;
            }
        }

        table[index] = key;
        cout << "Insertado en el índice " << index << endl;
    }

    void remove(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                table[index] = DELETED;
                cout << "Elemento eliminado.\n";
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex) break;
        }

        cout << "Elemento no encontrado.\n";
    }

    void search(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                cout << "Elemento encontrado en el índice " << index << endl;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex) break;
        }

        cout << "Elemento no encontrado.\n";
    }

    void printTable() {
        cout << "\n--- Tabla Hash ---\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] == EMPTY)
                cout << i << ": [VACÍO]\n";
            else if (table[i] == DELETED)
                cout << i << ": [ELIMINADO]\n";
            else
                cout << i << ": " << table[i] << endl;
        }
    }
};

// Menú principal
int main() {
    HashTable hashTable;
    int opcion, valor;

    do {
        cout << "\n--- MENU TABLA HASH ---\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Buscar\n";
        cout << "4. Imprimir tabla\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Valor a insertar: ";
            cin >> valor;
            hashTable.insert(valor);
            break;
        case 2:
            cout << "Valor a eliminar: ";
            cin >> valor;
            hashTable.remove(valor);
            break;
        case 3:
            cout << "Valor a buscar: ";
            cin >> valor;
            hashTable.search(valor);
            break;
        case 4:
            hashTable.printTable();
            break;
        case 5:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 5);

    return 0;
}

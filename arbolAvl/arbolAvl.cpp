// arbolavl.cpp

#include "arbolavl.h"

// Constructor
ArbolAVL::ArbolAVL() {
    raiz = nullptr;
}

// Destructor
ArbolAVL::~ArbolAVL() {
    destruirArbol();
}

// Función para insertar un valor en el árbol
void ArbolAVL::insertar(int valor) {
    raiz = insertar(raiz, valor);
}

// Función auxiliar para insertar un valor en el subárbol
Nodo* ArbolAVL::insertar(Nodo* nodo, int valor) {
    if (nodo == nullptr) {
        return new Nodo(valor);
    }

    if (valor < nodo->valor) {
        nodo->izquierdo = insertar(nodo->izquierdo, valor);
    }
    else if (valor > nodo->valor) {
        nodo->derecho = insertar(nodo->derecho, valor);
    }
    else {
        return nodo; // No permitir duplicados
    }

    // Actualizamos la altura del nodo
    nodo->altura = 1 + max(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho));

    // Balanceamos el nodo
    int balance = obtenerBalance(nodo);

    // Si el árbol se desbalancea, hay 4 casos

    // Rotación derecha
    if (balance > 1 && valor < nodo->izquierdo->valor)
        return rotarDerecha(nodo);

    // Rotación izquierda
    if (balance < -1 && valor > nodo->derecho->valor)
        return rotarIzquierda(nodo);

    // Rotación izquierda-derecha
    if (balance > 1 && valor > nodo->izquierdo->valor) {
        nodo->izquierdo = rotarIzquierda(nodo->izquierdo);
        return rotarDerecha(nodo);
    }

    // Rotación derecha-izquierda
    if (balance < -1 && valor < nodo->derecho->valor) {
        nodo->derecho = rotarDerecha(nodo->derecho);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

// Rotación a la derecha
Nodo* ArbolAVL::rotarDerecha(Nodo* y) {
    Nodo* x = y->izquierdo;
    Nodo* T2 = x->derecho;

    // Realizamos la rotación
    x->derecho = y;
    y->izquierdo = T2;

    // Actualizamos las alturas
    y->altura = max(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho)) + 1;
    x->altura = max(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho)) + 1;

    return x; // Nueva raíz
}

// Rotación a la izquierda
Nodo* ArbolAVL::rotarIzquierda(Nodo* x) {
    Nodo* y = x->derecho;
    Nodo* T2 = y->izquierdo;

    // Realizamos la rotación
    y->izquierdo = x;
    x->derecho = T2;

    // Actualizamos las alturas
    x->altura = max(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho)) + 1;
    y->altura = max(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho)) + 1;

    return y; // Nueva raíz
}

// Función para obtener la altura de un nodo
int ArbolAVL::obtenerAltura(Nodo* nodo) {
    if (nodo == nullptr)
        return 0;
    return nodo->altura;
}

// Función para obtener el balance de un nodo
int ArbolAVL::obtenerBalance(Nodo* nodo) {
    if (nodo == nullptr)
        return 0;
    return obtenerAltura(nodo->izquierdo) - obtenerAltura(nodo->derecho);
}

// Función para eliminar un nodo
void ArbolAVL::eliminar(int valor) {
    raiz = eliminar(raiz, valor);
}

// Función auxiliar para eliminar un nodo
Nodo* ArbolAVL::eliminar(Nodo* nodo, int valor) {
    if (nodo == nullptr)
        return nodo;

    if (valor < nodo->valor) {
        nodo->izquierdo = eliminar(nodo->izquierdo, valor);
    }
    else if (valor > nodo->valor) {
        nodo->derecho = eliminar(nodo->derecho, valor);
    }
    else {
        if ((nodo->izquierdo == nullptr) || (nodo->derecho == nullptr)) {
            Nodo* temp = nodo->izquierdo ? nodo->izquierdo : nodo->derecho;

            if (temp == nullptr) {
                temp = nodo;
                nodo = nullptr;
            }
            else {
                *nodo = *temp;
            }
            delete temp;
        }
        else {
            Nodo* temp = obtenerMinimo(nodo->derecho);
            nodo->valor = temp->valor;
            nodo->derecho = eliminar(nodo->derecho, temp->valor);
        }
    }

    if (nodo == nullptr)
        return nodo;

    // Actualizamos la altura y balanceamos
    nodo->altura = 1 + max(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho));
    int balance = obtenerBalance(nodo);

    // Balanceamos el árbol
    if (balance > 1 && obtenerBalance(nodo->izquierdo) >= 0)
        return rotarDerecha(nodo);

    if (balance > 1 && obtenerBalance(nodo->izquierdo) < 0) {
        nodo->izquierdo = rotarIzquierda(nodo->izquierdo);
        return rotarDerecha(nodo);
    }

    if (balance < -1 && obtenerBalance(nodo->derecho) <= 0)
        return rotarIzquierda(nodo);

    if (balance < -1 && obtenerBalance(nodo->derecho) > 0) {
        nodo->derecho = rotarDerecha(nodo->derecho);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

// Función para obtener el nodo mínimo
Nodo* ArbolAVL::obtenerMinimo(Nodo* nodo) {
    Nodo* actual = nodo;
    while (actual->izquierdo != nullptr)
        actual = actual->izquierdo;
    return actual;
}

// Mostrar el árbol en pre-orden
void ArbolAVL::mostrarPreOrden() {
    preOrden(raiz);
    cout << endl;
}

// Función recursiva para mostrar el árbol en pre-orden

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

// Funci�n para insertar un valor en el �rbol
void ArbolAVL::insertar(int valor) {
    raiz = insertar(raiz, valor);
}

// Funci�n auxiliar para insertar un valor en el sub�rbol
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

    // Si el �rbol se desbalancea, hay 4 casos

    // Rotaci�n derecha
    if (balance > 1 && valor < nodo->izquierdo->valor)
        return rotarDerecha(nodo);

    // Rotaci�n izquierda
    if (balance < -1 && valor > nodo->derecho->valor)
        return rotarIzquierda(nodo);

    // Rotaci�n izquierda-derecha
    if (balance > 1 && valor > nodo->izquierdo->valor) {
        nodo->izquierdo = rotarIzquierda(nodo->izquierdo);
        return rotarDerecha(nodo);
    }

    // Rotaci�n derecha-izquierda
    if (balance < -1 && valor < nodo->derecho->valor) {
        nodo->derecho = rotarDerecha(nodo->derecho);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

// Rotaci�n a la derecha
Nodo* ArbolAVL::rotarDerecha(Nodo* y) {
    Nodo* x = y->izquierdo;
    Nodo* T2 = x->derecho;

    // Realizamos la rotaci�n
    x->derecho = y;
    y->izquierdo = T2;

    // Actualizamos las alturas
    y->altura = max(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho)) + 1;
    x->altura = max(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho)) + 1;

    return x; // Nueva ra�z
}

// Rotaci�n a la izquierda
Nodo* ArbolAVL::rotarIzquierda(Nodo* x) {
    Nodo* y = x->derecho;
    Nodo* T2 = y->izquierdo;

    // Realizamos la rotaci�n
    y->izquierdo = x;
    x->derecho = T2;

    // Actualizamos las alturas
    x->altura = max(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho)) + 1;
    y->altura = max(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho)) + 1;

    return y; // Nueva ra�z
}

// Funci�n para obtener la altura de un nodo
int ArbolAVL::obtenerAltura(Nodo* nodo) {
    if (nodo == nullptr)
        return 0;
    return nodo->altura;
}

// Funci�n para obtener el balance de un nodo
int ArbolAVL::obtenerBalance(Nodo* nodo) {
    if (nodo == nullptr)
        return 0;
    return obtenerAltura(nodo->izquierdo) - obtenerAltura(nodo->derecho);
}

// Funci�n para eliminar un nodo
void ArbolAVL::eliminar(int valor) {
    raiz = eliminar(raiz, valor);
}

// Funci�n auxiliar para eliminar un nodo
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

    // Balanceamos el �rbol
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

// Funci�n para obtener el nodo m�nimo
Nodo* ArbolAVL::obtenerMinimo(Nodo* nodo) {
    Nodo* actual = nodo;
    while (actual->izquierdo != nullptr)
        actual = actual->izquierdo;
    return actual;
}

// Mostrar el �rbol en pre-orden
void ArbolAVL::mostrarPreOrden() {
    preOrden(raiz);
    cout << endl;
}

// Funci�n recursiva para mostrar el �rbol en pre-orden

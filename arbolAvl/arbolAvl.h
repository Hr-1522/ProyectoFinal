// arbolavl.h

#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include <iostream>
using namespace std;

// Estructura del Nodo
struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
    int altura;

    // Constructor para crear un nodo
    Nodo(int val) : valor(val), izquierdo(nullptr), derecho(nullptr), altura(1) {}
};

class ArbolAVL {
private:
    Nodo* raiz;

    // M�todos auxiliares privados
    Nodo* insertar(Nodo* nodo, int valor);
    Nodo* rotarDerecha(Nodo* y);
    Nodo* rotarIzquierda(Nodo* x);
    int obtenerAltura(Nodo* nodo);
    int obtenerBalance(Nodo* nodo);
    Nodo* obtenerMinimo(Nodo* nodo);
    Nodo* eliminar(Nodo* nodo, int valor);
    void preOrden(Nodo* nodo);

public:
    // Constructor y Destructor
    ArbolAVL();
    ~ArbolAVL();

    // M�todos p�blicos
    void insertar(int valor);
    void eliminar(int valor);
    void mostrarPreOrden();
    void destruirArbol();
};

#endif

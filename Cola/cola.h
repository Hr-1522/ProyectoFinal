#ifndef COLA_H
#define COLA_H

// Estructura Nodo para la Cola
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Clase Cola (usa PascalCase)
class Cola {
private:
    Nodo* frente;
    Nodo* final;

public:
    Cola();                    // Constructor
    ~Cola();                   // Destructor

    void encolar(int dato);    // Agregar elemento
    void desencolar();         // Eliminar elemento
    int verFrente();           // Ver primer elemento
    bool estaVacia();          // Verificar si está vacía
    void mostrar();            // Mostrar todos los elementos
    void menuCola();           // Submenú para la cola
};

#endif

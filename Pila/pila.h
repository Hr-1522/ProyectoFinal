#ifndef PILA_H
#define PILA_H

#define TAM 100

class Pila {
private:
    int elementos[TAM];
    int tope;
public:
    Pila();
    bool estaVacia();
    bool estaLlena();
    void push(int valor);
    void pop();
    void mostrarTop();
    void mostrarPila();
};

// Prototipo del submenú
void menuPila();

#endif

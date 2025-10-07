#ifndef BEBIDAS_H
#define BEBIDAS_H

#include "Produto.h"
#include <iostream>
#include <string>
using namespace std;

class Bebidas : public Produto {
public:
    Bebidas(const string& n = "", double p = 0) : Produto(n, p, "Bebida") {}

    void mostrar() const override {
        cout << "Bebida: " << nome << " (R$" << preco << ")" << endl;
    }
};

#endif

#ifndef APERITIVO_H
#define APERITIVO_H

#include "Produto.h"
#include <iostream>
#include <string>
using namespace std;

class Aperitivo : public Produto {
public:
    Aperitivo(const string& n, double p) : Produto(n, p, "Aperitivo") {}

    void mostrar() const override {
        cout << "Aperitivo: " << nome << " (R$" << preco << ")" << endl;
    }
};

#endif

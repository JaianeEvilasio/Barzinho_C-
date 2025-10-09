#ifndef BEBIDAS_H
#define BEBIDAS_H

#include "Produto.h"
#include <iostream>
#include <string>
using namespace std;

class Bebidas : public Produto { //bebida tambem é subclasse de produto entao pode acessar a classe produto (no caso esta acessando o q foi definido como public em produto.h)
public:
    Bebidas(const string& n = "", double p = 0) : Produto(n, p, "Bebida") {} //em produto.h todo objeto tem nome, preco e categoria, aqui estamos dizendo q a categoria é bebidas

    void mostrar() const override { //essa função vai ser a q substitue a virtual que esta em produto.h
        cout << "Bebida: " << nome << " (R$" << preco << ")" << endl;
    }
};

#endif

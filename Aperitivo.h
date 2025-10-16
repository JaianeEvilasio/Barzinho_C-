#ifndef APERITIVO_H
#define APERITIVO_H

#include "Produto.h"
#include <iostream>
#include <string>
using namespace std;

class Aperitivo : public Produto { // aperitivo é uma subclasse de produto (herança)
public:
    Aperitivo(const string& n, double p) : Produto(n, p, "Aperitivo") {} 

    void mostrar() const override { // usei esse override para fazer polimorfismo, essa versao substitui o virtual la em produto.h
        cout << nome << " (R$" << preco << ")" << endl; // isso é oq aparece quando a função mostrar() é chamada e por um ponteiro ou referencia q aponta para aperitivo
    }
};

#endif

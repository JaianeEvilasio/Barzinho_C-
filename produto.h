#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <iostream>
using namespace std;

class Produto {
protected:
    string nome;
    double preco;
    string categoria;

public:
    Produto(const string& n = "", double p = 0, const string& c = "") 
        : nome(n), preco(p), categoria(c) {}

    virtual ~Produto() {}

    virtual void mostrar() const {
        cout << nome << " (R$" << preco << ") - " << categoria << endl;
    }

    string getnome() const { return nome; }
    double getpreco() const { return preco; }
    string getcategoria() const { return categoria; }
};

#endif

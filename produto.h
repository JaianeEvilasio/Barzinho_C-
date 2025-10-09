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
    Produto(const string& n = "", double p = 0, const string& c = "") //construtor
        : nome(n), preco(p), categoria(c) {}

    virtual ~Produto() {}

    virtual void mostrar() const {// essa é a função que é modificada com base em qual produto esta sendo mostrado (polimorfismo)
        cout << nome << " (R$" << preco << ") - " << categoria << endl;
    }

    string getnome() const { return nome; }
    double getpreco() const { return preco; }
    string getcategoria() const { return categoria; }
};

#endif

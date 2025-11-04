#ifndef PRODUTO_H
#define PRODUTO_H
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QString>
#include <QColor>

//Nossa classe inicial, dessa classe mais abrangente faremos classes filhas.

#include <string>
#include <iostream>
using namespace std;

class Produto {
protected:
    //Atributos protected, pois poderão ser acessados pelas classes filhas.
    string nome;
    double preco;
    string categoria;

public:
    Produto(const string& n = "", double p = 0, const string& c = "") //construtor
        : nome(n), preco(p), categoria(c) {}

    virtual ~Produto() {} //destrutor

    virtual void mostrar() const {// Essa é a função que é modificada com base em qual produto esta sendo mostrado (polimorfismo)
        cout << nome << " (R$" << preco << ") - " << categoria << endl;
    }

    virtual void mostrarGUI(QTableWidget* tabela) const {
        int linha = tabela->rowCount();
        tabela->insertRow(linha);
        tabela->setItem(linha, 0, new QTableWidgetItem(QString::fromStdString(nome)));
        tabela->setItem(linha, 1, new QTableWidgetItem(QString::number(preco, 'f', 2)));
    }

    //getters
    string getnome() const { return nome; }
    double getpreco() const { return preco; }
    string getcategoria() const { return categoria; }
};

#endif

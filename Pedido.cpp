#include "Pedido.h"
#include <iostream>
using namespace std;

Pedido::Pedido(const Cliente& c) 
    : cliente(c), qtd(0) 
{}

Pedido::~Pedido() {}



void Pedido::adicionaProduto(Produto* p) { //
    if (qtd < 50) { //limite de 50
        produtos[qtd++] = p;
    } else {
        cout << "Limite de produtos no pedido atingido!" << endl;
    }
}

void Pedido::mostrarpedido() const {
    cout << "Cliente: " << cliente.getnome() << endl;
    cout << "Itens do pedido:" << endl;

    double total = 0;
    for (int i = 0; i < qtd; i++) {
        produtos[i]->mostrar();
        total += produtos[i]->getpreco(); //preço de cada produto é somado e obtem o total
    }

    cout << "Total: R$" << total << endl;
}

double Pedido::calcularTotal() const {
    double total = 0;
    for (int i = 0; i < qtd; i++) {
        total += produtos[i]->getpreco();
    }
    return total;
}

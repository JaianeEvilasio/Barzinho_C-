#include "Barzinho.h"
#include <iostream>
using namespace std;

Barzinho::Barzinho() : qtdProdutos(0), qtdPedidos(0) {}

Barzinho::~Barzinho() {
    for (int i = 0; i < qtdProdutos; i++)
        delete cardapio[i];
    for (int i = 0; i < qtdPedidos; i++)
        delete pedidos[i];
}

void Barzinho::adicionaProduto(Produto* p) {
    if (qtdProdutos < 100)
        cardapio[qtdProdutos++] = p;
}

Produto* Barzinho::getProduto(int i) const {
    return cardapio[i];
}

int Barzinho::getQuantidade() const {
    return qtdProdutos;
}

void Barzinho::adicionarpedido(Pedido* p) {
    if (qtdPedidos < 100)
        pedidos[qtdPedidos++] = p;
}

void Barzinho::mostrarpedidos() const {
    for (int i = 0; i < qtdPedidos; i++) {
        pedidos[i]->mostrarpedido();
        cout << "=============================" << endl;
    }
}

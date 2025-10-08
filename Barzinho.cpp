#include "Barzinho.h"
#include <iostream>
using namespace std;

Barzinho::Barzinho() : qtdProdutos(0), qtdPedidos(0) {} //construtor

Barzinho::~Barzinho() { // destrutor
    for (int i = 0; i < qtdProdutos; i++)
        delete cardapio[i];
    for (int i = 0; i < qtdPedidos; i++)
        delete pedidos[i];
}

void Barzinho::adicionaProduto(Produto* p) { // adiciona o produto e muda o indice somando +1, entao o proximo produto é guardado em cardapio[1]
    if (qtdProdutos < 100)
        cardapio[qtdProdutos++] = p;
}

Produto* Barzinho::getProduto(int i) const { //retorna o produto que esta no cardapio, dependendo do numero que o cliente escolhe
    return cardapio[i];
}

int Barzinho::getQuantidade() const { //retorna a quantidade de produtos
    return qtdProdutos;
}

void Barzinho::adicionarpedido(Pedido* p) { // aqui é adicionado a quantidade de pedidos
    if (qtdPedidos < 100)
        pedidos[qtdPedidos++] = p;
}

void Barzinho::mostrarpedidos() const { //para cada pedido é chamada a função que mostra pedido, ou seja, cada pedido é apresentado por vez
    for (int i = 0; i < qtdPedidos; i++) {
        pedidos[i]->mostrarpedido();
        cout << "=============================" << endl;
    }
}

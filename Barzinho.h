#ifndef BARZINHO_H
#define BARZINHO_H

#include "Produto.h"
#include "Pedido.h"

class Barzinho {  
private:
    Produto* cardapio[100]; 
    int qtdProdutos;

    Pedido* pedidos[100];
    int qtdPedidos;

public:
    Barzinho();
    ~Barzinho();

    void adicionaProduto(Produto* p);   
    Produto* getProduto(int i) const;
    int getQuantidade() const;

    void adicionarpedido(Pedido* p);
    void mostrarpedidos() const;
};

#endif

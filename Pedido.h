#ifndef PEDIDO_H
#define PEDIDO_H

#include "Cliente.h"
#include "Produto.h"

class Pedido {
private:
    Cliente cliente;
    Produto* produtos[50];
    int qtd;

public:
    Pedido(const Cliente& c);
    ~Pedido();


    void adicionaProduto(Produto* p);
    void mostrarpedido() const;
    double calcularTotal() const;

    //funcoes banco de dados
    Produto* const* getProdutos() const { return produtos;}
    int getQtd() const { return qtd;}
    const Cliente& getCliente() const { return cliente;}
};


#endif

#ifndef BARZINHO_H
#define BARZINHO_H

#include "Produto.h"
#include "Pedido.h"
#include <sqlite3.h>

class Barzinho {  
private:
    //o barzinho possuirá, por padrão, um cardápio e pedidos dos clientes
    Produto* cardapio[100]; 
    int qtdProdutos;

    Pedido* pedidos[100];
    int qtdPedidos;
    //BANCO DE DADOS
    sqlite3* db;

public:
    Barzinho(sqlite3* bd): qtdProdutos(0), qtdPedidos(0), db(bd) {};
    ~Barzinho();

    void adicionaProduto(Produto* p);  
    Produto* getProduto(int i) const;
    int getQuantidade() const;

    void adicionarpedido(Pedido* p);
    void mostrarpedidos() const;
    void mostrarpocategoria() const;

    void salvarpedidobd(Pedido* p);
};

#endif

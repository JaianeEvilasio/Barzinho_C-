#include "Barzinho.h"
#include <iostream>
#include "Bebidas.h"
#include "Aperitivo.h"
using namespace std;

Barzinho::Barzinho() : qtdProdutos(0), qtdPedidos(0) {} //construtor

Barzinho::~Barzinho() { // destrutor
    for (int i = 0; i < qtdProdutos; i++) // quando o destrutor é chamado tanto os objetos de cardapio quanto os pedidos sao deletados 
        delete cardapio[i];
    for (int i = 0; i < qtdPedidos; i++)
        delete pedidos[i];
}

Produto* Barzinho::getProduto(int i) const { //retorna o ponteiro para o produto da posição i do cardapio 
    return cardapio[i]; 
}

void Barzinho::adicionaProduto(Produto* p) {  //adiciona um produto ao cardapio
    if (qtdProdutos < 100)
        cardapio[qtdProdutos++] = p;
}

int Barzinho::getQuantidade() const {  //retorna a quantidade de produtos cadastrados
    return qtdProdutos;
}

void Barzinho::adicionarpedido(Pedido* p) { //quando um pedido é finalizado ele é guardado
    if (qtdPedidos < 100)
        pedidos[qtdPedidos++] = p;
}

void Barzinho::mostrarpedidos() const { //mostra todos os pedidos guardados
    for (int i = 0; i < qtdPedidos; i++) {
        pedidos[i]->mostrarpedido(); //para cada pedido, ele aponta para a função mostrar pedido declarada em pedido.cpp
        cout << "=============================" << endl;
    }
}

void Barzinho::mostrarpocategoria() const { //mostrando tudo em categorias

    cout<<"===Menu do Barzinho==="<<endl; 

    cout<<endl;

    cout<<"===Aperitivos==="<<endl; //começando com aperetivos
    for(int i=0;i<qtdProdutos;i++){
        if(dynamic_cast<Aperitivo*>(cardapio[i])){ //o dynamic cast serve pra averiguar se o tipo do produto é bebida
            cout<< i+1<< "-";
            cardapio[i]->mostrar();
        }
    }
    

    cout<<endl;
    
    cout<<"===Bebidas==="<<endl; //agora bebidas
    for(int i=0;i<qtdProdutos;i++){
        if(dynamic_cast<Bebidas*>(cardapio[i])){ //o dynamic cast serve pra averiguar se o tipo do produto é aperitivos
            cout<< i+1<< "-";
            cardapio[i]->mostrar();
        }
    }

    cout<<"\n====================================";
}


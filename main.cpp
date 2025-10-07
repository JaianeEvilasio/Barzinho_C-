#include <iostream>
#include <string>
#include "Barzinho.h"
#include "Bebidas.h"
#include "Aperitivo.h"
#include "Cliente.h"
#include "Pedido.h"
using namespace std;

int main() {
    Barzinho b;

    // Adiciona bebidas
    b.adicionaProduto(new Bebidas("Caipirinha", 8.00));
    b.adicionaProduto(new Bebidas("Negroni", 18.00));
    b.adicionaProduto(new Bebidas("Pina Colada", 18.00));
    b.adicionaProduto(new Bebidas("Aperol", 25.00));
    b.adicionaProduto(new Bebidas("Sex on the Beach", 23.00));
    b.adicionaProduto(new Bebidas("Coca-Cola Zero", 6.00));
    b.adicionaProduto(new Bebidas("Agua", 2.00));

    // Adiciona aperitivos
    b.adicionaProduto(new Aperitivo("Batatas Fritas", 10.00));
    b.adicionaProduto(new Aperitivo("Bolinhos de Bacalhau", 12.00));

    // Cliente
    string nomecliente;
    cout << "Digite seu nome: ";
    getline(cin, nomecliente);
    Cliente cliente(nomecliente);
    Pedido* pedido = new Pedido(cliente);

    cout << "\nBem-vindo ao Barzinho dos Divos, " << cliente.getnome() << "!" << endl;
    cout << "===============================" << endl;

    // Mostra cardápio
    int totalProdutos = b.getQuantidade();
    for (int i = 0; i < totalProdutos; i++) {
        cout << i + 1 << " - ";
        b.getProduto(i)->mostrar();
    }

    // Escolhendo produtos
    string resposta;
    do {
        int opcao;
        cout << "\nDigite o número da bebida ou aperitivo que deseja adicionar ao pedido: ";
        cin >> opcao;
        cin.ignore();

        if (opcao > 0 && opcao <= totalProdutos) {
            pedido->adicionaProduto(b.getProduto(opcao - 1));
            cout << "Adicionado: " << b.getProduto(opcao - 1)->getnome() << endl;
        } else {
            cout << "Opção inválida!" << endl;
        }

        cout << "Deseja adicionar mais bebidas e/ou aperitivos? (sim/nao): ";
        cin >> resposta;
        cin.ignore();
    } while (resposta == "sim" || resposta == "SIM");

    // Finalizando pedido
    b.adicionarpedido(pedido);
    b.mostrarpedidos();

    delete pedido;
    return 0;
}

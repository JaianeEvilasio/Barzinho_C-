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

    //bebidas
    b.adicionaProduto(new Bebidas("Caipirinha", 8.00));
    b.adicionaProduto(new Bebidas("Negroni", 18.00));
    b.adicionaProduto(new Bebidas("Pina Colada", 18.00));
    b.adicionaProduto(new Bebidas("Aperol", 25.00));
    b.adicionaProduto(new Bebidas("Sex on the Beach", 23.00));
    b.adicionaProduto(new Bebidas("Coca-Cola Zero", 6.00));
    b.adicionaProduto(new Bebidas("Agua", 2.00));

    //aperitivos
    b.adicionaProduto(new Aperitivo("Batatas Fritas", 10.00));
    b.adicionaProduto(new Aperitivo("Bolinhos de Bacalhau", 12.00));

    string nomecliente;

    while (true) {
        cout << "\nDigite seu nome (ou 'finalizado' para encerrar): ";
        getline(cin, nomecliente);

        if (nomecliente == "finalizado" || nomecliente == "Finalizado" || nomecliente == "FINALIZADO") {
            cout << "\nEncerrando o sistema de pedidos..." << endl;
            break;
        }

        Cliente cliente(nomecliente);
        Pedido* pedido = new Pedido(cliente);

        cout << "\nBem-vindo ao Nosso Barzinho, " << cliente.getnome() << "!" << endl;
 
        int totalProdutos = b.getQuantidade();
        cout << "\nMenu do Barzinho:\n";
        for (int i = 0; i < totalProdutos; i++) {
            cout << i + 1 << " - ";
            b.getProduto(i)->mostrar();
        }

        int quantidade;
        cout << "\nQuantos itens deseja adicionar ao pedido? ";
        cin >> quantidade;
        cin.ignore();

        for (int i = 0; i < quantidade; i++) {
            int opcao;
            cout << "Digite o numero do item #" << (i + 1) << ": ";
            cin >> opcao;
            cin.ignore();

            if (opcao > 0 && opcao <= totalProdutos) {
                pedido->adicionaProduto(b.getProduto(opcao - 1));
                cout << "Adicionado: " << b.getProduto(opcao - 1)->getnome() << endl;
            } else {
                cout << "Digite um numero valido!\n";
            }
        }
         b.adicionarpedido(pedido);
         cout << "\n=============================" << endl;
         cout << "Pedido de registrado com sucesso!" << endl;
         cout << "=============================" << endl;
         
         b.mostrarpedidos();

    }

    return 0;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "Aperitivo.h"
#include "Barzinho.h"
#include "Bebidas.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
    // alocando memória para o objeto que representa sua interface visual
{
    ui->setupUi(this); // carrega o layout e os widgets definidos em .ui

    if (sqlite3_open("barzinho.db", &db)) {
        QMessageBox::critical(this, "erro", QString("falha ao abrir banco %1").arg(sqlite3_errmsg(db)));
        return;
    }

    funcaotabela();
    b = new Barzinho(db);
    carregarcardapio();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonTeste_clicked() {

    QMessageBox::information(this, "Botão clicado", "Você clicou no botão!");
}

void MainWindow::funcaotabela() {
    const char* sql_cardapio =
        "CREATE TABLE IF NOT EXISTS cardapio("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "nome TEXT,"
        "preco REAL,"
        "categoria TEXT);";

    const char* sql_pedidos=
        "CREATE TABLE IF NOT EXISTS pedidos("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "cliente TEXT,"
        "item TEXT,"
        "quantidade INTEGER,"
        "total REAL);";

    //tabelas montadas, passando pro sqlite junto cm a errmsg
    char* errMSG= nullptr;
    sqlite3_exec(db,sql_cardapio,nullptr,nullptr,&errMSG);
    sqlite3_exec(db,sql_pedidos,nullptr,nullptr,&errMSG);
}

void MainWindow::carregarcardapio() {
    //aperitivos
    b->adicionaProduto(new Aperitivo("Caldinho", 8.00));
    b->adicionaProduto(new Aperitivo("Batatas Fritas", 10.00));
    b->adicionaProduto(new Aperitivo("Bolinhos de Bacalhau", 12.00));
    b->adicionaProduto(new Aperitivo("Espetinho de Frango", 15.00));
    b->adicionaProduto(new Aperitivo("Espetinho de Carne", 15.50));
    b->adicionaProduto(new Aperitivo("Espetinho de Frango com Bacon ", 16.00));

    //bebidas
    b->adicionaProduto(new Bebidas("Brahma Chopp", 6.00));  //esse new ele serve para você guardar os objetos dentro do heap e nao deixar so na pilha
    //inclusive, é por isso que temos que usar o "delete"
    b->adicionaProduto(new Bebidas("Corona Long Neck", 10.00));
    b->adicionaProduto(new Bebidas("Heineken Long Neck", 12.00));
    b->adicionaProduto(new Bebidas("Caipirinha", 8.00));
    b->adicionaProduto(new Bebidas("Sangria", 18.00));
    b->adicionaProduto(new Bebidas("Negroni", 18.00));
    b->adicionaProduto(new Bebidas("Pina Colada", 18.00));
    b->adicionaProduto(new Bebidas("Aperol", 25.00));
    b->adicionaProduto(new Bebidas("Sex on the Beach", 23.00));
    b->adicionaProduto(new Bebidas("Coca-Cola Zero", 6.00));
    b->adicionaProduto(new Bebidas("Agua", 2.00));
}

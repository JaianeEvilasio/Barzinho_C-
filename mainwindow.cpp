#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "Aperitivo.h"
#include "Barzinho.h"
#include "Bebidas.h"
#include "telacardapio.h"



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
    // alocando memória para o objeto que representa sua interface visual
{
    ui->setupUi(this); // carrega o layout e os widgets definidos em .ui

    sqlite3* db=nullptr;
    if (sqlite3_open("barzinho.db", &db)) {
        QMessageBox::critical(this, "erro", QString("falha ao abrir banco %1").arg(sqlite3_errmsg(db)));
        return;
    }

    sqlite3_exec(db, "PRAGMA journal_mode=WAL;", nullptr, nullptr, nullptr); // permite leituras e escritas simultâneas

    this->db = db;
    funcaotabela();
    b = new Barzinho(db);
    carregarcardapio();
}

MainWindow::~MainWindow()
{
    if (db) sqlite3_close(db);
    delete ui;
}

void MainWindow::on_pushButtonTeste_clicked() {

    QString nomeCliente = ui->lineEditNome->text();

    if(nomeCliente.isEmpty()) {
        QMessageBox::warning(this, "Atenção", "Digite seu nome antes de continuar!");
        return;
    }

    // inserir o cliente no banco
    QString sql = QString("INSERT INTO pedidos (cliente) VALUES ('%1')").arg(nomeCliente);
    char* errMsg = nullptr;
    if(sqlite3_exec(db, sql.toUtf8().constData(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        QMessageBox::critical(this, "Erro", QString("Falha ao salvar cliente: %1").arg(errMsg));
        sqlite3_free(errMsg);
        return;
    }

    // abrir tela do cardápio
    TelaCardapio *cardapio = new TelaCardapio(this, db);
    cardapio->show();

    this->hide();

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

void MainWindow::adicionaraobanco(const QString& nome, double preco, const QString& categoria) {
    QString sql = QString(
        "INSERT INTO cardapio (nome, preco, categoria)"
        "VALUES ('%1', %2, '%3')"
                      ).arg(nome).arg(preco).arg(categoria);

    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.toUtf8().constData(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        qDebug() << "Erro ao inserir produto:" << errMsg;
        sqlite3_free(errMsg);
    }
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

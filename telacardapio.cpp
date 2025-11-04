#include "telacardapio.h"
#include "ui_telacardapio.h"
#include <QMessageBox>
#include <QTableWidget>
#include "Produto.h"
#include "Cliente.h"
#include "Barzinho.h"
#include "Bebidas.h"
#include "Aperitivo.h"
#include <QHeaderView>

TelaCardapio::TelaCardapio(QWidget *parent, sqlite3* banco) :
    QWidget(parent),
    ui(new Ui::TelaCardapio),
    db(banco)
{
    ui->setupUi(this);
    setWindowTitle("Cardápio do Barzinho");

    if (!db) {
        QMessageBox::critical(this, "Erro", "Não foi possível abrir o banco");
        return;
    }

    sqlite3_exec(db, "PRAGMA journal_mode=WAL;", nullptr, nullptr, nullptr);

    // duas colunas para as tabelas dos produtos: "nome" e "preço"
    ui->tabelaBebidas->setColumnCount(2);
    QStringList headerBebidas{"Nome", "Preço"};
    ui->tabelaBebidas->setHorizontalHeaderLabels(headerBebidas);
    ui->tabelaBebidas->setEditTriggers(QAbstractItemView::NoEditTriggers); // impede que o cliente altere o texto da tabela

    ui->tabelaAperitivos->setColumnCount(2);
    QStringList headerAperitivos{"Nome", "Preço"};
    ui->tabelaAperitivos->setHorizontalHeaderLabels(headerAperitivos);
    ui->tabelaAperitivos->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // esticando as colunas para ocuparem toda a tabela
    ui->tabelaBebidas->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tabelaBebidas->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);

    ui->tabelaAperitivos->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tabelaAperitivos->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);

    carregarCardapio(); // chamando para mostrar o cardápio
}

TelaCardapio::~TelaCardapio()
{
    delete ui;
}

void TelaCardapio::carregarCardapio() {
    if (!db) {
        return;
    }

    sqlite3_stmt* stmt;

    //carregando as bebidas
    const char* sqlBebidas = "SELECT nome, preco FROM cardapio WHERE categoria = 'bebida';";
    if (sqlite3_prepare_v2(db, sqlBebidas, -1, &stmt, nullptr) == SQLITE_OK) {
        ui->tabelaBebidas->setRowCount(0);
        int row=0;

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            QString nome = QString::fromUtf8(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
            double preco = sqlite3_column_double(stmt, 1);

            ui->tabelaBebidas->insertRow(row);
            ui->tabelaBebidas->setItem(row, 0, new QTableWidgetItem(nome));
            ui->tabelaBebidas->setItem(row, 1, new QTableWidgetItem(QString::number(preco, 'f', 2)));
            row++;

        }
    }
    sqlite3_finalize(stmt);

    //carregando os aperitivos

    const char* sqlAperitivos = "SELECT nome, preco FROM cardapio WHERE categoria = 'aperitivo';";
    if (sqlite3_prepare_v2(db, sqlAperitivos, -1, &stmt, nullptr) == SQLITE_OK) {
        ui->tabelaAperitivos->setRowCount(0);
        int row=0;

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            QString nome = QString::fromUtf8(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
            double preco = sqlite3_column_double(stmt, 1);

            ui->tabelaAperitivos->insertRow(row);
            ui->tabelaAperitivos->setItem(row, 0, new QTableWidgetItem(nome));
            ui->tabelaAperitivos->setItem(row, 1, new QTableWidgetItem(QString::number(preco, 'f', 2)));
            row++;

        }
    }
    sqlite3_finalize(stmt);
}

void TelaCardapio::setNomeCliente(const QString &nome) {
    nomeCliente = nome;
}


void TelaCardapio::on_botaoAdicionar_clicked() {
    QTableWidget* tabelaSelecionada = nullptr;

    // verificando qual tabela está selecionada
    if (ui->tabelaBebidas->currentRow() != -1) {
        tabelaSelecionada = ui->tabelaBebidas;

    } else if (ui->tabelaAperitivos->currentRow() != -1) {
        tabelaSelecionada = ui->tabelaAperitivos;

    } else {
        QMessageBox::warning(this, "Atenção", "Selecione um item do cardápio!");
        return;
    }

    int linha = tabelaSelecionada->currentRow();
    QString nomeProduto = tabelaSelecionada->item(linha, 0)->text();
    double preco = tabelaSelecionada->item(linha, 1)->text().toDouble();

    // verificando se o cliente já tem o produto no pedido

    Produto* prod = nullptr;

    if (tabelaSelecionada == ui->tabelaBebidas) {
        prod = new Bebidas(nomeProduto.toStdString(), preco);

    } else {
        prod = new Aperitivo(nomeProduto.toStdString(), preco);
    }

    if (!pedidoAtual) {
        pedidoAtual = new Pedido(Cliente(nomeCliente.toStdString()));
    }

    pedidoAtual->adicionaProduto(prod);

    QMessageBox::information(this, "Pedido", QString("%1 adicionado ao pedido!").arg(nomeProduto));

    tabelaSelecionada->clearSelection();
}

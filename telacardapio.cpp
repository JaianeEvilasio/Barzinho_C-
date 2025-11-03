#include "telacardapio.h"
#include "ui_telacardapio.h"
#include <QMessageBox>
#include <QTableWidget>

TelaCardapio::TelaCardapio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaCardapio)
{
    ui->setupUi(this);
    setWindowTitle("Cardápio do Barzinho");

    // duas colunas para as tabelas dos produtos: "nome" e "preço"
    ui->tabelaBebidas->setColumnCount(2);
    QStringList headerBebidas;
    headerBebidas << "Nome" << "Preço";
    ui->tabelaBebidas->setHorizontalHeaderLabels(headerBebidas);

    ui->tabelaBebidas->setColumnCount(2);
    QStringList headerAperitivos;
    headerAperitivos << "Nome" << "Preço";
    ui->tabelaAperitivos->setHorizontalHeaderLabels(headerAperitivos);

    // esticando as colunas para ocuparem toda a tabela
    ui->tabelaBebidas->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tabelaAperitivos->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    carregarCardapio(); // chamando para mostrar o cardápio
}

TelaCardapio::~TelaCardapio()
{
    delete ui;
}

void TelaCardapio::carregarCardapio() {
    sqlite3* db;
    if (sqlite3_open("barzinho.db", &db)) {
        QMessageBox::critical(this, "Erro", "Não foi possível abrir o banco de dados");
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

    sqlite3_close(db);
}

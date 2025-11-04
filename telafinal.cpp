#include "telafinal.h"
#include "ui_telafinal.h"

TelaFinal::TelaFinal(QWidget *parent, sqlite3* db, Pedido* pedido) :
    QWidget(parent),
    ui(new Ui::TelaFinal),
    db(db),  // ponteiro para o banco já aberto
    pedidoAtual(pedido)
{
    ui->setupUi(this);

    // configuração visual da tabela
    ui->tabelaQuantidades->setColumnCount(3);
    QStringList cabecalhos = {"Item", "Quantidade", "Valor"};
    ui->tabelaQuantidades->setHorizontalHeaderLabels(cabecalhos);
    ui->tabelaQuantidades->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tabelaQuantidades->setAlternatingRowColors(true);
    ui->tabelaQuantidades->setEditTriggers(QAbstractItemView::NoEditTriggers);

    carregarTabela(); // carrega os dados da tabela ao abrir a tela
}

TelaFinal::~TelaFinal()
{
    delete ui;
}

void TelaFinal::on_btnVoltar_clicked()
{
    this->close();  // Fecha a TelaFinal
    TelaCardapio *cardapio = new TelaCardapio(nullptr, db, pedidoAtual);
    cardapio->show(); // Abre a TelaCardapio
}


void TelaFinal::on_btnFecharPedido_clicked()
{
    QApplication::quit();
}

void TelaFinal::carregarTabela()
{

    if (!pedidoAtual) {
        QMessageBox::warning(this, "Aviso", "Não há pedido");
        return;
    }

    ui->tabelaQuantidades->setRowCount(0);
    double totalGeral = 0.0;

    int qtdProdutos = pedidoAtual->getQtd();
    Produto* const* produtos = pedidoAtual->getProdutos();

    bool gerenciamentop[50] = {false};
    int linha = 0;

    for (int i=0; i<qtdProdutos; i++) {
        if (!gerenciamentop[i]) {
            int contador = 1;
            double preco = produtos[i]->getpreco();

            for (int j= i+1; j<qtdProdutos; j++) {
                if (!gerenciamentop[j] && produtos[j]->getnome() == produtos[i]->getnome()) {
                    contador++;
                    gerenciamentop[j] = true;
                }
            }

            double totalItem = contador * preco;
            totalGeral += totalItem;

            ui->tabelaQuantidades->insertRow(linha);
            ui->tabelaQuantidades->setItem(linha, 0, new QTableWidgetItem(QString::fromStdString(produtos[i]->getnome())));
            ui->tabelaQuantidades->setItem(linha, 1, new QTableWidgetItem(QString::number(contador)));
            ui->tabelaQuantidades->setItem(linha, 2, new QTableWidgetItem(QString::number(totalItem, 'f', 2)));
            linha++;
        }
    }

    ui->labelTotal->setText("Total: R$ " + QString::number(totalGeral, 'f', 2));
}

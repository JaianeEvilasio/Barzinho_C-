#ifndef TELAFINAL_H
#define TELAFINAL_H

#include <QWidget>
#include <QMessageBox>
#include "sqlite3.h"
#include "Pedido.h"

namespace Ui {
class TelaFinal;
}

class TelaFinal : public QWidget
{
    Q_OBJECT

public:
    explicit TelaFinal(QWidget *parent = nullptr, sqlite3* db = nullptr, Pedido* pedido = nullptr);
    ~TelaFinal();

private slots:
    void on_btnVoltar_clicked();
    void on_btnFecharPedido_clicked();

private:
    Ui::TelaFinal *ui;
    sqlite3* db;  // ponteiro pro banco já aberto
    Pedido* pedidoAtual;
    void carregarTabela();
};

#endif // TELAFINAL_H

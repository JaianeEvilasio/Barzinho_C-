#ifndef TELACARDAPIO_H
#define TELACARDAPIO_H
#include "Produto.h"
#include <QMainWindow>
#include "sqlite3.h"


namespace Ui {
class TelaCardapio;
}

class TelaCardapio : public QWidget
{
    Q_OBJECT

public:
    explicit TelaCardapio(QWidget *parent = nullptr, sqlite3* banco = nullptr);
    ~TelaCardapio();

    void setNomeCliente(const QString &nome);

private slots:
    void on_botaoAdicionar_clicked();

private:
    Ui::TelaCardapio *ui;
    sqlite3* db;
    QString nomeCliente;

    void carregarCardapio();
};

#endif // TELACARDAPIO_H

#ifndef TELACARDAPIO_H
#define TELACARDAPIO_H
#include "Produto.h"
#include <QMainWindow>
#include "sqlite3.h"


namespace Ui {
class TelaCardapio;
}

class TelaCardapio : public QMainWindow
{
    Q_OBJECT

public:
    explicit TelaCardapio(QWidget *parent = nullptr, sqlite3* banco = nullptr);
    ~TelaCardapio();

private:
    Ui::TelaCardapio *ui;
    sqlite3* db;

    void carregarCardapio();
};

#endif // TELACARDAPIO_H

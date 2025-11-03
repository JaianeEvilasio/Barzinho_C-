#ifndef TELACARDAPIO_H
#define TELACARDAPIO_H
#include "Produto.h"

#include <QMainWindow>

namespace Ui {
class TelaCardapio;  // 👈 T maiúsculo
}

class TelaCardapio : public QMainWindow  // 👈 T maiúsculo
{
    Q_OBJECT

public:
    explicit TelaCardapio(QWidget *parent = nullptr);
    ~TelaCardapio();

private:
    Ui::TelaCardapio *ui;  // 👈 T maiúsculo
};

#endif // TELACARDAPIO_H

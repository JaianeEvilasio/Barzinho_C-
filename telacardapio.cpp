#include "telacardapio.h"
#include "ui_telacardapio.h"

TelaCardapio::TelaCardapio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaCardapio)
{
    ui->setupUi(this);
    setWindowTitle("Cardápio do Barzinho");
}

TelaCardapio::~TelaCardapio()
{
    delete ui;
}

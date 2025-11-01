#include "telacardapio.h"
#include "ui_telacardapio.h"

TelaCardapio::TelaCardapio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaCardapio)  // 👈 T maiúsculo
{
    ui->setupUi(this);
    setWindowTitle("Cardápio do Barzinho 🍻");
}

TelaCardapio::~TelaCardapio()
{
    delete ui;
}

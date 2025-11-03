#include "telafinal.h"
#include "ui_telafinal.h"

TelaFinal::TelaFinal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TelaFinal)
{
    ui->setupUi(this);
}

TelaFinal::~TelaFinal()
{
    delete ui;
}

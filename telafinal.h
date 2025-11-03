#ifndef TELAFINAL_H
#define TELAFINAL_H

#include <QWidget>

namespace Ui {
class TelaFinal;
}

class TelaFinal : public QWidget
{
    Q_OBJECT

public:
    explicit TelaFinal(QWidget *parent = nullptr);
    ~TelaFinal();

private:
    Ui::TelaFinal *ui;
};

#endif // TELAFINAL_H

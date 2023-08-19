#ifndef HELPANDCHECK_H
#define HELPANDCHECK_H

#include <QMainWindow>

namespace Ui {
class helpAndCheck;
}

class helpAndCheck : public QMainWindow
{
    Q_OBJECT

public:
    explicit helpAndCheck(QWidget *parent = nullptr);
    ~helpAndCheck();

private:
    Ui::helpAndCheck *ui;
};

#endif // HELPANDCHECK_H

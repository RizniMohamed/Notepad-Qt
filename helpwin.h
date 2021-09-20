#ifndef HELPWIN_H
#define HELPWIN_H

#include <QMainWindow>

namespace Ui {
class HelpWin;
}

class HelpWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit HelpWin(QWidget *parent = nullptr);
    ~HelpWin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HelpWin *ui;
};

#endif // HELPWIN_H

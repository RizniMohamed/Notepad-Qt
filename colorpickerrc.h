#ifndef COLORPICKERRC_H
#define COLORPICKERRC_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class ColorPickerRC;
}

class ColorPickerRC : public QDialog
{
    Q_OBJECT

public:
    explicit ColorPickerRC(QWidget *parent = nullptr);
    ~ColorPickerRC();

    static QColor getFC();
    static QColor getTEC();
    static QColor getWC();
    static QColor getTIC();

private slots:
    void on_btnFC_clicked();

    void on_btnWC_clicked();

    void on_btnTIC_clicked();

    void on_btnTEC_clicked();

    void on_btnOK_clicked();


private:
    Ui::ColorPickerRC *ui;

};

#endif // COLORPICKERRC_H

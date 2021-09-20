#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    #ifdef Q_OS_WIN
        this->setFixedSize(840,265);
    #endif
    ui->btnOK->setStyleSheet("QPushButton:hover{background-color:grey; color:black;}"
                             "QPushButton{width:100px;border:1px; solid black;border-radius: 3px;padding: 2px;text-align:center;}"
                             );

}

About::~About()
{
    delete ui;
}

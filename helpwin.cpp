#include "helpwin.h"
#include "ui_helpwin.h"
#include <QtDebug>
#include <QtCore>
#include <QtGui>
HelpWin::HelpWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HelpWin)
{
    ui->setupUi(this);


    QString styleTextbtnAction = "QPushButton:hover{background-color:grey; color:black;}"
                                 "QPushButton{width:187px; height:30px; border:1px solid black;border-radius: 3px;padding: 2px;text-align:center;}";
    ui->pushButton->setStyleSheet(styleTextbtnAction);


    #ifdef Q_OS_ANDROID
      ui->pushButton->setStyleSheet(styleTextbtnAction +
                                   "QPushButton{width:187px; height:30px; font-size:30px; border:1px solid black;border-radius: 3px;padding: 2px;text-align:center;}"
                                  );
    ui->gridLayout_3->removeWidget(ui->label_6);
    ui->gridLayout_3->removeWidget(ui->label_7);
    ui->gridLayout_3->removeWidget(ui->label_8);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->label_8->setVisible(false);

   #endif

    ui->label_49->setText(": " + QApplication::applicationVersion());
}

HelpWin::~HelpWin()
{
    delete ui;
}

void HelpWin::on_pushButton_clicked()
{
    this->close();
}

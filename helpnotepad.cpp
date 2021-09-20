#include "helpnotepad.h"
#include "ui_helpnotepad.h"

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileDialog>
#include "about.h"
#include "colorpickerrc.h"

HelpNotepad::HelpNotepad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpNotepad)
{
    ui->setupUi(this);


    QString styleTextbtnAction = "QPushButton:hover{background-color:grey; color:black;}"
                                 "QPushButton{width:187px; height:30px; border:1px solid black;border-radius: 3px;padding: 2px;text-align:center;}";
    ui->pushButton->setStyleSheet(styleTextbtnAction);


    #ifdef Q_OS_ANDROID
      ui->pushButton->setStyleSheet(styleTextbtnAction +
                                   "QPushButton{width:187px; height:30px; font-size:30px; border:1px solid black;border-radius: 3px;padding: 2px;text-align:center;}"
                                  );
      ui->label_6->setVisible(false);
      ui->label_7->setVisible(false);
      ui->label_8->setVisible(false);
    #endif

}

HelpNotepad::~HelpNotepad()
{
    delete ui;
}

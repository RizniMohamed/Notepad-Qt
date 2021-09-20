#include "colorpickerrc.h"
#include "ui_colorpickerrc.h"
#include <QColorDialog>
#include <QDebug>
#include <QLayout>

bool ok = false;

QColor newFC    = "green";      QColor oldFC    = "green";
QColor newTEC   = "black" ;     QColor oldTEC   = "black";
QColor newWC    = "grey";       QColor oldWC    = "grey";
QColor newTIC   = "lightgrey";  QColor oldTIC   = "lightgrey";



ColorPickerRC::ColorPickerRC(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ColorPickerRC)
{
    QString styleText = "QPushButton:hover{background-color:grey; color:black;}"
                        "QPushButton{width:100px; border:1px solid black;border-radius: 3px;padding: 2px;text-align:center;}"
                        ;
    QString styleTextbtnAction = "QPushButton:hover{background-color:grey; color:black;}"
                                 "QPushButton{width:187px; height:30px; font-size:30px; border:1px solid black;border-radius: 3px;padding: 2px;text-align:center;}"
                                ;
    ui->setupUi(this);
    ui->btnFC->setStyleSheet(styleText);
    ui->btnTEC->setStyleSheet(styleText);
    ui->btnTIC->setStyleSheet(styleText);
    ui->btnWC->setStyleSheet(styleText);
    ui->btnCancel->setStyleSheet(styleTextbtnAction);
    ui->btnOK->setStyleSheet(styleTextbtnAction);


#ifdef Q_OS_WIN
    resize(374,234);
#endif
#ifdef Q_OS_ANDRIOD
    andriod::SET_SCREEN_ANGLE = 'landscape';
#endif
}


ColorPickerRC::~ColorPickerRC()
{
    delete ui;
    ok = false;
}

void ColorPickerRC::on_btnFC_clicked()
{
    QColorDialog colordialog;
    colordialog.setSizeGripEnabled(true);
    colordialog.layout()->setSizeConstraint(QLayout::SetNoConstraint);
    colordialog.setWindowModality(Qt::ApplicationModal);
    colordialog.setGeometry(0,0,200,200);
    colordialog.resize(2000,2000);

    oldFC = newFC;
    newFC = colordialog.getColor();


}

void ColorPickerRC::on_btnWC_clicked()
{
    oldWC = newWC;
    newWC = QColorDialog::getColor();
}

void ColorPickerRC::on_btnTIC_clicked()
{
    oldTIC = newTIC;
    newTIC = QColorDialog::getColor();
}

void ColorPickerRC::on_btnTEC_clicked()
{
    oldTEC = newTEC;
    newTEC = QColorDialog::getColor();
}

void ColorPickerRC::on_btnOK_clicked()
{
    ok = true;
}

QColor ColorPickerRC::getFC(){

    if(ok){
        return newFC;
    }
    return oldFC;
}

QColor ColorPickerRC::getTEC(){
    if(ok){
        return newTEC;
    }
    return oldTEC;
}

QColor ColorPickerRC::getWC(){
    if(ok){
        return newWC;
    }
    return oldWC;
}

QColor ColorPickerRC::getTIC(){
    if(ok){
        return newTIC;
    }
    return oldTIC;
}



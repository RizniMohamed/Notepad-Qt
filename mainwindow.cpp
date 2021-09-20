#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindowduplicate.h"
#include <QFontDialog>
#include <QtWidgets>
#include <QObject>
#include <QSize>
#include "helpwin.h"
#include <QtMath>
#include "count.h"
#include "helpnotepad.h"

QString memText;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

    connect(ui->textEdit,SIGNAL(undoAvailable(bool)),this,SLOT(onUndoAvailable(bool)));
    connect(ui->textEdit,SIGNAL(redoAvailable(bool)),this,SLOT(onRedoAvailable(bool)));

    ui->actionRedo->setEnabled(false);
    ui->actionUndo->setEnabled(false);

    preUpdate();

}

void MainWindow::preUpdate(){

    QScreen *screen = qApp->screens().at(0);
    int UNK = (13*screen->physicalSize().height()/100);
    ui->toolBar->setIconSize(QSize( UNK , UNK ));

#ifdef Q_OS_ANDROID
    UNK = (7*screen->geometry().height()/100);
    ui->toolBar->setIconSize(QSize( UNK , UNK ));
    ui->actionNew_Window->setVisible(false);
#endif

    ui->textEdit->setStyleSheet("color:" + ColorPickerRC::getFC().name() + ";"
                                                                           "background-color:" + ColorPickerRC::getTEC().name());
    setStyleSheet("background-color:"+ColorPickerRC::getWC().name()+";");
    ui->toolBar->setStyleSheet("background-color:" + ColorPickerRC::getTIC().name());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *bar)
{
    count::decrease();
    if(count::get() == -1){
        QApplication::setQuitOnLastWindowClosed(true);
    }

    bar->accept();
}

void MainWindow::on_actionNew_triggered()
{
    if ( ( (memText != ui->textEdit->toPlainText()) || FileName.isEmpty() ) ){

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirm", "Text not saved, do you want to save?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            on_actionSave_triggered();
        }
    }

    FileName = "";
    ui->textEdit->setPlainText("");
    this->setWindowTitle("New File");
}

void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,"Open a File");
    if(!(file.isEmpty())){
        QFile sFile(file);
        if(sFile.open(QFile::ReadOnly | QFile::Text)){
            FileName = file;
            QFileInfo info(FileName);
            this->setWindowTitle(info.fileName());
            QTextStream in(&sFile);
            QString text = in.readAll();
            sFile.close();

            ui->textEdit->setPlainText(text);
            memText = ui->textEdit->toPlainText();
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    if(FileName == ""){
        on_actionSave_As_triggered();
    }else{
        QFile sFile(FileName);
        if(sFile.open(QFile::WriteOnly | QFile::Text)){
            QTextStream out(&sFile);
            out << ui->textEdit->toPlainText();
            sFile.flush();
            sFile.close();
            QFileInfo info(FileName);
            this->setWindowTitle(info.fileName());
            memText = ui->textEdit->toPlainText();
        }
    }
}

void MainWindow::on_actionSave_As_triggered()
{
    QFileDialog *fileOpen = new QFileDialog();
    fileOpen->setDefaultSuffix(".txt");
    QString file = fileOpen->getSaveFileName(this, tr("Save File"), "" ,
                                                   tr("Text(*.txt);"));
    if(!(file.isEmpty())){
        FileName = file;
        on_actionSave_triggered();
    }

}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::onUndoAvailable(bool isUndoAvailable)
{
    if(isUndoAvailable){
        ui->actionUndo->setEnabled(true);
    }else{
        ui->actionUndo->setEnabled(false);
    }
}

void MainWindow::onRedoAvailable(bool isRedoAvailable)
{
    if(isRedoAvailable){
        ui->actionRedo->setEnabled(true);
    }else{
        ui->actionRedo->setEnabled(false);
    }

}

void MainWindow::on_actionNew_Window_triggered()
{
    count::increase();
    MainWindow *a = new MainWindow(this);
    a->show();
}

void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::exit();
}

void MainWindow::on_actionFont_triggered()
{
    QString fontFamily = ui->textEdit->font().family();
    int fontSize =  ui->textEdit->font().pointSize();

    bool ok;
    QFont initial(fontFamily,fontSize);
    QFont font = QFontDialog::getFont(&ok,initial, this);

    if (ok) {
        ui->textEdit->setFont(font);
    }

}


void MainWindow::on_actionColor_triggered()
{
    ColorPickerRC *colorPicWin = new ColorPickerRC(this);
    colorPicWin->show();
}

void MainWindow::on_actionUpdate_Settings_triggered()
{
    preUpdate();
}

void MainWindow::on_actionHelp_triggered()
{
    HelpWin *help = new HelpWin ();
    help->show();

}

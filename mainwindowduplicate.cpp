#include "mainwindowduplicate.h"
#include "mainwindow.h"
#include "ui_mainwindowduplicate.h"

#include "count.h"

MainWindowDuplicate::MainWindowDuplicate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowDuplicate)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

    connect(ui->textEdit,SIGNAL(undoAvailable(bool)),this,SLOT(onUndoAvailable(bool)));
    connect(ui->textEdit,SIGNAL(redoAvailable(bool)),this,SLOT(onRedoAvailable(bool)));

    ui->actionRedo->setEnabled(false);
    ui->actionUndo->setEnabled(false);
}

MainWindowDuplicate::~MainWindowDuplicate()
{
    count::decrease();
    delete ui;
}


void MainWindowDuplicate::on_actionNew_triggered()
{
    FileName = "";
    ui->textEdit->setPlainText("");

}

void MainWindowDuplicate::on_actionOpen_triggered()
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
         }
     }
}

void MainWindowDuplicate::on_actionSave_triggered()
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
        }
    }
}

void MainWindowDuplicate::on_actionSave_As_triggered()
{
    QString file = QFileDialog::getSaveFileName(this,"Open a File");
    if(!(file.isEmpty())){
        FileName = file;
        on_actionSave_triggered();
    }

}

void MainWindowDuplicate::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindowDuplicate::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindowDuplicate::on_actionPaste_triggered()
{
     ui->textEdit->paste();
}

void MainWindowDuplicate::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindowDuplicate::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindowDuplicate::onUndoAvailable(bool isUndoAvailable)
{
    if(isUndoAvailable){
        ui->actionUndo->setEnabled(true);
    }else{
        ui->actionUndo->setEnabled(false);
    }
}

void MainWindowDuplicate::onRedoAvailable(bool isRedoAvailable)
{
    if(isRedoAvailable){
        ui->actionRedo->setEnabled(true);
    }else{
        ui->actionRedo->setEnabled(false);
    }

}

void MainWindowDuplicate::on_actionNew_Window_triggered()
{
    MainWindow *winDupe = new MainWindow(this);
    count::increase();
    winDupe->show();
}


void MainWindowDuplicate::on_actionExit_triggered()
{
    QCoreApplication::exit();
}


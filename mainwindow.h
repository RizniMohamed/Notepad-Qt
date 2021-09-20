#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileDialog>
#include "about.h"
#include "colorpickerrc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void preUpdate();

private slots:

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void onUndoAvailable(bool isUndoAvailable);

    void onRedoAvailable(bool isRedoAvailable);

    void on_actionNew_Window_triggered();

    void on_actionExit_triggered();

    void on_actionFont_triggered();

    void on_actionColor_triggered();

    void on_actionUpdate_Settings_triggered();

    void on_actionHelp_triggered();

private:
    Ui::MainWindow *ui;
    QString FileName;
    void closeEvent(QCloseEvent *bar);
};
#endif // MAINWINDOW_H

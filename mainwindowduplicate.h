#ifndef MAINWINDOWDUPLICATE_H
#define MAINWINDOWDUPLICATE_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileDialog>

namespace Ui {
class MainWindowDuplicate;
}

class MainWindowDuplicate : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowDuplicate(QWidget *parent = nullptr);
    ~MainWindowDuplicate();

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

private:
    Ui::MainWindowDuplicate *ui;
    QString FileName;
};

#endif // MAINWINDOWDUPLICATE_H

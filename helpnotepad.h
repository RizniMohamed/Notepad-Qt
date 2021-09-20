#ifndef HELPNOTEPAD_H
#define HELPNOTEPAD_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QMainWindow>

namespace Ui {
class HelpNotepad;
}

class HelpNotepad : public QDialog
{
    Q_OBJECT

public:
    explicit HelpNotepad(QWidget *parent = nullptr);
    ~HelpNotepad();

private:
    Ui::HelpNotepad *ui;
};

#endif // HELPNOTEPAD_H

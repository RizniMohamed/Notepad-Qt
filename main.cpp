#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#include "count.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE( res );
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("RC Notepad");
    MainWindow w;
    QApplication::setQuitOnLastWindowClosed(false);

    w.show();
    return a.exec();
}

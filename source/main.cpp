#include "mainwindow.h"
#include <QApplication>
#include "ocenka.h"
#include "startwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow w;
    w.show();
    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>

#include <QtWidgets>

#include "button.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow(NULL, &a);

    mainWindow.show();

    return a.exec();
}

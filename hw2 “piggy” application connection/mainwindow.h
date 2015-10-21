#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include "button.h"
#include <QApplication>
#include <QGridLayout>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent, QApplication * app);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QGridLayout * layout;
    Button * initializeLayout();
};


#endif // MAINWINDOW_H

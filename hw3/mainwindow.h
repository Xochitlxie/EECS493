#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "radiobutton.h"
#include <QGridLayout>
#include <QMessageBox>
#include <QApplication>
#include <QButtonGroup>
#include <vector>
#include <QMenu>
#include <QMenuBar>
#include <QUndoStack>
#include "rbuttonundocommand.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QApplication * parentApp;

    //-------------Buttons and Layout------------//
    QWidget * container;
    QButtonGroup * radio;
    QGridLayout * layout;
    std::vector<RadioButton *> buttons;

    //-------------Menus and Actions---------------//
    QMenu * actionMenu;
    QAction * incrementAct;
    QAction * decrementAct;
    QAction * printAct;

    QMenu * fileMenu;
    QAction * openAct;
    QAction * saveAct;
    QAction * saveAsAct;
    QAction * quitAct;

    QMenu * editMenu;
    QAction * undoAct;
    QAction * redoAct;

    QUndoStack * undoStack;

    RadioButton * initializeLayout();
    void createActions();
    void createMenus();

public:
    MainWindow(QWidget *parent, QApplication * app);
    ~MainWindow();

private slots:

    //------------ Edit Menu --------------//
    void undo();
    void redo();

    //------------ Action Menu ------------//
    void increment();
    void decrement();
    void print();
};

#endif // MAINWINDOW_H

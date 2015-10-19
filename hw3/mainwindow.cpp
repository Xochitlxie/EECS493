#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QApplication * app)
    : QMainWindow(parent)
{
    parentApp = app;
    container = new QWidget;
    RadioButton * quitButton = initializeLayout();

    container->setLayout(layout);
    setCentralWidget(container);

    QObject::connect(quitButton, SIGNAL(clicked()), app, SLOT(quit()));

    //--------------- Initialize Menu ----------------//
    createActions();
    createMenus();

    undoStack = new QUndoStack();
}

RadioButton * MainWindow::initializeLayout(){
    layout = new QGridLayout;
    radio = new QButtonGroup;

    // The last one must be quit button;

    buttons.push_back(new RadioButton("market piggy"));
    buttons.push_back(new RadioButton("home piggy"));
    buttons.push_back(new RadioButton("glutton piggy"));
    buttons.push_back(new RadioButton("dieting piggy"));
    buttons.push_back(new RadioButton("whiny piggy"));
    buttons.push_back(new RadioButton("wolverine piggy"));
    buttons.push_back(new RadioButton("quit"));

    for(size_t i = 0 ; i < buttons.size() - 1; ++i){
        layout->addWidget(buttons[i], i/2, i%2);
        radio->addButton(buttons[i], i);
        buttons[i]->setCheckable(true);
        buttons[i]->setChecked(false);
    }
    buttons[0]->setChecked(true);
    int quitIdx = buttons.size() - 1;
    layout->addWidget(buttons[quitIdx], quitIdx / 2, quitIdx % 2, 1, 2, Qt::AlignHCenter);

    return buttons[quitIdx];
}

void MainWindow::increment(){
    RadioButton * button = (RadioButton*)(radio->checkedButton());
    undoStack->push(new RButtonUndoCommand(true, button));
    undoAct->setEnabled(undoStack->canUndo());
    redoAct->setEnabled(undoStack->canRedo());
}

void MainWindow::decrement(){
    RadioButton * button = (RadioButton*)(radio->checkedButton());
    undoStack->push(new RButtonUndoCommand(false, button));
    undoAct->setEnabled(undoStack->canUndo());
    redoAct->setEnabled(undoStack->canRedo());
}

void MainWindow::print(){
    ((RadioButton*)(radio->checkedButton()))->print();
}

void MainWindow::redo(){
    undoStack->redo();
    undoAct->setEnabled(undoStack->canUndo());
    redoAct->setEnabled(undoStack->canRedo());
}

void MainWindow::undo(){
    undoStack->undo();
    undoAct->setEnabled(undoStack->canUndo());
    redoAct->setEnabled(undoStack->canRedo());
}


void MainWindow::createActions(){
    openAct = new QAction(" Open", this);
    saveAct = new QAction(" Save", this);
    saveAsAct = new QAction(" Save As", this);
    quitAct = new QAction(" Quit", this);
    connect(quitAct, SIGNAL(triggered(bool)), parentApp, SLOT(quit()));

    incrementAct = new QAction("Increment", this);
    incrementAct->setShortcut(QKeySequence(tr("Ctrl+I")));
    connect(incrementAct, SIGNAL(triggered(bool)), this, SLOT(increment()));

    decrementAct = new QAction("Decrement", this);
    decrementAct->setShortcut(QKeySequence(tr("Ctrl+D")));
    connect(decrementAct, SIGNAL(triggered(bool)), this, SLOT(decrement()));

    printAct = new QAction("Print Amount", this);
    printAct->setShortcut(QKeySequence(tr("Ctrl+P")));
    connect(printAct, SIGNAL(triggered(bool)), this, SLOT(print()));

    undoAct = new QAction("Undo", this);
    undoAct->setShortcut(QKeySequence(tr("Ctrl+Z")));
    connect(undoAct, SIGNAL(triggered(bool)), this, SLOT(undo()));
    redoAct = new QAction("Redo", this);
    redoAct->setShortcut(QKeySequence(tr("Ctrl+Y")));
    connect(redoAct, SIGNAL(triggered(bool)), this, SLOT(redo()));
}

void MainWindow::createMenus(){
    fileMenu = menuBar()->addMenu(tr("File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addAction(quitAct);

    openAct->setEnabled(false);
    saveAct->setEnabled(false);
    saveAsAct->setEnabled(false);


    editMenu = menuBar()->addMenu(tr("Edit"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    undoAct->setEnabled(false);
    redoAct->setEnabled(false);

    actionMenu = menuBar()->addMenu(tr("Actions"));
    actionMenu->addAction(incrementAct);
    actionMenu->addAction(decrementAct);
    actionMenu->addAction(printAct);

}

MainWindow::~MainWindow()
{
    for(size_t i = 0; i < buttons.size(); ++i){
        delete buttons[i];
    }
}

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent){}

MainWindow::MainWindow(QWidget *parent, QApplication * app) : QMainWindow(parent)
{
    QWidget * container = new QWidget;
    Button * quitButton = initializeLayout();

    container->setLayout(layout);
    setCentralWidget(container);

    QObject::connect(quitButton, SIGNAL(clicked()), app, SLOT(quit()));
}

Button * MainWindow::initializeLayout(){
    layout = new QGridLayout;

    Button * button1 = new Button("market piggy", "Button 1: this little piggy went to market");
    Button * button2 = new Button("home piggy", "Button 2: this little piggy stayed home");
    Button * button3 = new Button("glutton piggy", "Button 3: this little piggy ate roast beef");
    Button * button4 = new Button("dieting piggy", "Button 4: this little piggy had none");
    Button * button5 = new Button("whiny piggy", "Button 5: this little piggy cried wee wee wee");
    Button * button6 = new Button("wolverine piggy", "Button 6: this little piggy cried go blue");
    Button * quitButton = new Button("quit");

    layout->addWidget(button1, 0, 0);
    layout->addWidget(button2, 0, 1);
    layout->addWidget(button3, 1, 0);
    layout->addWidget(button4, 1, 1);
    layout->addWidget(button5, 2, 0);
    layout->addWidget(button6, 2, 1);
    layout->addWidget(quitButton, 3, 0, 1, 2, Qt::AlignHCenter);

    return quitButton;
}

MainWindow::~MainWindow(){}


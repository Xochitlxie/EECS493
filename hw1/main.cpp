#include <qapplication.h>
#include <qpushbutton.h>
#include <Qtgui>
#include"widget.h"
#include <QtWidgets>


int main(int argc, char **argv)
{
    QApplication app(argc,argv);

    Widget * window = new Widget;

    QPushButton *market = new QPushButton("market piggy");
    market->setFont(QFont("Times",14,QFont::Bold));

    QPushButton *home = new QPushButton("home piggy");
    home->setFont(QFont("Times",14,QFont::Bold));

    QPushButton *glutton = new QPushButton("glutton piggy");
    glutton->setFont(QFont("Times",14,QFont::Bold));

    QPushButton *dieting = new QPushButton("dieting piggy");
    dieting->setFont(QFont("Times",14,QFont::Bold));

    QPushButton *whiny = new QPushButton("whiny piggy");
    whiny->setFont(QFont("Times",14,QFont::Bold));

    QPushButton *wolverine = new QPushButton("wolverine piggy");
    wolverine->setFont(QFont("Times",14,QFont::Bold));

    QPushButton *quit = new QPushButton("quit");
    quit->setFont(QFont("Times",14,QFont::Bold));

    QGridLayout *leftLayout = new QGridLayout;
    leftLayout->addWidget(market, 0, 0);
    leftLayout->addWidget(home, 0, 1);
    leftLayout->addWidget(glutton, 1, 0);
    leftLayout->addWidget(dieting, 1, 1);
    leftLayout->addWidget(whiny, 2, 0);
    leftLayout->addWidget(wolverine, 2, 2);
    leftLayout->addWidget(quit, 4, 1);

    QObject::connect(quit,SIGNAL(clicked()), &app, SLOT(quit()));
    window->setLayout(leftLayout);
    window->show();

    return app.exec();
}

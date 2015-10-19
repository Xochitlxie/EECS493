#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

#include <QPushButton>
#include <iostream>
#include <QTextStream>

class RadioButton : public QPushButton
{
    int val;
    void updateTitle();
    QString text;

public:
    RadioButton(const QString text);
    ~RadioButton();
    void increment();
    void decrement();
    void print();
signals:

public slots:
};

#endif // RADIOBUTTON_H

#include "radiobutton.h"
#include <iostream>

RadioButton::RadioButton(const QString text)
{
    val = 0;
    this->text = text;
    this->updateTitle();
}

void RadioButton::increment(){
    val++;
    this->updateTitle();
}

void RadioButton::decrement(){
    val--;
    this->updateTitle();
}

void RadioButton::updateTitle(){
    this->setText(QString::number(val) + QString(" ") + text);
}

void RadioButton::print(){
    std::cout << val << " " << text.toStdString();
    std::cout.flush();
}

RadioButton::~RadioButton(){

}

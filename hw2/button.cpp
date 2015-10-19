#include "button.h"


Button::Button(const QString & text, const QString & message) : QPushButton(text){
    messageBox = new QMessageBox;
    messageBox->setText(message);
    messageBox->addButton(QMessageBox::Ok);
    QObject::connect(this, SIGNAL(clicked(bool)), messageBox, SLOT(show()));
}

Button::Button(const QString &text) : QPushButton(text){
    messageBox = NULL;
}

Button::~Button(){
    delete messageBox;
}

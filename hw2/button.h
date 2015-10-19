#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QMessageBox>

class Button : public QPushButton
{
    QMessageBox * messageBox;
public:
    Button(const QString & text);
    Button(const QString & text, const QString & message);
    ~Button();
signals:

public slots:

};

#endif // BUTTON_H

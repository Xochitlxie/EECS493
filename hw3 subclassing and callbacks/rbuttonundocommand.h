#ifndef RBUTTONUNDOCOMMAND_H
#define RBUTTONUNDOCOMMAND_H

#include "radiobutton.h"
#include <QUndoCommand>

class RButtonUndoCommand : public QUndoCommand
{
    bool increment;
    RadioButton * button;
public:
    RButtonUndoCommand(bool increment, RadioButton * button);
    void undo(); Q_DECL_OVERRIDE;
    void redo(); Q_DECL_OVERRIDE;


    ~RButtonUndoCommand();
signals:

public slots:
};

#endif // RBUTTONUNDOCOMMAND_H

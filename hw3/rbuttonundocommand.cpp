#include "rbuttonundocommand.h"

RButtonUndoCommand::RButtonUndoCommand(bool increment, RadioButton * button) : increment(increment), button(button)
{
}

void RButtonUndoCommand::redo(){
    if(increment){
        button->increment();
    }
    else
        button->decrement();
}

void RButtonUndoCommand::undo(){
    if(increment){
        button->decrement();
    }
    else
        button->increment();
}

RButtonUndoCommand::~RButtonUndoCommand(){

}

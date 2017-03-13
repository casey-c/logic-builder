#ifndef COMMANDINVOKER_H
#define COMMANDINVOKER_H

#include "icommand.h"
#include <QStack>
#include <QObject>

class CommandInvoker : public QObject
{
    Q_OBJECT

public:
    CommandInvoker() {}
    ~CommandInvoker() {}

    void runCommand(ICommand* comm);
    void repeatLastCommand();

    void undoLastCommand();
    void redoLastCommand();

signals:
    void updateMenu(QString undo, QString redo, QString repeat,
                    bool undoable, bool redoable, bool repeatable);

private:
    QStack<ICommand*> commandStack;
    QStack<ICommand*> undoStack;

    void update();

};

#endif // COMMANDINVOKER_H

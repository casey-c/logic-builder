#include "commandinvoker.h"

/*
 * Executes the command
 */
void CommandInvoker::runCommand(ICommand *comm)
{
    // Command was successful
    if (comm->execute())
    {
        // Add it to the stack
        commandStack.append(comm);

        // Clear any undoable commands
        undoStack.clear();

        // Update any signals
        update();
    }
}

/*
 * Repeats the last command
 */
void CommandInvoker::repeatLastCommand()
{
    // Nothing to repeat
    if (commandStack.empty())
        return;

    runCommand(commandStack.last()->copy());
    update();
}

/*
 * Undo the last command
 */
void CommandInvoker::undoLastCommand()
{
    // Nothing to undo
    if (commandStack.empty())
        return;

    ICommand* command = commandStack.pop();
    command->undo();

    undoStack.append(command);
    update();
}

/*
 * Redo the last undone command
 */
void CommandInvoker::redoLastCommand()
{
    // Nothing to redo
    if (undoStack.empty())
        return;

    // Attempt to redo the last undone command
    ICommand* command = undoStack.pop();
    if (command->redo())
    {
        commandStack.append(command);
        update();
    }
    else // Put it back on the undo stack since nothing changed
        undoStack.append(command);
}

/*
 * Updates bookkeeping on a command change
 */
void CommandInvoker::update()
{
    QString undo = "Undo";
    QString redo = "Redo";
    QString repeat = "Repeat";

    // Undo
    bool undoable = (!commandStack.isEmpty());
    bool repeatable = undoable;

    if (undoable)
    {
        ICommand* command = commandStack.top();
        undo.append(": " + command->getText());
        redo.append(": " + command->getText());
    }

    // Redo
    bool redoable = (!undoStack.isEmpty());

    if (redoable)
    {
        ICommand* command = undoStack.top();
        redo.append(": " + command->getText());
    }

    // Emit the signal
    emit updateMenu(undo, redo, repeat, undoable, redoable, repeatable);
}





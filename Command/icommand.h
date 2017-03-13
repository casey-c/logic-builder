#ifndef ICOMMAND_H
#define ICOMMAND_H


/*
 * Interface for commands
 */
class ICommand
{
public:
    virtual bool execute() = 0;
    virtual void undo() = 0;
    virtual bool redo() { return execute(); }

    virtual ICommand* copy() = 0;

    QString getText() { return text; }

protected:
    QString text;
};

#endif // ICOMMAND_H

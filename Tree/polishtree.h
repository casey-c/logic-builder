#ifndef POLISHTREE_H
#define POLISHTREE_H

#include "polishnode.h"
#include <QStack>
#include <QObject>

class PolishTree : public QObject
{
    Q_OBJECT

public:
    /* Constructor */
    PolishTree() : root(nullptr) {}

    /* Destructor */
    ~PolishTree();

    /* Add nodes */
    bool addNArityNode(int arity, QString t);

    /* Print functions */
    QString toPlaintextString();
    QString toLatexString(QString plain);
    QString toLispString();
    QString toTreeString();

    void redraw();

signals:
    void treeChanged(QString plain, QString latex, QString lisp);
    void wffCreated(QString plain);

private:
    PolishNode* root;
    QStack<PolishNode*> stack;
};

#endif // POLISHTREE_H

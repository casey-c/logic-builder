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
    PolishTree();

    /* Destructor */
    ~PolishTree();

    /* Add nodes */
    bool addNArityNode(int arity, QString t);
    //void addNullaryOperator(QString n) { addNArityOperator(0,n); }
    //void addUnaryOperator(QString n) { addNArityOperator(1,n); }
    //void addBinaryOperator(QString n) { addNArityOperator(2,n); }

    /* Print functions */
    QString toPlaintextString();
    QString toLatexString();
    QString toLispString();
    QString toTreeString();

    void redraw();

signals:
    void treeChanged(QString plain, QString latex, QString lisp);

private:
    PolishNode* root;
    QStack<PolishNode*> stack;
};

#endif // POLISHTREE_H

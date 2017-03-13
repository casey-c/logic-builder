#ifndef POLISHTREE_H
#define POLISHTREE_H

#include "polishnode.h"
#include <QStack>

class PolishTree
{
public:
    /* Constructor */
    PolishTree();

    /* Destructor */
    ~PolishTree();

    /* Add nodes */
    bool addNArityOperator(int arity, QString n);
    //void addNullaryOperator(QString n) { addNArityOperator(0,n); }
    //void addUnaryOperator(QString n) { addNArityOperator(1,n); }
    //void addBinaryOperator(QString n) { addNArityOperator(2,n); }

    /* Print functions */
    QString toPlaintextString();
    QString toLatexString();
    QString toLispString();
    QString toTreeString();

private:
    PolishNode* root;
    QStack<PolishNode*> stack;
};

#endif // POLISHTREE_H

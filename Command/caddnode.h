#ifndef CADDNODE_H
#define CADDNODE_H

#include "icommand.h"
#include "Tree/polishtree.h"
#include "Tree/polishnode.h"

class CAddNode : public ICommand
{
public:
    CAddNode(PolishTree* t, QString o, int a) :
        tree(t),
        op(o),
        arity(a) {
        text = "Add " + o;
    }

    bool execute();
    void undo();

    ICommand* copy() { return new CAddNode(tree, op, arity); }

private:
    PolishTree* tree;
    PolishNode* node;

    QString op;
    int arity;

};

#endif // CADDNODE_H

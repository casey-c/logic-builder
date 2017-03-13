#ifndef CADDNODE_H
#define CADDNODE_H

#include "icommand.h"
#include "Tree/polishtree.h"
#include "Tree/polishnode.h"

class CAddNode : public ICommand
{
public:
    CAddNode(PolishTree* t, QString n, int a) :
        tree(t),
        nodeText(n),
        arity(a) {
        text = "Add " + n;
    }

    bool execute();
    void undo();

    ICommand* copy() { return new CAddNode(tree, nodeText, arity); }

private:
    PolishTree* tree;
    PolishNode* node;

    QString nodeText;
    int arity;

};

#endif // CADDNODE_H

#ifndef POLISHNODE_H
#define POLISHNODE_H

#include <QList>

class PolishNode
{
public:
    /* Constructor */
    PolishNode();

    /* Destructor */
    ~PolishNode();

    /* Add nodes */
    PolishNode* makeNewChild(int type, QString n);

    /* Boolean identifiers */
    bool isLeaf() { return children.isEmpty(); }
    bool isWrappedWithParens() { return wrappedWithParens; }

private:
    /* Connections */
    PolishNode* parent;
    QList<PolishNode*> children;

    /* Details */
    QString name;
    int nodeType;
    bool wrappedWithParens;
};

#endif // POLISHNODE_H

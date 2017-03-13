#ifndef POLISHNODE_H
#define POLISHNODE_H

#include <QList>

/*
 * Polish nodes store a QString label describing it (either an operator symbol
 * or a letter) as well as connections to other nodes on the tree.
 *
 * The first node must be created through the makeFirstNode factory, while the
 * rest are created from an existing node using makeNewChild(). This pattern
 * hopes to maintain the acyclic tree structure by restricting how nodes are
 * manufactured outside of the class.
 *
 * The use of the named factory hopefully makes it more intuitive how to make
 * a new Tree with a new root.
 *
 * The destructor will recursively delete all of its children. Because of this,
 * it is sufficient to call delete only on the first (root) node. All the
 * dynamically allocated memory will be cleaned up automatically with this call.
 *
 * Nodes have a couple of details:
 *      parent: the node above the current one in the tree. The first (root)
 *              node has a nullptr parent.
 *      text:   the printed form of the node; this can be a symbol like ∧ or ∨
 *              or a letter like P or Q.
 *      op:     whether or not the node is allowed to have kids of its own
 *      wrapped: indicates whether the node should be wrapped in parentheses.
 *              this occurs when an operator is a direct child of an operator.
 *              the first (root) node is never wrapped. every other node's
 *              wrapping is determined by whether it is an operator and its
 *              direct parent is also an operator.
 *
 * Newly created nodes have no details yet. These are placeholder nodes added
 * to the stack in PolishTree. Only once they are popped from the top with a
 * keypress do they get any details like an operator symbol or a letter.
 */
class PolishNode
{
public:
    /* Factory Constructor */
    static PolishNode* makeFirstNode(QString t, bool o)
        { return new PolishNode(nullptr, t, o, false); }

    /* Destructor */
    ~PolishNode();

    /* Add nodes */
    PolishNode* makeNewChild();
    void setDetails(QString t, bool o);

    /* Boolean identifiers */
    bool isLeaf() { return children.isEmpty(); }

    /* Getters */
    QString getText() { return text; }

private:
    /* Private Constructor */
    PolishNode(PolishNode* parent, QString t, bool o, bool w) :
        parent(parent),
        text(t),
        op(o),
        wrapped(w) {}

    /* Connections */
    PolishNode* parent;
    QList<PolishNode*> children;

    /* Details */
    QString text;
    bool op;
    bool wrapped;
};

#endif // POLISHNODE_H

#include "polishnode.h"

//////////////////
/// Destructor ///
//////////////////

/*
 * Destructor deletes all child nodes recursively
 */
PolishNode::~PolishNode()
{
    for (PolishNode* child : children)
        delete child;
}

////////////////////////
/// Create new nodes ///
////////////////////////

/*
 * Creates a new node beneath this one.
 *
 * Returns:
 *      the newly created node
 */
PolishNode* PolishNode::makeNewChild()
{
    // Only operators can have children
    if (!op)
        return nullptr;

    // New nodes have no details yet
    PolishNode* newNode = new PolishNode(this, "___", false, false);
    children.append(newNode);
    return newNode;
}

/*
 * Sets the details of a node
 */
void PolishNode::setDetails(QString t, bool o)
{
    text = t;
    op = wrapped = o;
}

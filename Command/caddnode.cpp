#include "caddnode.h"

/*
 * Adds a node to the tree
 */
bool CAddNode::execute()
{
    bool success = tree->addNArityNode(arity, nodeText);

    // If we've done any changes, redraw the tree
    if (success)
        tree->redraw();

    return success;
}

/*
 * Removes the added node
 */
void CAddNode::undo()
{

}

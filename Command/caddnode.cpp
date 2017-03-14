#include "caddnode.h"

/*
 * Adds a node to the tree
 */
bool CAddNode::execute()
{
    return tree->addNArityNode(arity, nodeText);
}

/*
 * Removes the added node
 */
void CAddNode::undo()
{

}

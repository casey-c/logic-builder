#include "caddnode.h"

/*
 * Adds a node to the tree
 */
bool CAddNode::execute()
{
    return tree->addNArityOperator(arity,op);
}

/*
 * Removes the added node
 */
void CAddNode::undo()
{

}

#include "polishtree.h"
#include <QDebug>

//////////////////////////////////
/// Constructor and Destructor ///
//////////////////////////////////

/*
 * Constructor
 */
PolishTree::PolishTree()
{
    // TODO: implementation
}

/*
 * Destructor deletes the root node
 */
PolishTree::~PolishTree()
{
    if (root != nullptr)
        delete root;
}

/////////////////
/// Additions ///
/////////////////

/*
 * The main add function
 *
 * Returns:
 *      true if successfully added the node and all potential children
 *      false otherwise
 */
bool PolishTree::addNArityNode(int arity, QString t, bool o)
{
    // No first node yet
    if (root == nullptr)
    {
        // Make the first node
        root = PolishNode::makeFirstNode(t, o);

        // Add the proper number of child nodes
        for (int i = 0; i < arity; ++i)
            stack.push(root->makeNewChild());

        // Don't want to do anything else yet
        return true;
    }

    // Root node already exists but stack is empty (WFF already)
    if (stack.isEmpty())
    {
        qDebug() << "We already have a WFF!";
        return false;
    }

    // Set the details and make the children for this node
    PolishNode* node = stack.pop();
    node->setDetails(t, o);

    for (int i = 0; i < arity; ++i)
    {
        PolishNode* child = node->makeNewChild();

        // No child created (THIS SHOULD NEVER BE ENTERED)
        if (child == nullptr)
        {
            qDebug() << "Couldn't add the child for whatever reason";
            return false;
        }
        else // Push the new kid onto the stack
            stack.push(child);
    }

    // Check to see if we've made a WFF yet
    if (stack.isEmpty())
        qDebug() << "We made a WFF!";

    return true;
}

/////////////
/// Print ///
/////////////

/*
 * Returns a plaintext QString representation of the tree
 */
QString PolishTree::toPlaintextString()
{
    // TODO: implementation
    return nullptr;
}

/*
 * Returns a LaTeX QString representation of the tree
 */
QString PolishTree::toLatexString()
{
    // TODO: implementation
    return nullptr;
}

/*
 * Returns a LISP QString representation of the tree
 */
QString PolishTree::toLispString()
{
    // TODO: implementation
    return nullptr;
}

/*
 * Returns a plaintext tree depiction
 */
QString PolishTree::toTreeString()
{
    // TODO: implementation
    return nullptr;
}

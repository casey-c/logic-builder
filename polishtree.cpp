#include "polishtree.h"

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
 */
void PolishTree::addNArityOperator(int arity, QString n)
{
    // TODO: implementation
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

#include "polishtree.h"
#include <QDebug>

//////////////////
/// Destructor ///
//////////////////

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
bool PolishTree::addNArityNode(int arity, QString t)
{
    // If the arity is positive, we have an operator
    bool o = (arity > 0);

    // No first node yet
    if (root == nullptr)
    {
        // Make the first node
        root = PolishNode::makeFirstNode(t, o);

        // Add the proper number of child nodes
        for (int i = 0; i < arity; ++i)
            stack.push(root->makeNewChild());

        // Check to see if we've made a WFF yet
        if (stack.isEmpty())
        {
            wff = true;
            QString plain = toPlaintextString();
            emit wffCreated(plain, toLatexString(plain), toLispString());
        }

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
    {
        wff = true;
        QString plain = toPlaintextString();
        emit wffCreated(plain, toLatexString(plain), toLispString());
    }

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
    // If no root, we have an empty string
    if (root == nullptr)
        return "";

    // Otherwise recurse off of the root
    return root->getPlaintext();
}

/*
 * Returns a LaTeX QString representation of the tree
 */
QString PolishTree::toLatexString(QString plain)
{
    // LaTeX format takes the plaintext and converts the following symbols:
    //   * ∧: \land
    //   * ∨: \lor
    //   * ¬: \neg
    //   * →: \to
    //   * ↔: \leftrightarrow
    QString result = plain.replace("∧", "\\land");
    result = result.replace("∨", "\\lor");
    result = result.replace("¬", "\\neg ");
    result = result.replace("→", "\\to");
    result = result.replace("↔", "\\leftrightarrow");

    return result;
}

/*
 * Returns a LISP QString representation of the tree
 */
QString PolishTree::toLispString()
{
    // Nothing to convert
    if (root == nullptr)
        return "";

    else
        return root->getLisp();
}

/*
 * Returns a plaintext tree depiction
 */
QString PolishTree::toTreeString()
{
    // TODO: implementation
    return nullptr;
}

void PolishTree::redraw()
{
    QString plain = toPlaintextString();
    emit(treeChanged(plain, toLatexString(plain), toLispString()));
}

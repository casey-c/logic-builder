#include "polishnode.h"
#include <QStack>

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
    children.prepend(newNode);
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

/////////////
/// Print ///
/////////////

/*
 * Recursive function to get a plaintext string
 */
QString PolishNode::getPlaintext()
{
    QString result = "";

    // Opening parens
    if (wrapped && (children.size() > 1))
        result += "(";

    // Non operators just include their text
    if (!op)
        result += text;

    // Operators must include each of their children separated by this op symbol
    else
    {
        // Single arity check
        if (children.size() == 1)
            result += text + children.at(0)->getPlaintext();

        // For arities > 1
        else
        {
            for (int i = 0; i < children.size(); ++i)
            {
                result += children.at(i)->getPlaintext();

                // Add the operator in between
                if (i != children.size() - 1)
                    result += " " + text + " ";
            }
        }
    }

    // Closing parens
    if (wrapped && (children.size() > 1))
        result += ")";

    return result;
}

/*
 * Runs a DFS to generate the same order of commands entered. Obviously, it
 * would be more efficient to just save the order of keypresses as you type
 * them, but this way also produces the ___ characters of the next inputs.
 *
 * I kind of like that feature, so I'm going to make the LISP output do all this
 * work here.
 *
 * Note: this function is ideally run off of root as that will get all the
 * commands for the whole tree, but it can work on a younger node too.
 */
QString PolishNode::getLisp()
{
    QString result = "";

    // DFS based
    QStack<PolishNode*> stack;
    stack.push(this);

    while (!stack.isEmpty())
    {
        PolishNode* node = stack.pop();

        // Add the text
        result += node->text + " ";

        // Add the children
        QList<PolishNode*>::reverse_iterator it = node->children.rbegin();
        for (; it != node->children.rend(); ++it)
            stack.push((*it));
    }

    // Chop off the final space
    if (result.length() > 0)
        return result.left(result.length() - 1);
    else
        return "";

}













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













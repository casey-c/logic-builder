#include "testplaintext.h"
#include "Tree/polishtree.h"

///////////////////
/// Basic tests ///
///////////////////

/*
 * Tests plaintext output for an empty tree
 */
void TestPlaintext::emptyTree()
{
    PolishTree* tree = new PolishTree();
    QCOMPARE(tree->toPlaintextString(), QString(""));
    delete tree;
}

/*
 * Tests a single P on the tree
 */
void TestPlaintext::singleP()
{
    PolishTree* tree = new PolishTree();

    // Add a single P to the tree
    tree->addNArityNode(0, "P");

    QCOMPARE(tree->toPlaintextString(), QString("P"));
    delete tree;
}

///////////////////////
/// Basic AND tests ///
///////////////////////

/*
 * Tests an empty AND operator
 */
void TestPlaintext::emptyAnd()
{
    PolishTree* tree = new PolishTree();

    // Add a single AND to the tree
    tree->addNArityNode(2, "∧");

    QCOMPARE(tree->toPlaintextString(), QString("___ ∧ ___"));
    delete tree;
}

/*
 * Tests an AND with a single P
 */
void TestPlaintext::andP()
{
    PolishTree* tree = new PolishTree();

    // Add AND followed by P
    tree->addNArityNode(2, "∧");
    tree->addNArityNode(0, "P");

    QCOMPARE(tree->toPlaintextString(), QString("P ∧ ___"));
    delete tree;
}

/*
 * Tests an AND followed by P and Q
 */
void TestPlaintext::andPQ()
{
    PolishTree* tree = new PolishTree();

    // Add AND followed by P
    tree->addNArityNode(2, "∧");
    tree->addNArityNode(0, "P");
    tree->addNArityNode(0, "Q");

    QCOMPARE(tree->toPlaintextString(), QString("P ∧ Q"));
    delete tree;
}

/////////////////
/// NOT tests ///
/////////////////

/*
 * Tests an empty NOT
 */
void TestPlaintext::emptyNot()
{
    PolishTree* tree = new PolishTree();

    // Add NOT
    tree->addNArityNode(1, "¬");

    QCOMPARE(tree->toPlaintextString(), QString("¬___"));
    delete tree;
}

/*
 * Tests NOT, followed by P
 */
void TestPlaintext::notP()
{
    PolishTree* tree = new PolishTree();

    // Add NOT, P
    tree->addNArityNode(1, "¬");
    tree->addNArityNode(0, "P");

    QCOMPARE(tree->toPlaintextString(), QString("¬P"));
    delete tree;
}

//////////////////////////
/// Two operator tests ///
//////////////////////////

/*
 * Tests an AND followed by an OR
 */
void TestPlaintext::andOr()
{
    PolishTree* tree = new PolishTree();

    // Add AND followed by OR
    tree->addNArityNode(2, "∧");
    tree->addNArityNode(2, "∨");

    QCOMPARE(tree->toPlaintextString(), QString("(___ ∨ ___) ∧ ___"));
    delete tree;
}

/*
 * Tests &|P
 */
void TestPlaintext::andOrP()
{
    PolishTree* tree = new PolishTree();

    // Add AND, OR, P
    tree->addNArityNode(2, "∧");
    tree->addNArityNode(2, "∨");
    tree->addNArityNode(0, "P");

    QCOMPARE(tree->toPlaintextString(), QString("(P ∨ ___) ∧ ___"));
    delete tree;
}

/*
 * Tests &|PQ
 */
void TestPlaintext::andOrPQ()
{
    PolishTree* tree = new PolishTree();

    // Add AND, OR, P, Q
    tree->addNArityNode(2, "∧");
    tree->addNArityNode(2, "∨");
    tree->addNArityNode(0, "P");
    tree->addNArityNode(0, "Q");

    QCOMPARE(tree->toPlaintextString(), QString("(P ∨ Q) ∧ ___"));
    delete tree;
}

/*
 * Tests &|PQR
 */
void TestPlaintext::andOrPQR()
{
    PolishTree* tree = new PolishTree();

    // Add AND, OR, P, Q, R
    tree->addNArityNode(2, "∧");
    tree->addNArityNode(2, "∨");
    tree->addNArityNode(0, "P");
    tree->addNArityNode(0, "Q");
    tree->addNArityNode(0, "R");

    QCOMPARE(tree->toPlaintextString(), QString("(P ∨ Q) ∧ R"));
    delete tree;
}

////////////////////////////////////
/// Multiple operators, with NOT ///
////////////////////////////////////

/*
 * AND, OR, NOT, P, Not, Q
 */
void TestPlaintext::andOrNotPNotQ()
{
    PolishTree* tree = new PolishTree();

    // Add AND, OR, P, Q, R
    tree->addNArityNode(2, "∧");
    tree->addNArityNode(2, "∨");
    tree->addNArityNode(1, "¬");
    tree->addNArityNode(0, "P");
    tree->addNArityNode(1, "¬");
    tree->addNArityNode(0, "Q");

    QCOMPARE(tree->toPlaintextString(), QString("(¬P ∨ ¬Q) ∧ ___"));
    delete tree;
}

/*
 * AND, OR, NOT, P, Not, Q, Not, And, R, S
 */
void TestPlaintext::andOrNotPNotQNotAndRS()
{
    PolishTree* tree = new PolishTree();

    // Add AND, OR, P, Q, R
    tree->addNArityNode(2, "∧");
    tree->addNArityNode(2, "∨");
    tree->addNArityNode(1, "¬");
    tree->addNArityNode(0, "P");
    tree->addNArityNode(1, "¬");
    tree->addNArityNode(0, "Q");

    tree->addNArityNode(1, "¬");
    tree->addNArityNode(2, "∧");
    tree->addNArityNode(0, "R");
    tree->addNArityNode(0, "S");

    QCOMPARE(tree->toPlaintextString(), QString("(¬P ∨ ¬Q) ∧ ¬(R ∧ S)"));
    delete tree;
}

/////////////////////////
/// Ternary Operators ///
/////////////////////////

/*
 * Ternary empty AND
 */
void TestPlaintext::ternaryEmptyAnd()
{
    PolishTree* tree = new PolishTree();

    // Empty 3 arity AND
    tree->addNArityNode(3, "∧");

    QCOMPARE(tree->toPlaintextString(), QString("___ ∧ ___ ∧ ___"));
    delete tree;
}

/*
 * Ternary AND, P
 */
void TestPlaintext::ternaryAndP()
{
    PolishTree* tree = new PolishTree();

    // Ternary AND, P
    tree->addNArityNode(3, "∧");
    tree->addNArityNode(0, "P");

    QCOMPARE(tree->toPlaintextString(), QString("P ∧ ___ ∧ ___"));
    delete tree;
}

/*
 * Ternary AND, P, Q
 */
void TestPlaintext::ternaryAndPQ()
{
    PolishTree* tree = new PolishTree();

    // Ternary AND, P
    tree->addNArityNode(3, "∧");
    tree->addNArityNode(0, "P");
    tree->addNArityNode(0, "Q");

    QCOMPARE(tree->toPlaintextString(), QString("P ∧ Q ∧ ___"));
    delete tree;
}

/*
 * Ternary AND, P, Q, R
 */
void TestPlaintext::ternaryAndPQR()
{
    PolishTree* tree = new PolishTree();

    // Ternary AND, P
    tree->addNArityNode(3, "∧");
    tree->addNArityNode(0, "P");
    tree->addNArityNode(0, "Q");
    tree->addNArityNode(0, "R");

    QCOMPARE(tree->toPlaintextString(), QString("P ∧ Q ∧ R"));
    delete tree;
}

QTEST_MAIN(TestPlaintext)

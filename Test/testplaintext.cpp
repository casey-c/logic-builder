#include "testplaintext.h"
#include "Tree/polishtree.h"


void TestPlaintext::emptyTree()
{
    PolishTree* tree = new PolishTree();
    QCOMPARE(tree->toPlaintextString(), QString(""));
    delete tree;
}

QTEST_MAIN(TestPlaintext)

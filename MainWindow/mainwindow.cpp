#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Tree/polishtree.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Test the tree
    PolishTree* tree = new PolishTree();

    qDebug() << tree->toPlaintextString();

    // Add binary and
    tree->addNArityNode(2,"&");
    qDebug() << tree->toPlaintextString();

    // Add left "P"
    tree->addNArityNode(0, "P");
    qDebug() << tree->toPlaintextString();

    // Add right "Q"
    tree->addNArityNode(0, "Q");
    qDebug() << tree->toPlaintextString();

    // Test 2
    qDebug() << "\nNew test:";
    tree = new PolishTree();

    qDebug() << tree->toPlaintextString();

    // Add binary and
    tree->addNArityNode(2,"&");
    qDebug() << tree->toPlaintextString();

    // Add binary or
    tree->addNArityNode(2, "|");
    qDebug() << tree->toPlaintextString();

    // Add left "P"
    tree->addNArityNode(0, "P");
    qDebug() << tree->toPlaintextString();

    // Add right "Q"
    tree->addNArityNode(0, "Q");
    qDebug() << tree->toPlaintextString();

    // Add right "R"
    tree->addNArityNode(0, "R");
    qDebug() << tree->toPlaintextString();

    // Test 3
    qDebug() << "\nNew test:";
    tree = new PolishTree();

    qDebug() << tree->toPlaintextString();

    // Add binary and
    tree->addNArityNode(2,"&");
    qDebug() << tree->toPlaintextString();

    // Add binary or
    tree->addNArityNode(2, "|");
    qDebug() << tree->toPlaintextString();

    // Add left "P"
    tree->addNArityNode(0, "P");
    qDebug() << tree->toPlaintextString();

    // Add right "Q"
    tree->addNArityNode(0, "Q");
    qDebug() << tree->toPlaintextString();

    // Add right "R"
    tree->addNArityNode(0, "R");
    qDebug() << tree->toPlaintextString();

    // Try and add an node after we already have a WFF
    tree->addNArityNode(0, "S");
    qDebug() << tree->toPlaintextString();

    /// Test 4 ///
    qDebug() << "\nNew test:";
    tree = new PolishTree();

    qDebug() << tree->toPlaintextString();

    // Add binary and
    tree->addNArityNode(2,"&");
    qDebug() << tree->toPlaintextString();

    // Add binary or
    tree->addNArityNode(2, "|");
    qDebug() << tree->toPlaintextString();

    // Add left "P"
    tree->addNArityNode(0, "P");
    qDebug() << tree->toPlaintextString();

    // Add right NOT
    tree->addNArityNode(1, "~");
    qDebug() << tree->toPlaintextString();

    // Add > child
    tree->addNArityNode(2, ">");
    qDebug() << tree->toPlaintextString();
    // Add Q
    tree->addNArityNode(0, "Q");
    qDebug() << tree->toPlaintextString();
    // Add not
    tree->addNArityNode(1, "~");
    qDebug() << tree->toPlaintextString();
    // Add R
    tree->addNArityNode(0, "R");
    qDebug() << tree->toPlaintextString();

    // Add final s
    tree->addNArityNode(0, "S");
    qDebug() << tree->toPlaintextString();


}

MainWindow::~MainWindow()
{
    delete ui;
}

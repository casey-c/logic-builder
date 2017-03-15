#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Tree/polishtree.h"

#include "Command/caddnode.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tree = new PolishTree();
    commandInvoker = new CommandInvoker();

    listModel = new QStringListModel(formulaList, NULL);
    ui->listView->setModel(listModel);

    // Connections
    connect(tree,
            SIGNAL(treeChanged(QString,QString,QString)),
            this,
            SLOT(updateText(QString,QString,QString)));

    connect(tree,
            SIGNAL(wffCreated(QString)),
            this,
            SLOT(addWFF(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tree;
}

/*
 * Handles a key press
 */
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // Letters A-Z add statements
    if (event->key() >= 65 && event->key() <= 90)
    {
        ICommand* command = new CAddNode(tree, event->text().toUpper(), 0);
        commandInvoker->runCommand(command);
        return;
    }

    // Operators will use the binary helper (except for NOT which needs a unary)
    switch (event->key())
    {
    case Qt::Key_Ampersand:
        addBinaryOperatorHelper("∧");
        break;
    case Qt::Key_Bar:
        addBinaryOperatorHelper("∨");
        break;
    case Qt::Key_Dollar:
        addBinaryOperatorHelper("→");
        break;
    case Qt::Key_Percent:
        addBinaryOperatorHelper("↔");
        break;
    case Qt::Key_AsciiTilde:
    {
        ICommand* command = new CAddNode(tree, "¬", 1);
        commandInvoker->runCommand(command);
        break;
    }
    default: // Pass it on
        QMainWindow::keyPressEvent(event);
    }
}

void MainWindow::addBinaryOperatorHelper(QString op)
{
    ICommand* command = new CAddNode(tree, op, 2);
    commandInvoker->runCommand(command);
}

///////////////
/// Updates ///
///////////////

/*
 * Slot updates the ui text boxes
 */
void MainWindow::updateText(QString plain, QString latex, QString lisp)
{
    ui->line_plain->setText(plain);
    ui->line_latex->setText(latex);
    ui->line_lisp->setText(lisp);
}

void MainWindow::addWFF(QString plain)
{
    formulaList.append(plain);
    listModel->setStringList(formulaList);
}

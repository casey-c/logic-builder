#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Tree/polishtree.h"

#include "Command/caddnode.h"

#include <QDebug>
#include <QClipboard>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    autocopy(true)
{
    ui->setupUi(this);

    tree = new PolishTree();
    commandInvoker = new CommandInvoker();

    listModel = new QStringListModel(formulaList, NULL);
    ui->listView->setModel(listModel);

    // Autocopy
    autocopyGroup = new QActionGroup(this);
    ui->menu_autocopy_disable->setActionGroup(autocopyGroup);
    ui->menu_autocopy_plain->setActionGroup(autocopyGroup);
    ui->menu_autocopy_latex->setActionGroup(autocopyGroup);
    ui->menu_autocopy_lisp->setActionGroup(autocopyGroup);

    // Make sure changes in the group update
    connect(autocopyGroup,
            SIGNAL(triggered(QAction*)),
            this,
            SLOT(changeAutoCopy(QAction*)));


    // Connect the tree's signals to these slots
    connectTree();
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
    qDebug() << "key press " << event->text();

    // Letters A-Z add statements
    if (event->key() >= 65 && event->key() <= 90)
    {
        addNodeHelper(event->text().toUpper(), 0);
        return;
    }

    // Operators will use the binary helper (except for NOT which needs a unary)
    switch (event->key())
    {
    case Qt::Key_Ampersand:
        addNodeHelper("∧", 2);
        break;
    case Qt::Key_Bar:
        addNodeHelper("∨", 2);
        break;
    case Qt::Key_Dollar:
        addNodeHelper("→", 2);
        break;
    case Qt::Key_Percent:
        addNodeHelper("↔", 2);
        break;
    case Qt::Key_AsciiTilde:
        addNodeHelper("¬", 1);
        break;
    default: // Pass it on
        QMainWindow::keyPressEvent(event);
    }
}

void MainWindow::addNodeHelper(QString text, int arity)
{
    // Check for WFF
    if (tree->isWFF())
    {
        // Get rid of the old tree
        disconnect(tree);

        // Make a new one and connect
        tree = new PolishTree();
        connectTree();
    }

    ICommand* command = new CAddNode(tree, text, arity);
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

void MainWindow::addWFF(QString plain, QString latex, QString lisp)
{
    formulaList.append(plain);
    listModel->setStringList(formulaList);

    // Auto-copy
    if (!autocopy)
        return;

    // Copy to clipboard
    if (ui->menu_autocopy_plain->isChecked())
        QApplication::clipboard()->setText(plain);
    else if (ui->menu_autocopy_latex->isChecked())
        QApplication::clipboard()->setText(latex);
    else if (ui->menu_autocopy_lisp->isChecked())
        QApplication::clipboard()->setText(lisp);
}

void MainWindow::connectTree()
{
    connect(tree,
            SIGNAL(treeChanged(QString,QString,QString)),
            this,
            SLOT(updateText(QString,QString,QString)));

    connect(tree,
            SIGNAL(wffCreated(QString,QString,QString)),
            this,
            SLOT(addWFF(QString,QString,QString)));
}

void MainWindow::on_button_copy_plain_clicked()
{
    QApplication::clipboard()->setText(ui->line_plain->text());
}

void MainWindow::on_button_copy_latex_clicked()
{
    QApplication::clipboard()->setText(ui->line_latex->text());
}

void MainWindow::on_button_copy_lisp_clicked()
{
    QApplication::clipboard()->setText(ui->line_lisp->text());
}

void MainWindow::changeAutoCopy(QAction *action)
{
    // Enable autocopy on everything but disable
    autocopy = (action != ui->menu_autocopy_disable);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

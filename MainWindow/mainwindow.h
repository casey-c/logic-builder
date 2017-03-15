#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include "Tree/polishtree.h"
#include "Command/commandinvoker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PolishTree* tree;
    CommandInvoker* commandInvoker;
    void keyPressEvent(QKeyEvent* event);

    void addBinaryOperatorHelper(QString op);

    QStringList formulaList;
    QStringListModel* listModel;

public slots:
    void updateText(QString plain, QString latex, QString lisp);
    void addWFF(QString plain);
};

#endif // MAINWINDOW_H

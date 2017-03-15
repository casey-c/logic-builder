#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QActionGroup>

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

    void addNodeHelper(QString text, int arity);

    void connectTree();

    QStringList formulaList;
    QStringListModel* listModel;

    bool autocopy;

    QActionGroup* autocopyGroup;

public slots:
    void updateText(QString plain, QString latex, QString lisp);
    void addWFF(QString plain, QString latex, QString lisp);

private slots:
    /* Copy buttons */
    void on_button_copy_plain_clicked();
    void on_button_copy_latex_clicked();
    void on_button_copy_lisp_clicked();


    void changeAutoCopy(QAction* action);
    void on_actionExit_triggered();
};

#endif // MAINWINDOW_H

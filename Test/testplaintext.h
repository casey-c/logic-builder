#ifndef TESTPLAINTEXT_H
#define TESTPLAINTEXT_H

#include <QObject>
#include <QtTest/QtTest>

class TestPlaintext : public QObject
{
    Q_OBJECT

private slots:
    /* Basic tests */
    void emptyTree();
    void singleP();

    /* Basic AND tests */
    void emptyAnd();
    void andP();
    void andPQ();

    /* NOT test */
    void emptyNot();
    void notP();

    /* 2 operators */
    void andOr();
    void andOrP();
    void andOrPQ();
    void andOrPQR();

    /* Multiple operators, with NOT */
    void andOrNotPNotQ();
    void andOrNotPNotQNotAndRS();

    /* Ternary operators */
    void ternaryEmptyAnd();
    void ternaryAndP();
    void ternaryAndPQ();
    void ternaryAndPQR();
};

#endif // TESTPLAINTEXT_H

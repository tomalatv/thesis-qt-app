/********************************************************************************
** Form generated from reading UI file 'testdialog.ui'
**
** Created: Tue 4. Sep 17:42:14 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTDIALOG_H
#define UI_TESTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_TestDialogClass
{
public:
    QComboBox *selectTest;
    QLineEdit *testRepeat;
    QPushButton *cancelTest;
    QPushButton *runTest;
    QTextBrowser *testResult;
    QPushButton *pushButton;

    void setupUi(QDialog *TestDialogClass)
    {
        if (TestDialogClass->objectName().isEmpty())
            TestDialogClass->setObjectName(QString::fromUtf8("TestDialogClass"));
        TestDialogClass->resize(180, 265);
        selectTest = new QComboBox(TestDialogClass);
        selectTest->setObjectName(QString::fromUtf8("selectTest"));
        selectTest->setGeometry(QRect(10, 20, 161, 22));
        testRepeat = new QLineEdit(TestDialogClass);
        testRepeat->setObjectName(QString::fromUtf8("testRepeat"));
        testRepeat->setGeometry(QRect(10, 50, 161, 20));
        cancelTest = new QPushButton(TestDialogClass);
        cancelTest->setObjectName(QString::fromUtf8("cancelTest"));
        cancelTest->setGeometry(QRect(10, 180, 75, 24));
        runTest = new QPushButton(TestDialogClass);
        runTest->setObjectName(QString::fromUtf8("runTest"));
        runTest->setGeometry(QRect(100, 180, 75, 24));
        testResult = new QTextBrowser(TestDialogClass);
        testResult->setObjectName(QString::fromUtf8("testResult"));
        testResult->setGeometry(QRect(10, 80, 161, 91));
        pushButton = new QPushButton(TestDialogClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 220, 141, 23));

        retranslateUi(TestDialogClass);
        QObject::connect(cancelTest, SIGNAL(clicked()), TestDialogClass, SLOT(close()));
        QObject::connect(runTest, SIGNAL(clicked()), TestDialogClass, SLOT(runTest()));
        QObject::connect(pushButton, SIGNAL(clicked()), TestDialogClass, SLOT(saveToFile()));

        QMetaObject::connectSlotsByName(TestDialogClass);
    } // setupUi

    void retranslateUi(QDialog *TestDialogClass)
    {
        TestDialogClass->setWindowTitle(QApplication::translate("TestDialogClass", "TestDialog", 0, QApplication::UnicodeUTF8));
        cancelTest->setText(QApplication::translate("TestDialogClass", "Cancel", 0, QApplication::UnicodeUTF8));
        runTest->setText(QApplication::translate("TestDialogClass", "Run test", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("TestDialogClass", "Save test result to file", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TestDialogClass: public Ui_TestDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTDIALOG_H

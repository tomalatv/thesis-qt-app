/********************************************************************************
** Form generated from reading ui file 'openfile.ui'
**
** Created: Fri 8. May 10:18:26 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_OPENFILE_H
#define UI_OPENFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>

QT_BEGIN_NAMESPACE

class Ui_OpenFileDialog
{
public:
    QDialogButtonBox *buttonBox;
    QListView *listView;

    void setupUi(QDialog *OpenFileDialog)
    {
        if (OpenFileDialog->objectName().isEmpty())
            OpenFileDialog->setObjectName(QString::fromUtf8("OpenFileDialog"));
        OpenFileDialog->resize(444, 358);
        buttonBox = new QDialogButtonBox(OpenFileDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(120, 310, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listView = new QListView(OpenFileDialog);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(20, 10, 411, 291));

        retranslateUi(OpenFileDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OpenFileDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OpenFileDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OpenFileDialog);
    } // setupUi

    void retranslateUi(QDialog *OpenFileDialog)
    {
        OpenFileDialog->setWindowTitle(QApplication::translate("OpenFileDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(OpenFileDialog);
    } // retranslateUi

};

namespace Ui {
    class OpenFileDialog: public Ui_OpenFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENFILE_H

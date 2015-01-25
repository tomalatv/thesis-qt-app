/********************************************************************************
** Form generated from reading UI file 'dialogselectfiles.ui'
**
** Created: Mon 22. Feb 21:14:46 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSELECTFILES_H
#define UI_DIALOGSELECTFILES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_DialogSelectFiles
{
public:
    QDialogButtonBox *buttonBox;
    QTreeView *treeView;
    QListView *listView;

    void setupUi(QDialog *DialogSelectFiles)
    {
        if (DialogSelectFiles->objectName().isEmpty())
            DialogSelectFiles->setObjectName(QString::fromUtf8("DialogSelectFiles"));
        DialogSelectFiles->resize(640, 480);
        buttonBox = new QDialogButtonBox(DialogSelectFiles);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 430, 621, 21));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        treeView = new QTreeView(DialogSelectFiles);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(10, 10, 251, 461));
        listView = new QListView(DialogSelectFiles);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(275, 11, 351, 411));

        retranslateUi(DialogSelectFiles);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogSelectFiles, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogSelectFiles, SLOT(reject()));
        QObject::connect(treeView, SIGNAL(activated(QModelIndex)), DialogSelectFiles, SLOT(showFiles()));

        QMetaObject::connectSlotsByName(DialogSelectFiles);
    } // setupUi

    void retranslateUi(QDialog *DialogSelectFiles)
    {
        DialogSelectFiles->setWindowTitle(QApplication::translate("DialogSelectFiles", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogSelectFiles: public Ui_DialogSelectFiles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSELECTFILES_H

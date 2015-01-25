/********************************************************************************
** Form generated from reading UI file 'multimediax.ui'
**
** Created: Tue 4. Sep 17:42:14 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIMEDIAX_H
#define UI_MULTIMEDIAX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MultimediaX
{
public:
    QTextBrowser *songInformation;
    QPushButton *openImages;
    QLabel *songName;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *openButton;
    QPushButton *playButton;
    QPushButton *stopButton;
    QWidget *layoutWidget1;
    QVBoxLayout *vboxLayout;
    QLabel *imageLabel;
    QProgressBar *progressBar;
    QPushButton *test;

    void setupUi(QWidget *MultimediaX)
    {
        if (MultimediaX->objectName().isEmpty())
            MultimediaX->setObjectName(QString::fromUtf8("MultimediaX"));
        MultimediaX->setWindowModality(Qt::NonModal);
        MultimediaX->setEnabled(true);
        MultimediaX->resize(341, 431);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MultimediaX->sizePolicy().hasHeightForWidth());
        MultimediaX->setSizePolicy(sizePolicy);
        MultimediaX->setSizeIncrement(QSize(0, 0));
        songInformation = new QTextBrowser(MultimediaX);
        songInformation->setObjectName(QString::fromUtf8("songInformation"));
        songInformation->setEnabled(true);
        songInformation->setGeometry(QRect(10, 340, 321, 81));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(songInformation->sizePolicy().hasHeightForWidth());
        songInformation->setSizePolicy(sizePolicy1);
        songInformation->setSizeIncrement(QSize(1, 1));
        songInformation->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
#ifndef QT_NO_TOOLTIP
        songInformation->setToolTip(QString::fromUtf8(""));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        songInformation->setStatusTip(QString::fromUtf8(""));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        songInformation->setWhatsThis(QString::fromUtf8(""));
#endif // QT_NO_WHATSTHIS
        songInformation->setFrameShape(QFrame::StyledPanel);
        songInformation->setFrameShadow(QFrame::Sunken);
        openImages = new QPushButton(MultimediaX);
        openImages->setObjectName(QString::fromUtf8("openImages"));
        openImages->setGeometry(QRect(10, 10, 75, 24));
        songName = new QLabel(MultimediaX);
        songName->setObjectName(QString::fromUtf8("songName"));
        songName->setGeometry(QRect(10, 280, 301, 21));
        songName->setText(QString::fromUtf8(""));
        layoutWidget = new QWidget(MultimediaX);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 310, 321, 26));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        openButton = new QPushButton(layoutWidget);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setIconSize(QSize(34, 16));

        horizontalLayout_2->addWidget(openButton);

        playButton = new QPushButton(layoutWidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setIconSize(QSize(34, 14));

        horizontalLayout_2->addWidget(playButton);

        stopButton = new QPushButton(layoutWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        horizontalLayout_2->addWidget(stopButton);

        layoutWidget1 = new QWidget(MultimediaX);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 40, 321, 241));
        vboxLayout = new QVBoxLayout(layoutWidget1);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setSizeConstraint(QLayout::SetNoConstraint);
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        imageLabel = new QLabel(layoutWidget1);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy2);

        vboxLayout->addWidget(imageLabel);

        progressBar = new QProgressBar(layoutWidget1);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        vboxLayout->addWidget(progressBar);

        test = new QPushButton(MultimediaX);
        test->setObjectName(QString::fromUtf8("test"));
        test->setGeometry(QRect(100, 10, 75, 24));
        QWidget::setTabOrder(openButton, stopButton);

        retranslateUi(MultimediaX);
        QObject::connect(openImages, SIGNAL(clicked()), MultimediaX, SLOT(openImages()));
        QObject::connect(progressBar, SIGNAL(valueChanged(int)), progressBar, SLOT(update()));
        QObject::connect(openButton, SIGNAL(clicked()), progressBar, SLOT(reset()));
        QObject::connect(playButton, SIGNAL(clicked()), MultimediaX, SLOT(playFile()));
        QObject::connect(stopButton, SIGNAL(clicked()), MultimediaX, SLOT(stopFile()));
        QObject::connect(stopButton, SIGNAL(clicked()), progressBar, SLOT(reset()));
        QObject::connect(test, SIGNAL(clicked()), MultimediaX, SLOT(openTestWindow()));
        QObject::connect(openButton, SIGNAL(clicked()), MultimediaX, SLOT(openMusic()));

        QMetaObject::connectSlotsByName(MultimediaX);
    } // setupUi

    void retranslateUi(QWidget *MultimediaX)
    {
        MultimediaX->setWindowTitle(QApplication::translate("MultimediaX", "MultimediaX", 0, QApplication::UnicodeUTF8));
        openImages->setText(QApplication::translate("MultimediaX", "Open pics", 0, QApplication::UnicodeUTF8));
        openImages->setShortcut(QApplication::translate("MultimediaX", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        openButton->setText(QApplication::translate("MultimediaX", "Open file", 0, QApplication::UnicodeUTF8));
        openButton->setShortcut(QApplication::translate("MultimediaX", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        playButton->setText(QApplication::translate("MultimediaX", "Play", 0, QApplication::UnicodeUTF8));
        playButton->setShortcut(QApplication::translate("MultimediaX", "P", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("MultimediaX", "Stop", 0, QApplication::UnicodeUTF8));
        stopButton->setShortcut(QApplication::translate("MultimediaX", "S", 0, QApplication::UnicodeUTF8));
        imageLabel->setText(QString());
        test->setText(QApplication::translate("MultimediaX", "Test", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MultimediaX: public Ui_MultimediaX {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIMEDIAX_H

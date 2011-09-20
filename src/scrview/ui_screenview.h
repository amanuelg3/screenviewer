/********************************************************************************
** Form generated from reading UI file 'screenview.ui'
**
** Created: Mon Sep 19 16:42:08 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENVIEW_H
#define UI_SCREENVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScreenView
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *ScreenView)
    {
        if (ScreenView->objectName().isEmpty())
            ScreenView->setObjectName(QString::fromUtf8("ScreenView"));
        ScreenView->resize(360, 640);
        centralWidget = new QWidget(ScreenView);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ScreenView->setCentralWidget(centralWidget);

        retranslateUi(ScreenView);

        QMetaObject::connectSlotsByName(ScreenView);
    } // setupUi

    void retranslateUi(QMainWindow *ScreenView)
    {
        ScreenView->setWindowTitle(QApplication::translate("ScreenView", "ScreenView", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ScreenView: public Ui_ScreenView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENVIEW_H

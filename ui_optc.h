/********************************************************************************
** Form generated from reading UI file 'optc.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTC_H
#define UI_OPTC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Optc
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Optc)
    {
        if (Optc->objectName().isEmpty())
            Optc->setObjectName(QStringLiteral("Optc"));
        Optc->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Optc->sizePolicy().hasHeightForWidth());
        Optc->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(Optc);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));

        horizontalLayout->addWidget(tabWidget);

        Optc->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Optc);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        Optc->setMenuBar(menubar);
        statusbar = new QStatusBar(Optc);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Optc->setStatusBar(statusbar);

        retranslateUi(Optc);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Optc);
    } // setupUi

    void retranslateUi(QMainWindow *Optc)
    {
        Optc->setWindowTitle(QApplication::translate("Optc", "Optc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Optc: public Ui_Optc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTC_H

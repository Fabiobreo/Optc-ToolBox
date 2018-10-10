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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Optc
{
public:
    QAction *actionLogout;
    QAction *actionAbout_Optc_Toolbox;
    QAction *actionSave;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menu;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Optc)
    {
        if (Optc->objectName().isEmpty())
            Optc->setObjectName(QStringLiteral("Optc"));
        Optc->resize(800, 640);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Optc->sizePolicy().hasHeightForWidth());
        Optc->setSizePolicy(sizePolicy);
        actionLogout = new QAction(Optc);
        actionLogout->setObjectName(QStringLiteral("actionLogout"));
        actionAbout_Optc_Toolbox = new QAction(Optc);
        actionAbout_Optc_Toolbox->setObjectName(QStringLiteral("actionAbout_Optc_Toolbox"));
        actionSave = new QAction(Optc);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ui/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon);
        centralwidget = new QWidget(Optc);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::West);

        horizontalLayout->addWidget(tabWidget);

        Optc->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Optc);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(menubar->sizePolicy().hasHeightForWidth());
        menubar->setSizePolicy(sizePolicy1);
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        Optc->setMenuBar(menubar);
        statusbar = new QStatusBar(Optc);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(statusbar->sizePolicy().hasHeightForWidth());
        statusbar->setSizePolicy(sizePolicy2);
        Optc->setStatusBar(statusbar);
        toolBar = new QToolBar(Optc);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMinimumSize(QSize(0, 30));
        toolBar->setMaximumSize(QSize(16777215, 30));
        toolBar->setMovable(false);
        Optc->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menu->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLogout);
        menu->addAction(actionAbout_Optc_Toolbox);
        toolBar->addAction(actionSave);

        retranslateUi(Optc);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Optc);
    } // setupUi

    void retranslateUi(QMainWindow *Optc)
    {
        Optc->setWindowTitle(QApplication::translate("Optc", "Optc Toolbox", nullptr));
        actionLogout->setText(QApplication::translate("Optc", "Logout", nullptr));
        actionAbout_Optc_Toolbox->setText(QApplication::translate("Optc", "About Optc Toolbox", nullptr));
        actionSave->setText(QApplication::translate("Optc", "Save", nullptr));
        menuFile->setTitle(QApplication::translate("Optc", "File", nullptr));
        menu->setTitle(QApplication::translate("Optc", "?", nullptr));
        toolBar->setWindowTitle(QApplication::translate("Optc", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Optc: public Ui_Optc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTC_H

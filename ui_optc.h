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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Optc
{
public:
    QAction *actionLogout;
    QAction *actionAbout_Optc_Toolbox;
    QAction *actionSave;
    QAction *actionBuy_me_a_coffee;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *idLabel;
    QTabWidget *tabWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menu;
    QToolBar *toolBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QStatusBar *statusbar;

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
        QIcon icon;
        icon.addFile(QStringLiteral(":/ui/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLogout->setIcon(icon);
        actionAbout_Optc_Toolbox = new QAction(Optc);
        actionAbout_Optc_Toolbox->setObjectName(QStringLiteral("actionAbout_Optc_Toolbox"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ui/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_Optc_Toolbox->setIcon(icon1);
        actionSave = new QAction(Optc);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/ui/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionBuy_me_a_coffee = new QAction(Optc);
        actionBuy_me_a_coffee->setObjectName(QStringLiteral("actionBuy_me_a_coffee"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/ui/buyMeACoffeeIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBuy_me_a_coffee->setIcon(icon3);
        centralwidget = new QWidget(Optc);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 5, 9, 0);
        idLabel = new QLabel(centralwidget);
        idLabel->setObjectName(QStringLiteral("idLabel"));

        verticalLayout_2->addWidget(idLabel, 0, Qt::AlignHCenter);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::West);

        verticalLayout_2->addWidget(tabWidget);

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
        toolBar = new QToolBar(Optc);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMinimumSize(QSize(0, 30));
        toolBar->setMaximumSize(QSize(16777215, 30));
        toolBar->setMovable(false);
        Optc->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidget = new QDockWidget(Optc);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy2);
        dockWidget->setMinimumSize(QSize(340, 550));
        dockWidget->setMaximumSize(QSize(340, 524287));
        dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dockWidget->setWidget(dockWidgetContents);
        Optc->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget);
        statusbar = new QStatusBar(Optc);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(statusbar->sizePolicy().hasHeightForWidth());
        statusbar->setSizePolicy(sizePolicy3);
        Optc->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menu->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLogout);
        menu->addAction(actionBuy_me_a_coffee);
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
        actionBuy_me_a_coffee->setText(QApplication::translate("Optc", "Buy me a coffee", nullptr));
        idLabel->setText(QString());
        menuFile->setTitle(QApplication::translate("Optc", "File", nullptr));
        menu->setTitle(QApplication::translate("Optc", "?", nullptr));
        toolBar->setWindowTitle(QApplication::translate("Optc", "toolBar", nullptr));
        dockWidget->setWindowTitle(QApplication::translate("Optc", "Details", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Optc: public Ui_Optc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTC_H

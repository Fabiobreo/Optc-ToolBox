/********************************************************************************
** Form generated from reading UI file 'database.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASE_H
#define UI_DATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Database
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *filterByName;
    QRadioButton *ownedMode;
    QCheckBox *showOwned;
    QListWidget *characterList;

    void setupUi(QMainWindow *Database)
    {
        if (Database->objectName().isEmpty())
            Database->setObjectName(QStringLiteral("Database"));
        Database->resize(730, 532);
        centralWidget = new QWidget(Database);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        filterByName = new QLineEdit(centralWidget);
        filterByName->setObjectName(QStringLiteral("filterByName"));

        horizontalLayout->addWidget(filterByName);

        ownedMode = new QRadioButton(centralWidget);
        ownedMode->setObjectName(QStringLiteral("ownedMode"));

        horizontalLayout->addWidget(ownedMode);

        showOwned = new QCheckBox(centralWidget);
        showOwned->setObjectName(QStringLiteral("showOwned"));

        horizontalLayout->addWidget(showOwned);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        characterList = new QListWidget(centralWidget);
        characterList->setObjectName(QStringLiteral("characterList"));

        gridLayout->addWidget(characterList, 1, 0, 1, 1);

        Database->setCentralWidget(centralWidget);

        retranslateUi(Database);

        QMetaObject::connectSlotsByName(Database);
    } // setupUi

    void retranslateUi(QMainWindow *Database)
    {
        Database->setWindowTitle(QApplication::translate("Database", "Database", nullptr));
        ownedMode->setText(QApplication::translate("Database", "Owned Mode", nullptr));
        showOwned->setText(QApplication::translate("Database", "Show only owned", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Database: public Ui_Database {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASE_H

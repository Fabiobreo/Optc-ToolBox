/********************************************************************************
** Form generated from reading UI file 'database.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASE_H
#define UI_DATABASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Database
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *fixedIdLabel;
    QComboBox *idOperator;
    QLineEdit *filterById;
    QLabel *fixedNameLabel;
    QLineEdit *filterByName;
    QPushButton *advancedFilters;
    QPushButton *saveButton;
    QRadioButton *ownedMode;
    QCheckBox *showOwned;
    QCheckBox *editMode;
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
        fixedIdLabel = new QLabel(centralWidget);
        fixedIdLabel->setObjectName(QStringLiteral("fixedIdLabel"));

        horizontalLayout->addWidget(fixedIdLabel);

        idOperator = new QComboBox(centralWidget);
        idOperator->addItem(QString());
        idOperator->addItem(QString());
        idOperator->addItem(QString());
        idOperator->addItem(QString());
        idOperator->addItem(QString());
        idOperator->addItem(QString());
        idOperator->setObjectName(QStringLiteral("idOperator"));
        sizePolicy.setHeightForWidth(idOperator->sizePolicy().hasHeightForWidth());
        idOperator->setSizePolicy(sizePolicy);
        idOperator->setMinimumSize(QSize(35, 0));
        idOperator->setMaximumSize(QSize(35, 16777215));
        idOperator->setCursor(QCursor(Qt::ArrowCursor));

        horizontalLayout->addWidget(idOperator);

        filterById = new QLineEdit(centralWidget);
        filterById->setObjectName(QStringLiteral("filterById"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(filterById->sizePolicy().hasHeightForWidth());
        filterById->setSizePolicy(sizePolicy1);
        filterById->setMinimumSize(QSize(35, 0));
        filterById->setMaximumSize(QSize(35, 16777215));

        horizontalLayout->addWidget(filterById);

        fixedNameLabel = new QLabel(centralWidget);
        fixedNameLabel->setObjectName(QStringLiteral("fixedNameLabel"));

        horizontalLayout->addWidget(fixedNameLabel);

        filterByName = new QLineEdit(centralWidget);
        filterByName->setObjectName(QStringLiteral("filterByName"));

        horizontalLayout->addWidget(filterByName);

        advancedFilters = new QPushButton(centralWidget);
        advancedFilters->setObjectName(QStringLiteral("advancedFilters"));
        sizePolicy.setHeightForWidth(advancedFilters->sizePolicy().hasHeightForWidth());
        advancedFilters->setSizePolicy(sizePolicy);
        advancedFilters->setMinimumSize(QSize(25, 25));
        advancedFilters->setMaximumSize(QSize(25, 25));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ui/filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        advancedFilters->setIcon(icon);
        advancedFilters->setIconSize(QSize(22, 22));
        advancedFilters->setFlat(false);

        horizontalLayout->addWidget(advancedFilters);

        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(saveButton);

        ownedMode = new QRadioButton(centralWidget);
        ownedMode->setObjectName(QStringLiteral("ownedMode"));

        horizontalLayout->addWidget(ownedMode);

        showOwned = new QCheckBox(centralWidget);
        showOwned->setObjectName(QStringLiteral("showOwned"));

        horizontalLayout->addWidget(showOwned);

        editMode = new QCheckBox(centralWidget);
        editMode->setObjectName(QStringLiteral("editMode"));

        horizontalLayout->addWidget(editMode);


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
        fixedIdLabel->setText(QApplication::translate("Database", "Id", nullptr));
        idOperator->setItemText(0, QApplication::translate("Database", "=", nullptr));
        idOperator->setItemText(1, QApplication::translate("Database", "\342\211\240", nullptr));
        idOperator->setItemText(2, QApplication::translate("Database", ">", nullptr));
        idOperator->setItemText(3, QApplication::translate("Database", "\342\211\245", nullptr));
        idOperator->setItemText(4, QApplication::translate("Database", "<", nullptr));
        idOperator->setItemText(5, QApplication::translate("Database", "\342\211\244", nullptr));

        fixedNameLabel->setText(QApplication::translate("Database", "Name:", nullptr));
        advancedFilters->setText(QString());
        saveButton->setText(QApplication::translate("Database", "Save", nullptr));
        ownedMode->setText(QApplication::translate("Database", "Owned Mode", nullptr));
        showOwned->setText(QApplication::translate("Database", "Show only owned", nullptr));
        editMode->setText(QApplication::translate("Database", "Edit Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Database: public Ui_Database {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASE_H

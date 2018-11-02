/********************************************************************************
** Form generated from reading UI file 'advancedFilters.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVANCEDFILTERS_H
#define UI_ADVANCEDFILTERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdvancedFilters
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QPushButton *clearFiltersButton;
    QPushButton *cancelButton;

    void setupUi(QMainWindow *AdvancedFilters)
    {
        if (AdvancedFilters->objectName().isEmpty())
            AdvancedFilters->setObjectName(QStringLiteral("AdvancedFilters"));
        AdvancedFilters->setWindowModality(Qt::WindowModal);
        AdvancedFilters->resize(900, 400);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AdvancedFilters->sizePolicy().hasHeightForWidth());
        AdvancedFilters->setSizePolicy(sizePolicy);
        AdvancedFilters->setAutoFillBackground(false);
        centralWidget = new QWidget(AdvancedFilters);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        verticalLayout->addLayout(gridLayout);

        horizontalWidget = new QWidget(centralWidget);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        okButton = new QPushButton(horizontalWidget);
        okButton->setObjectName(QStringLiteral("okButton"));
        sizePolicy1.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(okButton, 0, Qt::AlignRight);

        clearFiltersButton = new QPushButton(horizontalWidget);
        clearFiltersButton->setObjectName(QStringLiteral("clearFiltersButton"));
        sizePolicy1.setHeightForWidth(clearFiltersButton->sizePolicy().hasHeightForWidth());
        clearFiltersButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(clearFiltersButton);

        cancelButton = new QPushButton(horizontalWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        sizePolicy1.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(cancelButton, 0, Qt::AlignRight);


        verticalLayout->addWidget(horizontalWidget, 0, Qt::AlignRight);

        AdvancedFilters->setCentralWidget(centralWidget);

        retranslateUi(AdvancedFilters);

        QMetaObject::connectSlotsByName(AdvancedFilters);
    } // setupUi

    void retranslateUi(QMainWindow *AdvancedFilters)
    {
        AdvancedFilters->setWindowTitle(QApplication::translate("AdvancedFilters", "AdvancedFilters", nullptr));
        okButton->setText(QApplication::translate("AdvancedFilters", "Ok", nullptr));
        clearFiltersButton->setText(QApplication::translate("AdvancedFilters", "Clear Filters", nullptr));
        cancelButton->setText(QApplication::translate("AdvancedFilters", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdvancedFilters: public Ui_AdvancedFilters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVANCEDFILTERS_H

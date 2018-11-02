/********************************************************************************
** Form generated from reading UI file 'filterWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERWIDGET_H
#define UI_FILTERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilterWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *filterLayout;
    QPushButton *addConditionButton;
    QPushButton *addFilterButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FilterWidget)
    {
        if (FilterWidget->objectName().isEmpty())
            FilterWidget->setObjectName(QStringLiteral("FilterWidget"));
        FilterWidget->resize(550, 73);
        verticalLayout = new QVBoxLayout(FilterWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        filterLayout = new QGridLayout();
        filterLayout->setObjectName(QStringLiteral("filterLayout"));
        addConditionButton = new QPushButton(FilterWidget);
        addConditionButton->setObjectName(QStringLiteral("addConditionButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addConditionButton->sizePolicy().hasHeightForWidth());
        addConditionButton->setSizePolicy(sizePolicy);
        addConditionButton->setMinimumSize(QSize(20, 20));
        addConditionButton->setMaximumSize(QSize(20, 20));
        addConditionButton->setStyleSheet(QStringLiteral("color: #333; border: 2px solid #555; border-radius: 10px; border-style: outset; background: qradialgradient( cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4, radius: 1.35, stop: 0 #ffffff, stop: 1 #bbb); font: 12pt; Text-align: bottom;"));

        filterLayout->addWidget(addConditionButton, 0, 1, 1, 1, Qt::AlignRight);


        verticalLayout->addLayout(filterLayout);

        addFilterButton = new QPushButton(FilterWidget);
        addFilterButton->setObjectName(QStringLiteral("addFilterButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addFilterButton->sizePolicy().hasHeightForWidth());
        addFilterButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(addFilterButton, 0, Qt::AlignRight);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        QWidget::setTabOrder(addConditionButton, addFilterButton);

        retranslateUi(FilterWidget);

        QMetaObject::connectSlotsByName(FilterWidget);
    } // setupUi

    void retranslateUi(QWidget *FilterWidget)
    {
        FilterWidget->setWindowTitle(QApplication::translate("FilterWidget", "Form", nullptr));
        addConditionButton->setText(QApplication::translate("FilterWidget", "+", nullptr));
        addFilterButton->setText(QApplication::translate("FilterWidget", "Add Filter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilterWidget: public Ui_FilterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERWIDGET_H

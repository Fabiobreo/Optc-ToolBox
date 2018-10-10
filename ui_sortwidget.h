/********************************************************************************
** Form generated from reading UI file 'sortwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTWIDGET_H
#define UI_SORTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SortWidget
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QComboBox *secondaryComboBox;
    QComboBox *primaryComboBox;
    QLabel *primaryCriteriaLabel;
    QLabel *secondaryCriteriaLabel;
    QSpacerItem *verticalSpacer;
    QCheckBox *primaryIncludeLimit;
    QCheckBox *secondaryIncludeLimit;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *primaryPriority;
    QToolButton *secondaryPriority;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QMainWindow *SortWidget)
    {
        if (SortWidget->objectName().isEmpty())
            SortWidget->setObjectName(QStringLiteral("SortWidget"));
        SortWidget->setWindowModality(Qt::WindowModal);
        SortWidget->resize(320, 122);
        centralWidget = new QWidget(SortWidget);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        secondaryComboBox = new QComboBox(centralWidget);
        secondaryComboBox->setObjectName(QStringLiteral("secondaryComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(secondaryComboBox->sizePolicy().hasHeightForWidth());
        secondaryComboBox->setSizePolicy(sizePolicy);
        secondaryComboBox->setMinimumSize(QSize(120, 0));
        secondaryComboBox->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(secondaryComboBox, 1, 2, 1, 1);

        primaryComboBox = new QComboBox(centralWidget);
        primaryComboBox->setObjectName(QStringLiteral("primaryComboBox"));
        sizePolicy.setHeightForWidth(primaryComboBox->sizePolicy().hasHeightForWidth());
        primaryComboBox->setSizePolicy(sizePolicy);
        primaryComboBox->setMinimumSize(QSize(120, 0));
        primaryComboBox->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(primaryComboBox, 1, 0, 1, 1);

        primaryCriteriaLabel = new QLabel(centralWidget);
        primaryCriteriaLabel->setObjectName(QStringLiteral("primaryCriteriaLabel"));

        gridLayout->addWidget(primaryCriteriaLabel, 0, 0, 1, 1, Qt::AlignHCenter);

        secondaryCriteriaLabel = new QLabel(centralWidget);
        secondaryCriteriaLabel->setObjectName(QStringLiteral("secondaryCriteriaLabel"));

        gridLayout->addWidget(secondaryCriteriaLabel, 0, 2, 1, 1, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        primaryIncludeLimit = new QCheckBox(centralWidget);
        primaryIncludeLimit->setObjectName(QStringLiteral("primaryIncludeLimit"));

        gridLayout->addWidget(primaryIncludeLimit, 2, 0, 1, 1, Qt::AlignHCenter);

        secondaryIncludeLimit = new QCheckBox(centralWidget);
        secondaryIncludeLimit->setObjectName(QStringLiteral("secondaryIncludeLimit"));

        gridLayout->addWidget(secondaryIncludeLimit, 2, 2, 1, 1, Qt::AlignHCenter);

        horizontalSpacer_3 = new QSpacerItem(40, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(10, 1, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 3, 1, 1);

        primaryPriority = new QToolButton(centralWidget);
        primaryPriority->setObjectName(QStringLiteral("primaryPriority"));
        primaryPriority->setMinimumSize(QSize(21, 21));
        primaryPriority->setMaximumSize(QSize(21, 21));

        gridLayout->addWidget(primaryPriority, 1, 1, 1, 1);

        secondaryPriority = new QToolButton(centralWidget);
        secondaryPriority->setObjectName(QStringLiteral("secondaryPriority"));
        secondaryPriority->setMinimumSize(QSize(21, 21));
        secondaryPriority->setMaximumSize(QSize(21, 21));

        gridLayout->addWidget(secondaryPriority, 1, 3, 1, 1, Qt::AlignHCenter);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(centralWidget);
        okButton->setObjectName(QStringLiteral("okButton"));
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(okButton, 0, Qt::AlignRight);

        cancelButton = new QPushButton(centralWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        sizePolicy.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(cancelButton, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout);

        SortWidget->setCentralWidget(centralWidget);
        QWidget::setTabOrder(primaryComboBox, secondaryComboBox);

        retranslateUi(SortWidget);

        QMetaObject::connectSlotsByName(SortWidget);
    } // setupUi

    void retranslateUi(QMainWindow *SortWidget)
    {
        SortWidget->setWindowTitle(QApplication::translate("SortWidget", "Sort Conditions", nullptr));
        primaryCriteriaLabel->setText(QApplication::translate("SortWidget", "<b>Primary Criteria</b>", nullptr));
        secondaryCriteriaLabel->setText(QApplication::translate("SortWidget", "<b>Secondary Criteria</b>", nullptr));
        primaryIncludeLimit->setText(QApplication::translate("SortWidget", "Include Limit Break", nullptr));
        secondaryIncludeLimit->setText(QApplication::translate("SortWidget", "Include Limit Break", nullptr));
        primaryPriority->setText(QString());
        secondaryPriority->setText(QString());
        okButton->setText(QApplication::translate("SortWidget", "Ok", nullptr));
        cancelButton->setText(QApplication::translate("SortWidget", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SortWidget: public Ui_SortWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTWIDGET_H

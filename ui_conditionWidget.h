/********************************************************************************
** Form generated from reading UI file 'conditionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONDITIONWIDGET_H
#define UI_CONDITIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConditionWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *layout;
    QComboBox *targetBox;
    QComboBox *secondaryTargetBox;
    QComboBox *typeClassTargetBox;
    QComboBox *operatorBox;
    QComboBox *typeClassValueBox;
    QLineEdit *numericValueEdit;
    QLineEdit *stringValueEdit;
    QCheckBox *includeLimitBreak;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ConditionWidget)
    {
        if (ConditionWidget->objectName().isEmpty())
            ConditionWidget->setObjectName(QStringLiteral("ConditionWidget"));
        ConditionWidget->resize(767, 42);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ConditionWidget->sizePolicy().hasHeightForWidth());
        ConditionWidget->setSizePolicy(sizePolicy);
        ConditionWidget->setMinimumSize(QSize(600, 0));
        ConditionWidget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(ConditionWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        layout = new QHBoxLayout();
        layout->setObjectName(QStringLiteral("layout"));
        targetBox = new QComboBox(ConditionWidget);
        targetBox->setObjectName(QStringLiteral("targetBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(targetBox->sizePolicy().hasHeightForWidth());
        targetBox->setSizePolicy(sizePolicy1);
        targetBox->setMinimumSize(QSize(110, 0));
        targetBox->setMaximumSize(QSize(110, 16777215));

        layout->addWidget(targetBox, 0, Qt::AlignLeft|Qt::AlignTop);

        secondaryTargetBox = new QComboBox(ConditionWidget);
        secondaryTargetBox->setObjectName(QStringLiteral("secondaryTargetBox"));
        sizePolicy1.setHeightForWidth(secondaryTargetBox->sizePolicy().hasHeightForWidth());
        secondaryTargetBox->setSizePolicy(sizePolicy1);
        secondaryTargetBox->setMinimumSize(QSize(150, 0));
        secondaryTargetBox->setMaximumSize(QSize(150, 16777215));

        layout->addWidget(secondaryTargetBox, 0, Qt::AlignLeft|Qt::AlignTop);

        typeClassTargetBox = new QComboBox(ConditionWidget);
        typeClassTargetBox->setObjectName(QStringLiteral("typeClassTargetBox"));
        sizePolicy1.setHeightForWidth(typeClassTargetBox->sizePolicy().hasHeightForWidth());
        typeClassTargetBox->setSizePolicy(sizePolicy1);
        typeClassTargetBox->setMinimumSize(QSize(90, 0));
        typeClassTargetBox->setMaximumSize(QSize(90, 16777215));

        layout->addWidget(typeClassTargetBox, 0, Qt::AlignLeft|Qt::AlignTop);

        operatorBox = new QComboBox(ConditionWidget);
        operatorBox->setObjectName(QStringLiteral("operatorBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(operatorBox->sizePolicy().hasHeightForWidth());
        operatorBox->setSizePolicy(sizePolicy2);
        operatorBox->setMinimumSize(QSize(35, 0));
        operatorBox->setMaximumSize(QSize(35, 16777215));

        layout->addWidget(operatorBox, 0, Qt::AlignLeft|Qt::AlignTop);

        typeClassValueBox = new QComboBox(ConditionWidget);
        typeClassValueBox->setObjectName(QStringLiteral("typeClassValueBox"));
        sizePolicy2.setHeightForWidth(typeClassValueBox->sizePolicy().hasHeightForWidth());
        typeClassValueBox->setSizePolicy(sizePolicy2);
        typeClassValueBox->setMinimumSize(QSize(120, 0));
        typeClassValueBox->setMaximumSize(QSize(120, 16777215));

        layout->addWidget(typeClassValueBox, 0, Qt::AlignLeft|Qt::AlignTop);

        numericValueEdit = new QLineEdit(ConditionWidget);
        numericValueEdit->setObjectName(QStringLiteral("numericValueEdit"));
        sizePolicy2.setHeightForWidth(numericValueEdit->sizePolicy().hasHeightForWidth());
        numericValueEdit->setSizePolicy(sizePolicy2);
        numericValueEdit->setMinimumSize(QSize(50, 0));
        numericValueEdit->setMaximumSize(QSize(50, 16777215));

        layout->addWidget(numericValueEdit, 0, Qt::AlignLeft|Qt::AlignTop);

        stringValueEdit = new QLineEdit(ConditionWidget);
        stringValueEdit->setObjectName(QStringLiteral("stringValueEdit"));
        sizePolicy2.setHeightForWidth(stringValueEdit->sizePolicy().hasHeightForWidth());
        stringValueEdit->setSizePolicy(sizePolicy2);
        stringValueEdit->setMinimumSize(QSize(50, 0));
        stringValueEdit->setMaximumSize(QSize(50, 16777215));

        layout->addWidget(stringValueEdit, 0, Qt::AlignLeft|Qt::AlignTop);

        includeLimitBreak = new QCheckBox(ConditionWidget);
        includeLimitBreak->setObjectName(QStringLiteral("includeLimitBreak"));

        layout->addWidget(includeLimitBreak);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layout->addItem(horizontalSpacer);


        verticalLayout->addLayout(layout);


        retranslateUi(ConditionWidget);

        QMetaObject::connectSlotsByName(ConditionWidget);
    } // setupUi

    void retranslateUi(QWidget *ConditionWidget)
    {
        ConditionWidget->setWindowTitle(QApplication::translate("ConditionWidget", "Form", nullptr));
        includeLimitBreak->setText(QApplication::translate("ConditionWidget", "Include Limit Break", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConditionWidget: public Ui_ConditionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONDITIONWIDGET_H

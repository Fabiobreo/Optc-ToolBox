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
#include <QtWidgets/QLabel>
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
    QComboBox *primaryTargetBox;
    QComboBox *secondaryTargetBox;
    QComboBox *terziaryTargetBox;
    QComboBox *quaternaryTargetBox;
    QCheckBox *boolTarget;
    QComboBox *operatorBox;
    QLabel *intoLabel;
    QComboBox *genericValueBox;
    QLineEdit *numericValueEdit;
    QLineEdit *stringValueEdit;
    QLabel *turnsLabel;
    QComboBox *secondaryOperatorBox;
    QLineEdit *secondaryNumericValueEdit;
    QCheckBox *includePlus;
    QCheckBox *includeWantToFinish;
    QCheckBox *includeLimitBreak;
    QComboBox *finalTargetBox;
    QCheckBox *endOfTurn;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ConditionWidget)
    {
        if (ConditionWidget->objectName().isEmpty())
            ConditionWidget->setObjectName(QStringLiteral("ConditionWidget"));
        ConditionWidget->resize(1284, 44);
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
        primaryTargetBox = new QComboBox(ConditionWidget);
        primaryTargetBox->setObjectName(QStringLiteral("primaryTargetBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(primaryTargetBox->sizePolicy().hasHeightForWidth());
        primaryTargetBox->setSizePolicy(sizePolicy1);
        primaryTargetBox->setMinimumSize(QSize(110, 22));
        primaryTargetBox->setMaximumSize(QSize(110, 22));
        primaryTargetBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        layout->addWidget(primaryTargetBox, 0, Qt::AlignLeft|Qt::AlignTop);

        secondaryTargetBox = new QComboBox(ConditionWidget);
        secondaryTargetBox->setObjectName(QStringLiteral("secondaryTargetBox"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(secondaryTargetBox->sizePolicy().hasHeightForWidth());
        secondaryTargetBox->setSizePolicy(sizePolicy2);
        secondaryTargetBox->setMinimumSize(QSize(110, 22));
        secondaryTargetBox->setMaximumSize(QSize(150, 22));
        secondaryTargetBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        layout->addWidget(secondaryTargetBox, 0, Qt::AlignLeft|Qt::AlignTop);

        terziaryTargetBox = new QComboBox(ConditionWidget);
        terziaryTargetBox->setObjectName(QStringLiteral("terziaryTargetBox"));
        sizePolicy2.setHeightForWidth(terziaryTargetBox->sizePolicy().hasHeightForWidth());
        terziaryTargetBox->setSizePolicy(sizePolicy2);
        terziaryTargetBox->setMinimumSize(QSize(110, 22));
        terziaryTargetBox->setMaximumSize(QSize(140, 22));
        terziaryTargetBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        layout->addWidget(terziaryTargetBox, 0, Qt::AlignLeft|Qt::AlignTop);

        quaternaryTargetBox = new QComboBox(ConditionWidget);
        quaternaryTargetBox->setObjectName(QStringLiteral("quaternaryTargetBox"));
        sizePolicy2.setHeightForWidth(quaternaryTargetBox->sizePolicy().hasHeightForWidth());
        quaternaryTargetBox->setSizePolicy(sizePolicy2);
        quaternaryTargetBox->setMinimumSize(QSize(110, 22));
        quaternaryTargetBox->setMaximumSize(QSize(140, 22));
        quaternaryTargetBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        layout->addWidget(quaternaryTargetBox, 0, Qt::AlignLeft|Qt::AlignTop);

        boolTarget = new QCheckBox(ConditionWidget);
        boolTarget->setObjectName(QStringLiteral("boolTarget"));

        layout->addWidget(boolTarget);

        operatorBox = new QComboBox(ConditionWidget);
        operatorBox->setObjectName(QStringLiteral("operatorBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(operatorBox->sizePolicy().hasHeightForWidth());
        operatorBox->setSizePolicy(sizePolicy3);
        operatorBox->setMinimumSize(QSize(35, 22));
        operatorBox->setMaximumSize(QSize(35, 22));
        operatorBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        layout->addWidget(operatorBox, 0, Qt::AlignLeft|Qt::AlignTop);

        intoLabel = new QLabel(ConditionWidget);
        intoLabel->setObjectName(QStringLiteral("intoLabel"));

        layout->addWidget(intoLabel);

        genericValueBox = new QComboBox(ConditionWidget);
        genericValueBox->setObjectName(QStringLiteral("genericValueBox"));
        sizePolicy2.setHeightForWidth(genericValueBox->sizePolicy().hasHeightForWidth());
        genericValueBox->setSizePolicy(sizePolicy2);
        genericValueBox->setMinimumSize(QSize(90, 22));
        genericValueBox->setMaximumSize(QSize(120, 22));
        genericValueBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        layout->addWidget(genericValueBox, 0, Qt::AlignLeft|Qt::AlignTop);

        numericValueEdit = new QLineEdit(ConditionWidget);
        numericValueEdit->setObjectName(QStringLiteral("numericValueEdit"));
        sizePolicy3.setHeightForWidth(numericValueEdit->sizePolicy().hasHeightForWidth());
        numericValueEdit->setSizePolicy(sizePolicy3);
        numericValueEdit->setMinimumSize(QSize(50, 0));
        numericValueEdit->setMaximumSize(QSize(50, 16777215));

        layout->addWidget(numericValueEdit, 0, Qt::AlignLeft|Qt::AlignTop);

        stringValueEdit = new QLineEdit(ConditionWidget);
        stringValueEdit->setObjectName(QStringLiteral("stringValueEdit"));
        sizePolicy3.setHeightForWidth(stringValueEdit->sizePolicy().hasHeightForWidth());
        stringValueEdit->setSizePolicy(sizePolicy3);
        stringValueEdit->setMinimumSize(QSize(50, 0));
        stringValueEdit->setMaximumSize(QSize(50, 16777215));

        layout->addWidget(stringValueEdit, 0, Qt::AlignLeft|Qt::AlignTop);

        turnsLabel = new QLabel(ConditionWidget);
        turnsLabel->setObjectName(QStringLiteral("turnsLabel"));

        layout->addWidget(turnsLabel);

        secondaryOperatorBox = new QComboBox(ConditionWidget);
        secondaryOperatorBox->setObjectName(QStringLiteral("secondaryOperatorBox"));
        sizePolicy3.setHeightForWidth(secondaryOperatorBox->sizePolicy().hasHeightForWidth());
        secondaryOperatorBox->setSizePolicy(sizePolicy3);
        secondaryOperatorBox->setMinimumSize(QSize(35, 22));
        secondaryOperatorBox->setMaximumSize(QSize(35, 22));
        secondaryOperatorBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        layout->addWidget(secondaryOperatorBox);

        secondaryNumericValueEdit = new QLineEdit(ConditionWidget);
        secondaryNumericValueEdit->setObjectName(QStringLiteral("secondaryNumericValueEdit"));
        sizePolicy3.setHeightForWidth(secondaryNumericValueEdit->sizePolicy().hasHeightForWidth());
        secondaryNumericValueEdit->setSizePolicy(sizePolicy3);
        secondaryNumericValueEdit->setMinimumSize(QSize(50, 0));
        secondaryNumericValueEdit->setMaximumSize(QSize(50, 16777215));

        layout->addWidget(secondaryNumericValueEdit);

        includePlus = new QCheckBox(ConditionWidget);
        includePlus->setObjectName(QStringLiteral("includePlus"));

        layout->addWidget(includePlus);

        includeWantToFinish = new QCheckBox(ConditionWidget);
        includeWantToFinish->setObjectName(QStringLiteral("includeWantToFinish"));

        layout->addWidget(includeWantToFinish);

        includeLimitBreak = new QCheckBox(ConditionWidget);
        includeLimitBreak->setObjectName(QStringLiteral("includeLimitBreak"));

        layout->addWidget(includeLimitBreak);

        finalTargetBox = new QComboBox(ConditionWidget);
        finalTargetBox->setObjectName(QStringLiteral("finalTargetBox"));
        sizePolicy2.setHeightForWidth(finalTargetBox->sizePolicy().hasHeightForWidth());
        finalTargetBox->setSizePolicy(sizePolicy2);
        finalTargetBox->setMinimumSize(QSize(80, 0));
        finalTargetBox->setMaximumSize(QSize(80, 16777215));

        layout->addWidget(finalTargetBox);

        endOfTurn = new QCheckBox(ConditionWidget);
        endOfTurn->setObjectName(QStringLiteral("endOfTurn"));

        layout->addWidget(endOfTurn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layout->addItem(horizontalSpacer);


        verticalLayout->addLayout(layout);


        retranslateUi(ConditionWidget);

        QMetaObject::connectSlotsByName(ConditionWidget);
    } // setupUi

    void retranslateUi(QWidget *ConditionWidget)
    {
        ConditionWidget->setWindowTitle(QApplication::translate("ConditionWidget", "Form", nullptr));
        boolTarget->setText(QString());
        intoLabel->setText(QApplication::translate("ConditionWidget", "Into:", nullptr));
        numericValueEdit->setText(QApplication::translate("ConditionWidget", "0", nullptr));
        turnsLabel->setText(QApplication::translate("ConditionWidget", "Turns:", nullptr));
        secondaryNumericValueEdit->setText(QApplication::translate("ConditionWidget", "0", nullptr));
        includePlus->setText(QApplication::translate("ConditionWidget", "Plus", nullptr));
        includeWantToFinish->setText(QApplication::translate("ConditionWidget", "Only Want to Finish", nullptr));
        includeLimitBreak->setText(QApplication::translate("ConditionWidget", "Include Limit Break", nullptr));
        endOfTurn->setText(QApplication::translate("ConditionWidget", "End of turn", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConditionWidget: public Ui_ConditionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONDITIONWIDGET_H

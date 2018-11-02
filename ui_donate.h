/********************************************************************************
** Form generated from reading UI file 'donate.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DONATE_H
#define UI_DONATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Donate
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *donateButton;
    QLabel *label_2;

    void setupUi(QMainWindow *Donate)
    {
        if (Donate->objectName().isEmpty())
            Donate->setObjectName(QStringLiteral("Donate"));
        Donate->resize(264, 121);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(Donate->sizePolicy().hasHeightForWidth());
        Donate->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(Donate);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 0));
        label->setWordWrap(false);

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter|Qt::AlignTop);

        donateButton = new QPushButton(centralwidget);
        donateButton->setObjectName(QStringLiteral("donateButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(donateButton->sizePolicy().hasHeightForWidth());
        donateButton->setSizePolicy(sizePolicy2);
        donateButton->setMinimumSize(QSize(174, 41));
        donateButton->setMaximumSize(QSize(174, 41));

        verticalLayout->addWidget(donateButton, 0, Qt::AlignHCenter);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2, 0, Qt::AlignHCenter);

        Donate->setCentralWidget(centralwidget);

        retranslateUi(Donate);

        QMetaObject::connectSlotsByName(Donate);
    } // setupUi

    void retranslateUi(QMainWindow *Donate)
    {
        Donate->setWindowTitle(QApplication::translate("Donate", "Thank you!", nullptr));
        label->setText(QApplication::translate("Donate", "Do you like my work? Do you want to help me?", nullptr));
        donateButton->setText(QString());
        label_2->setText(QApplication::translate("Donate", "Thank you for supporting me and for using my tool!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Donate: public Ui_Donate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DONATE_H

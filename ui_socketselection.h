/********************************************************************************
** Form generated from reading UI file 'socketselection.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCKETSELECTION_H
#define UI_SOCKETSELECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SocketSelection
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *socketSelectionList;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SocketSelection)
    {
        if (SocketSelection->objectName().isEmpty())
            SocketSelection->setObjectName(QStringLiteral("SocketSelection"));
        SocketSelection->setWindowModality(Qt::WindowModal);
        SocketSelection->resize(350, 200);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SocketSelection->sizePolicy().hasHeightForWidth());
        SocketSelection->setSizePolicy(sizePolicy);
        SocketSelection->setMinimumSize(QSize(350, 200));
        SocketSelection->setMaximumSize(QSize(350, 200));
        verticalLayout_2 = new QVBoxLayout(SocketSelection);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        socketSelectionList = new QListWidget(SocketSelection);
        socketSelectionList->setObjectName(QStringLiteral("socketSelectionList"));

        verticalLayout->addWidget(socketSelectionList);

        buttonBox = new QDialogButtonBox(SocketSelection);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(SocketSelection);

        QMetaObject::connectSlotsByName(SocketSelection);
    } // setupUi

    void retranslateUi(QDialog *SocketSelection)
    {
        SocketSelection->setWindowTitle(QApplication::translate("SocketSelection", "Socket Selection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SocketSelection: public Ui_SocketSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCKETSELECTION_H

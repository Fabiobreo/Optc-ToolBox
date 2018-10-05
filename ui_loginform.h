/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginForm
{
public:
    QWidget *widget;
    QGridLayout *LoginLayout;
    QCheckBox *remembeMeCheckbox;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QLineEdit *usernameEdit;
    QLabel *fixedLoginText;
    QPushButton *registerButton;
    QLabel *fixedUsernameText;
    QLabel *fixedPasswordText;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName(QStringLiteral("LoginForm"));
        LoginForm->setWindowModality(Qt::ApplicationModal);
        LoginForm->resize(257, 212);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginForm->sizePolicy().hasHeightForWidth());
        LoginForm->setSizePolicy(sizePolicy);
        widget = new QWidget(LoginForm);
        widget->setObjectName(QStringLiteral("widget"));
        LoginLayout = new QGridLayout(widget);
        LoginLayout->setObjectName(QStringLiteral("LoginLayout"));
        remembeMeCheckbox = new QCheckBox(widget);
        remembeMeCheckbox->setObjectName(QStringLiteral("remembeMeCheckbox"));

        LoginLayout->addWidget(remembeMeCheckbox, 4, 0, 1, 2);

        passwordEdit = new QLineEdit(widget);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);
        passwordEdit->setClearButtonEnabled(false);

        LoginLayout->addWidget(passwordEdit, 3, 1, 1, 1);

        loginButton = new QPushButton(widget);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setMinimumSize(QSize(0, 30));
        loginButton->setMaximumSize(QSize(16777215, 30));
        loginButton->setStyleSheet(QStringLiteral("background-color: rgb(1, 108, 194);"));
        loginButton->setFlat(false);

        LoginLayout->addWidget(loginButton, 6, 0, 1, 2);

        usernameEdit = new QLineEdit(widget);
        usernameEdit->setObjectName(QStringLiteral("usernameEdit"));

        LoginLayout->addWidget(usernameEdit, 1, 1, 1, 1);

        fixedLoginText = new QLabel(widget);
        fixedLoginText->setObjectName(QStringLiteral("fixedLoginText"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fixedLoginText->sizePolicy().hasHeightForWidth());
        fixedLoginText->setSizePolicy(sizePolicy1);
        fixedLoginText->setStyleSheet(QStringLiteral("font: 75 12pt \"MS Shell Dlg 2\";"));

        LoginLayout->addWidget(fixedLoginText, 0, 0, 1, 2, Qt::AlignHCenter|Qt::AlignVCenter);

        registerButton = new QPushButton(widget);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setMinimumSize(QSize(0, 30));
        registerButton->setMaximumSize(QSize(16777215, 30));
        registerButton->setFlat(false);

        LoginLayout->addWidget(registerButton, 7, 0, 1, 2);

        fixedUsernameText = new QLabel(widget);
        fixedUsernameText->setObjectName(QStringLiteral("fixedUsernameText"));

        LoginLayout->addWidget(fixedUsernameText, 1, 0, 1, 1);

        fixedPasswordText = new QLabel(widget);
        fixedPasswordText->setObjectName(QStringLiteral("fixedPasswordText"));

        LoginLayout->addWidget(fixedPasswordText, 3, 0, 1, 1);

        LoginForm->setCentralWidget(widget);
        statusBar = new QStatusBar(LoginForm);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setSizeGripEnabled(false);
        LoginForm->setStatusBar(statusBar);
        QWidget::setTabOrder(usernameEdit, passwordEdit);
        QWidget::setTabOrder(passwordEdit, remembeMeCheckbox);
        QWidget::setTabOrder(remembeMeCheckbox, loginButton);
        QWidget::setTabOrder(loginButton, registerButton);

        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QMainWindow *LoginForm)
    {
        LoginForm->setWindowTitle(QApplication::translate("LoginForm", "Optc Login", nullptr));
        remembeMeCheckbox->setText(QApplication::translate("LoginForm", "Remember me", nullptr));
        passwordEdit->setPlaceholderText(QApplication::translate("LoginForm", "password", nullptr));
        loginButton->setText(QApplication::translate("LoginForm", "Login", nullptr));
        usernameEdit->setText(QString());
        usernameEdit->setPlaceholderText(QApplication::translate("LoginForm", "Id", nullptr));
        fixedLoginText->setText(QApplication::translate("LoginForm", "Login to Your Account", nullptr));
        registerButton->setText(QApplication::translate("LoginForm", "Register", nullptr));
        fixedUsernameText->setText(QApplication::translate("LoginForm", "In-game id", nullptr));
        fixedPasswordText->setText(QApplication::translate("LoginForm", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H

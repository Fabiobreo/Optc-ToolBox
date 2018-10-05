#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QMainWindow>

namespace Ui {
class LoginForm;
}

class LoginForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = 0);
    ~LoginForm();

private slots:

    void on_usernameEdit_textChanged(const QString &_text);

    void on_loginButton_clicked();

    void on_registerButton_clicked();

    std::string encryptDecrypt(std::string _toEncrypt);

private:
    Ui::LoginForm *ui;

    void loadSettings();
    void saveSettings();

    bool autoLogin;
    std::string lastLogin;
    std::map<std::string, std::string> userPwd;
    QString loginPath;

};

#endif // LOGINFORM_H

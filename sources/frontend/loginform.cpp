#include "loginform.h"
#include "ui_loginform.h"
#include <optc.h>
#include <fstream>
#include <json.h>

LoginForm::LoginForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginForm),
    autoLogin(false),
    lastLogin("")
{
    ui->setupUi(this);
    loginPath = QDir::currentPath() + QString("/resources/data/login.json");
    loadSettings();

    ui->usernameEdit->setText(QString::fromStdString(lastLogin));
    if (autoLogin)
    {
        ui->statusBar->setStyleSheet("color: green");
        ui->statusBar->showMessage(QString::fromStdString("Login successful"), 2000);

        //Login
        QApplication::setOverrideCursor(Qt::WaitCursor);
        Optc* optcWindow = static_cast<Optc*>(parent);
        optcWindow->loadCharacters(ui->usernameEdit->text().toLong());
        optcWindow->show();
        QApplication::restoreOverrideCursor();
        QTimer::singleShot(0, this, SLOT(close()));
    }
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_usernameEdit_textChanged(const QString &_text)
{
    if (_text.size() < 9)
    {
        long possibleUsername = _text.toLong();
        if (_text != "0" && possibleUsername <= 0)
        {
            ui->usernameEdit->setText("");
            ui->statusBar->setStyleSheet("color: red");
            ui->statusBar->showMessage("The username must be numeric", 2000);
        }
    }
    else
    {
        QStringRef subString(&_text, 0, 9);
        ui->usernameEdit->setText(subString.toString());
    }
}

void LoginForm::on_loginButton_clicked()
{
    std::string possibleUsername = ui->usernameEdit->text().toUtf8().constData();
    if (userPwd.find(possibleUsername) == userPwd.end())
    {
        ui->statusBar->setStyleSheet("color: red");
        ui->statusBar->showMessage("The username: " + QString::fromStdString(possibleUsername) + " is not registered", 2000);
    }
    else
    {
        std::string registeredPassword = userPwd.at(possibleUsername);
        if (registeredPassword == ui->passwordEdit->text().toUtf8().constData())
        {
            // Save new settings
            lastLogin = possibleUsername;
            autoLogin = ui->remembeMeCheckbox->isChecked();
            saveSettings();

            ui->statusBar->setStyleSheet("color: green");
            ui->statusBar->showMessage(QString::fromStdString("Login successful"), 2000);

            //Login
            QApplication::setOverrideCursor(Qt::WaitCursor);
            Optc* optcWindow = static_cast<Optc*>(parent());
            optcWindow->loadCharacters(ui->usernameEdit->text().toLong());
            optcWindow->show();
            QApplication::restoreOverrideCursor();
            close();
        }
        else
        {
            ui->statusBar->setStyleSheet("color: red");
            ui->statusBar->showMessage("The password is wrong", 2000);
        }
    }
}

void LoginForm::on_registerButton_clicked()
{
    std::string possibleUsername = ui->usernameEdit->text().toUtf8().constData();
    if (userPwd.find(possibleUsername) != userPwd.end())
    {
        ui->statusBar->setStyleSheet("color: red");
        ui->statusBar->showMessage(QString::fromStdString("The username: " + possibleUsername + " is already in use"), 2000);
    }
    else
    {
        if (possibleUsername != "")
        {
            if (ui->passwordEdit->text() != "")
            {
                // Save new settings
                userPwd[possibleUsername] = ui->passwordEdit->text().toUtf8().constData();
                lastLogin = possibleUsername;
                autoLogin = ui->remembeMeCheckbox->isChecked();
                saveSettings();

                ui->statusBar->setStyleSheet("color: green");
                ui->statusBar->showMessage(QString::fromStdString("Registration successful"), 2000);

                //Login
                QApplication::setOverrideCursor(Qt::WaitCursor);
                Optc* optcWindow = static_cast<Optc*>(parent());
                optcWindow->loadCharacters(ui->usernameEdit->text().toLong());
                optcWindow->show();
                QApplication::restoreOverrideCursor();
                close();
            }
            else
            {
                ui->statusBar->setStyleSheet("color: red");
                ui->statusBar->showMessage(QString::fromStdString("Password can not be empty"), 2000);
            }
        }
        else
        {
            ui->statusBar->setStyleSheet("color: red");
            ui->statusBar->showMessage(QString::fromStdString("Id can not be empty"), 2000);
        }
    }
}

void LoginForm::loadSettings()
{
    std::ifstream inputStream(loginPath.toUtf8().constData());
    if (inputStream.is_open())
    {
        json inputFile;
        inputStream >> inputFile;

        if (inputFile.find("RegisteredUsers") != inputFile.end())
        {
            json registeredUsers = inputFile.at("RegisteredUsers");
            for (json::iterator fileIterator = registeredUsers.begin(); fileIterator != registeredUsers.end(); ++fileIterator)
            {
                std::string username = fileIterator.key();
                std::string pwd = encryptDecrypt(registeredUsers.at(fileIterator.key()));
                userPwd[username] = pwd;
            }
        }

        if (inputFile.find("LastLogin") != inputFile.end())
        {
            lastLogin = inputFile.at("LastLogin");
        }

        if (inputFile.find("AutoLogin") != inputFile.end())
        {
            autoLogin = inputFile.at("AutoLogin");
        }
    }
    else
    {
        autoLogin = false;
        lastLogin = "";
    }
    inputStream.close();
}

void LoginForm::saveSettings()
{
    std::ofstream outputFile(loginPath.toUtf8().constData());
    if (outputFile.is_open())
    {
        json settingsJson;

        settingsJson["LastLogin"] = lastLogin;
        settingsJson["AutoLogin"] = autoLogin;

        json registeredJson;
        for (std::map<std::string, std::string>::iterator it = userPwd.begin(); it != userPwd.end(); ++it)
        {
            registeredJson[it->first] = encryptDecrypt(userPwd.at(it->first));
        }
        settingsJson["RegisteredUsers"] = registeredJson;
        outputFile << std::setw(4) << settingsJson << std::endl;
    }
    outputFile.close();
}

std::string LoginForm::encryptDecrypt(std::string _toEncrypt)
{
    std::string key = "Mast3rKek";
    std::string output = _toEncrypt;

    for (unsigned int i = 0; i < _toEncrypt.size(); i++)
    {
        output[i] = _toEncrypt[i] ^ key[i % (key.length() / sizeof(char))];
    }

    return output;
}

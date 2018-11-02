#ifndef ABOUT_H
#define ABOUT_H

#include <QMainWindow>

namespace Ui {
class About;
}

class About : public QMainWindow
{
    Q_OBJECT

public:
    explicit About(QWidget *_parent = nullptr);
    ~About();

private slots:

    void on_okButton_clicked();

private:
    Ui::About *ui;
};

#endif // ABOUT_H

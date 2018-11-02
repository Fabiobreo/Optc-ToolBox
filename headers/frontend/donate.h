#ifndef DONATE_H
#define DONATE_H

#include <QMainWindow>

namespace Ui {
class Donate;
}

class Donate : public QMainWindow
{
    Q_OBJECT

public:
    explicit Donate(QWidget *parent = nullptr);
    ~Donate();

private slots:
    void on_donateButton_clicked();

private:
    Ui::Donate *ui;
};

#endif // DONATE_H

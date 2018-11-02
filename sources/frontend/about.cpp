#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
}

About::~About()
{
    delete ui;
}

void About::on_okButton_clicked()
{
    hide();
}

#include "donate.h"
#include "ui_donate.h"
#include <QDesktopServices>
#include <QUrl>

Donate::Donate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Donate)
{
    ui->setupUi(this);

    QPixmap image(":/ui/buyMeACoffee.png");
    QIcon icon(image);
    ui->donateButton->setIcon(icon);
    ui->donateButton->setIconSize(image.rect().size());
}

Donate::~Donate()
{
    delete ui;
}

void Donate::on_donateButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.paypal.me/FabioBrea/"));
}

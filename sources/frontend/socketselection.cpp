#include "socketselection.h"
#include "ui_socketselection.h"

SocketSelection::SocketSelection(int _row, int _column, std::vector<QListWidgetItem*>& _items, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SocketSelection),
    row(_row),
    column(_column)
{
    ui->setupUi(this);
    ui->socketSelectionList->setViewMode(QListWidget::IconMode);
    ui->socketSelectionList->setIconSize(QSize(50, 50));
    ui->socketSelectionList->setResizeMode(QListWidget::Adjust);

    for (QListWidgetItem* item : _items)
    {
        ui->socketSelectionList->addItem(item);
    }
}

SocketSelection::~SocketSelection()
{
    delete ui;
}

void SocketSelection::on_buttonBox_accepted()
{
    Socket::Type selected_type = Socket::Type::None;
    QString selectedText = ui->socketSelectionList->currentItem()->text();
    if (selectedText == "Dmg Red.")
    {
        selected_type = Socket::Type::Dmr;
    }
    else if (selectedText == "Cooldown")
    {
        selected_type = Socket::Type::Cd;
    }
    else if (selectedText == "Bind")
    {
        selected_type = Socket::Type::Bind;
    }
    else if (selectedText == "Despair")
    {
        selected_type = Socket::Type::Despair;
    }
    else if (selectedText == "Autoheal")
    {
        selected_type = Socket::Type::AH;
    }
    else if (selectedText == "Rcv")
    {
        selected_type = Socket::Type::Rcv;
    }
    else if (selectedText == "Orb rate")
    {
        selected_type = Socket::Type::Slot;
    }
    else if (selectedText == "Map")
    {
        selected_type = Socket::Type::Map;
    }
    else if (selectedText == "Poison")
    {
        selected_type = Socket::Type::Poison;
    }
    else if (selectedText == "Resilience")
    {
        selected_type = Socket::Type::Resilience;
    }
    else if (selectedText == "None")
    {
        selected_type = Socket::Type::None;
    }

    emit acceptedSocket(row, column, selected_type);
    close();
}

void SocketSelection::on_buttonBox_rejected()
{
    close();
}

void SocketSelection::on_socketSelectionList_itemDoubleClicked(QListWidgetItem *item)
{
    assert(item);
    on_buttonBox_accepted();
}

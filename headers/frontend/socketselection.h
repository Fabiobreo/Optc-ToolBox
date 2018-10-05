#ifndef SOCKETSELECTION_H
#define SOCKETSELECTION_H

#include <QDialog>
#include <QListWidget>
#include <socket.h>

namespace Ui {
class SocketSelection;
}

class SocketSelection : public QDialog
{
    Q_OBJECT

public:
    explicit SocketSelection(int _row, int _column, std::vector<QListWidgetItem*>& _items, QWidget *parent = nullptr);
    ~SocketSelection();

signals:
    void acceptedSocket(int, int, Socket::Type);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_socketSelectionList_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::SocketSelection *ui;
    int row;
    int column;
};

#endif // SOCKETSELECTION_H

#ifndef Database_H
#define Database_H
#pragma once
#include <QMainWindow>
#include <QPushButton>
#include <QListWidgetItem>
#include <details.h>
#include <tools.h>
#include <map>
#include <utility.h>

class Details;

namespace Ui {
class Database;
}

class Database : public QMainWindow
{
    Q_OBJECT

public:
    explicit Database(Utility* _utility, QWidget* _parent = 0);
    ~Database();


private slots:
    void on_filterByName_textChanged(const QString& _text);
    void on_ownedMode_toggled(bool _checked);
    void on_showOwned_toggled(bool _checked);
    void on_characterList_itemClicked(QListWidgetItem* _item);
    void changeDetails(int _characterId);
    void redraw();

private:

    void openCloseDetails(short _id);

    Ui::Database *ui;
    std::vector<QPushButton*> buttons;
    Utility* utility;
    std::vector<Character*> characters;
    std::map<int, MyCharacter*> myCharacters;
    std::vector<QIcon> coloredIcons;
    std::vector<QIcon> grayIcons;
    Details* detailMenu = nullptr;
    bool open = false;
    int openId = 0;
};

#endif // Database_H

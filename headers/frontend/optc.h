#ifndef OPTC_H
#define OPTC_H

#include <QMainWindow>
#include <utility.h>
#include <parser.h>
#include <about.h>
#include <donate.h>
#include <details.h>

namespace Ui {
class Optc;
}

class Optc : public QMainWindow
{
    Q_OBJECT

public:
    explicit Optc(QWidget* _parent = nullptr);
    ~Optc();

    void loadCharacters(long _id);
    void logout();

signals:
    void save();

private slots:
    void on_actionLogout_triggered();

    void on_actionAbout_Optc_Toolbox_triggered();

    void on_actionSave_triggered();

    void on_actionBuy_me_a_coffee_triggered();

    void detail_request(bool _toOpen, short _id);

private:
    Ui::Optc *ui;
    About* aboutWindow;
    Donate* donateWindow;
    Parser* character_parser;
    std::vector<Character*> characters;
    std::map<std::string, Material*> materials;
    std::map<std::string, int> familiesMap;
    std::map<int, std::vector<MyCharacter*>> myCharacters;
    Utility utility;
};

#endif // OPTC_H

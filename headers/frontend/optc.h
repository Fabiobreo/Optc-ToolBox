#ifndef OPTC_H
#define OPTC_H

#include <QMainWindow>
#include <utility.h>
#include <parser.h>

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

private slots:
    void on_actionLogout_triggered();

private:
    Ui::Optc *ui;
    Parser* character_parser;
    std::vector<Character*> characters;
    std::map<std::string, Material*> materials;
    std::map<std::string, int> familiesMap;
    std::map<int, std::vector<MyCharacter*>> myCharacters;
    Utility utility;
};

#endif // OPTC_H

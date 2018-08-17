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
    explicit Optc(QWidget *parent = nullptr);
    ~Optc();

    void loadCharacters();

private:
    Ui::Optc *ui;
    Parser* character_parser;
    std::vector<Character*> characters;
    std::map<int, MyCharacter*> myCharacters;
    Utility utility;
};

#endif // OPTC_H

#ifndef DETAILS_H
#define DETAILS_H

#include <QDialog>
#include <map>
#include <database.h>
#include <utility.h>

class Character;

namespace Ui {
class Details;
}

class Details : public QDialog
{
    Q_OBJECT

public:
    explicit Details(Utility* _utility, short _characterId, QWidget *_parent = 0);
    ~Details();
signals:
    void changedOwnedState();
    void changeCharacterDetail(int _newId);
    void changeEditMode();

private slots:

    void on_LeftButton_clicked();

    void on_RightButton_clicked();

    void on_addCharacterButton_clicked();

    void on_removeCharacterButton_clicked();

    void editModeChangedDb();

    void on_detailsTabWidget_currentChanged(int index);

private:

    void loadCharacter(short _characterId);
    void setName(Character* _character);
    void setArt(Character* _character);
    void setTypes(Character* _character);
    void setRarity(Character* _character);
    void setClasses(Character* _character);
    void setStatsTab(Character* _character);
    void setCaptainTab(Character* _character);
    void setCaptainActionTab(Character* _character);
    void setSwapTab(Character* _character);
    void setSailorTab(Character* _character);
    void setSpecialTab(Character* _character);
    void setLimitBreakTab(Character* _character);
    void setEvolutionTab(Character* _character);
    void setTandemTab(Character* _character);

    void removeTab(QString name);
    Ui::Details *ui;
    Utility* utility;
    short characterId;
    std::vector<Character*>* characters;
    std::map<int, std::vector<MyCharacter*>>* myCharacters;
};

#endif // DETAILS_H

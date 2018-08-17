#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <stats.h>
#include <enums.h>
#include <iostream>
#include <vector>
#include <limitbreak.h>
#include <special.h>
#include <captain.h>
#include <sailor.h>
#include <QPixmap>

class Character
{
public:
    explicit Character(short _id, std::string _name, std::vector<Type>& _type, Class _first, Class _second = Class::None);
    friend std::ostream& operator<<(std::ostream &_os, Character &_character);

    void setName(std::string _name);
    std::string getName();
    short getId();
    void setId(short _id);

    //Class
    void setClasses(Class _first, Class _second = Class::None);
    Class getFirstClass() const;
    Class getSecondClass() const;

    //Type
    void setType(std::vector<Type>& _type);
    std::vector<Type> getType() const;

    //Stats
    void setStats(Stats* _stats);
    Stats* getStats();

    //Captain
    void setCaptain(Captain* _captain);
    bool hasCaptain() const;
    Captain* getCaptain();

    //Captain action
    void setCaptainAction(Captain* _captainAction);
    bool hasCaptainAction() const;
    Captain* getCaptainAction();

    //Sailor
    void addSailor(Sailor* _sailor);
    bool hasSailor() const;
    std::vector<Sailor> getSailors();

    //Special
    void setSpecial(Special* _special);
    bool hasSpecial() const;
    Special* getSpecial();

    //Evolution
    void setEvolution(Character* &_character, std::vector<Character*> &_evolvers);
    std::vector<Character*> getEvolution();
    std::vector<Character*> getEvolutionMaterials(Character* _character);

    //Limit Break
    void setLimitBreak(LimitBreak* _limitBreak);
    bool hasLimitBreak() const;
    LimitBreak* getLimitBreak();

    //Icons
    void setColoredIcon(QPixmap* _icon);
    QPixmap* getColoredIcon();
    void setGrayIcon(QPixmap* _icon);
    QPixmap* getGrayIcon();

    //Dual units
    bool hasDual();
    void addDualUnit(Character* _dual);
    std::vector<Character*> getDualUnits();
    std::string getSwapDescription();
    void setSwapDescription(std::string _description);

private:

    short id;
    std::string name;
    Class first_class;
    Class second_class;
    std::vector<Type> type;
    Stats stats;
    std::vector<Character*> evolution;
    std::vector<std::vector<Character*>> evolvers;
    LimitBreak limitBreak;
    Captain captain;
    Captain captainAction;
    std::vector<Sailor> sailors;
    Special special;
    QPixmap* coloredIcon;
    QPixmap* grayIcon;
    std::vector<Character*> dual_units;
    std::string swap_description;
};

#endif //CHARACTER_HPP

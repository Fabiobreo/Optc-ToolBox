#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>
#include <set>
#include <stats.h>
#include <enums.h>
#include <iostream>
#include <limitbreak.h>
#include <special.h>
#include <captain.h>
#include <sailor.h>
#include <tandem.h>
#include <material.h>
#include <QPixmap>

class Tandem;

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
    void setEvolution(Character* &_character, std::vector<Character*> &_evolvers, std::vector<Material*> _materials = std::vector<Material*>());
    std::vector<Character*> getEvolution();
    std::vector<Character*> getEvolvers(Character* _character);
    std::vector<Material*> getEvolutionMaterials(Character* _character);

    //Limit Break
    void setLimitBreak(LimitBreak* _limitBreak);
    bool hasLimitBreak() const;
    LimitBreak* getLimitBreak();

    //Icons
    void setColoredIcon(QPixmap* _icon);
    QPixmap* getColoredIcon();
    void setGrayIcon(QPixmap _icon);
    QPixmap* getGrayIcon();

    //Dual units
    bool hasDual();
    void addDualUnit(Character* _dual);
    std::vector<Character*> getDualUnits();
    std::string getSwapDescription();
    void setSwapDescription(std::string _description);

    void setFamily(std::vector<std::string>& _family);
    std::vector<std::string> getFamily();

    void setAvailabilities(std::set<Availability> _availabilities);
    void addAvailability(Availability _availability);
    std::set<Availability> getAvailabilities();

    void addTandem(Tandem* _tandem);
    std::vector<Tandem*> getTandems();
    bool hasTandem();

    //TODO
    friend QDataStream & operator >> (QDataStream &arch, Character& _object)
    {
        arch >> _object.id;
        return arch;
    }

    //TODO
    friend QDataStream & operator << (QDataStream &arch, const Character& _object)
    {
        arch << _object.id;
        return arch;
    }

private:

    short id;
    std::string name;
    Class first_class;
    Class second_class;
    std::vector<Type> type;
    Stats stats;
    std::vector<Character*> evolution;
    std::vector<std::vector<Character*>> evolvers;
    std::vector<std::vector<Material*>> evolverMaterials;
    LimitBreak limitBreak;
    Captain captain;
    Captain captainAction;
    std::vector<Sailor> sailors;
    Special special;
    QPixmap* coloredIcon;
    QPixmap grayIcon;
    std::vector<Character*> dual_units;
    std::string swap_description;
    std::vector<std::string> family;
    std::set<Availability> availabilities;
    std::vector<Tandem*> tandems;
};

#endif //CHARACTER_HPP

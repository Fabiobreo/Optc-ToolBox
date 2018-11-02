#ifndef TANDEM_H
#define TANDEM_H

#include <iostream>
#include <vector>

class Character;

class Tandem
{
public:
    explicit Tandem(std::string _name);

    void setName(std::string _name);
    void setDescription(std::string _description);
    void addUnit(Character* _character);

    std::string getName();
    std::string getDescription();
    std::vector<Character*> getUnits();

private:
    std::string name;
    std::string description;
    std::vector<Character*> units;
};

#endif // TANDEM_H

#include <tandem.h>

Tandem::Tandem(std::string _name) :
    name(_name)
{

}

void Tandem::setName(std::string _name)
{
    name = _name;
}

void Tandem::setDescription(std::string _description)
{
    description = _description;
}

void Tandem::addUnit(Character* _character)
{
    units.push_back(_character);
}

std::string Tandem::getName()
{
    return name;
}

std::string Tandem::getDescription()
{
    return description;
}

std::vector<Character*> Tandem::getUnits()
{
    return units;
}

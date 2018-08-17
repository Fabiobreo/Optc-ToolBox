#include <potential.h>

Potential::Potential(Potential::Type _type, short _value) :
type(_type)
{
    setValue(_value);
}

short Potential::getValue()
{
    return value;
}

void Potential::setValue(short _value)
{
    if (_value < MAXVALUE)
    {
        value = _value;
    }
}

Potential::Type Potential::getType()
{
    return type;
}

void Potential::addDescription(std::string _description)
{
    if (descriptions.size() < MAXVALUE)
    {
        descriptions.push_back(_description);
    }
}

std::vector<std::string> Potential::getDescriptions()
{
    return descriptions;
}

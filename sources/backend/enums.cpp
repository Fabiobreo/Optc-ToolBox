#include <enums.h>

std::string to_string(const Class _value)
{
    std::string to_string;
    switch (_value)
    {
        case Class::Fighter:
            to_string = "Fighter";
            break;
        case Class::Shooter:
            to_string = "Shooter";
            break;
        case Class::Slasher:
            to_string = "Slasher";
            break;
        case Class::Striker:
            to_string = "Striker";
            break;
        case Class::Free_Spirit:
            to_string = "Free Spirit";
            break;
        case Class::Cerebral:
            to_string = "Cerebral";
            break;
        case Class::Powerhouse:
            to_string = "Powerhouse";
            break;
        case Class::Driven:
            to_string = "Driven";
            break;
        case Class::Evolver:
            to_string = "Evolver";
            break;
        case Class::Booster:
            to_string = "Booster";
            break;
        default:
            to_string = "";
    }
    return to_string;
}

std::string to_string(const Type _value)
{
    std::string to_string;
    switch (_value)
    {
        case Type::STR:
            to_string = "STR";
            break;
        case Type::QCK:
            to_string = "QCK";
            break;
        case Type::DEX:
            to_string = "DEX";
            break;
        case Type::PSY:
            to_string = "PSY";
            break;
        case Type::INT:
            to_string = "INT";
            break;
        default:
            to_string = "None";
    }
    return to_string;
}

Type stringToType(std::string _value)
{
    std::transform(_value.begin(), _value.end(), _value.begin(), ::toupper);
    Type to_type = Type::STR;
    if (_value == "STR")
    {
        to_type = Type::STR;
    }
    else if (_value == "QCK")
    {
        to_type = Type::QCK;
    }
    else if (_value == "DEX")
    {
        to_type = Type::DEX;
    }
    else if (_value == "PSY")
    {
        to_type = Type::PSY;
    }
    else if (_value == "INT")
    {
        to_type = Type::INT;
    }
    else
    {
        to_type = Type::None;
    }
    return to_type;
}

Class stringToClass(std::string _value)
{
    std::transform(_value.begin(), _value.end(), _value.begin(), ::toupper);
    Class to_class;
    if (_value == "FIGHTER")
    {
        to_class = Class::Fighter;
    }
    else if (_value == "SHOOTER")
    {
        to_class = Class::Shooter;
    }
    else if (_value == "SLASHER")
    {
        to_class = Class::Slasher;
    }
    else if (_value == "STRIKER")
    {
        to_class = Class::Striker;
    }
    else if (_value == "FREESPIRIT")
    {
        to_class = Class::Free_Spirit;
    }
    else if (_value == "CEREBRAL")
    {
        to_class = Class::Cerebral;
    }
    else if (_value == "POWERHOUSE")
    {
        to_class = Class::Powerhouse;
    }
    else if (_value == "DRIVEN")
    {
        to_class = Class::Driven;
    }
    else if (_value == "EVOLVER")
    {
        to_class = Class::Evolver;
    }
    else if (_value == "BOOSTER")
    {
        to_class = Class::Booster;
    }
    else
    {
        to_class = Class::None;
    }
    return to_class;
}

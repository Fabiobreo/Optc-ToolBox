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
        to_string = "None";
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

std::string to_string(const Availability _avail)
{
    std::string to_string;
    switch (_avail)
    {
    case Availability::Raid:
        to_string = "Raid";
        break;
    case Availability::RaidNeo:
        to_string = "Neo Raid";
        break;
    case Availability::Coliseums:
        to_string = "Coliseums";
        break;
    case Availability::ColiseumsNeo:
        to_string = "Neo Coliseums";
        break;
    case Availability::Ambush:
        to_string = "Ambush";
        break;
    case Availability::Special:
        to_string = "Special";
        break;
    case Availability::FNOnly:
        to_string = "FN only";
        break;
    case Availability::GenericF2P:
        to_string = "Generic F2P";
        break;
    case Availability::StoryOnly:
        to_string = "Story only";
        break;
    case Availability::Limited:
        to_string = "Limited time";
        break;
    case Availability::LimitedTM:
        to_string = "TM Limited";
        break;
    case Availability::LRR:
        to_string = "Limited RR";
        break;
    case Availability::TM:
        to_string = "Treasure Map";
        break;
    default:
        to_string = "";
        break;
    }
    return to_string;
}

std::string to_string(Slots _slots)
{
    std::string to_string;
    switch (_slots)
    {
    case Slots::STR:
        to_string = "STR";
        break;
    case Slots::QCK:
        to_string = "QCK";
        break;
    case Slots::DEX:
        to_string = "DEX";
        break;
    case Slots::PSY:
        to_string = "PSY";
        break;
    case Slots::INT:
        to_string = "INT";
        break;
    case Slots::TND:
        to_string = "TND";
        break;
    case Slots::RCV:
        to_string = "RCV";
        break;
    case Slots::BLOCK:
        to_string = "BLOCK";
        break;
    case Slots::G:
        to_string = "G";
        break;
    case Slots::RAINBOW:
        to_string = "RAINBOW";
        break;
    case Slots::EMPTY:
        to_string = "EMPTY";
        break;
    case Slots::BOMB:
        to_string = "BOMB";
        break;
    default:
        to_string = "";
        break;
    }
    return to_string;
}

Type stringToType(std::string _value)
{
    std::transform(_value.begin(), _value.end(), _value.begin(), ::toupper);
    Type to_type = Type::StartType;
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
    _value.erase(std::remove(_value.begin(), _value.end(), ' '), _value.end());
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

Availability stringToAvailability(std::string _value)
{
    std::transform(_value.begin(), _value.end(), _value.begin(), ::toupper);
    Availability to_avail = Availability::StartAvailability;
    if (_value == "RAID")
    {
        to_avail = Availability::Raid;
    }
    else if (_value == "NEO RAID")
    {
        to_avail = Availability::RaidNeo;
    }
    else if (_value == "COLISEUMS")
    {
        to_avail = Availability::Coliseums;
    }
    else if (_value == "NEO COLISEUMS")
    {
        to_avail = Availability::ColiseumsNeo;
    }
    else if (_value == "AMBUSH")
    {
        to_avail = Availability::Ambush;
    }
    else if (_value == "SPECIAL")
    {
        to_avail = Availability::Special;
    }
    else if (_value == "FN ONLY")
    {
        to_avail = Availability::FNOnly;
    }
    else if (_value == "GENERIC F2P")
    {
        to_avail = Availability::GenericF2P;
    }
    else if (_value == "STORY ONLY")
    {
        to_avail = Availability::StoryOnly;
    }
    else if (_value == "LIMITED TIME")
    {
        to_avail = Availability::Limited;
    }
    else if (_value == "TM LIMITED")
    {
        to_avail = Availability::LimitedTM;
    }
    else if (_value == "LIMITED RR")
    {
        to_avail = Availability::LRR;
    }
    else if (_value == "TREASURE MAP")
    {
        to_avail = Availability::TM;
    }
    else
    {
        to_avail = Availability::EndAvailability;
    }
    return to_avail;
}

Slots stringToSlots(std::string _value)
{
    std::transform(_value.begin(), _value.end(), _value.begin(), ::toupper);
    Slots to_slots = Slots::StartSlots;
    if (_value == "STR")
    {
        to_slots = Slots::STR;
    }
    else if (_value == "QCK")
    {
        to_slots = Slots::QCK;
    }
    else if (_value == "DEX")
    {
        to_slots = Slots::DEX;
    }
    else if (_value == "PSY")
    {
        to_slots = Slots::PSY;
    }
    else if (_value == "INT")
    {
        to_slots = Slots::INT;
    }
    else if (_value == "TND")
    {
        to_slots = Slots::TND;
    }
    else if (_value == "RCV")
    {
        to_slots = Slots::RCV;
    }
    else if (_value == "BLOCK")
    {
        to_slots = Slots::BLOCK;
    }
    else if (_value == "G")
    {
        to_slots = Slots::G;
    }
    else if (_value == "RAINBOW")
    {
        to_slots = Slots::RAINBOW;
    }
    else if (_value == "EMPTY")
    {
        to_slots = Slots::EMPTY;
    }
    else if (_value == "BOMB")
    {
        to_slots = Slots::BOMB;
    }
    else
    {
        to_slots = Slots::EndSlots;
    }

    return to_slots;
}

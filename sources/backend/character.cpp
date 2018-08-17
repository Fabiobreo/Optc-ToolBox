#include <character.h>

std::ostream &operator<<(std::ostream &_os, Character &_character)
{
    _os << _character.name << " " << _character.stats.stars << (_character.stats.plus? "+" : "") << "* " << to_string(_character.type.at(0)) << " "
        << to_string(_character.first_class);
    std::string second_class = to_string(_character.second_class);
    if (!second_class.empty())
    {
        _os << "/" << second_class;
    }
    _os << std::endl;
    _os << "Id: " << _character.id << std::endl;
    _os << "Cost: " << _character.stats.cost << std::endl;
    _os << "Combo: " << _character.stats.combo << std::endl;
    _os << "Sockets: " << _character.stats.num_sockets;
    if (_character.hasLimitBreak())
    {
        LimitBreak* lb = _character.getLimitBreak();
        short fullsocket = lb->getAllImprovements().socket;
        if (fullsocket > 0)
        {
            _os << "->" << _character.stats.num_sockets + lb->getAllImprovements().socket;
        }
    }
    _os << std::endl;
    _os << "Max Level: " << _character.stats.max_level << std::endl;
    _os << "HP: " /*<< _character.stats.hp_min << "->"*/ << _character.stats.hp_max;
    if (_character.hasLimitBreak())
    {
        LimitBreak* lb = _character.getLimitBreak();
        _os << "->" << _character.stats.hp_max + lb->getAllImprovements().hp << " (+" << lb->getAllImprovements().hp << ")";
    }
     _os << std::endl;

    _os << "ATK: " /*<< _character.stats.atk_min << "->"*/ << _character.stats.atk_max;
    if (_character.hasLimitBreak())
    {
        LimitBreak* lb = _character.getLimitBreak();
        _os << "->" << _character.stats.atk_max + lb->getAllImprovements().atk << " (+" << lb->getAllImprovements().atk << ")";
    }
    _os << std::endl;

    _os << "RCV: " /*<< _character.stats.rcv_min << "->"*/ << _character.stats.rcv_max;
    if (_character.hasLimitBreak())
    {
        LimitBreak* lb = _character.getLimitBreak();
        _os << "->" << _character.stats.rcv_max + lb->getAllImprovements().rcv << " (+" << lb->getAllImprovements().rcv << ")";
    }
    _os << std::endl;

    if (_character.hasCaptain())
    {
        Captain* captain = _character.getCaptain();
        _os << "Captain ability: " << std::endl << "- " << captain->getDescription() << std::endl;

    }
    if (_character.hasLimitBreak())
    {
        LimitBreak *lb = _character.getLimitBreak();
        if (lb->hasNewCaptainAbilities())
        {
            std::vector<Captain> new_captain_abilities = lb->getNewCaptainAbilities();
            for (unsigned long i = 0; i < new_captain_abilities.size(); ++i)
            {
                int lbLevel = i - new_captain_abilities.size() + 1;
                _os << "- LB ";
                if (lbLevel == 0)
                {
                    _os << "Max";
                }
                else
                {
                    _os << std::to_string(i + 1);
                }
                _os << ": " << new_captain_abilities.at(i).getDescription() << std::endl;
            }
        }
        else
        {
            if (!_character.hasCaptain())
            {
                _os << "Captain ability:" << std::endl << "- None" << std::endl;
            }
        }
    }
    else
    {
        if (!_character.hasCaptain())
        {
            _os << "Captain ability:" << std::endl << "- None" << std::endl;
        }
    }

    if (_character.hasCaptainAction())
    {
        _os << "Captain action:" << std::endl << "- " <<_character.getCaptainAction()->getDescription() << std::endl;
    }

    _os << "Sailor: " << std::endl;
    if (_character.hasSailor())
    {
        for (auto sailor : _character.getSailors())
        {
            _os << "- " << sailor.getDescription() << std::endl;
        }
    }

    if (_character.hasLimitBreak())
    {
        LimitBreak *lb = _character.getLimitBreak();
        if (lb->hasNewSailorAbilities())
        {
            std::vector<Sailor> new_sailor_abilities = lb->getNewSailorAbilities();
            for (unsigned long i = 0; i < new_sailor_abilities.size(); ++i)
            {
                _os << "- LB " << std::to_string(i + 1) << ": " << new_sailor_abilities.at(i).getDescription() << std::endl;
            }
        }
        else
        {
            if (!_character.hasSailor())
            {
                _os << "- None" << std::endl;
            }
        }
    }
    else
    {
        if (!_character.hasSailor())
        {
            _os << "- None" << std::endl;
        }
    }

    if (_character.hasSpecial())
    {
        short cdReduction = 0;
        if (_character.hasLimitBreak())
        {
            LimitBreak *lb = _character.getLimitBreak();
            cdReduction = lb->getAllImprovements().cd;
        }
        Special* special = _character.getSpecial();
        if (special->getBase() != -1)
        {
            _os << "Special (" << special->getName() << "): " << std::endl;
            short cdSkill = special->getBase() - special->getMaxedCd();
            for (unsigned long i = 0; i < special->getDescription().size(); ++i)
            {
                if (!special->hasMultipleStages())
                {
                    _os << "- (" << special->getBase() << "->" << special->getMaxedCd();
                    if (cdReduction > 0)
                    {
                        _os << "->" << (special->getMaxedCd() - cdReduction);
                    }
                }
                else
                {
                    short stage_base_cd = special->getBase() - special->getStageOffset(i + 1);
                    _os << "- (" << stage_base_cd << "->" << (stage_base_cd - cdSkill);
                    if (cdReduction > 0)
                    {
                        _os << "->" << (stage_base_cd - cdSkill - cdReduction);
                    }
                }
                _os <<  "): " << special->getDescription().at(i) << std::endl;
            }
        }
        else
        {
            _os << "Special:" << std::endl << "None" << std::endl;
        }
    }
    else
    {
        _os << "Special: None" << std::endl;
    }

    if (_character.hasLimitBreak())
    {
        LimitBreak* lb = _character.getLimitBreak();
        _os << "Potential abilities: " << std::endl;
        for (auto potential : lb->getAllImprovements().potentials)
        {
            if (potential->getType() == Potential::Type::Enrage)
            {
                _os << "- Enrage" << std::endl;
            }
            else if (potential->getType() == Potential::Type::NoHealing)
            {
                _os << "- No Healing" << std::endl;
            }
            else if (potential->getType() == Potential::Type::CriticalHit)
            {
                _os << "- Critical Hit" << std::endl;
            }
            else if (potential->getType() == Potential::Type::SlotBind)
            {
                _os << "- Slot Bind" << std::endl;
            }
            else if (potential->getType() == Potential::Type::BarrierPenetration)
            {
                _os << "- Barrier Penetration" << std::endl;
            }
            else if (potential->getType() == Potential::Type::PinchHealing)
            {
                _os << "- Pinch Healing" << std::endl;
            }
            else if (potential->getType() == Potential::Type::DMRSTR)
            {
                _os << "- STR Damage Reduction" << std::endl;
            }
            else if (potential->getType() == Potential::Type::DMRQCK)
            {
                _os << "- QCK Damage Reduction" << std::endl;
            }
            else if (potential->getType() == Potential::Type::DMRDEX)
            {
                _os << "- DEX Damage Reduction" << std::endl;
            }
            else if (potential->getType() == Potential::Type::DMRPSY)
            {
                _os << "- PSY Damage Reduction" << std::endl;
            }
            else if (potential->getType() == Potential::Type::DMRINT)
            {
                _os << "- INT Damage Reduction" << std::endl;
            }
            else if (potential->getType() == Potential::Type::CDR)
            {
                _os << "- Cooldown Reduction" << std::endl;
            }
        }
    }

    _os << "Evolutions: " << (_character.evolution.empty() ? "None" : "") << std::endl;
    for (auto character : _character.evolution)
    {
        _os << " - " << character->name << " (Id: " << character->id << ")" << std::endl;
    }

    return _os;
}

Character::Character(short _id, std::string _name, std::vector<Type>& _type, Class _first, Class _second) :
        id(_id),
        name(std::move(_name))
{
    setType(_type);
    setClasses(_first, _second);
}


void Character::setClasses(Class _first, Class _second)
{
    first_class = _first;
    second_class = _second;
}

void Character::setType(std::vector<Type>& _type)
{
    type = _type;
}

void Character::setStats(Stats* _stats)
{
    stats = *_stats;
}

Class Character::getFirstClass() const
{
    return first_class;
}

Class Character::getSecondClass() const
{
    return second_class;
}

std::vector<Type> Character::getType() const
{
    return type;
}

Stats* Character::getStats()
{
    return &stats;
}

void Character::setCaptain(Captain* _captain)
{
    captain = *_captain;
}

bool Character::hasCaptain() const
{
    return !captain.getDescription().empty();
}

Captain* Character::getCaptain()
{
    return &captain;
}

void Character::setCaptainAction(Captain* _captainAction)
{
    captainAction = *_captainAction;
}

bool Character::hasCaptainAction() const
{
    return !captainAction.getDescription().empty();
}

Captain* Character::getCaptainAction()
{
    return &captainAction;
}

void Character::addSailor(Sailor* _sailor)
{
    sailors.push_back(*_sailor);
}

bool Character::hasSailor() const
{
    return !sailors.empty();
}
std::vector<Sailor> Character::getSailors()
{
    return sailors;
}

void Character::setSpecial(Special* _special)
{
    special = *_special;
}

bool Character::hasSpecial() const
{
    return !special.getDescription().empty();
}

Special* Character::getSpecial()
{
    return &special;
}

void Character::setEvolution(Character *&_character, std::vector<Character *> &_evolvers)
{
    evolution.push_back(_character);
    evolvers.push_back(_evolvers);
}

std::vector<Character *> Character::getEvolution()
{
    return evolution;
}

std::vector<Character *> Character::getEvolutionMaterials(Character *_character)
{
    for (unsigned long i = 0; i < evolution.size(); ++i)
    {
        Character *_char = evolution.at(i);
        if (_char == _character)
        {
            return evolvers.at(i);
        }
    }
    return std::vector<Character *>();
}

void Character::setLimitBreak(LimitBreak* _limitBreak)
{
    limitBreak = *_limitBreak;
}

bool Character::hasLimitBreak() const
{
    return (limitBreak.getTotalNodes() != 0);
}

LimitBreak* Character::getLimitBreak()
{
    return &limitBreak;
}

void Character::setName(std::string _name)
{
    name = _name;
}

std::string Character::getName()
{
    return name;
}

short Character::getId()
{
    return id;
}

void Character::setId(short _id)
{
    id = _id;
}

void Character::setColoredIcon(QPixmap* _icon)
{
    coloredIcon = _icon;
}

QPixmap* Character::getColoredIcon()
{
    return coloredIcon;
}

void Character::setGrayIcon(QPixmap* _icon)
{
    grayIcon = _icon;
}

QPixmap* Character::getGrayIcon()
{
    return grayIcon;
}

bool Character::hasDual()
{
    return !dual_units.empty();
}

void Character::addDualUnit(Character* _dual)
{
    dual_units.push_back(_dual);
}

std::vector<Character*> Character::getDualUnits()
{
    return dual_units;
}

std::string Character::getSwapDescription()
{
    return swap_description;
}

void Character::setSwapDescription(std::string _description)
{
    swap_description = _description;
}

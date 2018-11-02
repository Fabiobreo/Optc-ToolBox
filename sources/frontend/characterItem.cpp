#include "characterItem.h"

CharacterItem::CharacterItem(Character* _character, Utility* _utility) :
    character(_character),
    utility(_utility)
{
    QVariant v = qVariantFromValue(static_cast<void*>(character));
    setData(Qt::UserRole, v);
}

CharacterItem::CharacterItem()
{
    CharacterItem(nullptr, nullptr);
}

bool CharacterItem::operator<(const QListWidgetItem &_other) const
{
    // Retrieve other character
    void* otherData = _other.data(Qt::UserRole).value<void*>();
    Character* otherCharacter = static_cast<Character*>(otherData);

    bool result = true;

    if (utility->primarySortCondition == "Id")
    {
        result = (hasLowerId(character, otherCharacter) == utility->primarySortAscendingOrder);
    }
    else
    {
        int condition = checkCondition(character, otherCharacter, utility->primarySortCondition, utility->primarySortIncludeLimit);
        if (condition == LESS)
        {
            result = (true == utility->primarySortAscendingOrder);
        }
        else if (condition == GREATER)
        {
            result = (false == utility->primarySortAscendingOrder);
        }
        else    // Use secondary condition
        {
            if (utility->secondarySortCondition == "Id")
            {
                result = (hasLowerId(character, otherCharacter) == utility->secondarySortAscendingOrder);
            }
            else
            {
                int secondCondition = checkCondition(character, otherCharacter, utility->secondarySortCondition, utility->secondarySortIncludeLimit);
                if (secondCondition == LESS)
                {
                    result = (true == utility->secondarySortAscendingOrder);
                }
                else if (secondCondition == GREATER)
                {
                    result = (false == utility->secondarySortAscendingOrder);
                }
                else
                {
                    result = applyFinalConditions(character, otherCharacter);
                }
            }
        }
    }

    return result;
}


int CharacterItem::checkCondition(Character* _first, Character* _second, std::string _condition, bool _includeLimit) const
{
    if (_condition == "Rarity")
    {
        return hasLowerRarity(_first, _second);
    }
    else if (_condition == "Type")
    {
        return hasLowerType(_first, _second);
    }
    else if (_condition == "Family")
    {
        return hasLowerFamily(_first, _second);
    }
    else if (_condition == "Cost")
    {
        return hasLowerCost(_first, _second);
    }
    else if (_condition == "Primary Class")
    {
        return hasLowerPrimaryClass(_first, _second);
    }
    else if (_condition == "Secondary Class")
    {
        return hasLowerSecondaryClass(_first, _second);
    }
    else if (_condition == "HP")
    {
        return hasLowerHP(_first, _second, _includeLimit);
    }
    else if (_condition == "ATK")
    {
        return hasLowerATK(_first, _second, _includeLimit);
    }
    else if (_condition == "RCV")
    {
        return hasLowerRCV(_first, _second, _includeLimit);
    }
    else if (_condition == "Combo")
    {
        return hasLowerCombo(_first, _second);
    }
    else if (_condition == "Slots")
    {
        return hasLessSlots(_first, _second, _includeLimit);
    }
    else if (_condition == "Cooldown")
    {
        return hasLowerCooldown(_first, _second, _includeLimit);
    }
    else
    {
        return EQUAL;
    }
}

bool CharacterItem::applyFinalConditions(Character *_first, Character *_second) const
{
    int condition = EQUAL;

    // 1 - Type
    if (utility->primarySortCondition != "Type" && utility->secondarySortCondition != "Type")
    {
        condition = hasLowerType(_first, _second);
    }

    if (condition != EQUAL)
    {
        if (condition == LESS)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // 2 - Rarity
    if (utility->primarySortCondition != "Rarity" && utility->secondarySortCondition != "Rarity")
    {
        condition = hasLowerRarity(_first, _second);
    }

    if (condition != EQUAL) // Invert for rarity, I want rarest character first
    {
        if (condition == LESS)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    // 3 - Family
    if (utility->primarySortCondition != "Family" && utility->secondarySortCondition != "Family")
    {
        condition = hasLowerFamily(_first, _second);
    }

    if (condition != EQUAL)
    {
        if (condition == LESS)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // 4 - Id
    return hasLowerId(_first, _second);
}

bool CharacterItem::hasLowerId(Character* _first, Character* _second) const
{
    if (_first->getId() < _second->getId())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int CharacterItem::hasLowerRarity(Character* _first, Character* _second) const
{
    if (_first->getStats()->stars < _second->getStats()->stars)
    {
        return LESS;
    }
    else if (_first->getStats()->stars > _second->getStats()->stars)
    {
        return GREATER;
    }
    else
    {
        if (!_first->getStats()->plus && _second->getStats()->plus)
        {
            return LESS;
        }
        else if (_first->getStats()->plus && !_second->getStats()->plus)
        {
            return GREATER;
        }
        else
        {
            return EQUAL;
        }
    }
}

int CharacterItem::hasLowerType(Character* _first, Character* _second) const
{
    if (_first->getType().size() == 1 && _second->getType().size() == 1)  // None have dual
    {
        if (static_cast<int>(_first->getType()[0]) < static_cast<int>(_second->getType()[0]))
        {
            return LESS;
        }
        else if (static_cast<int>(_first->getType()[0]) > static_cast<int>(_second->getType()[0]))
        {
            return GREATER;
        }
        else
        {
            return EQUAL;
        }
    }
    else if (_first->getType().size() > 1 && _second->getType().size() == 1)
    {
        return LESS;
    }
    else if (_first->getType().size() == 1 && _second->getType().size() > 1)
    {
        return GREATER;
    }
    else    // Both have dual
    {
        if (static_cast<int>(_first->getType()[0]) < static_cast<int>(_second->getType()[0]))
        {
            return LESS;
        }
        else if (static_cast<int>(_first->getType()[0]) > static_cast<int>(_second->getType()[0]))
        {
            return GREATER;
        }
        else
        {
            if (static_cast<int>(_first->getType()[1]) < static_cast<int>(_second->getType()[1]))
            {
                return LESS;
            }
            else if (static_cast<int>(_first->getType()[1]) > static_cast<int>(_second->getType()[1]))
            {
                return GREATER;
            }
            else
            {
                return EQUAL;
            }
        }
    }
}

int CharacterItem::hasLowerFamily(Character* _first, Character* _second) const
{
    if (_first->getFamily().size() == 1 && _second->getFamily().size() == 1) // None have dual
    {
        if ((*utility->familiesMap)[_first->getFamily()[0]] < (*utility->familiesMap)[_second->getFamily()[0]])
        {
            return LESS;
        }
        else if ((*utility->familiesMap)[_first->getFamily()[0]] > (*utility->familiesMap)[_second->getFamily()[0]])
        {
            return GREATER;
        }
        else
        {
            return EQUAL;
        }
    }
    else if (_first->getFamily().size() > 1 && _second->getFamily().size() == 1)
    {
        return LESS;
    }
    else if (_first->getFamily().size() == 1 && _second->getFamily().size() > 1)
    {
        return GREATER;
    }
    else    // Both have dual
    {

        if ((*utility->familiesMap)[_first->getFamily()[0]] < (*utility->familiesMap)[_second->getFamily()[0]])
        {
            return LESS;
        }
        else if ((*utility->familiesMap)[_first->getFamily()[0]] > (*utility->familiesMap)[_second->getFamily()[0]])
        {
            return GREATER;
        }
        else
        {
            if ((*utility->familiesMap)[_first->getFamily()[1]] < (*utility->familiesMap)[_second->getFamily()[1]])
            {
                return LESS;
            }
            else if ((*utility->familiesMap)[_first->getFamily()[1]] > (*utility->familiesMap)[_second->getFamily()[1]])
            {
                return GREATER;
            }
            else
            {
                return EQUAL;
            }
        }
    }
}

int CharacterItem::hasLowerCost(Character* _first, Character* _second) const
{
    if (_first->getStats()->cost < _second->getStats()->cost)
    {
        return LESS;
    }
    else if (_first->getStats()->cost > _second->getStats()->cost)
    {
        return GREATER;
    }
    else
    {
        return EQUAL;
    }
}

int CharacterItem::hasLowerCombo(Character* _first, Character* _second) const
{
    if (_first->getStats()->combo < _second->getStats()->combo)
    {
        return LESS;
    }
    else if (_first->getStats()->combo > _second->getStats()->combo)
    {
        return GREATER;
    }
    else
    {
        return EQUAL;
    }
}

int CharacterItem::hasLowerPrimaryClass(Character* _first, Character* _second) const
{
    if ((int)_first->getFirstClass() < (int)_second->getFirstClass())
    {
        return LESS;
    }
    else if ((int)_first->getFirstClass() > (int)_second->getFirstClass())
    {
        return GREATER;
    }
    else
    {
        return EQUAL;
    }
}

int CharacterItem::hasLowerSecondaryClass(Character* _first, Character* _second) const
{
    if ((int)_first->getSecondClass() < (int)_second->getSecondClass())
    {
        return LESS;
    }
    else if ((int)_first->getSecondClass() > (int)_second->getSecondClass())
    {
        return GREATER;
    }
    else
    {
        return EQUAL;
    }
}

int CharacterItem::hasLowerHP(Character* _first, Character* _second, bool _includeLimit) const
{
    int firstHp = _first->getStats()->hp_max;
    int secondHp = _second->getStats()->hp_max;

    if (_includeLimit)
    {
        if (_first->hasLimitBreak())
        {
            firstHp += _first->getLimitBreak()->getAllImprovements().hp;
        }

        if (_second->hasLimitBreak())
        {
            secondHp += _second->getLimitBreak()->getAllImprovements().hp;
        }
    }

    if (firstHp < secondHp)
    {
        return LESS;
    }
    else if (firstHp > secondHp)
    {
        return GREATER;
    }
    else
    {
        return EQUAL;
    }
}

int CharacterItem::hasLowerATK(Character* _first, Character* _second, bool _includeLimit) const
{
    int firstAtk = _first->getStats()->atk_max;
    int secondAtk = _second->getStats()->atk_max;

    if (_includeLimit)
    {
        if (_first->hasLimitBreak())
        {
            firstAtk += _first->getLimitBreak()->getAllImprovements().atk;
        }

        if (_second->hasLimitBreak())
        {
            secondAtk += _second->getLimitBreak()->getAllImprovements().atk;
        }
    }

    if (firstAtk < secondAtk)
    {
        return LESS;
    }
    else if (firstAtk > secondAtk)
    {
        return GREATER;
    }
    else
    {
        return EQUAL;
    }
}

int CharacterItem::hasLowerRCV(Character* _first, Character* _second, bool _includeLimit) const
{
    int firstRcv = _first->getStats()->rcv_max;
    int secondRcv = _second->getStats()->rcv_max;

    if (_includeLimit)
    {
        if (_first->hasLimitBreak())
        {
            firstRcv += _first->getLimitBreak()->getAllImprovements().rcv;
        }

        if (_second->hasLimitBreak())
        {
            secondRcv += _second->getLimitBreak()->getAllImprovements().rcv;
        }
    }

    if (firstRcv < secondRcv)
    {
        return LESS;
    }
    else if (firstRcv > secondRcv)
    {
        return GREATER;
    }
    else
    {
        return EQUAL;
    }
}

int CharacterItem::hasLessSlots(Character* _first, Character* _second, bool _includeLimit) const
{
    int firstSockets = _first->getStats()->num_sockets;
    int secondSockets = _second->getStats()->num_sockets;

    if (_includeLimit)
    {
        if (_first->hasLimitBreak())
        {
            firstSockets += _first->getLimitBreak()->getAllImprovements().socket;
        }

        if (_second->hasLimitBreak())
        {
            secondSockets += _second->getLimitBreak()->getAllImprovements().socket;
        }
    }

    if (firstSockets < secondSockets)
    {
        return LESS;
    }
    else if (firstSockets > secondSockets)
    {
        return GREATER;
    }
    else
    {
        return EQUAL;
    }
}

int CharacterItem::hasLowerCooldown(Character* _first, Character* _second, bool _includeLimit) const
{
    int firstCd = _first->getSpecial()->getMaxedCd();
    int secondCd = _second->getSpecial()->getMaxedCd();

    if (_includeLimit)
    {
        if (_first->hasLimitBreak())
        {
            firstCd -= _first->getLimitBreak()->getAllImprovements().cd;
        }

        if (_second->hasLimitBreak())
        {
            secondCd -= _second->getLimitBreak()->getAllImprovements().cd;
        }
    }

    if (firstCd < secondCd)
    {
        return LESS;
    }
    else if (firstCd > secondCd)
    {
        return GREATER;
    }
    else
    {
        return EQUAL;
    }
}


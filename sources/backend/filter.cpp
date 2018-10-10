#include "filter.h"
#include <enums.h>
#include <QRegularExpression>


Condition::Condition(std::string _id, Target _target, Operator _operator, std::string _value) :
    id(_id),
    target(_target),
    op(_operator),
    value(_value),
    includeLimitBreak(false),
    typeTargetSet(false),
    classTargetSet(false)
{
    //// Target to description
    // Primary targets
    targetToDescriptionMap[Target::Id] = "Id";
    targetToDescriptionMap[Target::Name] = "Name";
    targetToDescriptionMap[Target::Type] = "Type";
    targetToDescriptionMap[Target::Class] = "Class";
    targetToDescriptionMap[Target::PrimaryClass] = "Primary Class";
    targetToDescriptionMap[Target::SecondaryClass] = "Secondary Class";
    targetToDescriptionMap[Target::Stats] = "Statistics";
    targetToDescriptionMap[Target::Rarity] = "Rarity";
    targetToDescriptionMap[Target::Cost] = "Cost";
    targetToDescriptionMap[Target::Combo] = "Combo";
    targetToDescriptionMap[Target::Slots] = "Num. of slots";
    targetToDescriptionMap[Target::MaxLvl] = "Max level";
    targetToDescriptionMap[Target::ExpToMax] = "Exp to max";
    targetToDescriptionMap[Target::Evolution] = "Evolution";
    targetToDescriptionMap[Target::Tandem] = "Tandem";
    targetToDescriptionMap[Target::Captain] = "Captain";
    targetToDescriptionMap[Target::Sailor] = "Sailor";
    targetToDescriptionMap[Target::Special] = "Special";
    targetToDescriptionMap[Target::LimitBreak] = "Limit Break";
    targetToDescriptionMap[Target::MyCharacter] = "My Characters";
    targetToDescriptionMap[Target::Availability] = "Availability";

    // Stats targets
    targetToDescriptionMap[Target::minHp] = "Min Hp";
    targetToDescriptionMap[Target::minAtk] = "Min Atk";
    targetToDescriptionMap[Target::minRcv] = "Min Rcv";
    targetToDescriptionMap[Target::maxHp] = "Max Hp";
    targetToDescriptionMap[Target::maxAtk] = "Max Atk";
    targetToDescriptionMap[Target::maxRcv] = "Max Rcv";

    // Captain targets
    targetToDescriptionMap[Target::BoostHP] = "Boost HP";
    targetToDescriptionMap[Target::BoostATK] = "Boost ATK";
    targetToDescriptionMap[Target::BoostRCV] = "Boost RCV";
    targetToDescriptionMap[Target::TimingBased] = "Timing based";
    targetToDescriptionMap[Target::BoostSpecial] = "Boost special";
    targetToDescriptionMap[Target::HpBased] = "Hp-Based ATK";
    targetToDescriptionMap[Target::ChainMultiplier] = "Boost chain";
    targetToDescriptionMap[Target::ComboBased] = "Combo based";
    targetToDescriptionMap[Target::CdReducer] = "Cd reduction";
    targetToDescriptionMap[Target::DamageReducer] = "Dmg reduction";
    targetToDescriptionMap[Target::Healer] = "Healer";
    targetToDescriptionMap[Target::Tanker] = "Tanker";
    targetToDescriptionMap[Target::Zombies] = "Zombies";
    targetToDescriptionMap[Target::EoTDamageDealer] = "EoT Dmg";
    targetToDescriptionMap[Target::BeliBooster] = "Beli boost";
    targetToDescriptionMap[Target::ExpBooster] = "Exp boost";
    targetToDescriptionMap[Target::DropDoublers] = "Double drop";

    // Sailor targets
    targetToDescriptionMap[Target::BoostHPSailor] = "Boost base HP";
    targetToDescriptionMap[Target::BoostATKSailor] = "Boost base ATK";
    targetToDescriptionMap[Target::BoostRCVSailor] = "Boost base RCV";
    targetToDescriptionMap[Target::ParalysisReducer] = "Paralysis reducers";
    targetToDescriptionMap[Target::BlindnessReducer] = "Blindness reducers";
    targetToDescriptionMap[Target::SilenceReducer] = "Silence reducers";
    targetToDescriptionMap[Target::SpecialRewindReducer] = "Special rewind restorers";
    targetToDescriptionMap[Target::SpecialCdSailor] = "Special Cooldown Reducer";
    targetToDescriptionMap[Target::OrbKeeper] = "Orb keeper";
    targetToDescriptionMap[Target::BlownAway] = "Blow Away Resistance";
    targetToDescriptionMap[Target::AdditionalDamage] = "Additional Damage";
    targetToDescriptionMap[Target::BeneficialOrb] = "Beneficial orb";

    // Limit Break targets
    targetToDescriptionMap[Target::NewCaptain] = "Acquire new Captains";
    targetToDescriptionMap[Target::NewSailors] = "Acquire new Sailors";
    targetToDescriptionMap[Target::AcquireSocket] = "Acquire socket slots";
    targetToDescriptionMap[Target::ReduceCd] = "Reduce Cooldown";
    targetToDescriptionMap[Target::Potential] = "Potential";

    // Evolution targets
    targetToDescriptionMap[Target::HasEvolution] = "Have";
    targetToDescriptionMap[Target::NotHasEvolution] = "Not have";
    targetToDescriptionMap[Target::MultipleEvolutions] = "Multiple possible";
    targetToDescriptionMap[Target::MoreThanAEvolution] = "Evolution can evolve";

    //// Description to target
    descriptionToTargetMap["Id"] = Target::Id;
    descriptionToTargetMap["Name"] = Target::Name;
    descriptionToTargetMap["Type"] = Target::Type;
    descriptionToTargetMap["Class"] = Target::Class;
    descriptionToTargetMap["Primary Class"] = Target::PrimaryClass;
    descriptionToTargetMap["Secondary Class"] = Target::SecondaryClass;
    descriptionToTargetMap["Statistics"] = Target::Stats;
    descriptionToTargetMap["Rarity"] = Target::Rarity;
    descriptionToTargetMap["Cost"] = Target::Cost;
    descriptionToTargetMap["Combo"] = Target::Combo;
    descriptionToTargetMap["Num. of slots"] = Target::Slots;
    descriptionToTargetMap["Max level"] = Target::MaxLvl;
    descriptionToTargetMap["Exp to max"] = Target::ExpToMax;
    descriptionToTargetMap["Evolution"] = Target::Evolution;
    descriptionToTargetMap["Tandem"] = Target::Tandem;
    descriptionToTargetMap["Captain"] = Target::Captain;
    descriptionToTargetMap["Sailor"] = Target::Sailor;
    descriptionToTargetMap["Special"] = Target::Special;
    descriptionToTargetMap["Limit Break"] = Target::LimitBreak;
    descriptionToTargetMap["My Characters"] = Target::MyCharacter;
    descriptionToTargetMap["Availability"] = Target::Availability;

    descriptionToTargetMap["Min Hp"] = Target::minHp;
    descriptionToTargetMap["Min Atk"] = Target::minAtk;
    descriptionToTargetMap["Min Rcv"] = Target::minRcv;
    descriptionToTargetMap["Max Hp"] = Target::maxHp;
    descriptionToTargetMap["Max Atk"] = Target::maxAtk;
    descriptionToTargetMap["Max Rcv"] = Target::maxRcv;

    descriptionToTargetMap["Boost HP"] = Target::BoostHP;
    descriptionToTargetMap["Boost ATK"] = Target::BoostATK;
    descriptionToTargetMap["Boost RCV"] = Target::BoostRCV;
    descriptionToTargetMap["Timing based"] = Target::TimingBased;
    descriptionToTargetMap["Boost special"] = Target::BoostSpecial;
    descriptionToTargetMap["Hp-Based ATK"] = Target::HpBased;
    descriptionToTargetMap["Boost chain"] = Target::ChainMultiplier;
    descriptionToTargetMap["Combo based"] = Target::ComboBased;
    descriptionToTargetMap["Cd reduction"] = Target::CdReducer;
    descriptionToTargetMap["Dmg reduction"] = Target::DamageReducer;
    descriptionToTargetMap["Healer"] = Target::Healer;
    descriptionToTargetMap["Tanker"] = Target::Tanker;
    descriptionToTargetMap["Zombies"] = Target::Zombies;
    descriptionToTargetMap["EoT Dmg"] = Target::EoTDamageDealer;
    descriptionToTargetMap["Beli boost"] = Target::BeliBooster;
    descriptionToTargetMap["Exp boost"] = Target::ExpBooster;
    descriptionToTargetMap["Double drop"] = Target::DropDoublers;

    // Sailor targets
    descriptionToTargetMap["Boost base HP"] = Target::BoostHPSailor;
    descriptionToTargetMap["Boost base ATK"] = Target::BoostATKSailor;
    descriptionToTargetMap["Boost base RCV"] = Target::BoostRCVSailor;
    descriptionToTargetMap["Paralysis reducers"] = Target::ParalysisReducer;
    descriptionToTargetMap["Blindness reducers"] = Target::BlindnessReducer;
    descriptionToTargetMap["Silence reducers"] = Target::SilenceReducer;
    descriptionToTargetMap["Special rewind restorers"] = Target::SpecialRewindReducer;
    descriptionToTargetMap["Special Cooldown Reducer"] = Target::SpecialCdSailor;
    descriptionToTargetMap["Orb keeper"] = Target::OrbKeeper;
    descriptionToTargetMap["Blow Away Resistance"] = Target::BlownAway;
    descriptionToTargetMap["Additional Damage"] = Target::AdditionalDamage;
    descriptionToTargetMap["Beneficial orb"] = Target::BeneficialOrb;

    // Limit Break targets
    descriptionToTargetMap["Acquire new Captains"] = Target::NewCaptain;
    descriptionToTargetMap["Acquire new Sailors"] = Target::NewSailors;
    descriptionToTargetMap["Acquire socket slots"] = Target::AcquireSocket;
    descriptionToTargetMap["Reduce Cooldown"] = Target::ReduceCd;
    descriptionToTargetMap["Potential"] = Target::Potential;

    // Evolution targets
    descriptionToTargetMap["Have"] = Target::HasEvolution;
    descriptionToTargetMap["Not have"] = Target::NotHasEvolution;
    descriptionToTargetMap["Multiple possible"] = Target::MultipleEvolutions;
    descriptionToTargetMap["Evolution can evolve"] = Target::MoreThanAEvolution;

    //// Operator to description
    operatorToDescriptionMap[Operator::Equal] = "=";
    operatorToDescriptionMap[Operator::Unequal] = "≠";
    operatorToDescriptionMap[Operator::Greater] = ">";
    operatorToDescriptionMap[Operator::GreaterEqual] = "≥";
    operatorToDescriptionMap[Operator::Less] = "<";
    operatorToDescriptionMap[Operator::LessEqual] = "≤";

    //// Description to operator
    descriptionToOperatorMap["="] = Operator::Equal;
    descriptionToOperatorMap["≠"] = Operator::Unequal;
    descriptionToOperatorMap[">"] = Operator::Greater;
    descriptionToOperatorMap["≥"] = Operator::GreaterEqual;
    descriptionToOperatorMap["<"] = Operator::Less;
    descriptionToOperatorMap["≤"] = Operator::LessEqual;

    //// Target to possible operations
    targetToPossibleOperations[Target::Id] = "Integer";
    targetToPossibleOperations[Target::Name] = "OnlyEquals";
    targetToPossibleOperations[Target::Type] = "OnlyEquals";
    targetToPossibleOperations[Target::Class] = "OnlyEquals";
    targetToPossibleOperations[Target::PrimaryClass] = "OnlyEquals";
    targetToPossibleOperations[Target::SecondaryClass] = "OnlyEquals";
    targetToPossibleOperations[Target::Stats] = "Integer";
    targetToPossibleOperations[Target::Rarity] = "Integer";
    targetToPossibleOperations[Target::Cost] = "Integer";
    targetToPossibleOperations[Target::Combo] = "Integer";
    targetToPossibleOperations[Target::Slots] = "Integer";
    targetToPossibleOperations[Target::MaxLvl] = "Integer";
    targetToPossibleOperations[Target::ExpToMax] = "Integer";
    targetToPossibleOperations[Target::Tandem] = "OnlyEquals";
    targetToPossibleOperations[Target::Captain] = "Decimal";
    targetToPossibleOperations[Target::Sailor] = "Integer";
    targetToPossibleOperations[Target::LimitBreak] = "OnlyEquals";
    targetToPossibleOperations[Target::Availability] = "OnlyEquals";
    // To check
    targetToPossibleOperations[Target::Special] = "Decimal";
    targetToPossibleOperations[Target::MyCharacter] = "Integer";
}

Condition::Condition(std::string _id, Target _target, Target _secondaryTarget, Operator _operator, std::string _value)
{
    Condition(_id, _target, _operator, _value);
    secondaryTarget = _secondaryTarget;
}

std::string Condition::getId()
{
    return id;
}

Condition::Target* Condition::getTarget()
{
    return &target;
}

Condition::Target* Condition::getSecondaryTarget()
{
    return &secondaryTarget;
}

Condition::Operator* Condition::getOperator()
{
    return &op;
}

std::string Condition::getValue()
{
    return value;
}

bool Condition::getIncludeLimitBreak()
{
    return includeLimitBreak;
}

Type Condition::getTypeValue()
{
    return typeValue;
}

Class Condition::getClassValue()
{
    return classValue;
}

Potential::Type Condition::getPotentialTarget()
{
    return potentialTarget;
}

void Condition::setId(std::string _id)
{
    id = _id;
}

void Condition::setTarget(Target _target)
{
    target = _target;
}

void Condition::setSecondaryTarget(Target _target)
{
    secondaryTarget = _target;
}

void Condition::setOperator(Operator _operator)
{
    op = _operator;
}

void Condition::setValue(std::string _value)
{
    value = _value;
}

void Condition::setIncludeLimitBreak(bool _include)
{
    includeLimitBreak = _include;
}

void Condition::setTypeValue(Type _type)
{
    typeValue = _type;
}

void Condition::setClassValue(Class _class)
{
    classValue = _class;
}

void Condition::setPotentialTarget(Potential::Type _potentialTarget)
{
    potentialTarget = _potentialTarget;
}

bool Condition::isMet(Character* _character)
{
    bool conditionMet = false;
    if (target == Target::Id)
    {
        conditionMet = numericConditionMet(_character->getId());
    }
    else if (target == Target::Name)
    {
        std::vector<std::string> family = _character->getFamily();
        for (std::string fam : family)
        {
            std::transform(fam.begin(), fam.end(), fam.begin(), ::tolower);
            std::transform(value.begin(), value.end(), value.begin(), ::tolower);
            if (fam.find(value) != std::string::npos)
            {
                conditionMet = true;
                break;
            }
        }
    }
    else if (target == Target::Type)
    {
        if (op == Operator::Equal)
        {
            for (Type characterType : _character->getType())
            {
                if (characterType == typeValue)
                {
                    conditionMet = true;
                    break;
                }
            }
        }
        else if (op == Operator::Unequal)
        {
            conditionMet = true;
            for (Type characterType : _character->getType())
            {
                if (characterType != typeValue)
                {
                    conditionMet = conditionMet && true;
                }
                else
                {
                    conditionMet = conditionMet && false;
                }
            }
        }
    }
    else if (target == Target::PrimaryClass)
    {
        std::vector<Character*> characterToCheck = {_character};
        if (_character->hasDual())
        {
            characterToCheck.push_back(_character->getDualUnits()[0]);
            characterToCheck.push_back(_character->getDualUnits()[1]);
        }

        if (op == Operator::Equal)
        {
            for (Character* checkingChar : characterToCheck)
            {
                if (classValue == checkingChar->getFirstClass())
                {
                    conditionMet = true;
                }
            }
        }
        else if (op == Operator::Unequal)
        {
            conditionMet = true;
            for (Character* checkingChar : characterToCheck)
            {
                if (classValue != checkingChar->getFirstClass())
                {
                    conditionMet = conditionMet && true;
                }
                else
                {
                    conditionMet = conditionMet && false;
                }
            }
        }
    }
    else if (target == Target::SecondaryClass)
    {
        std::vector<Character*> characterToCheck = {_character};
        if (_character->hasDual())
        {
            characterToCheck.push_back(_character->getDualUnits()[0]);
            characterToCheck.push_back(_character->getDualUnits()[1]);
        }

        if (op == Operator::Equal)
        {
            for (Character* checkingChar : characterToCheck)
            {
                if (classValue == checkingChar->getSecondClass())
                {
                    conditionMet = true;
                }
            }
        }
        else if (op == Operator::Unequal)
        {
            conditionMet = true;
            for (Character* checkingChar : characterToCheck)
            {
                if (classValue != checkingChar->getSecondClass())
                {
                    conditionMet = conditionMet && true;
                }
                else
                {
                    conditionMet = conditionMet && false;
                }
            }
        }
    }
    else if (target == Target::Class)
    {
        std::vector<Character*> characterToCheck = {_character};
        if (_character->hasDual())
        {
            characterToCheck.push_back(_character->getDualUnits()[0]);
            characterToCheck.push_back(_character->getDualUnits()[1]);
        }

        if (op == Operator::Equal)
        {
            for (Character* checkingChar : characterToCheck)
            {
                if (classValue == checkingChar->getFirstClass() || classValue == checkingChar->getSecondClass())
                {
                    conditionMet = true;
                }
            }
        }
        else if (op == Operator::Unequal)
        {
            conditionMet = true;
            for (Character* checkingChar : characterToCheck)
            {
                if (classValue != checkingChar->getFirstClass() && classValue != checkingChar->getSecondClass())
                {
                    conditionMet = conditionMet && true;
                }
                else
                {
                    conditionMet = conditionMet && false;
                }
            }
        }
    }
    else if (target == Target::Stats)
    {
        if (secondaryTarget == Target::minHp)
        {
            conditionMet = numericConditionMet(_character->getStats()->hp_min);
        }
        else if (secondaryTarget == Target::minAtk)
        {
            conditionMet = numericConditionMet(_character->getStats()->atk_min);
        }
        else if (secondaryTarget == Target::minRcv)
        {
            conditionMet = numericConditionMet(_character->getStats()->rcv_min);
        }
        else if (secondaryTarget == Target::maxHp)
        {
            conditionMet = numericConditionMet(_character->getStats()->hp_max);

            if (includeLimitBreak)
            {
                if (_character->hasLimitBreak())
                {
                    short limitHp = _character->getLimitBreak()->getAllImprovements().hp;
                    conditionMet = conditionMet || numericConditionMet(_character->getStats()->hp_max + limitHp);
                }
            }
        }
        else if (secondaryTarget == Target::maxAtk)
        {
            conditionMet = numericConditionMet(_character->getStats()->atk_max);

            if (includeLimitBreak)
            {
                if (_character->hasLimitBreak())
                {
                    short limitAtk = _character->getLimitBreak()->getAllImprovements().atk;
                    conditionMet = conditionMet || numericConditionMet(_character->getStats()->atk_max + limitAtk);
                }
            }
        }
        else if (secondaryTarget == Target::maxRcv)
        {

            conditionMet = numericConditionMet(_character->getStats()->rcv_max);

            if (includeLimitBreak)
            {
                if (_character->hasLimitBreak())
                {
                    short limitRcv = _character->getLimitBreak()->getAllImprovements().rcv;
                    conditionMet = conditionMet || numericConditionMet(_character->getStats()->rcv_max + limitRcv);
                }
            }
        }
    }
    else if (target == Target::Rarity)
    {
        conditionMet = numericConditionMet(_character->getStats()->stars);
    }
    else if (target == Target::Cost)
    {
        conditionMet = numericConditionMet(_character->getStats()->cost);
    }
    else if (target == Target::Combo)
    {
        conditionMet = numericConditionMet(_character->getStats()->combo);
    }
    else if (target == Target::Slots)
    {
        conditionMet = numericConditionMet(_character->getStats()->num_sockets);

        if (includeLimitBreak)
        {
            if (_character->hasLimitBreak())
            {
                short limitSocket = _character->getLimitBreak()->getAllImprovements().socket;
                conditionMet = conditionMet || numericConditionMet(_character->getStats()->num_sockets + limitSocket);
            }
        }
    }
    else if (target == Target::MaxLvl)
    {
        conditionMet = numericConditionMet(_character->getStats()->max_level);
    }
    else if (target == Target::ExpToMax)
    {
        conditionMet = numericConditionMet(_character->getStats()->exp_to_max);
    }
    else if (target == Target::Evolution)
    {
        if (secondaryTarget == Target::HasEvolution)
        {
            conditionMet = _character->getEvolution().size() > 0;
        }
        else if (secondaryTarget == Target::NotHasEvolution)
        {
            conditionMet = _character->getEvolution().size() == 0;
        }
        else if (secondaryTarget == Target::MultipleEvolutions)
        {
            conditionMet = _character->getEvolution().size() > 1;
        }
        else if (secondaryTarget == Target::MoreThanAEvolution)
        {
            for (Character* evoChar : _character->getEvolution())
            {
                conditionMet = conditionMet || (evoChar->getEvolution().size() > 0);
            }
        }
    }
    else if (target == Target::Tandem)
    {
        conditionMet = _character->hasTandem();
    }
    else if (target == Target::Captain)
    {
        if (_character->hasCaptain())
        {
            QString matcher;

            QString valueTarget = "\\D*(by|up to) ";
            valueTarget += QString::fromStdString(getRegexFromValue(value));

            // All matchers
            if (secondaryTarget == Target::BoostHP || secondaryTarget == Target::BoostATK || secondaryTarget == Target::BoostRCV)
            {
                // Add target
                QString statTarget = "";
                if (secondaryTarget == Target::BoostHP)
                {
                    statTarget += "HP";
                }
                else if (secondaryTarget == Target::BoostATK)
                {
                    statTarget += "ATK";
                }
                else if (secondaryTarget == Target::BoostRCV)
                {
                    statTarget += "RCV";
                }

                matcher += ")";

                // Add type/class
                QString classTypeTarget = " of\\D*";
                if (typeTargetSet)
                {
                    if (typeTarget == Type::StartType)
                    {
                        classTypeTarget += "(all characters|all others)";
                    }
                    else if (typeTarget == Type::EndTypes)
                    {
                        classTypeTarget += "";
                    }
                    else
                    {
                        classTypeTarget += "\\[" + QString::fromStdString(to_string(typeTarget)) + "\\]";
                    }
                }

                if (classTargetSet)
                {
                    classTypeTarget += QString::fromStdString(to_string(classTarget));
                }

                valueTarget += "x";
                matcher = "(Boosts.+" + statTarget + classTypeTarget + valueTarget + ")";

                if (secondaryTarget != Target::BoostATK)
                {
                    matcher += "|(Boosts.+" + classTypeTarget + ".+and their " + statTarget + valueTarget + ")";
                }

            }
            else if (secondaryTarget == Target::TimingBased)
            {
                matcher = "(after scoring|following a chain|perfect|great|good)";
            }
            else if (secondaryTarget == Target::BoostSpecial)
            {
                matcher = "Boosts damage.+specials";
            }
            else if (secondaryTarget == Target::HpBased)
            {
                matcher = "Boosts ATK.+proportionally to";
            }
            else if (secondaryTarget == Target::ChainMultiplier)
            {
                matcher = "Boosts.+chain multiplier";
            }
            else if (secondaryTarget == Target::ComboBased)
            {
                matcher = "Boosts.+hit in the chain";
            }
            else if (secondaryTarget == Target::CdReducer)
            {
                matcher = "Reduces cooldown" + valueTarget + " turn";
            }
            else if (secondaryTarget == Target::DamageReducer)
            {
                matcher = "Reduces (any )?damage received" + valueTarget + "%";
            }
            else if (secondaryTarget == Target::Healer)
            {
                matcher = "Recovers";
            }
            else if (secondaryTarget == Target::Tanker)
            {
                matcher = "Reduces (any )?damage.+if HP.+99";
            }
            else if (secondaryTarget == Target::Zombies)
            {
                matcher = "Protects from defeat";
            }
            else if (secondaryTarget == Target::EoTDamageDealer)
            {
                matcher = "(deals|cuts).+end of each turn";
            }
            else if (secondaryTarget == Target::BeliBooster)
            {
                matcher = "Boosts.+Beli" + valueTarget + "x";
            }
            else if (secondaryTarget == Target::ExpBooster)
            {
                matcher = "Boosts.+EXP" + valueTarget + "x";
            }
            else if (secondaryTarget == Target::DropDoublers)
            {
                matcher = "Duplicating a drop";
            }

            // Load all captains
            std::vector<std::string> captains;
            if (_character->hasCaptain())
            {
                captains.push_back(_character->getCaptain()->getDescription());
            }

            if (_character->hasLimitBreak())
            {
                for (Captain cap : _character->getLimitBreak()->getNewCaptainAbilities())
                {
                    captains.push_back(cap.getDescription());
                }
            }

            if (_character->hasDual())
            {
                std::vector<Character*> duals = _character->getDualUnits();
                if (duals[0]->hasCaptain())
                {
                    captains.push_back(duals[0]->getCaptain()->getDescription());
                }
                if (duals[1]->hasCaptain())
                {
                    captains.push_back(duals[1]->getCaptain()->getDescription());
                }
            }

            QRegularExpression regex(matcher, QRegularExpression::CaseInsensitiveOption);
            for (std::string cap : captains)
            {
                QRegularExpressionMatch match = regex.match(QString::fromStdString(cap));
                if (match.hasMatch())
                {
                    conditionMet = true;
                }
            }
        }
    }
    else if (target == Target::Sailor)
    {
        QString matcher;
        if (secondaryTarget == Target::BoostHPSailor || secondaryTarget == Target::BoostATKSailor || secondaryTarget == Target::BoostRCVSailor)
        {
            // Add target
            QString statTarget = "";
            if (secondaryTarget == Target::BoostHPSailor)
            {
                statTarget += "HP";
            }
            else if (secondaryTarget == Target::BoostATKSailor)
            {
                statTarget += "ATK";
            }
            else if (secondaryTarget == Target::BoostRCVSailor)
            {
                statTarget += "RCV";
            }

            // Add type/class
            QString classTypeTarget = " of\\D*";
            if (typeTargetSet)
            {
                if (typeTarget == Type::StartType)
                {
                    classTypeTarget += "(all characters|all others)";
                }
                else if (typeTarget == Type::EndTypes)
                {
                    classTypeTarget += "";
                }
                else
                {
                    classTypeTarget += "\\[" + QString::fromStdString(to_string(typeTarget)) + "\\]";
                }
            }

            if (classTargetSet)
            {
                classTypeTarget += QString::fromStdString(to_string(classTarget));
            }

            matcher = "(Boosts.+base " + statTarget + classTypeTarget + ")";

            if (secondaryTarget != Target::BoostATK)
            {
                matcher += "|(Boosts.+" + classTypeTarget + ".+and their " + statTarget + ")";
            }
        }
        else if (secondaryTarget == Target::ParalysisReducer)
        {
            matcher = "(reduces|removes|resists).+Paralysis";
        }
        else if (secondaryTarget == Target::BlindnessReducer)
        {
            matcher = "(reduces|removes|resists).+blindness";
        }
        else if (secondaryTarget == Target::SilenceReducer)
        {
            matcher = "(reduces|removes|resists).+silence";
        }
        else if (secondaryTarget == Target::SpecialRewindReducer)
        {
            matcher = "Restores (his|her) own special";
        }
        else if (secondaryTarget == Target::SpecialCdSailor)
        {
            matcher = "When any.+character uses a special, reduces own cooldown";
        }
        else if (secondaryTarget == Target::OrbKeeper)
        {
            matcher = "If this character has.+" + QString::fromStdString(to_string(slotTarget)) + ".+" + QString::fromStdString(value);
        }
        else if (secondaryTarget == Target::BlownAway)
        {
            matcher = "Cannot be Blown away";
        }
        else if (secondaryTarget == Target::AdditionalDamage)
        {
            matcher = "Additional.+Damage";
        }
        else if (secondaryTarget == Target::BeneficialOrb)
        {
            QString slotTargetDesc = "";
            if (slotTarget != Slots::StartSlots)
            {
                slotTargetDesc = "\\[" + QString::fromStdString(to_string(slotTarget)) + "\\]";
            }

            QString classTypeTarget = "";
            if (typeTargetSet)
            {
                if (typeTarget == Type::StartType)
                {
                    classTypeTarget += "(all characters|all others)";
                }
                else if (typeTarget == Type::EndTypes)
                {
                    classTypeTarget += "this";
                }
                else
                {
                    classTypeTarget += "\\[" + QString::fromStdString(to_string(typeTarget)) + "\\]";
                }
            }

            if (classTargetSet)
            {
                classTypeTarget += QString::fromStdString(to_string(classTarget));
            }
            matcher = "Makes " + slotTargetDesc + "\\D*orbs \"beneficial\" for " + classTypeTarget + "\\D*character";
        }

        std::vector<std::string> sailors;

        if (_character->hasSailor())
        {
            for (Sailor sail : _character->getSailors())
            {
                sailors.push_back(sail.getDescription());
            }
        }

        if (_character->hasDual())
        {
            std::vector<Character*> duals = _character->getDualUnits();
            if (duals[0]->hasSailor())
            {
                for (Sailor sail : duals[0]->getSailors())
                {
                    sailors.push_back(sail.getDescription());
                }
            }
            if (duals[1]->hasSailor())
            {
                for (Sailor sail : duals[1]->getSailors())
                {
                    sailors.push_back(sail.getDescription());
                }
            }
        }

        // Include limit break
        if (includeLimitBreak)
        {
            if (_character->hasLimitBreak())
            {
                for (Sailor sail : _character->getLimitBreak()->getNewSailorAbilities())
                {
                    sailors.push_back(sail.getDescription());
                }
            }
        }


        QRegularExpression regex(matcher, QRegularExpression::CaseInsensitiveOption);
        for (std::string sailor : sailors)
        {
            QRegularExpressionMatch match = regex.match(QString::fromStdString(sailor));
            if (match.hasMatch())
            {
                conditionMet = true;
            }
        }

    }
    else if (target == Target::Special)
    {
        // TODO
    }
    else if (target == Target::LimitBreak)
    {
        if (_character->hasLimitBreak())
        {
            LimitBreak::Improvements improvements = _character->getLimitBreak()->getAllImprovements();
            if (secondaryTarget == Target::Potential)
            {
                std::vector<Potential*> potentials = improvements.potentials;
                if (op == Operator::Equal)
                {
                    for (Potential* pot : potentials)
                    {
                        if (potentialTarget == pot->getType())
                        {
                            conditionMet = true;
                            break;
                        }
                    }
                }
                else if (op == Operator::Unequal)
                {
                    conditionMet = true;
                    for (Potential* pot : potentials)
                    {
                        if (potentialTarget != pot->getType())
                        {
                            conditionMet = conditionMet && true;
                        }
                        else
                        {
                            conditionMet = conditionMet && false;
                        }
                    }
                }
            }
            else if (secondaryTarget == Target::NewCaptain)
            {
                    conditionMet = improvements.new_captain;
            }
            else if (secondaryTarget == Target::NewSailors)
            {
                    conditionMet = improvements.new_sailor > 0 ? true : false;
            }
            else if (secondaryTarget == Target::AcquireSocket)
            {
                    conditionMet = improvements.socket > 0 ? true : false;
            }
            else if (secondaryTarget == Target::ReduceCd)
            {
                    conditionMet = improvements.cd > 0 ? true : false;
            }
        }
    }
    else if (target == Target::MyCharacter)
    {
        // TODO
    }
    else if (target == Target::Availability)
    {
        std::set<Availability> availabilities = _character->getAvailabilities();
        if (op == Operator::Equal)
        {
            if (availabilities.find(availabilityValue) != availabilities.end())
            {
                conditionMet = true;
            }
        }
        else if (op == Operator::Unequal)
        {
            conditionMet = true;
            if (availabilities.find(availabilityValue) != availabilities.end())
            {
                conditionMet = false;
            }
        }
    }

    return conditionMet;
}


std::string Condition::getDescriptionFromTarget(Target _target)
{
    return targetToDescriptionMap[_target];
}

Condition::Target Condition::getTargetFromDescription(std::string _description)
{
    return descriptionToTargetMap[_description];
}

std::string Condition::getDescriptionFromOperator(Operator _operator)
{
    return operatorToDescriptionMap[_operator];
}

Condition::Operator Condition::getOperatorFromDescription(std::string _description)
{
    return descriptionToOperatorMap[_description];
}

std::vector<std::string> Condition::getPossibleOperators(Target _target)
{
    std::vector<std::string> operators;
    operators.push_back(getDescriptionFromOperator(Operator::Equal));
    operators.push_back(getDescriptionFromOperator(Operator::Unequal));
    if (targetToPossibleOperations[_target] == "Integer" || targetToPossibleOperations[_target] == "Decimal")
    {
        operators.push_back(getDescriptionFromOperator(Operator::Greater));
        operators.push_back(getDescriptionFromOperator(Operator::GreaterEqual));
        operators.push_back(getDescriptionFromOperator(Operator::Less));
        operators.push_back(getDescriptionFromOperator(Operator::LessEqual));
    }
    return operators;
}

std::string Condition::getPossibleOperationsTypeFromTarget(Target _target)
{
    return targetToPossibleOperations[_target];
}


bool Condition::numericConditionMet(int _valueToCheck)
{
    int conditionValue = std::stoi(value);
    if (op == Operator::Equal)
    {
        if (_valueToCheck == conditionValue)
        {
            return true;
        }
    }
    else if (op == Operator::Unequal)
    {
        if (_valueToCheck != conditionValue)
        {
            return true;
        }
    }
    else if (op == Operator::Greater)
    {
        if (_valueToCheck > conditionValue)
        {
            return true;
        }
    }
    else if (op == Operator::GreaterEqual)
    {
        if (_valueToCheck >= conditionValue)
        {
            return true;
        }
    }
    else if (op == Operator::Less)
    {
        if (_valueToCheck < conditionValue)
        {
            return true;
        }
    }
    else if (op <= Operator::LessEqual)
    {
        if (_valueToCheck <= conditionValue)
        {
            return true;
        }
    }
    return false;
}

std::string Condition::getRegexFromValue(std::string _value)
{
    std::vector<short> integerPart;
    std::vector<short> fractionalPart;
    bool parsingInteger = true;
    for (char c : _value)
    {
        if (c == '.')
        {
            parsingInteger = false;
            continue;
        }
        else
        {
            short value = c -'0';
            if (parsingInteger)
            {
                integerPart.push_back(value);
            }
            else
            {
                fractionalPart.push_back(value);
            }
        }
    }

    if (integerPart.empty())
    {
        integerPart.push_back(0);
    }
    std::string integerString;
    std::string fractionalString;

    for (unsigned int i = 0; i < integerPart.size(); ++i)
    {
        integerString += std::to_string(integerPart[i]);
    }

    for (unsigned int i = 0; i < fractionalPart.size(); ++i)
    {
        fractionalString += std::to_string(fractionalPart[i]);
    }

    std::string regex = "(";
    if (op == Operator::Greater || op == Operator::GreaterEqual || op == Operator::Unequal)
    {
        // Regex greater than the last decimal digit. Starting with zero
        regex += integerString + "\\." + fractionalString + "[0]+[1-9]+";

        // Regex greater than the last decimal digit. Starting with one to nine
        regex += "|" + integerString + "\\." + fractionalString + "[1-9]+[0-9]*";

        // Regex greater than one or more magnitude higher than integer part.
        regex += "|[1-9]";
        for (unsigned int i = 0; i < integerPart.size() - 1; ++i)
        {
            regex += "[0-9]";
        }
        regex += "[0-9]+\\.?[0-9]*";

        // Regex greater than the integer part.
        for (int i = static_cast<int>(integerPart.size()) - 1; i >= 0; --i)
        {
            if (integerPart[static_cast<unsigned int>(i)] != 9)
            {
                regex += "|";
                for (int j = i - 1; j >= 0; --j)
                {
                    regex += std::to_string(integerPart[static_cast<unsigned int>(j)]);
                }

                regex += "[" + std::to_string(integerPart[static_cast<unsigned int>(i)] + 1) + "-9]";

                for (int j = i + 1; j < static_cast<int>(integerPart.size()); ++j)
                {
                    regex += "[0-9]";
                }

                regex += "\\.?[0-9]*";
            }
        }

        // Regex greater than the decimal part.
        for (unsigned int i = 0; i < fractionalPart.size(); ++i)
        {
            if (fractionalPart[i] != 9)
            {
                regex += "|" + integerString + "\\.";

                // Add fractional part before as is
                for (unsigned int j = 0; j < i; ++j)
                {
                    regex += std::to_string(fractionalPart[j]);
                }

                regex += "[" + std::to_string(fractionalPart[i] + 1) + "-9]";
                regex += "[0-9]*";
            }
        }
    }

    if (op == Operator::Unequal)
    {
        regex += "|";
    }

    if (op == Operator::Less || op == Operator::LessEqual || op == Operator::Unequal)
    {
        regex += "0";

        //Regex lesser than integer
        for (int i = static_cast<int>(integerPart.size()) - 1; i >= 0; --i)
        {
            if (integerPart[static_cast<unsigned int>(i)] != 0)
            {
                if (!(i == 0 && integerPart[static_cast<unsigned int>(i)] == 1))
                {
                    std::string noFraction;
                    for (int j = 0; j < i; ++j)
                    {
                        noFraction += std::to_string(integerPart[static_cast<unsigned int>(j)]);
                    }
                    noFraction += "[0-" + std::to_string(integerPart[static_cast<unsigned int>(i)] - 1) + "]";

                    for (int j = i + 1; j < static_cast<int>(integerPart.size()); ++j)
                    {
                        noFraction += "[0-9]";
                    }

                    regex += "|" + noFraction;
                    regex += "|" + noFraction + "\\.[0-9]*";
                }
            }
        }

        //Regex with less integer size
        for (unsigned int i = 1; i < integerPart.size(); ++i)
        {
            std::string noFraction;

            noFraction += "[0-9]";
            for (unsigned int j = i + 1; j < integerPart.size(); ++j)
            {
                noFraction += "[0-9]";
            }
            regex += "|" + noFraction;
            regex += "|" + noFraction + "\\.[0-9]*";
        }


        // Regex lesser than fractional
        for (int j = static_cast<int>(fractionalPart.size()) - 1; j >= 0; --j)
        {
            regex += "|";

            regex += integerString + "\\.";
            for (int i = 0; i < j; ++i)
            {
                regex += std::to_string(fractionalPart[static_cast<unsigned int>(i)]);
            }
            regex += "[0-" + std::to_string(fractionalPart[static_cast<unsigned int>(j)] - 1) + "][0-9]*";
        }

        // Regex integer without fractional part
        if (!fractionalPart.empty())
        {
            regex += "|" + integerString;
        }
    }

    if (op == Operator::Equal || op == Operator::GreaterEqual || op == Operator::LessEqual)
    {
        if (op == Operator::Equal)
        {
            regex += _value;
        }
        else
        {
            regex += "|" + _value;
        }
    }

    regex += ")";
    return regex;
}


Type Condition::getTypeTarget()
{
    return typeTarget;
}

Class Condition::getClassTarget()
{
    return classTarget;
}

void Condition::setTypeTarget(Type _type)
{
    typeTarget = _type;
    typeTargetSet = true;
}

void Condition::setClassTarget(Class _class)
{
    classTarget = _class;
    classTargetSet = true;
}

void Condition::setAvailabilityTarget(Availability _availabilityTarget)
{
    availabilityValue = _availabilityTarget;
}

Availability Condition::getAvailabilityTarget()
{
    return availabilityValue;
}

Slots Condition::getSlotTarget()
{
    return slotTarget;
}

void Condition::setSlotsTarget(Slots _slotsTarget)
{
    slotTarget = _slotsTarget;
}











Filter::Filter(Utility* _utility) :
    utility(_utility)
{
    std::vector<Character*> characters = *utility->characters;
    for (Character* character : characters)
    {
        charactersMap[character->getId()] = character;
    }
}

void Filter::addAndCondition(Condition _condition)
{
    if (*_condition.getTarget() != Condition::Target::PrimaryTargets)
    {
        andConditions.push_back(_condition);
    }
}

void Filter::addOrCondition(Filter _filter)
{
    orConditions.push_back(_filter);
}

std::set<int> Filter::filter(std::set<int> _ids)
{
    // Filtering by andConditions gives stricter set
    for (Condition condition : andConditions)
    {
        for (std::set<int>::iterator iterator = _ids.begin(); iterator != _ids.end(); )
        {
            int id = *iterator;
            if (!condition.isMet(charactersMap[id]))
            {
                iterator = _ids.erase(iterator);
                continue;
            }
            else
            {
                iterator++;
            }
        }
    }

    // Get all subsets from orConditions
    std::set<int> filteredIds;
    for (Filter filt : orConditions)
    {
        std::set<int> tmpFiltered = filt.filter(_ids);
        filteredIds.insert(tmpFiltered.begin(), tmpFiltered.end());
    }

    // Add only and conditions if no orConditions were set
    if (orConditions.empty())
    {
        filteredIds = _ids;
    }

    return filteredIds;
}

void Filter::resetFilters()
{
    andConditions.clear();
    orConditions.clear();
}

void Filter::setId(std::string _id)
{
    id = _id;
}

std::string Filter::getId()
{
    return id;
}

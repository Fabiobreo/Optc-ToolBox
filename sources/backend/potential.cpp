#include <potential.h>

Potential::Potential(Potential::Type _type, short _value) :
type(_type)
{
    setValue(_value);

    descriptionToType["Enrage"] = Type::Enrage;
    descriptionToType["No Healing"] = Type::NoHealing;
    descriptionToType["Critical Hit"] = Type::CriticalHit;
    descriptionToType["Slot Bind"] = Type::SlotBind;
    descriptionToType["Barrier Penetration"] = Type::BarrierPenetration;
    descriptionToType["Pinch Healing"] = Type::PinchHealing;
    descriptionToType["Dmr red. STR"] = Type::DMRSTR;
    descriptionToType["Dmr red. QCK"] = Type::DMRQCK;
    descriptionToType["Dmr red. DEX"] = Type::DMRDEX;
    descriptionToType["Dmr red. PSY"] = Type::DMRPSY;
    descriptionToType["Dmr red. INT"] = Type::DMRINT;
    descriptionToType["Cooldown red."] = Type::CDR;
    descriptionToType["Double Special"] = Type::DoubleSpecial;

    typeToDescription[Type::Enrage] = "Enrage";
    typeToDescription[Type::NoHealing] = "No Healing";
    typeToDescription[Type::CriticalHit] = "Critical Hit";
    typeToDescription[Type::SlotBind] = "Slot Bind";
    typeToDescription[Type::BarrierPenetration] = "Barrier Penetration";
    typeToDescription[Type::PinchHealing] = "Pinch Healing";
    typeToDescription[Type::DMRSTR] = "Dmr red. STR";
    typeToDescription[Type::DMRQCK] = "Dmr red. QCK";
    typeToDescription[Type::DMRDEX] = "Dmr red. DEX";
    typeToDescription[Type::DMRPSY] = "Dmr red. PSY";
    typeToDescription[Type::DMRINT] = "Dmr red. INT";
    typeToDescription[Type::CDR] = "Cooldown red.";
    typeToDescription[Type::DoubleSpecial] = "Double Special";
}

short Potential::getValue()
{
    return value;
}

void Potential::setValue(short _value)
{
    if (_value <= MAXVALUE)
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

std::string Potential::getDescriptionFromType(Potential::Type _potential)
{
    return typeToDescription[_potential];
}

Potential::Type Potential::getTypeFromDescription(std::string _potential)
{
    return descriptionToType[_potential];
}

#include <special.h>

Special::Special()
{

}

void Special::setDescription(const std::string &_description, unsigned long _num)
{
    if (_num > 0)
    {
        while (_num > description.size())
        {
            description.push_back("");
        }
        description[_num - 1] = _description;
    }
}

void Special::addDescription(std::string _description)
{
    description.push_back(_description);
}

std::vector<std::string> Special::getDescription() const
{
    return description;
}

void Special::setBase(short _special_base)
{
    base = _special_base;
}

short Special::getBase() const
{
    return base;
}

void Special::setMaxLevel(short _max_level)
{
    max_level = _max_level;
}

short Special::getMaxLevel() const
{
    return max_level;
}

void Special::setMaxedCd(short _max_cd)
{
    if (_max_cd > 0 && _max_cd <= base)
    {
        max_level = static_cast<short>(base - _max_cd + 1);
    }
}

short Special::getMaxedCd() const
{
    if (base != -1)
    {
        if (max_level != -1)
        {
            return static_cast<short>(base - max_level + 1);
        }
    }
    return base;
}

std::string Special::getStage(unsigned long _num)
{
    if (_num > 0 && _num <= description.size())
    {
        return description[_num - 1];
    }
    else
    {
        return "";
    }
}

bool Special::hasMultipleStages()
{
    return description.size() > 1;
}

unsigned long Special::getNumberOfStages()
{
    return description.size();
}

void Special::setStageOffset(unsigned long _num, short _value)
{
    if (_num > 0)
    {
        while (_num > offsets.size())
        {
            offsets.push_back(0);
        }
        offsets[_num - 1] = _value;
    }
}

void Special::addOffset(short _value)
{
    offsets.push_back(_value);
}


short Special::getStageOffset(unsigned long _num)
{
    if (_num > 0 && _num <= offsets.size())
    {
        return offsets[_num - 1];
    }
    return 0;
}

void Special::setName(std::string _name)
{
    name = _name;
}

std::string Special::getName()
{
    return name;
}


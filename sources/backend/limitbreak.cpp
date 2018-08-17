#include <limitBreak.h>

void LimitBreak::addNode(LimitBreak::NodeType _type, Stats::Type _stats, short _value)
{
    Node node{};
    node.type = _type;
    if (_type == LimitBreak::NodeType::STATS)
    {
        node.stats = _stats;
        node.value = _value;
        nodes.push_back(node);
    }
}

void LimitBreak::addNode(LimitBreak::NodeType _type, Potential::Type _potential, short _value)
{
    Node node{};
    node.type = _type;
    if (_type == LimitBreak::NodeType::POTENTIAL)
    {
        node.potential = _potential;
        node.value = _value;
        nodes.push_back(node);
        Potential potential(_potential, _value);
        potentialAbilities.push_back(potential);
    }
}

void LimitBreak::addNode(LimitBreak::NodeType _type)
{
    Node node{};
    node.type = _type;
    nodes.push_back(node);
}

void LimitBreak::addNode(NodeType _type, Sailor _sailor)
{
    Node node{};
    node.type = _type;
    if (_type == LimitBreak::NodeType::SAILOR)
    {
        node.value = 0;
        nodes.push_back(node);
        sailorAbilities.push_back(_sailor);
    }
}

void LimitBreak::addNode(NodeType _type, Captain _captain)
{
    Node node{};
    node.type = _type;
    if (_type == LimitBreak::NodeType::CAPTAIN)
    {
        node.value = 0;
        nodes.push_back(node);
        captainAbilities.push_back(_captain);
    }
}

void LimitBreak::addNode(LimitBreak::NodeType _type, short _value)
{
    Node node{};
    node.type = _type;
    if (_type == LimitBreak::NodeType::CD || _type == LimitBreak::NodeType::SOCKET)
    {
        node.value = _value;
        nodes.push_back(node);
    }
}

LimitBreak::Improvements LimitBreak::getNodeImprovements(short _value)
{
    LimitBreak::Improvements improvements = Improvements();
    if (_value > 0 && _value <= (short) nodes.size())
    {
        Node node = nodes.at(static_cast<unsigned long>(_value - 1));
        if (node.type == LimitBreak::NodeType::STATS)
        {
            if (node.stats == Stats::Type::HP)
            {
                improvements.hp = node.value;
            }
            else if (node.stats == Stats::Type::ATK)
            {
                improvements.atk = node.value;
            }
            else if (node.stats == Stats::Type::RCV)
            {
                improvements.rcv = node.value;
            }
        }
        else if (node.type == LimitBreak::NodeType::SOCKET)
        {
            improvements.socket = node.value;
        }
        else if (node.type == LimitBreak::NodeType::CD)
        {
            improvements.cd = node.value;
        }
        else if (node.type == LimitBreak::NodeType::CAPTAIN)
        {
            improvements.new_captain = true;
        }
        else if (node.type == LimitBreak::NodeType::SAILOR)
        {
            improvements.new_sailor++;
        }
        else if (node.type == LimitBreak::NodeType::POTENTIAL)
        {
            for (Potential& potential : potentialAbilities)
            {
                if (potential.getType() == node.potential)
                {
                    improvements.potentials.push_back(&potential);
                }
            }
        }
    }
    return improvements;
}

LimitBreak::Improvements LimitBreak::getUnlockedImprovements(unsigned long _value)
{
    LimitBreak::Improvements improvements = Improvements();
    if (_value > 0 && _value <= nodes.size())
    {
        for (unsigned long i = 0; i < _value; ++i)
        {
            Node node = nodes.at(i);
            if (node.type == LimitBreak::NodeType::STATS)
            {
                if (node.stats == Stats::Type::HP)
                {
                    improvements.hp += node.value;
                }
                else if (node.stats == Stats::Type::ATK)
                {
                    improvements.atk += node.value;
                }
                else if (node.stats == Stats::Type::RCV)
                {
                    improvements.rcv += node.value;
                }
            }
            else if (node.type == LimitBreak::NodeType::SOCKET)
            {
                improvements.socket += node.value;
            }
            else if (node.type == LimitBreak::NodeType::CD)
            {
                improvements.cd += node.value;
            }
            else if (node.type == LimitBreak::NodeType::CAPTAIN)
            {
                improvements.new_captain = true;
            }
            else if (node.type == LimitBreak::NodeType::SAILOR)
            {
                improvements.new_sailor++;
            }
            else if (node.type == LimitBreak::NodeType::POTENTIAL)
            {
                for (Potential& potential : potentialAbilities)
                {
                    if (potential.getType() == node.potential)
                    {
                        improvements.potentials.push_back(&potential);
                    }
                }
            }
        }
    }
    return improvements;
}

unsigned long LimitBreak::getTotalNodes() const
{
    return nodes.size();
}

LimitBreak::Improvements LimitBreak::getAllImprovements()
{
    return getUnlockedImprovements(nodes.size());
}

std::vector<Captain> LimitBreak::getNewCaptainAbilities()
{
    return captainAbilities;
}


bool LimitBreak::hasNewCaptainAbilities()
{
    return captainAbilities.size() > 0;
}


std::vector<Sailor> LimitBreak::getNewSailorAbilities()
{
    return sailorAbilities;
}

bool LimitBreak::hasNewSailorAbilities()
{
    return sailorAbilities.size() > 0;
}

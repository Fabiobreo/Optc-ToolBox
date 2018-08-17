#include <myCharacter.h>
#include <cmath>

MyCharacter::MyCharacter(Character* _template_character) :
        template_character(_template_character)
{}

void MyCharacter::setLevel(short _level)
{
    if (_level > 0 && _level < (template_character->getStats()->max_level))
    {
        level = _level;
    }
}

short MyCharacter::getLevel()
{
    return level;
}

std::vector<int> MyCharacter::getStats()
{
    std::vector<int> current_stats;
    Stats* stats = template_character->getStats();

    //FIXME this works only for linear growth
    double hp_step = ((double)(stats->hp_max - stats->hp_min)) / ((double)(stats->max_level - 1));
    double atk_step = ((double)(stats->atk_max - stats->atk_min)) / ((double)(stats->max_level - 1));
    double rcv_step = ((double)(stats->rcv_max - stats->rcv_min)) / ((double)(stats->max_level - 1));

    auto current_hp = static_cast<int>(std::ceil(stats->hp_min + hp_step * (level - 1)));
    auto current_atk = static_cast<int>(std::ceil(stats->atk_min + atk_step * (level - 1)));
    auto current_rcv = static_cast<int>(std::ceil(stats->rcv_min + rcv_step * (level - 1)));
    current_stats.push_back(current_hp);
    current_stats.push_back(current_atk);
    current_stats.push_back(current_rcv);

    return current_stats;
}

void MyCharacter::addSocket(Socket _socket)
{
    if ( (int)current_sockets.size() < (getCurrentSocketsTotalNum() - 1))
    {
        bool alreadyIn = false;
        for (Socket socket : current_sockets)
        {
            if (socket.getType() == _socket.getType())
            {
                // If already in, change value
                alreadyIn = true;
                socket.setValue(_socket.getValue());
                break;
            }
        }

        // If not already in, add.
        if (!alreadyIn)
        {
            current_sockets.push_back(_socket);
        }
    }
}

void MyCharacter::removeSocket(Socket::Type _type)
{
    int index = -1;
    for (unsigned long i = 0; i < current_sockets.size(); ++i)
    {
        Socket socket = current_sockets.at(i);
        if (socket.getType() == _type)
        {
            index = static_cast<int>(i);
            break;
        }
    }

    // Erase only if found
    if (index > -1)
    {
        current_sockets.erase(current_sockets.begin() + index);
    }
}

void MyCharacter::modifySocketValue(Socket::Type _type, short _value)
{
    for (Socket socket : current_sockets)
    {
        if (socket.getType() == _type)
        {
            // If already in, change value
            socket.setValue(_value);
            return;
        }
    }
}
short MyCharacter::getSocketValue(Socket::Type _type)
{
    for (Socket socket : current_sockets)
    {
        if (socket.getType() == _type)
        {
            return socket.getValue();
        }
    }
    return 0;
}

short MyCharacter::getCurrentSocketsTotalNum()
{
    LimitBreak* limit = template_character->getLimitBreak();
    LimitBreak::Improvements improvements = limit->getUnlockedImprovements(lb_unlocked_nodes);
    return template_character->getStats()->num_sockets + improvements.socket;
}

short MyCharacter::getSocketsTotalNum()
{
    LimitBreak* limit = template_character->getLimitBreak();
    LimitBreak::Improvements improvements = limit->getAllImprovements();
    return template_character->getStats()->num_sockets + improvements.socket;
}

void MyCharacter::addDesiredSocket(Socket::Type _type)
{
    if ( (short)desired_sockets.size() < getSocketsTotalNum())
    {
        bool alreadyIn = false;
        for (Socket::Type type : desired_sockets)
        {
            if (type == _type)
            {
                alreadyIn = true;
                break;
            }
        }

        // Add if not already in
        if (!alreadyIn)
        {
            desired_sockets.push_back(_type);
        }
    }
}

void MyCharacter::removeDesiredSocket(Socket::Type _type)
{
    int index = -1;
    for (unsigned long i = 0; i < desired_sockets.size(); ++i)
    {
        Socket::Type type = desired_sockets.at(i);
        if (type == _type)
        {
            index = static_cast<int>(i);
            break;
        }
    }

    // Erase only if found
    if (index > -1)
    {
        current_sockets.erase(current_sockets.begin() + index);
    }
}

void MyCharacter::changeDesiredSocket(Socket::Type _current, Socket::Type _updated)
{
    for (Socket::Type &type : desired_sockets)
    {
        if (type == _current)
        {
            type = _updated;
            break;
        }
    }
}

std::vector<Socket> MyCharacter::missingSocketPoints()
{
    std::vector<Socket> missingPoints;
    for (Socket::Type type : desired_sockets)
    {
        Socket missingSocket(type, Socket::MAXVALUE);
        for (Socket socket : current_sockets)
        {
            if (socket.getType() == type)
            {
                missingSocket.setValue(Socket::MAXVALUE - socket.getValue());
                break;
            }
        }
        missingPoints.push_back(missingSocket);
    }
    return missingPoints;
}

void MyCharacter::setSkillLevel(short _level)
{
    if (_level <= template_character->getSpecial()->getMaxLevel())
    {
        skill_level = _level;
    }
}

short MyCharacter::getSkillLevel()
{
    return skill_level;
}

void MyCharacter::setLbUnlockedNodes(short _num)
{
    LimitBreak* limit = template_character->getLimitBreak();
    if (_num >= 0 && _num <= (short)limit->getTotalNodes())
    {
        lb_unlocked_nodes = _num;
    }
}

short MyCharacter::getLbUnlockedNodes()
{
    return lb_unlocked_nodes;
}

void MyCharacter::setCC(short _hp, short _atk, short _rcv)
{
    const short MAX_CC = 200;
    if (_hp + _atk + _rcv <= MAX_CC)
    {
        cc_hp = _hp;
        cc_atk = _atk;
        cc_rcv = _rcv;
    }
}

std::vector<short> MyCharacter::getCC()
{
    std::vector<short> cc;
    cc.push_back(cc_hp);
    cc.push_back(cc_atk);
    cc.push_back(cc_rcv);
    return cc;
}

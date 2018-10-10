#include <myCharacter.h>
#include <cmath>

MyCharacter::MyCharacter(Character* _template_character, std::string _nickname) :
        template_character(_template_character),
        nickname(_nickname),
        want_to_finish_level(true),
        want_to_finish_cc(true),
        want_to_finish_skill(true),
        want_to_finish_sockets(true),
        want_to_finish_limit(true),
        level(template_character->getStats()->max_level),
        skill_level(1),
        lb_unlocked_nodes(0),
        training_points(0),
        cc_hp(0),
        cc_atk(0),
        cc_rcv(0)
{
    setNickname(_nickname);
}

void MyCharacter::setNickname(std::string _nickname)
{
    nickname = _nickname;
}

std::string MyCharacter::getNickname()
{
    return nickname;
}

void MyCharacter::setLevel(short _level)
{
    short maxLevel = template_character->getStats()->max_level;
    if (_level > 0 && _level <= maxLevel)
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
    if (static_cast<int>(current_sockets.size()) < getCurrentSocketsTotalNum())
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

std::vector<Socket>& MyCharacter::getSockets()
{
    return current_sockets;
}

void MyCharacter::removeSocket(Socket::Type _type)
{
    int index = -1;
    for (unsigned long i = 0; i < current_sockets.size(); ++i)
    {
        Socket socket = current_sockets[i];
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
    for (Socket& socket : current_sockets)
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
    if ( static_cast<short>(desired_sockets.size()) < getSocketsTotalNum())
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

std::vector<Socket::Type>& MyCharacter::getDesiredSockets()
{
    return desired_sockets;
}

void MyCharacter::removeDesiredSocket(Socket::Type _type)
{
    int index = -1;
    for (unsigned long i = 0; i < desired_sockets.size(); ++i)
    {
        Socket::Type type = desired_sockets[i];
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

void MyCharacter::setPotential(Potential::Type _type, short _value)
{
    bool found = false;
    for (Potential& potential : current_potentials)
    {
        if (potential.getType() == _type)
        {
            potential.setValue(_value);
            found = true;
            break;
        }
    }

    if (!found)
    {
        Potential potential(_type, _value);
        current_potentials.push_back(potential);
    }
}

std::vector<Potential> MyCharacter::getPotential()
{
    return current_potentials;
}

short MyCharacter::getPotential(Potential::Type _type)
{
    for (Potential potential : current_potentials)
    {
        if (potential.getType() == _type)
        {
            return potential.getValue();
        }
    }

    return -1;
}

void MyCharacter::setSkillLevel(short _level)
{
    if (_level > 0 && _level <= template_character->getSpecial()->getMaxLevel())
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


void MyCharacter::setTrainingPoints(int _trainingPoints)
{
    LimitBreak* limit = template_character->getLimitBreak();

    if (_trainingPoints >= 0 && _trainingPoints <= limit->getMaxTrainingPoints())
    {
        training_points = _trainingPoints;
    }

}

int MyCharacter::getTrainingPoints()
{
    return training_points;
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

void MyCharacter::setCC(std::vector<short> _cottons)
{
    if (_cottons.size() == 3)
    {
        setCC(_cottons[0], _cottons[1], _cottons[2]);
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

bool MyCharacter::getWantToFinishLevel()
{
    return want_to_finish_level;
}

void MyCharacter::setWantToFinishLevel(bool _wantToFinish)
{
    want_to_finish_level = _wantToFinish;
}

bool MyCharacter::getWantToFinishCotton()
{
    return want_to_finish_cc;
}

void MyCharacter::setWantToFinishCotton(bool _wantToFinish)
{
    want_to_finish_cc = _wantToFinish;
}

bool MyCharacter::getWantToFinishSockets()
{
    return want_to_finish_sockets;
}

void MyCharacter::setWantToFinishSockets(bool _wantToFinish)
{
    want_to_finish_sockets = _wantToFinish;
}

bool MyCharacter::getWantToFinishSkill()
{
    return want_to_finish_skill;
}

void MyCharacter::setWantToFinishSkill(bool _wantToFinish)
{
    want_to_finish_skill = _wantToFinish;
}

bool MyCharacter::getWantToFinishLimitBreak()
{
    return want_to_finish_limit;
}

void MyCharacter::setWantToFinishLimitBreak(bool _wantToFinish)
{
    want_to_finish_limit = _wantToFinish;
}

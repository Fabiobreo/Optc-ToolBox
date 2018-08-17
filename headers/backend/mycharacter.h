#include <vector>
#include <socket.h>
#include <character.h>

#ifndef MYCHARACTER_HPP
#define MYCHARACTER_HPP

class MyCharacter
{

public:
    explicit MyCharacter(Character* _template_character);

    void setLevel(short _level);
    short getLevel();
    std::vector<int> getStats();

    void addSocket(Socket _socket);
    void removeSocket(Socket::Type _type);
    void modifySocketValue(Socket::Type _type, short _value);
    short getSocketValue(Socket::Type _type);

    short getCurrentSocketsTotalNum();
    short getSocketsTotalNum();

    void addDesiredSocket(Socket::Type _type);
    void removeDesiredSocket(Socket::Type _type);
    void changeDesiredSocket(Socket::Type _current, Socket::Type _updated);
    std::vector<Socket> missingSocketPoints();

    void setSkillLevel(short _level);
    short getSkillLevel();

    void setLbUnlockedNodes(short _num);
    short getLbUnlockedNodes();

    void setCC(short _hp, short _atk, short _rcv);
    std::vector<short> getCC();

private:
    Character* template_character;
    short level = 1;
    std::vector<Socket> current_sockets;
    std::vector<Socket::Type> desired_sockets;
    short skill_level = 1;
    short lb_unlocked_nodes = 0;
    short cc_hp = 0;
    short cc_atk = 0;
    short cc_rcv = 0;
};
#endif //MYCHARACTER_HPP

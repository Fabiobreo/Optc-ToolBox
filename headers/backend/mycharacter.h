#include <vector>
#include <socket.h>
#include <character.h>

#ifndef MYCHARACTER_HPP
#define MYCHARACTER_HPP

class MyCharacter
{

public:

    /**
     * @brief MyCharacter
     * @param _template_character
     * @param _nickname
     */
    explicit MyCharacter(Character* _template_character, std::string _nickname);

    /**
     * @brief setNickname
     * @param _nickname
     */
    void setNickname(std::string _nickname);

    /**
     * @brief getNickname
     * @return
     */
    std::string getNickname();

    /**
     * @brief setLevel
     * @param _level
     */
    void setLevel(short _level);

    /**
     * @brief getLevel
     * @return
     */
    short getLevel();

    /**
     * @brief getStats
     * @return
     */
    std::vector<int> getStats();

    /**
     * @brief addSocket
     * @param _socket
     */
    void addSocket(Socket _socket);

    /**
     * @brief getSockets
     * @return
     */
    std::vector<Socket>& getSockets();

    /**
     * @brief removeSocket
     * @param _type
     */
    void removeSocket(Socket::Type _type);

    /**
     * @brief modifySocketValue
     * @param _type
     * @param _value
     */
    void modifySocketValue(Socket::Type _type, short _value);

    /**
     * @brief getSocketValue
     * @param _type
     * @return
     */
    short getSocketValue(Socket::Type _type);

    /**
     * @brief getCurrentSocketsTotalNum
     * @return
     */
    short getCurrentSocketsTotalNum();

    /**
     * @brief getSocketsTotalNum
     * @return
     */
    short getSocketsTotalNum();

    /**
     * @brief addDesiredSocket
     * @param _type
     */
    void addDesiredSocket(Socket::Type _type);

    /**
     * @brief getDesiredSockets
     * @return
     */
    std::vector<Socket::Type>& getDesiredSockets();

    /**
     * @brief removeDesiredSocket
     * @param _type
     */
    void removeDesiredSocket(Socket::Type _type);

    /**
     * @brief changeDesiredSocket
     * @param _current
     * @param _updated
     */
    void changeDesiredSocket(Socket::Type _current, Socket::Type _updated);

    /**
     * @brief missingSocketPoints
     * @return
     */
    std::vector<Socket> missingSocketPoints();

    /**
     * @brief setPotential
     * @param _type
     * @param _value
     */
    void setPotential(Potential::Type _type, short _value);

    /**
     * @brief getPotential
     * @return
     */
    std::vector<Potential> getPotential();

    /**
     * @brief getPotential
     * @param _type
     * @return
     */
    short getPotential(Potential::Type _type);

    /**
     * @brief setSkillLevel
     * @param _level
     */
    void setSkillLevel(short _level);

    /**
     * @brief getSkillLevel
     * @return
     */
    short getSkillLevel();

    /**
     * @brief setLbUnlockedNodes
     * @param _num
     */
    void setLbUnlockedNodes(short _num);

    /**
     * @brief getLbUnlockedNodes
     * @return
     */
    short getLbUnlockedNodes();

    /**
     * @brief setTrainingPoints
     * @param _trainingPoints
     */
    void setTrainingPoints(int _trainingPoints);

    /**
     * @brief getTrainingPoints
     * @return
     */
    int getTrainingPoints();

    /**
     * @brief setCC
     * @param _hp
     * @param _atk
     * @param _rcv
     */
    void setCC(short _hp, short _atk, short _rcv);

    /**
     * @brief setCC
     * @param cottons
     */
    void setCC(std::vector<short> _cottons);

    /**
     * @brief getCC
     * @return
     */
    std::vector<short> getCC();

    /**
     * @brief getWantToFinish
     * @return
     */
    bool getWantToFinishLevel();

    /**
     * @brief setWantToFinish
     * @param _wantToFinish
     */
    void setWantToFinishLevel(bool _wantToFinish);

    /**
     * @brief getWantToFinish
     * @return
     */
    bool getWantToFinishCotton();

    /**
     * @brief setWantToFinish
     * @param _wantToFinish
     */
    void setWantToFinishCotton(bool _wantToFinish);

    /**
     * @brief getWantToFinish
     * @return
     */
    bool getWantToFinishSockets();

    /**
     * @brief setWantToFinish
     * @param _wantToFinish
     */
    void setWantToFinishSockets(bool _wantToFinish);

    /**
     * @brief getWantToFinish
     * @return
     */
    bool getWantToFinishSkill();

    /**
     * @brief setWantToFinish
     * @param _wantToFinish
     */
    void setWantToFinishSkill(bool _wantToFinish);

    /**
     * @brief getWantToFinish
     * @return
     */
    bool getWantToFinishLimitBreak();

    /**
     * @brief setWantToFinish
     * @param _wantToFinish
     */
    void setWantToFinishLimitBreak(bool _wantToFinish);

private:

    Character* template_character;              ///< The character of reference.
    std::string nickname;                       ///< The nickname given to this character.
    bool want_to_finish_level;                  ///< If you want to complete this character's level.
    bool want_to_finish_cc;                     ///< If you want to complete this character's cottons.
    bool want_to_finish_skill;                  ///< If you want to complete this character's skill.
    bool want_to_finish_sockets;                ///< If you want to complete this character's sockets.
    bool want_to_finish_limit;                  ///< If you want to complete this character's limit break.
    short level;                                ///< The current level of the character.
    std::vector<Socket> current_sockets;        ///< The current sockets of the character.
    std::vector<Socket::Type> desired_sockets;  ///< The desired sockets for this character.
    std::vector<Potential> current_potentials;  ///< The current potentials of this character.
    short skill_level;                          ///< The current skill level.
    short lb_unlocked_nodes;                    ///< The currently unlocked limit break nodes.
    int training_points;                        ///< The current training points.
    short cc_hp;                                ///< The hp cotton candy of this character.
    short cc_atk;                               ///< The atk cotton candy of this character.
    short cc_rcv;                               ///< The rcv cotton candy of this character.
};
#endif //MYCHARACTER_HPP

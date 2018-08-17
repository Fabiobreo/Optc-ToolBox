#ifndef LIMITBREAK_HPP
#define LIMITBREAK_HPP

#include <potential.h>
#include <stats.h>
#include <vector>
#include <captain.h>
#include <sailor.h>

class LimitBreak
{
public:

    enum class NodeType
    {
        STATS, CAPTAIN, SAILOR, CD, POTENTIAL, SOCKET, None
    };

    class Improvements
    {
    public:
        short hp = 0;
        short atk = 0;
        short rcv = 0;
        short cd = 0;
        short socket = 0;
        bool new_captain = false;
        short new_sailor = 0;
        std::vector<Potential*> potentials;
    };

    LimitBreak() = default;
    void addNode(NodeType _type);
    void addNode(NodeType _type, Sailor _sailor);
    void addNode(NodeType _type, Captain _captain);
    void addNode(NodeType _type, Stats::Type _stats, short _value);
    void addNode(NodeType _type, Potential::Type _potential, short _value);
    void addNode(NodeType _type, short _value);

    //TODO Potential ability con valori
    Improvements getNodeImprovements(short _value);
    Improvements getUnlockedImprovements(unsigned long _value);
    Improvements getAllImprovements();
    unsigned long getTotalNodes() const;

    bool hasNewCaptainAbilities();
    std::vector<Captain> getNewCaptainAbilities();

    bool hasNewSailorAbilities();
    std::vector<Sailor> getNewSailorAbilities();

private:

    class Node
    {
    public:
        Potential::Type potential = Potential::Type::None;
        Stats::Type stats = Stats::Type::None;
        short value = 0;
        NodeType type = NodeType::None;
    };

    std::vector<Node> nodes;
    std::vector<Captain> captainAbilities;
    std::vector<Sailor> sailorAbilities;
    std::vector<Potential> potentialAbilities;
};
#endif //LIMITBREAK_HPP

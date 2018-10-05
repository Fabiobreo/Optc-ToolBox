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

    /**
     * @brief NodeType indicated the possible things that a limit break node can unlock.
     */
    enum class NodeType
    {
        STATS, CAPTAIN, SAILOR, CD, POTENTIAL, SOCKET, None
    };

    /**
     * @brief The Improvements class is a summary of the unlockable things in the limit break tree.
     */
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

    /**
     * @brief Void Constructor.
     */
    LimitBreak() = default;

    /**
     * @brief Add a generic node to the limit break.
     * @param _type: the type of the node.
     */
    void addNode(NodeType _type);

    /**
     * @brief Add a sailor node to the limit break.
     * @param _type: the type of the node.
     * @param _sailor: the corresponding sailor.
     */
    void addNode(NodeType _type, Sailor _sailor);

    /**
     * @brief Add a captain node to the limit break.
     * @param _type: the type of the node.
     * @param _captain: the corresponding captain.
     */
    void addNode(NodeType _type, Captain _captain);

    /**
     * @brief Add a stat node to the limit break.
     * @param _type: the type of the node.
     * @param _stats: the corresponding stat.
     * @param _value: the value of the stat.
     */
    void addNode(NodeType _type, Stats::Type _stats, short _value);

    /**
     * @brief Add a potential node to the limit break.
     * @param _type: the type of the node.
     * @param _potential: the correspongin potential.
     * @param _value: currently not used.
     */
    void addNode(NodeType _type, Potential::Type _potential, short _value);

    /**
     * @brief Add a generic node, with value to the limit break.
     * @param _type: the type of the node.
     * @param _value: the value of the node.
     */
    void addNode(NodeType _type, short _value);

    /**
     * @brief Get the improvements of the _value node.
     * @param _value: the node that we want to check.
     * @return the improvements of the _value node.
     */
    Improvements getNodeImprovements(short _value);

    /**
     * @brief Get the improvements of this limit break until the _value node.
     * @param _value: the last unlocked node.
     * @return a summary of all the unlocked improvements of this limit break.
     */
    Improvements getUnlockedImprovements(unsigned long _value);

    /**
     * @brief Get all the unlockable improvements with this limit break.
     * @return a summary of all the improvements of this limit break.
     */
    Improvements getAllImprovements();

    /**
     * @brief Get the total nodes for this limit break.
     * @return the number of nodes of the limit break.
     */
    unsigned long getTotalNodes() const;

    /**
     * @brief Check if this limit break unlocks new captain abilities.
     * @return true if the limit break unlocks new captain abilities.
     */
    bool hasNewCaptainAbilities();

    /**
     * @brief Get the new captain abilities unlockable with this limit break.
     * @return a vector with the new captain abilities.
     */
    std::vector<Captain> getNewCaptainAbilities();

    /**
     * @brief Check if this limit break unlocks new sailor abilities.
     * @return true if the limit break unlocks new sailor abilities.
     */
    bool hasNewSailorAbilities();

    /**
     * @brief Get the new sailor abilities unlockable with this limit break.
     * @return a vector with the new sailor abilities.
     */
    std::vector<Sailor> getNewSailorAbilities();

    /**
     * @brief Get the maximum training points for this limit break. 2M for generic characters, 3M for TM characters, 5M for legends.
     * @return the maximum training points.
     */
    int getMaxTrainingPoints();

private:

    /**
     * @brief The Node class represents a node in the limit break tree.
     */
    class Node
    {
    public:
        Potential::Type potential = Potential::Type::None;
        Stats::Type stats = Stats::Type::None;
        short value = 0;
        NodeType type = NodeType::None;
    };

    std::vector<Node> nodes;                    ///< The nodes of the limit break tree.
    std::vector<Captain> captainAbilities;      ///< The captain abilities unlockable in this limit break.
    std::vector<Sailor> sailorAbilities;        ///< The sailor abilities unlockable in this limit break.
    std::vector<Potential> potentialAbilities;  ///< The potential abilities unlockable in this limit break.
};

#endif //LIMITBREAK_HPP

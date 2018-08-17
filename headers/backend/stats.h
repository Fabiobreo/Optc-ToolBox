/**
 * \class Stats
 * \brief These are statistics that are useful to a character.
 * This class is a container of all those stats that a character has.
 * \author Fabio Brea
 * \version $Revision: 0.1 $
 * \date $Date: 2018/04/30 18:00:00 $
 */

#ifndef STATS_HPP
#define STATS_HPP

class Stats
{
public:

    /// Create void stats
    Stats();

    /**
     * \brief The stats type
     */
    enum class Type
    {
        HP, ATK, RCV, STARS, COST, COMBO, SOCKETS, LEVEL, EXP, None
    };

    short stars;                ///< The rarity of a character
    bool plus;                  ///< If is superevolved
    short cost;                 ///< How much it costs to have in a team
    short combo;                ///< Number of hits
    short num_sockets;          ///< Total number of sockets
    short max_level;            ///< Max level
    unsigned long exp_to_max;   ///< Exp needed to max level
    int hp_min;                 ///< HP at level 1
    int atk_min;                ///< ATK at level 1
    int rcv_min;                ///< RCV at level 1
    int hp_max;                 ///< HP at Max Level
    int atk_max;                ///< ATK at Max Level
    int rcv_max;                ///< RCV at Max Level
    double hp_growth;         ///< The hp growth rate of the character
    double atk_growth;         ///< The atk growth rate of the character
    double rcv_growth;         ///< The rcv growth rate of the character

};

#endif //STATS_HPP

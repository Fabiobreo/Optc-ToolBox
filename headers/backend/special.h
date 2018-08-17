#ifndef SPECIAL_HPP
#define SPECIAL_HPP

#include <iostream>
#include <vector>


class Special
{
public:
    Special();

    /**
     * @brief Set the description at _num to _description. If num > description size, add empty descriptions.
     * @param _description: the description to add.
     * @param _num: the number of the description, the higher the number, the highest cooldown.
     */
    void setDescription(const std::string &_description, unsigned long _num);

    /**
     * @brief Add a description to the character.
     * @param _description: the description to add.
     */
    void addDescription(std::string _description);

    /**
     * @brief Get the descriptions for the character
     * @return a vector of description for the character
     */
    std::vector<std::string> getDescription() const;

    /**
     * @brief Get the description of the _num stage. Empty if _num is invalid.
     * @param _num: the stage to return.
     * @return the description of the _num stage.
     */
    std::string getStage(unsigned long _num);

    /**
     * @brief Check if the special has multiple stages.
     * @return true is the special has multiple stages.
     */
    bool hasMultipleStages();

    /**
     * @brief Return the number of stages of the special.
     * @return the number of stages of the special.
     */
    unsigned long getNumberOfStages();

    /**
     * @brief Set the offset _value from the cooldown of the intermediate stage to the maximum cooldown.
     * @param _num: the stage to set
     * @param _value: the offset to set.
     */
    void setStageOffset(unsigned long _num, short _value);

    void addOffset(short _value);

    short getStageOffset(unsigned long _num);

    /**
     * @brief Set the special name.
     * @param _name: the name of the special.
     */
    void setName(std::string _name);

    /**
     * @brief Get the special name.
     * @return the name of the special.
     */
    std::string getName();

    /**
     * @brief Set the value of the special without skillups.
     * @param _special_base: the base value of the special.
     */
    void setBase(short _special_base);

    /**
     * @brief Get the value of the special without skillups.
     * @return the value of the special without skillups.
     */
    short getBase() const;

    /**
     * @brief Set the maximum level of the special.
     * @param _max_level: the maximum level of the special.
     */
    void setMaxLevel(short _max_level);

    /**
     * @brief Get the maximum level of the special.
     * @return the maximum level of the special.
     */
    short getMaxLevel() const;

    /**
     * @brief Set the cd with maxed skillups.
     * @param _max_cd: the cooldown with maxed skillups.
     */
    void setMaxedCd(short _max_cd);

    /**
     * @brief Get the cd with maxed skillups.
     * @return the cd with maxed skillups.
     */
    short getMaxedCd() const;

private:
    std::string name;                       ///< The name of the special
    std::vector<std::string> description;   ///< The descriptions of the special (possible multistage)
    std::vector<short> offsets;             ///< Offset between stages cd
    /*
     * Esempio: Zoro STR
     * Stage 1 (17 → 11 turns)
     *   Stage 2 (21 → 15 turns)
     *   Stage 3 (24 → 18 turns)
     *   Stage 1: offset 7
     *   Stage 2: offset 3
     *   Stage 3: offset 0
     */
    short base = -1;                        ///< The cooldown without level ups.
    short max_level = -1;                   ///< Max level of the special.
};

#endif //SPECIAL_HPP

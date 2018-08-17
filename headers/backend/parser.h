#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <enums.h>
#include <algorithm>
#include <character.h>
#include <tools.h>
#include <mycharacter.h>

#ifndef PARSER_HPP
#define PARSER_HPP

class Parser
{
public:
    /**
     * @brief Parser
     * @param _dataPath
     */
    explicit Parser(const std::string& _dataPath = "/../resources/details/");

    /**
     * @brief getCharacters
     * @return
     */
    std::vector<Character*> getCharacters();

    std::map<int, MyCharacter*> getOwnedCharacters(int id);

    /**
     * @brief load
     * @return
     */
    bool load();

private:

    /**
     * @brief loadCharacters
     * @return
     */
    bool loadCharacters();

    /**
     * @brief loadCooldowns
     * @return
     */
    bool loadCooldowns();

    /**
     * @brief loadEvolutions
     * @return
     */
    bool loadEvolutions();

    /**
     * @brief loadDetails
     * @return
     */
    bool loadDetails();

    /**
     * @brief loadLimitBreak
     * @param _characterId
     * @param _limitBreak
     * @return
     */
    bool loadLimitBreak(unsigned long _characterId, std::string _limitBreak);

    /**
     * @brief loadCaptain
     * @param _characterId
     * @param _captain
     * @return
     */
    bool loadCaptain(unsigned long _characterId, std::vector<std::string> _captain);

    /**
     * @brief loadSailor
     * @param _characterId
     * @param _sailor
     * @return
     */
    bool loadSailor(unsigned long _characterId, std::vector<std::string> _sailor);

    /**
     * @brief loadSpecial
     * @param _characterId
     * @param _special
     * @return
     */
    bool loadSpecial(unsigned long _characterId, std::vector<std::string> _special);

    std::vector<Character*> characters;
    std::string dataPath;
    std::string charactersFile = "units.txt";
    std::string cooldownFile = "cooldowns.txt";
    std::string evolutionFile = "evolutions.txt";
    std::string detailFile = "details.txt";

};
#endif //PARSER_HPP

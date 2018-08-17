#include <parser.h>
#include <algorithm>
#include <cctype>
#include <json.h>

Parser::Parser(const std::string& _dataPath) :
dataPath(_dataPath)
{

}

bool Parser::load()
{
    bool success = loadCharacters();
    success = success && loadCooldowns();
    success = success && loadEvolutions();
    success = success && loadDetails();
    return success;
}

bool Parser::loadCharacters()
{
    bool success = false;
    std::ifstream inputFile(dataPath + charactersFile);
    std::vector<char> charToRemove = {' ', '[', ']', '\\', '\"'};

    if (inputFile.is_open())
    {
        std::string line;
        short id = 0;
        while (std::getline(inputFile, line))
        {
            id++;
            size_t tmp_index = line.find('\"');
            std::string tmp = line.substr(tmp_index + 1);
            std::string leftToParse = line.substr(1);

            std::string name = Tools::parseBetween(leftToParse, "\"", "\", [");
            name.erase(std::remove(name.begin(), name.end(), '\\'), name.end());
            if (!name.empty())
            {
                tmp = tmp.substr(tmp.find("\", [") + 1);

                /* Parsing type */
                std::vector<std::string> types;
                Tools::split(Tools::parseBetween(leftToParse, "[\"", "\"],"), ',', types, &charToRemove);
                std::vector<Type> character_types;
                for (std::string type: types)
                {
                    Type character_type = stringToType(type);
                    character_types.push_back(character_type);
                }

                /* Parsing classes */
                std::vector<std::string> classes;
                Tools::split(Tools::parseBetween(leftToParse, "[\"", "\"],"), ',', classes, &charToRemove);
                Class first_class = stringToClass(classes.at(0));
                Class second_class = classes.size() > 1 ? stringToClass(classes.at(1)) : Class::None;

                /* Parsing stats */
                Stats character_stats{};
                std::string starsString = Tools::removeString(Tools::parseBetween(leftToParse, ","), " '\"");
                std::string stars = starsString.substr(0, 1);
                character_stats.stars = static_cast<short>(std::stoi(stars));
                if (starsString.length() > 1)
                {
                    character_stats.plus = true;
                }

                std::string tmp = Tools::removeString(Tools::parseBetween(leftToParse, ","), " \"");
                character_stats.cost        = static_cast<short>(std::stoi(tmp != "null"? tmp : "0"));
                tmp = Tools::removeString(Tools::parseBetween(leftToParse, ","), " \"");
                character_stats.combo       = static_cast<short>(std::stoi(tmp != "null"? tmp : "0"));
                tmp = Tools::removeString(Tools::parseBetween(leftToParse, ","), " \"");
                character_stats.num_sockets = static_cast<short>(std::stoi(tmp != "null"? tmp : "0"));
                tmp = Tools::removeString(Tools::parseBetween(leftToParse, ","), " \"");
                character_stats.max_level   = static_cast<short>(std::stoi(tmp != "null"? tmp : "0"));
                tmp = Tools::removeString(Tools::parseBetween(leftToParse, ","), " \"");
                character_stats.exp_to_max  = std::stoul(tmp != "null"? tmp : "0L");
                tmp = Tools::removeString(Tools::parseBetween(leftToParse, ","), " \"");
                character_stats.hp_min      = std::stoi(tmp != "null"? tmp : "0");
                tmp = Tools::removeString(Tools::parseBetween(leftToParse, ","), " \"");
                character_stats.atk_min     = std::stoi(tmp != "null"? tmp : "0");
                tmp = Tools::removeString(Tools::parseBetween(leftToParse, ","), " \"");
                character_stats.rcv_min     = std::stoi(tmp != "null"? tmp : "0");
                tmp = Tools::removeString(Tools::parseBetween(leftToParse, ","), " \"");
                character_stats.hp_max      = std::stoi(tmp != "null"? tmp : "0");
                tmp = Tools::removeString(Tools::parseBetween(leftToParse, ","), " \"");
                character_stats.atk_max     = std::stoi(tmp != "null"? tmp : "0");
                tmp = Tools::removeString(Tools::parseBetween(leftToParse, ","), " \"");
                character_stats.rcv_max     = std::stoi(tmp != "null"? tmp : "0");

                std::vector<std::string> growth_rate;
                if (leftToParse.find('[') != std::string::npos)
                {
                    Tools::split(Tools::parseBalanced(leftToParse, '[', ']'), ',', growth_rate, &charToRemove);
                }
                else
                {
                    tmp = Tools::removeString(Tools::parseBalanced(leftToParse, ','), " \"]");
                    growth_rate.push_back(tmp);
                }
                if (growth_rate.size() == 1)
                {
                    character_stats.hp_growth = static_cast<double>(std::stof(growth_rate.at(0) != "null" ? growth_rate.at(0) : "1"));
                    character_stats.atk_growth = character_stats.hp_growth;
                    character_stats.rcv_growth = character_stats.hp_growth;
                }
                else
                {
                    character_stats.hp_growth = static_cast<double>(std::stof(growth_rate.at(0)));
                    character_stats.atk_growth = static_cast<double>(std::stof(growth_rate.at(1)));
                    character_stats.rcv_growth = static_cast<double>(std::stof(growth_rate.at(2)));
                }
                short dualId = -1;
                if (!leftToParse.empty())
                {
                    tmp = Tools::removeString(leftToParse, " \"],");
                    if (!tmp.empty())
                    {
                        dualId = static_cast<short>(std::stoi(tmp));
                    }
                }

                /* Create character*/
                Character* character = new Character(id, name, character_types, first_class, second_class);
                character->setStats(&character_stats);
                characters.push_back(character);
                if (dualId != -1)
                {
                    characters.at(static_cast<unsigned int>(dualId - 1))->addDualUnit(character);
                }
            }
            else
            {
                std::vector<Type> types = {Type::None};
                Character* character = new Character(id, name, types, Class::None);
                characters.push_back(character);
            }
        }
        success = true;
    }
    inputFile.close();
    return success;
}

bool Parser::loadCooldowns()
{
    bool success = false;
    std::ifstream cdFile(dataPath + cooldownFile);
    std::vector<char> charToRemove = {' ', '[', ']', '\\', '\"'};
    if (cdFile.is_open())
    {
        std::string line;
        unsigned long id = 0;
        while (std::getline(cdFile, line))
        {
            std::vector<std::string> elements;
            Tools::split(line, ',', elements, &charToRemove);
            if (elements.at(0) != "null")
            {
                Special special;
                auto base_cd = static_cast<short>(std::stoi(elements.at(0)));
                special.setBase(base_cd);
                if (elements.size() > 1)
                {
                    auto max_cd = static_cast<short>(std::stoi(elements.at(1)));
                    special.setMaxedCd(max_cd);
                }
                characters.at(id)->setSpecial(&special);
            }
            id++;
        }
        success = true;
    }
    cdFile.close();
    return success;
}

bool Parser::loadEvolutions()
{
    bool success = false;
    std::ifstream evoFile(dataPath + evolutionFile);
    std::vector<char> charToRemove = {' ', '[', ']', '\\', '\"'};
    if (evoFile.is_open())
    {
        std::string line;
        while (std::getline(evoFile, line))
        {
            // Now we have at least three other rows
            line = line.substr(0, line.find(':'));
            line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
            auto id = static_cast<unsigned long>(std::atoi(line.c_str()));

            // Evolution line
            std::getline(evoFile, line);
            line = line.substr(line.find(':') + 1);
            std::vector<std::string> evos_str;
            Tools::split(line, ',', evos_str, &charToRemove);
            std::vector<unsigned long> evos;
            for (const auto &evo : evos_str)
            {
                evos.push_back(static_cast<unsigned long>(std::atoi(evo.c_str())));
            }

            //Evolvers line
            std::getline(evoFile, line);
            line = line.substr(line.find(':') + 1);
            unsigned long startIndex = 0L;
            unsigned long endIndex = 1000L;
            std::vector<std::vector<unsigned long>> evolvers;
            for (unsigned long i = 0; i < line.length(); ++i)
            {
                char c = line.at(i);
                if (c == '[')
                {
                    startIndex = i;
                    continue;
                }

                if (c == ']' && endIndex != startIndex)
                {
                    endIndex = i;
                    std::string evos_string = line.substr(startIndex, endIndex - startIndex + 1);
                    std::vector<std::string> evos_vector;
                    Tools::split(evos_string, ',', evos_vector, &charToRemove);
                    std::vector<unsigned long> this_evolvers;
                    for (const auto & evos_vec : evos_vector)
                    {
                        if (evos_vec.find('s') == std::string::npos && !evos_vec.empty())
                        {
                            this_evolvers.push_back(static_cast<unsigned long>(std::atoi(evos_vec.c_str())));
                        }
                    }
                    evolvers.push_back(this_evolvers);
                    startIndex = i;
                }
            }
            for (unsigned long k = 0; k < evos.size(); k++)
            {
                auto evo = evos.at(k);
                Character* character_evolution = characters.at(evo - 1);
                std::vector<Character*> character_evolvers;
                for (auto evolver : evolvers.at(k))
                {
                    Character* evolver_pointer = characters.at(evolver - 1);
                    character_evolvers.push_back(evolver_pointer);
                }
                characters.at(id - 1)->setEvolution(character_evolution, character_evolvers);
            }

            //Closing line
            std::getline(evoFile, line);
        }
        success = true;
    }
    return success;
}

std::vector<Character*> Parser::getCharacters()
{
    return characters;
}

bool Parser::loadDetails()
{
    bool success = true;
    std::ifstream detailsFile(dataPath + detailFile);
    if (detailsFile.is_open())
    {
        std::string characterDetails;
        std::string line;
        while (std::getline(detailsFile, line))
        {
            characterDetails = line + "\r";
            unsigned long numCurly = 0;
            if (line.find('{') != std::string::npos)
            {
                numCurly++;
            }

            while (numCurly > 0)
            {
                std::getline(detailsFile, line);
                if (line.find('{') != std::string::npos)
                {
                    numCurly++;
                }
                if (line.find('}') != std::string::npos)
                {
                    numCurly--;
                }
                characterDetails += line + "\r";
            }

            std::stringstream detailsStream(characterDetails);
            unsigned long id = 0;
            std::string limitDetail;
            while (std::getline(detailsStream, line, '\r'))
            {
                if (line.empty())
                {
                    continue;
                }
                std::vector<std::string> elements;
                Tools::split(line, ':', elements);
                elements.at(0).erase(std::remove(elements.at(0).begin(), elements.at(0).end(), ' '), elements.at(0).end());
                if (Tools::is_number(elements.at(0)))
                {
                    id = std::stoul(elements.at(0));
                }
                else if (elements.at(0) == "captain")
                {
                    std::vector<std::string> captain_string;
                    std::string cap = "";
                    for (unsigned long ind = 1; ind < elements.size(); ++ind)
                    {
                        cap += elements.at(ind);
                    }
                    captain_string.push_back(cap);
                    if (cap.find('{') != std::string::npos)
                    {
                        while (true)
                        {
                            std::getline(detailsStream, line, '\r');
                            captain_string.push_back(line);
                            if (line.find('}') != std::string::npos)
                            {
                                break;
                            }
                        }
                    }
                    success = success && loadCaptain(id, captain_string);
                }
                else if (elements.at(0) == "action")
                {
                    std::string action_description = elements.at(1).substr(elements.at(1).find("\"") + 1);
                    action_description = Tools::removeString(action_description.substr(0, action_description.find_last_of("\"")), "\\");
                    Captain cap_action(action_description);
                    characters.at(id - 1)->setCaptainAction(&cap_action);
                }
                else if (elements.at(0) == "special")
                {
                    std::vector<std::string> special_string;
                    special_string.push_back(elements.at(1));
                    if (elements.at(1).find('[') != std::string::npos && elements.at(1).find(']') == std::string::npos)
                    {
                        int numBrackets = 1;
                        while (true)
                        {
                            std::getline(detailsStream, line, '\r');
                            special_string.push_back(line);
                            if (line.find('[') != std::string::npos)
                            {
                                numBrackets++;
                            }
                            if (line.find(']') != std::string::npos)
                            {
                                numBrackets--;
                                if (numBrackets == 0)
                                {
                                    break;
                                }
                            }
                        }
                    }
                    success = success && loadSpecial(id, special_string);
                }
                else if (elements.at(0) == "specialName")
                {
                    std::string specialName = elements.at(1).substr(elements.at(1).find('\"') + 1);
                    specialName = specialName.substr(0, specialName.find_last_of('\"'));
                    characters.at(id - 1)->getSpecial()->setName(specialName);
                }
                else if (elements.at(0) == "swap")
                {
                    std::string swap = elements.at(1).substr(elements.at(1).find('\"') + 1);
                    swap = swap.substr(0, swap.find_last_of('\"'));
                    characters.at(id - 1)->setSwapDescription(swap);
                }
                else if (elements.at(0) == "sailor")
                {
                    std::vector<std::string> sailor_string;
                    sailor_string.push_back(elements.at(1));
                    if (elements.at(1).find('{') != std::string::npos)
                    {
                        while (true)
                        {
                            std::getline(detailsStream, line, '\r');
                            sailor_string.push_back(line);
                            if (line.find('}') != std::string::npos)
                            {
                                break;
                            }
                        }
                    }
                    success = success && loadSailor(id, sailor_string);
                }
                else if (elements.at(0) == "limit")
                {
                    limitDetail = line + "\r";
                    unsigned long numBrackets = 0;
                    if (line.find('[') != std::string::npos)
                    {
                        numBrackets++;
                    }

                    while (numBrackets > 0)
                    {
                        std::getline(detailsStream, line, '\r');
                        if (line.find('[') != std::string::npos)
                        {
                            numBrackets++;
                        }
                        if (line.find(']') != std::string::npos)
                        {
                            numBrackets--;
                        }
                        limitDetail += line + "\r";
                    }
                    std::getline(detailsStream, line, '\r');
                    if (line.find("potential") != std::string::npos)
                    {
                        numBrackets++;
                        while (numBrackets > 0)
                        {
                            std::getline(detailsStream, line, '\r');
                            if (line.find('[') != std::string::npos)
                            {
                                numBrackets++;
                            }
                            if (line.find(']') != std::string::npos)
                            {
                                numBrackets--;
                            }
                            limitDetail += line;
                        }
                    }
                    success = true;
                }
                success = true;
            }

            if (!limitDetail.empty())
            {
                success = success && loadLimitBreak(id, limitDetail);
            }
        }

        success = true;
        //Parsa il resto
    }
    return success;
}

bool Parser::loadLimitBreak(unsigned long _characterId, std::string _limitBreak)
{
    if (!_limitBreak.empty() && _limitBreak.find("\"This character has a Limit Break Tree\"") == std::string::npos && _limitBreak.find("Not Translated") == std::string::npos)
    {
        LimitBreak limitBreak;
        std::stringstream detailsStream(_limitBreak);
        std::string line;
        bool limit = false;
        unsigned long numBrackets = 0;
        while (std::getline(detailsStream, line, '\r'))
        {
            if (line.find("limit") != std::string::npos)
            {
                limit = true;
                numBrackets++;
            }

            while(limit && numBrackets > 0)
            {
                std::getline(detailsStream, line, '\r');
                if (line.empty())
                {
                    continue;
                }
                if (line.find('[') != std::string::npos)
                {
                    numBrackets++;
                }
                if (line.find(']') != std::string::npos)
                {
                    numBrackets--;
                }
                if (numBrackets == 0)
                {
                    limit = false;
                    break;
                }

                std::string descriptionString = "\"description\":";
                std::string quotes = "\"";
                line = line.substr(line.find(descriptionString) + descriptionString.length());
                line = line.substr(line.find(quotes) + quotes.length());
                line = line.substr(0, line.find_last_of('\"'));

                if (line.find("Boosts base") != std::string::npos && line.find("Sailor") == std::string::npos)
                {
                    unsigned long place = line.find("by") + 2;
                    std::string stringValue = Tools::removeString(line.substr(place), " ");
                    short value = static_cast<short>(std::stoi(Tools::is_number(stringValue) ? stringValue : "0"));
                    if (line.find("HP") != std::string::npos)
                    {
                        limitBreak.addNode(LimitBreak::NodeType::STATS, Stats::Type::HP, value);
                    }
                    else if (line.find("ATK") != std::string::npos)
                    {
                        limitBreak.addNode(LimitBreak::NodeType::STATS, Stats::Type::ATK, value);
                    }
                    else if (line.find("RCV") != std::string::npos)
                    {
                        limitBreak.addNode(LimitBreak::NodeType::STATS, Stats::Type::RCV, value);
                    }
                }
                else if (line.find("additional Socket") != std::string::npos)
                {
                    std::string stringa = "Acquire ";
                    unsigned long place = line.find(stringa) + stringa.length();
                    line = line.substr(place);
                    line = line.substr(0, line.find(' '));
                    auto value = static_cast<short>(std::atoi(line.c_str()));
                    limitBreak.addNode(LimitBreak::NodeType::SOCKET, value);
                }
                else if (line.find("Special Cooldown") != std::string::npos)
                {
                    std::string stringa = "by ";
                    unsigned long place = line.find(stringa) + stringa.length();
                    line = line.substr(place);
                    line = line.substr(0, line.find(' '));
                    auto value = static_cast<short>(std::atoi(line.c_str()));
                    limitBreak.addNode(LimitBreak::NodeType::CD, value);
                }
                else if (line.find("Captain Ability") != std::string::npos)
                {
                    line = Tools::removeString(line.substr(line.find(':') + 2), "\\");
                    Captain cap(line);
                    limitBreak.addNode(LimitBreak::NodeType::CAPTAIN, cap);
                }
                else if (line.find("Sailor Ability") != std::string::npos)
                {
                    line = Tools::removeString(line.substr(line.find(':') + 2), "\\");
                    Sailor sail(line);
                    limitBreak.addNode(LimitBreak::NodeType::SAILOR, sail);
                }
                else if (line.find("Potential") != std::string::npos)
                {
                    //TODO mancano da fare i dati
                    line = line.substr(line.find(':') + 2);
                    if (line.find("Enrage") != std::string::npos)
                    {
                        limitBreak.addNode(LimitBreak::NodeType::POTENTIAL, Potential::Type::Enrage, 1);
                    }
                    else if (line.find("No Healing") != std::string::npos)
                    {
                        limitBreak.addNode(LimitBreak::NodeType::POTENTIAL, Potential::Type::NoHealing, 1);
                    }
                    else if (line.find("Critical Hit") != std::string::npos)
                    {
                        limitBreak.addNode(LimitBreak::NodeType::POTENTIAL, Potential::Type::CriticalHit, 1);
                    }
                    else if (line.find("Slot Bind") != std::string::npos)
                    {
                        limitBreak.addNode(LimitBreak::NodeType::POTENTIAL, Potential::Type::SlotBind, 1);
                    }
                    else if (line.find("Barrier Penetration") != std::string::npos)
                    {
                        limitBreak.addNode(LimitBreak::NodeType::POTENTIAL, Potential::Type::BarrierPenetration, 1);
                    }
                    else if (line.find("Pinch Healing") != std::string::npos)
                    {
                        limitBreak.addNode(LimitBreak::NodeType::POTENTIAL, Potential::Type::PinchHealing, 1);
                    }
                    else if (line.find("Damage Reduction") != std::string::npos)
                    {
                        //TODO manca da fare i tipi
                        if (line.find("STR") != std::string::npos)
                        {
                            limitBreak.addNode(LimitBreak::NodeType::POTENTIAL, Potential::Type::DMRSTR, 1);
                        }
                        else if (line.find("QCK") != std::string::npos)
                        {
                            limitBreak.addNode(LimitBreak::NodeType::POTENTIAL, Potential::Type::DMRQCK, 1);
                        }
                        else if (line.find("DEX") != std::string::npos)
                        {
                            limitBreak.addNode(LimitBreak::NodeType::POTENTIAL, Potential::Type::DMRDEX, 1);
                        }
                        else if (line.find("PSY") != std::string::npos)
                        {
                            limitBreak.addNode(LimitBreak::NodeType::POTENTIAL, Potential::Type::DMRPSY, 1);
                        }
                        else if (line.find("INT") != std::string::npos)
                        {
                            limitBreak.addNode(LimitBreak::NodeType::POTENTIAL, Potential::Type::DMRINT, 1);
                        }
                    }
                    else if (line.find("Cooldown Reduction") != std::string::npos)
                    {
                        limitBreak.addNode(LimitBreak::NodeType::POTENTIAL, Potential::Type::CDR, 1);
                    }
                }
            }

            // Get potential descriptions
            std::getline(detailsStream, line, '\r');
            for (Potential* potential : limitBreak.getAllImprovements().potentials)
            {
                std::string parsed = Tools::parseBalanced(line, '[', ']');
                if (parsed.find("STR") != std::string::npos ||
                        parsed.find("QCK") != std::string::npos ||
                        parsed.find("DEX") != std::string::npos ||
                        parsed.find("PSY") != std::string::npos ||
                        parsed.find("INT") != std::string::npos)
                {
                    parsed = Tools::parseBalanced(line, '[', ']');
                }
                for (int i = 0; i < 5; ++i)
                {
                    std::string description = Tools::parseBetween(parsed, "\"");
                    description = description.substr(description.find(":") + 2);
                    parsed = parsed.substr(1);
                    potential->addDescription(description);
                }
            }
        }
        Character* limitBrokeCharacter = characters.at(_characterId - 1);
        limitBrokeCharacter->setLimitBreak(&limitBreak);
        if (limitBrokeCharacter->hasDual())
        {
            std::vector<Character*> dual_units = limitBrokeCharacter->getDualUnits();
            dual_units.at(0)->setLimitBreak(&limitBreak);
            dual_units.at(1)->setLimitBreak(&limitBreak);
        }
    }
    return true;
}

bool Parser::loadCaptain(unsigned long _characterId, std::vector<std::string> _captain)
{
    std::vector<Captain> captains;
    std::vector<char> charToRemove = {'{', '}'};
    for (std::string cap_string : _captain)
    {
        std::vector<std::string> element;
        Tools::split(cap_string, ':', element, &charToRemove);
        if (!element.empty())
        {
            std::vector<char> otherChars = {' ', ','};
            std::vector<std::string> emptyCheck;
            Tools::split(element.at(0), ':', emptyCheck, &otherChars);
            if (!emptyCheck.empty())
            {
                std::string cap_description = element.at(element.size() - 1);
                cap_description = cap_description.substr(cap_description.find('\"') + 1);
                cap_description = Tools::removeString(cap_description.substr(0, cap_description.find_last_of('\"')), "\\");
                Captain cap(cap_description);
                captains.push_back(cap);
            }
        }
    }
    if (captains.empty())
    {
        return false;
    }
    else
    {
        if (characters.at(_characterId - 1)->hasDual())
        {
            std::vector<Character*> dual_units = characters.at(_characterId - 1)->getDualUnits();
            dual_units.at(0)->setCaptain(&captains.at(0));
            dual_units.at(1)->setCaptain(&captains.at(1));
            characters.at(_characterId - 1)->setCaptain(&captains.at(2));
        }
        else
        {
            characters.at(_characterId - 1)->setCaptain(&captains.at(0));
        }
        return true;
    }
}

bool Parser::loadSailor(unsigned long _characterId, std::vector<std::string> _sailor)
{
    std::vector<Sailor> sailors;
    std::vector<char> charToRemove = {'{', '}'};
    for (std::string sailor_string : _sailor)
    {
        std::vector<std::string> element;
        Tools::split(sailor_string, ':', element, &charToRemove);
        if (!element.empty())
        {
            std::vector<char> otherChars = {' ', ','};
            std::vector<std::string> emptyCheck;
            Tools::split(element.at(0), ':', emptyCheck, &otherChars);
            if (!emptyCheck.empty())
            {
                std::string sailor_description = element.at(element.size() - 1);
                sailor_description = sailor_description.substr(sailor_description.find('\"') + 1);
                sailor_description = Tools::removeString(sailor_description.substr(0, sailor_description.find_last_of('\"')), "\\");
                Sailor sail(sailor_description);
                sailors.push_back(sail);
            }
        }
    }
    if (sailors.empty())
    {
        return false;
    }
    else
    {
        if (characters.at(_characterId - 1)->hasDual())
        {
            std::vector<Character*> dual_units = characters.at(_characterId - 1)->getDualUnits();
            dual_units.at(0)->addSailor(&sailors.at(0));
            dual_units.at(1)->addSailor(&sailors.at(1));
            characters.at(_characterId - 1)->addSailor(&sailors.at(2));
        }
        else
        {
            if (sailors.at(0).getDescription().find("None") == std::string::npos)
            {
                characters.at(_characterId - 1)->addSailor(&sailors.at(0));
            }
        }
        return true;
    }
}

bool Parser::loadSpecial(unsigned long _characterId, std::vector<std::string> _special)
{
    std::vector<std::string> special_descriptions;
    std::vector<short> special_cd;
    if (_special.size() == 1)
    {
        std::string special_description = _special.at(0).substr(_special.at(0).find('\"') + 1);
        special_description = Tools::removeString(special_description.substr(0, special_description.find_last_of('\"')), "\\");
        special_descriptions.push_back(special_description);
    }
    else
    {
        for (std::string special_desc : _special)
        {
            std::vector<std::string> element;
            Tools::split(special_desc, ':', element);
            if (element.at(0).find("\"description\"") != std::string::npos)
            {
                std::string special_description = element.at(1).substr(element.at(1).find('\"') + 1);
                special_description = Tools::removeString(special_description.substr(0, special_description.find_last_of('\"')), "\\");
                special_descriptions.push_back(special_description);
            }
            else if (element.at(0).find("\"cooldown\"") != std::string::npos)
            {
                std::vector<std::string> cds;
                std::vector<char> charToRemove = {'[', ']', ' '};
                Tools::split(element.at(1), ',', cds, &charToRemove);
                special_cd.push_back(static_cast<short>(std::stoi(cds.at(0))));
            }
        }
    }
    Special* spec = characters.at(_characterId - 1)->getSpecial();
    const short base_cd = spec->getBase();
    for (unsigned long i = 0; i < special_descriptions.size(); ++i)
    {
        spec->addDescription(special_descriptions.at(i));
        if (_special.size() > 1)
        {
            short offset = base_cd - special_cd.at(i);
            spec->addOffset(offset);
        }
    }
    return false;
}


std::map<int, MyCharacter*> Parser::getOwnedCharacters(int id)
{
    std::map<int, MyCharacter*> idCharacters;
    std::string working_path = QDir::currentPath().toUtf8().constData();
    std::ifstream stream(working_path + "/resources/characters/" + std::to_string(id) + ".json");
    json file;
    stream >> file;

    //Get all owned characters id
    std::vector<std::string> charactersId;
    for (json::iterator it = file.begin(); it != file.end(); ++it)
    {
        auto characterIstance = file.at(it.key()); //Character id
        for (json::iterator kek = characterIstance.begin(); kek != characterIstance.end(); ++kek)
        {
            auto yolo = characterIstance.at(kek.key()); // Istanza del personaggio

            for (json::iterator tre = yolo.begin(); tre != yolo.end(); ++tre)
            {
                auto yololol = tre.key();
                auto ahaha = tre.value();
                std::cout << yololol << " " << ahaha << std::endl;
            }
        }

      charactersId.push_back(it.key());

    }

    return idCharacters;
}

#include "utils.h"

namespace Utils
{

/********************* WIDGET UTILS ***********************************/

void deleteChildWidgets(QLayoutItem* _item)
{
    if (_item->layout())
    {
        // Process all child items recursively.
        for (int i = 0; i < _item->layout()->count(); ++i)
        {
            deleteChildWidgets(_item->layout()->itemAt(i));
        }
    }
    delete _item->widget();
}

void remove(QGridLayout* _layout, int _row, int _column, bool _deleteWidgets)
{
    // We avoid usage of QGridLayout::itemAtPosition() here to improve performance.
    for (int i = _layout->count() - 1; i >= 0; i--)
    {
        int itemRow, itemColumn, itemRowSpan, itemColumnSpan;
        _layout->getItemPosition(i, &itemRow, &itemColumn, &itemRowSpan, &itemColumnSpan);
        if ((itemRow <= _row && itemRow + itemRowSpan - 1 >= _row) ||
            (itemColumn <= _column && itemColumn + itemColumnSpan - 1 >= _column))
        {
            // This layout item is subject to deletion.
            QLayoutItem *item = _layout->takeAt(i);
            if (_deleteWidgets)
            {
                deleteChildWidgets(item);
            }
            delete item;
        }
    }
}

void removeRow(QGridLayout* _layout, int _row, bool _deleteWidgets)
{
    remove(_layout, _row, -1, _deleteWidgets);
    _layout->setRowMinimumHeight(_row, 0);
    _layout->setRowStretch(_row, 0);
}

void removeColumn(QGridLayout* _layout, int _column, bool _deleteWidgets)
{
    remove(_layout, -1, _column, _deleteWidgets);
    _layout->setColumnMinimumWidth(_column, 0);
    _layout->setColumnStretch(_column, 0);
}

/************************ LOGIC UTILS **********************************/

void split(const std::string &_s, char _delim, std::vector<std::string> &_elements, const std::vector<char>* _charToRemove)
{
    std::stringstream ss(_s);
    std::string item;
    while (std::getline(ss, item, _delim))
    {
        if (!item.empty())
        {
            if (_charToRemove != nullptr)
            {
                for (auto symbol : *_charToRemove)
                {
                    item.erase(std::remove(item.begin(), item.end(), symbol), item.end());
                }
            }
            item.erase(std::remove(item.begin(), item.end(), '\r'), item.end());
            if (!item.empty())
            {
                _elements.push_back(item);
            }
        }
    }
}

bool is_number(const std::string& _stringToCheck)
{
    bool isNumber = !_stringToCheck.empty();
    isNumber = isNumber && std::find_if(_stringToCheck.begin(), _stringToCheck.end(), [](char c)
                           {
                                return !std::isdigit(c);
                           }) == _stringToCheck.end();
    return isNumber;
}

std::vector<std::string> parseBalancedBrackets(std::string _stringToParse, unsigned long &_startIndex)
{
    short numBrackets = 0;
    unsigned long currentLength = 0;
    std::vector<char> charToRemove;
    charToRemove.push_back(' ');
    charToRemove.push_back(']');
    charToRemove.push_back('[');
    charToRemove.push_back('\\');
    charToRemove.push_back('\"');

    for (unsigned long i = _startIndex; i < _stringToParse.length(); ++i)
    {
        char letter = _stringToParse.at(i);
        currentLength++;
        if (letter == ',' && numBrackets <= 0)
        {
            std::string parsedString = _stringToParse.substr(_startIndex, currentLength);
            _startIndex += currentLength;
            currentLength = 0;
            std::vector<std::string> element;
            split(parsedString, ',', element, &charToRemove);
            if (element.empty())
            {
                continue;
            }
            else
            {
                return element;
            }
        }
        else if (letter == '[')
        {
            numBrackets++;
        }
        else if (letter == ']')
        {
            numBrackets--;
        }
    }
    return std::vector<std::string>();
}

std::string parseBalanced(std::string& _stringToParse, char _startingChar, char _endingChar)
{
    short numUnbalancedChar = 0;
    unsigned long startingIndex = 0;
    unsigned long endingIndex = 0;

    for (unsigned long i = 0; i < _stringToParse.length(); ++i)
    {
        char letter = _stringToParse.at(i);
        if (letter == _startingChar)
        {
            if (!(_startingChar == _endingChar && numUnbalancedChar > 0))
            {
                numUnbalancedChar++;
                startingIndex = i;
                continue;
            }
        }

        if (letter == _endingChar)
        {
            numUnbalancedChar--;
            if (numUnbalancedChar == 0)
            {
                endingIndex = i;
                break;
            }
        }
    }

    if (startingIndex != 0 && endingIndex != 0)
    {
        std::string parsedString = _stringToParse.substr(startingIndex + 1, endingIndex - startingIndex - 1);
        _stringToParse = _stringToParse.substr(endingIndex + 1);
        return parsedString;
    }
    else
    {
        return "";
    }
}

std::string parseBalanced(std::string& _stringToParse, char _charToBalance)
{
    return parseBalanced(_stringToParse, _charToBalance, _charToBalance);
}


std::string parseBetween(std::string& _stringToParse, std::string _startingString, std::string _endingString)
{
    std::size_t startingIndex = _stringToParse.find(_startingString);
    if (startingIndex == std::string::npos)
    {
        return "";
    }

    std::string fromStartString = _stringToParse.substr(startingIndex + _startingString.length());
    std::size_t endingIndex = fromStartString.find(_endingString);
    if (endingIndex == std::string::npos)
    {
        return "";
    }
    std::string parsedString = fromStartString.substr(0, endingIndex);
    _stringToParse = fromStartString.substr(endingIndex + _endingString.length() - 1);
    return parsedString;
}

std::string parseBetween(std::string& _stringToParse, std::string _char)
{
    return parseBetween(_stringToParse, _char, _char);
}

std::string removeString(std::string _stringToParse, std::string _toRemove)
{
    for (char del : _toRemove)
    {
        _stringToParse.erase(std::remove(_stringToParse.begin(), _stringToParse.end(), del), _stringToParse.end());
    }
    return _stringToParse;
}

std::map<int, std::vector<MyCharacter*>> loadOwnedCharacters(std::vector<Character*> _characters, int _id)
{
    std::map<int, std::vector<MyCharacter*>> ownedCharacters;
    if (_characters.size() > 0)
    {
        // Get owner file
        std::string working_path = QDir::currentPath().toUtf8().constData();
        std::ifstream stream(working_path + "/resources/characters/" + std::to_string(_id) + ".json");
        json file;
        stream >> file;

        // Parse json
        for (json::iterator fileIterator = file.begin(); fileIterator != file.end(); ++fileIterator)
        {
            auto characterIterated = file.at(fileIterator.key()); // (Possibly) List of characters with the same id
            unsigned long id = std::stoul(fileIterator.key());    // Character id
            std::vector<MyCharacter*> charactersWithThisId;
            for (json::iterator characterIdIstance = characterIterated.begin(); characterIdIstance != characterIterated.end(); ++characterIdIstance)
            {
                auto myCharacterJson = characterIterated.at(characterIdIstance.key());  // Character to parse
                MyCharacter* character = new MyCharacter(_characters.at(id - 1), characterIdIstance.key());

                // Set Character Level
                if (myCharacterJson.find("Level") != myCharacterJson.end())
                {
                    short level = myCharacterJson.at("Level");
                    character->setLevel(level);
                }

                // Set Character Skill Level
                if (myCharacterJson.find("SkillLevel") != myCharacterJson.end())
                {
                    short skillLevel = myCharacterJson.at("SkillLevel");
                    character->setSkillLevel(skillLevel);
                }

                // Set Cotton Candies
                if (myCharacterJson.find("Cotton") != myCharacterJson.end())
                {
                    std::vector<short> cottons = myCharacterJson.at("Cotton");
                    character->setCC(cottons);
                }

                if (myCharacterJson.find("DesiredSockets") != myCharacterJson.end())
                {
                    std::vector<std::string> desiredSockets = myCharacterJson.at("DesiredSockets");
                    for (std::string socket : desiredSockets)
                    {
                        if (socket.find("Dmr") != std::string::npos)
                        {
                            character->addDesiredSocket(Socket::Type::Dmr);
                        }
                        else if (socket.find("Cd") != std::string::npos)
                        {
                            character->addDesiredSocket(Socket::Type::Cd);
                        }
                        else if (socket.find("Bind") != std::string::npos)
                        {
                            character->addDesiredSocket(Socket::Type::Bind);
                        }
                        else if (socket.find("Despair") != std::string::npos)
                        {
                            character->addDesiredSocket(Socket::Type::Despair);
                        }
                        else if (socket.find("AH") != std::string::npos)
                        {
                            character->addDesiredSocket(Socket::Type::AH);
                        }
                        else if (socket.find("Rcv") != std::string::npos)
                        {
                            character->addDesiredSocket(Socket::Type::Rcv);
                        }
                        else if (socket.find("Slot") != std::string::npos)
                        {
                            character->addDesiredSocket(Socket::Type::Slot);
                        }
                        else if (socket.find("Poison") != std::string::npos)
                        {
                            character->addDesiredSocket(Socket::Type::Poison);
                        }
                        else if (socket.find("Map") != std::string::npos)
                        {
                            character->addDesiredSocket(Socket::Type::Map);
                        }
                        else if (socket.find("Resilience") != std::string::npos)
                        {
                            character->addDesiredSocket(Socket::Type::Resilience);
                        }
                    }
                }

                if (myCharacterJson.find("CurrentSockets") != myCharacterJson.end())
                {
                    auto currentSockets = myCharacterJson.at("CurrentSockets");
                    if (currentSockets.find("Dmr") != currentSockets.end())
                    {
                        Socket socket(Socket::Type::Dmr, currentSockets.at("Dmr"));
                        character->addSocket(socket);
                    }
                    if (currentSockets.find("Cd") != currentSockets.end())
                    {
                        Socket socket(Socket::Type::Cd, currentSockets.at("Cd"));
                        character->addSocket(socket);
                    }
                    if (currentSockets.find("Bind") != currentSockets.end())
                    {
                        Socket socket(Socket::Type::Bind, currentSockets.at("Bind"));
                        character->addSocket(socket);
                    }
                    if (currentSockets.find("Despair") != currentSockets.end())
                    {
                        Socket socket(Socket::Type::Despair, currentSockets.at("Despair"));
                        character->addSocket(socket);
                    }
                    if (currentSockets.find("AH") != currentSockets.end())
                    {
                        Socket socket(Socket::Type::AH, currentSockets.at("AH"));
                        character->addSocket(socket);
                    }
                    if (currentSockets.find("Rcv") != currentSockets.end())
                    {
                        Socket socket(Socket::Type::Rcv, currentSockets.at("Rcv"));
                        character->addSocket(socket);
                    }
                    if (currentSockets.find("Slot") != currentSockets.end())
                    {
                        Socket socket(Socket::Type::Slot, currentSockets.at("Slot"));
                        character->addSocket(socket);
                    }
                    if (currentSockets.find("Poison") != currentSockets.end())
                    {
                        Socket socket(Socket::Type::Poison, currentSockets.at("Poison"));
                        character->addSocket(socket);
                    }
                    if (currentSockets.find("Map") != currentSockets.end())
                    {
                        Socket socket(Socket::Type::Map, currentSockets.at("Map"));
                        character->addSocket(socket);
                    }
                    if (currentSockets.find("Resilience") != currentSockets.end())
                    {
                        Socket socket(Socket::Type::Resilience, currentSockets.at("Resilience"));
                        character->addSocket(socket);
                    }
                }

                if (myCharacterJson.find("LbUnlockedNodes") != myCharacterJson.end())
                {
                    short unlockedNodes = myCharacterJson.at("LbUnlockedNodes");
                    character->setLbUnlockedNodes(unlockedNodes);
                }

                if (myCharacterJson.find("CurrentPotentials") != myCharacterJson.end())
                {
                    auto currentPotentials = myCharacterJson.at("CurrentPotentials");
                    if (currentPotentials.find("Enrage") != currentPotentials.end())
                    {
                        character->setPotential(Potential::Type::Enrage, currentPotentials.at("Enrage"));
                    }
                    if (currentPotentials.find("NoHealing") != currentPotentials.end())
                    {
                        character->setPotential(Potential::Type::NoHealing, currentPotentials.at("NoHealing"));
                    }
                    if (currentPotentials.find("CriticalHit") != currentPotentials.end())
                    {
                        character->setPotential(Potential::Type::CriticalHit, currentPotentials.at("CriticalHit"));
                    }
                    if (currentPotentials.find("SlotBind") != currentPotentials.end())
                    {
                        character->setPotential(Potential::Type::SlotBind, currentPotentials.at("SlotBind"));
                    }
                    if (currentPotentials.find("BarrierPenetration") != currentPotentials.end())
                    {
                        character->setPotential(Potential::Type::BarrierPenetration, currentPotentials.at("BarrierPenetration"));
                    }
                    if (currentPotentials.find("PinchHealing") != currentPotentials.end())
                    {
                        character->setPotential(Potential::Type::PinchHealing, currentPotentials.at("PinchHealing"));
                    }
                    if (currentPotentials.find("DMRSTR") != currentPotentials.end())
                    {
                        character->setPotential(Potential::Type::DMRSTR, currentPotentials.at("DMRSTR"));
                    }
                    if (currentPotentials.find("DMRQCK") != currentPotentials.end())
                    {
                        character->setPotential(Potential::Type::DMRQCK, currentPotentials.at("DMRQCK"));
                    }
                    if (currentPotentials.find("DMRDEX") != currentPotentials.end())
                    {
                        character->setPotential(Potential::Type::DMRDEX, currentPotentials.at("DMRDEX"));
                    }
                    if (currentPotentials.find("DMRINT") != currentPotentials.end())
                    {
                        character->setPotential(Potential::Type::DMRINT, currentPotentials.at("DMRINT"));
                    }
                    if (currentPotentials.find("DMRPSY") != currentPotentials.end())
                    {
                        character->setPotential(Potential::Type::DMRPSY, currentPotentials.at("DMRPSY"));
                    }
                    if (currentPotentials.find("CDR") != currentPotentials.end())
                    {
                        character->setPotential(Potential::Type::CDR, currentPotentials.at("CDR"));
                    }
                }

                charactersWithThisId.push_back(character);
            }
            ownedCharacters[static_cast<int>(id)] = charactersWithThisId;
        }
        stream.close();
    }

    return ownedCharacters;
}

void saveOwnedCharacters(std::vector<Character*> _characters, std::map<int, std::vector<MyCharacter*>> _myCharacters, int _id)
{
    if (_myCharacters.size() > 0)
    {
        // Get owner file
        std::string working_path = QDir::currentPath().toUtf8().constData();
        std::ofstream outputFile(working_path + "/resources/characters/" + std::to_string(_id) + ".json");
        json myCharactersJson;

        for (std::map<int, std::vector<MyCharacter*>>::iterator it = _myCharacters.begin(); it != _myCharacters.end(); ++it)
        {
            std::vector<MyCharacter*> charactersWithThisId = _myCharacters.at(it->first);
            json thisCharacterJson;
            for (MyCharacter* thisCharacter : charactersWithThisId)
            {
                thisCharacterJson[thisCharacter->getNickname()]["Level"] = thisCharacter->getLevel();
                thisCharacterJson[thisCharacter->getNickname()]["SkillLevel"] = thisCharacter->getSkillLevel();
                thisCharacterJson[thisCharacter->getNickname()]["Cotton"] = thisCharacter->getCC();

                if (_characters.at(it->first - 1)->hasLimitBreak())
                {
                    thisCharacterJson[thisCharacter->getNickname()]["LbUnlockedNodes"] = thisCharacter->getLbUnlockedNodes();
                }

                std::vector<std::string> desiredSockets;
                for (Socket::Type desired : thisCharacter->getDesiredSockets())
                {
                    if (desired == Socket::Type::Dmr)
                    {
                        desiredSockets.push_back("Dmr");
                    }
                    else if (desired == Socket::Type::Cd)
                    {
                        desiredSockets.push_back("Cd");
                    }
                    else if (desired == Socket::Type::Bind)
                    {
                        desiredSockets.push_back("Bind");
                    }
                    else if (desired == Socket::Type::Despair)
                    {
                        desiredSockets.push_back("Despair");
                    }
                    else if (desired == Socket::Type::AH)
                    {
                        desiredSockets.push_back("AH");
                    }
                    else if (desired == Socket::Type::Rcv)
                    {
                        desiredSockets.push_back("Rcv");
                    }
                    else if (desired == Socket::Type::Slot)
                    {
                        desiredSockets.push_back("Slot");
                    }
                    else if (desired == Socket::Type::Poison)
                    {
                        desiredSockets.push_back("Poison");
                    }
                    else if (desired == Socket::Type::Map)
                    {
                        desiredSockets.push_back("Map");
                    }
                    else if (desired == Socket::Type::Resilience)
                    {
                        desiredSockets.push_back("Resilience");
                    }
                }

                if (!thisCharacter->getDesiredSockets().empty())
                {
                    thisCharacterJson[thisCharacter->getNickname()]["DesiredSockets"] = desiredSockets;
                }

                json currentSockets;
                for (Socket socket : thisCharacter->getSockets())
                {
                    if (socket.getType() == Socket::Type::Dmr)
                    {
                        currentSockets["Dmr"] = socket.getValue();
                    }
                    else if (socket.getType() == Socket::Type::Cd)
                    {
                        currentSockets["Cd"] = socket.getValue();
                    }
                    else if (socket.getType() == Socket::Type::Bind)
                    {
                        currentSockets["Bind"] = socket.getValue();
                    }
                    else if (socket.getType() == Socket::Type::Despair)
                    {
                        currentSockets["Despair"] = socket.getValue();
                    }
                    else if (socket.getType() == Socket::Type::AH)
                    {
                        currentSockets["AH"] = socket.getValue();
                    }
                    else if (socket.getType() == Socket::Type::Rcv)
                    {
                        currentSockets["Rcv"] = socket.getValue();
                    }
                    else if (socket.getType() == Socket::Type::Slot)
                    {
                        currentSockets["Slot"] = socket.getValue();
                    }
                    else if (socket.getType() == Socket::Type::Poison)
                    {
                        currentSockets["Poison"] = socket.getValue();
                    }
                    else if (socket.getType() == Socket::Type::Map)
                    {
                        currentSockets["Map"] = socket.getValue();
                    }
                    else if (socket.getType() == Socket::Type::Resilience)
                    {
                        currentSockets["Resilience"] = socket.getValue();
                    }
                }

                if (!thisCharacter->getSockets().empty())
                {
                    thisCharacterJson[thisCharacter->getNickname()]["CurrentSockets"] = currentSockets;
                }

                json currentPotentials;
                for (Potential potential: thisCharacter->getPotential())
                {
                    if (potential.getType() == Potential::Type::Enrage)
                    {
                        currentPotentials["Enrage"] = potential.getValue();
                    }
                    else if (potential.getType() == Potential::Type::NoHealing)
                    {
                        currentPotentials["NoHealing"] = potential.getValue();
                    }
                    else if (potential.getType() == Potential::Type::CriticalHit)
                    {
                        currentPotentials["CriticalHit"] = potential.getValue();
                    }
                    else if (potential.getType() == Potential::Type::SlotBind)
                    {
                        currentPotentials["SlotBind"] = potential.getValue();
                    }
                    else if (potential.getType() == Potential::Type::BarrierPenetration)
                    {
                        currentPotentials["BarrierPenetration"] = potential.getValue();
                    }
                    else if (potential.getType() == Potential::Type::PinchHealing)
                    {
                        currentPotentials["PinchHealing"] = potential.getValue();
                    }
                    else if (potential.getType() == Potential::Type::DMRSTR)
                    {
                        currentPotentials["DMRSTR"] = potential.getValue();
                    }
                    else if (potential.getType() == Potential::Type::DMRQCK)
                    {
                        currentPotentials["DMRQCK"] = potential.getValue();
                    }
                    else if (potential.getType() == Potential::Type::DMRDEX)
                    {
                        currentPotentials["DMRDEX"] = potential.getValue();
                    }
                    else if (potential.getType() == Potential::Type::DMRINT)
                    {
                        currentPotentials["DMRINT"] = potential.getValue();
                    }
                    else if (potential.getType() == Potential::Type::DMRPSY)
                    {
                        currentPotentials["DMRPSY"] = potential.getValue();
                    }
                    else if (potential.getType() == Potential::Type::CDR)
                    {
                        currentPotentials["CDR"] = potential.getValue();
                    }
                }

                if (!thisCharacter->getPotential().empty())
                {
                    thisCharacterJson[thisCharacter->getNickname()]["CurrentPotentials"] = currentPotentials;
                }

            }
            myCharactersJson[std::to_string(it->first)] = thisCharacterJson;
        }
        outputFile << std::setw(4) << myCharactersJson << std::endl;
        outputFile.close();
    }
}

}

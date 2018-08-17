#ifndef UTILITY_H
#define UTILITY_H

#include <character.h>
#include <mycharacter.h>
#include <map>

class Utility
{
public:
    std::vector<Character*>* characters = nullptr;
    std::map<int, MyCharacter*>* myCharacters = nullptr;
};

#endif // UTILITY_H

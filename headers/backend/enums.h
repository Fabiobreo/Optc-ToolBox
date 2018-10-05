#ifndef ENUMS_HPP
#define ENUMS_HPP

#include <iostream>
#include <string>
#include <algorithm>

/**
 * @brief The possible classes of a character
 */
enum class Class
{
    StartClass, Fighter, Shooter, Slasher, Striker, Free_Spirit, Cerebral, Powerhouse, Driven, Evolver, Booster, None, EndClasses
};

/**
 * @brief The possible types of a character
 */
enum class Type
{
    StartType, STR, QCK, DEX, PSY, INT, None, EndTypes
};

/**
 * @brief The possible slots types
 */
enum class Slots
{
    StartSlots, STR, QCK, DEX, PSY, INT, TND, RCV, BLOCK, G, RAINBOW, EMPTY, BOMB, EndSlots
};

/**
 * @brief The possible availability of a character
 */
enum class Availability
{
    StartAvailability, Raid, RaidNeo, Coliseums, ColiseumsNeo, Ambush, Special, FNOnly, GenericF2P, StoryOnly, Limited, TM, LimitedTM, LRR, EndAvailability
};

/**
 * @brief Return a string representation of _value
 * @param _value the class to return
 * @return a string representation of _value
 */
std::string to_string(Class _value);

/**
 * @brief Return the corresponding class of _value
 * @param _value the string to convert to class
 * @return the corresponding class of _value
 */
Class stringToClass(std::string _value);

/**
 * @brief Return a string representation of _value
 * @param _value the type to return
 * @return a string representation of _value
 */
std::string to_string(Type _value);

/**
 * @brief Return the corresponding type of _value
 * @param _value the string to convert to type
 * @return the corresponding type of _value
 */
Type stringToType(std::string _value);

/**
 * @brief Return a string representation of _avail
 * @param _avail the Availability to return
 * @return a string representation of _avail
 */
std::string to_string(Availability _avail);

/**
 * @brief Return the corresponding Availability of _value
 * @param _value the string to convert to Availability
 * @return the corresponding Availability of _value
 */
Availability stringToAvailability(std::string _value);

/**
 * @brief Return a string representation of _slots
 * @param _slots the Slots to return
 * @return a string representation of _slots
 */
std::string to_string(Slots _slots);

/**
 * @brief Return the corresponding Slots of _value
 * @param _value the string to convert to Slots
 * @return the corresponding Slots of _value
 */
Slots stringToSlots(std::string _value);

#endif //ENUMS_HPP

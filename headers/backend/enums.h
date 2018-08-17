#ifndef ENUMS_HPP
#define ENUMS_HPP

#include <iostream>
#include <string>
#include <algorithm>

/**
 * \brief The possible classes of a character
 */
enum class Class
{
    Fighter, Shooter, Slasher, Striker, Free_Spirit, Cerebral, Powerhouse, Driven, Evolver, Booster, None
};

/**
 * \brief The possible types of a character
 */
enum class Type
{
    STR, QCK, DEX, PSY, INT, None
};

/**
 * \brief The possible slots types
 */
enum class Slots
{
    STR, QCK, DEX, PSY, INT, TND, RCV, BLOCK, G, RAINBOW, EMPTY, BOMB
};

/**
 * \brief Return a string representation of _value
 * @param _value the class to return
 * @return a string representation of _value
 */
std::string to_string(Class _value);

/**
 * \brief Return the corresponding class of _value
 * @param _value the string to convert to class
 * @return the corresponding class of _value
 */
Class stringToClass(std::string _value);

/**
 * \brief Return a string representation of _value
 * @param _value the type to return
 * @return a string representation of _value
 */
std::string to_string(Type _value);

/**
 * \brief Return the corresponding type of _value
 * @param _value the string to convert to type
 * @return the corresponding type of _value
 */
Type stringToType(std::string _value);

#endif //ENUMS_HPP

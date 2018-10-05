#ifndef UTILS_H
#define UTILS_H

#include <QLayoutItem>
#include <QGridLayout>
#include <QtWidgets>
#include <iomanip>
#include <sstream>
#include <mycharacter.h>
#include <json.h>
#include <fstream>

namespace Utils
{

    /********************* WIDGET UTILS ***********************************/

    /**
     * @brief Deletes all child widgets of the given layout _item.
     * @param _item: the parent of the children to delete.
     */
    void deleteChildWidgets(QLayoutItem* _item);


    /**
     * @brief Removes all layout items within the given _layout which either span
     * the given _row or _column. If _deleteWidgets is true, all concerned child widgets
     * become not only removed from the layout, but also deleted.
     * @param _layout: the grid layout.
     * @param _row: the row to remove.
     * @param _column: the column to remove.
     * @param _deleteWidgets: deletes child widgets.
     */
    void remove(QGridLayout* _layout, int _row, int _column, bool _deleteWidgets);

    /**
     * @brief Removes all layout items on the given _row from the given grid
     * _layout. If _deleteWidgets is true, all concerned child widgets
     * become not only removed from the layout, but also deleted.
     * @param _layout: the grid layout.
     * @param _row: the row to remove.
     * @param _deleteWidgets: deletes child widgets.
     */
    void removeRow(QGridLayout* _layout, int _row, bool _deleteWidgets);

    /**
     * @brief Removes all layout items on the given _column from the given grid
     * _layout. If _deleteWidgets is true, all concerned child widgets
     * become not only removed from the layout, but also deleted.
     * @param _layout: the grid layout.
     * @param _column: the column to remove.
     * @param _deleteWidgets: deletes child widgets.
     */
    void removeColumn(QGridLayout* _layout, int _column, bool _deleteWidgets);

    /************************ LOGIC UTILS **********************************/

    /**
     * @brief split
     * @param _s
     * @param _delim
     * @param _elements
     * @param _charToRemove
     */
    void split(const std::string &_s, char _delim, std::vector<std::string> &_elements, const std::vector<char>* _charToRemove = nullptr);

    /**
     * @brief parseBalancedBrackets
     * @param _stringToParse
     * @param _startIndex
     * @return
     */
    std::vector<std::string> parseBalancedBrackets(std::string _stringToParse, unsigned long &_startIndex);

    /**
     * @brief is_number
     * @param _stringToCheck
     * @return
     */
    bool is_number(const std::string& _stringToCheck);

    /**
     * @brief Get the string between _startingChar and _endingChar
     * @param _stringToParse
     * @param _startingChar
     * @param _endingChar
     * @return
     */
    std::string parseBalanced(std::string& _stringToParse, char _startingChar, char _endingChar);

    std::string parseBetween(std::string& _stringToParse, std::string _startingString, std::string _endingString);
    std::string parseBetween(std::string& _stringToParse, std::string _char);

    std::string parseBalanced(std::string& _stringToParse, char _charToBalance);

    std::string removeString(std::string _stringToParse, std::string _toRemove);

    std::map<int, std::vector<MyCharacter*>> loadOwnedCharacters(std::vector<Character*> _characters, int _id);
    void saveOwnedCharacters(std::vector<Character*> _characters, std::map<int, std::vector<MyCharacter*>> _myCharacters, int _id);
}

#endif // UTILS_H

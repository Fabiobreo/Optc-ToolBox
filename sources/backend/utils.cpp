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

}

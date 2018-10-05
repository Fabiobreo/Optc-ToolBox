#ifndef CHARACTERITEM_H
#define CHARACTERITEM_H

#include <QtCore>
#include <QtWidgets>
#include <character.h>

class CharacterItem : public QListWidgetItem
{
public:
    explicit CharacterItem(Character* _character);
    ~CharacterItem();

    Character* character;
};

#endif // CHARACTERITEM_H

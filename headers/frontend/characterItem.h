#ifndef CHARACTERITEM_H
#define CHARACTERITEM_H

#include <QtCore>
#include <QtWidgets>
#include <character.h>
#include <QVariant>
#include <utility.h>

class CharacterItem : public QListWidgetItem
{
public:
    explicit CharacterItem(Character* _character, Utility* _utility);

    ~CharacterItem();

    virtual bool operator<(const QListWidgetItem &_other) const override;

    Character* character;
    Utility* utility;

private:

    int checkCondition(Character* _first, Character* _second, std::string _condition, bool _includeLimit = false) const;

    bool applyFinalConditions(Character* _first, Character* _second) const;

    bool hasLowerId(Character* _first, Character* _second) const;

    int hasLowerRarity(Character* _first, Character* _second) const;

    int hasLowerType(Character* _first, Character* _second) const;

    int hasLowerFamily(Character* _first, Character* _second) const;

    int hasLowerCost(Character* _first, Character* _second) const;

    int hasLowerPrimaryClass(Character* _first, Character* _second) const;

    int hasLowerSecondaryClass(Character* _first, Character* _second) const;

    int hasLowerHP(Character* _first, Character* _second, bool _includeLimit) const;

    int hasLowerATK(Character* _first, Character* _second, bool _includeLimit) const;

    int hasLowerRCV(Character* _first, Character* _second, bool _includeLimit) const;

    int hasLowerCombo(Character* _first, Character* _second) const;

    int hasLessSlots(Character* _first, Character* _second, bool _includeLimit) const;

    int hasLowerCooldown(Character* _first, Character* _second, bool _includeLimit) const;

    const int LESS = 0;
    const int GREATER = 1;
    const int EQUAL = 2;
};

#endif // CHARACTERITEM_H

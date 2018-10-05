#ifndef FILTER_H
#define FILTER_H

#include <iostream>
#include <vector>
#include <set>
#include <utility.h>

class Condition
{
public:
    /**
     * \brief Possible targets.
     * NB if you change or add something you have to populate the description in the constructor accordingly.
     */
    enum class Target
    {
        // Primary targets
        PrimaryTargets = 0,
        Id, Name, Rarity, Type, Class, PrimaryClass, SecondaryClass,
        Captain, Sailor, Special, LimitBreak,
        MyCharacter, Availability,
        Stats, Cost, Combo, Slots, MaxLvl, ExpToMax, Evolution, Tandem,
        EndPrimaryTargets,

        // Stats targets
        StatsTargets = 1000,
        minHp, minAtk, minRcv, maxHp, maxAtk, maxRcv,
        EndStatsTargets,

        // Captain targets
        CaptainTargets = 2000,
        BoostHP, BoostATK, BoostRCV,
        BeliBooster, ExpBooster, DropDoublers,
        TimingBased, BoostSpecial, HpBased,
        ChainMultiplier, ComboBased, CdReducer, DamageReducer,
        Healer, Tanker, Zombies, EoTDamageDealer,
        EndCaptainTargets,

        // Sailor targets
        SailorTargets = 3000,
        BoostHPSailor, BoostATKSailor, BoostRCVSailor,
        ParalysisReducer, BlindnessReducer, SilenceReducer,
        SpecialRewindReducer, SpecialCdSailor, OrbKeeper,
        BlownAway, AdditionalDamage, BeneficialOrb,
        EndSailorTargets,

        // Special targets
        SpecialTargets = 4000,

        EndSpecialTargets,

        // Limit Break targets
        LimitBreakTargets = 5000,
        NewCaptain, NewSailors,
        AcquireSocket, ReduceCd, Potential,
        EndLimitBreakTargets,

        // MyCharacter targets
        MyCharacterTargets = 6000,

        EndMyCharacterTargets,

        // Evolution targets
        EvolutionTargets = 7000,
        HasEvolution, NotHasEvolution, MultipleEvolutions, MoreThanAEvolution,
        EndEvolutionTargets
    };

    enum class Operator
    {
         Equal, Unequal, Greater, GreaterEqual, Less, LessEqual, NumOperators
    };

    explicit Condition(std::string _id, Target _target, Operator _operator, std::string _value);
    explicit Condition(std::string _id, Target _target, Target _secondaryTarget, Operator _operator, std::string _value);

    bool isMet(Character* _character);

    std::string getId();
    Target* getTarget();
    Target* getSecondaryTarget();
    Operator* getOperator();
    std::string getValue();
    bool getIncludeLimitBreak();
    Type getTypeValue();
    Class getClassValue();
    Type getTypeTarget();
    Class getClassTarget();
    Potential::Type getPotentialTarget();
    Availability getAvailabilityTarget();
    Slots getSlotTarget();

    void setId(std::string _id);
    void setTarget(Target _target);
    void setSecondaryTarget(Target _target);
    void setOperator(Operator _operator);
    void setValue(std::string _value);
    void setIncludeLimitBreak(bool _include);
    void setTypeValue(Type _type);
    void setClassValue(Class _class);
    void setTypeTarget(Type _type);
    void setClassTarget(Class _class);
    void setPotentialTarget(Potential::Type _potentialTarget);
    void setAvailabilityTarget(Availability _availabilityTarget);
    void setSlotsTarget(Slots _slotsTarget);

    std::string getDescriptionFromTarget(Target _target);
    Target getTargetFromDescription(std::string _description);
    std::string getDescriptionFromOperator(Operator _operator);
    Operator getOperatorFromDescription(std::string _description);
    std::string getPossibleOperationsTypeFromTarget(Target _target);

    std::vector<std::string> getPossibleOperators(Target _target);

private:

    bool numericConditionMet(int _valueToCheck);
    std::string getRegexFromValue(std::string _value);

    std::string id;
    Target target;
    Target secondaryTarget;
    Operator op;
    std::string value;
    bool includeLimitBreak;
    Type typeValue;
    Type typeTarget;
    bool typeTargetSet;
    Class classValue;
    Class classTarget;
    bool classTargetSet;
    Potential::Type potentialTarget;
    Slots slotTarget;
    Availability availabilityValue;
    std::map<Target, std::string> targetToDescriptionMap;
    std::map<std::string, Target> descriptionToTargetMap;
    std::map<Operator, std::string> operatorToDescriptionMap;
    std::map<std::string, Operator> descriptionToOperatorMap;
    std::map<Target, std::string> targetToPossibleOperations;

};

class Filter
{
public:
    explicit Filter(Utility* _utility);

    void addAndCondition(Condition _condition);
    void addOrCondition(Filter _filter);

    void resetFilters();

    std::string getId();
    void setId(std::string _id);

    std::set<int> filter(std::set<int> _ids);

    std::vector<Condition> andConditions;
    std::vector<Filter> orConditions;

private:
    Utility* utility;
    std::map<int, Character*> charactersMap;
    std::string id;

};

#endif // FILTER_H

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
        ATKBoostCaptain, HPBoostCaptain, RCVBoostCaptain,
        BeliBoosterCaptain, ExpBoosterCaptain, DropDoublersCaptain,
        TimingBasedCaptain, BoostSpecialCaptain, HpBasedCaptain,
        ChainMultiplierCaptain, ComboBasedCaptain, CdReducerCaptain, DamageReducerCaptain,
        HealerCaptain, TankCaptain, ZombieCaptain, EoTDamageDealerCaptain,
        EndCaptainTargets,

        // Sailor targets
        SailorTargets = 3000,
        BoostHPSailor, BoostATKSailor, BoostRCVSailor,
        ParalysisReducer, BlindnessReducer, SilenceReducer,
        SpecialRewindReducer, SpecialCdSailor, OrbKeeper,
        BlownAway, AdditionalDamageSailor, BeneficialOrb,
        EndSailorTargets,

        // Special targets
        SpecialTargets = 4000,
        ATKBoostSpecial/**/, OrbBoostSpecial/**/, ColorAffinitySpecial/**/, AdditionalDmgSpecial, ChainBoostSpecial, ChainLockSpecial,
        OrbManipulationSpecial, ConditionSpecial, CrewDebuffReductionSpecial, EnemyBuffReductionSpecial,
        UtilitySpecial, MinCooldownSpecial/**/, NumStagesSpecial/**/,
        EndSpecialTargets,

        // Condition targets
        ConditionTargets = 4100,
        ReduceDefenseCondition, ReduceDefenseBoostCondition, PoisonCondition, PoisonBoostCondition, StronglyPoisonCondition, StronglyPoisonBoostCondition,
        ToxicCondition, ToxicBoostCondition, DelayCondition, DelayBoostCondition, IncreasedDefenseBoostCondition,
        EndConditionTargets,

        // Crew Debuff reducers targets
        CrewDebuffReducerTargets = 4200,
        BindCrew, DespairCrew, SilenceCrew, ParalysisCrew, BlindnessCrew,
        PoisonCrew, BurnCrew, AtkDownCrew, IncreasedDamageTakenCrew,
        PositiveBuffCrew, ChainMultiplierLimitCrew, ChainCoefficientReductionCrew,
        OrbRateUpCrew, OrbRateDownCrew,
        EndCrewDebuffReducerTargets,

        // Enemy Buff reducers targets
        EnemyBuffReducerTargets = 4300,
        EnrageEnemy, AtkUpEnemy, EndOfTurnEnemy, IncreasedDefenseEnemy, PercentDamageReductionEnemy,
        DamageNullificationEnemy, ThresholdDamageReductionEnemy, BarrierEnemy, ResilienceEnemy,
        EndEnemyBuffReducerTargets,

        // Special Utility targets
        SpecialUtilityTargets = 4400,
        CdReducerUtility, ComboBoostUtility, CutterUtility, DmgDealerUtility, DmgReducerUtility,
        FollowingTurnUtility, HealerUtility, HealthReducerUtility, InstantDefeatUtility,
        PerfectEasierUtility, RcvBoostUtility, ZombiesUtility,
        EndSpecialUtilityTargets,

        // Orb manipulation targets
        OrbManipulationTargets = 4500,
        BeneficialManipulation, ChanceManipulation, ControllerManipulation,
        LockManipulation, ShufflerManipulation, SwitcherManipulation,
        EndOrbManipulationTargets,

        // Limit Break targets
        LimitBreakTargets = 5000,
        NewCaptain, NewSailors,
        AcquireSocket, ReduceCd, Potential,
        EndLimitBreakTargets,

        // MyCharacter targets
        MyCharacterTargets = 6000,
        MyLevel, MySkill, MyCotton, MySockets, MyTrainingPoints, MyPotentials,
        EndMyCharacterTargets,

        // Generic targets
        OtherTargets = 6500,
        Have, NotHave, Finished, NotFinished, CottonHp, CottonAtk, CottonRcv,
        EndOtherTargets,

        // Evolution targets
        EvolutionTargets = 7000,
        HasEvolution, NotHasEvolution, MultipleEvolutions, MoreThanAEvolution,
        EndEvolutionTargets
    };

    enum class Operator
    {
         Equal, Unequal, Greater, GreaterEqual, Less, LessEqual, NumOperators
    };

    explicit Condition(Utility* _utility, std::string _id, Target _target, Operator _operator, std::string _value);

    explicit Condition(Utility* _utility, std::string _id, Target _target, Target _secondaryTarget, Operator _operator, std::string _value);

    bool isMet(Character* _character);

    std::string getId();

    Target* getTarget();

    Target* getSecondaryTarget();

    Target* getTerziaryTarget();

    Target* getQuaternaryTarget();

    std::vector<std::string> getGenericTargetValues();

    Operator* getOperator();

    Operator* getSecondaryOperator();

    std::string getValue();

    std::string getSecondaryValue();

    bool getIncludeLimitBreak();

    bool getIncludePlus();

    bool getIncludeWantToFinish();

    Type getTypeValue();

    Class getClassValue();

    Type getTypeTarget();

    Class getClassTarget();

    Potential::Type getPotentialTarget();

    Socket::Type getSocketTarget();

    Availability getAvailabilityTarget();

    Slots getSlotTarget();

    void setId(std::string _id);

    void setTarget(Target _target);

    void setSecondaryTarget(Target _target);

    void setTerziaryTarget(Target _target);

    void setQuaternaryTarget(Target _target);

    void addGenericTargetValue(std::string _value);

    void setOperator(Operator _operator);

    void setValue(std::string _value);

    void setSecondaryOperatorValue(Operator _operator, std::string _value);

    void setIncludeLimitBreak(bool _include);

    void setIncludePlus(bool _include);

    void setIncludeWantToFinish(bool _include);

    void setTypeValue(Type _type);

    void setClassValue(Class _class);

    void setTypeTarget(Type _type);

    void setClassTarget(Class _class);

    void setPotentialTarget(Potential::Type _potentialTarget);

    void setSocketTarget(Socket::Type _socketTarget);

    void setAvailabilityTarget(Availability _availabilityTarget);

    void setSlotsTarget(Slots _slotsTarget);

    std::string getDescriptionFromTarget(Target _macroTarget, Target _target);

    Target getTargetFromDescription(Target _macroTarget, std::string _description);

    std::string getDescriptionFromOperator(Operator _operator);

    Operator getOperatorFromDescription(std::string _description);

    std::string getPossibleOperationsTypeFromTarget(Target _target);

    std::vector<std::string> getPossibleOperators(Target _target);

private:

    bool numericConditionMet(std::string _currentValue, int _valueToCheck);
    std::string getRegexFromValue(std::string _value, Operator _op);

    Utility* utility;
    std::string id;
    Target target;
    Target secondaryTarget;
    Operator op;
    Operator secondaryOp;
    std::string value;
    std::string secondaryValue;
    Target terziaryTarget;
    Target quaternaryTarget;
    std::vector<std::string> genericTargetValues;
    bool includeLimitBreak;
    bool includePlus;
    Type typeValue;
    Type typeTarget;
    bool typeTargetSet;
    Class classValue;
    Class classTarget;
    bool classTargetSet;
    bool includeWantToFinish;
    Potential::Type potentialTarget;
    Socket::Type socketTarget;
    Slots slotTarget;
    Availability availabilityValue;

    std::map<Target, std::map<Target, std::string>> targetToDescriptionMap;
    std::map<Target, std::map<std::string, Target>> descriptionToTargetMap;

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

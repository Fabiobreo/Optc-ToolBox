#include "filter.h"
#include <enums.h>
#include <QRegularExpression>


Condition::Condition(Utility* _utility, std::string _id, Target _target, Operator _operator, std::string _value) :
    utility(_utility),
    id(_id),
    target(_target),
    op(_operator),
    value(_value),
    terziaryTarget(Target::PrimaryTargets),
    quaternaryTarget(Target::PrimaryTargets),
    includeLimitBreak(false),
    includePlus(false),
    typeTargetSet(false),
    classTargetSet(false),
    includeWantToFinish(false)
{
    //// Target to description
    // Primary targets
    targetToDescriptionMap[Target::PrimaryTargets][Target::Id] = "Id";
    targetToDescriptionMap[Target::PrimaryTargets][Target::Name] = "Name";
    targetToDescriptionMap[Target::PrimaryTargets][Target::Type] = "Type";
    targetToDescriptionMap[Target::PrimaryTargets][Target::Class] = "Class";
    targetToDescriptionMap[Target::PrimaryTargets][Target::PrimaryClass] = "Primary Class";
    targetToDescriptionMap[Target::PrimaryTargets][Target::SecondaryClass] = "Secondary Class";
    targetToDescriptionMap[Target::PrimaryTargets][Target::Stats] = "Statistics";
    targetToDescriptionMap[Target::PrimaryTargets][Target::Rarity] = "Rarity";
    targetToDescriptionMap[Target::PrimaryTargets][Target::Cost] = "Cost";
    targetToDescriptionMap[Target::PrimaryTargets][Target::Combo] = "Combo";
    targetToDescriptionMap[Target::PrimaryTargets][Target::Slots] = "Num. of slots";
    targetToDescriptionMap[Target::PrimaryTargets][Target::MaxLvl] = "Max level";
    targetToDescriptionMap[Target::PrimaryTargets][Target::ExpToMax] = "Exp to max";
    targetToDescriptionMap[Target::PrimaryTargets][Target::Evolution] = "Evolution";
    targetToDescriptionMap[Target::PrimaryTargets][Target::Tandem] = "Tandem";
    targetToDescriptionMap[Target::PrimaryTargets][Target::Captain] = "Captain";
    targetToDescriptionMap[Target::PrimaryTargets][Target::Sailor] = "Sailor";
    targetToDescriptionMap[Target::PrimaryTargets][Target::Special] = "Special";
    targetToDescriptionMap[Target::PrimaryTargets][Target::LimitBreak] = "Limit Break";
    targetToDescriptionMap[Target::PrimaryTargets][Target::MyCharacter] = "My Characters";
    targetToDescriptionMap[Target::PrimaryTargets][Target::Availability] = "Availability";

    // Stats targets
    targetToDescriptionMap[Target::Stats][Target::minHp] = "Min Hp";
    targetToDescriptionMap[Target::Stats][Target::minAtk] = "Min Atk";
    targetToDescriptionMap[Target::Stats][Target::minRcv] = "Min Rcv";
    targetToDescriptionMap[Target::Stats][Target::maxHp] = "Max Hp";
    targetToDescriptionMap[Target::Stats][Target::maxAtk] = "Max Atk";
    targetToDescriptionMap[Target::Stats][Target::maxRcv] = "Max Rcv";

    // Captain targets
    targetToDescriptionMap[Target::Captain][Target::HPBoostCaptain] = "Boost HP";
    targetToDescriptionMap[Target::Captain][Target::ATKBoostCaptain] = "Boost ATK";
    targetToDescriptionMap[Target::Captain][Target::RCVBoostCaptain] = "Boost RCV";
    targetToDescriptionMap[Target::Captain][Target::TimingBasedCaptain] = "Timing based";
    targetToDescriptionMap[Target::Captain][Target::BoostSpecialCaptain] = "Boost special";
    targetToDescriptionMap[Target::Captain][Target::HpBasedCaptain] = "Hp-Based ATK";
    targetToDescriptionMap[Target::Captain][Target::ChainMultiplierCaptain] = "Boost chain";
    targetToDescriptionMap[Target::Captain][Target::ComboBasedCaptain] = "Combo based";
    targetToDescriptionMap[Target::Captain][Target::CdReducerCaptain] = "Cd reduction";
    targetToDescriptionMap[Target::Captain][Target::DamageReducerCaptain] = "Dmg reduction";
    targetToDescriptionMap[Target::Captain][Target::HealerCaptain] = "Healer";
    targetToDescriptionMap[Target::Captain][Target::TankCaptain] = "Tanker";
    targetToDescriptionMap[Target::Captain][Target::ZombieCaptain] = "Zombies";
    targetToDescriptionMap[Target::Captain][Target::EoTDamageDealerCaptain] = "EoT Dmg";
    targetToDescriptionMap[Target::Captain][Target::BeliBoosterCaptain] = "Beli boost";
    targetToDescriptionMap[Target::Captain][Target::ExpBoosterCaptain] = "Exp boost";
    targetToDescriptionMap[Target::Captain][Target::DropDoublersCaptain] = "Double drop";

    // Sailor targets
    targetToDescriptionMap[Target::Sailor][Target::BoostHPSailor] = "Boost base HP";
    targetToDescriptionMap[Target::Sailor][Target::BoostATKSailor] = "Boost base ATK";
    targetToDescriptionMap[Target::Sailor][Target::BoostRCVSailor] = "Boost base RCV";
    targetToDescriptionMap[Target::Sailor][Target::ParalysisReducer] = "Paralysis reducers";
    targetToDescriptionMap[Target::Sailor][Target::BlindnessReducer] = "Blindness reducers";
    targetToDescriptionMap[Target::Sailor][Target::SilenceReducer] = "Silence reducers";
    targetToDescriptionMap[Target::Sailor][Target::SpecialRewindReducer] = "Special rewind restorers";
    targetToDescriptionMap[Target::Sailor][Target::SpecialCdSailor] = "Special Cooldown Reducer";
    targetToDescriptionMap[Target::Sailor][Target::OrbKeeper] = "Orb keeper";
    targetToDescriptionMap[Target::Sailor][Target::BlownAway] = "Blow Away Resistance";
    targetToDescriptionMap[Target::Sailor][Target::AdditionalDamageSailor] = "Additional Damage";
    targetToDescriptionMap[Target::Sailor][Target::BeneficialOrb] = "Beneficial orb";

    // Special targets
    targetToDescriptionMap[Target::Special][Target::ATKBoostSpecial] = "Atk boost";
    targetToDescriptionMap[Target::Special][Target::OrbBoostSpecial] = "Orb boost";
    targetToDescriptionMap[Target::Special][Target::ColorAffinitySpecial] = "Color affinity";
    targetToDescriptionMap[Target::Special][Target::AdditionalDmgSpecial] = "Additional Damage";
    targetToDescriptionMap[Target::Special][Target::ChainBoostSpecial] = "Chain boost";
    targetToDescriptionMap[Target::Special][Target::ChainLockSpecial] = "Chain lock";
    targetToDescriptionMap[Target::Special][Target::OrbManipulationSpecial] = "Orb manipulation";
    targetToDescriptionMap[Target::Special][Target::ConditionSpecial] = "Condition";
    targetToDescriptionMap[Target::Special][Target::CrewDebuffReductionSpecial] = "Crew debuff reduction";
    targetToDescriptionMap[Target::Special][Target::EnemyBuffReductionSpecial] = "Enemy buff reduction";
    targetToDescriptionMap[Target::Special][Target::UtilitySpecial] = "Utility";
    targetToDescriptionMap[Target::Special][Target::MinCooldownSpecial] = "Min cooldown";
    targetToDescriptionMap[Target::Special][Target::NumStagesSpecial] = "Num of stages";

    // Condition targets
    targetToDescriptionMap[Target::ConditionSpecial][Target::ReduceDefenseCondition] = "Reduce defense";
    targetToDescriptionMap[Target::ConditionSpecial][Target::ReduceDefenseBoostCondition] = "Boost reduced defense";
    targetToDescriptionMap[Target::ConditionSpecial][Target::PoisonCondition] = "Poison";
    targetToDescriptionMap[Target::ConditionSpecial][Target::PoisonBoostCondition] = "Boost poisoned";
    targetToDescriptionMap[Target::ConditionSpecial][Target::StronglyPoisonCondition] = "Strongly poison";
    targetToDescriptionMap[Target::ConditionSpecial][Target::StronglyPoisonBoostCondition] = "Boost strongly poisoned";
    targetToDescriptionMap[Target::ConditionSpecial][Target::ToxicCondition] = "Toxic";
    targetToDescriptionMap[Target::ConditionSpecial][Target::ToxicBoostCondition] = "Boost toxic";
    targetToDescriptionMap[Target::ConditionSpecial][Target::DelayCondition] = "Delay";
    targetToDescriptionMap[Target::ConditionSpecial][Target::DelayBoostCondition] = "Boost delayed";
    targetToDescriptionMap[Target::ConditionSpecial][Target::IncreasedDefenseBoostCondition] = "Boost Increased Defense";

    // Crew Debuff reducers targets
    targetToDescriptionMap[Target::CrewDebuffReductionSpecial][Target::BindCrew] = "Bind";
    targetToDescriptionMap[Target::CrewDebuffReductionSpecial][Target::DespairCrew] = "Despair";
    targetToDescriptionMap[Target::CrewDebuffReductionSpecial][Target::SilenceCrew] = "Silence";
    targetToDescriptionMap[Target::CrewDebuffReductionSpecial][Target::ParalysisCrew] = "Paralysis";
    targetToDescriptionMap[Target::CrewDebuffReductionSpecial][Target::BlindnessCrew] = "Blindness";
    targetToDescriptionMap[Target::CrewDebuffReductionSpecial][Target::PoisonCrew] = "Poison";
    targetToDescriptionMap[Target::CrewDebuffReductionSpecial][Target::BurnCrew] = "Burn";
    targetToDescriptionMap[Target::CrewDebuffReductionSpecial][Target::AtkDownCrew] = "Atk down";
    targetToDescriptionMap[Target::CrewDebuffReductionSpecial][Target::IncreasedDamageTakenCrew] = "Increase Damage Taken";
    targetToDescriptionMap[Target::CrewDebuffReductionSpecial][Target::PositiveBuffCrew] = "Positive Buff";
    targetToDescriptionMap[Target::CrewDebuffReductionSpecial][Target::ChainMultiplierLimitCrew] = "Chain Multiplier Limit";
    targetToDescriptionMap[Target::CrewDebuffReductionSpecial][Target::ChainCoefficientReductionCrew] = "Chain Coefficient Reduction";
    targetToDescriptionMap[Target::CrewDebuffReductionSpecial][Target::OrbRateUpCrew] = "Orb Rate Up";
    targetToDescriptionMap[Target::CrewDebuffReductionSpecial][Target::OrbRateDownCrew] = "Orb Rate Down";

    // Enemy Buff reducers targets
    targetToDescriptionMap[Target::EnemyBuffReductionSpecial][Target::EnrageEnemy] = "Enrage";
    targetToDescriptionMap[Target::EnemyBuffReductionSpecial][Target::AtkUpEnemy] = "Atk up";
    targetToDescriptionMap[Target::EnemyBuffReductionSpecial][Target::EndOfTurnEnemy] = "End of turn";
    targetToDescriptionMap[Target::EnemyBuffReductionSpecial][Target::IncreasedDefenseEnemy] = "Increased Defense";
    targetToDescriptionMap[Target::EnemyBuffReductionSpecial][Target::PercentDamageReductionEnemy] = "Percent Dmg Reduction";
    targetToDescriptionMap[Target::EnemyBuffReductionSpecial][Target::DamageNullificationEnemy] = "Damage Nullification";
    targetToDescriptionMap[Target::EnemyBuffReductionSpecial][Target::ThresholdDamageReductionEnemy] = "Threshold Damage Reduction";
    targetToDescriptionMap[Target::EnemyBuffReductionSpecial][Target::BarrierEnemy] = "Barrier";
    targetToDescriptionMap[Target::EnemyBuffReductionSpecial][Target::ResilienceEnemy] = "Resilience";

    // Special Utility targets
    targetToDescriptionMap[Target::UtilitySpecial][Target::CdReducerUtility] = "Cd reducer";
    targetToDescriptionMap[Target::UtilitySpecial][Target::ComboBoostUtility] = "Boost combo";
    targetToDescriptionMap[Target::UtilitySpecial][Target::CutterUtility] = "Cutter";
    targetToDescriptionMap[Target::UtilitySpecial][Target::DmgDealerUtility] = "Damage dealer";
    targetToDescriptionMap[Target::UtilitySpecial][Target::DmgReducerUtility] = "Damage reducer";
    targetToDescriptionMap[Target::UtilitySpecial][Target::FollowingTurnUtility] = "Boost following turn";
    targetToDescriptionMap[Target::UtilitySpecial][Target::HealerUtility] = "Healer";
    targetToDescriptionMap[Target::UtilitySpecial][Target::HealthReducerUtility] = "Health reducer";
    targetToDescriptionMap[Target::UtilitySpecial][Target::InstantDefeatUtility] = "Instant defeat";
    targetToDescriptionMap[Target::UtilitySpecial][Target::PerfectEasierUtility] = "Perfect easier";
    targetToDescriptionMap[Target::UtilitySpecial][Target::RcvBoostUtility] = "Boost rcv";
    targetToDescriptionMap[Target::UtilitySpecial][Target::ZombiesUtility] = "Prevent defeat";

    // Orb manipulation targets
    targetToDescriptionMap[Target::OrbManipulationSpecial][Target::BeneficialManipulation] = "Beneficial enabler";
    targetToDescriptionMap[Target::OrbManipulationSpecial][Target::ChanceManipulation] = "Chance changer";
    targetToDescriptionMap[Target::OrbManipulationSpecial][Target::ControllerManipulation] = "Controller";
    targetToDescriptionMap[Target::OrbManipulationSpecial][Target::LockManipulation] = "Locker";
    targetToDescriptionMap[Target::OrbManipulationSpecial][Target::ShufflerManipulation] = "Shuffler";
    targetToDescriptionMap[Target::OrbManipulationSpecial][Target::SwitcherManipulation] = "Switcher";

    // Limit Break targets
    targetToDescriptionMap[Target::LimitBreak][Target::NewCaptain] = "Acquire new Captains";
    targetToDescriptionMap[Target::LimitBreak][Target::NewSailors] = "Acquire new Sailors";
    targetToDescriptionMap[Target::LimitBreak][Target::AcquireSocket] = "Acquire socket slots";
    targetToDescriptionMap[Target::LimitBreak][Target::ReduceCd] = "Reduce Cooldown";
    targetToDescriptionMap[Target::LimitBreak][Target::Potential] = "Potential";

    // Evolution targets
    targetToDescriptionMap[Target::Evolution][Target::HasEvolution] = "Have evolution";
    targetToDescriptionMap[Target::Evolution][Target::NotHasEvolution] = "Not have evolution";
    targetToDescriptionMap[Target::Evolution][Target::MultipleEvolutions] = "Multiple possible";
    targetToDescriptionMap[Target::Evolution][Target::MoreThanAEvolution] = "Evolution can evolve";

    // My Characters target
    targetToDescriptionMap[Target::MyCharacter][Target::MyLevel] = "Level";
    targetToDescriptionMap[Target::MyCharacter][Target::MySkill] = "Skill";
    targetToDescriptionMap[Target::MyCharacter][Target::MyCotton] = "Cotton";
    targetToDescriptionMap[Target::MyCharacter][Target::MySockets] = "Socket";
    targetToDescriptionMap[Target::MyCharacter][Target::MyTrainingPoints] = "Training points";
    targetToDescriptionMap[Target::MyCharacter][Target::MyPotentials] = "Potentials";

    // Generic targets
    targetToDescriptionMap[Target::OtherTargets][Target::Have] = "Have";
    targetToDescriptionMap[Target::OtherTargets][Target::NotHave] = "Not have";
    targetToDescriptionMap[Target::OtherTargets][Target::Finished] = "Finished";
    targetToDescriptionMap[Target::OtherTargets][Target::NotFinished] = "Not finished";
    targetToDescriptionMap[Target::OtherTargets][Target::CottonHp] = "Hp";
    targetToDescriptionMap[Target::OtherTargets][Target::CottonAtk] = "Atk";
    targetToDescriptionMap[Target::OtherTargets][Target::CottonRcv] = "Rcv";

    //// Description to target
    // Primary targets
    descriptionToTargetMap[Target::PrimaryTargets]["Id"] = Target::Id;
    descriptionToTargetMap[Target::PrimaryTargets]["Name"] = Target::Name;
    descriptionToTargetMap[Target::PrimaryTargets]["Type"] = Target::Type;
    descriptionToTargetMap[Target::PrimaryTargets]["Class"] = Target::Class;
    descriptionToTargetMap[Target::PrimaryTargets]["Primary Class"] = Target::PrimaryClass;
    descriptionToTargetMap[Target::PrimaryTargets]["Secondary Class"] = Target::SecondaryClass;
    descriptionToTargetMap[Target::PrimaryTargets]["Statistics"] = Target::Stats;
    descriptionToTargetMap[Target::PrimaryTargets]["Rarity"] = Target::Rarity;
    descriptionToTargetMap[Target::PrimaryTargets]["Cost"] = Target::Cost;
    descriptionToTargetMap[Target::PrimaryTargets]["Combo"] = Target::Combo;
    descriptionToTargetMap[Target::PrimaryTargets]["Num. of slots"] = Target::Slots;
    descriptionToTargetMap[Target::PrimaryTargets]["Max level"] = Target::MaxLvl;
    descriptionToTargetMap[Target::PrimaryTargets]["Exp to max"] = Target::ExpToMax;
    descriptionToTargetMap[Target::PrimaryTargets]["Evolution"] = Target::Evolution;
    descriptionToTargetMap[Target::PrimaryTargets]["Tandem"] = Target::Tandem;
    descriptionToTargetMap[Target::PrimaryTargets]["Captain"] = Target::Captain;
    descriptionToTargetMap[Target::PrimaryTargets]["Sailor"] = Target::Sailor;
    descriptionToTargetMap[Target::PrimaryTargets]["Special"] = Target::Special;
    descriptionToTargetMap[Target::PrimaryTargets]["Limit Break"] = Target::LimitBreak;
    descriptionToTargetMap[Target::PrimaryTargets]["My Characters"] = Target::MyCharacter;
    descriptionToTargetMap[Target::PrimaryTargets]["Availability"] = Target::Availability;

    // Stats targets
    descriptionToTargetMap[Target::Stats]["Min Hp"] = Target::minHp;
    descriptionToTargetMap[Target::Stats]["Min Atk"] = Target::minAtk;
    descriptionToTargetMap[Target::Stats]["Min Rcv"] = Target::minRcv;
    descriptionToTargetMap[Target::Stats]["Max Hp"] = Target::maxHp;
    descriptionToTargetMap[Target::Stats]["Max Atk"] = Target::maxAtk;
    descriptionToTargetMap[Target::Stats]["Max Rcv"] = Target::maxRcv;

    // Captain targets
    descriptionToTargetMap[Target::Captain]["Boost HP"] = Target::HPBoostCaptain;
    descriptionToTargetMap[Target::Captain]["Boost ATK"] = Target::ATKBoostCaptain;
    descriptionToTargetMap[Target::Captain]["Boost RCV"] = Target::RCVBoostCaptain;
    descriptionToTargetMap[Target::Captain]["Timing based"] = Target::TimingBasedCaptain;
    descriptionToTargetMap[Target::Captain]["Boost special"] = Target::BoostSpecialCaptain;
    descriptionToTargetMap[Target::Captain]["Hp-Based ATK"] = Target::HpBasedCaptain;
    descriptionToTargetMap[Target::Captain]["Boost chain"] = Target::ChainMultiplierCaptain;
    descriptionToTargetMap[Target::Captain]["Combo based"] = Target::ComboBasedCaptain;
    descriptionToTargetMap[Target::Captain]["Cd reduction"] = Target::CdReducerCaptain;
    descriptionToTargetMap[Target::Captain]["Dmg reduction"] = Target::DamageReducerCaptain;
    descriptionToTargetMap[Target::Captain]["Healer"] = Target::HealerCaptain;
    descriptionToTargetMap[Target::Captain]["Tanker"] = Target::TankCaptain;
    descriptionToTargetMap[Target::Captain]["Zombies"] = Target::ZombieCaptain;
    descriptionToTargetMap[Target::Captain]["EoT Dmg"] = Target::EoTDamageDealerCaptain;
    descriptionToTargetMap[Target::Captain]["Beli boost"] = Target::BeliBoosterCaptain;
    descriptionToTargetMap[Target::Captain]["Exp boost"] = Target::ExpBoosterCaptain;
    descriptionToTargetMap[Target::Captain]["Double drop"] = Target::DropDoublersCaptain;

    // Sailor targets
    descriptionToTargetMap[Target::Sailor]["Boost base HP"] = Target::BoostHPSailor;
    descriptionToTargetMap[Target::Sailor]["Boost base ATK"] = Target::BoostATKSailor;
    descriptionToTargetMap[Target::Sailor]["Boost base RCV"] = Target::BoostRCVSailor;
    descriptionToTargetMap[Target::Sailor]["Paralysis reducers"] = Target::ParalysisReducer;
    descriptionToTargetMap[Target::Sailor]["Blindness reducers"] = Target::BlindnessReducer;
    descriptionToTargetMap[Target::Sailor]["Silence reducers"] = Target::SilenceReducer;
    descriptionToTargetMap[Target::Sailor]["Special rewind restorers"] = Target::SpecialRewindReducer;
    descriptionToTargetMap[Target::Sailor]["Special Cooldown Reducer"] = Target::SpecialCdSailor;
    descriptionToTargetMap[Target::Sailor]["Orb keeper"] = Target::OrbKeeper;
    descriptionToTargetMap[Target::Sailor]["Blow Away Resistance"] = Target::BlownAway;
    descriptionToTargetMap[Target::Sailor]["Additional Damage"] = Target::AdditionalDamageSailor;
    descriptionToTargetMap[Target::Sailor]["Beneficial orb"] = Target::BeneficialOrb;

    // Special targets
    descriptionToTargetMap[Target::Special]["Atk boost"] = Target::ATKBoostSpecial;
    descriptionToTargetMap[Target::Special]["Orb boost"] = Target::OrbBoostSpecial;
    descriptionToTargetMap[Target::Special]["Color affinity"] = Target::ColorAffinitySpecial;
    descriptionToTargetMap[Target::Special]["Additional Damage"] = Target::AdditionalDmgSpecial;
    descriptionToTargetMap[Target::Special]["Chain boost"] = Target::ChainBoostSpecial;
    descriptionToTargetMap[Target::Special]["Chain lock"] = Target::ChainLockSpecial;
    descriptionToTargetMap[Target::Special]["Orb manipulation"] = Target::OrbManipulationSpecial;
    descriptionToTargetMap[Target::Special]["Condition"] = Target::ConditionSpecial;
    descriptionToTargetMap[Target::Special]["Crew debuff reduction"] = Target::CrewDebuffReductionSpecial;
    descriptionToTargetMap[Target::Special]["Enemy buff reduction"] = Target::EnemyBuffReductionSpecial;
    descriptionToTargetMap[Target::Special]["Utility"] = Target::UtilitySpecial;
    descriptionToTargetMap[Target::Special]["Min cooldown"] = Target::MinCooldownSpecial;
    descriptionToTargetMap[Target::Special]["Num of stages"] = Target::NumStagesSpecial;

    // Condition targets
    descriptionToTargetMap[Target::ConditionSpecial]["Reduce defense"] = Target::ReduceDefenseCondition;
    descriptionToTargetMap[Target::ConditionSpecial]["Boost reduced defense"] = Target::ReduceDefenseBoostCondition;
    descriptionToTargetMap[Target::ConditionSpecial]["Poison"] = Target::PoisonCondition;
    descriptionToTargetMap[Target::ConditionSpecial]["Boost poisoned"] = Target::PoisonBoostCondition;
    descriptionToTargetMap[Target::ConditionSpecial]["Strongly poison"] = Target::StronglyPoisonCondition;
    descriptionToTargetMap[Target::ConditionSpecial]["Boost strongly poisoned"] = Target::StronglyPoisonBoostCondition;
    descriptionToTargetMap[Target::ConditionSpecial]["Toxic"] = Target::ToxicCondition;
    descriptionToTargetMap[Target::ConditionSpecial]["Boost toxic"] = Target::ToxicBoostCondition;
    descriptionToTargetMap[Target::ConditionSpecial]["Delay"] = Target::DelayCondition;
    descriptionToTargetMap[Target::ConditionSpecial]["Boost delayed"] = Target::DelayBoostCondition;
    descriptionToTargetMap[Target::ConditionSpecial]["Boost Increased Defense"] = Target::IncreasedDefenseBoostCondition;

    // Crew Debuff reducers targets
    descriptionToTargetMap[Target::CrewDebuffReductionSpecial]["Bind"] = Target::BindCrew;
    descriptionToTargetMap[Target::CrewDebuffReductionSpecial]["Despair"] = Target::DespairCrew;
    descriptionToTargetMap[Target::CrewDebuffReductionSpecial]["Silence"] = Target::SilenceCrew;
    descriptionToTargetMap[Target::CrewDebuffReductionSpecial]["Paralysis"] = Target::ParalysisCrew;
    descriptionToTargetMap[Target::CrewDebuffReductionSpecial]["Blindness"] = Target::BlindnessCrew;
    descriptionToTargetMap[Target::CrewDebuffReductionSpecial]["Poison"] = Target::PoisonCrew;
    descriptionToTargetMap[Target::CrewDebuffReductionSpecial]["Burn"] = Target::BurnCrew;
    descriptionToTargetMap[Target::CrewDebuffReductionSpecial]["Atk down"] = Target::AtkDownCrew;
    descriptionToTargetMap[Target::CrewDebuffReductionSpecial]["Increase Damage Taken"] = Target::IncreasedDamageTakenCrew;
    descriptionToTargetMap[Target::CrewDebuffReductionSpecial]["Positive Buff"] = Target::PositiveBuffCrew;
    descriptionToTargetMap[Target::CrewDebuffReductionSpecial]["Chain Multiplier Limit"] = Target::ChainMultiplierLimitCrew;
    descriptionToTargetMap[Target::CrewDebuffReductionSpecial]["Chain Coefficient Reduction"] = Target::ChainCoefficientReductionCrew;
    descriptionToTargetMap[Target::CrewDebuffReductionSpecial]["Orb Rate Up"] = Target::OrbRateUpCrew;
    descriptionToTargetMap[Target::CrewDebuffReductionSpecial]["Orb Rate Down"] = Target::OrbRateDownCrew;

    // Enemy Buff reducers targets
    descriptionToTargetMap[Target::EnemyBuffReductionSpecial]["Enrage"] = Target::EnrageEnemy;
    descriptionToTargetMap[Target::EnemyBuffReductionSpecial]["Atk up"] = Target::AtkUpEnemy;
    descriptionToTargetMap[Target::EnemyBuffReductionSpecial]["End of turn"] = Target::EndOfTurnEnemy;
    descriptionToTargetMap[Target::EnemyBuffReductionSpecial]["Increased Defense"] = Target::IncreasedDefenseEnemy;
    descriptionToTargetMap[Target::EnemyBuffReductionSpecial]["Percent Dmg Reduction"] = Target::PercentDamageReductionEnemy;
    descriptionToTargetMap[Target::EnemyBuffReductionSpecial]["Damage Nullification"] = Target::DamageNullificationEnemy;
    descriptionToTargetMap[Target::EnemyBuffReductionSpecial]["Threshold Damage Reduction"] = Target::ThresholdDamageReductionEnemy;
    descriptionToTargetMap[Target::EnemyBuffReductionSpecial]["Barrier"] = Target::BarrierEnemy;
    descriptionToTargetMap[Target::EnemyBuffReductionSpecial]["Resilience"] = Target::ResilienceEnemy;

    // Special Utility targets
    descriptionToTargetMap[Target::UtilitySpecial]["Cd reducer"] = Target::CdReducerUtility;
    descriptionToTargetMap[Target::UtilitySpecial]["Boost combo"] = Target::ComboBoostUtility;
    descriptionToTargetMap[Target::UtilitySpecial]["Cutter"] = Target::CutterUtility;
    descriptionToTargetMap[Target::UtilitySpecial]["Damage dealer"] = Target::DmgDealerUtility;
    descriptionToTargetMap[Target::UtilitySpecial]["Damage reducer"] = Target::DmgReducerUtility;
    descriptionToTargetMap[Target::UtilitySpecial]["Boost following turn"] = Target::FollowingTurnUtility;
    descriptionToTargetMap[Target::UtilitySpecial]["Healer"] = Target::HealerUtility;
    descriptionToTargetMap[Target::UtilitySpecial]["Health reducer"] = Target::HealthReducerUtility;
    descriptionToTargetMap[Target::UtilitySpecial]["Instant defeat"] = Target::InstantDefeatUtility;
    descriptionToTargetMap[Target::UtilitySpecial]["Perfect easier"] = Target::PerfectEasierUtility;
    descriptionToTargetMap[Target::UtilitySpecial]["Boost rcv"] = Target::RcvBoostUtility;
    descriptionToTargetMap[Target::UtilitySpecial]["Prevent defeat"] = Target::ZombiesUtility;

    // Orb manipulation targets
    descriptionToTargetMap[Target::OrbManipulationSpecial]["Beneficial enabler"] = Target::BeneficialManipulation;
    descriptionToTargetMap[Target::OrbManipulationSpecial]["Chance changer"] = Target::ChanceManipulation;
    descriptionToTargetMap[Target::OrbManipulationSpecial]["Controller"] = Target::ControllerManipulation;
    descriptionToTargetMap[Target::OrbManipulationSpecial]["Locker"] = Target::LockManipulation;
    descriptionToTargetMap[Target::OrbManipulationSpecial]["Shuffler"] = Target::ShufflerManipulation;
    descriptionToTargetMap[Target::OrbManipulationSpecial]["Switcher"] = Target::SwitcherManipulation;

    // Limit Break targets
    descriptionToTargetMap[Target::LimitBreak]["Acquire new Captains"] = Target::NewCaptain;
    descriptionToTargetMap[Target::LimitBreak]["Acquire new Sailors"] = Target::NewSailors;
    descriptionToTargetMap[Target::LimitBreak]["Acquire socket slots"] = Target::AcquireSocket;
    descriptionToTargetMap[Target::LimitBreak]["Reduce Cooldown"] = Target::ReduceCd;
    descriptionToTargetMap[Target::LimitBreak]["Potential"] = Target::Potential;

    // Evolution targets
    descriptionToTargetMap[Target::Evolution]["Have evolution"] = Target::HasEvolution;
    descriptionToTargetMap[Target::Evolution]["Not have evolution"] = Target::NotHasEvolution;
    descriptionToTargetMap[Target::Evolution]["Multiple possible"] = Target::MultipleEvolutions;
    descriptionToTargetMap[Target::Evolution]["Evolution can evolve"] = Target::MoreThanAEvolution;

    // My Character targets
    descriptionToTargetMap[Target::MyCharacter]["Level"] = Target::MyLevel;
    descriptionToTargetMap[Target::MyCharacter]["Skill"] = Target::MySkill;
    descriptionToTargetMap[Target::MyCharacter]["Cotton"] = Target::MyCotton;
    descriptionToTargetMap[Target::MyCharacter]["Socket"] = Target::MySockets;
    descriptionToTargetMap[Target::MyCharacter]["Training points"] = Target::MyTrainingPoints;
    descriptionToTargetMap[Target::MyCharacter]["Potentials"] = Target::MyPotentials;

    // Generic targets
    descriptionToTargetMap[Target::OtherTargets]["Have"] = Target::Have;
    descriptionToTargetMap[Target::OtherTargets]["Not have"] = Target::NotHave;
    descriptionToTargetMap[Target::OtherTargets]["Finished"] = Target::Finished;
    descriptionToTargetMap[Target::OtherTargets]["Not finished"] = Target::NotFinished;
    descriptionToTargetMap[Target::OtherTargets]["Hp"] = Target::CottonHp;
    descriptionToTargetMap[Target::OtherTargets]["Atk"] = Target::CottonAtk;
    descriptionToTargetMap[Target::OtherTargets]["Rcv"] = Target::CottonRcv;

    //// Operator to description
    operatorToDescriptionMap[Operator::Equal] = "=";
    operatorToDescriptionMap[Operator::Unequal] = "≠";
    operatorToDescriptionMap[Operator::Greater] = ">";
    operatorToDescriptionMap[Operator::GreaterEqual] = "≥";
    operatorToDescriptionMap[Operator::Less] = "<";
    operatorToDescriptionMap[Operator::LessEqual] = "≤";

    //// Description to operator
    descriptionToOperatorMap["="] = Operator::Equal;
    descriptionToOperatorMap["≠"] = Operator::Unequal;
    descriptionToOperatorMap[">"] = Operator::Greater;
    descriptionToOperatorMap["≥"] = Operator::GreaterEqual;
    descriptionToOperatorMap["<"] = Operator::Less;
    descriptionToOperatorMap["≤"] = Operator::LessEqual;

    //// Target to possible operations
    targetToPossibleOperations[Target::Id] = "Integer";
    targetToPossibleOperations[Target::Name] = "OnlyEquals";
    targetToPossibleOperations[Target::Type] = "OnlyEquals";
    targetToPossibleOperations[Target::Class] = "OnlyEquals";
    targetToPossibleOperations[Target::PrimaryClass] = "OnlyEquals";
    targetToPossibleOperations[Target::SecondaryClass] = "OnlyEquals";
    targetToPossibleOperations[Target::Stats] = "Integer";
    targetToPossibleOperations[Target::Rarity] = "Integer";
    targetToPossibleOperations[Target::Cost] = "Integer";
    targetToPossibleOperations[Target::Combo] = "Integer";
    targetToPossibleOperations[Target::Slots] = "Integer";
    targetToPossibleOperations[Target::MaxLvl] = "Integer";
    targetToPossibleOperations[Target::ExpToMax] = "Integer";
    targetToPossibleOperations[Target::Tandem] = "OnlyEquals";
    targetToPossibleOperations[Target::Captain] = "Decimal";
    targetToPossibleOperations[Target::Sailor] = "Integer";
    targetToPossibleOperations[Target::LimitBreak] = "OnlyEquals";
    targetToPossibleOperations[Target::Availability] = "OnlyEquals";
    targetToPossibleOperations[Target::Special] = "CheckSecondary";
    targetToPossibleOperations[Target::ATKBoostSpecial] = "Decimal";
    targetToPossibleOperations[Target::OrbBoostSpecial] = "Decimal";
    targetToPossibleOperations[Target::ColorAffinitySpecial] = "Decimal";
    targetToPossibleOperations[Target::AdditionalDmgSpecial] = "Decimal";
    targetToPossibleOperations[Target::ChainBoostSpecial] = "Decimal";
    targetToPossibleOperations[Target::ChainLockSpecial] = "Decimal";
    targetToPossibleOperations[Target::MinCooldownSpecial] = "Integer";
    targetToPossibleOperations[Target::NumStagesSpecial] = "Integer";
    targetToPossibleOperations[Target::DelayCondition] = "Integer";
    targetToPossibleOperations[Target::ConditionSpecial] = "Decimal";
    targetToPossibleOperations[Target::CrewDebuffReductionSpecial] = "Decimal";
    targetToPossibleOperations[Target::EnemyBuffReductionSpecial] = "Decimal";
    targetToPossibleOperations[Target::UtilitySpecial] = "Decimal";
    targetToPossibleOperations[Target::OrbManipulationSpecial] = "Decimal";
    targetToPossibleOperations[Target::MyCharacter] = "Integer";

    targetToPossibleOperations[Target::ATKBoostSpecial] = "Decimal";
    targetToPossibleOperations[Target::OrbBoostSpecial] = "Decimal";
    targetToPossibleOperations[Target::ColorAffinitySpecial] = "Decimal";
    targetToPossibleOperations[Target::AdditionalDmgSpecial] = "Decimal";
    targetToPossibleOperations[Target::ChainBoostSpecial] = "Decimal";
    targetToPossibleOperations[Target::ChainLockSpecial] = "Decimal";
    targetToPossibleOperations[Target::ConditionSpecial] = "Decimal";
    targetToPossibleOperations[Target::CrewDebuffReductionSpecial] = "Decimal";
    targetToPossibleOperations[Target::EnemyBuffReductionSpecial] = "Decimal";
    targetToPossibleOperations[Target::BeneficialManipulation] = "Integer";
    targetToPossibleOperations[Target::ChanceManipulation] = "Integer";
    targetToPossibleOperations[Target::CdReducerUtility] = "Integer";
    targetToPossibleOperations[Target::CutterUtility] = "Decimal";
    targetToPossibleOperations[Target::HealerUtility] = "Decimal";
    targetToPossibleOperations[Target::HealthReducerUtility] = "Decimal";
    targetToPossibleOperations[Target::PerfectEasierUtility] = "Integer";
    targetToPossibleOperations[Target::FollowingTurnUtility] = "Decimal";
    targetToPossibleOperations[Target::DmgReducerUtility] = "Decimal";
    targetToPossibleOperations[Target::UtilitySpecial] = "Integer";
}

Condition::Condition(Utility* _utility, std::string _id, Target _target, Target _secondaryTarget, Operator _operator, std::string _value)
{
    Condition(_utility, _id, _target, _operator, _value);
    secondaryTarget = _secondaryTarget;
}

std::string Condition::getId()
{
    return id;
}

Condition::Target* Condition::getTarget()
{
    return &target;
}

Condition::Target* Condition::getSecondaryTarget()
{
    return &secondaryTarget;
}

Condition::Target* Condition::getTerziaryTarget()
{
    return &terziaryTarget;
}

Condition::Target* Condition::getQuaternaryTarget()
{
    return &quaternaryTarget;
}

std::vector<std::string> Condition::getGenericTargetValues()
{
    return genericTargetValues;
}

Condition::Operator* Condition::getOperator()
{
    return &op;
}

Condition::Operator* Condition::getSecondaryOperator()
{
    return &secondaryOp;
}

std::string Condition::getValue()
{
    return value;
}

std::string Condition::getSecondaryValue()
{
    return secondaryValue;
}

bool Condition::getIncludeLimitBreak()
{
    return includeLimitBreak;
}

bool Condition::getIncludePlus()
{
    return includePlus;
}

bool Condition::getIncludeWantToFinish()
{
    return includeWantToFinish;
}

Type Condition::getTypeValue()
{
    return typeValue;
}

Class Condition::getClassValue()
{
    return classValue;
}

Potential::Type Condition::getPotentialTarget()
{
    return potentialTarget;
}

Socket::Type Condition::getSocketTarget()
{
    return socketTarget;
}

void Condition::setId(std::string _id)
{
    id = _id;
}

void Condition::setTarget(Target _target)
{
    target = _target;
}

void Condition::setSecondaryTarget(Target _target)
{
    secondaryTarget = _target;
}

void Condition::setTerziaryTarget(Target _target)
{
    terziaryTarget = _target;
}

void Condition::setQuaternaryTarget(Target _target)
{
    quaternaryTarget = _target;
}

void Condition::addGenericTargetValue(std::string _value)
{
    genericTargetValues.push_back(_value);
}

void Condition::setOperator(Operator _operator)
{
    op = _operator;
}

void Condition::setValue(std::string _value)
{
    value = _value;
}

void Condition::setSecondaryOperatorValue(Operator _operator, std::string _value)
{
    secondaryOp = _operator;
    secondaryValue = _value;
}

void Condition::setIncludeLimitBreak(bool _include)
{
    includeLimitBreak = _include;
}

void Condition::setIncludePlus(bool _include)
{
    includePlus = _include;
}

void Condition::setIncludeWantToFinish(bool _include)
{
    includeWantToFinish = _include;
}

void Condition::setTypeValue(Type _type)
{
    typeValue = _type;
}

void Condition::setClassValue(Class _class)
{
    classValue = _class;
}

void Condition::setPotentialTarget(Potential::Type _potentialTarget)
{
    potentialTarget = _potentialTarget;
}

void Condition::setSocketTarget(Socket::Type _socketTarget)
{
    socketTarget = _socketTarget;
}

bool Condition::isMet(Character* _character)
{
    bool conditionMet = false;
    if (target == Target::Id)
    {
        conditionMet = numericConditionMet(value, _character->getId());
    }
    else if (target == Target::Name)
    {
        std::vector<std::string> family = _character->getFamily();
        for (std::string fam : family)
        {
            std::transform(fam.begin(), fam.end(), fam.begin(), ::tolower);
            std::transform(value.begin(), value.end(), value.begin(), ::tolower);
            if (fam.find(value) != std::string::npos)
            {
                conditionMet = true;
                break;
            }
        }
    }
    else if (target == Target::Type)
    {
        if (op == Operator::Equal)
        {
            for (Type characterType : _character->getType())
            {
                if (characterType == typeValue)
                {
                    conditionMet = true;
                    break;
                }
            }
        }
        else if (op == Operator::Unequal)
        {
            conditionMet = true;
            for (Type characterType : _character->getType())
            {
                if (characterType != typeValue)
                {
                    conditionMet = conditionMet && true;
                }
                else
                {
                    conditionMet = conditionMet && false;
                }
            }
        }
    }
    else if (target == Target::PrimaryClass)
    {
        std::vector<Character*> characterToCheck = {_character};
        if (_character->hasDual())
        {
            characterToCheck.push_back(_character->getDualUnits()[0]);
            characterToCheck.push_back(_character->getDualUnits()[1]);
        }

        if (op == Operator::Equal)
        {
            for (Character* checkingChar : characterToCheck)
            {
                if (classValue == checkingChar->getFirstClass())
                {
                    conditionMet = true;
                }
            }
        }
        else if (op == Operator::Unequal)
        {
            conditionMet = true;
            for (Character* checkingChar : characterToCheck)
            {
                if (classValue != checkingChar->getFirstClass())
                {
                    conditionMet = conditionMet && true;
                }
                else
                {
                    conditionMet = conditionMet && false;
                }
            }
        }
    }
    else if (target == Target::SecondaryClass)
    {
        std::vector<Character*> characterToCheck = {_character};
        if (_character->hasDual())
        {
            characterToCheck.push_back(_character->getDualUnits()[0]);
            characterToCheck.push_back(_character->getDualUnits()[1]);
        }

        if (op == Operator::Equal)
        {
            for (Character* checkingChar : characterToCheck)
            {
                if (classValue == checkingChar->getSecondClass())
                {
                    conditionMet = true;
                }
            }
        }
        else if (op == Operator::Unequal)
        {
            conditionMet = true;
            for (Character* checkingChar : characterToCheck)
            {
                if (classValue != checkingChar->getSecondClass())
                {
                    conditionMet = conditionMet && true;
                }
                else
                {
                    conditionMet = conditionMet && false;
                }
            }
        }
    }
    else if (target == Target::Class)
    {
        std::vector<Character*> characterToCheck = {_character};
        if (_character->hasDual())
        {
            characterToCheck.push_back(_character->getDualUnits()[0]);
            characterToCheck.push_back(_character->getDualUnits()[1]);
        }

        if (op == Operator::Equal)
        {
            for (Character* checkingChar : characterToCheck)
            {
                if (classValue == checkingChar->getFirstClass() || classValue == checkingChar->getSecondClass())
                {
                    conditionMet = true;
                }
            }
        }
        else if (op == Operator::Unequal)
        {
            conditionMet = true;
            for (Character* checkingChar : characterToCheck)
            {
                if (classValue != checkingChar->getFirstClass() && classValue != checkingChar->getSecondClass())
                {
                    conditionMet = conditionMet && true;
                }
                else
                {
                    conditionMet = conditionMet && false;
                }
            }
        }
    }
    else if (target == Target::Stats)
    {
        if (secondaryTarget == Target::minHp)
        {
            conditionMet = numericConditionMet(value, _character->getStats()->hp_min);
        }
        else if (secondaryTarget == Target::minAtk)
        {
            conditionMet = numericConditionMet(value, _character->getStats()->atk_min);
        }
        else if (secondaryTarget == Target::minRcv)
        {
            conditionMet = numericConditionMet(value, _character->getStats()->rcv_min);
        }
        else if (secondaryTarget == Target::maxHp)
        {
            conditionMet = numericConditionMet(value, _character->getStats()->hp_max);

            if (includeLimitBreak)
            {
                if (_character->hasLimitBreak())
                {
                    short limitHp = _character->getLimitBreak()->getAllImprovements().hp;
                    conditionMet = conditionMet || numericConditionMet(value, _character->getStats()->hp_max + limitHp);
                }
            }
        }
        else if (secondaryTarget == Target::maxAtk)
        {
            conditionMet = numericConditionMet(value, _character->getStats()->atk_max);

            if (includeLimitBreak)
            {
                if (_character->hasLimitBreak())
                {
                    short limitAtk = _character->getLimitBreak()->getAllImprovements().atk;
                    conditionMet = conditionMet || numericConditionMet(value, _character->getStats()->atk_max + limitAtk);
                }
            }
        }
        else if (secondaryTarget == Target::maxRcv)
        {
            conditionMet = numericConditionMet(value, _character->getStats()->rcv_max);

            if (includeLimitBreak)
            {
                if (_character->hasLimitBreak())
                {
                    short limitRcv = _character->getLimitBreak()->getAllImprovements().rcv;
                    conditionMet = conditionMet || numericConditionMet(value, _character->getStats()->rcv_max + limitRcv);
                }
            }
        }
    }
    else if (target == Target::Rarity)
    {
        bool numCond = numericConditionMet(value, _character->getStats()->stars);

        int condValue = std::stoi(value);

        // Check for plus characters
        if (condValue == 5 || condValue == 6)
        {
            if (op == Operator::Equal)
            {
                conditionMet = numCond && (includePlus == _character->getStats()->plus);
            }
            else if (op == Operator::Unequal)
            {
                conditionMet = numCond || (includePlus != _character->getStats()->plus);
            }
            else if (op == Operator::Greater)
            {
                if (condValue == static_cast<int>(_character->getStats()->stars))
                {
                    if (!includePlus && _character->getStats()->plus)
                    {
                        conditionMet = true;
                    }
                    else
                    {
                        conditionMet = false;
                    }
                }
                else
                {
                    conditionMet = numCond;
                }
            }
            else if (op == Operator::GreaterEqual)
            {
                if (includePlus && condValue == static_cast<int>(_character->getStats()->stars))
                {
                    if (!_character->getStats()->plus)
                    {
                        conditionMet = false;
                    }
                    else
                    {
                        conditionMet = true;
                    }
                }
                else
                {
                    conditionMet = numCond;
                }
            }
            else if (op == Operator::Less)
            {
                if (includePlus && condValue == static_cast<int>(_character->getStats()->stars))
                {
                    if (!_character->getStats()->plus)
                    {
                        conditionMet = true;
                    }
                    else
                    {
                        conditionMet = false;
                    }
                }
                else
                {
                    conditionMet = numCond;
                }
            }
            else if (op == Operator::LessEqual)
            {
                if (condValue == static_cast<int>(_character->getStats()->stars))
                {
                    if (!includePlus && _character->getStats()->plus)
                    {
                        conditionMet = false;
                    }
                    else
                    {
                        conditionMet = true;
                    }
                }
                else
                {
                    conditionMet = numCond;
                }
            }
        }
        else
        {
            conditionMet = numCond;
        }
    }
    else if (target == Target::Cost)
    {
        conditionMet = numericConditionMet(value, _character->getStats()->cost);
    }
    else if (target == Target::Combo)
    {
        conditionMet = numericConditionMet(value, _character->getStats()->combo);
    }
    else if (target == Target::Slots)
    {
        conditionMet = numericConditionMet(value, _character->getStats()->num_sockets);

        if (includeLimitBreak)
        {
            if (_character->hasLimitBreak())
            {
                short limitSocket = _character->getLimitBreak()->getAllImprovements().socket;
                conditionMet = conditionMet || numericConditionMet(value, _character->getStats()->num_sockets + limitSocket);
            }
        }
    }
    else if (target == Target::MaxLvl)
    {
        conditionMet = numericConditionMet(value, _character->getStats()->max_level);
    }
    else if (target == Target::ExpToMax)
    {
        conditionMet = numericConditionMet(value, static_cast<int>(_character->getStats()->exp_to_max));
    }
    else if (target == Target::Evolution)
    {
        if (secondaryTarget == Target::HasEvolution)
        {
            conditionMet = _character->getEvolution().size() > 0;
        }
        else if (secondaryTarget == Target::NotHasEvolution)
        {
            conditionMet = _character->getEvolution().size() == 0;
        }
        else if (secondaryTarget == Target::MultipleEvolutions)
        {
            conditionMet = _character->getEvolution().size() > 1;
        }
        else if (secondaryTarget == Target::MoreThanAEvolution)
        {
            for (Character* evoChar : _character->getEvolution())
            {
                conditionMet = conditionMet || (evoChar->getEvolution().size() > 0);
            }
        }
    }
    else if (target == Target::Tandem)
    {
        conditionMet = _character->hasTandem();
    }
    else if (target == Target::Captain)
    {
        if (_character->hasCaptain())
        {
            QString matcher;

            QString valueTarget = ".+(by|up to) ";
            valueTarget += QString::fromStdString(getRegexFromValue(value, op));

            // All matchers
            if (secondaryTarget == Target::HPBoostCaptain || secondaryTarget == Target::ATKBoostCaptain || secondaryTarget == Target::RCVBoostCaptain)
            {
                // Add target
                QString statTarget = "";
                if (secondaryTarget == Target::HPBoostCaptain)
                {
                    statTarget += "HP";
                }
                else if (secondaryTarget == Target::ATKBoostCaptain)
                {
                    statTarget += "ATK";
                }
                else if (secondaryTarget == Target::RCVBoostCaptain)
                {
                    statTarget += "RCV";
                }

                matcher += ")";

                // Add type/class
                QString classTypeTarget = " of\\D*";
                if (typeTargetSet)
                {
                    if (typeTarget == Type::StartType)
                    {
                        classTypeTarget += "(all characters|all others)";
                    }
                    else if (typeTarget == Type::EndTypes)
                    {
                        classTypeTarget += "";
                    }
                    else
                    {
                        classTypeTarget += "\\[" + QString::fromStdString(to_string(typeTarget)) + "\\]";
                    }
                }

                if (classTargetSet)
                {
                    classTypeTarget += QString::fromStdString(to_string(classTarget));
                }

                valueTarget += "x";
                matcher = "(Boosts.+" + statTarget + classTypeTarget + valueTarget + ")";

                if (secondaryTarget != Target::ATKBoostCaptain)
                {
                    matcher += "|(Boosts.+" + classTypeTarget + ".+and their " + statTarget + valueTarget + ")";
                }

            }
            else if (secondaryTarget == Target::TimingBasedCaptain)
            {
                matcher = "(after scoring|following a chain|perfect|great|good)";
            }
            else if (secondaryTarget == Target::BoostSpecialCaptain)
            {
                matcher = "Boosts damage.+specials";
            }
            else if (secondaryTarget == Target::HpBasedCaptain)
            {
                matcher = "Boosts ATK.+proportionally to";
            }
            else if (secondaryTarget == Target::ChainMultiplierCaptain)
            {
                matcher = "Boosts.+chain multiplier";
            }
            else if (secondaryTarget == Target::ComboBasedCaptain)
            {
                matcher = "Boosts.+hit in the chain";
            }
            else if (secondaryTarget == Target::CdReducerCaptain)
            {
                matcher = "Reduces cooldown" + valueTarget + " turn";
            }
            else if (secondaryTarget == Target::DamageReducerCaptain)
            {
                matcher = "Reduces (any )?damage received" + valueTarget + "%";
            }
            else if (secondaryTarget == Target::HealerCaptain)
            {
                matcher = "Recovers.+";
                if (terziaryTarget == Target::PrimaryTargets)   //RCV based
                {
                    matcher += "(his|her|character's) RCV";
                }
                else if (terziaryTarget == Target::EndPrimaryTargets) //Other
                {
                    matcher += "(?<!RCV in) HP";
                }
            }
            else if (secondaryTarget == Target::TankCaptain)
            {
                matcher = "Reduces (any )?damage.+if HP.+99";
            }
            else if (secondaryTarget == Target::ZombieCaptain)
            {
                matcher = "Protects from defeat";
            }
            else if (secondaryTarget == Target::EoTDamageDealerCaptain)
            {
                matcher = "(deals|cuts).+end of each turn";
            }
            else if (secondaryTarget == Target::BeliBoosterCaptain)
            {
                matcher = "Boosts.+Beli" + valueTarget + "x";
            }
            else if (secondaryTarget == Target::ExpBoosterCaptain)
            {
                matcher = "Boosts.+EXP" + valueTarget + "x";
            }
            else if (secondaryTarget == Target::DropDoublersCaptain)
            {
                matcher = "Duplicating a drop";
            }

            // Load all captains
            std::vector<std::string> captains;
            if (_character->hasCaptain())
            {
                captains.push_back(_character->getCaptain()->getDescription());
            }

            if (_character->hasLimitBreak())
            {
                for (Captain cap : _character->getLimitBreak()->getNewCaptainAbilities())
                {
                    captains.push_back(cap.getDescription());
                }
            }

            if (_character->hasDual())
            {
                std::vector<Character*> duals = _character->getDualUnits();
                if (duals[0]->hasCaptain())
                {
                    captains.push_back(duals[0]->getCaptain()->getDescription());
                }
                if (duals[1]->hasCaptain())
                {
                    captains.push_back(duals[1]->getCaptain()->getDescription());
                }
            }

            QRegularExpression regex(matcher, QRegularExpression::CaseInsensitiveOption);
            for (std::string cap : captains)
            {
                QRegularExpressionMatch match = regex.match(QString::fromStdString(cap));
                if (match.hasMatch())
                {
                    conditionMet = true;
                }
            }
        }
    }
    else if (target == Target::Sailor)
    {
        QString matcher;
        if (secondaryTarget == Target::BoostHPSailor || secondaryTarget == Target::BoostATKSailor || secondaryTarget == Target::BoostRCVSailor)
        {
            // Add target
            QString statTarget = "";
            if (secondaryTarget == Target::BoostHPSailor)
            {
                statTarget += "HP";
            }
            else if (secondaryTarget == Target::BoostATKSailor)
            {
                statTarget += "ATK";
            }
            else if (secondaryTarget == Target::BoostRCVSailor)
            {
                statTarget += "RCV";
            }

            // Add type/class
            QString classTypeTarget = " of\\D*";
            if (typeTargetSet)
            {
                if (typeTarget == Type::StartType)
                {
                    classTypeTarget += "(all characters|all others)";
                }
                else if (typeTarget == Type::EndTypes)
                {
                    classTypeTarget += "";
                }
                else
                {
                    classTypeTarget += "\\[" + QString::fromStdString(to_string(typeTarget)) + "\\]";
                }
            }

            if (classTargetSet)
            {
                if (classTarget == Class::None)
                {
                    classTypeTarget += "(Dominant Type)";
                }
                else
                {
                    classTypeTarget += QString::fromStdString(to_string(classTarget));
                }
            }

            matcher = "(Boosts.+base " + statTarget + classTypeTarget + ")";

            if (secondaryTarget != Target::ATKBoostCaptain)
            {
                matcher += "|(Boosts.+" + classTypeTarget + ".+and their " + statTarget + ")";
            }
        }
        else if (secondaryTarget == Target::ParalysisReducer)
        {
            matcher = "(reduces|removes|resists).+Paralysis";
        }
        else if (secondaryTarget == Target::BlindnessReducer)
        {
            matcher = "(reduces|removes|resists).+blindness";
        }
        else if (secondaryTarget == Target::SilenceReducer)
        {
            matcher = "(reduces|removes|resists).+silence";
        }
        else if (secondaryTarget == Target::SpecialRewindReducer)
        {
            matcher = "Restores (his|her) own special";
        }
        else if (secondaryTarget == Target::SpecialCdSailor)
        {
            matcher = "When any.+character uses a special, reduces own cooldown";
        }
        else if (secondaryTarget == Target::OrbKeeper)
        {
            matcher = "If this character has.+" + QString::fromStdString(to_string(slotTarget)) + ".+" + QString::fromStdString(value);
        }
        else if (secondaryTarget == Target::BlownAway)
        {
            matcher = "Cannot be Blown away";
        }
        else if (secondaryTarget == Target::AdditionalDamageSailor)
        {
            matcher = "Additional.+Damage";
        }
        else if (secondaryTarget == Target::BeneficialOrb)
        {
            QString slotTargetDesc = "";
            if (slotTarget != Slots::StartSlots)
            {
                slotTargetDesc = "\\[" + QString::fromStdString(to_string(slotTarget)) + "\\]";
            }

            QString classTypeTarget = "";
            if (typeTargetSet)
            {
                if (typeTarget == Type::StartType)
                {
                    classTypeTarget += "(all characters|all others)";
                }
                else if (typeTarget == Type::EndTypes)
                {
                    classTypeTarget += "this";
                }
                else
                {
                    classTypeTarget += "\\[" + QString::fromStdString(to_string(typeTarget)) + "\\]";
                }
            }

            if (classTargetSet)
            {
                classTypeTarget += QString::fromStdString(to_string(classTarget));
            }
            matcher = "Makes " + slotTargetDesc + "\\D*orbs \"beneficial\" for " + classTypeTarget + "\\D*character";
        }

        std::vector<std::string> sailors;

        if (_character->hasSailor())
        {
            for (Sailor sail : _character->getSailors())
            {
                sailors.push_back(sail.getDescription());
            }
        }

        if (_character->hasDual())
        {
            std::vector<Character*> duals = _character->getDualUnits();
            if (duals[0]->hasSailor())
            {
                for (Sailor sail : duals[0]->getSailors())
                {
                    sailors.push_back(sail.getDescription());
                }
            }
            if (duals[1]->hasSailor())
            {
                for (Sailor sail : duals[1]->getSailors())
                {
                    sailors.push_back(sail.getDescription());
                }
            }
        }

        // Include limit break
        if (includeLimitBreak)
        {
            if (_character->hasLimitBreak())
            {
                for (Sailor sail : _character->getLimitBreak()->getNewSailorAbilities())
                {
                    sailors.push_back(sail.getDescription());
                }
            }
        }


        QRegularExpression regex(matcher, QRegularExpression::CaseInsensitiveOption);
        for (std::string sailor : sailors)
        {
            QRegularExpressionMatch match = regex.match(QString::fromStdString(sailor));
            if (match.hasMatch())
            {
                conditionMet = true;
            }
        }

    }
    else if (target == Target::Special)
    {
        if (_character->hasSpecial())
        {
            if (secondaryTarget == Target::MinCooldownSpecial)
            {
                short cd = _character->getSpecial()->getMaxedCd();
                cd -= _character->getSpecial()->getStageOffset(1);
                if (includeLimitBreak && _character->hasLimitBreak())
                {
                    cd -= _character->getLimitBreak()->getAllImprovements().cd;
                }
                conditionMet = numericConditionMet(value, cd);
            }
            else if (secondaryTarget == Target::NumStagesSpecial)
            {
                conditionMet = numericConditionMet(value, static_cast<int>(_character->getSpecial()->getNumberOfStages()));
            }
            else
            {
                QString matcher;
                if (secondaryTarget == Target::ATKBoostSpecial || secondaryTarget == Target::OrbBoostSpecial || secondaryTarget == Target::ColorAffinitySpecial)
                {
                    QString classTypeTarget;
                    if (secondaryTarget == Target::ATKBoostSpecial)
                    {
                        matcher = "Boosts ATK[^,]+";

                        // Add type/class
                        classTypeTarget = "of\\D*";
                        if (typeTargetSet)
                        {
                            if (typeTarget == Type::StartType)
                            {
                                classTypeTarget += "(all characters)";
                            }
                            else if (typeTarget == Type::EndTypes)
                            {
                                classTypeTarget += "";
                            }
                            else
                            {
                                classTypeTarget += "\\[" + QString::fromStdString(to_string(typeTarget)) + "\\]";
                            }
                        }

                        if (classTargetSet)
                        {
                            if (classTarget == Class::None)
                            {
                                classTypeTarget += "(Dominant Type)";
                            }
                            else
                            {
                                classTypeTarget += QString::fromStdString(to_string(classTarget));
                            }
                        }
                        classTypeTarget += ".+";
                    }
                    else if (secondaryTarget == Target::OrbBoostSpecial)
                    {
                        matcher = "amplifies.+orbs";

                        // Add type/class
                        classTypeTarget = "\\D*for.+";
                        if (typeTargetSet)
                        {
                            if (typeTarget == Type::StartType)
                            {
                                classTypeTarget = " ";
                            }
                            else if (typeTarget == Type::EndTypes)
                            {
                                classTypeTarget = ".+";
                            }
                            else
                            {
                                classTypeTarget += "\\[" + QString::fromStdString(to_string(typeTarget)) + "\\].+";
                            }
                        }

                        if (classTargetSet)
                        {
                            if (classTarget == Class::None)
                            {
                                classTypeTarget += "(Dominant Type).+";
                            }
                            else
                            {
                                classTypeTarget += QString::fromStdString(to_string(classTarget)) + ".+";
                            }
                        }
                    }
                    else if (secondaryTarget == Target::ColorAffinitySpecial)
                    {
                        matcher = "Boosts the Color Affinity[^,]+";
                        // Add type/class
                        classTypeTarget = "of.+";
                        if (typeTargetSet)
                        {
                            if (typeTarget == Type::StartType)
                            {
                                classTypeTarget += "(all characters)";
                            }
                            else if (typeTarget == Type::EndTypes)
                            {
                                classTypeTarget += "";
                            }
                            else
                            {
                                classTypeTarget += "\\[" + QString::fromStdString(to_string(typeTarget)) + "\\]";
                            }
                        }

                        if (classTargetSet)
                        {
                            if (classTarget == Class::None)
                            {
                                classTypeTarget += "(Dominant Type)";
                            }
                            else
                            {
                                classTypeTarget += QString::fromStdString(to_string(classTarget));
                            }
                        }
                        classTypeTarget += ".+";
                    }

                    // Add value
                    QString valueTarget = "(by ";
                    valueTarget += QString::fromStdString(getRegexFromValue(value, op));
                    valueTarget += "x|depending on your Treasure Map Level)";

                    // Add turns
                    QString secondaryValueTarget = "[^,]+for ";
                    secondaryValueTarget += QString::fromStdString(getRegexFromValue(secondaryValue, secondaryOp));
                    secondaryValueTarget += " turn";

                    matcher += classTypeTarget + valueTarget + secondaryValueTarget;
                }
                else if (secondaryTarget == Condition::Target::AdditionalDmgSpecial || secondaryTarget == Condition::Target::ChainBoostSpecial || secondaryTarget == Condition::Target::ChainLockSpecial)
                {
                    // Add value
                    QString valueTarget = "";
                    valueTarget += QString::fromStdString(getRegexFromValue(value, op));
                    valueTarget += "x|depending on your Treasure Map Level)";

                    // Add turns
                    QString secondaryValueTarget = "[^,]+for ";
                    secondaryValueTarget += QString::fromStdString(getRegexFromValue(secondaryValue, secondaryOp));
                    secondaryValueTarget += " turn";

                    if (secondaryTarget == Condition::Target::AdditionalDmgSpecial)
                    {
                        matcher = "(" + valueTarget + "\\D*Additional.+Damage" + secondaryValueTarget;
                    }
                    else if (secondaryTarget == Condition::Target::ChainBoostSpecial)
                    {
                        valueTarget = "(" + valueTarget;
                        matcher = "Adds\\D*" + valueTarget + "\\D*to chain multiplier" + secondaryValueTarget;
                    }
                    else if (secondaryTarget == Condition::Target::ChainLockSpecial)
                    {
                        valueTarget = "(at " + valueTarget;
                        matcher = "Locks the chain multiplier\\D*" + valueTarget + secondaryValueTarget;
                    }
                }
                else if (secondaryTarget == Condition::Target::CrewDebuffReductionSpecial || secondaryTarget == Condition::Target::EnemyBuffReductionSpecial)
                {
                    // Add value
                    QString valueTarget = "by ";
                    valueTarget += QString::fromStdString(getRegexFromValue(value, op));
                    valueTarget += " turn";
                    if (terziaryTarget == Condition::Target::BindCrew)
                    {
                        matcher = "(reduces\\D*bind\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))bind)";
                    }
                    else if (terziaryTarget == Condition::Target::DespairCrew)
                    {
                        matcher = "(reduces\\D*despair\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))despair)";
                    }
                    else if (terziaryTarget == Condition::Target::SilenceCrew)
                    {
                        matcher = "(reduces\\D*silence\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))silence)";
                    }
                    else if (terziaryTarget == Condition::Target::ParalysisCrew)
                    {
                        matcher = "(reduces\\D*paralysis\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))paralysis)";
                    }
                    else if (terziaryTarget == Condition::Target::BlindnessCrew)
                    {
                        matcher = "(reduces\\D*blindness\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))blindness)";
                    }
                    else if (terziaryTarget == Condition::Target::PoisonCrew)
                    {
                        matcher = "(reduces\\D*poison\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))poison)";
                    }
                    else if (terziaryTarget == Condition::Target::BurnCrew)
                    {
                        matcher = "(reduces\\D*burn\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))burn)";
                    }
                    else if (terziaryTarget == Condition::Target::AtkDownCrew)
                    {
                        matcher = "(reduces\\D*atk down\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))atk down)";
                    }
                    else if (terziaryTarget == Condition::Target::IncreasedDamageTakenCrew)
                    {
                        matcher = "(reduces\\D*Increase Damage Taken\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))Increase Damage Taken)";
                    }
                    else if (terziaryTarget == Condition::Target::PositiveBuffCrew)
                    {
                        matcher = "(reduces\\D*positive buffs\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))positive buffs)";
                    }
                    else if (terziaryTarget == Condition::Target::ChainMultiplierLimitCrew)
                    {
                        matcher = "(reduces\\D*Chain Multiplier Limit\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))Chain Multiplier Limit)";
                    }
                    else if (terziaryTarget == Condition::Target::ChainCoefficientReductionCrew)
                    {
                        matcher = "(reduces\\D*Chain Coefficient Reduction\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))Chain Coefficient Reduction)";
                    }
                    else if (terziaryTarget == Condition::Target::OrbRateUpCrew)
                    {
                        matcher = "(reduces\\D*Orb Rate Up\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))Orb Rate Up)";
                    }
                    else if (terziaryTarget == Condition::Target::OrbRateDownCrew)
                    {
                        matcher = "(reduces\\D*Orb Rate Down\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))Orb Rate Down)";
                    }
                    else if (terziaryTarget == Condition::Target::EnrageEnemy)
                    {
                        matcher = "(reduces\\D*Enrage\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))Enrage)";
                    }
                    else if (terziaryTarget == Condition::Target::AtkUpEnemy)
                    {
                        matcher = "(reduces\\D*atk up\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))atk up)";
                    }
                    else if (terziaryTarget == Condition::Target::EndOfTurnEnemy)
                    {
                        matcher = "(reduces\\D*end of turn\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))end of turn)";
                    }
                    else if (terziaryTarget == Condition::Target::IncreasedDefenseEnemy)
                    {
                        matcher = "(reduces\\D*Increased Defense\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))Increased Defense)";
                    }
                    else if (terziaryTarget == Condition::Target::PercentDamageReductionEnemy)
                    {
                        matcher = "(reduces\\D*Percent Damage Reduction\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))Percent Damage Reduction)";
                    }
                    else if (terziaryTarget == Condition::Target::DamageNullificationEnemy)
                    {
                        matcher = "(reduces\\D*Damage Nullification\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))Damage Nullification)";
                    }
                    else if (terziaryTarget == Condition::Target::ThresholdDamageReductionEnemy)
                    {
                        matcher = "(reduces\\D*Threshold Damage Reduction\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))Threshold Damage Reduction)";
                    }
                    else if (terziaryTarget == Condition::Target::BarrierEnemy)
                    {
                        matcher = "(reduces\\D*Barrier\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))Barrier)";
                    }
                    else if (terziaryTarget == Condition::Target::ResilienceEnemy)
                    {
                        matcher = "(reduces\\D*Resilience\\D*duration[^,]+" + valueTarget;
                        matcher += "|removes\\D*(?<!(reduces ))Resilience)";
                    }
                }
                else if (secondaryTarget == Condition::Target::UtilitySpecial)
                {
                    if (terziaryTarget == Condition::Target::ComboBoostUtility)
                    {
                        matcher = "Boost.+hit in the chain";
                    }
                    else if (terziaryTarget == Condition::Target::RcvBoostUtility)
                    {
                        matcher = "Boosts.+RCV";
                    }
                    else if (terziaryTarget == Condition::Target::InstantDefeatUtility)
                    {
                        matcher = "instantly defeat";
                    }
                    else if (terziaryTarget == Condition::Target::ZombiesUtility)
                    {
                        matcher = "Protects from defeat";
                    }
                    else if (terziaryTarget == Condition::Target::PerfectEasierUtility)
                    {
                        matcher = "makes PERFECTs easier to hit";

                        // Add turns
                        QString secondaryValueTarget = "[^,]+for ";
                        secondaryValueTarget += QString::fromStdString(getRegexFromValue(secondaryValue, secondaryOp));
                        secondaryValueTarget += " turn";

                        matcher += secondaryValueTarget;
                    }
                    else if (terziaryTarget == Condition::Target::DmgReducerUtility)
                    {
                        matcher = "Reduces (any )?damage received(\\D*above.+HP\\D*|\\D*)";

                        // Add value
                        QString valueTarget = "(by ";
                        valueTarget += QString::fromStdString(getRegexFromValue(value, op));
                        valueTarget += "%|depending on your Treasure Map Level|by a variable factor)";

                        // Add turns
                        QString secondaryValueTarget = "[^,]+for ";
                        secondaryValueTarget += QString::fromStdString(getRegexFromValue(secondaryValue, secondaryOp));
                        secondaryValueTarget += " turn";

                        matcher += valueTarget + secondaryValueTarget;
                    }
                    else if (terziaryTarget == Condition::Target::CdReducerUtility)
                    {
                        matcher = "reduces special cooldown\\D*";

                        // Add type/class
                        QString classTypeTarget = "of.+";
                        if (typeTargetSet)
                        {
                            if (typeTarget == Type::StartType)
                            {
                                classTypeTarget += "(all characters)";
                            }
                            else if (typeTarget == Type::EndTypes)
                            {
                                classTypeTarget += "";
                            }
                            else
                            {
                                classTypeTarget += "\\[" + QString::fromStdString(to_string(typeTarget)) + "\\]";
                            }
                        }

                        if (classTargetSet)
                        {
                            if (classTarget == Class::None)
                            {
                                classTypeTarget += "(Dominant Type)";
                            }
                            else
                            {
                                classTypeTarget += QString::fromStdString(to_string(classTarget));
                            }
                        }
                        classTypeTarget += ".+";

                        // Add value
                        QString valueTarget = "(by ";
                        valueTarget += QString::fromStdString(getRegexFromValue(value, op));
                        valueTarget += " turn|depending on your Treasure Map Level)";

                        matcher += classTypeTarget + valueTarget;
                    }
                    else if (terziaryTarget == Condition::Target::FollowingTurnUtility)
                    {
                        // Add type/class
                        QString classTypeTarget = "of.+";
                        if (typeTargetSet)
                        {
                            if (typeTarget == Type::StartType)
                            {
                                classTypeTarget += "(all characters)";
                            }
                            else if (typeTarget == Type::EndTypes)
                            {
                                classTypeTarget += "";
                            }
                            else
                            {
                                classTypeTarget += "\\[" + QString::fromStdString(to_string(typeTarget)) + "\\]";
                            }
                        }

                        if (classTargetSet)
                        {
                            if (classTarget == Class::None)
                            {
                                classTypeTarget += "(Dominant Type)";
                            }
                            else
                            {
                                classTypeTarget += QString::fromStdString(to_string(classTarget));
                            }
                        }
                        classTypeTarget += "\\D*";

                        // Add value
                        QString valueTarget = "(by ";
                        valueTarget += QString::fromStdString(getRegexFromValue(value, op));
                        valueTarget += "x|depending on your Treasure Map Level)";

                        matcher = "(Following the activation.+boosts\\D*ATK\\D*" + classTypeTarget + valueTarget;
                        matcher += "|If during that turn.+boosts\\D*ATK\\D*" + classTypeTarget + valueTarget + ")";
                    }
                    else if (terziaryTarget == Condition::Target::CutterUtility)
                    {
                        matcher = "Cuts\\D*current HP\\D*";
                        if (quaternaryTarget == Condition::Target::PrimaryTargets)  //One
                        {
                            matcher += "one enem\\D*";
                        }
                        else if (quaternaryTarget == Condition::Target::EndPrimaryTargets)  //All
                        {
                            matcher += "each enem\\D*";
                        }

                        // Add value
                        QString valueTarget = "(by ";
                        valueTarget += QString::fromStdString(getRegexFromValue(value, op));
                        valueTarget += "%|depending on your Treasure Map Level)";
                        matcher += valueTarget;
                    }
                    else if (terziaryTarget == Condition::Target::HealerUtility)
                    {
                        matcher = "Recovers\\D*";

                        // Add value
                        QString valueTarget = "(";
                        valueTarget += QString::fromStdString(getRegexFromValue(value, op));
                        valueTarget += "(x|%|)|depending on your Treasure Map Level|\\?(x|%|))";

                        if (quaternaryTarget == Condition::Target::PrimaryTargets) //Other
                        {
                            matcher += valueTarget + "\\D*(?=(?<!character's RCV in ))(?=(?<!MAX ))HP";
                        }
                        else if (quaternaryTarget == Condition::Target::EndPrimaryTargets) //Rcv based
                        {
                            matcher += valueTarget + "\\D*character's RCV";
                        }
                        else if (quaternaryTarget == Condition::Target::HealerUtility) //Max HP based
                        {
                            matcher += valueTarget + "\\D*MAX HP";
                        }
                    }
                    else if (terziaryTarget == Condition::Target::HealthReducerUtility)
                    {
                        matcher = "Reduces crew's (current )?HP";

                        // Add value
                        QString valueTarget = "(";
                        valueTarget += QString::fromStdString(getRegexFromValue(value, op));

                        if (quaternaryTarget == Condition::Target::PrimaryTargets) //Fixed
                        {
                            matcher += " to " + valueTarget + ")";
                        }
                        else if (quaternaryTarget == Condition::Target::EndPrimaryTargets) //Percentage
                        {
                            matcher += " by " + valueTarget + "%)";
                        }
                    }
                    else if (terziaryTarget == Condition::Target::DmgDealerUtility)
                    {
                        matcher = "deals.+";

                        //Quantity of damage
                        if (genericTargetValues[0] == "Generic")
                        {
                            matcher += "";
                        }
                        else if (genericTargetValues[0] == "Fixed")
                        {
                            matcher += "fixed.+";
                        }
                        else if (genericTargetValues[0] == "Random")
                        {
                            matcher += "random.+";
                        }
                        else if (genericTargetValues[0] == "Atk based")
                        {
                            matcher += "atk.+";
                        }
                        else if (genericTargetValues[0] == "Hp based")
                        {
                            matcher += "hp.+";
                        }
                        else if (genericTargetValues[0] == "Multi-hit")
                        {
                            matcher += "hits.+";
                        }

                        //Damage type
                        if (genericTargetValues[1] == "Generic")
                        {
                            matcher += "";
                        }
                        else if (genericTargetValues[1] == "Typeless")
                        {
                            matcher += "typeless.+";
                        }
                        else
                        {
                            matcher += "\\[" + QString::fromStdString(genericTargetValues[1]) + "\\].+";
                        }

                        //Final target
                        matcher += "to";
                        if (genericTargetValues[2] == "Generic")
                        {
                            matcher += "\\D*enem";
                        }
                        else if (genericTargetValues[2] == "Single")
                        {
                            matcher += " one enemy";
                        }
                        else if (genericTargetValues[2] == "Random")
                        {
                            matcher += " random enemies";
                        }
                        else if (genericTargetValues[2] == "All enemies")
                        {
                            matcher += " all enemies";
                        }

                        //Ignore barrier
                        if (includePlus)
                        {
                            matcher += ".+ignore damage negating abilities and barriers";
                        }

                        //End of turn damage
                        if (includeLimitBreak)
                        {
                            matcher += ".+end of the turn";
                        }
                    }
                }
                else if (secondaryTarget == Condition::Target::ConditionSpecial)
                {
                    if (terziaryTarget == Condition::Target::ReduceDefenseCondition)
                    {
                        matcher = "Reduces the defense\\D*";

                        // Add value
                        QString valueTarget = "by (";
                        valueTarget += QString::fromStdString(getRegexFromValue(value, op));
                        valueTarget += "|\\?)%\\D*";

                        // Add turns
                        QString secondaryValueTarget = "for ";
                        secondaryValueTarget += QString::fromStdString(getRegexFromValue(secondaryValue, secondaryOp));
                        secondaryValueTarget += " turn";

                        matcher += valueTarget + secondaryValueTarget;
                    }
                    else if (terziaryTarget == Condition::Target::PoisonCondition)
                    {
                        matcher = "(?<!Strongly )poisons";
                    }
                    else if (terziaryTarget == Condition::Target::StronglyPoisonCondition)
                    {
                        matcher = "Strongly poisons";
                    }
                    else if (terziaryTarget == Condition::Target::ToxicCondition)
                    {
                        matcher = "Inflicts Toxic";
                    }
                    else if (terziaryTarget == Condition::Target::DelayCondition)
                    {
                        matcher = "Delays\\D*";

                        // Add turns
                        QString valueTarget = "[^,]+(for|by) ";
                        valueTarget += QString::fromStdString(getRegexFromValue(value, op));
                        valueTarget += " turn";

                        matcher += valueTarget;
                    }
                    else
                    {
                        matcher = "Boosts ATK.+against.+";

                        if (terziaryTarget == Condition::Target::ReduceDefenseBoostCondition)
                        {
                            matcher += "enemies.+reduced defense";
                        }
                        else if (terziaryTarget == Condition::Target::IncreasedDefenseBoostCondition)
                        {
                            matcher += "enemies.+increased defense";
                        }
                        else if (terziaryTarget == Condition::Target::DelayBoostCondition)
                        {
                            matcher += "delayed.+enemies";
                        }
                        else if (terziaryTarget == Condition::Target::PoisonBoostCondition)
                        {
                            matcher += "(?<!Strongly )poisoned.+enemies";
                        }
                        else if (terziaryTarget == Condition::Target::StronglyPoisonBoostCondition)
                        {
                            matcher += "Strongly poisoned.+enemies";
                        }
                        else if (terziaryTarget == Condition::Target::ToxicBoostCondition)
                        {
                            matcher += "enemies.+with Toxic";
                        }

                        // Add value
                        QString valueTarget = "\\D*by (";
                        valueTarget += QString::fromStdString(getRegexFromValue(value, op));
                        valueTarget += "|\\?)x\\D*";

                        // Add turns
                        QString secondaryValueTarget = "for ";
                        secondaryValueTarget += QString::fromStdString(getRegexFromValue(secondaryValue, secondaryOp));
                        secondaryValueTarget += " turn";


                        matcher += valueTarget + secondaryValueTarget;
                    }
                }
                else if (secondaryTarget == Condition::Target::OrbManipulationSpecial)
                {
                    if (terziaryTarget == Condition::Target::SwitcherManipulation)
                    {
                        matcher = "switches orbs between slots\\D*";
                        // Add value
                        QString valueTarget = "";
                        valueTarget += QString::fromStdString(getRegexFromValue(value, op));
                        valueTarget += " time";

                        matcher += valueTarget;
                    }
                    else if (terziaryTarget == Condition::Target::ChanceManipulation)
                    {
                        matcher = "boosts chances of getting\\D*";
                        if (genericTargetValues[0] == "Generic")
                        {
                            matcher += "";
                        }
                        else if (genericTargetValues[0] == "Matching")
                        {
                            matcher += "matching";
                        }
                        else
                        {
                            matcher += "\\[" + QString::fromStdString(genericTargetValues[0]) + "\\]";
                        }
                        matcher += "\\D*orbs\\D*";

                        // Add turns
                        QString secondaryValueTarget = "for ";
                        secondaryValueTarget += QString::fromStdString(getRegexFromValue(secondaryValue, secondaryOp));
                        secondaryValueTarget += " turn";
                        matcher += secondaryValueTarget;

                    }
                    else if (terziaryTarget == Condition::Target::ShufflerManipulation)
                    {
                        matcher = "randomizes\\D*";

                        if (genericTargetValues[0] == "Generic")
                        {
                            matcher += "";
                        }
                        else if (genericTargetValues[0] == "All orbs")
                        {
                            matcher += "all";
                        }
                        else if (genericTargetValues[0] == "Non matching")
                        {
                            matcher += "non-matching";
                        }
                        else if (genericTargetValues[0] == "Badly matching")
                        {
                            matcher += "badly matching";
                        }

                        matcher += ".+orb";

                        if (includePlus)
                        {
                            matcher += "\\D*including\\D*BLOCK\\D*orbs";
                        }
                    }
                    else if (terziaryTarget == Condition::Target::BeneficialManipulation)
                    {
                        matcher = "Make\\D*";
                        if (genericTargetValues[0] == "Generic")
                        {
                            matcher += "";
                        }
                        else
                        {
                            matcher += "\\[" + QString::fromStdString(genericTargetValues[0]) + "\\]";
                        }
                        matcher += "\\D*orbs\\D*beneficial\\D*(for|to)\\D*";

                        if (genericTargetValues[1] == "Generic")
                        {
                            matcher += "";
                        }
                        else if (genericTargetValues[1] == "All Characters")
                        {
                            matcher += "all characters";
                        }
                        else
                        {
                            matcher += QString::fromStdString(genericTargetValues[1]);
                        }
                        matcher += "\\D*";

                        // Add turns
                        QString secondaryValueTarget = "for ";
                        secondaryValueTarget += QString::fromStdString(getRegexFromValue(secondaryValue, secondaryOp));
                        secondaryValueTarget += " turn";
                        matcher += secondaryValueTarget;
                    }
                    else if (terziaryTarget == Condition::Target::LockManipulation)
                    {
                        matcher += "locks (orbs|all orbs|orb|own orb)\\D*";
                        // Add turns
                        QString secondaryValueTarget = "for ";
                        secondaryValueTarget += QString::fromStdString(getRegexFromValue(secondaryValue, secondaryOp));
                        secondaryValueTarget += " turn";
                        matcher += secondaryValueTarget;
                    }
                    else if (terziaryTarget == Condition::Target::ControllerManipulation)
                    {
                        // TODO
                        //matcher += "(Empties|Changes).+orb";
                        //matcher += "Changes.+";
                        //matcher = "Changes the orbs in";  // QUESTO ha solo il toString
                        //matcher = "Changes.+all orbs";

                        matcher += "(Changes";

                        QString fromString;
                        bool fromBlock = false;
                        QString alternativeString;
                        if (genericTargetValues[0] == "Generic")
                        {
                            fromString = ".+";
                        }
                        else if (genericTargetValues[0] == "All orbs")
                        {
                            fromString = "[^,]+all orbs";
                            alternativeString = "[^,]+all slots";
                        }
                        else if (genericTargetValues[0] == "Badly matching")
                        {
                            fromString = ".+badly matching orb"; // ha bisogno di into dopo
                        }
                        else if (genericTargetValues[0] == "Own")
                        {
                            fromString = ".+own orb";
                        }
                        else if (genericTargetValues[0] == "Position based")
                        {
                            fromString = ".+the orbs in";
                        }
                        else if (genericTargetValues[0] == "BLOCK")
                        {
                            fromBlock = true;
                            fromString = ".+\\[" + QString::fromStdString(genericTargetValues[0]) + "\\] orbs";
                        }
                        else
                        {
                            fromString = ".+\\[" + QString::fromStdString(genericTargetValues[0]) + "\\] orbs";
                        }

                        QString toString = ".+(to|into)";
                        bool intoEmpty = false;
                        if (genericTargetValues[1] == "Generic")
                        {
                            toString += "";
                            intoEmpty = true;
                        }
                        else if (genericTargetValues[1] == "Matching")
                        {
                            toString += ".+matching orbs";
                        }
                        else if (genericTargetValues[1] == "EMPTY")
                        {
                            intoEmpty = true;
                            toString += ".+\\[" + QString::fromStdString(genericTargetValues[1]) + "\\]";
                        }
                        else
                        {
                            toString += ".+\\[" + QString::fromStdString(genericTargetValues[1]) + "\\]";
                        }

                        QString includeBlock = "";
                        if (includePlus)
                        {
                            if (!fromBlock)
                            {
                                includeBlock = "including.+\\[BLOCK\\]";
                            }
                        }

                        matcher += fromString + includeBlock + toString + ")";

                        if (intoEmpty)
                        {
                            if (alternativeString.size() > 0)
                            {
                                fromString = alternativeString;
                            }

                            if (genericTargetValues[0] != "Generic" && genericTargetValues[0] != "All orbs")
                            {
                                fromString = "[^,]+with" + fromString;
                            }
                            matcher += "|(Empties" + fromString + includeBlock + ")";
                        }
                    }
                }
                std::vector<std::string> special_descriptions = _character->getSpecial()->getDescription();

                QRegularExpression regex(matcher, QRegularExpression::CaseInsensitiveOption);
                for (std::string description : special_descriptions)
                {
                    QRegularExpressionMatch match = regex.match(QString::fromStdString(description));
                    if (match.hasMatch())
                    {
                        conditionMet = true;
                    }
                }
            }
        }
    }
    else if (target == Target::LimitBreak)
    {
        if (_character->hasLimitBreak())
        {
            LimitBreak::Improvements improvements = _character->getLimitBreak()->getAllImprovements();
            if (secondaryTarget == Target::Potential)
            {
                std::vector<Potential*> potentials = improvements.potentials;
                if (op == Operator::Equal)
                {
                    for (Potential* pot : potentials)
                    {
                        if (potentialTarget == pot->getType())
                        {
                            conditionMet = true;
                            break;
                        }
                    }
                }
                else if (op == Operator::Unequal)
                {
                    conditionMet = true;
                    for (Potential* pot : potentials)
                    {
                        if (potentialTarget != pot->getType())
                        {
                            conditionMet = conditionMet && true;
                        }
                        else
                        {
                            conditionMet = conditionMet && false;
                        }
                    }
                }
            }
            else if (secondaryTarget == Target::NewCaptain)
            {
                conditionMet = improvements.new_captain;
            }
            else if (secondaryTarget == Target::NewSailors)
            {
                conditionMet = improvements.new_sailor > 0 ? true : false;
            }
            else if (secondaryTarget == Target::AcquireSocket)
            {
                conditionMet = improvements.socket > 0 ? true : false;
            }
            else if (secondaryTarget == Target::ReduceCd)
            {
                conditionMet = improvements.cd > 0 ? true : false;
            }
        }
    }
    else if (target == Target::MyCharacter)
    {
        if (utility->myCharacters->find(_character->getId()) != utility->myCharacters->end())
        {
            std::vector<MyCharacter*> myCharacters = (*utility->myCharacters)[_character->getId()];
            for (MyCharacter* thisCharacter : myCharacters)
            {
                if (secondaryTarget == Target::MyLevel)
                {
                    if (!includeWantToFinish || thisCharacter->getWantToFinishLevel())
                    {
                        conditionMet = conditionMet || numericConditionMet(value, thisCharacter->getLevel());
                    }
                }
                else if (secondaryTarget == Target::MySkill)
                {
                    if (!includeWantToFinish || thisCharacter->getWantToFinishSkill())
                    {
                        bool skillMax = thisCharacter->getSkillLevel() == _character->getSpecial()->getMaxLevel();

                        if (terziaryTarget == Target::NotFinished)
                        {
                            conditionMet = conditionMet || !skillMax;
                        }
                        else if (terziaryTarget == Target::Finished)
                        {
                            conditionMet = conditionMet || skillMax;
                        }
                    }
                }
                else if (secondaryTarget == Target::MyCotton)
                {
                    if (!includeWantToFinish || thisCharacter->getWantToFinishCotton())
                    {
                        std::vector<short> cc = thisCharacter->getCC();
                        if (terziaryTarget == Target::Have)
                        {
                            conditionMet = conditionMet || (cc[0] != 0 || cc[1] != 0 || cc[2] != 0);
                        }
                        else if (terziaryTarget == Target::NotHave)
                        {
                            conditionMet = conditionMet || (cc[0] == 0 && cc[1] == 0 && cc[2] == 0);
                        }
                        else if (terziaryTarget == Target::Finished)
                        {
                            conditionMet = conditionMet || (cc[0] + cc[1] + cc[2] == 200);
                        }
                        else if (terziaryTarget == Target::NotFinished)
                        {
                            conditionMet = conditionMet || (cc[0] + cc[1] + cc[2] != 200);
                        }
                        else if (terziaryTarget == Target::CottonHp)
                        {
                            conditionMet = conditionMet || numericConditionMet(value, cc[0]);
                        }
                        else if (terziaryTarget == Target::CottonAtk)
                        {
                            conditionMet = conditionMet || numericConditionMet(value, cc[1]);
                        }
                        else if (terziaryTarget == Target::CottonRcv)
                        {
                            conditionMet = conditionMet || numericConditionMet(value, cc[2]);
                        }
                    }
                }
                else if (secondaryTarget == Target::MySockets)
                {
                    if (!includeWantToFinish || thisCharacter->getWantToFinishSockets())
                    {
                        if (terziaryTarget == Condition::Target::Finished)
                        {
                            std::vector<Socket> missingSockets = thisCharacter->missingSocketPoints();
                            bool zeroNeeded = true;
                            for (Socket& socket : missingSockets)
                            {
                                zeroNeeded = zeroNeeded && (socket.getValue() == 0);
                            }
                            conditionMet = conditionMet || zeroNeeded;
                        }
                        else if (terziaryTarget == Condition::Target::NotFinished)
                        {
                            std::vector<Socket> missingSockets = thisCharacter->missingSocketPoints();
                            int numMissing = 0;
                            for (Socket& socket : missingSockets)
                            {
                                numMissing += socket.getValue();
                            }
                            conditionMet = conditionMet || (numMissing > 0);
                        }
                        else
                        {
                            std::vector<Socket> currentSocket = thisCharacter->getSockets();
                            for (Socket socket : currentSocket)
                            {
                                if (socketTarget == socket.getType())
                                {
                                    conditionMet = conditionMet || numericConditionMet(value, socket.getValue());
                                    break;
                                }
                            }
                        }
                    }
                }
                else if (secondaryTarget == Target::MyTrainingPoints)
                {
                    if (_character->hasLimitBreak())
                    {
                        if (!includeWantToFinish || thisCharacter->getWantToFinishLimitBreak())
                        {
                            int maxTrainingPoints = _character->getLimitBreak()->getMaxTrainingPoints();
                            if (terziaryTarget == Target::NotFinished)
                            {
                                conditionMet = conditionMet || (thisCharacter->getTrainingPoints() != maxTrainingPoints);
                            }
                            else if (terziaryTarget == Target::Finished)
                            {
                                conditionMet = conditionMet || (thisCharacter->getTrainingPoints() == maxTrainingPoints);
                            }
                        }
                    }
                }
                else if (secondaryTarget == Target::MyPotentials)
                {
                    if (_character->hasLimitBreak())
                    {
                        if (!includeWantToFinish || thisCharacter->getWantToFinishLimitBreak())
                        {
                            std::vector<Potential> currentPotentials = thisCharacter->getPotential();
                            std::vector<Potential*> maxPotentials = _character->getLimitBreak()->getAllImprovements().potentials;
                            if (terziaryTarget == Condition::Target::Finished)
                            {
                                bool finished = currentPotentials.size() == maxPotentials.size();
                                for (Potential& potential : currentPotentials)
                                {
                                    finished = finished && (potential.getValue() == 5);
                                }
                                conditionMet = conditionMet || finished;
                            }
                            else if (terziaryTarget == Condition::Target::NotFinished)
                            {
                                bool finished = currentPotentials.size() == maxPotentials.size();
                                for (Potential& potential : currentPotentials)
                                {
                                    finished = finished && (potential.getValue() == 5);
                                }
                                conditionMet = conditionMet || !finished;
                            }
                            else
                            {
                                for (Potential& potential : currentPotentials)
                                {
                                    if (potential.getType() == potentialTarget)
                                    {
                                        conditionMet = conditionMet || numericConditionMet(value, potential.getValue());
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            conditionMet = false;
        }
    }
    else if (target == Target::Availability)
    {
        std::set<Availability> availabilities = _character->getAvailabilities();
        if (op == Operator::Equal)
        {
            if (availabilities.find(availabilityValue) != availabilities.end())
            {
                conditionMet = true;
            }
        }
        else if (op == Operator::Unequal)
        {
            conditionMet = true;
            if (availabilities.find(availabilityValue) != availabilities.end())
            {
                conditionMet = false;
            }
        }
    }

    return conditionMet;
}


std::string Condition::getDescriptionFromTarget(Target _macroTarget, Target _target)
{
    return targetToDescriptionMap[_macroTarget][_target];
}

Condition::Target Condition::getTargetFromDescription(Target _macroTarget, std::string _description)
{
    return descriptionToTargetMap[_macroTarget][_description];
}

std::string Condition::getDescriptionFromOperator(Operator _operator)
{
    return operatorToDescriptionMap[_operator];
}

Condition::Operator Condition::getOperatorFromDescription(std::string _description)
{
    return descriptionToOperatorMap[_description];
}

std::vector<std::string> Condition::getPossibleOperators(Target _target)
{
    std::vector<std::string> operators;
    operators.push_back(getDescriptionFromOperator(Operator::Equal));
    operators.push_back(getDescriptionFromOperator(Operator::Unequal));
    if (targetToPossibleOperations[_target] == "Integer" || targetToPossibleOperations[_target] == "Decimal")
    {
        operators.push_back(getDescriptionFromOperator(Operator::Greater));
        operators.push_back(getDescriptionFromOperator(Operator::GreaterEqual));
        operators.push_back(getDescriptionFromOperator(Operator::Less));
        operators.push_back(getDescriptionFromOperator(Operator::LessEqual));
    }
    return operators;
}

std::string Condition::getPossibleOperationsTypeFromTarget(Target _target)
{
    return targetToPossibleOperations[_target];
}


bool Condition::numericConditionMet(std::string _currentValue, int _valueToCheck)
{
    if (_currentValue == "")
    {
        _currentValue = "0";
    }

    int conditionValue = std::stoi(_currentValue);
    if (op == Operator::Equal)
    {
        if (_valueToCheck == conditionValue)
        {
            return true;
        }
    }
    else if (op == Operator::Unequal)
    {
        if (_valueToCheck != conditionValue)
        {
            return true;
        }
    }
    else if (op == Operator::Greater)
    {
        if (_valueToCheck > conditionValue)
        {
            return true;
        }
    }
    else if (op == Operator::GreaterEqual)
    {
        if (_valueToCheck >= conditionValue)
        {
            return true;
        }
    }
    else if (op == Operator::Less)
    {
        if (_valueToCheck < conditionValue)
        {
            return true;
        }
    }
    else if (op <= Operator::LessEqual)
    {
        if (_valueToCheck <= conditionValue)
        {
            return true;
        }
    }
    return false;
}

std::string Condition::getRegexFromValue(std::string _value, Operator _op)
{
    std::vector<short> integerPart;
    std::vector<short> fractionalPart;
    bool parsingInteger = true;
    for (char c : _value)
    {
        if (c == '.')
        {
            parsingInteger = false;
            continue;
        }
        else
        {
            short value = c - '0';
            if (parsingInteger)
            {
                integerPart.push_back(value);
            }
            else
            {
                fractionalPart.push_back(value);
            }
        }
    }

    if (integerPart.empty())
    {
        integerPart.push_back(0);
    }
    std::string integerString;
    std::string fractionalString;

    for (unsigned int i = 0; i < integerPart.size(); ++i)
    {
        integerString += std::to_string(integerPart[i]);
    }

    for (unsigned int i = 0; i < fractionalPart.size(); ++i)
    {
        fractionalString += std::to_string(fractionalPart[i]);
    }

    std::string regex = "(";
    if (_op == Operator::Greater || _op == Operator::GreaterEqual || _op == Operator::Unequal)
    {
        // Regex greater than the last decimal digit. Starting with zero
        regex += integerString + "\\." + fractionalString + "[0]+[1-9]+";

        // Regex greater than the last decimal digit. Starting with one to nine
        regex += "|" + integerString + "\\." + fractionalString + "[1-9]+[0-9]*";

        // Regex greater than one or more magnitude higher than integer part.
        regex += "|[1-9]";
        for (unsigned int i = 0; i < integerPart.size() - 1; ++i)
        {
            regex += "[0-9]";
        }
        regex += "[0-9]+\\.?[0-9]*";

        // Regex greater than the integer part.
        for (int i = 0; i < static_cast<int>(integerPart.size()); ++i)
        {
            if (integerPart[static_cast<unsigned int>(i)] != 9)
            {
                regex += "|";
                for (int j = 0; j < i; ++j)
                {
                    regex += std::to_string(integerPart[static_cast<unsigned int>(j)]);
                }

                regex += "[" + std::to_string(integerPart[static_cast<unsigned int>(i)] + 1) + "-9]";

                for (int j = i + 1; j < static_cast<int>(integerPart.size()); ++j)
                {
                    regex += "[0-9]";
                }

                regex += "\\.?[0-9]*";
            }
        }

        // Regex greater than the decimal part.
        for (unsigned int i = 0; i < fractionalPart.size(); ++i)
        {
            if (fractionalPart[i] != 9)
            {
                regex += "|" + integerString + "\\.";

                // Add fractional part before as is
                for (unsigned int j = 0; j < i; ++j)
                {
                    regex += std::to_string(fractionalPart[j]);
                }

                regex += "[" + std::to_string(fractionalPart[i] + 1) + "-9]";
                regex += "[0-9]*";
            }
        }
    }

    if (_op == Operator::Unequal)
    {
        regex += "|";
    }

    if (_op == Operator::Less || _op == Operator::LessEqual || _op == Operator::Unequal)
    {
        regex += "0";

        //Regex lesser than integer
        for (int i = static_cast<int>(integerPart.size()) - 1; i >= 0; --i)
        {
            if (integerPart[static_cast<unsigned int>(i)] != 0)
            {
                if (!(i == 0 && integerPart[static_cast<unsigned int>(i)] == 1))
                {
                    std::string noFraction;
                    for (int j = 0; j < i; ++j)
                    {
                        noFraction += std::to_string(integerPart[static_cast<unsigned int>(j)]);
                    }
                    noFraction += "[0-" + std::to_string(integerPart[static_cast<unsigned int>(i)] - 1) + "]";

                    for (int j = i + 1; j < static_cast<int>(integerPart.size()); ++j)
                    {
                        noFraction += "[0-9]";
                    }

                    regex += "|" + noFraction;
                    regex += "|" + noFraction + "\\.[0-9]*";
                }
            }
        }

        //Regex with less integer size
        for (unsigned int i = 1; i < integerPart.size(); ++i)
        {
            std::string noFraction;

            noFraction += "[0-9]";
            for (unsigned int j = i + 1; j < integerPart.size(); ++j)
            {
                noFraction += "[0-9]";
            }
            regex += "|" + noFraction;
            regex += "|" + noFraction + "\\.[0-9]*";
        }


        // Regex lesser than fractional
        for (int j = static_cast<int>(fractionalPart.size()) - 1; j >= 0; --j)
        {
            regex += "|";

            regex += integerString + "\\.";
            for (int i = 0; i < j; ++i)
            {
                regex += std::to_string(fractionalPart[static_cast<unsigned int>(i)]);
            }
            regex += "[0-" + std::to_string(fractionalPart[static_cast<unsigned int>(j)] - 1) + "][0-9]*";
        }

        // Regex integer without fractional part
        if (!fractionalPart.empty())
        {
            regex += "|" + integerString;
        }
    }

    if (_op == Operator::Equal || _op == Operator::GreaterEqual || _op == Operator::LessEqual)
    {
        if (_op == Operator::Equal)
        {
            regex += _value;
        }
        else
        {
            regex += "|" + _value;
        }
    }

    regex += ")";
    return regex;
}


Type Condition::getTypeTarget()
{
    return typeTarget;
}

Class Condition::getClassTarget()
{
    return classTarget;
}

void Condition::setTypeTarget(Type _type)
{
    typeTarget = _type;
    typeTargetSet = true;
}

void Condition::setClassTarget(Class _class)
{
    classTarget = _class;
    classTargetSet = true;
}

void Condition::setAvailabilityTarget(Availability _availabilityTarget)
{
    availabilityValue = _availabilityTarget;
}

Availability Condition::getAvailabilityTarget()
{
    return availabilityValue;
}

Slots Condition::getSlotTarget()
{
    return slotTarget;
}

void Condition::setSlotsTarget(Slots _slotsTarget)
{
    slotTarget = _slotsTarget;
}











Filter::Filter(Utility* _utility) :
    utility(_utility)
{
    std::vector<Character*> characters = *utility->characters;
    for (Character* character : characters)
    {
        charactersMap[character->getId()] = character;
    }
}

void Filter::addAndCondition(Condition _condition)
{
    if (*_condition.getTarget() != Condition::Target::PrimaryTargets)
    {
        andConditions.push_back(_condition);
    }
}

void Filter::addOrCondition(Filter _filter)
{
    orConditions.push_back(_filter);
}

std::set<int> Filter::filter(std::set<int> _ids)
{
    // Filtering by andConditions gives stricter set
    for (Condition condition : andConditions)
    {
        for (std::set<int>::iterator iterator = _ids.begin(); iterator != _ids.end(); )
        {
            int id = *iterator;
            if (!condition.isMet(charactersMap[id]))
            {
                iterator = _ids.erase(iterator);
                continue;
            }
            else
            {
                iterator++;
            }
        }
    }

    // Get all subsets from orConditions
    std::set<int> filteredIds;
    for (Filter filt : orConditions)
    {
        std::set<int> tmpFiltered = filt.filter(_ids);
        filteredIds.insert(tmpFiltered.begin(), tmpFiltered.end());
    }

    // Add only and conditions if no orConditions were set
    if (orConditions.empty())
    {
        filteredIds = _ids;
    }

    return filteredIds;
}

void Filter::resetFilters()
{
    andConditions.clear();
    orConditions.clear();
}

void Filter::setId(std::string _id)
{
    id = _id;
}

std::string Filter::getId()
{
    return id;
}

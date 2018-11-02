#include <conditionWidget.h>
#include "ui_conditionWidget.h"
#include <QDoubleValidator>
#include <cctype>
#include <algorithm>
#include <string>

ConditionWidget::ConditionWidget(Utility* _utility, QWidget *_parent) :
    QWidget(_parent),
    ui(new Ui::ConditionWidget),
    utility(_utility),
    dummy(new Condition(_utility, "Dummy", Condition::Target::EndPrimaryTargets, Condition::Operator::NumOperators, "0"))
{
    ui->setupUi(this);
    ui->primaryTargetBox->setEnabled(false);
    ui->secondaryTargetBox->hide();
    ui->operatorBox->hide();
    ui->numericValueEdit->hide();
    ui->stringValueEdit->hide();
    ui->includeLimitBreak->hide();
    ui->genericValueBox->hide();
    ui->terziaryTargetBox->hide();
    ui->includePlus->hide();

    for (int i = static_cast<int>(Condition::Target::PrimaryTargets); i < static_cast<int>(Condition::Target::EndPrimaryTargets); ++i)
    {
        std::string target = dummy->getDescriptionFromTarget(Condition::Target::PrimaryTargets, static_cast<Condition::Target>(i));
        QString targetString(QString::fromStdString(target));
        ui->primaryTargetBox->addItem(targetString);
    }

    loadIcons();
}

ConditionWidget::~ConditionWidget()
{
    delete ui;
}

void ConditionWidget::enableWidget()
{
    ui->primaryTargetBox->setEnabled(true);
}

void ConditionWidget::on_primaryTargetBox_currentIndexChanged(const QString &_text)
{
    std::string target = _text.toUtf8().constData();

    ui->includePlus->hide();
    ui->boolTarget->hide();
    ui->includeLimitBreak->hide();
    ui->includeWantToFinish->hide();
    ui->secondaryTargetBox->hide();
    ui->terziaryTargetBox->hide();
    ui->quaternaryTargetBox->hide();
    ui->operatorBox->hide();
    ui->secondaryOperatorBox->hide();
    ui->genericValueBox->hide();
    ui->intoLabel->hide();
    ui->turnsLabel->hide();
    ui->numericValueEdit->hide();
    ui->stringValueEdit->hide();
    ui->secondaryNumericValueEdit->hide();
    ui->finalTargetBox->hide();
    ui->endOfTurn->hide();

    if (_text != "")
    {
        Condition::Target primaryTarget = dummy->getTargetFromDescription(Condition::Target::PrimaryTargets, target);
        if (primaryTarget == Condition::Target::Stats)
        {
            ui->secondaryTargetBox->clear();
            ui->secondaryTargetBox->show();

            ui->numericValueEdit->clear();
            ui->numericValueEdit->setText("0");
            ui->numericValueEdit->show();

            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(primaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();
            for (int i = static_cast<int>(Condition::Target::StatsTargets) + 1; i < static_cast<int>(Condition::Target::EndStatsTargets); ++i)
            {
                std::string secondaryTarget = dummy->getDescriptionFromTarget(Condition::Target::Stats, static_cast<Condition::Target>(i));
                QString targetString(QString::fromStdString(secondaryTarget));
                ui->secondaryTargetBox->addItem(targetString);
            }
        }
        else if (primaryTarget == Condition::Target::Slots)
        {
            ui->includeWantToFinish->setChecked(false);
            ui->includeLimitBreak->show();

            ui->numericValueEdit->clear();
            ui->numericValueEdit->setText("0");
            ui->numericValueEdit->show();

            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(primaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();
        }
        else if (primaryTarget == Condition::Target::Type || primaryTarget == Condition::Target::Class || primaryTarget == Condition::Target::PrimaryClass || primaryTarget == Condition::Target::SecondaryClass)
        {
            ui->genericValueBox->clear();
            ui->genericValueBox->show();

            if (primaryTarget == Condition::Target::Type)
            {
                for (int i = static_cast<int>(Type::StartType) + 1; i < static_cast<int>(Type::EndTypes); ++i)
                {
                    QString typeString(QString::fromStdString(to_string(static_cast<Type>(i))));
                    ui->genericValueBox->addItem(typeToIcon[static_cast<Type>(i)], typeString);
                }
            }
            else
            {
                for (int i = static_cast<int>(Class::StartClass) + 1; i < static_cast<int>(Class::EndClasses); ++i)
                {
                    QString classString(QString::fromStdString(to_string(static_cast<Class>(i))));
                    ui->genericValueBox->addItem(classToIcon[static_cast<Class>(i)], classString);
                }
            }

            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(primaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();
        }
        else if (primaryTarget == Condition::Target::Captain)
        {
            ui->secondaryTargetBox->clear();
            ui->secondaryTargetBox->show();

            for (int i = static_cast<int>(Condition::Target::CaptainTargets) + 1; i < static_cast<int>(Condition::Target::EndCaptainTargets); ++i)
            {
                std::string secondaryTarget = dummy->getDescriptionFromTarget(Condition::Target::Captain, static_cast<Condition::Target>(i));
                QString targetString(QString::fromStdString(secondaryTarget));
                ui->secondaryTargetBox->addItem(targetString);
            }
        }
        else if (primaryTarget == Condition::Target::Evolution)
        {
            ui->secondaryTargetBox->clear();
            ui->secondaryTargetBox->show();
            for (int i = static_cast<int>(Condition::Target::EvolutionTargets) + 1; i < static_cast<int>(Condition::Target::EndEvolutionTargets); ++i)
            {
                std::string secondaryTarget = dummy->getDescriptionFromTarget(Condition::Target::Evolution, static_cast<Condition::Target>(i));
                QString targetString(QString::fromStdString(secondaryTarget));
                ui->secondaryTargetBox->addItem(targetString);
            }
        }
        else if (primaryTarget == Condition::Target::LimitBreak)
        {
            ui->secondaryTargetBox->clear();
            ui->secondaryTargetBox->show();
            for (int i = static_cast<int>(Condition::Target::LimitBreakTargets) + 1; i < static_cast<int>(Condition::Target::EndLimitBreakTargets); ++i)
            {
                std::string secondaryTarget = dummy->getDescriptionFromTarget(Condition::Target::LimitBreak, static_cast<Condition::Target>(i));
                QString targetString(QString::fromStdString(secondaryTarget));
                ui->secondaryTargetBox->addItem(targetString);
            }
        }
        else if (primaryTarget == Condition::Target::Availability)
        {
            ui->genericValueBox->clear();
            ui->genericValueBox->show();

            for (int i = static_cast<int>(Availability::StartAvailability) + 1; i < static_cast<int>(Availability::EndAvailability); ++i)
            {
                std::string secondaryTarget = to_string((static_cast<Availability>(i)));
                QString targetString(QString::fromStdString(secondaryTarget));
                ui->genericValueBox->addItem(targetString);
            }

            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(primaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();
        }
        else if (primaryTarget == Condition::Target::Sailor)
        {
            ui->includeLimitBreak->setChecked(false);
            ui->includeLimitBreak->show();
            ui->secondaryTargetBox->clear();
            ui->secondaryTargetBox->show();

            for (int i = static_cast<int>(Condition::Target::SailorTargets) + 1; i < static_cast<int>(Condition::Target::EndSailorTargets); ++i)
            {
                std::string secondaryTarget = dummy->getDescriptionFromTarget(Condition::Target::Sailor, static_cast<Condition::Target>(i));
                QString targetString(QString::fromStdString(secondaryTarget));
                ui->secondaryTargetBox->addItem(targetString);
            }
        }
        else if (primaryTarget == Condition::Target::Special)
        {
            ui->secondaryTargetBox->clear();
            for (int i = static_cast<int>(Condition::Target::SpecialTargets) + 1; i < static_cast<int>(Condition::Target::EndSpecialTargets); ++i)
            {
                std::string secondaryTarget = dummy->getDescriptionFromTarget(Condition::Target::Special, static_cast<Condition::Target>(i));
                QString targetString(QString::fromStdString(secondaryTarget));
                ui->secondaryTargetBox->addItem(targetString);
            }
            ui->secondaryTargetBox->show();
        }
        else if (primaryTarget == Condition::Target::MyCharacter)
        {
            ui->secondaryTargetBox->clear();
            ui->secondaryTargetBox->show();
            ui->includeWantToFinish->setChecked(false);
            ui->includeWantToFinish->show();

            ui->numericValueEdit->clear();
            ui->numericValueEdit->setText("0");
            ui->numericValueEdit->show();

            for (int i = static_cast<int>(Condition::Target::MyCharacterTargets) + 1; i < static_cast<int>(Condition::Target::EndMyCharacterTargets); ++i)
            {
                std::string secondaryTarget = dummy->getDescriptionFromTarget(Condition::Target::MyCharacter, static_cast<Condition::Target>(i));
                QString targetString(QString::fromStdString(secondaryTarget));
                ui->secondaryTargetBox->addItem(targetString);
            }
        }
        else if (primaryTarget == Condition::Target::Tandem)
        {
            // Do not show anything
        }
        else if (primaryTarget == Condition::Target::Name)
        {
            ui->stringValueEdit->clear();
            ui->stringValueEdit->show();

            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(primaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();
        }
        else
        {
            ui->numericValueEdit->clear();
            ui->numericValueEdit->setText("0");
            ui->numericValueEdit->show();

            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(primaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();
        }
    }
}

void ConditionWidget::on_secondaryTargetBox_currentIndexChanged(const QString &_text)
{
    std::string target = _text.toUtf8().constData();

    ui->includeLimitBreak->hide();
    ui->boolTarget->hide();
    ui->terziaryTargetBox->hide();
    ui->quaternaryTargetBox->hide();
    ui->genericValueBox->hide();
    ui->secondaryOperatorBox->hide();
    ui->secondaryNumericValueEdit->hide();
    ui->intoLabel->hide();
    ui->turnsLabel->hide();
    ui->numericValueEdit->hide();
    ui->operatorBox->hide();
    ui->finalTargetBox->hide();
    ui->endOfTurn->hide();

    if (_text != "")
    {
        Condition::Target primaryTarget = dummy->getTargetFromDescription(Condition::Target::PrimaryTargets, ui->primaryTargetBox->currentText().toUtf8().constData());
        Condition::Target secondaryTarget = dummy->getTargetFromDescription(primaryTarget, target);
        if (secondaryTarget == Condition::Target::maxHp || secondaryTarget == Condition::Target::maxAtk || secondaryTarget == Condition::Target::maxRcv ||
                secondaryTarget == Condition::Target::minHp || secondaryTarget == Condition::Target::minAtk || secondaryTarget == Condition::Target::minRcv)
        {
            ui->numericValueEdit->clear();
            ui->numericValueEdit->setText("0");
            ui->numericValueEdit->show();

            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(primaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();

            if (secondaryTarget == Condition::Target::maxHp || secondaryTarget == Condition::Target::maxAtk || secondaryTarget == Condition::Target::maxRcv)
            {
                ui->includeLimitBreak->setChecked(false);
                ui->includeLimitBreak->show();
            }
        }
        else if (secondaryTarget == Condition::Target::Potential)
        {
            ui->genericValueBox->clear();
            ui->genericValueBox->show();

            for (int i = static_cast<int>(Potential::Type::StartPotential) + 1; i < static_cast<int>(Potential::Type::None); ++i)
            {
                Potential dummyPotential(Potential::Type::None, 1);
                std::string potentialTarget = dummyPotential.getDescriptionFromType((static_cast<Potential::Type>(i)));
                QString potentialString(QString::fromStdString(potentialTarget));
                ui->genericValueBox->addItem(potentialToIcon[static_cast<Potential::Type>(i)], potentialString);
            }

            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(primaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();
        }
        else if (secondaryTarget == Condition::Target::HPBoostCaptain || secondaryTarget == Condition::Target::ATKBoostCaptain || secondaryTarget == Condition::Target::RCVBoostCaptain)
        {
            ui->terziaryTargetBox->clear();
            ui->terziaryTargetBox->show();
            ui->terziaryTargetBox->addItem("Generic");
            ui->terziaryTargetBox->addItem("All Characters");

            ui->numericValueEdit->clear();
            ui->numericValueEdit->setText("0");
            ui->numericValueEdit->show();

            // Add all types and classes
            for (int i = static_cast<int>(Type::StartType) + 1; i < static_cast<int>(Type::EndTypes); ++i)
            {
                QString typeString(QString::fromStdString(to_string(static_cast<Type>(i))));
                ui->terziaryTargetBox->addItem(typeToIcon[static_cast<Type>(i)], typeString);
            }
            for (int i = static_cast<int>(Class::StartClass) + 1; i < static_cast<int>(Class::None); ++i)
            {
                QString classString(QString::fromStdString(to_string(static_cast<Class>(i))));
                ui->terziaryTargetBox->addItem(classToIcon[static_cast<Class>(i)], classString);
            }

            // Add operators
            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(primaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();
        }
        else if (secondaryTarget == Condition::Target::HealerCaptain)
        {
            ui->terziaryTargetBox->clear();
            ui->terziaryTargetBox->show();
            ui->terziaryTargetBox->addItem("Rcv based");
            ui->terziaryTargetBox->addItem("Other");
        }
        else if (secondaryTarget == Condition::Target::BeliBoosterCaptain || secondaryTarget == Condition::Target::ExpBoosterCaptain || secondaryTarget == Condition::Target::CdReducerCaptain || secondaryTarget == Condition::Target::DamageReducerCaptain)
        {
            ui->numericValueEdit->clear();
            ui->numericValueEdit->setText("0");
            ui->numericValueEdit->show();

            // Add operators
            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(primaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();
        }
        else if (secondaryTarget == Condition::Target::BoostHPSailor || secondaryTarget == Condition::Target::BoostATKSailor || secondaryTarget == Condition::Target::BoostRCVSailor)
        {
            ui->includeLimitBreak->setChecked(false);
            ui->includeLimitBreak->show();

            ui->terziaryTargetBox->clear();
            ui->terziaryTargetBox->show();

            ui->terziaryTargetBox->addItem("Generic");
            ui->terziaryTargetBox->addItem("All Characters");
            // Add all types and classes
            for (int i = static_cast<int>(Type::StartType) + 1; i < static_cast<int>(Type::EndTypes); ++i)
            {
                QString typeString(QString::fromStdString(to_string(static_cast<Type>(i))));
                ui->terziaryTargetBox->addItem(typeToIcon[static_cast<Type>(i)], typeString);
            }
            ui->terziaryTargetBox->addItem("Dominant Type");
            for (int i = static_cast<int>(Class::StartClass) + 1; i < static_cast<int>(Class::None); ++i)
            {
                QString classString(QString::fromStdString(to_string(static_cast<Class>(i))));
                ui->terziaryTargetBox->addItem(classToIcon[static_cast<Class>(i)], classString);
            }
        }
        else if (secondaryTarget == Condition::Target::ParalysisReducer || secondaryTarget == Condition::Target::BlindnessReducer || secondaryTarget == Condition::Target::SilenceReducer ||
                 secondaryTarget == Condition::Target::SpecialRewindReducer || secondaryTarget == Condition::Target::SpecialCdSailor || secondaryTarget == Condition::Target::BlownAway || secondaryTarget == Condition::Target::AdditionalDamageSailor)
        {
            ui->includeLimitBreak->setChecked(false);
            ui->includeLimitBreak->show();
        }
        else if (secondaryTarget == Condition::Target::OrbKeeper || secondaryTarget == Condition::Target::BeneficialOrb)
        {
            ui->includeLimitBreak->setChecked(false);
            ui->includeLimitBreak->show();


            ui->terziaryTargetBox->clear();
            ui->terziaryTargetBox->show();

            ui->terziaryTargetBox->addItem("Generic");
            // Add all types and classes
            for (int i = static_cast<int>(Slots::StartSlots) + 1; i < static_cast<int>(Slots::EndSlots); ++i)
            {
                std::string slot = to_string(static_cast<Slots>(i));
                QString slotString(QString::fromStdString(slot));
                ui->terziaryTargetBox->addItem(slotString);
            }

            if (secondaryTarget == Condition::Target::OrbKeeper)
            {
                ui->genericValueBox->clear();
                ui->genericValueBox->addItem("Generic");
                ui->genericValueBox->addItem("Good");
                ui->genericValueBox->addItem("Great");
                ui->genericValueBox->addItem("Perfect");
                ui->genericValueBox->show();
            }
            else
            {
                ui->genericValueBox->clear();
                ui->genericValueBox->addItem("Self");
                ui->genericValueBox->addItem("All Characters");
                // Add all types and classes
                for (int i = static_cast<int>(Type::StartType) + 1; i < static_cast<int>(Type::EndTypes); ++i)
                {
                    QString typeString(QString::fromStdString(to_string(static_cast<Type>(i))));
                    ui->genericValueBox->addItem(typeToIcon[static_cast<Type>(i)], typeString);
                }
                for (int i = static_cast<int>(Class::StartClass) + 1; i < static_cast<int>(Class::None); ++i)
                {
                    QString classString(QString::fromStdString(to_string(static_cast<Class>(i))));
                    ui->genericValueBox->addItem(classToIcon[static_cast<Class>(i)], classString);
                }
                ui->genericValueBox->show();
            }
        }
        else if (secondaryTarget == Condition::Target::MyLevel)
        {
            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(primaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();

            ui->numericValueEdit->clear();
            ui->numericValueEdit->setText("0");
            ui->numericValueEdit->show();
        }
        else if (secondaryTarget == Condition::Target::MySkill || secondaryTarget == Condition::Target::MyTrainingPoints)
        {
            ui->terziaryTargetBox->clear();
            ui->terziaryTargetBox->addItem(QString::fromStdString(dummy->getDescriptionFromTarget(Condition::Target::OtherTargets, Condition::Target::Finished)));
            ui->terziaryTargetBox->addItem(QString::fromStdString(dummy->getDescriptionFromTarget(Condition::Target::OtherTargets, Condition::Target::NotFinished)));
            ui->terziaryTargetBox->show();
        }
        else if (secondaryTarget == Condition::Target::MyCotton)
        {
            ui->terziaryTargetBox->clear();
            for (int i = static_cast<int>(Condition::Target::OtherTargets) + 1; i < static_cast<int>(Condition::Target::EndOtherTargets); ++i)
            {
                std::string terziaryTarget = dummy->getDescriptionFromTarget(Condition::Target::OtherTargets, static_cast<Condition::Target>(i));
                QString targetString(QString::fromStdString(terziaryTarget));
                ui->terziaryTargetBox->addItem(targetString);
            }
            ui->terziaryTargetBox->show();
        }
        else if (secondaryTarget == Condition::Target::MySockets)
        {
            ui->terziaryTargetBox->clear();
            ui->terziaryTargetBox->addItem(QString::fromStdString(dummy->getDescriptionFromTarget(Condition::Target::OtherTargets, Condition::Target::Finished)));
            ui->terziaryTargetBox->addItem(QString::fromStdString(dummy->getDescriptionFromTarget(Condition::Target::OtherTargets, Condition::Target::NotFinished)));
            for (int i = static_cast<int>(Socket::Type::Dmr); i < static_cast<int>(Socket::Type::None); ++i)
            {
                std::string terziaryTarget = to_string(static_cast<Socket::Type>(i));
                QString targetString(QString::fromStdString(terziaryTarget));
                ui->terziaryTargetBox->addItem(targetString);
            }
            ui->terziaryTargetBox->show();
        }
        else if (secondaryTarget == Condition::Target::MyPotentials)
        {
            ui->terziaryTargetBox->clear();
            ui->terziaryTargetBox->addItem(QString::fromStdString(dummy->getDescriptionFromTarget(Condition::Target::OtherTargets, Condition::Target::Finished)));
            ui->terziaryTargetBox->addItem(QString::fromStdString(dummy->getDescriptionFromTarget(Condition::Target::OtherTargets, Condition::Target::NotFinished)));
            for (int i = static_cast<int>(Potential::Type::StartPotential) + 1; i < static_cast<int>(Potential::Type::None); ++i)
            {
                Potential dummyPotential(Potential::Type::None, 1);
                std::string potentialTarget = dummyPotential.getDescriptionFromType((static_cast<Potential::Type>(i)));
                QString potentialString(QString::fromStdString(potentialTarget));
                ui->terziaryTargetBox->addItem(potentialToIcon[static_cast<Potential::Type>(i)], potentialString);
            }
            ui->terziaryTargetBox->show();
        }
        else if (secondaryTarget == Condition::Target::ATKBoostSpecial || secondaryTarget == Condition::Target::OrbBoostSpecial || secondaryTarget == Condition::Target::ColorAffinitySpecial)
        {
            ui->terziaryTargetBox->clear();
            ui->terziaryTargetBox->addItem("Generic");
            ui->terziaryTargetBox->addItem("All Characters");
            for (int i = static_cast<int>(Type::StartType) + 1; i < static_cast<int>(Type::EndTypes); ++i)
            {
                QString typeString(QString::fromStdString(to_string(static_cast<Type>(i))));
                ui->terziaryTargetBox->addItem(typeToIcon[static_cast<Type>(i)], typeString);
            }
            ui->terziaryTargetBox->addItem("Dominant Type");
            for (int i = static_cast<int>(Class::StartClass) + 1; i < static_cast<int>(Class::None); ++i)
            {
                QString classString(QString::fromStdString(to_string(static_cast<Class>(i))));
                ui->terziaryTargetBox->addItem(classToIcon[static_cast<Class>(i)], classString);
            }
            ui->terziaryTargetBox->show();

            // Add operators
            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(secondaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();

            ui->numericValueEdit->clear();
            ui->numericValueEdit->setText("0");
            ui->numericValueEdit->show();

            // Add secondary operators
            ui->turnsLabel->show();
            ui->secondaryOperatorBox->clear();
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->secondaryOperatorBox->addItem(opText);
            }
            ui->secondaryOperatorBox->show();
            ui->secondaryNumericValueEdit->clear();
            ui->secondaryNumericValueEdit->setText("0");
            ui->secondaryNumericValueEdit->show();
        }
        else if (secondaryTarget == Condition::Target::MinCooldownSpecial || secondaryTarget == Condition::Target::NumStagesSpecial)
        {
            // Add operators
            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(secondaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();

            ui->numericValueEdit->clear();
            ui->numericValueEdit->setText("0");
            ui->numericValueEdit->show();

            if (secondaryTarget == Condition::Target::MinCooldownSpecial)
            {
                ui->includeLimitBreak->setChecked(false);
                ui->includeLimitBreak->show();
            }
        }
        else if (secondaryTarget == Condition::Target::AdditionalDmgSpecial || secondaryTarget == Condition::Target::ChainBoostSpecial || secondaryTarget == Condition::Target::ChainLockSpecial)
        {
            // Add operators
            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(secondaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();

            ui->numericValueEdit->clear();
            ui->numericValueEdit->setText("0");
            ui->numericValueEdit->show();

            ui->turnsLabel->show();

            ui->secondaryOperatorBox->clear();
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->secondaryOperatorBox->addItem(opText);
            }
            ui->secondaryOperatorBox->show();

            ui->secondaryNumericValueEdit->clear();
            ui->secondaryNumericValueEdit->setText("0");
            ui->secondaryNumericValueEdit->show();
        }
        else if (secondaryTarget == Condition::Target::ConditionSpecial)
        {
            ui->terziaryTargetBox->clear();
            for (int i = static_cast<int>(Condition::Target::ConditionTargets) + 1; i < static_cast<int>(Condition::Target::EndConditionTargets); ++i)
            {
                std::string terziaryTarget = dummy->getDescriptionFromTarget(Condition::Target::ConditionSpecial, static_cast<Condition::Target>(i));
                QString terziaryString(QString::fromStdString(terziaryTarget));
                ui->terziaryTargetBox->addItem(terziaryString);
            }
            ui->terziaryTargetBox->show();
        }
        else if (secondaryTarget == Condition::Target::CrewDebuffReductionSpecial)
        {
            ui->terziaryTargetBox->clear();
            for (int i = static_cast<int>(Condition::Target::CrewDebuffReducerTargets) + 1; i < static_cast<int>(Condition::Target::EndCrewDebuffReducerTargets); ++i)
            {
                std::string terziaryTarget = dummy->getDescriptionFromTarget(Condition::Target::CrewDebuffReductionSpecial, static_cast<Condition::Target>(i));
                QString terziaryString(QString::fromStdString(terziaryTarget));
                ui->terziaryTargetBox->addItem(terziaryString);
            }
            ui->terziaryTargetBox->show();

            // Add operators
            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(secondaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();

            ui->numericValueEdit->clear();
            ui->numericValueEdit->setText("0");
            ui->numericValueEdit->show();
        }
        else if (secondaryTarget == Condition::Target::EnemyBuffReductionSpecial)
        {
            ui->terziaryTargetBox->clear();
            for (int i = static_cast<int>(Condition::Target::EnemyBuffReducerTargets) + 1; i < static_cast<int>(Condition::Target::EndEnemyBuffReducerTargets); ++i)
            {
                std::string terziaryTarget = dummy->getDescriptionFromTarget(Condition::Target::EnemyBuffReductionSpecial, static_cast<Condition::Target>(i));
                QString terziaryString(QString::fromStdString(terziaryTarget));
                ui->terziaryTargetBox->addItem(terziaryString);
            }
            ui->terziaryTargetBox->show();

            // Add operators
            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(secondaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();

            ui->numericValueEdit->clear();
            ui->numericValueEdit->setText("0");
            ui->numericValueEdit->show();
        }
        else if (secondaryTarget == Condition::Target::UtilitySpecial)
        {
            ui->terziaryTargetBox->clear();
            for (int i = static_cast<int>(Condition::Target::SpecialUtilityTargets) + 1; i < static_cast<int>(Condition::Target::EndSpecialUtilityTargets); ++i)
            {
                std::string terziaryTarget = dummy->getDescriptionFromTarget(Condition::Target::UtilitySpecial, static_cast<Condition::Target>(i));
                QString terziaryString(QString::fromStdString(terziaryTarget));
                ui->terziaryTargetBox->addItem(terziaryString);
            }
            ui->terziaryTargetBox->show();
        }
        else if (secondaryTarget == Condition::Target::OrbManipulationSpecial)
        {
            ui->terziaryTargetBox->clear();
            for (int i = static_cast<int>(Condition::Target::OrbManipulationTargets) + 1; i < static_cast<int>(Condition::Target::EndOrbManipulationTargets); ++i)
            {
                std::string terziaryTarget = dummy->getDescriptionFromTarget(Condition::Target::OrbManipulationSpecial, static_cast<Condition::Target>(i));
                QString terziaryString(QString::fromStdString(terziaryTarget));
                ui->terziaryTargetBox->addItem(terziaryString);
            }
            ui->terziaryTargetBox->show();
        }
    }
}

void ConditionWidget::on_terziaryTargetBox_currentIndexChanged(const QString &_text)
{
    Condition::Target primaryTarget = dummy->getTargetFromDescription(Condition::Target::PrimaryTargets, ui->primaryTargetBox->currentText().toUtf8().constData());
    Condition::Target secondaryTarget = dummy->getTargetFromDescription(primaryTarget, ui->secondaryTargetBox->currentText().toUtf8().constData());
    std::string target = _text.toUtf8().constData();
    if (primaryTarget == Condition::Target::MyCharacter)
    {
        if (secondaryTarget == Condition::Target::MySockets)
        {
            if (stringToSocket(target) != Socket::Type::None)
            {
                ui->operatorBox->clear();
                std::vector<std::string> operators = dummy->getPossibleOperators(primaryTarget);
                for (auto op : operators)
                {
                    QString opText = QString::fromStdString(op);
                    ui->operatorBox->addItem(opText);
                }
                ui->operatorBox->show();

                ui->numericValueEdit->clear();
                ui->numericValueEdit->setText("0");
                ui->numericValueEdit->show();
            }
            else
            {
                ui->operatorBox->hide();
                ui->numericValueEdit->hide();
            }
        }
        else if (secondaryTarget == Condition::Target::MyCotton)
        {
            Condition::Target terziaryTarget = dummy->getTargetFromDescription(Condition::Target::OtherTargets, ui->terziaryTargetBox->currentText().toUtf8().constData());
            if (terziaryTarget == Condition::Target::CottonHp || terziaryTarget == Condition::Target::CottonAtk || terziaryTarget == Condition::Target::CottonRcv)
            {
                ui->operatorBox->clear();
                std::vector<std::string> operators = dummy->getPossibleOperators(primaryTarget);
                for (auto op : operators)
                {
                    QString opText = QString::fromStdString(op);
                    ui->operatorBox->addItem(opText);
                }
                ui->operatorBox->show();

                ui->numericValueEdit->clear();
                ui->numericValueEdit->setText("0");
                ui->numericValueEdit->show();
            }
        }
        else if (secondaryTarget == Condition::Target::MyPotentials)
        {
            Condition::Target terziaryTarget = dummy->getTargetFromDescription(Condition::Target::OtherTargets, ui->terziaryTargetBox->currentText().toUtf8().constData());
            if (terziaryTarget != Condition::Target::Finished && terziaryTarget != Condition::Target::NotFinished)
            {
                ui->operatorBox->clear();
                std::vector<std::string> operators = dummy->getPossibleOperators(primaryTarget);
                for (auto op : operators)
                {
                    QString opText = QString::fromStdString(op);
                    ui->operatorBox->addItem(opText);
                }
                ui->operatorBox->show();
                ui->numericValueEdit->clear();
                ui->numericValueEdit->setText("0");
                ui->numericValueEdit->show();
            }
            else
            {
                ui->operatorBox->hide();
                ui->numericValueEdit->hide();
            }
        }
    }
    else if (primaryTarget == Condition::Target::Special)
    {
        ui->quaternaryTargetBox->hide();
        ui->boolTarget->hide();
        ui->genericValueBox->hide();
        ui->operatorBox->hide();
        ui->numericValueEdit->hide();
        ui->secondaryOperatorBox->hide();
        ui->secondaryNumericValueEdit->hide();
        ui->turnsLabel->hide();
        ui->intoLabel->hide();
        ui->finalTargetBox->hide();
        ui->endOfTurn->hide();

        Condition::Target terziaryTarget = dummy->getTargetFromDescription(secondaryTarget, ui->terziaryTargetBox->currentText().toUtf8().constData());
        if (secondaryTarget == Condition::Target::ConditionSpecial)
        {
            if (terziaryTarget == Condition::Target::DelayCondition)
            {
                ui->operatorBox->clear();
                std::vector<std::string> operators = dummy->getPossibleOperators(terziaryTarget);
                for (auto op : operators)
                {
                    QString opText = QString::fromStdString(op);
                    ui->operatorBox->addItem(opText);
                }
                ui->operatorBox->show();
                ui->numericValueEdit->clear();
                ui->numericValueEdit->setText("0");
                ui->numericValueEdit->show();
            }
            else if (terziaryTarget == Condition::Target::ReduceDefenseCondition || terziaryTarget == Condition::Target::ReduceDefenseBoostCondition ||
                     terziaryTarget == Condition::Target::PoisonBoostCondition || terziaryTarget == Condition::Target::StronglyPoisonBoostCondition ||
                     terziaryTarget == Condition::Target::ToxicBoostCondition || terziaryTarget == Condition::Target::DelayBoostCondition ||
                     terziaryTarget == Condition::Target::IncreasedDefenseBoostCondition)
            {
                ui->operatorBox->clear();
                std::vector<std::string> operators = dummy->getPossibleOperators(secondaryTarget);
                for (auto op : operators)
                {
                    QString opText = QString::fromStdString(op);
                    ui->operatorBox->addItem(opText);
                }
                ui->operatorBox->show();
                ui->numericValueEdit->clear();
                ui->numericValueEdit->setText("0");
                ui->numericValueEdit->show();

                ui->turnsLabel->show();
                ui->secondaryOperatorBox->clear();
                for (auto op : operators)
                {
                    QString opText = QString::fromStdString(op);
                    ui->secondaryOperatorBox->addItem(opText);
                }
                ui->secondaryOperatorBox->show();

                ui->secondaryNumericValueEdit->clear();
                ui->secondaryNumericValueEdit->setText("0");
                ui->secondaryNumericValueEdit->show();
            }
        }
        else if (secondaryTarget == Condition::Target::OrbManipulationSpecial)
        {
            if (terziaryTarget == Condition::Target::LockManipulation)
            {
                ui->turnsLabel->show();
                ui->secondaryOperatorBox->clear();
                std::vector<std::string> operators = dummy->getPossibleOperators(secondaryTarget);
                for (auto op : operators)
                {
                    QString opText = QString::fromStdString(op);
                    ui->secondaryOperatorBox->addItem(opText);
                }
                ui->secondaryOperatorBox->show();

                ui->secondaryNumericValueEdit->clear();
                ui->secondaryNumericValueEdit->setText("0");
                ui->secondaryNumericValueEdit->show();
            }
            else if (terziaryTarget == Condition::Target::SwitcherManipulation)
            {
                ui->operatorBox->clear();
                std::vector<std::string> operators = dummy->getPossibleOperators(secondaryTarget);
                for (auto op : operators)
                {
                    QString opText = QString::fromStdString(op);
                    ui->operatorBox->addItem(opText);
                }
                ui->operatorBox->show();
                ui->numericValueEdit->clear();
                ui->numericValueEdit->setText("0");
                ui->numericValueEdit->show();
            }
            else if (terziaryTarget == Condition::Target::BeneficialManipulation)
            {
                ui->quaternaryTargetBox->clear();
                ui->quaternaryTargetBox->addItem("Generic");
                for (int i = static_cast<int>(Slots::StartSlots) + 1; i < static_cast<int>(Slots::EndSlots); ++i)
                {
                    std::string terziaryTarget = to_string(static_cast<Slots>(i));
                    QString terziaryString(QString::fromStdString(terziaryTarget));
                    ui->quaternaryTargetBox->addItem(terziaryString);
                }
                ui->quaternaryTargetBox->show();

                ui->genericValueBox->clear();
                ui->genericValueBox->addItem("Generic");
                ui->genericValueBox->addItem("All Characters");
                // Add all types and classes
                for (int i = static_cast<int>(Type::StartType) + 1; i < static_cast<int>(Type::EndTypes); ++i)
                {
                    QString typeString(QString::fromStdString(to_string(static_cast<Type>(i))));
                    ui->genericValueBox->addItem(typeToIcon[static_cast<Type>(i)], typeString);
                }
                for (int i = static_cast<int>(Class::StartClass) + 1; i < static_cast<int>(Class::None); ++i)
                {
                    QString classString(QString::fromStdString(to_string(static_cast<Class>(i))));
                    ui->genericValueBox->addItem(classToIcon[static_cast<Class>(i)], classString);
                }
                ui->genericValueBox->show();

                ui->turnsLabel->show();
                ui->secondaryOperatorBox->clear();
                std::vector<std::string> operators = dummy->getPossibleOperators(terziaryTarget);
                for (auto op : operators)
                {
                    QString opText = QString::fromStdString(op);
                    ui->secondaryOperatorBox->addItem(opText);
                }
                ui->secondaryOperatorBox->show();

                ui->secondaryNumericValueEdit->clear();
                ui->secondaryNumericValueEdit->setText("0");
                ui->secondaryNumericValueEdit->show();
            }
            else if (terziaryTarget == Condition::Target::ShufflerManipulation)
            {
                ui->quaternaryTargetBox->clear();
                ui->quaternaryTargetBox->addItem("Generic");
                ui->quaternaryTargetBox->addItem("All orbs");
                ui->quaternaryTargetBox->addItem("Non matching");
                ui->quaternaryTargetBox->addItem("Badly matching");
                ui->quaternaryTargetBox->show();

                ui->boolTarget->setText("Including Block");
                ui->boolTarget->setChecked(false);
                ui->boolTarget->show();
            }
            else if (terziaryTarget == Condition::Target::ChanceManipulation)
            {
                ui->quaternaryTargetBox->clear();
                ui->quaternaryTargetBox->addItem("Generic");
                ui->quaternaryTargetBox->addItem("Matching");
                for (int i = static_cast<int>(Slots::StartSlots) + 1; i < static_cast<int>(Slots::EndSlots); ++i)
                {
                    std::string terziaryTarget = to_string(static_cast<Slots>(i));
                    QString terziaryString(QString::fromStdString(terziaryTarget));
                    ui->quaternaryTargetBox->addItem(terziaryString);
                }
                ui->quaternaryTargetBox->show();

                ui->turnsLabel->show();
                ui->secondaryOperatorBox->clear();
                std::vector<std::string> operators = dummy->getPossibleOperators(terziaryTarget);
                for (auto op : operators)
                {
                    QString opText = QString::fromStdString(op);
                    ui->secondaryOperatorBox->addItem(opText);
                }
                ui->secondaryOperatorBox->show();

                ui->secondaryNumericValueEdit->clear();
                ui->secondaryNumericValueEdit->setText("0");
                ui->secondaryNumericValueEdit->show();
            }
            else if (terziaryTarget == Condition::Target::ControllerManipulation)
            {
                ui->quaternaryTargetBox->clear();
                ui->quaternaryTargetBox->addItem("Generic");
                ui->quaternaryTargetBox->addItem("All orbs");
                ui->quaternaryTargetBox->addItem("Badly matching");
                ui->quaternaryTargetBox->addItem("Own");
                ui->quaternaryTargetBox->addItem("Position based");
                for (int i = static_cast<int>(Slots::StartSlots) + 1; i < static_cast<int>(Slots::EndSlots); ++i)
                {
                    std::string terziaryTarget = to_string(static_cast<Slots>(i));
                    QString terziaryString(QString::fromStdString(terziaryTarget));
                    ui->quaternaryTargetBox->addItem(terziaryString);
                }
                ui->quaternaryTargetBox->show();

                ui->boolTarget->setText("Including Block");
                ui->boolTarget->setChecked(false);
                ui->boolTarget->show();

                ui->intoLabel->show();

                ui->genericValueBox->clear();
                ui->genericValueBox->addItem("Generic");
                ui->genericValueBox->addItem("Matching");
                for (int i = static_cast<int>(Slots::StartSlots) + 1; i < static_cast<int>(Slots::EndSlots); ++i)
                {
                    std::string genericTarget = to_string(static_cast<Slots>(i));
                    QString genericTargetString(QString::fromStdString(genericTarget));
                    ui->genericValueBox->addItem(genericTargetString);
                }
                ui->genericValueBox->show();
            }
        }
        else if (secondaryTarget == Condition::Target::UtilitySpecial)
        {
            if (terziaryTarget == Condition::Target::CdReducerUtility)
            {
                ui->quaternaryTargetBox->clear();
                ui->quaternaryTargetBox->addItem("Generic");
                ui->quaternaryTargetBox->addItem("All Characters");
                // Add all types and classes
                for (int i = static_cast<int>(Type::StartType) + 1; i < static_cast<int>(Type::EndTypes); ++i)
                {
                    QString typeString(QString::fromStdString(to_string(static_cast<Type>(i))));
                    ui->quaternaryTargetBox->addItem(typeToIcon[static_cast<Type>(i)], typeString);
                }
                for (int i = static_cast<int>(Class::StartClass) + 1; i < static_cast<int>(Class::None); ++i)
                {
                    QString classString(QString::fromStdString(to_string(static_cast<Class>(i))));
                    ui->quaternaryTargetBox->addItem(classToIcon[static_cast<Class>(i)], classString);
                }
                ui->quaternaryTargetBox->show();

                ui->operatorBox->clear();
                std::vector<std::string> operators = dummy->getPossibleOperators(terziaryTarget);
                for (auto op : operators)
                {
                    QString opText = QString::fromStdString(op);
                    ui->operatorBox->addItem(opText);
                }
                ui->operatorBox->show();
                ui->numericValueEdit->clear();
                ui->numericValueEdit->setText("0");
                ui->numericValueEdit->show();
            }
            else if (terziaryTarget == Condition::Target::CutterUtility)
            {
                ui->quaternaryTargetBox->clear();
                ui->quaternaryTargetBox->addItem("One Character");
                ui->quaternaryTargetBox->addItem("All Characters");
                ui->quaternaryTargetBox->show();

                ui->operatorBox->clear();
                std::vector<std::string> operators = dummy->getPossibleOperators(terziaryTarget);
                for (auto op : operators)
                {
                    QString opText = QString::fromStdString(op);
                    ui->operatorBox->addItem(opText);
                }
                ui->operatorBox->show();
                ui->numericValueEdit->clear();
                ui->numericValueEdit->setText("0");
                ui->numericValueEdit->show();
            }
            else if (terziaryTarget == Condition::Target::HealerUtility)
            {
                ui->quaternaryTargetBox->clear();
                ui->quaternaryTargetBox->addItem("Rcv based");
                ui->quaternaryTargetBox->addItem("Max HP based");
                ui->quaternaryTargetBox->addItem("Other");
                ui->quaternaryTargetBox->show();

                ui->operatorBox->clear();
                std::vector<std::string> operators = dummy->getPossibleOperators(terziaryTarget);
                for (auto op : operators)
                {
                    QString opText = QString::fromStdString(op);
                    ui->operatorBox->addItem(opText);
                }
                ui->operatorBox->show();
                ui->numericValueEdit->clear();
                ui->numericValueEdit->setText("0");
                ui->numericValueEdit->show();
            }
            else if (terziaryTarget == Condition::Target::HealthReducerUtility)
            {
                ui->quaternaryTargetBox->clear();
                ui->quaternaryTargetBox->addItem("Fixed");
                ui->quaternaryTargetBox->addItem("Percentage");
                ui->quaternaryTargetBox->show();

                ui->operatorBox->clear();
                std::vector<std::string> operators = dummy->getPossibleOperators(terziaryTarget);
                for (auto op : operators)
                {
                    QString opText = QString::fromStdString(op);
                    ui->operatorBox->addItem(opText);
                }
                ui->operatorBox->show();
                ui->numericValueEdit->clear();
                ui->numericValueEdit->setText("0");
                ui->numericValueEdit->show();
            }
            else if (terziaryTarget == Condition::Target::PerfectEasierUtility)
            {
                ui->turnsLabel->show();
                ui->secondaryOperatorBox->clear();
                std::vector<std::string> operators = dummy->getPossibleOperators(terziaryTarget);
                for (auto op : operators)
                {
                    QString opText = QString::fromStdString(op);
                    ui->secondaryOperatorBox->addItem(opText);
                }
                ui->secondaryOperatorBox->show();

                ui->secondaryNumericValueEdit->clear();
                ui->secondaryNumericValueEdit->setText("0");
                ui->secondaryNumericValueEdit->show();
            }
            else if (terziaryTarget == Condition::Target::FollowingTurnUtility)
            {
                ui->quaternaryTargetBox->clear();
                ui->quaternaryTargetBox->addItem("Generic");
                ui->quaternaryTargetBox->addItem("All Characters");
                // Add all types and classes
                for (int i = static_cast<int>(Type::StartType) + 1; i < static_cast<int>(Type::EndTypes); ++i)
                {
                    QString typeString(QString::fromStdString(to_string(static_cast<Type>(i))));
                    ui->quaternaryTargetBox->addItem(typeToIcon[static_cast<Type>(i)], typeString);
                }
                for (int i = static_cast<int>(Class::StartClass) + 1; i < static_cast<int>(Class::None); ++i)
                {
                    QString classString(QString::fromStdString(to_string(static_cast<Class>(i))));
                    ui->quaternaryTargetBox->addItem(classToIcon[static_cast<Class>(i)], classString);
                }
                ui->quaternaryTargetBox->show();

                ui->operatorBox->clear();
                std::vector<std::string> operators = dummy->getPossibleOperators(terziaryTarget);
                for (auto op : operators)
                {
                    QString opText = QString::fromStdString(op);
                    ui->operatorBox->addItem(opText);
                }
                ui->operatorBox->show();
                ui->numericValueEdit->clear();
                ui->numericValueEdit->setText("0");
                ui->numericValueEdit->show();
            }
            else if (terziaryTarget == Condition::Target::DmgReducerUtility)
            {
                ui->operatorBox->clear();
                std::vector<std::string> operators = dummy->getPossibleOperators(terziaryTarget);
                for (auto op : operators)
                {
                    QString opText = QString::fromStdString(op);
                    ui->operatorBox->addItem(opText);
                }
                ui->operatorBox->show();
                ui->numericValueEdit->clear();
                ui->numericValueEdit->setText("0");
                ui->numericValueEdit->show();

                ui->turnsLabel->show();
                ui->secondaryOperatorBox->clear();
                std::vector<std::string> secondaryOperators = dummy->getPossibleOperators(secondaryTarget);
                for (auto op : secondaryOperators)
                {
                    QString opText = QString::fromStdString(op);
                    ui->secondaryOperatorBox->addItem(opText);
                }
                ui->secondaryOperatorBox->show();

                ui->secondaryNumericValueEdit->clear();
                ui->secondaryNumericValueEdit->setText("0");
                ui->secondaryNumericValueEdit->show();
            }
            else if (terziaryTarget == Condition::Target::DmgDealerUtility)
            {
                ui->quaternaryTargetBox->clear();
                ui->quaternaryTargetBox->addItem("Generic");
                ui->quaternaryTargetBox->addItem("Fixed");
                ui->quaternaryTargetBox->addItem("Random");
                ui->quaternaryTargetBox->addItem("Atk based");
                ui->quaternaryTargetBox->addItem("Hp based");
                ui->quaternaryTargetBox->addItem("Multi-hit");
                ui->quaternaryTargetBox->show();

                ui->boolTarget->setText("Ignore Barriers");
                ui->boolTarget->setChecked(false);
                ui->boolTarget->show();

                ui->genericValueBox->clear();
                ui->genericValueBox->addItem("Generic");
                ui->genericValueBox->addItem("Typeless");
                // Add all types and classes
                for (int i = static_cast<int>(Type::StartType) + 1; i < static_cast<int>(Type::EndTypes); ++i)
                {
                    QString typeString(QString::fromStdString(to_string(static_cast<Type>(i))));
                    ui->genericValueBox->addItem(typeToIcon[static_cast<Type>(i)], typeString);
                }
                ui->genericValueBox->show();

                ui->finalTargetBox->clear();
                ui->finalTargetBox->addItem("Generic");
                ui->finalTargetBox->addItem("Single");
                ui->finalTargetBox->addItem("Random");
                ui->finalTargetBox->addItem("All enemies");
                ui->finalTargetBox->show();

                ui->endOfTurn->setChecked(false);
                ui->endOfTurn->show();
            }
        }
        else if (secondaryTarget == Condition::Target::ATKBoostSpecial || secondaryTarget == Condition::Target::OrbBoostSpecial || secondaryTarget == Condition::Target::ColorAffinitySpecial)
        {
            // Add operators
            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(secondaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();

            ui->numericValueEdit->clear();
            ui->numericValueEdit->setText("0");
            ui->numericValueEdit->show();

            // Add secondary operators
            ui->turnsLabel->show();
            ui->secondaryOperatorBox->clear();
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->secondaryOperatorBox->addItem(opText);
            }
            ui->secondaryOperatorBox->show();
            ui->secondaryNumericValueEdit->clear();
            ui->secondaryNumericValueEdit->setText("0");
            ui->secondaryNumericValueEdit->show();
        }
        else if (secondaryTarget == Condition::Target::AdditionalDmgSpecial || secondaryTarget == Condition::Target::ChainBoostSpecial || secondaryTarget == Condition::Target::ChainLockSpecial)
        {
            // Add operators
            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(secondaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();

            ui->numericValueEdit->clear();
            ui->numericValueEdit->setText("0");
            ui->numericValueEdit->show();

            ui->turnsLabel->show();

            ui->secondaryOperatorBox->clear();
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->secondaryOperatorBox->addItem(opText);
            }
            ui->secondaryOperatorBox->show();

            ui->secondaryNumericValueEdit->clear();
            ui->secondaryNumericValueEdit->setText("0");
            ui->secondaryNumericValueEdit->show();
        }
        else if (secondaryTarget == Condition::Target::CrewDebuffReductionSpecial)
        {
            // Add operators
            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(secondaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();

            ui->numericValueEdit->clear();
            ui->numericValueEdit->setText("0");
            ui->numericValueEdit->show();
        }
        else if (secondaryTarget == Condition::Target::EnemyBuffReductionSpecial)
        {
            // Add operators
            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(secondaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();

            ui->numericValueEdit->clear();
            ui->numericValueEdit->setText("0");
            ui->numericValueEdit->show();
        }
    }
}

Condition ConditionWidget::getCondition()
{
    if (ui->primaryTargetBox->currentText() != "")
    {
        Condition::Target target = dummy->getTargetFromDescription(Condition::Target::PrimaryTargets, ui->primaryTargetBox->currentText().toUtf8().constData());
        Condition::Operator op = dummy->getOperatorFromDescription(ui->operatorBox->currentText().toUtf8().constData());
        std::string value = ui->numericValueEdit->isHidden() ? ui->stringValueEdit->text().toUtf8().constData() : ui->numericValueEdit->text().toUtf8().constData();
        Condition condition(utility, "", target, op, value);
        if (!ui->secondaryTargetBox->isHidden())
        {
            condition.setSecondaryTarget(dummy->getTargetFromDescription(target, ui->secondaryTargetBox->currentText().toUtf8().constData()));
        }

        if (!ui->includeLimitBreak->isHidden())
        {
            condition.setIncludeLimitBreak(ui->includeLimitBreak->isChecked());
        }

        if (!ui->includePlus->isHidden())
        {
            condition.setIncludePlus(ui->includePlus->isChecked());
        }

        if (!ui->includeWantToFinish->isHidden())
        {
            condition.setIncludeWantToFinish(ui->includeWantToFinish->isChecked());
        }

        if (!ui->terziaryTargetBox->isHidden())
        {
            Condition::Target secondaryTarget = dummy->getTargetFromDescription(target, ui->secondaryTargetBox->currentText().toUtf8().constData());

            if (secondaryTarget == Condition::Target::HPBoostCaptain || secondaryTarget == Condition::Target::ATKBoostCaptain || secondaryTarget == Condition::Target::RCVBoostCaptain ||
                    secondaryTarget == Condition::Target::BoostHPSailor || secondaryTarget == Condition::Target::BoostATKSailor || secondaryTarget == Condition::Target::BoostRCVSailor ||
                    secondaryTarget == Condition::Target::ATKBoostSpecial || secondaryTarget == Condition::Target::OrbBoostSpecial || secondaryTarget == Condition::Target::ColorAffinitySpecial)
            {
                std::string terziaryTargetBox = ui->terziaryTargetBox->currentText().toUtf8().constData();
                if (terziaryTargetBox == "All Characters")
                {
                    condition.setTypeTarget(Type::StartType);
                }
                else if (terziaryTargetBox == "Generic")
                {
                    condition.setTypeTarget(Type::EndTypes);
                }
                else if (terziaryTargetBox == "Dominant Type")
                {
                    condition.setClassTarget(Class::None);
                }
                else
                {
                    bool isType = false;
                    for (int i = static_cast<int>(Type::StartType) + 1; i < static_cast<int>(Type::EndTypes); ++i)
                    {
                        std::string type = to_string(static_cast<Type>(i));
                        if (terziaryTargetBox == type)
                        {
                            isType = true;
                            break;
                        }
                    }

                    if (isType)
                    {
                        condition.setTypeTarget(stringToType(terziaryTargetBox));
                    }
                    else
                    {
                        condition.setClassTarget(stringToClass(terziaryTargetBox));
                    }
                }
            }
            else if (secondaryTarget == Condition::Target::OrbKeeper || secondaryTarget == Condition::Target::BeneficialOrb)
            {
                std::string currentSlot = ui->terziaryTargetBox->currentText().toUtf8().constData();
                if (currentSlot != "Generic")
                {
                    condition.setSlotsTarget(stringToSlots(currentSlot));
                }
                else
                {
                    condition.setSlotsTarget(Slots::StartSlots);
                }
            }
            else if (secondaryTarget == Condition::Target::CrewDebuffReductionSpecial || secondaryTarget == Condition::Target::EnemyBuffReductionSpecial ||
                     secondaryTarget == Condition::Target::UtilitySpecial || secondaryTarget == Condition::Target::ConditionSpecial || secondaryTarget == Condition::Target::OrbManipulationSpecial)
            {
                Condition::Target terziaryTarget = dummy->getTargetFromDescription(secondaryTarget, ui->terziaryTargetBox->currentText().toUtf8().constData());
                condition.setTerziaryTarget(terziaryTarget);
            }
            else if (secondaryTarget == Condition::Target::HealerCaptain)
            {
                std::string terziaryTargetBox = ui->terziaryTargetBox->currentText().toUtf8().constData();
                if (terziaryTargetBox == "Rcv based")
                {
                    condition.setTerziaryTarget(Condition::Target::PrimaryTargets);
                }
                else if (terziaryTargetBox == "Other")
                {
                    condition.setTerziaryTarget(Condition::Target::EndPrimaryTargets);
                }
            }

            if (target == Condition::Target::MyCharacter)
            {
                if (secondaryTarget != Condition::Target::MySockets && secondaryTarget != Condition::Target::MyPotentials)
                {
                    condition.setTerziaryTarget(dummy->getTargetFromDescription(Condition::Target::OtherTargets, ui->terziaryTargetBox->currentText().toUtf8().constData()));
                }
                else if (secondaryTarget == Condition::Target::MySockets)
                {
                    if (ui->terziaryTargetBox->currentText().toUtf8().constData() == dummy->getDescriptionFromTarget(Condition::Target::OtherTargets, Condition::Target::Finished))
                    {
                        condition.setTerziaryTarget(Condition::Target::Finished);
                    }
                    else if (ui->terziaryTargetBox->currentText().toUtf8().constData() == dummy->getDescriptionFromTarget(Condition::Target::OtherTargets, Condition::Target::NotFinished))
                    {
                        condition.setTerziaryTarget(Condition::Target::NotFinished);
                    }
                    else
                    {
                        condition.setSocketTarget(stringToSocket(ui->terziaryTargetBox->currentText().toUtf8().constData()));
                    }
                }
                else if (secondaryTarget == Condition::Target::MyPotentials)
                {
                    if (ui->terziaryTargetBox->currentText().toUtf8().constData() == dummy->getDescriptionFromTarget(Condition::Target::OtherTargets, Condition::Target::Finished))
                    {
                        condition.setTerziaryTarget(Condition::Target::Finished);
                    }
                    else if (ui->terziaryTargetBox->currentText().toUtf8().constData() == dummy->getDescriptionFromTarget(Condition::Target::OtherTargets, Condition::Target::NotFinished))
                    {
                        condition.setTerziaryTarget(Condition::Target::NotFinished);
                    }
                    else
                    {
                        Potential dummyPotential(Potential::Type::None, 1);
                        condition.setPotentialTarget(dummyPotential.getTypeFromDescription(ui->terziaryTargetBox->currentText().toUtf8().constData()));
                    }
                }
            }
        }

        if (!ui->quaternaryTargetBox->isHidden())
        {
            Condition::Target secondaryTarget = dummy->getTargetFromDescription(target, ui->secondaryTargetBox->currentText().toUtf8().constData());
            Condition::Target terziaryTarget = dummy->getTargetFromDescription(secondaryTarget, ui->terziaryTargetBox->currentText().toUtf8().constData());
            std::string quaternaryTargetBox = ui->quaternaryTargetBox->currentText().toUtf8().constData();

            if (secondaryTarget == Condition::Target::UtilitySpecial)
            {
                if (terziaryTarget == Condition::Target::FollowingTurnUtility || terziaryTarget == Condition::Target::CdReducerUtility)
                {
                    if (quaternaryTargetBox == "All Characters")
                    {
                        condition.setTypeTarget(Type::StartType);
                    }
                    else if (quaternaryTargetBox == "Generic")
                    {
                        condition.setTypeTarget(Type::EndTypes);
                    }
                    else if (quaternaryTargetBox == "Dominant Type")
                    {
                        condition.setClassTarget(Class::None);
                    }
                    else
                    {
                        bool isType = false;
                        for (int i = static_cast<int>(Type::StartType) + 1; i < static_cast<int>(Type::EndTypes); ++i)
                        {
                            std::string type = to_string(static_cast<Type>(i));
                            if (quaternaryTargetBox == type)
                            {
                                isType = true;
                                break;
                            }
                        }

                        if (isType)
                        {
                            condition.setTypeTarget(stringToType(quaternaryTargetBox));
                        }
                        else
                        {
                            condition.setClassTarget(stringToClass(quaternaryTargetBox));
                        }
                    }
                }
                else if (terziaryTarget == Condition::Target::CutterUtility)
                {
                    std::string quaternaryTargetBox = ui->quaternaryTargetBox->currentText().toUtf8().constData();

                    if (quaternaryTargetBox == "One Character")
                    {
                        condition.setQuaternaryTarget(Condition::Target::PrimaryTargets);
                    }
                    else if (quaternaryTargetBox == "All Characters")
                    {
                        condition.setQuaternaryTarget(Condition::Target::EndPrimaryTargets);
                    }
                }
                else if (terziaryTarget == Condition::Target::HealerUtility)
                {
                    std::string quaternaryTargetBox = ui->quaternaryTargetBox->currentText().toUtf8().constData();

                    if (quaternaryTargetBox == "Other")
                    {
                        condition.setQuaternaryTarget(Condition::Target::PrimaryTargets);
                    }
                    else if (quaternaryTargetBox == "Rcv based")
                    {
                        condition.setQuaternaryTarget(Condition::Target::EndPrimaryTargets);
                    }
                    else if (quaternaryTargetBox == "Max HP based")
                    {
                        condition.setQuaternaryTarget(Condition::Target::HealerUtility);
                    }
                }
                else if (terziaryTarget == Condition::Target::HealthReducerUtility)
                {
                    std::string quaternaryTargetBox = ui->quaternaryTargetBox->currentText().toUtf8().constData();

                    if (quaternaryTargetBox == "Fixed")
                    {
                        condition.setQuaternaryTarget(Condition::Target::PrimaryTargets);
                    }
                    else if (quaternaryTargetBox == "Percentage")
                    {
                        condition.setQuaternaryTarget(Condition::Target::EndPrimaryTargets);
                    }
                }
                else if (terziaryTarget == Condition::Target::DmgDealerUtility)
                {
                    condition.addGenericTargetValue(quaternaryTargetBox);

                    std::string damageTypeTargetBox = ui->genericValueBox->currentText().toUtf8().constData();
                    condition.addGenericTargetValue(damageTypeTargetBox);

                    std::string finalTargetBox = ui->finalTargetBox->currentText().toUtf8().constData();
                    condition.addGenericTargetValue(finalTargetBox);
                }
            }
            else if (secondaryTarget == Condition::Target::OrbManipulationSpecial)
            {
                if (terziaryTarget == Condition::Target::BeneficialManipulation)
                {
                    condition.addGenericTargetValue(quaternaryTargetBox);

                    std::string orbTarget = ui->genericValueBox->currentText().toUtf8().constData();
                    condition.addGenericTargetValue(orbTarget);
                }
                else if (terziaryTarget == Condition::Target::ChanceManipulation)
                {
                    condition.addGenericTargetValue(quaternaryTargetBox);
                }
                else if (terziaryTarget == Condition::Target::ShufflerManipulation)
                {
                    condition.addGenericTargetValue(quaternaryTargetBox);
                }
                else if (terziaryTarget == Condition::Target::ControllerManipulation)
                {
                    condition.addGenericTargetValue(quaternaryTargetBox);

                    std::string orbTarget = ui->genericValueBox->currentText().toUtf8().constData();
                    condition.addGenericTargetValue(orbTarget);
                }
            }
        }

        if (!ui->genericValueBox->isHidden())
        {
            if (target == Condition::Target::Type)
            {
                condition.setTypeValue(stringToType(ui->genericValueBox->currentText().toUtf8().constData()));
            }
            else if (target == Condition::Target::Class || target == Condition::Target::PrimaryClass || target == Condition::Target::SecondaryClass)
            {
                condition.setClassValue(stringToClass(ui->genericValueBox->currentText().toUtf8().constData()));
            }
            else if (target == Condition::Target::LimitBreak)
            {
                Potential dummyPotential(Potential::Type::None, 1);
                condition.setPotentialTarget(dummyPotential.getTypeFromDescription(ui->genericValueBox->currentText().toUtf8().constData()));
            }
            else if (target == Condition::Target::Availability)
            {
                condition.setAvailabilityTarget(stringToAvailability(ui->genericValueBox->currentText().toUtf8().constData()));
            }
            else if (target == Condition::Target::Sailor)
            {
                Condition::Target secondaryTarget = dummy->getTargetFromDescription(target, ui->secondaryTargetBox->currentText().toUtf8().constData());
                std::string typeClassValueBox = ui->genericValueBox->currentText().toUtf8().constData();
                if (secondaryTarget == Condition::Target::OrbKeeper)
                {
                    if (typeClassValueBox != "Generic")
                    {
                        condition.setValue(ui->genericValueBox->currentText().toUtf8().constData());
                    }
                    else
                    {
                        condition.setValue("");
                    }
                }
                else if (secondaryTarget == Condition::Target::BeneficialOrb)
                {
                    if (typeClassValueBox == "All Characters")
                    {
                        condition.setTypeTarget(Type::StartType);
                    }
                    else if (typeClassValueBox == "Self")
                    {
                        condition.setTypeTarget(Type::EndTypes);
                    }
                    else
                    {
                        bool isType = false;
                        for (int i = static_cast<int>(Type::StartType) + 1; i < static_cast<int>(Type::EndTypes); ++i)
                        {
                            std::string type = to_string(static_cast<Type>(i));
                            if (typeClassValueBox == type)
                            {
                                isType = true;
                                break;
                            }
                        }

                        if (isType)
                        {
                            condition.setTypeTarget(stringToType(typeClassValueBox));
                        }
                        else
                        {
                            condition.setClassTarget(stringToClass(typeClassValueBox));
                        }
                    }
                }
            }
        }

        if (!ui->boolTarget->isHidden())
        {
            Condition::Target secondaryTarget = dummy->getTargetFromDescription(target, ui->secondaryTargetBox->currentText().toUtf8().constData());
            Condition::Target terziaryTarget = dummy->getTargetFromDescription(secondaryTarget, ui->terziaryTargetBox->currentText().toUtf8().constData());
            if (secondaryTarget == Condition::Target::OrbManipulationSpecial)
            {
                if (terziaryTarget == Condition::Target::ShufflerManipulation || terziaryTarget == Condition::Target::ControllerManipulation)
                {
                    condition.setIncludePlus(ui->boolTarget->isChecked());
                }
            }
            else if (secondaryTarget == Condition::Target::UtilitySpecial)
            {
                if (terziaryTarget == Condition::Target::DmgDealerUtility)
                {
                    condition.setIncludePlus(ui->boolTarget->isChecked());
                    condition.setIncludeLimitBreak(ui->endOfTurn->isChecked());
                }
            }
        }

        if (!ui->secondaryOperatorBox->isHidden() && !ui->secondaryNumericValueEdit->isHidden())
        {
            Condition::Operator secondaryOperator = dummy->getOperatorFromDescription(ui->secondaryOperatorBox->currentText().toUtf8().constData());
            std::string secondaryValue = ui->secondaryNumericValueEdit->text().toUtf8().constData();
            condition.setSecondaryOperatorValue(secondaryOperator, secondaryValue);
        }
        return condition;
    }
    return Condition(utility, "", Condition::Target::PrimaryTargets, Condition::Operator::NumOperators, "");
}

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), s.end(), [](char c) { return !isdigit(c); }) == s.end();
}

void ConditionWidget::on_numericValueEdit_textChanged(const QString &_text)
{
    if (_text.size() > 0)
    {
        std::string text = _text.toUtf8().constData();
        std::string lastChar = text.substr(text.size() - 1);
        // Check if last character is a number or a dot
        bool removeLastChar = false;
        if (!is_number(lastChar))
        {
            Condition::Target target = dummy->getTargetFromDescription(Condition::Target::PrimaryTargets, ui->primaryTargetBox->currentText().toUtf8().constData());
            if (dummy->getPossibleOperationsTypeFromTarget(target) == "Decimal")
            {
                // If is decimal, check if the character is a dot (max 1 dot)
                if (lastChar != ".")
                {
                    removeLastChar = true;
                }
                else
                {
                    size_t dotNumber = static_cast<size_t>(std::count(text.begin(), text.end(), '.'));
                    if (dotNumber > 1)
                    {
                        removeLastChar = true;
                    }
                }
            }
            else if (dummy->getPossibleOperationsTypeFromTarget(target) == "CheckSecondary")
            {
                Condition::Target secondaryTarget = dummy->getTargetFromDescription(target, ui->secondaryTargetBox->currentText().toUtf8().constData());
                if (dummy->getPossibleOperationsTypeFromTarget(secondaryTarget) == "Decimal")
                {
                    // If is decimal, check if the character is a dot (max 1 dot)
                    if (lastChar != ".")
                    {
                        removeLastChar = true;
                    }
                    else
                    {
                        size_t dotNumber = static_cast<size_t>(std::count(text.begin(), text.end(), '.'));
                        if (dotNumber > 1)
                        {
                            removeLastChar = true;
                        }
                    }
                }
                else
                {
                    removeLastChar = true;
                }
            }
            else
            {
                removeLastChar = true;
            }
        }

        if (removeLastChar)
        {
            text = text.substr(0, text.size() - 1);
            ui->numericValueEdit->setText(QString::fromStdString(text));
        }

        // Check if where added points or letters befor last character
        bool commaAlreadySet = false;
        std::string correctText = "";
        for (size_t i = 0; i < text.size(); ++i)
        {
            std::string letter = text.substr(i, 1);
            if (!is_number(letter))
            {
                Condition::Target target = dummy->getTargetFromDescription(Condition::Target::PrimaryTargets, ui->primaryTargetBox->currentText().toUtf8().constData());
                if (dummy->getPossibleOperationsTypeFromTarget(target) == "Decimal")
                {
                    if (letter == "." && !commaAlreadySet)
                    {
                        commaAlreadySet = true;
                    }
                    else
                    {
                        letter = "";
                    }
                }
                else if (dummy->getPossibleOperationsTypeFromTarget(target) == "CheckSecondary")
                {
                    Condition::Target secondaryTarget = dummy->getTargetFromDescription(target, ui->secondaryTargetBox->currentText().toUtf8().constData());
                    if (dummy->getPossibleOperationsTypeFromTarget(secondaryTarget) == "Decimal")
                    {
                        if (letter == "." && !commaAlreadySet)
                        {
                            commaAlreadySet = true;
                        }
                        else
                        {
                            letter = "";
                        }
                    }
                    else
                    {
                        letter = "";
                    }
                }
                else
                {
                    letter = "";
                }
            }
            correctText += letter;
        }
        ui->numericValueEdit->setText(QString::fromStdString(correctText));

        // Set boundaries
        Condition::Target primaryTarget = dummy->getTargetFromDescription(Condition::Target::PrimaryTargets, ui->primaryTargetBox->currentText().toUtf8().constData());
        if (primaryTarget == Condition::Target::Rarity)
        {
            if (_text.toInt() == 5 || _text.toInt() == 6)
            {
                ui->includePlus->setChecked(false);
                ui->includePlus->show();
            }
            else
            {
                ui->includePlus->hide();
            }

            if (_text.toInt() > 6)
            {
                text = "6";
                ui->numericValueEdit->setText(QString::fromStdString(text));
            }
        }
        else if (primaryTarget == Condition::Target::MaxLvl)
        {
            if (_text.toInt() > 99)
            {
                text = "99";
                ui->numericValueEdit->setText(QString::fromStdString(text));
            }
        }
        else if (primaryTarget == Condition::Target::MyCharacter)
        {
            Condition::Target secondaryTarget = dummy->getTargetFromDescription(primaryTarget, ui->secondaryTargetBox->currentText().toUtf8().constData());
            if (secondaryTarget == Condition::Target::MyLevel)
            {
                if (_text.toInt() > 99)
                {
                    text = "99";
                    ui->numericValueEdit->setText(QString::fromStdString(text));
                }
            }
            else if (secondaryTarget == Condition::Target::MyCotton)
            {
                if (_text.toInt() > 100)
                {
                    text = "100";
                    ui->numericValueEdit->setText(QString::fromStdString(text));
                }
            }
            else
            {
                if (_text.toInt() > 5)
                {
                    text = "5";
                    ui->numericValueEdit->setText(QString::fromStdString(text));
                }
            }
        }
    }
    else
    {
        ui->includePlus->hide();
    }
}

void ConditionWidget::loadIcons()
{
    // Type icons
    for (int typeIdx = static_cast<int>(Type::StartType) + 1; typeIdx < static_cast<int>(Type::EndTypes); ++typeIdx)
    {
        QPixmap* iconPixmap = nullptr;
        if (static_cast<Type>(typeIdx) == Type::STR)
        {
            iconPixmap = new QPixmap(":/ui/str.png");
        }
        else if (static_cast<Type>(typeIdx) == Type::DEX)
        {
            iconPixmap = new QPixmap(":/ui/dex.png");
        }
        else if (static_cast<Type>(typeIdx) == Type::QCK)
        {
            iconPixmap = new QPixmap(":/ui/qck.png");
        }
        else if (static_cast<Type>(typeIdx) == Type::PSY)
        {
            iconPixmap = new QPixmap(":/ui/psy.png");
        }
        else if (static_cast<Type>(typeIdx) == Type::INT)
        {
            iconPixmap = new QPixmap(":/ui/int.png");
        }

        if (iconPixmap != nullptr)
        {
            QIcon icon(iconPixmap->scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            typeToIcon[static_cast<Type>(typeIdx)] = icon;
        }
    }

    // Class icons
    for (int classIdx = static_cast<int>(Class::StartClass) + 1; classIdx < static_cast<int>(Class::EndClasses); ++classIdx)
    {
        QPixmap* iconPixmap = nullptr;
        if (static_cast<Class>(classIdx) == Class::Fighter)
        {
            iconPixmap = new QPixmap(":/ui/fighter_icon.png");
        }
        else if (static_cast<Class>(classIdx) == Class::Shooter)
        {
            iconPixmap = new QPixmap(":/ui/shooter_icon.png");
        }
        else if (static_cast<Class>(classIdx) == Class::Slasher)
        {
            iconPixmap = new QPixmap(":/ui/slasher_icon.png");
        }
        else if (static_cast<Class>(classIdx) == Class::Striker)
        {
            iconPixmap = new QPixmap(":/ui/striker_icon.png");
        }
        else if (static_cast<Class>(classIdx) == Class::Free_Spirit)
        {
            iconPixmap = new QPixmap(":/ui/freespirit_icon.png");
        }
        else if (static_cast<Class>(classIdx) == Class::Cerebral)
        {
            iconPixmap = new QPixmap(":/ui/cerebral_icon.png");
        }
        else if (static_cast<Class>(classIdx) == Class::Powerhouse)
        {
            iconPixmap = new QPixmap(":/ui/powerhouse_icon.png");
        }
        else if (static_cast<Class>(classIdx) == Class::Driven)
        {
            iconPixmap = new QPixmap(":/ui/driven_icon.png");
        }
        else if (static_cast<Class>(classIdx) == Class::Evolver)
        {
            iconPixmap = new QPixmap(":/ui/evolver_icon.png");
        }
        else if (static_cast<Class>(classIdx) == Class::Booster)
        {
            iconPixmap = new QPixmap(":/ui/booster_icon.png");
        }

        if (iconPixmap != nullptr)
        {
            QIcon icon(iconPixmap->scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            classToIcon[static_cast<Class>(classIdx)] = icon;
        }
    }

    // Potentials icons
    for (int potentialIdx = static_cast<int>(Potential::Type::StartPotential) + 1; potentialIdx < static_cast<int>(Potential::Type::None); ++potentialIdx)
    {
        QPixmap* iconPixmap = nullptr;
        if (static_cast<Potential::Type>(potentialIdx) == Potential::Type::Enrage)
        {
            iconPixmap = new QPixmap(":/ui/potential_enrage.png");
        }
        else if (static_cast<Potential::Type>(potentialIdx) == Potential::Type::NoHealing)
        {
            iconPixmap = new QPixmap(":/ui/potential_nohealing.png");
        }
        else if (static_cast<Potential::Type>(potentialIdx) == Potential::Type::CriticalHit)
        {
            iconPixmap = new QPixmap(":/ui/potential_criticalhit.png");
        }
        else if (static_cast<Potential::Type>(potentialIdx) == Potential::Type::SlotBind)
        {
            iconPixmap = new QPixmap(":/ui/potential_slotbind.png");
        }
        else if (static_cast<Potential::Type>(potentialIdx) == Potential::Type::BarrierPenetration)
        {
            iconPixmap = new QPixmap(":/ui/potential_barrierPenetration.png");
        }
        else if (static_cast<Potential::Type>(potentialIdx) == Potential::Type::PinchHealing)
        {
            iconPixmap = new QPixmap(":/ui/potential_pinchhealing.png");
        }
        else if (static_cast<Potential::Type>(potentialIdx) == Potential::Type::DMRSTR)
        {
            iconPixmap = new QPixmap(":/ui/potential_dmrstr.png");
        }
        else if (static_cast<Potential::Type>(potentialIdx) == Potential::Type::DMRQCK)
        {
            iconPixmap = new QPixmap(":/ui/potential_dmrqck.png");
        }
        else if (static_cast<Potential::Type>(potentialIdx) == Potential::Type::DMRDEX)
        {
            iconPixmap = new QPixmap(":/ui/potential_dmrdex.png");
        }
        else if (static_cast<Potential::Type>(potentialIdx) == Potential::Type::DMRPSY)
        {
            iconPixmap = new QPixmap(":/ui/potential_dmrpsy.png");
        }
        else if (static_cast<Potential::Type>(potentialIdx) == Potential::Type::DMRINT)
        {
            iconPixmap = new QPixmap(":/ui/potential_dmrint.png");
        }
        else if (static_cast<Potential::Type>(potentialIdx) == Potential::Type::CDR)
        {
            iconPixmap = new QPixmap(":/ui/potential_cd.png");
        }
        else if (static_cast<Potential::Type>(potentialIdx) == Potential::Type::DoubleSpecial)
        {
            iconPixmap = new QPixmap(":/ui/potential_doublespecial.png");
        }
        else
        {
            iconPixmap = new QPixmap(":/ui/potential_frame.png");
        }

        if (iconPixmap != nullptr)
        {
            QIcon icon(iconPixmap->scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            potentialToIcon[static_cast<Potential::Type>(potentialIdx)] = icon;
        }
    }
}

void ConditionWidget::on_secondaryNumericValueEdit_textChanged(const QString &_text)
{
    if (_text.size() > 0)
    {
        std::string text = _text.toUtf8().constData();
        std::string lastChar = text.substr(text.size() - 1);

        // Check if last character is a number
        if (!is_number(lastChar))
        {
            text = text.substr(0, text.size() - 1);
            ui->secondaryNumericValueEdit->setText(QString::fromStdString(text));
        }

        // Check if where added points or letters befor last character
        std::string correctText = "";
        for (size_t i = 0; i < text.size(); ++i)
        {
            std::string letter = text.substr(i, 1);
            if (!is_number(letter))
            {
                letter = "";
            }
            correctText += letter;
        }
        ui->secondaryNumericValueEdit->setText(QString::fromStdString(correctText));

    }
}

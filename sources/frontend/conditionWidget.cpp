#include <conditionWidget.h>
#include "ui_conditionWidget.h"
#include <QDoubleValidator>
#include <cctype>
#include <algorithm>
#include <string>

ConditionWidget::ConditionWidget(QWidget *_parent) :
    QWidget(_parent),
    ui(new Ui::ConditionWidget),
    dummy(new Condition("Dummy", Condition::Target::EndPrimaryTargets, Condition::Operator::NumOperators, "0"))
{
    ui->setupUi(this);
    ui->targetBox->setEnabled(false);
    ui->secondaryTargetBox->hide();
    ui->operatorBox->hide();
    ui->numericValueEdit->hide();
    ui->stringValueEdit->hide();
    ui->includeLimitBreak->hide();
    ui->typeClassValueBox->hide();
    ui->typeClassTargetBox->hide();

    for (int i = static_cast<int>(Condition::Target::PrimaryTargets); i < static_cast<int>(Condition::Target::EndPrimaryTargets); ++i)
    {
        std::string target = dummy->getDescriptionFromTarget(static_cast<Condition::Target>(i));
        QString targetString(QString::fromStdString(target));
        ui->targetBox->addItem(targetString);
    }
}

ConditionWidget::~ConditionWidget()
{
    delete ui;
}

void ConditionWidget::enableWidget()
{
    ui->targetBox->setEnabled(true);
}

void ConditionWidget::on_targetBox_currentIndexChanged(const QString &_text)
{
    std::string target = _text.toUtf8().constData();
    if (_text == "")
    {
        ui->secondaryTargetBox->hide();
        ui->operatorBox->hide();
        ui->numericValueEdit->hide();
        ui->stringValueEdit->hide();
        ui->includeLimitBreak->hide();
        ui->typeClassValueBox->hide();
        ui->typeClassTargetBox->hide();
    }
    else
    {
        Condition::Target primaryTarget = dummy->getTargetFromDescription(target);
        if (primaryTarget == Condition::Target::Stats)
        {
            ui->secondaryTargetBox->clear();
            ui->secondaryTargetBox->show();

            ui->numericValueEdit->clear();
            ui->numericValueEdit->show();

            ui->typeClassValueBox->hide();
            ui->typeClassTargetBox->hide();


            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(primaryTarget);
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();
            for (int i = static_cast<int>(Condition::Target::StatsTargets); i < static_cast<int>(Condition::Target::EndStatsTargets); ++i)
            {
                std::string secondaryTarget = dummy->getDescriptionFromTarget(static_cast<Condition::Target>(i));
                QString targetString(QString::fromStdString(secondaryTarget));
                ui->secondaryTargetBox->addItem(targetString);
            }
        }
        else if (primaryTarget == Condition::Target::Slots)
        {
            ui->secondaryTargetBox->hide();
            ui->typeClassValueBox->hide();
            ui->typeClassTargetBox->hide();

            ui->includeLimitBreak->show();

            ui->numericValueEdit->clear();
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
            ui->typeClassValueBox->clear();
            ui->typeClassValueBox->show();

            ui->numericValueEdit->hide();
            ui->stringValueEdit->hide();
            ui->typeClassTargetBox->hide();
            if (primaryTarget == Condition::Target::Type)
            {
                for (int i = static_cast<int>(Type::StartType) + 1; i < static_cast<int>(Type::EndTypes); ++i)
                {
                    std::string type = to_string(static_cast<Type>(i));
                    QString typeString(QString::fromStdString(type));
                    QPixmap* iconPixmap = nullptr;
                    if (static_cast<Type>(i) == Type::STR)
                    {
                        iconPixmap = new QPixmap(":/ui/str.png");
                    }
                    else if (static_cast<Type>(i) == Type::DEX)
                    {
                        iconPixmap = new QPixmap(":/ui/dex.png");
                    }
                    else if (static_cast<Type>(i) == Type::QCK)
                    {
                        iconPixmap = new QPixmap(":/ui/qck.png");
                    }
                    else if (static_cast<Type>(i) == Type::PSY)
                    {
                        iconPixmap = new QPixmap(":/ui/psy.png");
                    }
                    else if (static_cast<Type>(i) == Type::INT)
                    {
                        iconPixmap = new QPixmap(":/ui/int.png");
                    }

                    // Create item
                    if (iconPixmap != nullptr)
                    {
                        QIcon icon(iconPixmap->scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                        ui->typeClassValueBox->addItem(icon, typeString);
                    }
                    else
                    {
                        ui->typeClassValueBox->addItem(typeString);
                    }
                }
            }
            else
            {
                for (int i = static_cast<int>(Class::StartClass) + 1; i < static_cast<int>(Class::EndClasses); ++i)
                {
                    std::string chClass = to_string(static_cast<Class>(i));
                    QString classString(QString::fromStdString(chClass));
                    QPixmap* iconPixmap = nullptr;
                    if (static_cast<Class>(i) == Class::Fighter)
                    {
                        iconPixmap = new QPixmap(":/ui/fighter_icon.png");
                    }
                    else if (static_cast<Class>(i) == Class::Shooter)
                    {
                        iconPixmap = new QPixmap(":/ui/shooter_icon.png");
                    }
                    else if (static_cast<Class>(i) == Class::Slasher)
                    {
                        iconPixmap = new QPixmap(":/ui/slasher_icon.png");
                    }
                    else if (static_cast<Class>(i) == Class::Striker)
                    {
                        iconPixmap = new QPixmap(":/ui/striker_icon.png");
                    }
                    else if (static_cast<Class>(i) == Class::Free_Spirit)
                    {
                        iconPixmap = new QPixmap(":/ui/freespirit_icon.png");
                    }
                    else if (static_cast<Class>(i) == Class::Cerebral)
                    {
                        iconPixmap = new QPixmap(":/ui/cerebral_icon.png");
                    }
                    else if (static_cast<Class>(i) == Class::Powerhouse)
                    {
                        iconPixmap = new QPixmap(":/ui/powerhouse_icon.png");
                    }
                    else if (static_cast<Class>(i) == Class::Driven)
                    {
                        iconPixmap = new QPixmap(":/ui/driven_icon.png");
                    }
                    else if (static_cast<Class>(i) == Class::Evolver)
                    {
                        iconPixmap = new QPixmap(":/ui/evolver_icon.png");
                    }
                    else if (static_cast<Class>(i) == Class::Booster)
                    {
                        iconPixmap = new QPixmap(":/ui/booster_icon.png");
                    }

                    // Create item
                    if (iconPixmap != nullptr)
                    {
                        QIcon icon(iconPixmap->scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                        ui->typeClassValueBox->addItem(icon, classString);
                    }
                    else
                    {
                        ui->typeClassValueBox->addItem(classString);
                    }
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
            ui->typeClassValueBox->hide();
            ui->includeLimitBreak->hide();

            ui->secondaryTargetBox->clear();
            ui->secondaryTargetBox->show();

            ui->numericValueEdit->clear();
            ui->numericValueEdit->hide();

            ui->operatorBox->clear();
            ui->operatorBox->hide();

            for (int i = static_cast<int>(Condition::Target::CaptainTargets); i < static_cast<int>(Condition::Target::EndCaptainTargets); ++i)
            {
                std::string secondaryTarget = dummy->getDescriptionFromTarget(static_cast<Condition::Target>(i));
                QString targetString(QString::fromStdString(secondaryTarget));
                ui->secondaryTargetBox->addItem(targetString);
            }
        }
        else if (primaryTarget == Condition::Target::Evolution)
        {
            ui->includeLimitBreak->hide();
            ui->numericValueEdit->hide();
            ui->typeClassValueBox->hide();
            ui->operatorBox->hide();

            ui->secondaryTargetBox->clear();
            ui->secondaryTargetBox->show();
            for (int i = static_cast<int>(Condition::Target::EvolutionTargets) + 1; i < static_cast<int>(Condition::Target::EndEvolutionTargets); ++i)
            {
                std::string secondaryTarget = dummy->getDescriptionFromTarget(static_cast<Condition::Target>(i));
                QString targetString(QString::fromStdString(secondaryTarget));
                ui->secondaryTargetBox->addItem(targetString);
            }
        }
        else if (primaryTarget == Condition::Target::LimitBreak)
        {
            ui->includeLimitBreak->hide();
            ui->numericValueEdit->hide();

            ui->secondaryTargetBox->clear();
            ui->secondaryTargetBox->show();
            for (int i = static_cast<int>(Condition::Target::LimitBreakTargets) + 1; i < static_cast<int>(Condition::Target::EndLimitBreakTargets); ++i)
            {
                std::string secondaryTarget = dummy->getDescriptionFromTarget(static_cast<Condition::Target>(i));
                QString targetString(QString::fromStdString(secondaryTarget));
                ui->secondaryTargetBox->addItem(targetString);
            }
            ui->typeClassValueBox->hide();
            ui->operatorBox->hide();
        }
        else if (primaryTarget == Condition::Target::Availability)
        {
            ui->includeLimitBreak->hide();
            ui->secondaryTargetBox->hide();
            ui->numericValueEdit->hide();

            ui->typeClassValueBox->clear();
            ui->typeClassValueBox->show();

            for (int i = static_cast<int>(Availability::StartAvailability) + 1; i < static_cast<int>(Availability::EndAvailability); ++i)
            {
                std::string secondaryTarget = to_string((static_cast<Availability>(i)));
                QString targetString(QString::fromStdString(secondaryTarget));
                ui->typeClassValueBox->addItem(targetString);
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
            ui->numericValueEdit->hide();
            ui->typeClassValueBox->hide();

            ui->includeLimitBreak->show();
            ui->secondaryTargetBox->clear();
            ui->secondaryTargetBox->show();

            for (int i = static_cast<int>(Condition::Target::SailorTargets); i < static_cast<int>(Condition::Target::EndSailorTargets); ++i)
            {
                std::string secondaryTarget = dummy->getDescriptionFromTarget(static_cast<Condition::Target>(i));
                QString targetString(QString::fromStdString(secondaryTarget));
                ui->secondaryTargetBox->addItem(targetString);
            }

            ui->operatorBox->clear();
            ui->operatorBox->hide();
        }
        else if (primaryTarget == Condition::Target::Tandem)
        {
            ui->typeClassValueBox->hide();
            ui->secondaryTargetBox->hide();
            ui->includeLimitBreak->hide();
            ui->typeClassTargetBox->hide();
            ui->numericValueEdit->hide();
            ui->stringValueEdit->hide();
            ui->operatorBox->hide();
        }
        else
        {
            ui->typeClassValueBox->hide();
            ui->secondaryTargetBox->hide();
            ui->includeLimitBreak->hide();
            ui->typeClassTargetBox->hide();
            if (primaryTarget == Condition::Target::Name)
            {
                ui->stringValueEdit->clear();
                ui->stringValueEdit->show();
                ui->numericValueEdit->hide();
            }
            else
            {
                ui->numericValueEdit->clear();
                ui->numericValueEdit->show();
                ui->stringValueEdit->hide();
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
    }
}

void ConditionWidget::on_secondaryTargetBox_currentIndexChanged(const QString &_text)
{
    std::string target = _text.toUtf8().constData();
    if (_text == "")
    {
        ui->includeLimitBreak->hide();
        ui->typeClassTargetBox->hide();
        ui->typeClassValueBox->hide();
    }
    else
    {
        Condition::Target secondaryTarget = dummy->getTargetFromDescription(target);
        if (secondaryTarget == Condition::Target::maxHp || secondaryTarget == Condition::Target::maxAtk || secondaryTarget == Condition::Target::maxRcv ||
                secondaryTarget == Condition::Target::minHp || secondaryTarget == Condition::Target::minAtk || secondaryTarget == Condition::Target::minRcv)
        {
            ui->includeLimitBreak->hide();
            ui->typeClassValueBox->hide();
            ui->numericValueEdit->clear();
            ui->numericValueEdit->show();
            ui->operatorBox->clear();
            Condition::Target primaryTarget = dummy->getTargetFromDescription(ui->targetBox->currentText().toUtf8().constData());
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
            ui->typeClassValueBox->clear();
            ui->typeClassValueBox->show();
            for (int i = static_cast<int>(Potential::Type::StartPotential) + 1; i < static_cast<int>(Potential::Type::None); ++i)
            {
                Potential dummyPotential(Potential::Type::None, 1);
                std::string secondaryTarget = dummyPotential.getDescriptionFromType((static_cast<Potential::Type>(i)));

                QPixmap* iconPixmap = nullptr;
                if (static_cast<Potential::Type>(i) == Potential::Type::Enrage)
                {
                    iconPixmap = new QPixmap(":/ui/potential_enrage.png");
                }
                else if (static_cast<Potential::Type>(i) == Potential::Type::NoHealing)
                {
                    iconPixmap = new QPixmap(":/ui/potential_nohealing.png");
                }
                else if (static_cast<Potential::Type>(i) == Potential::Type::CriticalHit)
                {
                    iconPixmap = new QPixmap(":/ui/potential_criticalhit.png");
                }
                else if (static_cast<Potential::Type>(i) == Potential::Type::SlotBind)
                {
                    iconPixmap = new QPixmap(":/ui/potential_slotbind.png");
                }
                else if (static_cast<Potential::Type>(i) == Potential::Type::BarrierPenetration)
                {
                    iconPixmap = new QPixmap(":/ui/potential_barrierPenetration.png");
                }
                else if (static_cast<Potential::Type>(i) == Potential::Type::PinchHealing)
                {
                    iconPixmap = new QPixmap(":/ui/potential_pinchhealing.png");
                }
                else if (static_cast<Potential::Type>(i) == Potential::Type::DMRSTR)
                {
                    iconPixmap = new QPixmap(":/ui/potential_dmrstr.png");
                }
                else if (static_cast<Potential::Type>(i) == Potential::Type::DMRQCK)
                {
                    iconPixmap = new QPixmap(":/ui/potential_dmrqck.png");
                }
                else if (static_cast<Potential::Type>(i) == Potential::Type::DMRDEX)
                {
                    iconPixmap = new QPixmap(":/ui/potential_dmrdex.png");
                }
                else if (static_cast<Potential::Type>(i) == Potential::Type::DMRPSY)
                {
                    iconPixmap = new QPixmap(":/ui/potential_dmrpsy.png");
                }
                else if (static_cast<Potential::Type>(i) == Potential::Type::DMRINT)
                {
                    iconPixmap = new QPixmap(":/ui/potential_dmrint.png");
                }
                else if (static_cast<Potential::Type>(i) == Potential::Type::CDR)
                {
                    iconPixmap = new QPixmap(":/ui/potential_cd.png");
                }
                else if (static_cast<Potential::Type>(i) == Potential::Type::DoubleSpecial)
                {
                    iconPixmap = new QPixmap(":/ui/potential_doublespecial.png");
                }
                else
                {
                    iconPixmap = new QPixmap(":/ui/potential_frame.png");
                }
                QIcon icon(iconPixmap->scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));

                QString targetString(QString::fromStdString(secondaryTarget));
                ui->typeClassValueBox->addItem(icon, targetString);
            }

            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(dummy->getTargetFromDescription(ui->targetBox->currentText().toUtf8().constData()));
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();
        }
        else if (secondaryTarget == Condition::Target::BoostHP || secondaryTarget == Condition::Target::BoostATK || secondaryTarget == Condition::Target::BoostRCV)
        {
            ui->typeClassValueBox->hide();
            ui->typeClassTargetBox->clear();
            ui->typeClassTargetBox->show();
            ui->typeClassTargetBox->addItem("Generic");
            ui->typeClassTargetBox->addItem("All Characters");

            ui->numericValueEdit->clear();
            ui->numericValueEdit->show();

            // Add all types and classes
            for (int i = static_cast<int>(Type::StartType) + 1; i < static_cast<int>(Type::EndTypes); ++i)
            {
                std::string type = to_string(static_cast<Type>(i));
                QString typeString(QString::fromStdString(type));
                ui->typeClassTargetBox->addItem(typeString);
            }
            for (int i = static_cast<int>(Class::StartClass) + 1; i < static_cast<int>(Class::EndClasses); ++i)
            {
                std::string chClass = to_string(static_cast<Class>(i));
                QString classString(QString::fromStdString(chClass));
                ui->typeClassTargetBox->addItem(classString);
            }

            // Add operators
            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(dummy->getTargetFromDescription(ui->targetBox->currentText().toUtf8().constData()));
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();
        }
        else if (secondaryTarget == Condition::Target::BeliBooster || secondaryTarget == Condition::Target::ExpBooster || secondaryTarget == Condition::Target::CdReducer || secondaryTarget == Condition::Target::DamageReducer)
        {
            ui->includeLimitBreak->hide();
            ui->typeClassTargetBox->hide();
            ui->typeClassValueBox->hide();

            ui->numericValueEdit->clear();
            ui->numericValueEdit->show();

            // Add operators
            ui->operatorBox->clear();
            std::vector<std::string> operators = dummy->getPossibleOperators(dummy->getTargetFromDescription(ui->targetBox->currentText().toUtf8().constData()));
            for (auto op : operators)
            {
                QString opText = QString::fromStdString(op);
                ui->operatorBox->addItem(opText);
            }
            ui->operatorBox->show();
        }
        else if (secondaryTarget == Condition::Target::BoostHPSailor || secondaryTarget == Condition::Target::BoostATKSailor || secondaryTarget == Condition::Target::BoostRCVSailor)
        {
            ui->numericValueEdit->hide();
            ui->operatorBox->hide();
            ui->typeClassValueBox->hide();

            ui->includeLimitBreak->setChecked(false);
            ui->includeLimitBreak->show();

            ui->typeClassTargetBox->clear();
            ui->typeClassTargetBox->show();

            ui->typeClassTargetBox->addItem("Generic");
            ui->typeClassTargetBox->addItem("All Characters");
            // Add all types and classes
            for (int i = static_cast<int>(Type::StartType) + 1; i < static_cast<int>(Type::EndTypes); ++i)
            {
                std::string type = to_string(static_cast<Type>(i));
                QString typeString(QString::fromStdString(type));
                ui->typeClassTargetBox->addItem(typeString);
            }
            for (int i = static_cast<int>(Class::StartClass) + 1; i < static_cast<int>(Class::EndClasses); ++i)
            {
                std::string chClass = to_string(static_cast<Class>(i));
                QString classString(QString::fromStdString(chClass));
                ui->typeClassTargetBox->addItem(classString);
            }
        }
        else if (secondaryTarget == Condition::Target::ParalysisReducer || secondaryTarget == Condition::Target::BlindnessReducer || secondaryTarget == Condition::Target::SilenceReducer ||
                 secondaryTarget == Condition::Target::SpecialRewindReducer || secondaryTarget == Condition::Target::SpecialCdSailor || secondaryTarget == Condition::Target::BlownAway || secondaryTarget == Condition::Target::AdditionalDamage)
        {
            ui->numericValueEdit->hide();
            ui->operatorBox->hide();
            ui->typeClassTargetBox->hide();
            ui->includeLimitBreak->setChecked(false);
            ui->includeLimitBreak->show();
            ui->typeClassValueBox->hide();
        }
        else if (secondaryTarget == Condition::Target::OrbKeeper || secondaryTarget == Condition::Target::BeneficialOrb)
        {
            ui->numericValueEdit->hide();
            ui->operatorBox->hide();
            ui->typeClassTargetBox->hide();
            ui->includeLimitBreak->setChecked(false);
            ui->includeLimitBreak->show();


            ui->typeClassTargetBox->clear();
            ui->typeClassTargetBox->show();

            ui->typeClassTargetBox->addItem("Generic");
            // Add all types and classes
            for (int i = static_cast<int>(Slots::StartSlots) + 1; i < static_cast<int>(Slots::EndSlots); ++i)
            {
                std::string slot = to_string(static_cast<Slots>(i));
                QString slotString(QString::fromStdString(slot));
                ui->typeClassTargetBox->addItem(slotString);
            }

            if (secondaryTarget == Condition::Target::OrbKeeper)
            {
                ui->typeClassValueBox->clear();
                ui->typeClassValueBox->addItem("Generic");
                ui->typeClassValueBox->addItem("Good");
                ui->typeClassValueBox->addItem("Great");
                ui->typeClassValueBox->addItem("Perfect");
                ui->typeClassValueBox->show();
            }
            else
            {
                ui->typeClassValueBox->clear();
                ui->typeClassValueBox->addItem("Self");
                ui->typeClassValueBox->addItem("All Characters");
                // Add all types and classes
                for (int i = static_cast<int>(Type::StartType) + 1; i < static_cast<int>(Type::EndTypes); ++i)
                {
                    std::string type = to_string(static_cast<Type>(i));
                    QString typeString(QString::fromStdString(type));
                    ui->typeClassValueBox->addItem(typeString);
                }
                for (int i = static_cast<int>(Class::StartClass) + 1; i < static_cast<int>(Class::EndClasses); ++i)
                {
                    std::string chClass = to_string(static_cast<Class>(i));
                    QString classString(QString::fromStdString(chClass));
                    ui->typeClassValueBox->addItem(classString);
                }
                ui->typeClassValueBox->show();
            }
        }
        else
        {
            ui->numericValueEdit->hide();
            ui->operatorBox->hide();
            ui->includeLimitBreak->hide();
            ui->typeClassTargetBox->hide();
            ui->typeClassValueBox->hide();
        }
    }
}

Condition ConditionWidget::getCondition()
{
    if (ui->targetBox->currentText() != "")
    {
        Condition::Target target = dummy->getTargetFromDescription(ui->targetBox->currentText().toUtf8().constData());
        Condition::Operator op = dummy->getOperatorFromDescription(ui->operatorBox->currentText().toUtf8().constData());
        std::string value = ui->numericValueEdit->isHidden() ? ui->stringValueEdit->text().toUtf8().constData() : ui->numericValueEdit->text().toUtf8().constData();
        Condition condition("", target, op, value);
        if (!ui->secondaryTargetBox->isHidden())
        {
            condition.setSecondaryTarget(dummy->getTargetFromDescription(ui->secondaryTargetBox->currentText().toUtf8().constData()));
        }

        if (!ui->includeLimitBreak->isHidden())
        {
            condition.setIncludeLimitBreak(ui->includeLimitBreak->isChecked());
        }

        if (!ui->typeClassTargetBox->isHidden())
        {
            Condition::Target secondaryTarget = dummy->getTargetFromDescription(ui->secondaryTargetBox->currentText().toUtf8().constData());

            if (secondaryTarget == Condition::Target::BoostHP || secondaryTarget == Condition::Target::BoostATK || secondaryTarget == Condition::Target::BoostRCV ||
                    secondaryTarget == Condition::Target::BoostHPSailor || secondaryTarget == Condition::Target::BoostATKSailor || secondaryTarget == Condition::Target::BoostRCVSailor)
            {
                std::string typeClassTargetBox = ui->typeClassTargetBox->currentText().toUtf8().constData();
                if (typeClassTargetBox == "All Characters")
                {
                    condition.setTypeTarget(Type::StartType);
                }
                else if (typeClassTargetBox == "Generic")
                {
                    condition.setTypeTarget(Type::EndTypes);
                }
                else
                {
                    bool isType = false;
                    for (int i = static_cast<int>(Type::StartType) + 1; i < static_cast<int>(Type::EndTypes); ++i)
                    {
                        std::string type = to_string(static_cast<Type>(i));
                        if (typeClassTargetBox == type)
                        {
                            isType = true;
                            break;
                        }
                    }

                    if (isType)
                    {
                        condition.setTypeTarget(stringToType(typeClassTargetBox));
                    }
                    else
                    {
                        condition.setClassTarget(stringToClass(typeClassTargetBox));
                    }
                }
            }
            else if (secondaryTarget == Condition::Target::OrbKeeper || secondaryTarget == Condition::Target::BeneficialOrb)
            {
                std::string currentSlot = ui->typeClassTargetBox->currentText().toUtf8().constData();
                if (currentSlot != "Generic")
                {
                    condition.setSlotsTarget(stringToSlots(currentSlot));
                }
                else
                {
                    condition.setSlotsTarget(Slots::StartSlots);
                }
            }
        }

        if (!ui->typeClassValueBox->isHidden())
        {
            Condition::Target target = dummy->getTargetFromDescription(ui->targetBox->currentText().toUtf8().constData());
            if (target == Condition::Target::Type)
            {
                condition.setTypeValue(stringToType(ui->typeClassValueBox->currentText().toUtf8().constData()));
            }
            else if (target == Condition::Target::Class || target == Condition::Target::PrimaryClass || target == Condition::Target::SecondaryClass)
            {
                condition.setClassValue(stringToClass(ui->typeClassValueBox->currentText().toUtf8().constData()));
            }
            else if (target == Condition::Target::LimitBreak)
            {
                Potential dummyPotential(Potential::Type::None, 1);
                condition.setPotentialTarget(dummyPotential.getTypeFromDescription(ui->typeClassValueBox->currentText().toUtf8().constData()));
            }
            else if (target == Condition::Target::Availability)
            {
                condition.setAvailabilityTarget(stringToAvailability(ui->typeClassValueBox->currentText().toUtf8().constData()));
            }
            else if (target == Condition::Target::Sailor)
            {
                Condition::Target secondaryTarget = dummy->getTargetFromDescription(ui->secondaryTargetBox->currentText().toUtf8().constData());
                std::string typeClassValueBox = ui->typeClassValueBox->currentText().toUtf8().constData();
                if (secondaryTarget == Condition::Target::OrbKeeper)
                {
                    if (typeClassValueBox != "Generic")
                    {
                        condition.setValue(ui->typeClassValueBox->currentText().toUtf8().constData());
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

        return condition;
    }
    return Condition("", Condition::Target::PrimaryTargets, Condition::Operator::NumOperators, "");
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
            Condition::Target target = dummy->getTargetFromDescription(ui->targetBox->currentText().toUtf8().constData());
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
    }
}

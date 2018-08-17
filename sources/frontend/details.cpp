#include "details.h"
#include "ui_details.h"
#include <iomanip>
#include <sstream>
#include <QFileInfo>

QString getClassIcon(Class& _class);

Details::Details(Utility* _utility, short _characterId, QWidget *_parent) :
    QDialog(_parent),
    ui(new Ui::Details),
    utility(_utility),
    characterId(_characterId)
{
    ui->setupUi(this);
    connect(this, SIGNAL(changeCharacterDetail(int)), this->parent(), SLOT(changeDetails(int)));

    characters = utility->characters;
    myCharacters = utility->myCharacters;

    loadCharacter(characterId);

    if (!utility->characters->at(characterId - 1)->hasDual())
    {
        ui->LeftButton->hide();
        ui->RightButton->hide();
    }
    // Set owned box
    if (myCharacters->find(characterId) != myCharacters->end())
    {
        ui->ownedBox->setChecked(true);
    }
    else
    {
        ui->ownedBox->setChecked(false);
    }


}

Details::~Details()
{
    delete ui;
}

void Details::on_ownedBox_toggled(bool checked)
{

    if (checked)
    {
        MyCharacter myChar(characters->at(characterId - 1));
        (*myCharacters)[characterId] = &myChar;
    }
    else
    {
        //TODO check multiple
        int success = myCharacters->erase(characterId);
        if (success)
        {
            std::cout << "Erased character n." << characterId << std::endl;
        }
    }
    emit changedOwnedState();
}


void Details::removeTab(QString name)
{
    QWidget* page = ui->detailsTabWidget->findChild<QWidget*>(name);
    int index = ui->detailsTabWidget->indexOf(page);
    ui->detailsTabWidget->removeTab(index);
}


void Details::loadCharacter(short _characterId)
{
    Character* character = utility->characters->at(_characterId - 1);

    setName(character);
    setArt(character);
    setTypes(character);
    setRarity(character);
    setClasses(character);
    setStatsTab(character);
    setCaptainTab(character);
    setCaptainActionTab(character);
    setSwapTab(character);
    setSailorTab(character);
    setSpecialTab(character);
    setLimitBreakTab(character);
    setEvolutionTab(character);
}

void Details::setArt(Character* _character)
{
    std::ostringstream ss;

    ss << std::setw(4) << std::setfill('0') << _character->getId();
    QString id(ss.str().c_str());
    QString workingPath =  QDir::currentPath().toUtf8().constData();
    QString characterArtPath = workingPath + "/resources/arts/c" + id + ".png";
    QPixmap* pixmap;
    if(QFileInfo::exists(characterArtPath) && QFileInfo(characterArtPath).isFile())
    {
        pixmap = new QPixmap(characterArtPath);
    }
    else
    {
        Type ch_type = _character->getType().empty()? Type::None : _character->getType().at(0);
        QString type(QString::fromStdString(to_string(ch_type)));
        pixmap = new QPixmap(workingPath + "/resources/icons/blank_" + type.toLower() + ".png");
    }

    *pixmap = pixmap->scaled(250, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->imageLabel->setPixmap(*pixmap);
}

void Details::setName(Character* _character)
{
    ui->nameLabel->setText(QString::fromStdString(_character->getName()));
}

void Details::setTypes(Character* _character)
{
    QString workingPath =  QDir::currentPath().toUtf8().constData();
    std::vector<Type> types = _character->getType();
    for (unsigned long i = 0; i < types.size(); ++i)
    {
        Type type = types.at(i);
        QString typing = QString::fromStdString(to_string(type));
        QPixmap typeImage(workingPath + "/resources/ui/" + typing.toLower() + ".png");
        typeImage = typeImage.scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation);

        if (i == 0)
        {
            ui->typeLabel->setPixmap(typeImage);
            if (types.size() == 1)
            {
                ui->type2Label->hide();
            }
        }
        else
        {
            if (ui->type2Label->isHidden())
            {
                ui->type2Label->show();
            }
            ui->type2Label->setPixmap(typeImage);
        }
    }
}

void Details::setRarity(Character* _character)
{
    QString workingPath =  QDir::currentPath().toUtf8().constData();
    QString starPath = workingPath + "/resources/ui/star.png";
    QPixmap* starPixmap;
    if(QFileInfo::exists(starPath) && QFileInfo(starPath).isFile())
    {
        starPixmap = new QPixmap(starPath);
    }
    *starPixmap = starPixmap->scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    QHBoxLayout *hBox = new QHBoxLayout;
    hBox->setAlignment(Qt::AlignHCenter);
    Stats* stats = _character->getStats();
    for (int i = 0; i < stats->stars; ++i)
    {
        QLabel* starLabel = new QLabel(this);
        starLabel->setPixmap(*starPixmap);
        hBox->addWidget(starLabel);
    }

    if (stats->plus)
    {
        QString plusPath = workingPath + "/resources/ui/plus.png";
        QPixmap* plusPixmap;
        if(QFileInfo::exists(plusPath) && QFileInfo(plusPath).isFile())
        {
            plusPixmap = new QPixmap(plusPath);
        }
        *plusPixmap = plusPixmap->scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation);

        QLabel* plusLabel = new QLabel(this);
        plusLabel->setPixmap(*plusPixmap);
        hBox->addWidget(plusLabel);
    }

    ui->starLayout->addRow(hBox);
}

void Details::setClasses(Character* _character)
{
    QString workingPath =  QDir::currentPath().toUtf8().constData();
    /* Setting class*/
    Class firstClass = _character->getFirstClass();
    Class secondClass = _character->getSecondClass();
    QString firstIcon = getClassIcon(firstClass);
    QPixmap firstClassImage(workingPath + "/resources/ui/" + firstIcon + "_icon.png");
    firstClassImage = firstClassImage.scaled(28, 28, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap firstClassDesc(workingPath + "/resources/ui/" + firstIcon + "_desc.png");
    firstClassDesc = firstClassDesc.scaled(64, 13, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    ui->classeP->setPixmap(firstClassImage);
    ui->classePDesc->setPixmap(firstClassDesc);
    if (secondClass != Class::None)
    {
        QString secondIcon = getClassIcon(secondClass);
        QPixmap secondClassImage(workingPath + "/resources/ui/" + secondIcon + "_icon.png");
        secondClassImage = secondClassImage.scaled(28, 28, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QPixmap secondClassDesc(workingPath + "/resources/ui/" + secondIcon + "_desc.png");
        secondClassDesc = secondClassDesc.scaled(64, 13, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->classeS->setPixmap(secondClassImage);
        ui->classeSDesc->setPixmap(secondClassDesc);
    }
    else
    {
        delete ui->classeS;
        delete ui->classeSDesc;
    }
}

void Details::setStatsTab(Character* _character)
{
    Stats* stats = _character->getStats();

    /* Add Stats box */
    ui->idLabel->setText("<b>Id:</b> " + QString::number(characterId));
    ui->costLabel->setText("<b>Cost:</b> " + QString::number(stats->cost));
    ui->comboLabel->setText("<b>Combo:</b> " + QString::number(stats->combo));
    ui->expLabel->setText("<b>Exp to Max:</b> " + QString::number(stats->exp_to_max));
    QString socketString = "<b>Socket:</b> " + QString::number(stats->num_sockets);

    ui->levelMaxLabel->setText("Lv." + QString::number(stats->max_level));
    ui->hpMinLabel->setText(QString::number(stats->hp_min));
    ui->hpMaxLabel->setText(QString::number(stats->hp_max));
    ui->atkMinLabel->setText(QString::number(stats->atk_min));
    ui->atkMaxLabel->setText(QString::number(stats->atk_max));
    ui->rcvMinLabel->setText(QString::number(stats->rcv_min));
    ui->rcvMaxLabel->setText(QString::number(stats->rcv_max));

    if (_character->hasLimitBreak())
    {
        LimitBreak* limit = _character->getLimitBreak();
        LimitBreak::Improvements improvements = limit->getAllImprovements();
        ui->hpLimitBreak->setText(QString::number(stats->hp_max + improvements.hp) + " (+" + QString::number(improvements.hp) + ")");
        ui->atkLimitBreak->setText(QString::number(stats->atk_max + improvements.atk) + " (+" + QString::number(improvements.atk) + ")");
        ui->rcvLimitBreak->setText(QString::number(stats->rcv_max + improvements.rcv) + " (+" + QString::number(improvements.rcv) + ")");
        if (improvements.socket > 0)
        {
            socketString += "->" + QString::number(stats->num_sockets + improvements.socket);
        }
    }
    else
    {
        Tools::removeColumn(ui->statsLayout, 3, true);
    }
    ui->socketLabel->setText(socketString);
}

void Details::setCaptainTab(Character* _character)
{
    /* Setting captain tab */
    QString capString;
    if (_character->hasCaptain())
    {
        capString += "<p><b>Captain Ability</b></p>";
        capString += "<p>" + QString::fromStdString(_character->getCaptain()->getDescription()) + "</p>";
    }

    if (_character->hasLimitBreak())
    {
        LimitBreak* lb = _character->getLimitBreak();
        if (lb->hasNewCaptainAbilities())
        {
            std::vector<Captain> new_captain_abilities = lb->getNewCaptainAbilities();
            for (unsigned long i = 0; i < new_captain_abilities.size(); ++i)
            {
                int lbLevel = i - new_captain_abilities.size() + 1;
                capString += "<p><b> Captain Ability Limit Break ";
                if (lbLevel == 0)
                {
                    capString += "Max";
                }
                else
                {
                    capString += QString::number(i + 1);
                }
                capString += "</b></p>";
                capString += "<p>" + QString::fromStdString(new_captain_abilities.at(i).getDescription()) + "</p>";
            }
        }
    }

    if (capString.length() != 0)
    {
        ui->capAbilityLabel->setText(capString);
    }
    else
    {
        removeTab("Captain");
    }
}

void Details::setCaptainActionTab(Character* _character)
{
    /* Setting sailor tab */
    if (_character->hasCaptainAction())
    {
        QString captainText("<p><b>Captain Action</b></p>");
        captainText += "<p>" + QString::fromStdString(_character->getCaptainAction()->getDescription()) + "</p>";
        ui->capActionLabel->setText(captainText);
    }
    else
    {
        removeTab("CaptainAction");
    }
}

void Details::setSwapTab(Character* _character)
{
    /* Setting swap tab */
    if (_character->hasDual())
    {
        QString swapText("<p><b>On Swap</b></p>");
        swapText += "<p>" + QString::fromStdString(_character->getSwapDescription()) + "</p>";
        ui->swapLabel->setText(swapText);
    }
    else
    {
        removeTab("Swap");
    }
}

void Details::setSailorTab(Character* _character)
{
    /* Setting sailor tab */
    QString sailorString;
    int numSailor = 0;
    if (_character->hasSailor())
    {
        std::vector<Sailor> sailors = _character->getSailors();
        for (Sailor sailor : sailors)
        {
            numSailor++;
            sailorString += "<p><b>Sailor Ability " + QString::number(numSailor) + "</b></p>";
            sailorString += "<p>" + QString::fromStdString(sailor.getDescription()) + "</p>";
        }
    }

    if (_character->hasLimitBreak())
    {
        LimitBreak* lb = _character->getLimitBreak();
        if (lb->hasNewSailorAbilities())
        {
            std::vector<Sailor> sailors = lb->getNewSailorAbilities();
            for (Sailor sailor : sailors)
            {
                numSailor++;
                sailorString += "<p><b>Sailor Ability " + QString::number(numSailor) + " (Limit Break)</b></p>";
                sailorString += "<p>" + QString::fromStdString(sailor.getDescription()) + "</p>";
            }
        }
    }

    if (sailorString.length() != 0)
    {
        ui->sailorAbilityLabel->setText(sailorString);
    }
    else
    {
        removeTab("Sailor");
    }
}

void Details::setSpecialTab(Character* _character)
{
    /* Setting special tab */
    if (_character->hasSpecial())
    {
        Special* special = _character->getSpecial();
        QString specialText("<p><b>" + QString::fromStdString(special->getName()) + "</b></p>"); // Add name to special

        short limitCdReduction = 0;
        if (_character->hasLimitBreak())
        {
            LimitBreak *lb = _character->getLimitBreak();
            limitCdReduction = lb->getAllImprovements().cd;
        }
        short cdReduction = special->getBase() - special->getMaxedCd();
        for (unsigned long i = 0; i < special->getDescription().size(); ++i)
        {
            if (!special->hasMultipleStages())
            {
                specialText += "<p>" + QString::fromStdString(special->getDescription().at(i)) + "<br /><br />";
                QString baseCd = special->getBase() > -1 ? QString::number(special->getBase()) : "Unknown";
                QString maxedCd = special->getMaxedCd() > -1 ? QString::number(special->getMaxedCd()) : "Unknown";
                specialText += "(" + baseCd + "->" + maxedCd;
                if (limitCdReduction > 0)
                {
                    specialText += "->" + QString::number(special->getMaxedCd() - limitCdReduction);
                }
                specialText += ")";
            }
            else
            {
                short stageBaseCd = special->getBase() - special->getStageOffset(i + 1);
                specialText += "<p><b>Stage " + QString::number(i + 1) + "</b> ";
                specialText += "(" + QString::number(stageBaseCd) + "->" + QString::number(stageBaseCd - cdReduction);
                if (limitCdReduction > 0)
                {
                    specialText += "->" + QString::number(stageBaseCd - cdReduction - limitCdReduction);
                }
                specialText += "):<br /> " + QString::fromStdString(special->getDescription().at(i)) + "</p>";
            }
        }

        ui->specialAbilityLabel->setText(specialText);
    }
    else
    {
        removeTab("Special");
    }
}

void Details::setLimitBreakTab(Character* _character)
{
    if (_character->hasLimitBreak())
    {
        QString limitBreakString;
        LimitBreak* lb = _character->getLimitBreak();
        std::vector<Potential*> potentials = lb->getAllImprovements().potentials;
        for (Potential* potential : potentials)
        {
            QString potentialType;
            Potential::Type type = potential->getType();
            if (type == Potential::Type::Enrage)
            {
                potentialType = "Enrage";
            }
            else if (type == Potential::Type::NoHealing)
            {
                potentialType = "No Healing Duration";
            }
            else if (type == Potential::Type::CriticalHit)
            {
                potentialType = "Critical Hit";
            }
            else if (type == Potential::Type::SlotBind)
            {
                potentialType = "Slot Bind Duration";
            }
            else if (type == Potential::Type::BarrierPenetration)
            {
                potentialType = "Barrier Penetration";
            }
            else if (type == Potential::Type::PinchHealing)
            {
                potentialType = "Pinch Healing";
            }
            else if (type == Potential::Type::DMRSTR)
            {
                potentialType = "STR Damage Reduction";
            }
            else if (type == Potential::Type::DMRQCK)
            {
                potentialType = "QCK Damage Reduction";
            }
            else if (type == Potential::Type::DMRDEX)
            {
                potentialType = "DEX Damage Reduction";
            }
            else if (type == Potential::Type::DMRPSY)
            {
                potentialType = "PSY Damage Reduction";
            }
            else if (type == Potential::Type::DMRINT)
            {
                potentialType = "INT Damage Reduction";
            }
            else if (type == Potential::Type::CDR)
            {
                potentialType = "Cooldown Self Reduction";
            }

            limitBreakString += "<p><b>" + potentialType + "</b></p>";
            limitBreakString += "<p>";
            for (std::string description : potential->getDescriptions())
            {
                limitBreakString += "- " + QString::fromStdString(description) + "<br><br>";
            }
            limitBreakString += "</p>";
        }
        ui->limitLabel->setText(limitBreakString);
    }
    else
    {
        removeTab("LimitBreak");
    }
}

void Details::setEvolutionTab(Character* _character)
{
    /* Evolution tab */

    if (!_character->getEvolution().empty())
    {
        std::vector<Character*> evolutions_character = _character->getEvolution();

        for (unsigned long j = 0; j < evolutions_character.size(); ++j)
        {
            /* Create evolution button */
            QPushButton* evoCharacter = new QPushButton(this);
            evoCharacter->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            evoCharacter->setMinimumSize(QSize(60, 60));
            evoCharacter->setMaximumSize(QSize(60, 60));
            evoCharacter->setIcon(QIcon(*evolutions_character.at(j)->getColoredIcon()));
            evoCharacter->setIconSize(QSize(60, 60));

            /* Connect signals and slots and add to grid */
            int evoId = evolutions_character.at(j)->getId();
            connect(evoCharacter, &QPushButton::clicked, this->parent(), [this, evoId]{ changeCharacterDetail(evoId); });
            ui->evolutionGrid->addWidget(evoCharacter, j, 0);

            /* Add equals symbol */
            std::vector<Character*> materials = _character->getEvolutionMaterials(evolutions_character.at(j));
            QLabel* lab = new QLabel(this);
            lab->setText("=");
            ui->evolutionGrid->addWidget(lab, j, 1, Qt::AlignCenter);

            /* Add evolution materials */
            for (unsigned long i = 0; i < 2 * materials.size(); ++i)
            {
                int id = materials.at(i / 2)->getId();

                QPushButton* mat = new QPushButton(this);
                mat->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
                mat->setMinimumSize(QSize(60, 60));
                mat->setMaximumSize(QSize(60, 60));
                mat->setIcon(QIcon(*materials.at(i / 2)->getColoredIcon()));
                mat->setIconSize(QSize(60, 60));
                ui->evolutionGrid->addWidget(mat, j, (i + 2));

                connect(mat, &QPushButton::clicked, this->parent(), [this, id]{ changeCharacterDetail(id); });

                /* Add plus symbol */
                i++;
                if (i == 2 * materials.size() - 1)
                {
                    break;
                }
                QLabel* lab = new QLabel(this);
                lab->setText("+");
                ui->evolutionGrid->addWidget(lab, j, (i + 2), Qt::AlignCenter);
            }
        }
    }
    else
    {
        removeTab("Evolution");
    }
}


QString getClassIcon(Class& _class)
{
    QString icon;
    if (_class == Class::Fighter)
    {
        icon = "fighter";
    }
    else if(_class == Class::Shooter)
    {
        icon = "shooter";
    }
    else if(_class == Class::Slasher)
    {
        icon = "slasher";
    }
    else if(_class == Class::Striker)
    {
        icon = "striker";
    }
    else if(_class == Class::Free_Spirit)
    {
        icon = "freespirit";
    }
    else if(_class ==  Class::Cerebral)
    {
        icon = "cerebral";
    }
    else if(_class == Class::Powerhouse)
    {
        icon = "powerhouse";
    }
    else if(_class == Class::Driven)
    {
        icon = "driven";
    }
    else if(_class == Class::Evolver)
    {
        icon = "evolver";
    }
    else if(_class == Class::Booster)
    {
        icon = "booster";
    }
    return icon;
}

void Details::on_LeftButton_clicked()
{
    Character* characterToLoad = nullptr;
    if (!ui->RightButton->isHidden())
    {
        ui->LeftButton->hide();
        characterToLoad = characters->at(characterId - 1)->getDualUnits().at(0);
    }
    else
    {
        ui->RightButton->show();
        characterToLoad = characters->at(characterId - 1);
    }
    setName(characterToLoad);
    setTypes(characterToLoad);
    setClasses(characterToLoad);
    setStatsTab(characterToLoad);
    setCaptainTab(characterToLoad);
    setSailorTab(characterToLoad);
}

void Details::on_RightButton_clicked()
{
    Character* characterToLoad = nullptr;
    if (!ui->LeftButton->isHidden())
    {
        ui->RightButton->hide();
        characterToLoad = characters->at(characterId - 1)->getDualUnits().at(1);
    }
    else
    {
        ui->LeftButton->show();
        characterToLoad = characters->at(characterId - 1);
    }
    setName(characterToLoad);
    setTypes(characterToLoad);
    setClasses(characterToLoad);
    setStatsTab(characterToLoad);
    setCaptainTab(characterToLoad);
    setSailorTab(characterToLoad);
}

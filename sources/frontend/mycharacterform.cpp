#include "mycharacterform.h"
#include "ui_mycharacterform.h"
#include <qpainter.h>
#include <socketselection.h>

MyCharacterForm::MyCharacterForm(Character* _character, MyCharacter* _myCharacter, bool _editMode, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyCharacterForm),
    templateCharacter(_character),
    myCharacter(_myCharacter),
    editMode(_editMode)
{
    ui->setupUi(this);
    ui->levelEdit->setText(QString::number(myCharacter->getLevel()));
    ui->skillLevelEdit->setText(QString::number(myCharacter->getSkillLevel()));
    ui->lbUnlockedEdit->setText(QString::number(myCharacter->getLbUnlockedNodes()));
    ui->trainingPointsEdit->setText(QString::number(myCharacter->getTrainingPoints()));
    std::vector<short> cottons = myCharacter->getCC();
    ui->cottonHpEdit->setText(QString::number(cottons[0]));
    ui->cottonAtkEdit->setText(QString::number(cottons[1]));
    ui->cottonRcvEdit->setText(QString::number(cottons[2]));
    ui->cottonTotalEdit->setText(QString("+") + QString::number(cottons[0] + cottons[1] + cottons[2]));

    if (!templateCharacter->hasSpecial())
    {
        ui->skillLevelEdit->hide();
        ui->fixedSkillLevelLabel->hide();
    }

    int numLbSocket = 0;
    if (!templateCharacter->hasLimitBreak())
    {
        ui->lbUnlockedEdit->hide();
        ui->fixedLbUnlockedLabel->hide();
        ui->maxLbUnlocked->hide();

        ui->trainingPointsEdit->hide();
        ui->fixedTrainingPointsLabel->hide();
        ui->maxTrainingPoints->hide();

        ui->firstPotential->hide();
        ui->secondPotential->hide();
        ui->thirdPotential->hide();
        ui->firstPotentialValueEdit->hide();
        ui->secondPotentialValueEdit->hide();
        ui->thirdPotentialValueEdit->hide();
        ui->fixedPotentialLabel->hide();
    }
    else
    {
        numLbSocket = templateCharacter->getLimitBreak()->getAllImprovements().socket;
    }

    prepareSocketPixmap();

    // Hide socket in surplus
    for (int i = (templateCharacter->getStats()->num_sockets + numLbSocket + 1); i <= 5; ++i)
    {
        ui->socketLayout->itemAtPosition(0, i)->widget()->hide();
        ui->socketLayout->itemAtPosition(1, i)->widget()->hide();
        ui->socketLayout->itemAtPosition(2, i)->widget()->hide();
        ui->socketLayout->itemAtPosition(3, i)->widget()->hide();
        ui->socketLayout->itemAtPosition(4, i)->widget()->hide();
    }

    // Hide text if no socket
    if (templateCharacter->getStats()->num_sockets + numLbSocket == 0)
    {
        ui->socketLayout->itemAtPosition(0, 0)->widget()->hide();
        ui->socketLayout->itemAtPosition(1, 0)->widget()->hide();
        ui->socketLayout->itemAtPosition(3, 0)->widget()->hide();
    }

    // Set Want to finish checkboxes and then hide
    ui->wantToFinishLevel->setChecked(myCharacter->getWantToFinishLevel());
    ui->wantToFinishCotton->setChecked(myCharacter->getWantToFinishCotton());
    ui->wantToFinishSkill->setChecked(myCharacter->getWantToFinishSkill());
    ui->wantToFinishSocket->setChecked(myCharacter->getWantToFinishSockets());
    ui->wantToFinishLimit->setChecked(myCharacter->getWantToFinishLimitBreak());

    if (!_character->hasSpecial())
    {
        ui->wantToFinishSkill->hide();
    }

    if (_character->getStats()->num_sockets == 0)
    {
        if (!_character->hasLimitBreak())
        {
            ui->wantToFinishSocket->hide();
        }
        else
        {
            if (_character->getLimitBreak()->getAllImprovements().socket == 0)
            {
                ui->wantToFinishSocket->hide();;
            }
        }
    }

    if (!_character->hasLimitBreak())
    {
        ui->wantToFinishLimit->hide();
    }

    refresh();
}

MyCharacterForm::~MyCharacterForm()
{
    delete ui;
}

void MyCharacterForm::editModeChanged()
{
    editMode = !editMode;
    refresh();
}

void MyCharacterForm::refresh()
{
    ui->wantToFinishLevel->setEnabled(editMode);
    ui->wantToFinishCotton->setEnabled(editMode);
    ui->wantToFinishSkill->setEnabled(editMode);
    ui->wantToFinishSocket->setEnabled(editMode);
    ui->wantToFinishLimit->setEnabled(editMode);

    ui->levelEdit->setEnabled(editMode);
    ui->skillLevelEdit->setEnabled(editMode);
    ui->lbUnlockedEdit->setEnabled(editMode);
    ui->trainingPointsEdit->setEnabled(editMode);
    ui->cottonHpEdit->setEnabled(editMode);
    ui->cottonAtkEdit->setEnabled(editMode);
    ui->cottonRcvEdit->setEnabled(editMode);

    ui->firstDesiredSocket->setEnabled(editMode);
    ui->secondDesiredSocket->setEnabled(editMode);
    ui->thirdDesiredSocket->setEnabled(editMode);
    ui->fourthDesiredSocket->setEnabled(editMode);
    ui->fifthDesiredSocket->setEnabled(editMode);

    // La modifica di questi è abilitata quando è abilitato il socket e ce n'è uno
    int numLbSocket = 0;
    int unlockedSocket = 0;
    if (templateCharacter->hasLimitBreak())
    {
        numLbSocket = templateCharacter->getLimitBreak()->getAllImprovements().socket;
        unlockedSocket = templateCharacter->getLimitBreak()->getUnlockedImprovements(static_cast<unsigned long>(myCharacter->getLbUnlockedNodes())).socket;
    }

    QPixmap* frame = nullptr;
    QPixmap* grayFrame = nullptr;
    QIcon frameIcon;
    QIcon grayFrameIcon;
    if (socketPixmap.size() > 0)
    {
        frame = socketPixmap["Frame"];
        frameIcon = frame->scaled(ui->firstCurrentSocket->width(), ui->firstCurrentSocket->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        grayFrame = socketPixmap["GrayFrame"];
        grayFrameIcon = grayFrame->scaled(ui->firstCurrentSocket->width(), ui->firstCurrentSocket->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);


        // Set desired socket to saved state
        int k = 1;
        for (Socket::Type type : myCharacter->getDesiredSockets())
        {
            QPixmap* socketPixmap = getFrameFromSocket(type);
            QIcon socketIcon(socketPixmap->scaled(ui->firstCurrentSocket->width(), ui->firstCurrentSocket->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            QPushButton* socketButton = static_cast<QPushButton*>(ui->socketLayout->itemAtPosition(0, k)->widget());
            socketButton->setIcon(socketIcon);
            socketButton->setIconSize(socketPixmap->rect().size());
            k++;
        }

        // Set remaining desired socket to empty
        for (; k <= templateCharacter->getStats()->num_sockets + numLbSocket; ++k)
        {
            QPushButton* socketButton = static_cast<QPushButton*>(ui->socketLayout->itemAtPosition(0, k)->widget());
            socketButton->setIconSize(frame->rect().size());
            socketButton->setIcon(frameIcon);
        }

        //Set current socket to saved state
        k = 1;
        for (Socket& socket : myCharacter->getSockets())
        {
            QPixmap* socketPixmap = getFrameFromSocket(socket.getType());
            QIcon socketIcon(socketPixmap->scaled(ui->firstCurrentSocket->width(), ui->firstCurrentSocket->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            QPushButton* socketButton = static_cast<QPushButton*>(ui->socketLayout->itemAtPosition(1, k)->widget());
            socketButton->setIcon(socketIcon);
            socketButton->setIconSize(socketPixmap->rect().size());
            QLineEdit* socketValue = static_cast<QLineEdit*>(ui->socketLayout->itemAtPosition(2, k)->widget());
            if (myCharacter->getSockets()[k - 1].getType() != Socket::Type::None)
            {
                if (socketValue->text() != "")
                {
                    socketValue->setText(QString::number(socket.getValue()));
                }
            }
            else
            {
                socketValue->setText("0");
            }
            k++;
        }

        // Set remaining current socket to empty
        for (; k <= templateCharacter->getStats()->num_sockets + numLbSocket; ++k)
        {
            QPushButton* socketButton = static_cast<QPushButton*>(ui->socketLayout->itemAtPosition(1, k)->widget());
            socketButton->setIconSize(frame->rect().size());
            socketButton->setIcon(frameIcon);
        }

        // Set locked socket to gray
        for (int i = (templateCharacter->getStats()->num_sockets + unlockedSocket + 1); i <= templateCharacter->getStats()->num_sockets + numLbSocket; ++i)
        {
            QPushButton* socketButton = static_cast<QPushButton*>(ui->socketLayout->itemAtPosition(1, i)->widget());
            socketButton->setIconSize(grayFrame->rect().size());
            socketButton->setIcon(grayFrameIcon);
            QLineEdit* socketValue = static_cast<QLineEdit*>(ui->socketLayout->itemAtPosition(2, i)->widget());
            socketValue->setEnabled(false);
            socketValue->setText("0");
        }

        // Set missing sockets points
        k = 1;
        for (Socket& socket : myCharacter->missingSocketPoints())
        {
            QPixmap* socketPixmap = getFrameFromSocket(socket.getType());
            QIcon socketIcon(socketPixmap->scaled(ui->firstCurrentSocket->width(), ui->firstCurrentSocket->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            QPushButton* socketButton = static_cast<QPushButton*>(ui->socketLayout->itemAtPosition(3, k)->widget());
            socketButton->setIcon(socketIcon);
            socketButton->setIconSize(socketPixmap->rect().size());
            QLineEdit* socketValue = static_cast<QLineEdit*>(ui->socketLayout->itemAtPosition(4, k)->widget());
            socketValue->setText(QString::number(socket.getValue()));
            k++;
        }

        // Set remaining desired socket to empty
        for (; k <= templateCharacter->getStats()->num_sockets + numLbSocket; ++k)
        {
            QPushButton* socketButton = static_cast<QPushButton*>(ui->socketLayout->itemAtPosition(3, k)->widget());
            socketButton->setIconSize(frame->rect().size());
            QLineEdit* socketValue = static_cast<QLineEdit*>(ui->socketLayout->itemAtPosition(4, k)->widget());
            socketValue->setText("0");
            socketButton->setIcon(frameIcon);
        }
    }

    for (int i = 1; i <= templateCharacter->getStats()->num_sockets + unlockedSocket; ++i)
    {
        QPushButton* socketButton = static_cast<QPushButton*>(ui->socketLayout->itemAtPosition(1, i)->widget());
        socketButton->setEnabled(editMode);
        // Set only unlocked socket icon
        if (i > templateCharacter->getStats()->num_sockets)
        {
            if (i > static_cast<int>(myCharacter->getSockets().size()))
            {
                if (socketPixmap.size() > 0)
                {
                    QPixmap* frame = socketPixmap["Frame"];
                    QIcon frameIcon(frame->scaled(ui->firstCurrentSocket->width(), ui->firstCurrentSocket->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
                    socketButton->setIcon(frameIcon);
                    socketButton->setIconSize(frame->rect().size());
                }
            }
        }
        QLineEdit* socketValue = static_cast<QLineEdit*>(ui->socketLayout->itemAtPosition(2, i)->widget());
        if (i > static_cast<int>(myCharacter->getSockets().size()))
        {
            socketValue->setEnabled(false);
        }
        else
        {
            if (myCharacter->getSockets()[i - 1].getType() != Socket::Type::None)
            {
                socketValue->setEnabled(editMode);
            }
        }
    }

    // Set locked socket to gray
    for (int i = (templateCharacter->getStats()->num_sockets + unlockedSocket + 1); i <= templateCharacter->getStats()->num_sockets + numLbSocket; ++i)
    {
        QPushButton* socketButton = static_cast<QPushButton*>(ui->socketLayout->itemAtPosition(1, i)->widget());
        socketButton->setEnabled(false);
        if (socketPixmap.size() > 0)
        {
            socketButton->setIconSize(grayFrame->rect().size());
            QIcon grayFrameIcon(grayFrame->scaled(ui->firstCurrentSocket->width(), ui->firstCurrentSocket->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            socketButton->setIcon(grayFrameIcon);
        }
        QLineEdit* socketValue = static_cast<QLineEdit*>(ui->socketLayout->itemAtPosition(2, i)->widget());
        socketValue->setEnabled(false);
        socketValue->setText("0");
    }

    // Set stats
    int hpLb = 0;
    int atkLb = 0;
    int rcvLb = 0;
    std::vector<int> currentStats = myCharacter->getStats();
    std::vector<short> currentCC = myCharacter->getCC();

    if (templateCharacter->hasLimitBreak())
    {
        LimitBreak* limit = templateCharacter->getLimitBreak();
        LimitBreak::Improvements improvements = limit->getUnlockedImprovements(static_cast<unsigned long>(myCharacter->getLbUnlockedNodes()));
        hpLb = improvements.hp;
        atkLb = improvements.atk;
        rcvLb = improvements.rcv;
    }

    ui->statsHpEdit->setText(QString::number(currentStats[0] + 5 * currentCC[0] + hpLb));
    ui->statsAtkEdit->setText(QString::number(currentStats[1] + 2 * currentCC[1] + atkLb));
    ui->statsRcvEdit->setText(QString::number(currentStats[2] + currentCC[2] + rcvLb));

    // Set potentials
    if (templateCharacter->hasLimitBreak())
    {
        std::vector<Potential> currentPotentials = myCharacter->getPotential();
        std::vector<Potential*> unlockedPotentials = templateCharacter->getLimitBreak()->getUnlockedImprovements(static_cast<unsigned long>(myCharacter->getLbUnlockedNodes())).potentials;
        std::vector<Potential*> unlockablePotentials = templateCharacter->getLimitBreak()->getAllImprovements().potentials;
        int numPotential = static_cast<int>(unlockablePotentials.size());
        for (int i = 1; i <= 3; ++i)
        {
            if (i <= numPotential)
            {
                QPixmap* potentialFrame = getFrameFromPotential(unlockablePotentials[static_cast<unsigned int>(i - 1)]->getType());
                QIcon potentialFrameIcon(potentialFrame->scaled(ui->firstPotential->width(), ui->firstPotential->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
                QPushButton* potentialButton = static_cast<QPushButton*>(ui->potentialLayout->itemAtPosition(0, i)->widget());
                potentialButton->setIcon(potentialFrameIcon);
                potentialButton->setIconSize(potentialFrame->rect().size());
                if (i <= static_cast<int>(unlockedPotentials.size()))
                {   //Unlocked
                    potentialButton->setEnabled(true);

                    QLineEdit* potentialValue = static_cast<QLineEdit*>(ui->potentialLayout->itemAtPosition(1, i)->widget());
                    if (i > static_cast<int>(currentPotentials.size()))
                    {
                        potentialValue->setEnabled(editMode);
                        potentialValue->setText("1");
                    }
                    else
                    {
                        potentialValue->setText(QString::number(currentPotentials[static_cast<unsigned int>(i - 1)].getValue()));
                        potentialValue->setEnabled(editMode);
                    }
                }
                else
                {   //Not unlocked
                    potentialButton->setEnabled(false);

                    QLineEdit* potentialValue = static_cast<QLineEdit*>(ui->potentialLayout->itemAtPosition(1, i)->widget());
                    potentialValue->setEnabled(false);
                    potentialValue->setText("0");
                }
            }
            else
            {
                ui->potentialLayout->itemAtPosition(0, i)->widget()->hide();
                ui->potentialLayout->itemAtPosition(1, i)->widget()->hide();
            }
        }
    }
}

void MyCharacterForm::on_levelEdit_textChanged(const QString &_level)
{
    QString level = _level;
    if (_level.toInt() < 1)
    {
        level = "1";
    }

    if (_level.toInt() > templateCharacter->getStats()->max_level)
    {
        level = QString::number(templateCharacter->getStats()->max_level);
    }

    if (_level != "")
    {
        ui->levelEdit->setText(level);
    }
    myCharacter->setLevel(level.toShort());
    if (level.toInt() == templateCharacter->getStats()->max_level)
    {
        ui->maxLevel->show();
    }
    else
    {
        ui->maxLevel->hide();
    }
}

void MyCharacterForm::on_skillLevelEdit_textChanged(const QString &_skillLevel)
{
    QString skillLevel = _skillLevel;
    if (_skillLevel.toInt() < 1)
    {
        skillLevel = "1";
    }

    if (_skillLevel.toInt() > templateCharacter->getSpecial()->getMaxLevel())
    {
        skillLevel = QString::number(templateCharacter->getSpecial()->getMaxLevel());
    }

    if (skillLevel != "" && skillLevel.toInt() > -1)
    {
        ui->skillLevelEdit->setText(skillLevel);
    }
    myCharacter->setSkillLevel(skillLevel.toShort());
    if (skillLevel.toInt() == templateCharacter->getSpecial()->getMaxLevel() && skillLevel.toInt() != -1)
    {
        ui->maxSkillLevel->show();
    }
    else
    {
        ui->maxSkillLevel->hide();
    }
}

void MyCharacterForm::on_lbUnlockedEdit_textChanged(const QString &_lbUnlockedNodes)
{
    QString lbUnlockedNodes = _lbUnlockedNodes;
    if (_lbUnlockedNodes.toInt() < 1)
    {
        lbUnlockedNodes = "0";
    }

    if (_lbUnlockedNodes.toUInt() > templateCharacter->getLimitBreak()->getTotalNodes())
    {
        lbUnlockedNodes = QString::number(templateCharacter->getLimitBreak()->getTotalNodes());
    }

    if (_lbUnlockedNodes != "")
    {
        ui->lbUnlockedEdit->setText(lbUnlockedNodes);
    }
    myCharacter->setLbUnlockedNodes(lbUnlockedNodes.toShort());
    if (lbUnlockedNodes.toUInt() == templateCharacter->getLimitBreak()->getTotalNodes())
    {
        ui->maxLbUnlocked->show();
    }
    else
    {
        ui->maxLbUnlocked->hide();
    }
    refresh();
}

void MyCharacterForm::on_trainingPointsEdit_textChanged(const QString &_trainingPoints)
{
    QString trainingPoints = _trainingPoints;

    // Get max training points
    LimitBreak* limit = templateCharacter->getLimitBreak();
    int maxTrainingPoints = limit->getMaxTrainingPoints();

    // Check boundaries
    if (trainingPoints.toInt() < 1)
    {
        trainingPoints = "0";
    }

    if (_trainingPoints.toInt() > maxTrainingPoints)
    {
        trainingPoints = QString::number(maxTrainingPoints);
    }

    // Set training points
    if (_trainingPoints != "")
    {
        ui->trainingPointsEdit->setText(trainingPoints);
    }

    myCharacter->setTrainingPoints(trainingPoints.toInt());

    if (trainingPoints.toInt() == maxTrainingPoints)
    {
        ui->maxTrainingPoints->show();
    }
    else
    {
        ui->maxTrainingPoints->hide();
    }
    refresh();
}

void MyCharacterForm::on_cottonHpEdit_textChanged(const QString &_ccHp)
{
    short hpValue = _ccHp.toShort();
    if (hpValue < 0)
    {
        hpValue = 0;
    }

    short atkValue = ui->cottonAtkEdit->text().toShort();
    short rcvValue = ui->cottonRcvEdit->text().toShort();
    short hpMaxValue = 200 - atkValue - rcvValue;

    if (hpValue > hpMaxValue)
    {
        hpValue = hpMaxValue;
    }

    if (hpValue > 100)
    {
        hpValue = 100;
    }


    if (_ccHp != "")
    {
        ui->cottonHpEdit->setText(QString::number(hpValue));
    }
    ui->cottonTotalEdit->setText(QString("+") + QString::number(hpValue + atkValue + rcvValue));
    myCharacter->setCC(hpValue, atkValue, rcvValue);

    if (hpValue + atkValue + rcvValue == 200)
    {
        ui->maxCC->show();
    }
    else
    {
        ui->maxCC->hide();
    }
    refresh();
}

void MyCharacterForm::on_cottonAtkEdit_textChanged(const QString &_ccAtk)
{
    short atkValue = _ccAtk.toShort();
    if (atkValue < 0)
    {
        atkValue = 0;
    }

    short hpValue = ui->cottonHpEdit->text().toShort();
    short rcvValue = ui->cottonRcvEdit->text().toShort();
    short atkMaxValue = 200 - hpValue - rcvValue;

    if (atkValue > atkMaxValue)
    {
        atkValue = atkMaxValue;
    }

    if (atkValue > 100)
    {
        atkValue = 100;
    }

    if (_ccAtk != "")
    {
        ui->cottonAtkEdit->setText(QString::number(atkValue));
    }
    ui->cottonTotalEdit->setText(QString("+") + QString::number(hpValue + atkValue + rcvValue));
    myCharacter->setCC(hpValue, atkValue, rcvValue);

    if (hpValue + atkValue + rcvValue == 200)
    {
        ui->maxCC->show();
    }
    else
    {
        ui->maxCC->hide();
    }
    refresh();
}

void MyCharacterForm::on_cottonRcvEdit_textChanged(const QString &_ccRcv)
{
    short rcvValue = _ccRcv.toShort();
    if (rcvValue < 0)
    {
        rcvValue = 0;
    }

    short hpValue = ui->cottonHpEdit->text().toShort();
    short atkValue = ui->cottonAtkEdit->text().toShort();
    short rcvMaxValue = 200 - hpValue - atkValue;

    if (rcvValue > rcvMaxValue)
    {
        rcvValue = rcvMaxValue;
    }

    if (rcvValue > 100)
    {
        rcvValue = 100;
    }

    if (_ccRcv != "")
    {
        ui->cottonRcvEdit->setText(QString::number(rcvValue));
    }
    ui->cottonTotalEdit->setText(QString("+") + QString::number(hpValue + atkValue + rcvValue));
    myCharacter->setCC(hpValue, atkValue, rcvValue);

    if (hpValue + atkValue + rcvValue == 200)
    {
        ui->maxCC->show();
    }
    else
    {
        ui->maxCC->hide();
    }
    refresh();
}

void MyCharacterForm::prepareSocketPixmap()
{
    QPixmap* frame = new QPixmap(":/ui/skill_frame.png");
    QPixmap* dmr = new QPixmap(":/ui/skill_dmr.png");
    QPixmap* cd = new QPixmap(":/ui/skill_cd.png");
    QPixmap* bind = new QPixmap(":/ui/skill_bind.png");
    QPixmap* despair = new QPixmap(":/ui/skill_despair.png");
    QPixmap* heal = new QPixmap(":/ui/skill_heal.png");
    QPixmap* rcv = new QPixmap(":/ui/skill_rcv.png");
    QPixmap* slot = new QPixmap(":/ui/skill_slot.png");
    QPixmap* poison = new QPixmap(":/ui/skill_poison.png");
    QPixmap* map = new QPixmap(":/ui/skill_map.png");
    QPixmap* resilience = new QPixmap(":/ui/skill_resilience.png");

    QImage im = frame->toImage().convertToFormat(QImage::Format_ARGB32);
    for (int y = 0; y < im.height(); ++y)
    {
        QRgb *scanLine = (QRgb*)im.scanLine(y);
        for (int x = 0; x < im.width(); ++x)
        {
            QRgb pixel = *scanLine;
            uint ci = uint(qGray(pixel));
            *scanLine = qRgba(static_cast<int>(ci), static_cast<int>(ci), static_cast<int>(ci), qAlpha(pixel) / 3);
            ++scanLine;
        }
    }
    QPixmap* grayFrame = new QPixmap(QPixmap::fromImage(im));

    socketPixmap["Frame"] = frame;
    socketPixmap["GrayFrame"] = grayFrame;
    socketPixmap["Dmr"] = dmr;
    socketPixmap["Cd"] = cd;
    socketPixmap["Bind"] = bind;
    socketPixmap["Despair"] = despair;
    socketPixmap["Heal"] = heal;
    socketPixmap["Rcv"] = rcv;
    socketPixmap["Slot"] = slot;
    socketPixmap["Poison"] = poison;
    socketPixmap["Map"] = map;
    socketPixmap["Resilience"] = resilience;
}

QPixmap* MyCharacterForm::getFramedPixmap(QPixmap* _base, QPixmap* _overlay)
{
    QPixmap* result = new QPixmap(_base->width(), _base->height());

    result->fill(Qt::transparent); // force alpha channel
    {
        QPainter painter(result);
        painter.drawPixmap(0, 0, *_base);
        int widthIndent = _base->width() / 2 - _overlay->width() / 2;
        int heightIndent = _base->height() / 2 - _overlay->height() / 2;
        painter.drawPixmap(widthIndent, heightIndent, *_overlay);
    }
    return result;
}


QPixmap* MyCharacterForm::getFrameFromSocket(Socket::Type _type)
{
    QPixmap* socket = nullptr;
    if (_type == Socket::Type::Dmr)
    {
        socket = getFramedPixmap(socketPixmap["Frame"], socketPixmap["Dmr"]);
    }
    else if (_type == Socket::Type::Cd)
    {
        socket = getFramedPixmap(socketPixmap["Frame"], socketPixmap["Cd"]);
    }
    else if (_type == Socket::Type::Bind)
    {
        socket = getFramedPixmap(socketPixmap["Frame"], socketPixmap["Bind"]);
    }

    else if (_type == Socket::Type::Despair)
    {
        socket = getFramedPixmap(socketPixmap["Frame"], socketPixmap["Despair"]);
    }

    else if (_type == Socket::Type::AH)
    {
        socket = getFramedPixmap(socketPixmap["Frame"], socketPixmap["Heal"]);
    }

    else if (_type == Socket::Type::Rcv)
    {
        socket = getFramedPixmap(socketPixmap["Frame"], socketPixmap["Rcv"]);
    }

    else if (_type == Socket::Type::Slot)
    {
        socket = getFramedPixmap(socketPixmap["Frame"], socketPixmap["Slot"]);
    }

    else if (_type == Socket::Type::Poison)
    {
        socket = getFramedPixmap(socketPixmap["Frame"], socketPixmap["Poison"]);
    }

    else if (_type == Socket::Type::Map)
    {
        socket = getFramedPixmap(socketPixmap["Frame"], socketPixmap["Map"]);
    }

    else if (_type == Socket::Type::Resilience)
    {
        socket = getFramedPixmap(socketPixmap["Frame"], socketPixmap["Resilience"]);
    }
    else
    {
        socket = getFramedPixmap(socketPixmap["Frame"], socketPixmap["Frame"]);
    }

    return socket;
}


QPixmap* MyCharacterForm::getFrameFromPotential(Potential::Type _type)
{
    QPixmap* potential = nullptr;
    QPixmap* potentialFrame = new QPixmap(":/ui/potential_frame.png");
    if (_type == Potential::Type::Enrage)
    {
        potential = new QPixmap(":/ui/potential_enrage.png");
        potential = getFramedPixmap(potentialFrame, potential);
    }
    else if (_type == Potential::Type::NoHealing)
    {
        potential = new QPixmap(":/ui/potential_nohealing.png");
        potential = getFramedPixmap(potentialFrame, potential);
    }
    else if (_type == Potential::Type::CriticalHit)
    {
        potential = new QPixmap(":/ui/potential_criticalhit.png");
        potential = getFramedPixmap(potentialFrame, potential);
    }
    else if (_type == Potential::Type::SlotBind)
    {
        potential = new QPixmap(":/ui/potential_slotbind.png");
        potential = getFramedPixmap(potentialFrame, potential);
    }
    else if (_type == Potential::Type::BarrierPenetration)
    {
        potential = new QPixmap(":/ui/potential_barrierPenetration.png");
        potential = getFramedPixmap(potentialFrame, potential);
    }
    else if (_type == Potential::Type::PinchHealing)
    {
        potential = new QPixmap(":/ui/potential_pinchhealing.png");
        potential = getFramedPixmap(potentialFrame, potential);
    }
    else if (_type == Potential::Type::DMRSTR)
    {
        potential = new QPixmap(":/ui/potential_dmrstr.png");
        potential = getFramedPixmap(potentialFrame, potential);
    }
    else if (_type == Potential::Type::DMRQCK)
    {
        potential = new QPixmap(":/ui/potential_dmrqck.png");
        potential = getFramedPixmap(potentialFrame, potential);
    }
    else if (_type == Potential::Type::DMRDEX)
    {
        potential = new QPixmap(":/ui/potential_dmrdex.png");
        potential = getFramedPixmap(potentialFrame, potential);
    }
    else if (_type == Potential::Type::DMRINT)
    {
        potential = new QPixmap(":/ui/potential_dmrint.png");
        potential = getFramedPixmap(potentialFrame, potential);
    }
    else if (_type == Potential::Type::DMRPSY)
    {
        potential = new QPixmap(":/ui/potential_dmrpsy.png");
        potential = getFramedPixmap(potentialFrame, potential);
    }
    else if (_type == Potential::Type::CDR)
    {
        potential = new QPixmap(":/ui/potential_cd.png");
        potential = getFramedPixmap(potentialFrame, potential);
    }
    else if (_type == Potential::Type::DoubleSpecial)
    {
        potential = new QPixmap(":/ui/potential_doublespecial.png");
        potential = getFramedPixmap(potentialFrame, potential);
    }

    return potential;
}

void MyCharacterForm::on_firstPotentialValueEdit_textChanged(const QString &_potentialLevel)
{
    if (ui->firstPotentialValueEdit->isEnabled())
    {
        QString potentialValue = _potentialLevel;
        if (potentialValue.toInt() < 1)
        {
            potentialValue = "1";
        }

        if (potentialValue.toInt() > 5)
        {
            potentialValue = "5";
        }

        if (_potentialLevel != "")
        {
            ui->firstPotentialValueEdit->setText(potentialValue);
        }
        std::vector<Potential*> unlockablePotentials = templateCharacter->getLimitBreak()->getAllImprovements().potentials;

        myCharacter->setPotential(unlockablePotentials[0]->getType(), potentialValue.toShort());

        Potential* thisPotential = templateCharacter->getLimitBreak()->getAllImprovements().potentials[0];
        ui->firstPotential->setToolTip(QString::fromStdString(thisPotential->getDescriptions()[potentialValue.toInt() - 1]));
    }
}

void MyCharacterForm::on_secondPotentialValueEdit_textChanged(const QString &_potentialLevel)
{

    if (ui->secondPotentialValueEdit->isEnabled())
    {
        QString potentialValue = _potentialLevel;
        if (potentialValue.toInt() < 1)
        {
            potentialValue = "1";
        }

        if (potentialValue.toInt() > 5)
        {
            potentialValue = "5";
        }

        if (_potentialLevel != "")
        {
            ui->secondPotentialValueEdit->setText(potentialValue);
        }
        std::vector<Potential*> unlockablePotentials = templateCharacter->getLimitBreak()->getAllImprovements().potentials;

        myCharacter->setPotential(unlockablePotentials[1]->getType(), potentialValue.toShort());
        Potential* thisPotential = templateCharacter->getLimitBreak()->getAllImprovements().potentials[1];
        ui->secondPotential->setToolTip(QString::fromStdString(thisPotential->getDescriptions()[potentialValue.toInt() - 1]));
    }
}

void MyCharacterForm::on_thirdPotentialValueEdit_textChanged(const QString &_potentialLevel)
{
    if (ui->thirdPotentialValueEdit->isEnabled())
    {
        QString potentialValue = _potentialLevel;
        if (potentialValue.toInt() < 1)
        {
            potentialValue = "1";
        }

        if (potentialValue.toInt() > 5)
        {
            potentialValue = "5";
        }

        if (_potentialLevel != "")
        {
            ui->thirdPotentialValueEdit->setText(potentialValue);
        }
        std::vector<Potential*> unlockablePotentials = templateCharacter->getLimitBreak()->getAllImprovements().potentials;

        myCharacter->setPotential(unlockablePotentials[2]->getType(), potentialValue.toShort());
        Potential* thisPotential = templateCharacter->getLimitBreak()->getAllImprovements().potentials[2];
        ui->thirdPotential->setToolTip(QString::fromStdString(thisPotential->getDescriptions()[potentialValue.toInt() - 1]));
    }
    refresh();
}

void MyCharacterForm::on_firstSocketEdit_textChanged(const QString &_socketLevel)
{
    if (ui->firstSocketEdit->isEnabled())
    {
        QString socketValue = _socketLevel;
        if (socketValue.toInt() < 1)
        {
            socketValue = "1";
        }

        if (socketValue.toInt() > 5)
        {
            socketValue = "5";
        }

        if (_socketLevel != "")
        {
            ui->firstSocketEdit->setText(socketValue);
        }

        std::vector<Socket>& currentSockets = myCharacter->getSockets();
        currentSockets[0].setValue(socketValue.toShort());
    }
    refresh();
}

void MyCharacterForm::on_secondSocketEdit_textChanged(const QString &_socketLevel)
{
    if (ui->secondSocketEdit->isEnabled())
    {
        QString socketValue = _socketLevel;
        if (socketValue.toInt() < 1)
        {
            socketValue = "1";
        }

        if (socketValue.toInt() > 5)
        {
            socketValue = "5";
        }

        if (_socketLevel != "")
        {
            ui->secondSocketEdit->setText(socketValue);
        }
        std::vector<Socket>& currentSockets = myCharacter->getSockets();
        currentSockets[1].setValue(socketValue.toShort());
    }
    refresh();
}

void MyCharacterForm::on_thirdSocketEdit_textChanged(const QString &_socketLevel)
{
    if (ui->thirdSocketEdit->isEnabled())
    {
        QString socketValue = _socketLevel;
        if (socketValue.toInt() < 1)
        {
            socketValue = "1";
        }

        if (socketValue.toInt() > 5)
        {
            socketValue = "5";
        }

        if (_socketLevel != "")
        {
            ui->thirdSocketEdit->setText(socketValue);
        }
        std::vector<Socket>& currentSockets = myCharacter->getSockets();
        currentSockets[2].setValue(socketValue.toShort());
    }
    refresh();
}

void MyCharacterForm::on_fourthSocketEdit_textChanged(const QString &_socketLevel)
{
    if (ui->fourthSocketEdit->isEnabled())
    {
        QString socketValue = _socketLevel;
        if (socketValue.toInt() < 1)
        {
            socketValue = "1";
        }

        if (socketValue.toInt() > 5)
        {
            socketValue = "5";
        }

        if (_socketLevel != "")
        {
            ui->fourthSocketEdit->setText(socketValue);
        }
        std::vector<Socket>& currentSockets = myCharacter->getSockets();
        currentSockets[3].setValue(socketValue.toShort());
    }
    refresh();
}

void MyCharacterForm::on_fifthSocketEdit_textChanged(const QString &_socketLevel)
{
    if (ui->fifthSocketEdit->isEnabled())
    {
        QString socketValue = _socketLevel;
        if (socketValue.toInt() < 1)
        {
            socketValue = "1";
        }

        if (socketValue.toInt() > 5)
        {
            socketValue = "5";
        }

        if (_socketLevel != "")
        {
            ui->fifthSocketEdit->setText(socketValue);
        }
        std::vector<Socket>& currentSockets = myCharacter->getSockets();
        currentSockets[4].setValue(socketValue.toShort());
    }
    refresh();
}

void MyCharacterForm::acceptedSelection(int _row, int _column, Socket::Type _type)
{
    QPixmap* selectedSocket = getFrameFromSocket(_type);
    QIcon selectedIcon(selectedSocket->scaled(ui->firstDesiredSocket->width(), ui->firstDesiredSocket->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    QPushButton* socketButton = static_cast<QPushButton*>(ui->socketLayout->itemAtPosition(_row, _column)->widget());
    socketButton->setIcon(selectedIcon);

    if (_row == 0)
    {
        std::vector<Socket::Type>& desiredSockets = myCharacter->getDesiredSockets();

        // Checking if setting a new desired socket
        while (_column > static_cast<int>(desiredSockets.size()))
        {
            desiredSockets.push_back(Socket::Type::None);
        }

        desiredSockets[static_cast<unsigned int>(_column - 1)] = _type;
    }
    else if (_row == 1)
    {
        std::vector<Socket>& currentSockets = myCharacter->getSockets();
        // Checking if setting a new current socket
        while (_column > static_cast<int>(currentSockets.size()))
        {
            currentSockets.push_back(Socket(Socket::Type::None, 1));
        }
        currentSockets[static_cast<unsigned int>(_column - 1)] = Socket(_type, currentSockets[static_cast<unsigned int>(_column - 1)].getValue());

        QLineEdit* socketValue = static_cast<QLineEdit*>(ui->socketLayout->itemAtPosition(2, _column)->widget());
        if (_type == Socket::Type::None)
        {
            socketValue->setEnabled(false);
            socketValue->setText("0");
        }
        else
        {
            socketValue->setEnabled(true);
        }
    }
    refresh();
}

void MyCharacterForm::on_firstDesiredSocket_clicked()
{
    openSocketSelection(0, 1);
}

void MyCharacterForm::on_secondDesiredSocket_clicked()
{
    openSocketSelection(0, 2);
}

void MyCharacterForm::on_thirdDesiredSocket_clicked()
{
    openSocketSelection(0, 3);
}

void MyCharacterForm::on_fourthDesiredSocket_clicked()
{
    openSocketSelection(0, 4);
}

void MyCharacterForm::on_fifthDesiredSocket_clicked()
{
    openSocketSelection(0, 5);
}

void MyCharacterForm::on_firstCurrentSocket_clicked()
{
    openSocketSelection(1, 1);
}

void MyCharacterForm::on_secondCurrentSocket_clicked()
{
    openSocketSelection(1, 2);
}

void MyCharacterForm::on_thirdCurrentSocket_clicked()
{
    openSocketSelection(1, 3);
}

void MyCharacterForm::on_fourthCurrentSocket_clicked()
{
    openSocketSelection(1, 4);
}

void MyCharacterForm::on_fifthCurrentSocket_clicked()
{
    openSocketSelection(1, 5);
}

void MyCharacterForm::openSocketSelection(int _row, int _column)
{
    std::vector<Socket::Type> possibleTypes =
    {
        Socket::Type::Dmr, Socket::Type::Cd, Socket::Type::Bind, Socket::Type::Despair,
        Socket::Type::AH, Socket::Type::Rcv, Socket::Type::Slot, Socket::Type::Map,
        Socket::Type::Poison, Socket::Type::Resilience
    };

    if (_row == 0)
    {
        std::vector<Socket::Type> desiredSockets = myCharacter->getDesiredSockets();
        for (unsigned int i = 0; i < desiredSockets.size(); ++i)
        {
            if (i != static_cast<unsigned int>(_column - 1))
            {
                possibleTypes.erase(std::remove(possibleTypes.begin(), possibleTypes.end(), desiredSockets[i]), possibleTypes.end());
            }
        }
    }
    else if (_row == 1)
    {
        std::vector<Socket> currentSockets = myCharacter->getSockets();
        for (unsigned int i = 0; i < currentSockets.size(); ++i)
        {
            if (i != static_cast<unsigned int>(_column - 1))
            {
                possibleTypes.erase(std::remove(possibleTypes.begin(), possibleTypes.end(), currentSockets[i].getType()), possibleTypes.end());
            }
        }
    }

    std::vector<QListWidgetItem*> possibleSockets;
    for (Socket::Type type : possibleTypes)
    {
        QIcon typeIcon(*getFrameFromSocket(type));
        QString typeDescription;
        if (type == Socket::Type::Dmr)
        {
            typeDescription = "Dmg Red.";
        }
        else if (type == Socket::Type::Cd)
        {
            typeDescription = "Cooldown";
        }
        else if (type == Socket::Type::Bind)
        {
            typeDescription = "Bind";
        }
        else if (type == Socket::Type::Despair)
        {
            typeDescription = "Despair";
        }
        else if (type == Socket::Type::AH)
        {
            typeDescription = "Autoheal";
        }
        else if (type == Socket::Type::Rcv)
        {
            typeDescription = "Rcv";
        }
        else if (type == Socket::Type::Slot)
        {
            typeDescription = "Orb rate";
        }
        else if (type == Socket::Type::Map)
        {
            typeDescription = "Map";
        }
        else if (type == Socket::Type::Poison)
        {
            typeDescription = "Poison";
        }
        else if (type == Socket::Type::Resilience)
        {
            typeDescription = "Resilience";
        }
        QListWidgetItem* socket = new QListWidgetItem(typeIcon, typeDescription);
        possibleSockets.push_back(socket);
    }
    QIcon typeNone(*getFrameFromSocket(Socket::Type::None));
    QListWidgetItem* socketNone = new QListWidgetItem(typeNone, "None");
    possibleSockets.push_back(socketNone);


    // Aggiunge socket none
    SocketSelection* window = new SocketSelection(_row, _column, possibleSockets, this);
    connect(window, SIGNAL(acceptedSocket(int, int, Socket::Type)), this, SLOT(acceptedSelection(int, int, Socket::Type)));
    window->show();
}

void MyCharacterForm::on_lbUnlockedEdit_editingFinished()
{
    if (ui->lbUnlockedEdit->text() == "")
    {
        ui->lbUnlockedEdit->setText("0");
    }
}

void MyCharacterForm::on_cottonHpEdit_editingFinished()
{
    if (ui->cottonHpEdit->text() == "")
    {
        ui->cottonHpEdit->setText("0");
    }
}

void MyCharacterForm::on_cottonAtkEdit_editingFinished()
{
    if (ui->cottonAtkEdit->text() == "")
    {
        ui->cottonAtkEdit->setText("0");
    }
}

void MyCharacterForm::on_cottonRcvEdit_editingFinished()
{
    if (ui->cottonRcvEdit->text() == "")
    {
        ui->cottonRcvEdit->setText("0");
    }
}

void MyCharacterForm::on_firstSocketEdit_editingFinished()
{
    if (ui->firstSocketEdit->text() == "")
    {
        ui->firstSocketEdit->setText("1");
    }
}

void MyCharacterForm::on_secondSocketEdit_editingFinished()
{
    if (ui->secondSocketEdit->text() == "")
    {
        ui->secondSocketEdit->setText("1");
    }
}

void MyCharacterForm::on_thirdSocketEdit_editingFinished()
{
    if (ui->thirdSocketEdit->text() == "")
    {
        ui->thirdSocketEdit->setText("1");
    }
}

void MyCharacterForm::on_fourthSocketEdit_editingFinished()
{
    if (ui->fourthSocketEdit->text() == "")
    {
        ui->fourthSocketEdit->setText("1");
    }
}

void MyCharacterForm::on_fifthSocketEdit_editingFinished()
{
    if (ui->fifthSocketEdit->text() == "")
    {
        ui->fifthSocketEdit->setText("1");
    }
}

void MyCharacterForm::on_levelEdit_editingFinished()
{
    if (ui->levelEdit->text() == "")
    {
        ui->levelEdit->setText("1");
    }
}

void MyCharacterForm::on_skillLevelEdit_editingFinished()
{
    if (ui->skillLevelEdit->text() == "")
    {
        ui->skillLevelEdit->setText("1");
    }
}

void MyCharacterForm::on_firstPotentialValueEdit_editingFinished()
{
    if (ui->firstPotentialValueEdit->text() == "")
    {
        ui->firstPotentialValueEdit->setText("1");
    }
}

void MyCharacterForm::on_secondPotentialValueEdit_editingFinished()
{
    if (ui->secondPotentialValueEdit->text() == "")
    {
        ui->secondPotentialValueEdit->setText("1");
    }
}

void MyCharacterForm::on_thirdPotentialValueEdit_editingFinished()
{
    if (ui->thirdPotentialValueEdit->text() == "")
    {
        ui->thirdPotentialValueEdit->setText("1");
    }
}

void MyCharacterForm::on_wantToFinishLevel_stateChanged(int _state)
{
    if (_state > 0)
    {
        myCharacter->setWantToFinishLevel(true);
    }
    else
    {
        myCharacter->setWantToFinishLevel(false);
    }
}

void MyCharacterForm::on_wantToFinishCotton_stateChanged(int _state)
{
    if (_state > 0)
    {
        myCharacter->setWantToFinishCotton(true);
    }
    else
    {
        myCharacter->setWantToFinishCotton(false);
    }
}

void MyCharacterForm::on_wantToFinishSkill_stateChanged(int _state)
{
    if (_state > 0)
    {
        myCharacter->setWantToFinishSkill(true);
    }
    else
    {
        myCharacter->setWantToFinishSkill(false);
    }
}

void MyCharacterForm::on_wantToFinishSocket_stateChanged(int _state)
{
    if (_state > 0)
    {
        myCharacter->setWantToFinishSockets(true);
    }
    else
    {
        myCharacter->setWantToFinishSockets(false);
    }
}

void MyCharacterForm::on_wantToFinishLimit_stateChanged(int _state)
{
    if (_state > 0)
    {
        myCharacter->setWantToFinishLimitBreak(true);
    }
    else
    {
        myCharacter->setWantToFinishLimitBreak(false);
    }
}

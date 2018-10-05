/********************************************************************************
** Form generated from reading UI file 'mycharacterform.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCHARACTERFORM_H
#define UI_MYCHARACTERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyCharacterForm
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *wantToFinishLabel;
    QHBoxLayout *wantToFinishLayout;
    QCheckBox *wantToFinishLevel;
    QCheckBox *wantToFinishCotton;
    QCheckBox *wantToFinishSkill;
    QCheckBox *wantToFinishSocket;
    QCheckBox *wantToFinishLimit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QHBoxLayout *levelAndSkillLayout;
    QHBoxLayout *levelLayout;
    QHBoxLayout *levelSubLayout;
    QLabel *fixedLevelLabel;
    QLineEdit *levelEdit;
    QLabel *maxLevel;
    QSpacerItem *levelSpacer;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *skillLevelLayout;
    QHBoxLayout *skillLevelSubLayout;
    QLabel *fixedSkillLevelLabel;
    QLineEdit *skillLevelEdit;
    QLabel *maxSkillLevel;
    QSpacerItem *skillSpacer;
    QGridLayout *socketLayout;
    QPushButton *secondDesiredSocket;
    QPushButton *fourthDesiredSocket;
    QLineEdit *firstSocketEdit;
    QPushButton *thirdDesiredSocket;
    QLineEdit *thirdSocketEdit;
    QLineEdit *secondSocketEdit;
    QLineEdit *fifthSocketEdit;
    QPushButton *fifthDesiredSocket;
    QLabel *currentSocketsLabel;
    QLineEdit *fourthSocketEdit;
    QPushButton *fifthCurrentSocket;
    QPushButton *firstCurrentSocket;
    QPushButton *secondCurrentSocket;
    QPushButton *firstDesiredSocket;
    QPushButton *fourthCurrentSocket;
    QLabel *desiredSocketsLabel;
    QLabel *missingSocketsLabel;
    QPushButton *firstMissingSocket;
    QPushButton *thirdCurrentSocket;
    QPushButton *secondMissingSocket;
    QLineEdit *firstMissingEdit;
    QPushButton *thirdMissingSocket;
    QPushButton *fourthMissingSocket;
    QPushButton *fifthMissingSocket;
    QLineEdit *thirdMissingEdit;
    QLineEdit *secondMissingEdit;
    QLineEdit *fifthMissingEdit;
    QLineEdit *fourthMissingEdit;
    QSpacerItem *socketSpacer;
    QGridLayout *cottonLayout;
    QLineEdit *statsHpEdit;
    QLineEdit *cottonRcvEdit;
    QLabel *fixedCottonHpLabel;
    QLineEdit *statsRcvEdit;
    QLineEdit *cottonHpEdit;
    QLabel *maxCC;
    QLineEdit *statsAtkEdit;
    QLabel *fixedCottonAtkLabel;
    QLineEdit *cottonAtkEdit;
    QLabel *fixedCottonLabel;
    QLineEdit *cottonTotalEdit;
    QSpacerItem *ccSpacer;
    QLabel *fixedStatsLabel;
    QLabel *fixedCottonRcvLabel;
    QHBoxLayout *trainingPointsMaxLayout;
    QHBoxLayout *trainingPointsLayout;
    QLabel *fixedTrainingPointsLabel;
    QLineEdit *trainingPointsEdit;
    QLabel *maxTrainingPoints;
    QSpacerItem *maxTrainingPointsSpacer;
    QHBoxLayout *lbUnlockedMaxLayout;
    QHBoxLayout *lbUnlockedLayout;
    QLabel *fixedLbUnlockedLabel;
    QLineEdit *lbUnlockedEdit;
    QLabel *maxLbUnlocked;
    QSpacerItem *maxLbUnlockedSpacer;
    QGridLayout *potentialLayout;
    QPushButton *firstPotential;
    QPushButton *secondPotential;
    QPushButton *thirdPotential;
    QLineEdit *firstPotentialValueEdit;
    QLineEdit *secondPotentialValueEdit;
    QLineEdit *thirdPotentialValueEdit;
    QLabel *fixedPotentialLabel;
    QSpacerItem *potentialSpacer;
    QSpacerItem *myCharacterSpacer;

    void setupUi(QWidget *MyCharacterForm)
    {
        if (MyCharacterForm->objectName().isEmpty())
            MyCharacterForm->setObjectName(QStringLiteral("MyCharacterForm"));
        MyCharacterForm->resize(300, 475);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MyCharacterForm->sizePolicy().hasHeightForWidth());
        MyCharacterForm->setSizePolicy(sizePolicy);
        MyCharacterForm->setMinimumSize(QSize(300, 0));
        MyCharacterForm->setMaximumSize(QSize(300, 16777215));
        verticalLayout = new QVBoxLayout(MyCharacterForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        scrollArea = new QScrollArea(MyCharacterForm);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMinimumSize(QSize(280, 0));
        scrollArea->setMaximumSize(QSize(280, 16777215));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaLayout = new QWidget();
        scrollAreaLayout->setObjectName(QStringLiteral("scrollAreaLayout"));
        scrollAreaLayout->setGeometry(QRect(0, 0, 278, 455));
        verticalLayout_2 = new QVBoxLayout(scrollAreaLayout);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        wantToFinishLabel = new QLabel(scrollAreaLayout);
        wantToFinishLabel->setObjectName(QStringLiteral("wantToFinishLabel"));
        wantToFinishLabel->setStyleSheet(QStringLiteral("font: 75 8pt \"MS Shell Dlg 2\";"));

        verticalLayout_2->addWidget(wantToFinishLabel, 0, Qt::AlignHCenter);

        wantToFinishLayout = new QHBoxLayout();
        wantToFinishLayout->setSpacing(0);
        wantToFinishLayout->setObjectName(QStringLiteral("wantToFinishLayout"));
        wantToFinishLayout->setSizeConstraint(QLayout::SetFixedSize);
        wantToFinishLevel = new QCheckBox(scrollAreaLayout);
        wantToFinishLevel->setObjectName(QStringLiteral("wantToFinishLevel"));

        wantToFinishLayout->addWidget(wantToFinishLevel, 0, Qt::AlignLeft);

        wantToFinishCotton = new QCheckBox(scrollAreaLayout);
        wantToFinishCotton->setObjectName(QStringLiteral("wantToFinishCotton"));

        wantToFinishLayout->addWidget(wantToFinishCotton, 0, Qt::AlignLeft);

        wantToFinishSkill = new QCheckBox(scrollAreaLayout);
        wantToFinishSkill->setObjectName(QStringLiteral("wantToFinishSkill"));

        wantToFinishLayout->addWidget(wantToFinishSkill, 0, Qt::AlignLeft);

        wantToFinishSocket = new QCheckBox(scrollAreaLayout);
        wantToFinishSocket->setObjectName(QStringLiteral("wantToFinishSocket"));

        wantToFinishLayout->addWidget(wantToFinishSocket, 0, Qt::AlignLeft);

        wantToFinishLimit = new QCheckBox(scrollAreaLayout);
        wantToFinishLimit->setObjectName(QStringLiteral("wantToFinishLimit"));

        wantToFinishLayout->addWidget(wantToFinishLimit, 0, Qt::AlignLeft);

        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        wantToFinishLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(wantToFinishLayout);

        label = new QLabel(scrollAreaLayout);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("font: 75 8pt;"));

        verticalLayout_2->addWidget(label, 0, Qt::AlignHCenter);

        levelAndSkillLayout = new QHBoxLayout();
        levelAndSkillLayout->setSpacing(0);
        levelAndSkillLayout->setObjectName(QStringLiteral("levelAndSkillLayout"));
        levelAndSkillLayout->setSizeConstraint(QLayout::SetFixedSize);
        levelLayout = new QHBoxLayout();
        levelLayout->setSpacing(2);
        levelLayout->setObjectName(QStringLiteral("levelLayout"));
        levelLayout->setSizeConstraint(QLayout::SetFixedSize);
        levelSubLayout = new QHBoxLayout();
        levelSubLayout->setSpacing(0);
        levelSubLayout->setObjectName(QStringLiteral("levelSubLayout"));
        levelSubLayout->setSizeConstraint(QLayout::SetFixedSize);
        fixedLevelLabel = new QLabel(scrollAreaLayout);
        fixedLevelLabel->setObjectName(QStringLiteral("fixedLevelLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fixedLevelLabel->sizePolicy().hasHeightForWidth());
        fixedLevelLabel->setSizePolicy(sizePolicy2);
        fixedLevelLabel->setMinimumSize(QSize(1, 0));

        levelSubLayout->addWidget(fixedLevelLabel, 0, Qt::AlignLeft);

        levelEdit = new QLineEdit(scrollAreaLayout);
        levelEdit->setObjectName(QStringLiteral("levelEdit"));
        levelEdit->setEnabled(false);
        sizePolicy2.setHeightForWidth(levelEdit->sizePolicy().hasHeightForWidth());
        levelEdit->setSizePolicy(sizePolicy2);
        levelEdit->setMaximumSize(QSize(20, 16777215));

        levelSubLayout->addWidget(levelEdit, 0, Qt::AlignRight);


        levelLayout->addLayout(levelSubLayout);

        maxLevel = new QLabel(scrollAreaLayout);
        maxLevel->setObjectName(QStringLiteral("maxLevel"));
        sizePolicy2.setHeightForWidth(maxLevel->sizePolicy().hasHeightForWidth());
        maxLevel->setSizePolicy(sizePolicy2);
        maxLevel->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"font: bold 8pt;"));

        levelLayout->addWidget(maxLevel);

        levelSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        levelLayout->addItem(levelSpacer);


        levelAndSkillLayout->addLayout(levelLayout);

        horizontalSpacer = new QSpacerItem(45, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        levelAndSkillLayout->addItem(horizontalSpacer);

        skillLevelLayout = new QHBoxLayout();
        skillLevelLayout->setSpacing(2);
        skillLevelLayout->setObjectName(QStringLiteral("skillLevelLayout"));
        skillLevelLayout->setSizeConstraint(QLayout::SetFixedSize);
        skillLevelSubLayout = new QHBoxLayout();
        skillLevelSubLayout->setSpacing(0);
        skillLevelSubLayout->setObjectName(QStringLiteral("skillLevelSubLayout"));
        skillLevelSubLayout->setSizeConstraint(QLayout::SetFixedSize);
        fixedSkillLevelLabel = new QLabel(scrollAreaLayout);
        fixedSkillLevelLabel->setObjectName(QStringLiteral("fixedSkillLevelLabel"));
        sizePolicy2.setHeightForWidth(fixedSkillLevelLabel->sizePolicy().hasHeightForWidth());
        fixedSkillLevelLabel->setSizePolicy(sizePolicy2);
        fixedSkillLevelLabel->setMinimumSize(QSize(1, 0));

        skillLevelSubLayout->addWidget(fixedSkillLevelLabel, 0, Qt::AlignLeft);

        skillLevelEdit = new QLineEdit(scrollAreaLayout);
        skillLevelEdit->setObjectName(QStringLiteral("skillLevelEdit"));
        skillLevelEdit->setEnabled(false);
        sizePolicy2.setHeightForWidth(skillLevelEdit->sizePolicy().hasHeightForWidth());
        skillLevelEdit->setSizePolicy(sizePolicy2);
        skillLevelEdit->setMaximumSize(QSize(20, 16777215));

        skillLevelSubLayout->addWidget(skillLevelEdit);


        skillLevelLayout->addLayout(skillLevelSubLayout);

        maxSkillLevel = new QLabel(scrollAreaLayout);
        maxSkillLevel->setObjectName(QStringLiteral("maxSkillLevel"));
        sizePolicy2.setHeightForWidth(maxSkillLevel->sizePolicy().hasHeightForWidth());
        maxSkillLevel->setSizePolicy(sizePolicy2);
        maxSkillLevel->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"font: bold 8pt;"));

        skillLevelLayout->addWidget(maxSkillLevel, 0, Qt::AlignLeft);

        skillSpacer = new QSpacerItem(0, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        skillLevelLayout->addItem(skillSpacer);


        levelAndSkillLayout->addLayout(skillLevelLayout);


        verticalLayout_2->addLayout(levelAndSkillLayout);

        socketLayout = new QGridLayout();
        socketLayout->setSpacing(0);
        socketLayout->setObjectName(QStringLiteral("socketLayout"));
        socketLayout->setSizeConstraint(QLayout::SetFixedSize);
        secondDesiredSocket = new QPushButton(scrollAreaLayout);
        secondDesiredSocket->setObjectName(QStringLiteral("secondDesiredSocket"));
        sizePolicy2.setHeightForWidth(secondDesiredSocket->sizePolicy().hasHeightForWidth());
        secondDesiredSocket->setSizePolicy(sizePolicy2);
        secondDesiredSocket->setMinimumSize(QSize(30, 30));
        secondDesiredSocket->setMaximumSize(QSize(30, 30));
        secondDesiredSocket->setFlat(true);

        socketLayout->addWidget(secondDesiredSocket, 0, 2, 1, 1);

        fourthDesiredSocket = new QPushButton(scrollAreaLayout);
        fourthDesiredSocket->setObjectName(QStringLiteral("fourthDesiredSocket"));
        sizePolicy2.setHeightForWidth(fourthDesiredSocket->sizePolicy().hasHeightForWidth());
        fourthDesiredSocket->setSizePolicy(sizePolicy2);
        fourthDesiredSocket->setMinimumSize(QSize(30, 30));
        fourthDesiredSocket->setMaximumSize(QSize(30, 30));
        fourthDesiredSocket->setFlat(true);

        socketLayout->addWidget(fourthDesiredSocket, 0, 4, 1, 1);

        firstSocketEdit = new QLineEdit(scrollAreaLayout);
        firstSocketEdit->setObjectName(QStringLiteral("firstSocketEdit"));
        sizePolicy2.setHeightForWidth(firstSocketEdit->sizePolicy().hasHeightForWidth());
        firstSocketEdit->setSizePolicy(sizePolicy2);
        firstSocketEdit->setMinimumSize(QSize(30, 0));
        firstSocketEdit->setMaximumSize(QSize(30, 16777215));
        firstSocketEdit->setAlignment(Qt::AlignCenter);

        socketLayout->addWidget(firstSocketEdit, 2, 1, 1, 1);

        thirdDesiredSocket = new QPushButton(scrollAreaLayout);
        thirdDesiredSocket->setObjectName(QStringLiteral("thirdDesiredSocket"));
        sizePolicy2.setHeightForWidth(thirdDesiredSocket->sizePolicy().hasHeightForWidth());
        thirdDesiredSocket->setSizePolicy(sizePolicy2);
        thirdDesiredSocket->setMinimumSize(QSize(30, 30));
        thirdDesiredSocket->setMaximumSize(QSize(30, 30));
        thirdDesiredSocket->setFlat(true);

        socketLayout->addWidget(thirdDesiredSocket, 0, 3, 1, 1);

        thirdSocketEdit = new QLineEdit(scrollAreaLayout);
        thirdSocketEdit->setObjectName(QStringLiteral("thirdSocketEdit"));
        sizePolicy2.setHeightForWidth(thirdSocketEdit->sizePolicy().hasHeightForWidth());
        thirdSocketEdit->setSizePolicy(sizePolicy2);
        thirdSocketEdit->setMinimumSize(QSize(30, 0));
        thirdSocketEdit->setMaximumSize(QSize(30, 16777215));
        thirdSocketEdit->setAlignment(Qt::AlignCenter);

        socketLayout->addWidget(thirdSocketEdit, 2, 3, 1, 1);

        secondSocketEdit = new QLineEdit(scrollAreaLayout);
        secondSocketEdit->setObjectName(QStringLiteral("secondSocketEdit"));
        sizePolicy2.setHeightForWidth(secondSocketEdit->sizePolicy().hasHeightForWidth());
        secondSocketEdit->setSizePolicy(sizePolicy2);
        secondSocketEdit->setMinimumSize(QSize(30, 0));
        secondSocketEdit->setMaximumSize(QSize(30, 16777215));
        secondSocketEdit->setAlignment(Qt::AlignCenter);

        socketLayout->addWidget(secondSocketEdit, 2, 2, 1, 1);

        fifthSocketEdit = new QLineEdit(scrollAreaLayout);
        fifthSocketEdit->setObjectName(QStringLiteral("fifthSocketEdit"));
        sizePolicy2.setHeightForWidth(fifthSocketEdit->sizePolicy().hasHeightForWidth());
        fifthSocketEdit->setSizePolicy(sizePolicy2);
        fifthSocketEdit->setMinimumSize(QSize(30, 0));
        fifthSocketEdit->setMaximumSize(QSize(30, 16777215));
        fifthSocketEdit->setAlignment(Qt::AlignCenter);

        socketLayout->addWidget(fifthSocketEdit, 2, 5, 1, 1);

        fifthDesiredSocket = new QPushButton(scrollAreaLayout);
        fifthDesiredSocket->setObjectName(QStringLiteral("fifthDesiredSocket"));
        sizePolicy2.setHeightForWidth(fifthDesiredSocket->sizePolicy().hasHeightForWidth());
        fifthDesiredSocket->setSizePolicy(sizePolicy2);
        fifthDesiredSocket->setMinimumSize(QSize(30, 30));
        fifthDesiredSocket->setMaximumSize(QSize(30, 30));
        fifthDesiredSocket->setFlat(true);

        socketLayout->addWidget(fifthDesiredSocket, 0, 5, 1, 1);

        currentSocketsLabel = new QLabel(scrollAreaLayout);
        currentSocketsLabel->setObjectName(QStringLiteral("currentSocketsLabel"));
        sizePolicy.setHeightForWidth(currentSocketsLabel->sizePolicy().hasHeightForWidth());
        currentSocketsLabel->setSizePolicy(sizePolicy);

        socketLayout->addWidget(currentSocketsLabel, 1, 0, 1, 1);

        fourthSocketEdit = new QLineEdit(scrollAreaLayout);
        fourthSocketEdit->setObjectName(QStringLiteral("fourthSocketEdit"));
        sizePolicy2.setHeightForWidth(fourthSocketEdit->sizePolicy().hasHeightForWidth());
        fourthSocketEdit->setSizePolicy(sizePolicy2);
        fourthSocketEdit->setMinimumSize(QSize(30, 0));
        fourthSocketEdit->setMaximumSize(QSize(30, 16777215));
        fourthSocketEdit->setAlignment(Qt::AlignCenter);

        socketLayout->addWidget(fourthSocketEdit, 2, 4, 1, 1);

        fifthCurrentSocket = new QPushButton(scrollAreaLayout);
        fifthCurrentSocket->setObjectName(QStringLiteral("fifthCurrentSocket"));
        sizePolicy2.setHeightForWidth(fifthCurrentSocket->sizePolicy().hasHeightForWidth());
        fifthCurrentSocket->setSizePolicy(sizePolicy2);
        fifthCurrentSocket->setMinimumSize(QSize(30, 30));
        fifthCurrentSocket->setMaximumSize(QSize(30, 30));
        fifthCurrentSocket->setFlat(true);

        socketLayout->addWidget(fifthCurrentSocket, 1, 5, 1, 1);

        firstCurrentSocket = new QPushButton(scrollAreaLayout);
        firstCurrentSocket->setObjectName(QStringLiteral("firstCurrentSocket"));
        sizePolicy2.setHeightForWidth(firstCurrentSocket->sizePolicy().hasHeightForWidth());
        firstCurrentSocket->setSizePolicy(sizePolicy2);
        firstCurrentSocket->setMinimumSize(QSize(30, 30));
        firstCurrentSocket->setMaximumSize(QSize(30, 30));
        firstCurrentSocket->setFlat(true);

        socketLayout->addWidget(firstCurrentSocket, 1, 1, 1, 1);

        secondCurrentSocket = new QPushButton(scrollAreaLayout);
        secondCurrentSocket->setObjectName(QStringLiteral("secondCurrentSocket"));
        sizePolicy2.setHeightForWidth(secondCurrentSocket->sizePolicy().hasHeightForWidth());
        secondCurrentSocket->setSizePolicy(sizePolicy2);
        secondCurrentSocket->setMinimumSize(QSize(30, 30));
        secondCurrentSocket->setMaximumSize(QSize(30, 30));
        secondCurrentSocket->setFlat(true);

        socketLayout->addWidget(secondCurrentSocket, 1, 2, 1, 1);

        firstDesiredSocket = new QPushButton(scrollAreaLayout);
        firstDesiredSocket->setObjectName(QStringLiteral("firstDesiredSocket"));
        sizePolicy2.setHeightForWidth(firstDesiredSocket->sizePolicy().hasHeightForWidth());
        firstDesiredSocket->setSizePolicy(sizePolicy2);
        firstDesiredSocket->setMinimumSize(QSize(30, 30));
        firstDesiredSocket->setMaximumSize(QSize(30, 30));
        firstDesiredSocket->setFlat(true);

        socketLayout->addWidget(firstDesiredSocket, 0, 1, 1, 1);

        fourthCurrentSocket = new QPushButton(scrollAreaLayout);
        fourthCurrentSocket->setObjectName(QStringLiteral("fourthCurrentSocket"));
        sizePolicy2.setHeightForWidth(fourthCurrentSocket->sizePolicy().hasHeightForWidth());
        fourthCurrentSocket->setSizePolicy(sizePolicy2);
        fourthCurrentSocket->setMinimumSize(QSize(30, 30));
        fourthCurrentSocket->setMaximumSize(QSize(30, 30));
        fourthCurrentSocket->setFlat(true);

        socketLayout->addWidget(fourthCurrentSocket, 1, 4, 1, 1);

        desiredSocketsLabel = new QLabel(scrollAreaLayout);
        desiredSocketsLabel->setObjectName(QStringLiteral("desiredSocketsLabel"));
        sizePolicy.setHeightForWidth(desiredSocketsLabel->sizePolicy().hasHeightForWidth());
        desiredSocketsLabel->setSizePolicy(sizePolicy);

        socketLayout->addWidget(desiredSocketsLabel, 0, 0, 1, 1, Qt::AlignLeft);

        missingSocketsLabel = new QLabel(scrollAreaLayout);
        missingSocketsLabel->setObjectName(QStringLiteral("missingSocketsLabel"));
        sizePolicy.setHeightForWidth(missingSocketsLabel->sizePolicy().hasHeightForWidth());
        missingSocketsLabel->setSizePolicy(sizePolicy);

        socketLayout->addWidget(missingSocketsLabel, 3, 0, 1, 1);

        firstMissingSocket = new QPushButton(scrollAreaLayout);
        firstMissingSocket->setObjectName(QStringLiteral("firstMissingSocket"));
        firstMissingSocket->setEnabled(true);
        sizePolicy2.setHeightForWidth(firstMissingSocket->sizePolicy().hasHeightForWidth());
        firstMissingSocket->setSizePolicy(sizePolicy2);
        firstMissingSocket->setMinimumSize(QSize(30, 30));
        firstMissingSocket->setMaximumSize(QSize(30, 30));
        firstMissingSocket->setFlat(true);

        socketLayout->addWidget(firstMissingSocket, 3, 1, 1, 1);

        thirdCurrentSocket = new QPushButton(scrollAreaLayout);
        thirdCurrentSocket->setObjectName(QStringLiteral("thirdCurrentSocket"));
        sizePolicy2.setHeightForWidth(thirdCurrentSocket->sizePolicy().hasHeightForWidth());
        thirdCurrentSocket->setSizePolicy(sizePolicy2);
        thirdCurrentSocket->setMinimumSize(QSize(30, 30));
        thirdCurrentSocket->setMaximumSize(QSize(30, 30));
        thirdCurrentSocket->setFlat(true);

        socketLayout->addWidget(thirdCurrentSocket, 1, 3, 1, 1);

        secondMissingSocket = new QPushButton(scrollAreaLayout);
        secondMissingSocket->setObjectName(QStringLiteral("secondMissingSocket"));
        secondMissingSocket->setEnabled(true);
        sizePolicy2.setHeightForWidth(secondMissingSocket->sizePolicy().hasHeightForWidth());
        secondMissingSocket->setSizePolicy(sizePolicy2);
        secondMissingSocket->setMinimumSize(QSize(30, 30));
        secondMissingSocket->setMaximumSize(QSize(30, 30));
        secondMissingSocket->setFlat(true);

        socketLayout->addWidget(secondMissingSocket, 3, 2, 1, 1);

        firstMissingEdit = new QLineEdit(scrollAreaLayout);
        firstMissingEdit->setObjectName(QStringLiteral("firstMissingEdit"));
        firstMissingEdit->setEnabled(false);
        sizePolicy2.setHeightForWidth(firstMissingEdit->sizePolicy().hasHeightForWidth());
        firstMissingEdit->setSizePolicy(sizePolicy2);
        firstMissingEdit->setMinimumSize(QSize(30, 0));
        firstMissingEdit->setMaximumSize(QSize(30, 16777215));
        firstMissingEdit->setAlignment(Qt::AlignCenter);

        socketLayout->addWidget(firstMissingEdit, 4, 1, 1, 1);

        thirdMissingSocket = new QPushButton(scrollAreaLayout);
        thirdMissingSocket->setObjectName(QStringLiteral("thirdMissingSocket"));
        thirdMissingSocket->setEnabled(true);
        sizePolicy2.setHeightForWidth(thirdMissingSocket->sizePolicy().hasHeightForWidth());
        thirdMissingSocket->setSizePolicy(sizePolicy2);
        thirdMissingSocket->setMinimumSize(QSize(30, 30));
        thirdMissingSocket->setMaximumSize(QSize(30, 30));
        thirdMissingSocket->setFlat(true);

        socketLayout->addWidget(thirdMissingSocket, 3, 3, 1, 1);

        fourthMissingSocket = new QPushButton(scrollAreaLayout);
        fourthMissingSocket->setObjectName(QStringLiteral("fourthMissingSocket"));
        fourthMissingSocket->setEnabled(true);
        sizePolicy2.setHeightForWidth(fourthMissingSocket->sizePolicy().hasHeightForWidth());
        fourthMissingSocket->setSizePolicy(sizePolicy2);
        fourthMissingSocket->setMinimumSize(QSize(30, 30));
        fourthMissingSocket->setMaximumSize(QSize(30, 30));
        fourthMissingSocket->setFlat(true);

        socketLayout->addWidget(fourthMissingSocket, 3, 4, 1, 1);

        fifthMissingSocket = new QPushButton(scrollAreaLayout);
        fifthMissingSocket->setObjectName(QStringLiteral("fifthMissingSocket"));
        fifthMissingSocket->setEnabled(true);
        sizePolicy2.setHeightForWidth(fifthMissingSocket->sizePolicy().hasHeightForWidth());
        fifthMissingSocket->setSizePolicy(sizePolicy2);
        fifthMissingSocket->setMinimumSize(QSize(30, 30));
        fifthMissingSocket->setMaximumSize(QSize(30, 30));
        fifthMissingSocket->setFlat(true);

        socketLayout->addWidget(fifthMissingSocket, 3, 5, 1, 1);

        thirdMissingEdit = new QLineEdit(scrollAreaLayout);
        thirdMissingEdit->setObjectName(QStringLiteral("thirdMissingEdit"));
        thirdMissingEdit->setEnabled(false);
        sizePolicy2.setHeightForWidth(thirdMissingEdit->sizePolicy().hasHeightForWidth());
        thirdMissingEdit->setSizePolicy(sizePolicy2);
        thirdMissingEdit->setMinimumSize(QSize(30, 0));
        thirdMissingEdit->setMaximumSize(QSize(30, 16777215));
        thirdMissingEdit->setAlignment(Qt::AlignCenter);

        socketLayout->addWidget(thirdMissingEdit, 4, 3, 1, 1);

        secondMissingEdit = new QLineEdit(scrollAreaLayout);
        secondMissingEdit->setObjectName(QStringLiteral("secondMissingEdit"));
        secondMissingEdit->setEnabled(false);
        sizePolicy2.setHeightForWidth(secondMissingEdit->sizePolicy().hasHeightForWidth());
        secondMissingEdit->setSizePolicy(sizePolicy2);
        secondMissingEdit->setMinimumSize(QSize(30, 0));
        secondMissingEdit->setMaximumSize(QSize(30, 16777215));
        secondMissingEdit->setAlignment(Qt::AlignCenter);

        socketLayout->addWidget(secondMissingEdit, 4, 2, 1, 1);

        fifthMissingEdit = new QLineEdit(scrollAreaLayout);
        fifthMissingEdit->setObjectName(QStringLiteral("fifthMissingEdit"));
        fifthMissingEdit->setEnabled(false);
        sizePolicy2.setHeightForWidth(fifthMissingEdit->sizePolicy().hasHeightForWidth());
        fifthMissingEdit->setSizePolicy(sizePolicy2);
        fifthMissingEdit->setMinimumSize(QSize(30, 0));
        fifthMissingEdit->setMaximumSize(QSize(30, 16777215));
        fifthMissingEdit->setAlignment(Qt::AlignCenter);

        socketLayout->addWidget(fifthMissingEdit, 4, 5, 1, 1);

        fourthMissingEdit = new QLineEdit(scrollAreaLayout);
        fourthMissingEdit->setObjectName(QStringLiteral("fourthMissingEdit"));
        fourthMissingEdit->setEnabled(false);
        sizePolicy2.setHeightForWidth(fourthMissingEdit->sizePolicy().hasHeightForWidth());
        fourthMissingEdit->setSizePolicy(sizePolicy2);
        fourthMissingEdit->setMinimumSize(QSize(30, 0));
        fourthMissingEdit->setMaximumSize(QSize(30, 16777215));
        fourthMissingEdit->setAlignment(Qt::AlignCenter);

        socketLayout->addWidget(fourthMissingEdit, 4, 4, 1, 1);

        socketSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        socketLayout->addItem(socketSpacer, 2, 6, 1, 1);


        verticalLayout_2->addLayout(socketLayout);

        cottonLayout = new QGridLayout();
        cottonLayout->setObjectName(QStringLiteral("cottonLayout"));
        cottonLayout->setSizeConstraint(QLayout::SetFixedSize);
        cottonLayout->setHorizontalSpacing(0);
        cottonLayout->setVerticalSpacing(3);
        statsHpEdit = new QLineEdit(scrollAreaLayout);
        statsHpEdit->setObjectName(QStringLiteral("statsHpEdit"));
        statsHpEdit->setEnabled(false);
        sizePolicy2.setHeightForWidth(statsHpEdit->sizePolicy().hasHeightForWidth());
        statsHpEdit->setSizePolicy(sizePolicy2);
        statsHpEdit->setMinimumSize(QSize(30, 0));
        statsHpEdit->setMaximumSize(QSize(30, 16777215));

        cottonLayout->addWidget(statsHpEdit, 1, 1, 1, 1, Qt::AlignLeft);

        cottonRcvEdit = new QLineEdit(scrollAreaLayout);
        cottonRcvEdit->setObjectName(QStringLiteral("cottonRcvEdit"));
        sizePolicy2.setHeightForWidth(cottonRcvEdit->sizePolicy().hasHeightForWidth());
        cottonRcvEdit->setSizePolicy(sizePolicy2);
        cottonRcvEdit->setMinimumSize(QSize(30, 0));
        cottonRcvEdit->setMaximumSize(QSize(30, 16777215));

        cottonLayout->addWidget(cottonRcvEdit, 2, 3, 1, 1, Qt::AlignLeft);

        fixedCottonHpLabel = new QLabel(scrollAreaLayout);
        fixedCottonHpLabel->setObjectName(QStringLiteral("fixedCottonHpLabel"));
        sizePolicy2.setHeightForWidth(fixedCottonHpLabel->sizePolicy().hasHeightForWidth());
        fixedCottonHpLabel->setSizePolicy(sizePolicy2);
        fixedCottonHpLabel->setMinimumSize(QSize(20, 0));

        cottonLayout->addWidget(fixedCottonHpLabel, 0, 1, 1, 1, Qt::AlignLeft);

        statsRcvEdit = new QLineEdit(scrollAreaLayout);
        statsRcvEdit->setObjectName(QStringLiteral("statsRcvEdit"));
        statsRcvEdit->setEnabled(false);
        sizePolicy2.setHeightForWidth(statsRcvEdit->sizePolicy().hasHeightForWidth());
        statsRcvEdit->setSizePolicy(sizePolicy2);
        statsRcvEdit->setMinimumSize(QSize(30, 0));
        statsRcvEdit->setMaximumSize(QSize(30, 16777215));

        cottonLayout->addWidget(statsRcvEdit, 1, 3, 1, 1, Qt::AlignLeft);

        cottonHpEdit = new QLineEdit(scrollAreaLayout);
        cottonHpEdit->setObjectName(QStringLiteral("cottonHpEdit"));
        sizePolicy2.setHeightForWidth(cottonHpEdit->sizePolicy().hasHeightForWidth());
        cottonHpEdit->setSizePolicy(sizePolicy2);
        cottonHpEdit->setMinimumSize(QSize(30, 0));
        cottonHpEdit->setMaximumSize(QSize(30, 16777215));

        cottonLayout->addWidget(cottonHpEdit, 2, 1, 1, 1, Qt::AlignLeft);

        maxCC = new QLabel(scrollAreaLayout);
        maxCC->setObjectName(QStringLiteral("maxCC"));
        sizePolicy.setHeightForWidth(maxCC->sizePolicy().hasHeightForWidth());
        maxCC->setSizePolicy(sizePolicy);
        maxCC->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"font: bold 8pt;"));

        cottonLayout->addWidget(maxCC, 2, 5, 1, 1, Qt::AlignLeft);

        statsAtkEdit = new QLineEdit(scrollAreaLayout);
        statsAtkEdit->setObjectName(QStringLiteral("statsAtkEdit"));
        statsAtkEdit->setEnabled(false);
        sizePolicy2.setHeightForWidth(statsAtkEdit->sizePolicy().hasHeightForWidth());
        statsAtkEdit->setSizePolicy(sizePolicy2);
        statsAtkEdit->setMinimumSize(QSize(30, 0));
        statsAtkEdit->setMaximumSize(QSize(30, 16777215));

        cottonLayout->addWidget(statsAtkEdit, 1, 2, 1, 1, Qt::AlignLeft);

        fixedCottonAtkLabel = new QLabel(scrollAreaLayout);
        fixedCottonAtkLabel->setObjectName(QStringLiteral("fixedCottonAtkLabel"));
        sizePolicy2.setHeightForWidth(fixedCottonAtkLabel->sizePolicy().hasHeightForWidth());
        fixedCottonAtkLabel->setSizePolicy(sizePolicy2);
        fixedCottonAtkLabel->setMinimumSize(QSize(20, 0));

        cottonLayout->addWidget(fixedCottonAtkLabel, 0, 2, 1, 1, Qt::AlignLeft);

        cottonAtkEdit = new QLineEdit(scrollAreaLayout);
        cottonAtkEdit->setObjectName(QStringLiteral("cottonAtkEdit"));
        sizePolicy2.setHeightForWidth(cottonAtkEdit->sizePolicy().hasHeightForWidth());
        cottonAtkEdit->setSizePolicy(sizePolicy2);
        cottonAtkEdit->setMinimumSize(QSize(30, 0));
        cottonAtkEdit->setMaximumSize(QSize(30, 16777215));

        cottonLayout->addWidget(cottonAtkEdit, 2, 2, 1, 1, Qt::AlignLeft);

        fixedCottonLabel = new QLabel(scrollAreaLayout);
        fixedCottonLabel->setObjectName(QStringLiteral("fixedCottonLabel"));
        sizePolicy2.setHeightForWidth(fixedCottonLabel->sizePolicy().hasHeightForWidth());
        fixedCottonLabel->setSizePolicy(sizePolicy2);
        fixedCottonLabel->setMinimumSize(QSize(20, 0));

        cottonLayout->addWidget(fixedCottonLabel, 2, 0, 1, 1, Qt::AlignLeft);

        cottonTotalEdit = new QLineEdit(scrollAreaLayout);
        cottonTotalEdit->setObjectName(QStringLiteral("cottonTotalEdit"));
        cottonTotalEdit->setEnabled(false);
        sizePolicy2.setHeightForWidth(cottonTotalEdit->sizePolicy().hasHeightForWidth());
        cottonTotalEdit->setSizePolicy(sizePolicy2);
        cottonTotalEdit->setMinimumSize(QSize(30, 0));
        cottonTotalEdit->setMaximumSize(QSize(20, 16777215));

        cottonLayout->addWidget(cottonTotalEdit, 2, 4, 1, 1, Qt::AlignLeft);

        ccSpacer = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        cottonLayout->addItem(ccSpacer, 1, 5, 1, 1);

        fixedStatsLabel = new QLabel(scrollAreaLayout);
        fixedStatsLabel->setObjectName(QStringLiteral("fixedStatsLabel"));
        sizePolicy2.setHeightForWidth(fixedStatsLabel->sizePolicy().hasHeightForWidth());
        fixedStatsLabel->setSizePolicy(sizePolicy2);

        cottonLayout->addWidget(fixedStatsLabel, 1, 0, 1, 1, Qt::AlignLeft);

        fixedCottonRcvLabel = new QLabel(scrollAreaLayout);
        fixedCottonRcvLabel->setObjectName(QStringLiteral("fixedCottonRcvLabel"));
        sizePolicy2.setHeightForWidth(fixedCottonRcvLabel->sizePolicy().hasHeightForWidth());
        fixedCottonRcvLabel->setSizePolicy(sizePolicy2);
        fixedCottonRcvLabel->setMinimumSize(QSize(20, 0));

        cottonLayout->addWidget(fixedCottonRcvLabel, 0, 3, 1, 1, Qt::AlignLeft);


        verticalLayout_2->addLayout(cottonLayout);

        trainingPointsMaxLayout = new QHBoxLayout();
        trainingPointsMaxLayout->setSpacing(2);
        trainingPointsMaxLayout->setObjectName(QStringLiteral("trainingPointsMaxLayout"));
        trainingPointsMaxLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        trainingPointsLayout = new QHBoxLayout();
        trainingPointsLayout->setSpacing(3);
        trainingPointsLayout->setObjectName(QStringLiteral("trainingPointsLayout"));
        trainingPointsLayout->setSizeConstraint(QLayout::SetFixedSize);
        fixedTrainingPointsLabel = new QLabel(scrollAreaLayout);
        fixedTrainingPointsLabel->setObjectName(QStringLiteral("fixedTrainingPointsLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(fixedTrainingPointsLabel->sizePolicy().hasHeightForWidth());
        fixedTrainingPointsLabel->setSizePolicy(sizePolicy3);
        fixedTrainingPointsLabel->setMinimumSize(QSize(1, 0));

        trainingPointsLayout->addWidget(fixedTrainingPointsLabel, 0, Qt::AlignLeft);

        trainingPointsEdit = new QLineEdit(scrollAreaLayout);
        trainingPointsEdit->setObjectName(QStringLiteral("trainingPointsEdit"));
        trainingPointsEdit->setEnabled(false);
        sizePolicy2.setHeightForWidth(trainingPointsEdit->sizePolicy().hasHeightForWidth());
        trainingPointsEdit->setSizePolicy(sizePolicy2);
        trainingPointsEdit->setMinimumSize(QSize(50, 0));
        trainingPointsEdit->setMaximumSize(QSize(50, 16777215));

        trainingPointsLayout->addWidget(trainingPointsEdit, 0, Qt::AlignRight);


        trainingPointsMaxLayout->addLayout(trainingPointsLayout);

        maxTrainingPoints = new QLabel(scrollAreaLayout);
        maxTrainingPoints->setObjectName(QStringLiteral("maxTrainingPoints"));
        sizePolicy3.setHeightForWidth(maxTrainingPoints->sizePolicy().hasHeightForWidth());
        maxTrainingPoints->setSizePolicy(sizePolicy3);
        maxTrainingPoints->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"font: bold 8pt;"));

        trainingPointsMaxLayout->addWidget(maxTrainingPoints);

        maxTrainingPointsSpacer = new QSpacerItem(15, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        trainingPointsMaxLayout->addItem(maxTrainingPointsSpacer);


        verticalLayout_2->addLayout(trainingPointsMaxLayout);

        lbUnlockedMaxLayout = new QHBoxLayout();
        lbUnlockedMaxLayout->setSpacing(2);
        lbUnlockedMaxLayout->setObjectName(QStringLiteral("lbUnlockedMaxLayout"));
        lbUnlockedMaxLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        lbUnlockedLayout = new QHBoxLayout();
        lbUnlockedLayout->setSpacing(3);
        lbUnlockedLayout->setObjectName(QStringLiteral("lbUnlockedLayout"));
        lbUnlockedLayout->setSizeConstraint(QLayout::SetFixedSize);
        fixedLbUnlockedLabel = new QLabel(scrollAreaLayout);
        fixedLbUnlockedLabel->setObjectName(QStringLiteral("fixedLbUnlockedLabel"));
        sizePolicy3.setHeightForWidth(fixedLbUnlockedLabel->sizePolicy().hasHeightForWidth());
        fixedLbUnlockedLabel->setSizePolicy(sizePolicy3);
        fixedLbUnlockedLabel->setMinimumSize(QSize(1, 0));

        lbUnlockedLayout->addWidget(fixedLbUnlockedLabel, 0, Qt::AlignLeft);

        lbUnlockedEdit = new QLineEdit(scrollAreaLayout);
        lbUnlockedEdit->setObjectName(QStringLiteral("lbUnlockedEdit"));
        lbUnlockedEdit->setEnabled(false);
        sizePolicy2.setHeightForWidth(lbUnlockedEdit->sizePolicy().hasHeightForWidth());
        lbUnlockedEdit->setSizePolicy(sizePolicy2);
        lbUnlockedEdit->setMinimumSize(QSize(30, 0));
        lbUnlockedEdit->setMaximumSize(QSize(30, 16777215));

        lbUnlockedLayout->addWidget(lbUnlockedEdit, 0, Qt::AlignRight);


        lbUnlockedMaxLayout->addLayout(lbUnlockedLayout);

        maxLbUnlocked = new QLabel(scrollAreaLayout);
        maxLbUnlocked->setObjectName(QStringLiteral("maxLbUnlocked"));
        sizePolicy3.setHeightForWidth(maxLbUnlocked->sizePolicy().hasHeightForWidth());
        maxLbUnlocked->setSizePolicy(sizePolicy3);
        maxLbUnlocked->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"font: bold 8pt;"));

        lbUnlockedMaxLayout->addWidget(maxLbUnlocked);

        maxLbUnlockedSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lbUnlockedMaxLayout->addItem(maxLbUnlockedSpacer);


        verticalLayout_2->addLayout(lbUnlockedMaxLayout);

        potentialLayout = new QGridLayout();
        potentialLayout->setSpacing(0);
        potentialLayout->setObjectName(QStringLiteral("potentialLayout"));
        firstPotential = new QPushButton(scrollAreaLayout);
        firstPotential->setObjectName(QStringLiteral("firstPotential"));
        sizePolicy2.setHeightForWidth(firstPotential->sizePolicy().hasHeightForWidth());
        firstPotential->setSizePolicy(sizePolicy2);
        firstPotential->setMinimumSize(QSize(30, 30));
        firstPotential->setMaximumSize(QSize(30, 30));
        firstPotential->setFlat(true);

        potentialLayout->addWidget(firstPotential, 0, 1, 1, 1);

        secondPotential = new QPushButton(scrollAreaLayout);
        secondPotential->setObjectName(QStringLiteral("secondPotential"));
        sizePolicy2.setHeightForWidth(secondPotential->sizePolicy().hasHeightForWidth());
        secondPotential->setSizePolicy(sizePolicy2);
        secondPotential->setMinimumSize(QSize(30, 30));
        secondPotential->setMaximumSize(QSize(30, 30));
        secondPotential->setFlat(true);

        potentialLayout->addWidget(secondPotential, 0, 2, 1, 1);

        thirdPotential = new QPushButton(scrollAreaLayout);
        thirdPotential->setObjectName(QStringLiteral("thirdPotential"));
        sizePolicy2.setHeightForWidth(thirdPotential->sizePolicy().hasHeightForWidth());
        thirdPotential->setSizePolicy(sizePolicy2);
        thirdPotential->setMinimumSize(QSize(30, 30));
        thirdPotential->setMaximumSize(QSize(30, 30));
        thirdPotential->setFlat(true);

        potentialLayout->addWidget(thirdPotential, 0, 3, 1, 1);

        firstPotentialValueEdit = new QLineEdit(scrollAreaLayout);
        firstPotentialValueEdit->setObjectName(QStringLiteral("firstPotentialValueEdit"));
        sizePolicy2.setHeightForWidth(firstPotentialValueEdit->sizePolicy().hasHeightForWidth());
        firstPotentialValueEdit->setSizePolicy(sizePolicy2);
        firstPotentialValueEdit->setMinimumSize(QSize(30, 0));
        firstPotentialValueEdit->setMaximumSize(QSize(30, 16777215));
        firstPotentialValueEdit->setAlignment(Qt::AlignCenter);

        potentialLayout->addWidget(firstPotentialValueEdit, 1, 1, 1, 1);

        secondPotentialValueEdit = new QLineEdit(scrollAreaLayout);
        secondPotentialValueEdit->setObjectName(QStringLiteral("secondPotentialValueEdit"));
        sizePolicy2.setHeightForWidth(secondPotentialValueEdit->sizePolicy().hasHeightForWidth());
        secondPotentialValueEdit->setSizePolicy(sizePolicy2);
        secondPotentialValueEdit->setMinimumSize(QSize(30, 0));
        secondPotentialValueEdit->setMaximumSize(QSize(30, 16777215));
        secondPotentialValueEdit->setAlignment(Qt::AlignCenter);

        potentialLayout->addWidget(secondPotentialValueEdit, 1, 2, 1, 1);

        thirdPotentialValueEdit = new QLineEdit(scrollAreaLayout);
        thirdPotentialValueEdit->setObjectName(QStringLiteral("thirdPotentialValueEdit"));
        sizePolicy2.setHeightForWidth(thirdPotentialValueEdit->sizePolicy().hasHeightForWidth());
        thirdPotentialValueEdit->setSizePolicy(sizePolicy2);
        thirdPotentialValueEdit->setMinimumSize(QSize(30, 0));
        thirdPotentialValueEdit->setMaximumSize(QSize(30, 16777215));
        thirdPotentialValueEdit->setAlignment(Qt::AlignCenter);

        potentialLayout->addWidget(thirdPotentialValueEdit, 1, 3, 1, 1);

        fixedPotentialLabel = new QLabel(scrollAreaLayout);
        fixedPotentialLabel->setObjectName(QStringLiteral("fixedPotentialLabel"));
        sizePolicy.setHeightForWidth(fixedPotentialLabel->sizePolicy().hasHeightForWidth());
        fixedPotentialLabel->setSizePolicy(sizePolicy);

        potentialLayout->addWidget(fixedPotentialLabel, 0, 0, 1, 1, Qt::AlignLeft);

        potentialSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        potentialLayout->addItem(potentialSpacer, 0, 4, 1, 1);


        verticalLayout_2->addLayout(potentialLayout);

        myCharacterSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(myCharacterSpacer);

        scrollArea->setWidget(scrollAreaLayout);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(MyCharacterForm);

        QMetaObject::connectSlotsByName(MyCharacterForm);
    } // setupUi

    void retranslateUi(QWidget *MyCharacterForm)
    {
        MyCharacterForm->setWindowTitle(QApplication::translate("MyCharacterForm", "Form", nullptr));
        wantToFinishLabel->setText(QApplication::translate("MyCharacterForm", "<b>Want to finish:</b>", nullptr));
        wantToFinishLevel->setText(QApplication::translate("MyCharacterForm", "Level", nullptr));
        wantToFinishCotton->setText(QApplication::translate("MyCharacterForm", "Cotton", nullptr));
        wantToFinishSkill->setText(QApplication::translate("MyCharacterForm", "Skill", nullptr));
        wantToFinishSocket->setText(QApplication::translate("MyCharacterForm", "Sockets", nullptr));
        wantToFinishLimit->setText(QApplication::translate("MyCharacterForm", "Limit", nullptr));
        label->setText(QApplication::translate("MyCharacterForm", "<b>Current:</b>", nullptr));
        fixedLevelLabel->setText(QApplication::translate("MyCharacterForm", "Level:", nullptr));
        maxLevel->setText(QApplication::translate("MyCharacterForm", "MAX", nullptr));
        fixedSkillLevelLabel->setText(QApplication::translate("MyCharacterForm", "Skill Level:", nullptr));
        maxSkillLevel->setText(QApplication::translate("MyCharacterForm", "MAX", nullptr));
        secondDesiredSocket->setText(QString());
        fourthDesiredSocket->setText(QString());
        firstSocketEdit->setText(QApplication::translate("MyCharacterForm", "0", nullptr));
        thirdDesiredSocket->setText(QString());
        thirdSocketEdit->setText(QApplication::translate("MyCharacterForm", "0", nullptr));
        secondSocketEdit->setText(QApplication::translate("MyCharacterForm", "0", nullptr));
        fifthSocketEdit->setText(QApplication::translate("MyCharacterForm", "0", nullptr));
        fifthDesiredSocket->setText(QString());
        currentSocketsLabel->setText(QApplication::translate("MyCharacterForm", "Current Sockets:", nullptr));
        fourthSocketEdit->setText(QApplication::translate("MyCharacterForm", "0", nullptr));
        fifthCurrentSocket->setText(QString());
        firstCurrentSocket->setText(QString());
        secondCurrentSocket->setText(QString());
        firstDesiredSocket->setText(QString());
        fourthCurrentSocket->setText(QString());
        desiredSocketsLabel->setText(QApplication::translate("MyCharacterForm", "Desired Sockets:", nullptr));
        missingSocketsLabel->setText(QApplication::translate("MyCharacterForm", "Missing Sockets:", nullptr));
        firstMissingSocket->setText(QString());
        thirdCurrentSocket->setText(QString());
        secondMissingSocket->setText(QString());
        thirdMissingSocket->setText(QString());
        fourthMissingSocket->setText(QString());
        fifthMissingSocket->setText(QString());
        statsHpEdit->setText(QString());
        fixedCottonHpLabel->setText(QApplication::translate("MyCharacterForm", "HP", nullptr));
        statsRcvEdit->setText(QString());
        maxCC->setText(QApplication::translate("MyCharacterForm", "MAX", nullptr));
        statsAtkEdit->setText(QString());
        fixedCottonAtkLabel->setText(QApplication::translate("MyCharacterForm", "ATK", nullptr));
        fixedCottonLabel->setText(QApplication::translate("MyCharacterForm", "Cotton:", nullptr));
        fixedStatsLabel->setText(QApplication::translate("MyCharacterForm", "Stats:", nullptr));
        fixedCottonRcvLabel->setText(QApplication::translate("MyCharacterForm", "RCV", nullptr));
        fixedTrainingPointsLabel->setText(QApplication::translate("MyCharacterForm", "Training Points:", nullptr));
        maxTrainingPoints->setText(QApplication::translate("MyCharacterForm", "MAX", nullptr));
        fixedLbUnlockedLabel->setText(QApplication::translate("MyCharacterForm", "Unlocked Limit Break nodes:", nullptr));
        maxLbUnlocked->setText(QApplication::translate("MyCharacterForm", "MAX", nullptr));
        firstPotential->setText(QString());
        secondPotential->setText(QString());
        thirdPotential->setText(QString());
        firstPotentialValueEdit->setText(QApplication::translate("MyCharacterForm", "0", nullptr));
        secondPotentialValueEdit->setText(QApplication::translate("MyCharacterForm", "0", nullptr));
        thirdPotentialValueEdit->setText(QApplication::translate("MyCharacterForm", "0", nullptr));
        fixedPotentialLabel->setText(QApplication::translate("MyCharacterForm", "Potential abilities:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyCharacterForm: public Ui_MyCharacterForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCHARACTERFORM_H

/********************************************************************************
** Form generated from reading UI file 'details.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILS_H
#define UI_DETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Details
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *DetailsLayout;
    QTabWidget *detailsTabWidget;
    QWidget *Stats;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollStats;
    QWidget *scrollStatsAreaLayout;
    QVBoxLayout *verticalLayout_5;
    QFormLayout *idLayout;
    QLabel *idLabel;
    QFormLayout *CCESLayout;
    QLabel *costLabel;
    QLabel *socketLabel;
    QLabel *expLabel;
    QLabel *comboLabel;
    QSpacerItem *verticalSpacer;
    QGridLayout *statsLayout;
    QLabel *fixedLvlMin;
    QLabel *fixedRcvLabel;
    QLabel *fixedHpLabel;
    QLabel *fixedAtkLabel;
    QLabel *levelMaxLabel;
    QLabel *fixedLimitBreakLabel;
    QLabel *hpMinLabel;
    QLabel *hpMaxLabel;
    QLabel *atkMinLabel;
    QLabel *rcvMinLabel;
    QLabel *hpLimitBreak;
    QLabel *atkMaxLabel;
    QLabel *atkLimitBreak;
    QLabel *rcvMaxLabel;
    QLabel *rcvLimitBreak;
    QWidget *Captain;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *captainScroll;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QLabel *capAbilityLabel;
    QWidget *CaptainAction;
    QHBoxLayout *horizontalLayout_6;
    QScrollArea *captainActionScroll;
    QWidget *scrollAreaWidgetContents_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *capActionLabel;
    QWidget *Swap;
    QHBoxLayout *horizontalLayout_8;
    QScrollArea *swapScroll;
    QWidget *scrollAreaWidgetContents_6;
    QVBoxLayout *verticalLayout_8;
    QLabel *swapLabel;
    QWidget *Sailor;
    QHBoxLayout *horizontalLayout_4;
    QScrollArea *sailorScroll;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *sailorAbilityLabel;
    QWidget *Special;
    QHBoxLayout *horizontalLayout_3;
    QScrollArea *specialScroll;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *specialAbilityLabel;
    QWidget *LimitBreak;
    QHBoxLayout *horizontalLayout_5;
    QScrollArea *limitScroll;
    QWidget *scrollAreaWidgetContents_4;
    QVBoxLayout *verticalLayout_7;
    QLabel *limitLabel;
    QWidget *Evolution;
    QHBoxLayout *horizontalLayout_7;
    QScrollArea *evolutionScroll;
    QWidget *evolutionWidget;
    QGridLayout *evolutionGrid;
    QWidget *Tandem;
    QHBoxLayout *horizontalLayout_x;
    QScrollArea *tandemScroll;
    QWidget *tandemWidget;
    QGridLayout *tandemGrid;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *addCharacterButton;
    QPushButton *removeCharacterButton;
    QSpacerItem *horizontalSpacer;
    QTabWidget *myCharactersTab;
    QSpacerItem *verticalSpacer_2;
    QWidget *typeWidget;
    QHBoxLayout *TypeLayout;
    QLabel *typeLabel;
    QLabel *type2Label;
    QWidget *classWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *classeP;
    QLabel *classePDesc;
    QLabel *classeS;
    QLabel *classeSDesc;
    QWidget *formLayoutWidget;
    QFormLayout *starLayout;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *ImageNameLayout;
    QLabel *nameLabel;
    QHBoxLayout *ImageLayout;
    QPushButton *LeftButton;
    QLabel *imageLabel;
    QPushButton *RightButton;

    void setupUi(QDialog *Details)
    {
        if (Details->objectName().isEmpty())
            Details->setObjectName(QStringLiteral("Details"));
        Details->resize(320, 1010);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Details->sizePolicy().hasHeightForWidth());
        Details->setSizePolicy(sizePolicy);
        Details->setMinimumSize(QSize(320, 0));
        Details->setMaximumSize(QSize(320, 16777215));
        layoutWidget = new QWidget(Details);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 300, 321, 711));
        DetailsLayout = new QVBoxLayout(layoutWidget);
        DetailsLayout->setObjectName(QStringLiteral("DetailsLayout"));
        DetailsLayout->setContentsMargins(10, 0, 10, 0);
        detailsTabWidget = new QTabWidget(layoutWidget);
        detailsTabWidget->setObjectName(QStringLiteral("detailsTabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(detailsTabWidget->sizePolicy().hasHeightForWidth());
        detailsTabWidget->setSizePolicy(sizePolicy1);
        detailsTabWidget->setMaximumSize(QSize(16777215, 220));
        Stats = new QWidget();
        Stats->setObjectName(QStringLiteral("Stats"));
        verticalLayout_2 = new QVBoxLayout(Stats);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        scrollStats = new QScrollArea(Stats);
        scrollStats->setObjectName(QStringLiteral("scrollStats"));
        scrollStats->setWidgetResizable(true);
        scrollStatsAreaLayout = new QWidget();
        scrollStatsAreaLayout->setObjectName(QStringLiteral("scrollStatsAreaLayout"));
        scrollStatsAreaLayout->setGeometry(QRect(0, 0, 277, 162));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollStatsAreaLayout->sizePolicy().hasHeightForWidth());
        scrollStatsAreaLayout->setSizePolicy(sizePolicy2);
        verticalLayout_5 = new QVBoxLayout(scrollStatsAreaLayout);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        idLayout = new QFormLayout();
        idLayout->setObjectName(QStringLiteral("idLayout"));
        idLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        idLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        idLayout->setLabelAlignment(Qt::AlignHCenter|Qt::AlignTop);
        idLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        idLayout->setHorizontalSpacing(0);
        idLayout->setVerticalSpacing(0);
        idLabel = new QLabel(scrollStatsAreaLayout);
        idLabel->setObjectName(QStringLiteral("idLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(idLabel->sizePolicy().hasHeightForWidth());
        idLabel->setSizePolicy(sizePolicy3);
        idLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        idLayout->setWidget(0, QFormLayout::SpanningRole, idLabel);


        verticalLayout_5->addLayout(idLayout);

        CCESLayout = new QFormLayout();
        CCESLayout->setObjectName(QStringLiteral("CCESLayout"));
        CCESLayout->setSizeConstraint(QLayout::SetMaximumSize);
        CCESLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        CCESLayout->setLabelAlignment(Qt::AlignCenter);
        CCESLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        costLabel = new QLabel(scrollStatsAreaLayout);
        costLabel->setObjectName(QStringLiteral("costLabel"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(costLabel->sizePolicy().hasHeightForWidth());
        costLabel->setSizePolicy(sizePolicy4);

        CCESLayout->setWidget(0, QFormLayout::LabelRole, costLabel);

        socketLabel = new QLabel(scrollStatsAreaLayout);
        socketLabel->setObjectName(QStringLiteral("socketLabel"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(socketLabel->sizePolicy().hasHeightForWidth());
        socketLabel->setSizePolicy(sizePolicy5);
        socketLabel->setMinimumSize(QSize(1, 0));

        CCESLayout->setWidget(1, QFormLayout::LabelRole, socketLabel);

        expLabel = new QLabel(scrollStatsAreaLayout);
        expLabel->setObjectName(QStringLiteral("expLabel"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(expLabel->sizePolicy().hasHeightForWidth());
        expLabel->setSizePolicy(sizePolicy6);
        expLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        CCESLayout->setWidget(1, QFormLayout::FieldRole, expLabel);

        comboLabel = new QLabel(scrollStatsAreaLayout);
        comboLabel->setObjectName(QStringLiteral("comboLabel"));
        sizePolicy6.setHeightForWidth(comboLabel->sizePolicy().hasHeightForWidth());
        comboLabel->setSizePolicy(sizePolicy6);
        comboLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        CCESLayout->setWidget(0, QFormLayout::FieldRole, comboLabel);


        verticalLayout_5->addLayout(CCESLayout);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        statsLayout = new QGridLayout();
        statsLayout->setObjectName(QStringLiteral("statsLayout"));
        statsLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        statsLayout->setHorizontalSpacing(0);
        statsLayout->setVerticalSpacing(6);
        fixedLvlMin = new QLabel(scrollStatsAreaLayout);
        fixedLvlMin->setObjectName(QStringLiteral("fixedLvlMin"));
        fixedLvlMin->setStyleSheet(QStringLiteral("font-weight: bold"));
        fixedLvlMin->setAlignment(Qt::AlignCenter);

        statsLayout->addWidget(fixedLvlMin, 0, 1, 1, 1);

        fixedRcvLabel = new QLabel(scrollStatsAreaLayout);
        fixedRcvLabel->setObjectName(QStringLiteral("fixedRcvLabel"));
        sizePolicy4.setHeightForWidth(fixedRcvLabel->sizePolicy().hasHeightForWidth());
        fixedRcvLabel->setSizePolicy(sizePolicy4);
        fixedRcvLabel->setStyleSheet(QStringLiteral("font-weight: bold"));

        statsLayout->addWidget(fixedRcvLabel, 3, 0, 1, 1);

        fixedHpLabel = new QLabel(scrollStatsAreaLayout);
        fixedHpLabel->setObjectName(QStringLiteral("fixedHpLabel"));
        sizePolicy4.setHeightForWidth(fixedHpLabel->sizePolicy().hasHeightForWidth());
        fixedHpLabel->setSizePolicy(sizePolicy4);
        fixedHpLabel->setStyleSheet(QStringLiteral("font-weight: bold"));
        fixedHpLabel->setTextFormat(Qt::AutoText);

        statsLayout->addWidget(fixedHpLabel, 1, 0, 1, 1);

        fixedAtkLabel = new QLabel(scrollStatsAreaLayout);
        fixedAtkLabel->setObjectName(QStringLiteral("fixedAtkLabel"));
        sizePolicy4.setHeightForWidth(fixedAtkLabel->sizePolicy().hasHeightForWidth());
        fixedAtkLabel->setSizePolicy(sizePolicy4);
        fixedAtkLabel->setStyleSheet(QStringLiteral("font-weight: bold"));

        statsLayout->addWidget(fixedAtkLabel, 2, 0, 1, 1);

        levelMaxLabel = new QLabel(scrollStatsAreaLayout);
        levelMaxLabel->setObjectName(QStringLiteral("levelMaxLabel"));
        levelMaxLabel->setStyleSheet(QStringLiteral("font-weight: bold"));
        levelMaxLabel->setAlignment(Qt::AlignCenter);

        statsLayout->addWidget(levelMaxLabel, 0, 2, 1, 1);

        fixedLimitBreakLabel = new QLabel(scrollStatsAreaLayout);
        fixedLimitBreakLabel->setObjectName(QStringLiteral("fixedLimitBreakLabel"));
        fixedLimitBreakLabel->setStyleSheet(QStringLiteral("font-weight: bold"));
        fixedLimitBreakLabel->setAlignment(Qt::AlignCenter);

        statsLayout->addWidget(fixedLimitBreakLabel, 0, 3, 1, 1);

        hpMinLabel = new QLabel(scrollStatsAreaLayout);
        hpMinLabel->setObjectName(QStringLiteral("hpMinLabel"));
        hpMinLabel->setAlignment(Qt::AlignCenter);

        statsLayout->addWidget(hpMinLabel, 1, 1, 1, 1);

        hpMaxLabel = new QLabel(scrollStatsAreaLayout);
        hpMaxLabel->setObjectName(QStringLiteral("hpMaxLabel"));
        hpMaxLabel->setAlignment(Qt::AlignCenter);

        statsLayout->addWidget(hpMaxLabel, 1, 2, 1, 1);

        atkMinLabel = new QLabel(scrollStatsAreaLayout);
        atkMinLabel->setObjectName(QStringLiteral("atkMinLabel"));
        atkMinLabel->setAlignment(Qt::AlignCenter);

        statsLayout->addWidget(atkMinLabel, 2, 1, 1, 1);

        rcvMinLabel = new QLabel(scrollStatsAreaLayout);
        rcvMinLabel->setObjectName(QStringLiteral("rcvMinLabel"));
        rcvMinLabel->setAlignment(Qt::AlignCenter);

        statsLayout->addWidget(rcvMinLabel, 3, 1, 1, 1);

        hpLimitBreak = new QLabel(scrollStatsAreaLayout);
        hpLimitBreak->setObjectName(QStringLiteral("hpLimitBreak"));
        hpLimitBreak->setAlignment(Qt::AlignCenter);

        statsLayout->addWidget(hpLimitBreak, 1, 3, 1, 1);

        atkMaxLabel = new QLabel(scrollStatsAreaLayout);
        atkMaxLabel->setObjectName(QStringLiteral("atkMaxLabel"));
        atkMaxLabel->setAlignment(Qt::AlignCenter);

        statsLayout->addWidget(atkMaxLabel, 2, 2, 1, 1);

        atkLimitBreak = new QLabel(scrollStatsAreaLayout);
        atkLimitBreak->setObjectName(QStringLiteral("atkLimitBreak"));
        atkLimitBreak->setAlignment(Qt::AlignCenter);

        statsLayout->addWidget(atkLimitBreak, 2, 3, 1, 1);

        rcvMaxLabel = new QLabel(scrollStatsAreaLayout);
        rcvMaxLabel->setObjectName(QStringLiteral("rcvMaxLabel"));
        rcvMaxLabel->setAlignment(Qt::AlignCenter);

        statsLayout->addWidget(rcvMaxLabel, 3, 2, 1, 1);

        rcvLimitBreak = new QLabel(scrollStatsAreaLayout);
        rcvLimitBreak->setObjectName(QStringLiteral("rcvLimitBreak"));
        rcvLimitBreak->setAlignment(Qt::AlignCenter);

        statsLayout->addWidget(rcvLimitBreak, 3, 3, 1, 1);


        verticalLayout_5->addLayout(statsLayout);

        scrollStats->setWidget(scrollStatsAreaLayout);

        verticalLayout_2->addWidget(scrollStats);

        detailsTabWidget->addTab(Stats, QString());
        Captain = new QWidget();
        Captain->setObjectName(QStringLiteral("Captain"));
        horizontalLayout_2 = new QHBoxLayout(Captain);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        captainScroll = new QScrollArea(Captain);
        captainScroll->setObjectName(QStringLiteral("captainScroll"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(captainScroll->sizePolicy().hasHeightForWidth());
        captainScroll->setSizePolicy(sizePolicy7);
        captainScroll->setFrameShadow(QFrame::Sunken);
        captainScroll->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 277, 162));
        QSizePolicy sizePolicy8(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy8);
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        capAbilityLabel = new QLabel(scrollAreaWidgetContents);
        capAbilityLabel->setObjectName(QStringLiteral("capAbilityLabel"));
        QSizePolicy sizePolicy9(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(capAbilityLabel->sizePolicy().hasHeightForWidth());
        capAbilityLabel->setSizePolicy(sizePolicy9);
        capAbilityLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        capAbilityLabel->setWordWrap(true);
        capAbilityLabel->setMargin(5);

        verticalLayout->addWidget(capAbilityLabel);

        captainScroll->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(captainScroll);

        detailsTabWidget->addTab(Captain, QString());
        CaptainAction = new QWidget();
        CaptainAction->setObjectName(QStringLiteral("CaptainAction"));
        horizontalLayout_6 = new QHBoxLayout(CaptainAction);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        captainActionScroll = new QScrollArea(CaptainAction);
        captainActionScroll->setObjectName(QStringLiteral("captainActionScroll"));
        sizePolicy7.setHeightForWidth(captainActionScroll->sizePolicy().hasHeightForWidth());
        captainActionScroll->setSizePolicy(sizePolicy7);
        captainActionScroll->setFrameShadow(QFrame::Sunken);
        captainActionScroll->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QStringLiteral("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 277, 162));
        sizePolicy8.setHeightForWidth(scrollAreaWidgetContents_5->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_5->setSizePolicy(sizePolicy8);
        verticalLayout_6 = new QVBoxLayout(scrollAreaWidgetContents_5);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        capActionLabel = new QLabel(scrollAreaWidgetContents_5);
        capActionLabel->setObjectName(QStringLiteral("capActionLabel"));
        sizePolicy9.setHeightForWidth(capActionLabel->sizePolicy().hasHeightForWidth());
        capActionLabel->setSizePolicy(sizePolicy9);
        capActionLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        capActionLabel->setWordWrap(true);
        capActionLabel->setMargin(5);

        verticalLayout_6->addWidget(capActionLabel);

        captainActionScroll->setWidget(scrollAreaWidgetContents_5);

        horizontalLayout_6->addWidget(captainActionScroll);

        detailsTabWidget->addTab(CaptainAction, QString());
        Swap = new QWidget();
        Swap->setObjectName(QStringLiteral("Swap"));
        horizontalLayout_8 = new QHBoxLayout(Swap);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        swapScroll = new QScrollArea(Swap);
        swapScroll->setObjectName(QStringLiteral("swapScroll"));
        sizePolicy7.setHeightForWidth(swapScroll->sizePolicy().hasHeightForWidth());
        swapScroll->setSizePolicy(sizePolicy7);
        swapScroll->setMinimumSize(QSize(1, 0));
        swapScroll->setFrameShadow(QFrame::Sunken);
        swapScroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        swapScroll->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        swapScroll->setWidgetResizable(true);
        scrollAreaWidgetContents_6 = new QWidget();
        scrollAreaWidgetContents_6->setObjectName(QStringLiteral("scrollAreaWidgetContents_6"));
        scrollAreaWidgetContents_6->setGeometry(QRect(0, 0, 277, 162));
        sizePolicy8.setHeightForWidth(scrollAreaWidgetContents_6->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_6->setSizePolicy(sizePolicy8);
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents_6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        swapLabel = new QLabel(scrollAreaWidgetContents_6);
        swapLabel->setObjectName(QStringLiteral("swapLabel"));
        sizePolicy9.setHeightForWidth(swapLabel->sizePolicy().hasHeightForWidth());
        swapLabel->setSizePolicy(sizePolicy9);
        swapLabel->setScaledContents(false);
        swapLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        swapLabel->setWordWrap(true);
        swapLabel->setMargin(5);

        verticalLayout_8->addWidget(swapLabel);

        swapScroll->setWidget(scrollAreaWidgetContents_6);

        horizontalLayout_8->addWidget(swapScroll);

        detailsTabWidget->addTab(Swap, QString());
        Sailor = new QWidget();
        Sailor->setObjectName(QStringLiteral("Sailor"));
        horizontalLayout_4 = new QHBoxLayout(Sailor);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        sailorScroll = new QScrollArea(Sailor);
        sailorScroll->setObjectName(QStringLiteral("sailorScroll"));
        sizePolicy7.setHeightForWidth(sailorScroll->sizePolicy().hasHeightForWidth());
        sailorScroll->setSizePolicy(sizePolicy7);
        sailorScroll->setFrameShadow(QFrame::Sunken);
        sailorScroll->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 277, 162));
        sizePolicy8.setHeightForWidth(scrollAreaWidgetContents_2->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_2->setSizePolicy(sizePolicy8);
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        sailorAbilityLabel = new QLabel(scrollAreaWidgetContents_2);
        sailorAbilityLabel->setObjectName(QStringLiteral("sailorAbilityLabel"));
        sizePolicy9.setHeightForWidth(sailorAbilityLabel->sizePolicy().hasHeightForWidth());
        sailorAbilityLabel->setSizePolicy(sizePolicy9);
        sailorAbilityLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        sailorAbilityLabel->setWordWrap(true);
        sailorAbilityLabel->setMargin(5);

        verticalLayout_3->addWidget(sailorAbilityLabel);

        sailorScroll->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_4->addWidget(sailorScroll);

        detailsTabWidget->addTab(Sailor, QString());
        Special = new QWidget();
        Special->setObjectName(QStringLiteral("Special"));
        horizontalLayout_3 = new QHBoxLayout(Special);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        specialScroll = new QScrollArea(Special);
        specialScroll->setObjectName(QStringLiteral("specialScroll"));
        sizePolicy7.setHeightForWidth(specialScroll->sizePolicy().hasHeightForWidth());
        specialScroll->setSizePolicy(sizePolicy7);
        specialScroll->setMinimumSize(QSize(1, 0));
        specialScroll->setFrameShadow(QFrame::Sunken);
        specialScroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        specialScroll->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        specialScroll->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 277, 162));
        sizePolicy8.setHeightForWidth(scrollAreaWidgetContents_3->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_3->setSizePolicy(sizePolicy8);
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        specialAbilityLabel = new QLabel(scrollAreaWidgetContents_3);
        specialAbilityLabel->setObjectName(QStringLiteral("specialAbilityLabel"));
        sizePolicy9.setHeightForWidth(specialAbilityLabel->sizePolicy().hasHeightForWidth());
        specialAbilityLabel->setSizePolicy(sizePolicy9);
        specialAbilityLabel->setScaledContents(false);
        specialAbilityLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        specialAbilityLabel->setWordWrap(true);
        specialAbilityLabel->setMargin(5);

        verticalLayout_4->addWidget(specialAbilityLabel);

        specialScroll->setWidget(scrollAreaWidgetContents_3);

        horizontalLayout_3->addWidget(specialScroll);

        detailsTabWidget->addTab(Special, QString());
        LimitBreak = new QWidget();
        LimitBreak->setObjectName(QStringLiteral("LimitBreak"));
        horizontalLayout_5 = new QHBoxLayout(LimitBreak);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        limitScroll = new QScrollArea(LimitBreak);
        limitScroll->setObjectName(QStringLiteral("limitScroll"));
        sizePolicy9.setHeightForWidth(limitScroll->sizePolicy().hasHeightForWidth());
        limitScroll->setSizePolicy(sizePolicy9);
        limitScroll->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QStringLiteral("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 277, 162));
        verticalLayout_7 = new QVBoxLayout(scrollAreaWidgetContents_4);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        limitLabel = new QLabel(scrollAreaWidgetContents_4);
        limitLabel->setObjectName(QStringLiteral("limitLabel"));
        sizePolicy9.setHeightForWidth(limitLabel->sizePolicy().hasHeightForWidth());
        limitLabel->setSizePolicy(sizePolicy9);
        limitLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        limitLabel->setWordWrap(true);
        limitLabel->setMargin(5);

        verticalLayout_7->addWidget(limitLabel);

        limitScroll->setWidget(scrollAreaWidgetContents_4);

        horizontalLayout_5->addWidget(limitScroll);

        detailsTabWidget->addTab(LimitBreak, QString());
        Evolution = new QWidget();
        Evolution->setObjectName(QStringLiteral("Evolution"));
        QSizePolicy sizePolicy10(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(Evolution->sizePolicy().hasHeightForWidth());
        Evolution->setSizePolicy(sizePolicy10);
        Evolution->setMinimumSize(QSize(1, 1));
        horizontalLayout_7 = new QHBoxLayout(Evolution);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setSizeConstraint(QLayout::SetNoConstraint);
        evolutionScroll = new QScrollArea(Evolution);
        evolutionScroll->setObjectName(QStringLiteral("evolutionScroll"));
        evolutionScroll->setWidgetResizable(true);
        evolutionWidget = new QWidget();
        evolutionWidget->setObjectName(QStringLiteral("evolutionWidget"));
        evolutionWidget->setGeometry(QRect(0, 0, 277, 162));
        evolutionGrid = new QGridLayout(evolutionWidget);
        evolutionGrid->setObjectName(QStringLiteral("evolutionGrid"));
        evolutionScroll->setWidget(evolutionWidget);

        horizontalLayout_7->addWidget(evolutionScroll);

        detailsTabWidget->addTab(Evolution, QString());
        Tandem = new QWidget();
        Tandem->setObjectName(QStringLiteral("Tandem"));
        sizePolicy10.setHeightForWidth(Tandem->sizePolicy().hasHeightForWidth());
        Tandem->setSizePolicy(sizePolicy10);
        Tandem->setMinimumSize(QSize(1, 1));
        horizontalLayout_x = new QHBoxLayout(Tandem);
        horizontalLayout_x->setObjectName(QStringLiteral("horizontalLayout_x"));
        horizontalLayout_x->setSizeConstraint(QLayout::SetNoConstraint);
        tandemScroll = new QScrollArea(Tandem);
        tandemScroll->setObjectName(QStringLiteral("tandemScroll"));
        tandemScroll->setWidgetResizable(true);
        tandemWidget = new QWidget();
        tandemWidget->setObjectName(QStringLiteral("tandemWidget"));
        tandemWidget->setGeometry(QRect(0, 0, 277, 162));
        tandemGrid = new QGridLayout(tandemWidget);
        tandemGrid->setObjectName(QStringLiteral("tandemGrid"));
        tandemScroll->setWidget(tandemWidget);

        horizontalLayout_x->addWidget(tandemScroll);

        detailsTabWidget->addTab(Tandem, QString());

        DetailsLayout->addWidget(detailsTabWidget);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        addCharacterButton = new QPushButton(layoutWidget);
        addCharacterButton->setObjectName(QStringLiteral("addCharacterButton"));
        QSizePolicy sizePolicy11(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(addCharacterButton->sizePolicy().hasHeightForWidth());
        addCharacterButton->setSizePolicy(sizePolicy11);
        addCharacterButton->setMinimumSize(QSize(20, 20));
        addCharacterButton->setMaximumSize(QSize(20, 20));
        addCharacterButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 10px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #ffffff, stop: 1 #bbb\n"
"        );\n"
"	font: 12pt;\n"
"	Text-align: bottom;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #fff\n"
"        );\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"    background: qradialgradient(\n"
"        cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n"
"        );\n"
"    }"));

        horizontalLayout_9->addWidget(addCharacterButton);

        removeCharacterButton = new QPushButton(layoutWidget);
        removeCharacterButton->setObjectName(QStringLiteral("removeCharacterButton"));
        sizePolicy11.setHeightForWidth(removeCharacterButton->sizePolicy().hasHeightForWidth());
        removeCharacterButton->setSizePolicy(sizePolicy11);
        removeCharacterButton->setMinimumSize(QSize(20, 20));
        removeCharacterButton->setMaximumSize(QSize(20, 20));
        removeCharacterButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 10px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #ffffff, stop: 1 #bbb\n"
"        );\n"
"	font: 12pt;\n"
"	Text-align: bottom;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #fff\n"
"        );\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"    background: qradialgradient(\n"
"        cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n"
"        );\n"
"    }"));

        horizontalLayout_9->addWidget(removeCharacterButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);


        DetailsLayout->addLayout(horizontalLayout_9);

        myCharactersTab = new QTabWidget(layoutWidget);
        myCharactersTab->setObjectName(QStringLiteral("myCharactersTab"));
        QSizePolicy sizePolicy12(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy12.setHorizontalStretch(0);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(myCharactersTab->sizePolicy().hasHeightForWidth());
        myCharactersTab->setSizePolicy(sizePolicy12);
        myCharactersTab->setMinimumSize(QSize(0, 460));
        myCharactersTab->setLayoutDirection(Qt::LeftToRight);

        DetailsLayout->addWidget(myCharactersTab);

        verticalSpacer_2 = new QSpacerItem(10, 0, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        DetailsLayout->addItem(verticalSpacer_2);

        typeWidget = new QWidget(Details);
        typeWidget->setObjectName(QStringLiteral("typeWidget"));
        typeWidget->setGeometry(QRect(20, 265, 65, 30));
        TypeLayout = new QHBoxLayout(typeWidget);
        TypeLayout->setObjectName(QStringLiteral("TypeLayout"));
        TypeLayout->setContentsMargins(0, 0, 0, 0);
        typeLabel = new QLabel(typeWidget);
        typeLabel->setObjectName(QStringLiteral("typeLabel"));

        TypeLayout->addWidget(typeLabel);

        type2Label = new QLabel(typeWidget);
        type2Label->setObjectName(QStringLiteral("type2Label"));

        TypeLayout->addWidget(type2Label);

        classWidget = new QWidget(Details);
        classWidget->setObjectName(QStringLiteral("classWidget"));
        classWidget->setGeometry(QRect(110, 265, 181, 30));
        QSizePolicy sizePolicy13(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy13.setHorizontalStretch(0);
        sizePolicy13.setVerticalStretch(0);
        sizePolicy13.setHeightForWidth(classWidget->sizePolicy().hasHeightForWidth());
        classWidget->setSizePolicy(sizePolicy13);
        horizontalLayout = new QHBoxLayout(classWidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        classeP = new QLabel(classWidget);
        classeP->setObjectName(QStringLiteral("classeP"));
        QSizePolicy sizePolicy14(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy14.setHorizontalStretch(0);
        sizePolicy14.setVerticalStretch(0);
        sizePolicy14.setHeightForWidth(classeP->sizePolicy().hasHeightForWidth());
        classeP->setSizePolicy(sizePolicy14);

        horizontalLayout->addWidget(classeP);

        classePDesc = new QLabel(classWidget);
        classePDesc->setObjectName(QStringLiteral("classePDesc"));

        horizontalLayout->addWidget(classePDesc);

        classeS = new QLabel(classWidget);
        classeS->setObjectName(QStringLiteral("classeS"));
        sizePolicy14.setHeightForWidth(classeS->sizePolicy().hasHeightForWidth());
        classeS->setSizePolicy(sizePolicy14);

        horizontalLayout->addWidget(classeS);

        classeSDesc = new QLabel(classWidget);
        classeSDesc->setObjectName(QStringLiteral("classeSDesc"));

        horizontalLayout->addWidget(classeSDesc);

        formLayoutWidget = new QWidget(Details);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 230, 321, 31));
        starLayout = new QFormLayout(formLayoutWidget);
        starLayout->setObjectName(QStringLiteral("starLayout"));
        starLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget = new QWidget(Details);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 321, 231));
        ImageNameLayout = new QVBoxLayout(verticalLayoutWidget);
        ImageNameLayout->setObjectName(QStringLiteral("ImageNameLayout"));
        ImageNameLayout->setSizeConstraint(QLayout::SetNoConstraint);
        ImageNameLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(verticalLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        QSizePolicy sizePolicy15(QSizePolicy::Ignored, QSizePolicy::Minimum);
        sizePolicy15.setHorizontalStretch(0);
        sizePolicy15.setVerticalStretch(0);
        sizePolicy15.setHeightForWidth(nameLabel->sizePolicy().hasHeightForWidth());
        nameLabel->setSizePolicy(sizePolicy15);
        nameLabel->setMinimumSize(QSize(1, 1));
        nameLabel->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        nameLabel->setFont(font);
        nameLabel->setLayoutDirection(Qt::LeftToRight);
        nameLabel->setAlignment(Qt::AlignCenter);
        nameLabel->setWordWrap(true);

        ImageNameLayout->addWidget(nameLabel);

        ImageLayout = new QHBoxLayout();
        ImageLayout->setObjectName(QStringLiteral("ImageLayout"));
        LeftButton = new QPushButton(verticalLayoutWidget);
        LeftButton->setObjectName(QStringLiteral("LeftButton"));
        sizePolicy10.setHeightForWidth(LeftButton->sizePolicy().hasHeightForWidth());
        LeftButton->setSizePolicy(sizePolicy10);
        LeftButton->setMinimumSize(QSize(1, 1));
        LeftButton->setMaximumSize(QSize(20, 20));
        LeftButton->setStyleSheet(QLatin1String("Text-align:center\n"
""));
        LeftButton->setCheckable(false);
        LeftButton->setFlat(false);

        ImageLayout->addWidget(LeftButton);

        imageLabel = new QLabel(verticalLayoutWidget);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        sizePolicy6.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy6);
        imageLabel->setFrameShape(QFrame::NoFrame);
        imageLabel->setLineWidth(0);
        imageLabel->setAlignment(Qt::AlignCenter);

        ImageLayout->addWidget(imageLabel);

        RightButton = new QPushButton(verticalLayoutWidget);
        RightButton->setObjectName(QStringLiteral("RightButton"));
        sizePolicy10.setHeightForWidth(RightButton->sizePolicy().hasHeightForWidth());
        RightButton->setSizePolicy(sizePolicy10);
        RightButton->setMinimumSize(QSize(1, 1));
        RightButton->setMaximumSize(QSize(20, 20));
        RightButton->setFlat(false);

        ImageLayout->addWidget(RightButton);


        ImageNameLayout->addLayout(ImageLayout);

        classWidget->raise();
        typeWidget->raise();
        layoutWidget->raise();
        formLayoutWidget->raise();
        verticalLayoutWidget->raise();

        retranslateUi(Details);

        detailsTabWidget->setCurrentIndex(0);
        myCharactersTab->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Details);
    } // setupUi

    void retranslateUi(QDialog *Details)
    {
        Details->setWindowTitle(QApplication::translate("Details", "Dialog", nullptr));
        idLabel->setText(QApplication::translate("Details", "Id", nullptr));
        costLabel->setText(QApplication::translate("Details", "Cost", nullptr));
        socketLabel->setText(QApplication::translate("Details", "Socket", nullptr));
        expLabel->setText(QApplication::translate("Details", "Exp", nullptr));
        comboLabel->setText(QApplication::translate("Details", "Combo", nullptr));
        fixedLvlMin->setText(QApplication::translate("Details", "Lv.1", nullptr));
        fixedRcvLabel->setText(QApplication::translate("Details", "RCV", nullptr));
        fixedHpLabel->setText(QApplication::translate("Details", "HP", nullptr));
        fixedAtkLabel->setText(QApplication::translate("Details", "ATK", nullptr));
        levelMaxLabel->setText(QApplication::translate("Details", "TextLabel", nullptr));
        fixedLimitBreakLabel->setText(QApplication::translate("Details", "Limit Break", nullptr));
        hpMinLabel->setText(QApplication::translate("Details", "hpmin", nullptr));
        hpMaxLabel->setText(QApplication::translate("Details", "hpmax", nullptr));
        atkMinLabel->setText(QApplication::translate("Details", "atkmin", nullptr));
        rcvMinLabel->setText(QApplication::translate("Details", "rcvmin", nullptr));
        hpLimitBreak->setText(QApplication::translate("Details", "hplimitbreak", nullptr));
        atkMaxLabel->setText(QApplication::translate("Details", "atkmax", nullptr));
        atkLimitBreak->setText(QApplication::translate("Details", "atklimitbreak", nullptr));
        rcvMaxLabel->setText(QApplication::translate("Details", "rcvmax", nullptr));
        rcvLimitBreak->setText(QApplication::translate("Details", "rcvlimitbreak", nullptr));
        detailsTabWidget->setTabText(detailsTabWidget->indexOf(Stats), QApplication::translate("Details", "Stats", nullptr));
        capAbilityLabel->setText(QApplication::translate("Details", "Cap ability", nullptr));
        detailsTabWidget->setTabText(detailsTabWidget->indexOf(Captain), QApplication::translate("Details", "Captain", nullptr));
        capActionLabel->setText(QApplication::translate("Details", "Cap ability", nullptr));
        detailsTabWidget->setTabText(detailsTabWidget->indexOf(CaptainAction), QApplication::translate("Details", "Captain action", nullptr));
        swapLabel->setText(QApplication::translate("Details", "Swap", nullptr));
        detailsTabWidget->setTabText(detailsTabWidget->indexOf(Swap), QApplication::translate("Details", "Swap", nullptr));
        sailorAbilityLabel->setText(QApplication::translate("Details", "Sailor ability", nullptr));
        detailsTabWidget->setTabText(detailsTabWidget->indexOf(Sailor), QApplication::translate("Details", "Sailor", nullptr));
        specialAbilityLabel->setText(QApplication::translate("Details", "Spec ability", nullptr));
        detailsTabWidget->setTabText(detailsTabWidget->indexOf(Special), QApplication::translate("Details", "Special", nullptr));
        limitLabel->setText(QApplication::translate("Details", "TextLabel", nullptr));
        detailsTabWidget->setTabText(detailsTabWidget->indexOf(LimitBreak), QApplication::translate("Details", "Limit", nullptr));
        detailsTabWidget->setTabText(detailsTabWidget->indexOf(Evolution), QApplication::translate("Details", "Evolution", nullptr));
        detailsTabWidget->setTabText(detailsTabWidget->indexOf(Tandem), QApplication::translate("Details", "Tandem", nullptr));
        addCharacterButton->setText(QApplication::translate("Details", "+", nullptr));
        removeCharacterButton->setText(QApplication::translate("Details", "-", nullptr));
        typeLabel->setText(QApplication::translate("Details", "TipoVero", nullptr));
        type2Label->setText(QApplication::translate("Details", "TipoVero", nullptr));
        classeP->setText(QApplication::translate("Details", "P", nullptr));
        classePDesc->setText(QApplication::translate("Details", "PDesc", nullptr));
        classeS->setText(QApplication::translate("Details", "S", nullptr));
        classeSDesc->setText(QApplication::translate("Details", "SDesc", nullptr));
        nameLabel->setText(QApplication::translate("Details", "NameVero", nullptr));
        LeftButton->setText(QApplication::translate("Details", "<", nullptr));
        imageLabel->setText(QApplication::translate("Details", "Immagine", nullptr));
        RightButton->setText(QApplication::translate("Details", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Details: public Ui_Details {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILS_H

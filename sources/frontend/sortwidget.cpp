#include"sortwidget.h"
#include"ui_sortwidget.h"

SortWidget::SortWidget(Utility* _utility, QWidget *_parent) :
    QMainWindow(_parent),
    ui(new Ui::SortWidget),
    utility(_utility),
    primaryCondition("Id"),
    primaryAscendingOrder(true),
    primaryIncludeLimit(false),
    secondaryCondition(""),
    secondaryAscendingOrder(true),
    secondaryIncludeLimit(false)
{
    ui->setupUi(this);

    ui->primaryPriority->setArrowType(Qt::ArrowType::UpArrow);
    ui->secondaryPriority->setArrowType(Qt::ArrowType::UpArrow);

    possibleConditions.push_back("Id");
    possibleConditions.push_back("Rarity");
    possibleConditions.push_back("Type");
    possibleConditions.push_back("Family");
    possibleConditions.push_back("Cost");
    possibleConditions.push_back("Primary Class");
    possibleConditions.push_back("Secondary Class");
    possibleConditions.push_back("HP");
    possibleConditions.push_back("ATK");
    possibleConditions.push_back("RCV");
    possibleConditions.push_back("Combo");
    possibleConditions.push_back("Slots");
    possibleConditions.push_back("Cooldown");

    for (QString& condition : possibleConditions)
    {
        ui->primaryComboBox->addItem(condition);
    }
}

SortWidget::~SortWidget()
{
    delete ui;
}

void SortWidget::on_primaryPriority_clicked()
{
    if (primaryAscendingOrder)
    {
        primaryAscendingOrder = false;
        ui->primaryPriority->setArrowType(Qt::ArrowType::DownArrow);
    }
    else
    {
        primaryAscendingOrder = true;
        ui->primaryPriority->setArrowType(Qt::ArrowType::UpArrow);
    }
}

void SortWidget::on_secondaryPriority_clicked()
{
    if (secondaryAscendingOrder)
    {
        secondaryAscendingOrder = false;
        ui->secondaryPriority->setArrowType(Qt::ArrowType::DownArrow);
    }
    else
    {
        secondaryAscendingOrder = true;
        ui->secondaryPriority->setArrowType(Qt::ArrowType::UpArrow);
    }
}

void SortWidget::on_primaryComboBox_currentIndexChanged(const QString &_text)
{
    primaryCondition = _text.toUtf8().constData();

    // Hide or show other things
    if (_text == "Id")
    {
        ui->primaryIncludeLimit->hide();

        ui->secondaryCriteriaLabel->hide();
        ui->secondaryComboBox->hide();
        ui->secondaryIncludeLimit->hide();
        ui->secondaryPriority->hide();
    }
    else
    {
        ui->primaryIncludeLimit->hide();

        ui->secondaryCriteriaLabel->show();
        ui->secondaryComboBox->show();
        ui->secondaryIncludeLimit->show();
        ui->secondaryPriority->show();

        ui->secondaryComboBox->clear();
        for (QString& condition : possibleConditions)
        {
            if (condition != _text)
            {
                ui->secondaryComboBox->addItem(condition);
            }
        }
    }

    if (_text == "HP" || _text == "ATK" || _text == "RCV" || _text == "Slots" || _text == "Cooldown")
    {
        ui->primaryIncludeLimit->show();
    }
}

void SortWidget::on_secondaryComboBox_currentIndexChanged(const QString &_text)
{
    secondaryCondition = _text.toUtf8().constData();

     if (_text == "HP" || _text == "ATK" || _text == "RCV" || _text == "Slots" || _text == "Cooldown")
     {
         ui->secondaryIncludeLimit->show();
     }
     else
     {
         ui->secondaryIncludeLimit->hide();
     }
}

void SortWidget::on_okButton_clicked()
{
    utility->primarySortCondition = primaryCondition;
    utility->primarySortAscendingOrder = primaryAscendingOrder;
    utility->primarySortIncludeLimit = primaryIncludeLimit;

    utility->secondarySortCondition = secondaryCondition;
    utility->secondarySortAscendingOrder = secondaryAscendingOrder;
    utility->secondarySortIncludeLimit = secondaryIncludeLimit;

    emit sort();
    hide();
}

void SortWidget::on_cancelButton_clicked()
{
    hide();
}

void SortWidget::on_primaryIncludeLimit_stateChanged(int _state)
{
    if (_state > 0)
    {
        primaryIncludeLimit = true;
    }
    else
    {
        primaryIncludeLimit = false;
    }
}

void SortWidget::on_secondaryIncludeLimit_stateChanged(int _state)
{
    if (_state > 0)
    {
        secondaryIncludeLimit = true;
    }
    else
    {
        secondaryIncludeLimit = false;
    }
}

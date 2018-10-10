#include "database.h"
#include "ui_database.h"
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <QMessageBox>
#include <QApplication>
#include <QScreen>
#include <QFileInfo>
#include <parser.h>
#include <characterItem.h>

Database::Database(Utility* _utility, QWidget* _parent) :
    QMainWindow(_parent),
    ui(new Ui::Database),
    utility(_utility)
{
    ui->setupUi(this);
    filter = new Filter(_utility);
    advancedFilters = new AdvancedFilters(utility, this);
    sortWidget = new SortWidget(utility, this);
    connect(sortWidget, SIGNAL(sort()), this, SLOT(sort()));
    characters = *_utility->characters;
    myCharacters = _utility->myCharacters;

    ui->characterList->setViewMode(QListWidget::IconMode);
    ui->characterList->setIconSize(QSize(60, 60));
    ui->characterList->setResizeMode(QListWidget::Adjust);

    /* Load characters to list */
    for (Character* ch : characters)
    {
        if (ch->getId() >= 3020)
        {
            break;
        }

        if (ch->getName() == "")
        {
            continue;
        }

        QIcon coloredIcon(*ch->getColoredIcon());

        CharacterItem* characterItem = new CharacterItem(ch, utility);
        characterItem->setIcon(coloredIcon);
        characterItem->setText(QString::number(ch->getId()));
        ui->characterList->addItem(characterItem);

        allIds.insert(ch->getId());
    }
}

Database::~Database()
{
    delete ui;
}

void Database::setIdCondition(QString _text)
{
    Condition::Operator currentOperator;
    if (_text != "")
    {
        Condition condition("filterById", Condition::Target::Id, Condition::Operator::NumOperators, _text.toUtf8().constData());
        currentOperator = condition.getOperatorFromDescription(ui->idOperator->currentText().toUtf8().constData());

        bool alreadyIn = false;
        for (Condition& cond : filter->andConditions)
        {
            if (cond.getId() == "filterById")
            {
                alreadyIn = true;
                cond.setOperator(currentOperator);
                cond.setValue(_text.toUtf8().constData());
            }
        }

        if (!alreadyIn)
        {
            condition.setOperator(currentOperator);
            filter->addAndCondition(condition);
        }
    }
    else
    {
        for (std::vector<Condition>::iterator it = filter->andConditions.begin(); it != filter->andConditions.end();)
        {
            if (it->getId() == "filterById")
            {
                it = filter->andConditions.erase(it);
            }
            else
            {
                it++;
            }
        }
    }
}

void Database::on_filterById_textChanged(const QString& _text)
{
    QRegExp re("\\d*");  // a digit (\d), zero or more times (*)
    if (re.exactMatch(_text))
    {
        setIdCondition(_text);
    }
    else
    {
        ui->filterById->setText("");
    }
    redraw();
}

void Database::on_filterByName_textChanged(const QString& _text)
{
    std::string toSearch = _text.toUtf8().constData();
    std::transform(toSearch.begin(), toSearch.end(), toSearch.begin(), ::tolower);
    bool alreadyIn = false;
    for (Condition& cond : filter->andConditions)
    {
        if (cond.getId() == "filterByName")
        {
            alreadyIn = true;
            cond.setValue(toSearch);
        }
    }

    if (!alreadyIn)
    {
        Condition condition("filterByName", Condition::Target::Name, Condition::Operator::Equal, toSearch);
        filter->addAndCondition(condition);
    }
    redraw();
}

void Database::openCloseDetails(short _id)
{
    if (!open)
    {
        /* Create vertical line */
        QWidget *verticalLineWidget = new QWidget;
        verticalLineWidget->setFixedWidth(2);
        verticalLineWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        verticalLineWidget->setStyleSheet(QString("background-color: #c0c0c0;"));
        ui->gridLayout->addWidget(verticalLineWidget, 0, 1, 2, 1);

        /**/
        Details* charMenu = new Details(utility, _id, this);
        connect(this, SIGNAL(changeEditModeDb()), charMenu, SLOT(editModeChangedDb()));
        QScrollArea *scrollArea = new QScrollArea();
        scrollArea->setWidget(charMenu);
        scrollArea->setFixedWidth(charMenu->width() + 20);
        detailMenu = charMenu;
        ui->gridLayout->addWidget(scrollArea, 0, 2, 2, 1);

        /* Full screen handling */
        QScreen *screen = QGuiApplication::primaryScreen();
        int newWidth = size().width() + charMenu->width();
        newWidth = this->parentWidget()->windowState() == Qt::WindowMaximized ? screen->geometry().width() : newWidth;
        resize(newWidth, size().height());

        open = true;
        openId = _id;
    }
    else
    {
        if (openId != _id)
        {
            Tools::removeColumn(ui->gridLayout, 2, true);
            Details* charMenu = new Details(utility, _id, this);
            connect(this, SIGNAL(changeEditModeDb()), charMenu, SLOT(editModeChangedDb()));
            QScrollArea *scrollArea = new QScrollArea();
            scrollArea->setWidget(charMenu);
            scrollArea->setFixedWidth(charMenu->width() + 20);
            ui->gridLayout->addWidget(scrollArea, 0, 2, 2, 1);
            detailMenu = charMenu;
            openId = _id;
        }
        else
        {
            open = false;

            QScreen *screen = QGuiApplication::primaryScreen();
            int newWidth = size().width() - detailMenu->width();
            newWidth = this->parentWidget()->windowState() == Qt::WindowMaximized ? screen->geometry().width() : newWidth;
            resize(newWidth, size().height());
            Tools::removeColumn(ui->gridLayout, 1, true);
            Tools::removeColumn(ui->gridLayout, 2, true);
        }
    }
}

void Database::on_characterList_itemClicked(QListWidgetItem* _item)
{
    CharacterItem* characterItem = static_cast<CharacterItem*>(_item);
    openCloseDetails(characterItem->character->getId());
}

void Database::changeDetails(int _characterId)
{
    ui->characterList->item(_characterId - 1)->setSelected(true);
    openCloseDetails(static_cast<short>(_characterId));
}

void Database::redraw()
{
    int characterListSize = ui->characterList->count();

    std::set<int> filteredCharacters = filter->filter(allIds);
    for (int i = 0; i < characterListSize; ++i)
    {
        CharacterItem* characterItem = static_cast<CharacterItem*>(ui->characterList->item(i));
        short id = characterItem->character->getId();

        if (filteredCharacters.find(id) != filteredCharacters.end())
        {
            if (ui->showOwned->isChecked())
            {
                // Hide not owned
                if (myCharacters->find(id) != myCharacters->end())
                {
                    ui->characterList->item(i)->setHidden(false);
                }
                else
                {
                    ui->characterList->item(i)->setHidden(true);
                }
            }
            else
            {
                ui->characterList->item(i)->setHidden(false);
            }

            if (ui->ownedMode->isChecked())
            {
                // Gray out not owned
                if (myCharacters->find(id) != myCharacters->end())
                {
                    QIcon coloredIcon(*characterItem->character->getColoredIcon());
                    characterItem->setIcon(coloredIcon);
                }
                else
                {
                    QIcon grayIcon(*characterItem->character->getGrayIcon());
                    characterItem->setIcon(grayIcon);
                }
            }
            else
            {
                QIcon coloredIcon(*characterItem->character->getColoredIcon());
                characterItem->setIcon(coloredIcon);
            }
        }
        else
        {
            ui->characterList->item(i)->setHidden(true);
        }
    }
}

void Database::saveCharacters()
{
    Tools::saveOwnedCharacters(characters, *myCharacters, utility->id);
}

void Database::on_ownedMode_clicked()
{
    redraw();
}

void Database::on_showOwned_clicked()
{
    redraw();
}

void Database::on_editMode_stateChanged(int _state)
{
    if (_state > 0)
    {
        utility->editMode = true;
    }
    else
    {
        utility->editMode = false;
    }
    emit changeEditModeDb();
}

void Database::on_idOperator_currentIndexChanged(int index)
{
    assert(index > -1);     // Only to remove the unused warning
    setIdCondition(ui->filterById->text());
    redraw();
}

void Database::on_advancedFilters_clicked()
{
    advancedFilters->show();
}

void Database::change_advancedFilters_color(bool _active)
{
    if (_active)
    {
        ui->advancedFilters->setStyleSheet("background-color: rgb(255, 204, 0);");
    }
    else
    {
        ui->advancedFilters->setStyleSheet("");
    }
}

void Database::advancedFilters_set(Filter _filter)
{
    filter->orConditions.clear();
    filter->addOrCondition(_filter);
    redraw();
}

void Database::advancedFilters_reset()
{
    filter->orConditions.clear();
    redraw();
}

void Database::on_sortButton_clicked()
{
    sortWidget->show();
}

void Database::sort()
{
    ui->characterList->sortItems(Qt::AscendingOrder);
}

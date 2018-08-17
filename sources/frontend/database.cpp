#include "database.h"
#include "ui_Database.h"
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <QMessageBox>
#include <QApplication>
#include <QScreen>
#include <QFileInfo>


Database::Database(Utility* _utility, QWidget* _parent) :
    QMainWindow(_parent),
    ui(new Ui::Database),
    utility(_utility)
{
    ui->setupUi(this);
    characters = *_utility->characters;
    myCharacters = *_utility->myCharacters;

    ui->characterList->setViewMode(QListWidget::IconMode);
    ui->characterList->setIconSize(QSize(60, 60));
    ui->characterList->setResizeMode(QListWidget::Adjust);

    /* Load characters to list */
    for (Character* ch : characters)
    {
        if (ch->getName() == "")
        {
            continue;
        }
        if (ch->getId() >= 3000)
        {
            break;
        }

        QIcon coloredIcon(*ch->getColoredIcon());
        QIcon grayIcon(*ch->getGrayIcon());
        coloredIcons.push_back(coloredIcon);
        grayIcons.push_back(grayIcon);

        ui->characterList->addItem(new QListWidgetItem(coloredIcon, QString::number(ch->getId())));
    }
//    utility->myCharacters = &myCharacters;
}

Database::~Database()
{
    delete ui;
}

void Database::on_filterByName_textChanged(const QString& _text)
{
    int characterListSize = ui->characterList->count();

    for (int i = 0; i < characterListSize; ++i)
    {
        if (ui->characterList->item(i)->text().contains(_text))
        {
            ui->characterList->item(i)->setHidden(false);
        }
        else
        {
            ui->characterList->item(i)->setHidden(true);
        }
    }
    std::string toSearch = _text.toUtf8().constData();
    std::transform(toSearch.begin(), toSearch.end(), toSearch.begin(), ::tolower);

    for (Character* ch : characters)
    {
        if (ch->getId() == 201)
        {
            break;
        }
        std::string name = ch->getName();
        std::transform(name.begin(), name.end(), name.begin(), ::tolower);
        if (name.find(toSearch) != std::string::npos)
        {
            ui->characterList->item(ch->getId() - 1)->setHidden(false);
        }
        else
        {
            ui->characterList->item(ch->getId() - 1)->setHidden(true);
        }
    }
}

void Database::on_ownedMode_toggled(bool _checked)
{
    if (_checked)
    {
        int characterListSize = ui->characterList->count();

        std::cout << myCharacters.size() << std::endl;
        for (int i = 0; i < characterListSize; ++i)
        {
//            if (characters.at(i).owned)
//            {
//                ui->characterList->item(i)->setIcon(coloredIcons.at(i));
//            }
//            else
//            {
//                ui->characterList->item(i)->setIcon(grayIcons.at(i));
//            }
        }
    }
    else
    {
        int characterListSize = ui->characterList->count();

        for (int i = 0; i < characterListSize; ++i)
        {
            ui->characterList->item(i)->setIcon(coloredIcons.at(i));
        }

    }
}

void Database::on_showOwned_toggled(bool _checked)
{
    int characterListSize = ui->characterList->count();

    for (int i = 0; i < characterListSize; ++i)
    {
        if (_checked)
        {
            int id = i + 1;
            if (myCharacters.find(id) != myCharacters.end())
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
    }
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
            Tools::removeColumn(ui->gridLayout, 1, true);
            Tools::removeColumn(ui->gridLayout, 2, true);

            QScreen *screen = QGuiApplication::primaryScreen();
            int newWidth = size().width() - detailMenu->width();
            newWidth = this->parentWidget()->windowState() == Qt::WindowMaximized ? screen->geometry().width() : newWidth;
            resize(newWidth, size().height());
        }
    }
}

void Database::on_characterList_itemClicked(QListWidgetItem* _item)
{
    openCloseDetails(_item->text().toShort());
}

void Database::changeDetails(int _characterId)
{
    ui->characterList->item(_characterId - 1)->setSelected(true);
    openCloseDetails(_characterId);
}

void Database::redraw()
{
    if (ui->showOwned->isChecked())
    {
        int characterListSize = ui->characterList->count();

        for (int i = 0; i < characterListSize; ++i)
        {
//            if (characters.at(i).owned)
//            {
//                ui->characterList->item(i)->setIcon(coloredIcons.at(i));
//            }
//            else
//            {
//                ui->characterList->item(i)->setIcon(grayIcons.at(i));
//            }
        }
    }
}

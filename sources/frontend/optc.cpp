#include <optc.h>
#include <ui_optc.h>
#include <database.h>
#include <parser.h>
#include <json.h>
#include <filter.h>
#include <about.h>

Optc::Optc(QWidget *_parent) :
    QMainWindow(_parent),
    ui(new Ui::Optc)
{
    ui->setupUi(this);
    aboutWindow = new About(this);
    donateWindow = new Donate(this);
}

Optc::~Optc()
{
    delete ui;
}

void Optc::loadCharacters(long _id)
{
    utility.id = static_cast<unsigned long>(_id);
    ui->idLabel->setText("Currently displaying id: <b>" + QString::number(_id) + "</b>");
    std::string working_path = QDir::currentPath().toUtf8().constData();
    character_parser = new Parser(working_path  + "/resources/details/");
    character_parser->load();
    characters = character_parser->getCharacters();
    materials = character_parser->getMaterials();
    familiesMap = character_parser->getFamiliesMap();
    utility.characters = &characters;
    utility.materials = &materials;
    utility.familiesMap = &familiesMap;
    myCharacters = Tools::loadOwnedCharacters(characters, utility.id);
    utility.myCharacters = &myCharacters;

//    std::cout << *characters[2168] << std::endl;
//    std::cout << *characters[2170] << std::endl;
//    std::cout << *characters[2172] << std::endl;
//    std::cout << *characters[2174] << std::endl;
//    std::cout << *characters[2160] << std::endl;

    for(std::map<std::string, Material*>::iterator it = materials.begin(); it != materials.end(); ++it)
    {
        QString materialIconPath = ":/ui/" + QString::fromStdString(materials[it->first]->getName()) + ".png";
        QPixmap* iconPixmap;

        // Load icon
        if(QFileInfo::exists(materialIconPath) && QFileInfo(materialIconPath).isFile())
        {
            iconPixmap = new QPixmap(materialIconPath);
        }
        else
        {
            iconPixmap = new QPixmap(":/ui/skullLuffy.png");
        }

        int portraitSize = 60;
        *iconPixmap = iconPixmap->scaled(portraitSize, portraitSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QIcon coloredIcon(*iconPixmap);

        /* Make gray icon*/
        int w = coloredIcon.availableSizes()[0].width();
        int h = coloredIcon.availableSizes()[0].height();
        QImage image = coloredIcon.pixmap(w, h).toImage();
        image = image.convertToFormat(QImage::Format_Grayscale8);
        QPixmap grayPix = QPixmap::fromImage(image);

        /* Add images to material*/
        materials[it->first]->setColoredIcon(iconPixmap);
        materials[it->first]->setGrayIcon(grayPix);
    }

    QString workingPath = QDir::currentPath().toUtf8().constData();
    for (Character* ch : characters)
    {
        if (ch->getName() == "")
        {
            continue;
        }
        std::ostringstream ss;
        ss << std::setw(4) << std::setfill('0') << ch->getId();
        QString characterId(ss.str().c_str());

        QString characterIconPath = workingPath + "/resources/icons/f" + characterId + ".png";
        QPixmap* iconPixmap;

        // Load icon
        if(QFileInfo::exists(characterIconPath) && QFileInfo(characterIconPath).isFile())
        {
            iconPixmap = new QPixmap(characterIconPath);
        }
        else
        {
            Type ch_type = ch->getType().empty()? Type::StartType : ch->getType()[0];
            QString type(QString::fromStdString(to_string(ch_type)));
            iconPixmap = new QPixmap(workingPath + "/resources/icons/blank_" + type.toLower() + ".png");
        }

        int portraitSize = 60;
        *iconPixmap = iconPixmap->scaled(portraitSize, portraitSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QIcon coloredIcon(*iconPixmap);

        /* Make gray icon*/
        int w = coloredIcon.availableSizes()[0].width();
        int h = coloredIcon.availableSizes()[0].height();
        QImage image = coloredIcon.pixmap(w, h).toImage();
        image = image.convertToFormat(QImage::Format_Grayscale8);
        QPixmap grayPix = QPixmap::fromImage(image);

        /* Add images to character*/
        ch->setColoredIcon(iconPixmap);
        ch->setGrayIcon(grayPix);
    }

    Database* data = new Database(&utility, this);
    ui->tabWidget->addTab(data, "Database");
    connect(this, SIGNAL(save()), data, SLOT(saveCharacters()));
    connect(data, SIGNAL(request_detail(bool, short)), this, SLOT(detail_request(bool, short)));
}

void Optc::logout()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void Optc::detail_request(bool _toOpen, short _id)
{
    if (_toOpen)
    {
        ui->dockWidget->show();
        ui->dockWidget->setTitleBarWidget(nullptr);
        Details* charMenu = new Details(&utility, _id, this);
        Database* database = static_cast<Database*>(ui->tabWidget->widget(0));

        // Add signals
        connect(database, SIGNAL(changeEditModeDb()), charMenu, SLOT(editModeChangedDb()));
        connect(charMenu, SIGNAL(changeCharacterDetail(int)), database, SLOT(changeDetails(int)));
        connect(charMenu, SIGNAL(changedOwnedState()), database, SLOT(redraw()));

        // Put details inside scrollarea and then into dockwidget
        QScrollArea* scrollDetails = new QScrollArea(this);
        scrollDetails->setWidget(charMenu);
        ui->dockWidget->setWidget(scrollDetails);
    }
    else
    {
        ui->dockWidget->setWidget(nullptr);
    }
}

void Optc::on_actionLogout_triggered()
{
    bool autoLogin;
    std::string lastLogin;
    std::map<std::string, std::string> userPwd;
    std::string loginPath = std::string(QDir::currentPath().toUtf8().constData()) + "/resources/data/login.json";
    std::ifstream inputStream(loginPath);
    if (inputStream.is_open())
    {
        json inputFile;
        inputStream >> inputFile;

        if (inputFile.find("RegisteredUsers") != inputFile.end())
        {
            json registeredUsers = inputFile["RegisteredUsers"];
            for (json::iterator fileIterator = registeredUsers.begin(); fileIterator != registeredUsers.end(); ++fileIterator)
            {
                std::string username = fileIterator.key();
                std::string pwd = registeredUsers[fileIterator.key()];
                userPwd[username] = pwd;
            }
        }

        if (inputFile.find("LastLogin") != inputFile.end())
        {
            lastLogin = inputFile["LastLogin"];
        }

        if (inputFile.find("AutoLogin") != inputFile.end())
        {
            autoLogin = inputFile["AutoLogin"];
        }
    }
    inputStream.close();

    // Remove autologin
    autoLogin = false;

    std::ofstream outputFile(loginPath);
    if (outputFile.is_open())
    {
        json settingsJson;

        settingsJson["LastLogin"] = lastLogin;
        settingsJson["AutoLogin"] = autoLogin;

        json registeredJson;
        for (std::map<std::string, std::string>::iterator it = userPwd.begin(); it != userPwd.end(); ++it)
        {
            registeredJson[it->first] = userPwd[it->first];
        }
        settingsJson["RegisteredUsers"] = registeredJson;
        outputFile << std::setw(4) << settingsJson << std::endl;
    }
    outputFile.close();
    logout();
}

void Optc::on_actionAbout_Optc_Toolbox_triggered()
{
    aboutWindow->show();
}

void Optc::on_actionSave_triggered()
{
    emit save();
}

void Optc::on_actionBuy_me_a_coffee_triggered()
{
    donateWindow->show();
}

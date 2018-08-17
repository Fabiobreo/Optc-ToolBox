#include <optc.h>
#include <ui_optc.h>
#include <database.h>
#include <parser.h>

Optc::Optc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Optc)
{
    ui->setupUi(this);
    loadCharacters();
//    std::cout << *characters.at(2012) << std::endl;
//    std::cout << characters.at(1975) << std::endl;
    Database* data = new Database(&utility, this);
    ui->tabWidget->addTab(data, "Database");
}

Optc::~Optc()
{
    delete ui;
}

void Optc::loadCharacters()
{
    std::string working_path = QDir::currentPath().toUtf8().constData();
    character_parser = new Parser(working_path  + "/resources/details/");
    character_parser->load();
    characters = character_parser->getCharacters();
    utility.characters = &characters;
    myCharacters = character_parser->getOwnedCharacters(541443375);
    utility.myCharacters = &myCharacters;

    for (Character* ch : characters)
    {
        if (ch->getName() == "")
        {
            continue;
        }
        std::ostringstream ss;
        ss << std::setw(4) << std::setfill('0') << ch->getId();
        QString characterId(ss.str().c_str());

        QString workingPath = QDir::currentPath().toUtf8().constData();
        QString characterIconPath = workingPath + "/resources/icons/f" + characterId + ".png";
        QPixmap* iconPixmap;

        // Load icon
        if(QFileInfo::exists(characterIconPath) && QFileInfo(characterIconPath).isFile())
        {
            iconPixmap = new QPixmap(characterIconPath);
        }
        else
        {
            Type ch_type = ch->getType().empty()? Type::None : ch->getType().at(0);
            QString type(QString::fromStdString(to_string(ch_type)));
            iconPixmap = new QPixmap(workingPath + "/resources/icons/blank_" + type.toLower() + ".png");
        }

        int portraitSize = 60;
        *iconPixmap = iconPixmap->scaled(portraitSize, portraitSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QIcon coloredIcon(*iconPixmap);

        /* Make gray icon*/
        int w = coloredIcon.availableSizes().at(0).width();
        int h = coloredIcon.availableSizes().at(0).height();
        QImage image = coloredIcon.pixmap(w, h).toImage();
        image = image.convertToFormat(QImage::Format_Grayscale8);
        QPixmap grayPix = QPixmap::fromImage(image);

        /* Add images to character*/
        ch->setColoredIcon(iconPixmap);
        ch->setGrayIcon(&grayPix);
    }

}

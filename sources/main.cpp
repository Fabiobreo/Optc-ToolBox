#include "database.h"
#include "optc.h"
#include <QApplication>
#include <parser.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Optc w;
    w.show();
    return a.exec();
    //    std::string working_path = QDir::currentPath().toUtf8().constData();
    //    Parser character_parser(working_path  + "/resources/details/");
    //    if (!character_parser.load())
    //    {
    //        return 1;
    //    }
    //    int id = 1360;
    //    std::cout << character_parser.getCharacters()->at(id - 1) << std::endl;
    //    id = 1970;
    //    std::cout << character_parser.getCharacters()->at(id - 1) << std::endl;

    //    return 0;
}

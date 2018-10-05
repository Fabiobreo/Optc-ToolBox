#include "database.h"
#include "optc.h"
#include <QApplication>
#include <parser.h>
#include <loginform.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Optc* window = new Optc();
    LoginForm loginDialog(window);
//    loginDialog->setUsername( "Luca" ); // optional
//    connect( loginDialog,
//     SIGNAL (acceptLogin(QString&,QString&,int&)),
//     this,
//     SLOT (slotAcceptUserLogin(QString&,QString&)));
    loginDialog.show();
    //Optc w;
    //w.show();
    return a.exec();
}

#include <QApplication>
#include "mainwindow.h"
#include "gamewindow.h"
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    GameWindow gw;
    Dialog dlg;
    w.show();

    QObject::connect(&w, SIGNAL(quit()), &a, SLOT(quit()));
    QObject::connect(&w, SIGNAL(gwshow()), &gw, SLOT(show()));
    QObject::connect(&w, SIGNAL(gwshow()), &gw, SIGNAL(gameStart()));

    QObject::connect(&gw, SIGNAL(gameEnd(int)), &dlg, SLOT(gameEnd(int)));
    QObject::connect(&gw, SIGNAL(quit()), &a, SLOT(quit()));

    QObject::connect(&dlg, SIGNAL(retry()), &gw, SIGNAL(gameStart()));
    QObject::connect(&dlg, SIGNAL(quit()), &a, SLOT(quit()));
    return a.exec();
}

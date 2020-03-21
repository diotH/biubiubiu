#include <QApplication>
#include "game/gameBackground.h"

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);

    CGameBackground game;
    game.show();

    return app.exec();
}

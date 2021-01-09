#include "server.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    server *dominoKingdomsServer = new server();
    dominoKingdomsServer->startServer();
    return a.exec();
}

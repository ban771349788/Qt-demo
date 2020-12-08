#include "tcpwidget.h"
#include "socketform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TcpWidget w;
    w.show();

    SocketForm w2;
    w2.show();

    SocketForm w3;
    w3.show();

    return a.exec();
}

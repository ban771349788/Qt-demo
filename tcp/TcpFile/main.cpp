#include "tcpserverfile.h"
#include <QApplication>
#include "tcpsocketform.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TcpServerFile w;
    w.show();

    tcpSocketForm w2;
    w2.show();

    return a.exec();
}

#include "tcpserve_widget.h"
#include "tcpclient_widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TcpServe_Widget w;
    w.show();

    TcpClient_Widget c1;
    c1.show();

    TcpClient_Widget c2;
    c2.show();

    TcpClient_Widget c3;
    c3.show();

    TcpClient_Widget c4;
    c4.show();

    return a.exec();
}

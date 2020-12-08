#ifndef TCPCLIENT_WIDGET_H
#define TCPCLIENT_WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTcpSocket>

namespace Ui {
class TcpClient_Widget;
}

class TcpClient_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit TcpClient_Widget(QWidget *parent = nullptr);
    ~TcpClient_Widget();

protected slots:
    void onButtonEnter_clicked(bool checked);
    void onButtonSend_clicked(bool checked);

    void slotconnectedsuccess();
    void slotdisconnected();
    void slotreceive();

private:
    Ui::TcpClient_Widget *ui;
    bool status;
    int port;
    QString serverIP;
    QString userName;
    QTcpSocket *tcpsocket;

};

#endif // TCPCLIENT_WIDGET_H

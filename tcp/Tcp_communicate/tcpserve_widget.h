#ifndef TCPSERVE_WIDGET_H
#define TCPSERVE_WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

QT_BEGIN_NAMESPACE

class CommCate_Socket : public QTcpSocket
{
    Q_OBJECT

public:
    CommCate_Socket(QObject *parent = 0)
        :QTcpSocket(parent)
    {
        connect(this, &QTcpSocket::readyRead, this, &CommCate_Socket::receiveData);
        connect(this, &QTcpSocket::disconnected, this, &CommCate_Socket::slotClientDisconnected);
    }

protected slots:
    void receiveData()
    {
        QByteArray arry = this->readAll();
        QString msg = arry;

        emit updataServe(msg, arry.size());
    }

    void slotClientDisconnected()
    {
        emit clientDisconnected(this->socketDescriptor());
    }

signals:
    void updataServe(QString msg, int len);
    void clientDisconnected(int descriptor);
};

typedef  struct CLIENT_INFO{
    CommCate_Socket *socket;
    QString IP;
    int Port;
}client_info;
typedef  QList< client_info > clien_list;

class TcpServe : public QTcpServer
{
    Q_OBJECT

public:
    TcpServe(QObject *parent = nullptr, int port = 0)
        :QTcpServer(parent)
    {
        listen(QHostAddress::Any, port);
    }

protected:
    void incomingConnection(qintptr socketDescriptor)
    {
        CommCate_Socket *comm_socket = new CommCate_Socket(this);
        comm_socket->setSocketDescriptor(socketDescriptor);

        client_info info;
        info.socket = comm_socket;
        info.IP     = comm_socket->peerAddress().toString();
        info.Port   = comm_socket->peerPort();
        clientList.append(info);

        connect(comm_socket, &CommCate_Socket::updataServe, this, &TcpServe::slotUpdateServer);
        connect(comm_socket, &CommCate_Socket::clientDisconnected, this, &TcpServe::slotClientDisconnect);

        emit updateClientList(clientList);
    }

protected slots:
    void slotUpdateServer(QString msg, int len)
    {
        emit updateServer(msg, len);

        for(int i = 0; i < clientList.count(); i++)
        {
            QTcpSocket * client = clientList.at(i).socket;
            client->write(msg.toUtf8().data(), len);
        }
    }

    void slotClientDisconnect(int descriptor)
    {
        for(int i =0; i < clientList.count(); i++)
        {
            QTcpSocket * client = clientList.at(i).socket;
            if(client->socketDescriptor() == descriptor)
            {
                clientList.removeAt(i);
            }
        }

        emit updateClientList(clientList);
    }

signals:
    void updateServer(QString msg, int descriptor);
    void updateClientList(clien_list list);

public:
     clien_list clientList;

};


namespace Ui{
class TcpServe_Widget;
}
QT_END_NAMESPACE

class TcpServe_Widget : public QWidget
{
    Q_OBJECT

public:
    TcpServe_Widget(QWidget *parent = nullptr);
    ~TcpServe_Widget();

private:
    Ui::TcpServe_Widget *ui;
    TcpServe    *server;
    int   m_port;

protected slots:
    void slotUpateServer(QString msg, int len);
    void slotUpateClientList(clien_list list);
    void onButtonClicked(bool clicked);
};

#endif // TCPSERVE_WIDGET_H

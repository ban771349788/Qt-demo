#include "tcpclient_widget.h"
#include "ui_tcpclient_widget.h"
#include <QHostAddress>

TcpClient_Widget::TcpClient_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpClient_Widget)
{
    ui->setupUi(this);

    status = false;
    tcpsocket = new QTcpSocket(this);
    connect(tcpsocket,  &QTcpSocket::connected, this, &TcpClient_Widget::slotconnectedsuccess);
    connect(tcpsocket,  &QTcpSocket::disconnected, this, &TcpClient_Widget::slotdisconnected);
    connect(tcpsocket,  &QTcpSocket::readyRead, this, &TcpClient_Widget::slotreceive);

    ui->msg_btn->setEnabled(false);
    connect(ui->msg_btn, &QPushButton::clicked, this, &TcpClient_Widget::onButtonSend_clicked);
    connect(ui->enter_btn, &QPushButton::clicked, this, &TcpClient_Widget::onButtonEnter_clicked);
}

TcpClient_Widget::~TcpClient_Widget()
{
    delete ui;
}

void TcpClient_Widget::onButtonEnter_clicked(bool checked)
{
    Q_UNUSED(checked);

     port       = ui->port_lineEdit->text().toInt();
     serverIP   = ui->server_ip->text();
     userName   = ui->username_lineEdit->text();

    if(!status){
        QHostAddress addr;
        QString ip = ui->server_ip->text();
        if(!addr.setAddress(ip) && ip.isEmpty())
            return;

        serverIP = ip;
        if(ui->username_lineEdit->text().isEmpty() || ui->port_lineEdit->text().isEmpty())
            return;
        userName = ui->username_lineEdit->text();
        port     = ui->port_lineEdit->text().toUInt();

        status = true;
        tcpsocket->connectToHost(serverIP, port);
    } else {
        status = false;
        QString msg = userName + " :Leave Chat Room";
        tcpsocket->write(msg.toUtf8().data());
        tcpsocket->disconnectFromHost();
    }
}

void TcpClient_Widget::onButtonSend_clicked(bool checked)
{
    Q_UNUSED(checked);

    if(ui->msg_lineEdit->text().isEmpty())
        return;

    QString msg = userName + ":" +ui->msg_lineEdit->text();
    tcpsocket->write(msg.toUtf8().data());
    ui->msg_lineEdit->clear();
}

void TcpClient_Widget::slotconnectedsuccess()
{
    ui->msg_btn->setEnabled(true);
    ui->enter_btn->setText("离开聊天室");

    QString msg= userName + " :Enter Chat Room";
    tcpsocket->write(msg.toUtf8().data());
}

void TcpClient_Widget::slotreceive()
{
    QByteArray arry = tcpsocket->readAll();
    ui->textEdit->append(arry);
}

void TcpClient_Widget::slotdisconnected()
{
    ui->msg_btn->setEnabled(false);
    ui->enter_btn->setText("进入聊天室");
}

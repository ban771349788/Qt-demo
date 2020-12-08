#include "socketform.h"
#include "ui_socketform.h"
#include <QString>

SocketForm::SocketForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SocketForm)
{
    ui->setupUi(this);

    ui->ReadMsg->setReadOnly(true);

    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(doReadyRead()));
}

SocketForm::~SocketForm()
{
    delete ui;
}

void SocketForm::on_btnconnect_clicked()
{
    QString ip   = ui->ServerIP->text();
    int     port = ui->port->text().toInt();

    tcpSocket->connectToHost(ip, port);
}

void SocketForm::doReadyRead(void)
{
    QString msg = tcpSocket->readAll();

    if(!msg.isEmpty())
    {
        ui->ReadMsg->append(msg.toUtf8());
    }
}

void SocketForm::on_btnSend_clicked()
{
    QString msg = ui->SendMsg->toPlainText();

    if(!msg.isEmpty())
    {
        tcpSocket->write(msg.toUtf8().data());
    }
    ui->SendMsg->clear();
}

void SocketForm::on_btnDisconnect_clicked()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}




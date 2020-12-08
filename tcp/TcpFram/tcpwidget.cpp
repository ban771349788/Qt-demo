#include "tcpwidget.h"
#include "ui_tcpwidget.h"
#include <QString>
#include <QDebug>
TcpWidget::TcpWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpWidget)
{
    ui->setupUi(this);

    ui->ReadMsg->setReadOnly(true);
    ui->btnSend->setText("发送");
    ui->btnDisconnect->setText("断开连接");

    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::AnyIPv4, 8888);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(doConnection()));
}

TcpWidget::~TcpWidget()
{
    delete ui;
}

void TcpWidget::doConnection(void)
{
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(doReadyRead()));

    QString ip    = tcpSocket->peerAddress().toString();
    quint16 port  = tcpSocket->peerPort();

    QString str = QString("[%1:%2]连接成功").arg(ip).arg(port);
    ui->ReadMsg->append(str);

}

void TcpWidget::doReadyRead(void)
{
    QString str = tcpSocket->readAll();

    if(!str.isEmpty())
    {
        ui->ReadMsg->append(str.toUtf8());
    }
}

void TcpWidget::on_btnSend_clicked()
{
    QString msg = ui->SendMsg->toPlainText();
    if(!msg.isEmpty())
    {
        tcpSocket->write(msg.toUtf8().data());
    }
    ui->SendMsg->clear();
}

void TcpWidget::on_btnDisconnect_clicked()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}

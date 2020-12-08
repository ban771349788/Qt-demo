#include "tcpsocketform.h"
#include "ui_tcpsocketform.h"
#include <QMessageBox>
tcpSocketForm::tcpSocketForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tcpSocketForm)
{
    ui->setupUi(this);

    isStart = true;
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(doReadyRead()));
}

tcpSocketForm::~tcpSocketForm()
{
    delete ui;
}

void tcpSocketForm::doReadyRead(void)
{
    QByteArray buf =  tcpSocket->readAll();

    if(isStart == true)
    {
        isStart  = false;
        fileName = QString(buf).section("##", 0, 0);
        fileSize = QString(buf).section("##", 1, 1).toInt();
        recvSize = 0;

        file.setFileName(fileName);
        bool isOk = file.open(QIODevice::WriteOnly);

        if(isOk == false)
        {
            qDebug()<< "open error";
        }
    }
    else
    {
        //read buf data to file
       qint64 len = file.write(buf);
       recvSize += len;
       if(recvSize == fileSize)
       {
           file.close();

           QMessageBox::information(this, "完成", "文件接收完成");
           tcpSocket->close();

       }
    }

}

void tcpSocketForm::on_btnConnect_clicked()
{
    QString ip   = ui->serverIp->text();
    qint16  port = ui->port->text().toInt();

    tcpSocket->connectToHost(ip, port);
}


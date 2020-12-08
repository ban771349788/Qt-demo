#include "tcpserverfile.h"
#include "ui_tcpserverfile.h"
#include <QFileDialog>
TcpServerFile::TcpServerFile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpServerFile)
{
    ui->setupUi(this);

    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::AnyIPv4, 8888);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(doConnection()));

    ui->btnChoseFile->setEnabled(false);
    ui->btnSend->setEnabled(false);
    connect(&timer, &QTimer::timeout, this, [=]()
    {
        timer.stop();
        sendData();
    }
    );
}

TcpServerFile::~TcpServerFile()
{
    delete ui;
}

void TcpServerFile::doConnection(void)
{
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(doReadyRead()));

    QString ip    = tcpSocket->peerAddress().toString();
    quint16 port  = tcpSocket->peerPort();

    QString str = QString("[%1:%2]连接成功").arg(ip).arg(port);
    ui->ReadMsg->append(str);

    ui->btnChoseFile->setEnabled(true);
    ui->btnSend->setEnabled(true);
}

void TcpServerFile::doReadyRead(void)
{
    QString msg = tcpSocket->readAll();

    if(!msg.isEmpty())
    {
        ui->ReadMsg->append(msg);
    }
}

void TcpServerFile::on_btnChoseFile_clicked()
{
    QString openfileName = QFileDialog::getOpenFileName(this, "Open File","../");

    if(openfileName.isEmpty() == false)
    {
        fileName.clear();
        fileSize = 0;

        QFileInfo fileInfo(openfileName);

        fileName  = fileInfo.fileName();
        fileSize  = fileInfo.size();
        SendSize  = 0;

        file.setFileName(openfileName);

        bool isOk =  file.open(QIODevice::ReadOnly);
        if(isOk == false)
        {
            ui->ReadMsg->append("open file error 70");
        }

        ui->ReadMsg->append(openfileName);
        ui->btnSend->setEnabled(true);
        ui->btnChoseFile->setEnabled(false);
    }
    else
    {
        qDebug()<<"filepath error 80";
    }
}

void TcpServerFile::on_btnSend_clicked()
{
    QString head  = QString("%1##%2").arg(fileName).arg(fileSize);
    quint64 len   = tcpSocket->write(head.toUtf8());

    if(len > 0)
    {
        timer.start(20);
    }
    else
    {
        qDebug()<<"send faile";
        file.close();
        ui->btnChoseFile->setEnabled(true);
        ui->btnSend->setEnabled(false);
    }
}

void TcpServerFile::sendData(void)
{
    quint64 len = 0;
    do{
        char buff[4*1024] = {0};
        len  = 0;

        len = file.read(buff, sizeof(buff));
        len = tcpSocket->write(buff, len);

        SendSize += len;
    }while(len >0); //有数据时就发送

    qDebug()<<__LINE__ << SendSize <<fileSize;
    if(SendSize == fileSize)
    {
        ui->ReadMsg->append("send success");
        file.close();
    }
}
















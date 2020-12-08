#ifndef TCPSERVERFILE_H
#define TCPSERVERFILE_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QString>
#include <QTimer>
namespace Ui {
class TcpServerFile;
}

class TcpServerFile : public QWidget
{
    Q_OBJECT

public:
    explicit TcpServerFile(QWidget *parent = 0);
    ~TcpServerFile();
    void sendData(void);

public slots:
    void doConnection(void);
    void doReadyRead(void);

private slots:
    void on_btnChoseFile_clicked();

    void on_btnSend_clicked();

private:
    Ui::TcpServerFile *ui;
    QTcpServer  *tcpServer;
    QTcpSocket  *tcpSocket;

    QFile       file;
    QString     fileName;
    qint64      fileSize;
    qint64      SendSize;
    QTimer      timer;

};

#endif // TCPSERVERFILE_H

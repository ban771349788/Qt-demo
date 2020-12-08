#ifndef TCPSOCKETFORM_H
#define TCPSOCKETFORM_H

#include <QWidget>
#include <QTcpSocket>
#include <QFile>
namespace Ui {
class tcpSocketForm;
}

class tcpSocketForm : public QWidget
{
    Q_OBJECT

public:
    explicit tcpSocketForm(QWidget *parent = 0);
    ~tcpSocketForm();

public slots:
    void doReadyRead(void);

private slots:
    void on_btnConnect_clicked();


private:
    Ui::tcpSocketForm *ui;
    QTcpSocket        *tcpSocket;

    QFile       file;
    QString     fileName;
    qint64      fileSize;
    qint64      recvSize;
    bool        isStart;

};

#endif // TCPSOCKETFORM_H

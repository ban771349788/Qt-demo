#ifndef TCPWIDGET_H
#define TCPWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class TcpWidget;
}

class TcpWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TcpWidget(QWidget *parent = 0);
    ~TcpWidget();
public slots:
    void doConnection(void);
    void doReadyRead(void);

private slots:
    void on_btnSend_clicked();
    void on_btnDisconnect_clicked();

private:
    Ui::TcpWidget *ui;
    QTcpServer  *tcpServer;
    QTcpSocket  *tcpSocket;
};

#endif // TCPWIDGET_H

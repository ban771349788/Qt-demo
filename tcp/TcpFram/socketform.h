#ifndef SOCKETFORM_H
#define SOCKETFORM_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class SocketForm;
}

class SocketForm : public QWidget
{
    Q_OBJECT

public:
    explicit SocketForm(QWidget *parent = 0);
    ~SocketForm();
public slots:
    void doReadyRead(void);

private slots:
    void on_btnconnect_clicked();

    void on_btnSend_clicked();

    void on_btnDisconnect_clicked();

private:
    Ui::SocketForm *ui;
    QTcpSocket     *tcpSocket;
};

#endif // SOCKETFORM_H

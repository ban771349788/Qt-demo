#include "tcpserve_widget.h"
#include "ui_tcpserve_widget.h"
#include <QListWidgetItem>

TcpServe_Widget::TcpServe_Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpServe_Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &TcpServe_Widget::onButtonClicked);
}

TcpServe_Widget::~TcpServe_Widget()
{
    delete ui;
}

void TcpServe_Widget::slotUpateServer(QString msg, int /*len*/)
{
    ui->textEdit->append(msg);
}

void TcpServe_Widget::onButtonClicked(bool clicked)
{
    Q_UNUSED(clicked);
    m_port = ui->lineEdit->text().toInt();

    server = new TcpServe(this, m_port);
    connect(server, &TcpServe::updateServer, this, &TcpServe_Widget::slotUpateServer);
    connect(server, &TcpServe::updateClientList, this, &TcpServe_Widget::slotUpateClientList);

    ui->pushButton->setEnabled(false);
}

void TcpServe_Widget::slotUpateClientList(clien_list list)
{
    ui->listWidget->clear();

    for (int i = 0; i < list.count(); i++) {
        QString msg = QString("%1 %2 %3").arg(list.at(i).socket->socketDescriptor()).arg(list.at(i).IP).arg(list.at(i).Port);
        QListWidgetItem *item = new QListWidgetItem(msg);
        ui->listWidget->insertItem(i, item);
    }
}

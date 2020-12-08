#include "widget.h"
#include "ui_widget.h"
#include "progressindicator.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btn_start_clicked()
{
    ui->scan->startAnimation();
}

void Widget::on_btn_stop_clicked()
{
    ui->scan->stopAnimation();
}

#include "widget.h"
#include <QApplication>
#include"connection.h"
#include<QTime>
#include<QSplashScreen>
#include<QPixmap>

int main(int argc, char *argv[])
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    QApplication a(argc, argv);

    //创建数据库
    if(!CreatConnection())
        return 1;

    Widget w;
    w.setWindowIcon(QIcon(":/image/image/ios8_Music_48px_1173465_easyicon.net.png"));
    w.setWindowTitle(QString::fromUtf8("我的音乐"));
    w.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    w.show();

    return a.exec();
}


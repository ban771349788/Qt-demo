#include "dialog.h"

#include <QApplication>
#include <QDebug>
#include <QString>
#include <QList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog test;
    test.open_databases();

    test.create_table();

    QString str = QString("student");
    qDebug()<< "istableExit:"<<test.is_table_exit(str);

    Sql_data data1 = {1, "zhangsan", 25};
    Sql_data data2 = {2, "lisi", 27};
    test.sing_insert_data(data1);
    test.sing_insert_data(data2);
    test.query_table();
    qDebug()<< endl;

    QList <Sql_data>list;
    Sql_data data3 = {3, "xiaoban", 22};
    Sql_data data4 = {4, "xiaowang", 23};
    list.append(data3);
    list.append(data4);
    test.more_insert_ata(list);
    test.query_table();
    qDebug()<< endl;

    test.modify_data(2, "modify", 10);
    test.query_table();
    qDebug()<< endl;

    test.delete_data(2);
    test.query_table();
    qDebug()<< endl;

    test.delete_table(str);

    test.close_databases();

    return a.exec();
}

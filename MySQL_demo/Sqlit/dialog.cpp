#include "dialog.h"
#include <QDebug>
#include <QMessageBox>
#include <QVariantList>

Dialog::Dialog()
{
    if(QSqlDatabase::contains("default_connect")){
        m_database = QSqlDatabase::database("default_connect");
        qDebug()<<__LINE__;
    }else{
        m_database = QSqlDatabase::addDatabase("QSQLITE");
        m_database.setDatabaseName("sql_data.db");
        qDebug()<<__LINE__;
    }
}

Dialog::~Dialog()
{
    //close_databases();
}

void Dialog::open_databases(void)
{
    if(!m_database.open())
        qDebug()<<m_database.lastError().text();
    else
        qDebug()<<"open database success";
}

void Dialog::close_databases(void)
{
    if(m_database.isOpen())
        m_database.close();
    qDebug()<<"close database success";
}

void Dialog::create_table(void)
{
    QSqlQuery sql_query;
    QString cmd = QString("create table student(\
                          id int primary key not null,\
                          name text not null,\
                          age int not null\
                          )");

    sql_query.prepare(cmd);
    if(!sql_query.exec())
        qDebug()<<sql_query.lastError().text();
}

bool Dialog::is_table_exit(QString table_name)
{
    if(m_database.tables().contains(table_name))
        return true;

    return false;
}

void Dialog::query_table(void)
{
    QSqlQuery sql_query;
    if(!sql_query.exec("select * from student;"))
        qDebug()<<sql_query.lastError().text();
    else{
        while (sql_query.next()) {
            qDebug()<<sql_query.value("id").toInt()
                   << sql_query.value("name").toString().toUtf8().data()
                   << sql_query.value("age").toInt();
        }
    }
}

void Dialog::delete_table(QString table_name)
{
    QSqlQuery sql_query;
    if(!sql_query.exec(QString("drop table %1;").arg(table_name)))
        qDebug()<<sql_query.lastError().text();
    else {
        qDebug()<<QString("delete table %1 success").arg(table_name);
    }
}

void Dialog::sing_insert_data(Sql_data &singData)
{
    QSqlQuery sql_query;
    sql_query.prepare("insert into student values(:id, :name, :age)");
    sql_query.bindValue(":id", singData.id);
    sql_query.bindValue(":name", singData.name);
    sql_query.bindValue(":age", singData.age);

    if(!sql_query.exec())
        qDebug()<<"insert data fail";
    else
        qDebug()<<"insert data success";
}

void Dialog::more_insert_ata(QList<Sql_data> &moreData)
{
    QSqlQuery sql_query;
    QVariantList id_list, name_list, age_list;

    sql_query.prepare("insert into student values(?, ?, ?)");
    for(int i = 0; i <moreData.size(); ++i)
    {
        id_list   << moreData.at(i).id;
        name_list << moreData.at(i).name;
        age_list  << moreData.at(i).age;
    };

    sql_query.addBindValue(id_list);
    sql_query.addBindValue(name_list);
    sql_query.addBindValue(age_list);

    if(!sql_query.execBatch())
        qDebug()<<"insert data fail";
    else
        qDebug()<<"insert data success";
}

void Dialog::modify_data(int id, QString name, int age)
{
    QSqlQuery sql_query;
    sql_query.prepare("update student set name =?, age=? where id = ?");
    sql_query.addBindValue(name);
    sql_query.addBindValue(age);
    sql_query.addBindValue(id);

    if(!sql_query.exec())
        qDebug()<<"modify data fail";
    else
        qDebug()<<"modify data success";
}

void Dialog::delete_data(int id)
{
    QSqlQuery sql_query;
    if(!sql_query.exec(QString("delete from student where id = %1").arg(id)))
        qDebug()<<"delete data fail";
    else
        qDebug()<<"delete data success";
}

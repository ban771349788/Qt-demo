#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

typedef  struct{
    int id;
    QString name;
    int age;
}Sql_data;

class Dialog
{
public:
    Dialog();
    ~Dialog();

public:
    void open_databases(void);
    void close_databases(void);

    void create_table(void);
    bool is_table_exit(QString table_name);
    void query_table(void);
    void delete_table(QString table_name);

    void sing_insert_data(Sql_data &singData);
    void more_insert_ata(QList<Sql_data> &moreData);

    void modify_data(int id, QString name, int age);
    void delete_data(int id);

private:
    QSqlDatabase m_database;
};
#endif // DIALOG_H

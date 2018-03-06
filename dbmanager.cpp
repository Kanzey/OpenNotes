#include "dbmanager.h"

DBManager::DBManager()
{
    Database = QSqlDatabase::addDatabase("QSQLITE");
    Database.setDatabaseName("notes.db");
    if (!Database.open())
    {
        qDebug() << Database.lastError().text();
    }
}


DBManager::~DBManager()
{
    Database.close();
}

QList<Section> DBManager::getSections()
{
    QList<Section> tmp;
    getSections(tmp);
    return tmp;
}

void DBManager::getSections(QList<Section> &sectionList)
{
    QSqlQuery query;
    query.exec("Select id, name, color From Sections;");
    while(query.next()){
        qDebug() << query.value(2);
        sectionList.append(Section(query.value(0).toInt() ,query.value(1).toString(),query.value(2).toString()));
        qDebug() << sectionList.last().color;
    }
}

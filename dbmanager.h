#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QtDebug>
#include <QSqlError>
#include <QList>
#include <QSqlQuery>
#include <section.h>

class DBManager
{
private:
    QSqlDatabase Database;
public:
    DBManager();
    ~DBManager();

    QList<Section> getSections();
    void getSections(QList<Section>& sectionList);
};

#endif // DBMANAGER_H

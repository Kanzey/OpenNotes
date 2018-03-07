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
    //QList<Note> getNotes();
    //void getNotes(QList<Note>& noteList);
};

#endif // DBMANAGER_H

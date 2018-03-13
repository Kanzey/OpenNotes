#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QtDebug>
#include <QSqlError>
#include <QList>
#include <QSqlQuery>

#include <section.h>
#include <note/note.h>

class DBManager
{
private:
    QSqlDatabase Database;
public:
    DBManager();
    ~DBManager();

    static DBManager& getInstance(){
        static DBManager db;
        return db;
    }

    QList<Section> getSections();
    void getSections(QList<Section>& sectionList);
    QList<Note> getNotes(int id);
    void getNotes(QList<Note>& noteList, int id);

    DBManager(DBManager const &)  = delete;
    void operator =(DBManager const &) = delete;
};

#endif // DBMANAGER_H

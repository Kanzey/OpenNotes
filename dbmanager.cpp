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
        sectionList.append(Section(query.value(0).toInt() ,query.value(1).toString(),query.value(2).toString()));
    }
}

QList<Note> DBManager::getNotes(int id)
{
    QList<Note> tmp;
    getNotes(tmp,id);
    return tmp;
}

void DBManager::getNotes(QList<Note> &noteList, int id)
{
    QSqlQuery q;
    q.prepare("Select Notes.id, c0title, c1text, tag  From Notes  Left Join NotesData_content  ON id = docid Left join (Select noteid, group_concat(name) tag from Tags Left Join Notes_Tags  ON id = tagid group by noteid)  on noteid = id  Where sectionid = :id");
    q.bindValue(":id", id);
    q.exec();
    while(query.next()){
        noteList.append(Note(q.value(0).toInt(),
                                q.value(1).toString(),
                                q.value(2).toString(),
                                q.value(3).toString());
    }
}

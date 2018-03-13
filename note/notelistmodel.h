#ifndef NOTELISTMODEL_H
#define NOTELISTMODEL_H

#include <QAbstractListModel>
#include <QList>

#include <dbmanager.h>

class NoteListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit NoteListModel(QObject *parent = nullptr);

    loadNotes(DBManager& db, int id);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

private:
    QList<Note> m_noteList;
};

#endif // NOTELISTMODEL_H

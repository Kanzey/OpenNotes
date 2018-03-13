#include "notelistmodel.h"

NoteListModel::NoteListModel(QObject *parent) : QAbstractListModel(parent)
{
}

NoteListModel::loadNotes(DBManager &db, int id)
{
    db.getNotes(m_noteList, id);
}

int NoteListModel::rowCount(const QModelIndex &parent) const
{
    return m_noteList.size();
}

QVariant NoteListModel::data(const QModelIndex &index, int role) const
{
    Note note = m_noteList[index.row()];
    return QVariant::fromValue(note);
}

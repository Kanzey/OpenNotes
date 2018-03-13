#include "noteproxymodel.h"

NoteProxyModel::NoteProxyModel(QObject *parent):
    QSortFilterProxyModel(parent)
{

}

void NoteProxyModel::setFilterString(const QString &filterString)
{
    this->filterString = filterString;
    invalidateFilter();
}

bool NoteProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex index = sourceModel()->index(source_row, 0, source_parent);
    Note note = index.data().value<Note>();
    return  note.header.contains(filterString) ||
            note.tags.contains(filterString)||
            note.text.contains(filterString);
}


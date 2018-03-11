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
    QModelIndex index0 = sourceModel()->index(source_row, 0, source_parent);
    QModelIndex index1 = sourceModel()->index(source_row, 1, source_parent);
    QModelIndex index2 = sourceModel()->index(source_row, 2, source_parent);

    return  index0.data().toString().contains(filterString) ||
            index1.data().toString().contains(filterString)||
            index2.data().toString().contains(filterString);
}


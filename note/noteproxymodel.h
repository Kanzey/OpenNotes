#ifndef NOTEPROXYMODEL_H
#define NOTEPROXYMODEL_H

#include <QDebug>
#include <QSortFilterProxyModel>

class NoteProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    NoteProxyModel(QObject *parent = 0);
public slots:
    void setFilterString(const QString & filterString);

    // QSortFilterProxyModel interface
protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

    QString filterString;
};

#endif // NOTEPROXYMODEL_H

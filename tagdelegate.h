#ifndef TAGDELEGATE_H
#define TAGDELEGATE_H

#include <QPainter>
#include <QStyledItemDelegate>
#include <QApplication>
#include <QDebug>
#include <QCache>
#include <QListView>
#include <QAbstractItemView>

class TagDelegate : public QStyledItemDelegate
{
public:
    TagDelegate(QWidget *parent=nullptr);
    void paint();

    // QAbstractItemDelegate interface
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // TAGDELEGATE_H

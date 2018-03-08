#ifndef NOTEDELEGATE_H
#define NOTEDELEGATE_H

#include <QPainter>
#include <QStyledItemDelegate>
#include <QApplication>
#include <QDebug>
#include <QCache>
#include <QListView>
#include <QAbstractItemView>

class NoteDelegate : public QStyledItemDelegate
{
private:
    QColor sTextColor;
    QColor sDecorationColor;
    QColor sBackgroundColor;
    QColor backgroundColor;
    QColor decorationColor;
    QColor textColor;
    QCache<QModelIndex, QPair<int,int>> cache;

public:
    NoteDelegate(QColor baseColor, QWidget *parent=nullptr);
    void paint();

    // QAbstractItemDelegate interface
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // NOTEDELEGATE_H

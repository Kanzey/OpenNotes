#ifndef NOTEDELEGATE_H
#define NOTEDELEGATE_H

#include <QPainter>
#include <QStyledItemDelegate>
#include <QApplication>
#include <QDebug>
#include <QCache>
#include <QListView>
#include <QAbstractItemView>
#include <notedisplaysettings.h>

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
    NoteDisplaySettings* displaySettings;

public:
    NoteDelegate(QColor baseColor, NoteDisplaySettings * ds, QWidget *parent=nullptr);
    void paint();

    // QAbstractItemDelegate interface
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // NOTEDELEGATE_H

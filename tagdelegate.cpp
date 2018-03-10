#include "tagdelegate.h"

TagDelegate::TagDelegate( QWidget *parent):
    QStyledItemDelegate(parent)
{

}

void TagDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QRect tmp;
    if(option.state & QStyle::State_Selected){
        tmp = option.rect.adjusted(3,1,-3,-1);
        painter->setPen(option.palette.text().color());
        painter->fillRect(tmp,option.palette.midlight());
        painter->drawRect(tmp);

    }else{
        painter->setPen(option.palette.midlight().color());
        painter->drawLine(option.rect.bottomLeft(), option.rect.bottomRight());
    }

    painter->drawText(option.rect.adjusted(10,0,-10,0), Qt::AlignRight|Qt::AlignVCenter,
                      index.sibling(index.row(),1).data().toString(), &tmp);
    painter->drawText(option.rect.adjusted(10,0,tmp.x(),0), Qt::AlignVCenter, index.data().toString());
}

QSize TagDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(80,20);
}

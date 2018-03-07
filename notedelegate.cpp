#include "notedelegate.h"

NoteDelegate::NoteDelegate(QColor baseColor, QWidget *parent):
    QStyledItemDelegate(parent)

{
    qreal h = baseColor.hueF();
    sTextColor = QColor::fromHsvF(h,0.31,0.49);
    sBackgroundColor = QColor::fromHsvF(h,0.02,0.98);
    sDecorationColor = QColor::fromHsvF(h,0.14,0.91);
    textColor = QColor::fromHsvF(h,0.32,0.29);
    backgroundColor = QColor::fromHsvF(h,0.01,0.99);
    decorationColor = QColor::fromHsvF(h,0.05, 0.98);
}

void NoteDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
          QModelIndex inx = index.model()->index(index.row(),1);
          QModelIndex tagi = index.model()->index(index.row(),2);
          QStringList tags = tagi.data().toString().split(',',QString::SkipEmptyParts);
          QRect rect = option.rect;
          QFont font = painter->font();
          font.setPointSize(11);
          font.setBold(true);
          painter->setFont(font);
          rect.setHeight( 1.5 * painter->fontMetrics().height());
          if(option.state & QStyle::State_Selected){
            painter->fillRect(rect, sDecorationColor);
            painter->setPen(sTextColor);
          }else{
            painter->fillRect(rect, decorationColor);
            painter->setPen(textColor);
          }
          //qDebug() << index.data().toString();
          painter->drawText(rect.adjusted(24,0,0,0), Qt::AlignVCenter, index.data().toString());
          font.setPointSize(8);
          font.setBold(false);
          painter->setFont(font);
          rect.moveTop(rect.height());
          rect.setHeight(painter->fontMetrics().height()*1.5);
          QRect tagRect = rect.adjusted(16,0,0,0);
          QRect bound;

          for(int i=0; i<tags.size(); ++i){
              painter->drawText(tagRect, Qt::AlignVCenter, tags[i], &bound);
              tagRect.adjust(bound.width()+8,0,0,0);
          }
          font.setPointSize(9);
          painter->setFont(font);
          painter->drawText(option.rect.adjusted(16,rect.height()+rect.y(),0,0),Qt::TextWordWrap  ,inx.data().toString());

          painter->drawRect(option.rect);
          //progressBarOption.rect.moveBottom(progressBarOption.rect.bottom()+100);
          //QApplication::style()->drawControl(QStyle::CE_ProgressBar,
          //                                   &progressBarOption, painter);
          qDebug() << "paint" << index.row();
}

QSize NoteDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    //qDebug() << option.rect << index.data();
    QPair<int,int>* cachePtr = cache[index];
    if(cachePtr != nullptr && cachePtr->first == option.rect.width()){
        qDebug() << "Using cache" << index.row() << "for width" << option.rect.width();
        return QSize(100,cachePtr->second);
    }
    const QModelIndex textIndex = index.sibling(index.row(),1);
    int tmp=4;
    QFont font = option.font;
    font.setPointSize(11);
    QFontMetrics dfm(font);
    font.setPointSize(8);
    QFontMetrics sfm(font);
    tmp += 1.5 * sfm.height();
    font.setPointSize(9);
    QFontMetrics fm(font);
    tmp += 1.5* dfm.height();
    tmp += fm.boundingRect(option.rect.adjusted(20,tmp,0,0),
                           Qt::TextWordWrap, textIndex.data().toString()).height();
    QPair<int,int>* objectPtr = new QPair<int,int>(option.rect.width(),tmp);
    const_cast<NoteDelegate*>(this)->cache.insert(index,objectPtr);
    qDebug() << "Computing Size" << index.row() << "for width" << option.rect.width();
    return QSize(100,tmp);
}

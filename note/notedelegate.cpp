#include "notedelegate.h"

NoteDelegate::NoteDelegate(QColor baseColor, NoteDisplaySettings *ds, QWidget *parent):
    QStyledItemDelegate(parent),
    displaySettings(ds)
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
          qDebug() << option.rect << "Paint rect";
          Note note = index.data().value<Note>();
          QRect rect = option.rect;
          painter->setFont(displaySettings->headerFont);
          rect.setHeight( 1.5 * painter->fontMetrics().height());
          if(option.state & QStyle::State_Selected){
            painter->fillRect(rect, sDecorationColor);
            painter->setPen(sTextColor);
          }else{
            painter->fillRect(rect, decorationColor);
            painter->setPen(textColor);
          }
          //qDebug() << index.data().toString();
          painter->drawText(rect.adjusted(24,0,0,0), Qt::AlignVCenter, note.header);
          QFont font = option.font;
          font.setPointSize(9);
          painter->setFont(font);
          rect.moveTop(rect.y()+rect.height());
          rect.setHeight(painter->fontMetrics().height()*1.5);
          QRect tagRect = rect.adjusted(20,0,0,0);
          QRect bound;

          for(int i=0; i<note.tags.size(); ++i){
              painter->drawText(tagRect, Qt::AlignVCenter, note.tags[i], &bound);
              tagRect.adjust(bound.width()+8,0,0,0);
          }
          painter->setFont(displaySettings->textFont);
          painter->setPen("black");
          painter->drawText(option.rect.adjusted(16,rect.y()-option.rect.y()+rect.height()+4,-10,0),Qt::TextWordWrap  ,note.text);

          painter->drawRect(option.rect);
          //progressBarOption.rect.moveBottom(progressBarOption.rect.bottom()+100);
          //QApplication::style()->drawControl(QStyle::CE_ProgressBar,
          //                                   &progressBarOption, painter);
          qDebug() << "paint" << index.row();
}

QSize NoteDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    int store=0;
    Note note = index.data().value<Note>();
    QListView* par= ((QListView*)parent());
    int width = par->width();
    if(option.rect.width() == 0){
        qDebug() << "Zero width rect" << par->gridSize() ;
    }
    qDebug() << option.rect;
    QPair<int,int>* cachePtr = cache[index];
    if(cachePtr != nullptr){
        if(cachePtr->first == width){
        qDebug() << "Using cache" << index.row() << "for width" << width;
        return QSize(width,cachePtr->second);
        }
        store = cachePtr->second;
    }
    QRect rect = option.rect;
    rect.setWidth(option.rect.width()?option.rect.width():width);
    int tmp=8;
    QFont font = option.font;
    QFontMetrics dfm(displaySettings->headerFont);
    font.setPointSize(9);
    QFontMetrics sfm(font);
    tmp += 1.5 * sfm.height();
    QFontMetrics fm(displaySettings->textFont);
    tmp += 1.5* dfm.height();
    tmp += fm.boundingRect(rect.adjusted(16,tmp,-10,0),
                           Qt::TextWordWrap, note.text).height();
    QPair<int,int>* objectPtr = new QPair<int,int>(width,tmp);
    if(option.rect.width() != 0 && store != tmp){
        const_cast<NoteDelegate*>(this)->cache.insert(index,objectPtr);
        const_cast<NoteDelegate*>(this)->sizeHintChanged(index);
    }
    qDebug() << "Computing Size" << index.row() << "for width" << width;
    return QSize(width,tmp);
}

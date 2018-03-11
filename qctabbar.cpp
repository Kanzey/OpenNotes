#include "qctabbar.h"

QCTabBar::QCTabBar(QHash<QString, Section> *sections, QWidget *parent):
    QTabBar(parent), sections(sections)
{
    setMovable(true);
    setExpanding(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void QCTabBar::paintEvent(QPaintEvent *){
    QStylePainter painter(this);
    QStyleOptionTab opt;

    for(int i = 0;i < count();i++)
    {
        initStyleOption(&opt,i);
        if(i == count()-1)
            opt.rect.adjust(0,0,-1,0);
        if(sections->contains(opt.text)){
            //opt.palette.setColor(QPalette::Button, (*sections)[opt.text].tabColor);
            QPalette palette = QPalette((*sections)[opt.text].tabColor);
            QColor c;
            if(opt.state & QStyle::State_Selected){
                c = palette.color(palette.Active, palette.Button);
            }else{
                opt.rect.adjust(0,2,0,0);
                c = palette.color(palette.Disabled, palette.Mid);
            }
            painter.fillRect(opt.rect, c);
            painter.drawRect(opt.rect);
        }
        //painter.drawControl(QStyle::CE_TabBarTabShape, opt);
        painter.drawControl(QStyle::CE_TabBarTabLabel, opt);
    }
}

QSize QCTabBar::tabSizeHint(int index) const
{
    QSize tmp = QTabBar::tabSizeHint(index);
    tmp.setWidth(qMax(60,((QWidget*)parent())->size().width()/count()));
    return tmp;
}

QCTabBar::~QCTabBar(){
    delete sections;
}

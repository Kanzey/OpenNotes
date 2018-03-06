#include "qctabwidget.h"

QCTabWidget::QCTabWidget(QWidget *parent):QTabWidget(parent){

}

void QCTabWidget::setTabBar(QList<Section> sections){
    QHash <QString, Section> * dict = new QHash<QString, Section>;
    for(int i=0; i< sections.size(); ++i)
        (*dict)[sections[i].name] = sections[i];
    QTabWidget::setTabBar(new QCTabBar(dict));
}

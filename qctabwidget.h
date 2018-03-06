#ifndef QCTABWIDGET_H
#define QCTABWIDGET_H

#include<QTabWidget>
#include<qctabbar.h>
#include<section.h>

class QCTabWidget : public QTabWidget
{
public:
    QCTabWidget(QWidget *parent=0);

    void setTabBar(QList<Section> sections);
};

#endif // QCTABWIDGET_H

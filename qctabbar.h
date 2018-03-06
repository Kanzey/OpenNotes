#ifndef QCTABBAR_H
#define QCTABBAR_H

#include <QTabBar>
#include <QStylePainter>
#include <QStyleOptionTab>
#include <section.h>

class QCTabBar : public QTabBar
{
public:
    QCTabBar(QHash<QString, Section> *sections, QWidget *parent=0);

protected:
    void paintEvent(QPaintEvent */*event*/);


private:
    QHash<QString, Section> * sections;
    ~QCTabBar();
};

#endif // QCTABBAR_H

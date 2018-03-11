#ifndef QCTABBAR_H
#define QCTABBAR_H

#include <QTabBar>
#include <QStylePainter>
#include <QStyleOptionTab>
#include <QDebug>
#include <section.h>

class QCTabBar : public QTabBar
{
public:
    QCTabBar(QHash<QString, Section> *sections, QWidget *parent=0);

private:
    QHash<QString, Section> * sections;
    ~QCTabBar();

    // QTabBar interface
protected:
    void paintEvent(QPaintEvent */*event*/);
    QSize tabSizeHint(int index) const override;

};

#endif // QCTABBAR_H

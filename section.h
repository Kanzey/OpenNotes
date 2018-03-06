#ifndef SECTION_H
#define SECTION_H

#include <QColor>

class Section
{
public:
    qint32 id;
    QString name;
    QColor color;
    QColor tabColor;

    Section();
    Section(qint32 id, QString name, QString color);
};

#endif // SECTION_H

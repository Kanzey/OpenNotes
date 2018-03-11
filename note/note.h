#ifndef NOTE_H
#define NOTE_H

#include <QString>

class Note
{
public:
    quint32 id;
    QString header;
    QString text;
    QStringList tags;
    Note(quint32 id, QString header, QString text, QString tags);
};

#endif // NOTE_H

#ifndef NOTE_H
#define NOTE_H

#include <QDebug>
#include <QMetaType>
#include <QString>
#include <QStringList>

class Note
{
public:
    quint32 id;
    QString header;
    QString text;
    QStringList tags;

    Note() = default;
    Note(const Note& other) = default;
    ~Note() = default;

    Note(quint32 id, QString header, QString text, QString tags);
};

Q_DECLARE_METATYPE(Note)

QDebug operator <<(QDebug dbg, const Note &note);

#endif // NOTE_H

#ifndef NOTEDISPLAYSETTINGS_H
#define NOTEDISPLAYSETTINGS_H

#include <QObject>

class NoteDisplaySettings : public QObject
{
    Q_OBJECT
public:
    explicit NoteDisplaySettings(QObject *parent = nullptr);

signals:

public slots:
};

#endif // NOTEDISPLAYSETTINGS_H
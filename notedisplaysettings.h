#ifndef NOTEDISPLAYSETTINGS_H
#define NOTEDISPLAYSETTINGS_H

#include <QFont>
#include <QObject>
#include "settingmanager.h"

class NoteDisplaySettings : public QObject
{
    Q_OBJECT
public:
    explicit NoteDisplaySettings(QObject *parent = nullptr);

    void loadConfig();
    void saveConfig();
    QFont headerFont;
    QFont textFont;
};

#endif // NOTEDISPLAYSETTINGS_H

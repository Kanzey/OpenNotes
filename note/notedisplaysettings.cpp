#include "notedisplaysettings.h"

NoteDisplaySettings::NoteDisplaySettings(QObject *parent) : QObject(parent)
{
    loadConfig();
}

void NoteDisplaySettings::loadConfig()
{
    SettingManager& sm = SettingManager::getInstance();
    sm.loadSettings("headerFont",headerFont);
    sm.loadSettings("textFont",textFont);
}

void NoteDisplaySettings::saveConfig()
{
    SettingManager& sm = SettingManager::getInstance();
    sm.saveSettings("headerFont",headerFont);
    sm.saveSettings("textFont",textFont);
}

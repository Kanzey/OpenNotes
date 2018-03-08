#ifndef SETTINGMANAGER_H
#define SETTINGMANAGER_H

#include<QApplication>
#include <QSettings>

class SettingManager
{
private:
    QSettings m_settings;
    SettingManager():m_settings("Generic","OpenNotes"){}
public:
    static SettingManager& getInstance(){
        static SettingManager s;
        return s;
    }

    template<typename T>
    void loadSettings(QString const& key, T& value)
    {
        value = m_settings.value(key).value<T>();
    }
    template<typename T>
    void saveSettings(QString const& key, T value)
    {
        m_settings.setValue(key,value);
    }

    SettingManager(SettingManager const &)  = delete;
    void operator =(SettingManager const &) = delete;
};

#endif // SETTINGMANAGER_H

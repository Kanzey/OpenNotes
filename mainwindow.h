#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QListView>
#include <QSqlQueryModel>
#include <dbmanager.h>
#include <notedelegate.h>
#include <settingmanager.h>
#include <notelistoptionsdialog.h>
#include <notedisplaysettings.h>
#include "notedisplay.h"
#include <QFrame>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    NoteDisplaySettings* noteDisplaySettings;

private:
    Ui::MainWindow *ui;
    DBManager dbManager;

    void createSections();
    void createOptions();

private slots:
    void NoteListOptions();
};

#endif // MAINWINDOW_H

#ifndef NOTEDISPLAY_H
#define NOTEDISPLAY_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <section.h>
#include <notedelegate.h>
#include <tagdelegate.h>
#include <notedisplaysettings.h>

namespace Ui {
class NoteDisplay;
}

class NoteDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit NoteDisplay(Section section, NoteDisplaySettings* ds, QWidget *parent = 0);
    ~NoteDisplay();

private:
    Section section;
    Ui::NoteDisplay *ui;

    void setupLists(NoteDisplaySettings* ds);
    void setupTags();

};

#endif // NOTEDISPLAY_H

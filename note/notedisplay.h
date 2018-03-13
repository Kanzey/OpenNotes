#ifndef NOTEDISPLAY_H
#define NOTEDISPLAY_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <section.h>
#include <note/notedelegate.h>
#include <tagdelegate.h>
#include <note/notedisplaysettings.h>
#include <note/noteproxymodel.h>
#include <note/notelistmodel.h>

#include <QStandardItemModel>

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

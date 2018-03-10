#ifndef NOTEDISPLAY_H
#define NOTEDISPLAY_H

#include <QWidget>

namespace Ui {
class NoteDisplay;
}

class NoteDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit NoteDisplay(QWidget *parent = 0);
    ~NoteDisplay();

private:
    Ui::NoteDisplay *ui;
};

#endif // NOTEDISPLAY_H

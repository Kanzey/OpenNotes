#ifndef NOTELISTOPTIONSDIALOG_H
#define NOTELISTOPTIONSDIALOG_H

#include <QDialog>

namespace Ui {
class NoteListOptionsDialog;
}

class NoteListOptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NoteListOptionsDialog(QWidget *parent = 0);
    ~NoteListOptionsDialog();

private:
    Ui::NoteListOptionsDialog *ui;
};

#endif // NOTELISTOPTIONSDIALOG_H

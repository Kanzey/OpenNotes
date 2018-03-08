#ifndef NOTELISTOPTIONSDIALOG_H
#define NOTELISTOPTIONSDIALOG_H

#include <QDialog>
#include <QFontDialog>
#include <QLabel>

namespace Ui {
class NoteListOptionsDialog;
}

class NoteListOptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NoteListOptionsDialog(QWidget *parent = 0);
    ~NoteListOptionsDialog();

private slots:
    void on_headerFontButton_clicked();
    void on_textFontButton_clicked();
private:
    Ui::NoteListOptionsDialog *ui;
    void dialogLogic(QLabel *preview);
};

#endif // NOTELISTOPTIONSDIALOG_H

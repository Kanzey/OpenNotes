#ifndef NOTELISTOPTIONSDIALOG_H
#define NOTELISTOPTIONSDIALOG_H

#include "notedisplaysettings.h"

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
    NoteDisplaySettings ds;

private slots:
    void on_headerFontButton_clicked();
    void on_textFontButton_clicked();
private:
    Ui::NoteListOptionsDialog *ui;
    void dialogLogic(QLabel *preview, QFont& orgFont);
    void setFontPreview(QLabel *preview, QFont& font);
    QString fontDescription(QFont font);
};

#endif // NOTELISTOPTIONSDIALOG_H

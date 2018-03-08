#include "notelistoptionsdialog.h"
#include "ui_notelistoptionsdialog.h"

NoteListOptionsDialog::NoteListOptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoteListOptionsDialog)
{
    ui->setupUi(this);
}

NoteListOptionsDialog::~NoteListOptionsDialog()
{
    delete ui;
}

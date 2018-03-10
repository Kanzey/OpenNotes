#include "notedisplay.h"
#include "ui_notedisplay.h"

NoteDisplay::NoteDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NoteDisplay)
{
    ui->setupUi(this);
}

NoteDisplay::~NoteDisplay()
{
    delete ui;
}

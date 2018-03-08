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

void NoteListOptionsDialog::on_headerFontButton_clicked()
{
    dialogLogic(ui->headerFontPreview);
}

void NoteListOptionsDialog::on_textFontButton_clicked()
{
    dialogLogic(ui->textFontPreview);
}

void NoteListOptionsDialog::dialogLogic(QLabel* preview)
{
    bool ok;
    QFont font = QFontDialog::getFont(
                &ok, preview->font(), this);
    if(ok){
        preview->setFont(font);
        QString text = font.family() + " " + font.styleName() + " " + QString::number(font.pointSize()) + " pt";
        preview->setText(text);
    }
}

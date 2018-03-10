#include "notelistoptionsdialog.h"
#include "ui_notelistoptionsdialog.h"

NoteListOptionsDialog::NoteListOptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoteListOptionsDialog)
{
    ui->setupUi(this);
    setFontPreview(ui->headerFontPreview, ds.headerFont);
    setFontPreview(ui->textFontPreview, ds.textFont);
}

NoteListOptionsDialog::~NoteListOptionsDialog()
{
    delete ui;
}

void NoteListOptionsDialog::on_headerFontButton_clicked()
{
    dialogLogic(ui->headerFontPreview, ds.headerFont);
}

void NoteListOptionsDialog::on_textFontButton_clicked()
{
    dialogLogic(ui->textFontPreview, ds.textFont);
}

void NoteListOptionsDialog::dialogLogic(QLabel* preview, QFont& orgFont)
{
    bool ok;
    QFont font = QFontDialog::getFont(
                &ok, orgFont, this);
    if(ok){
        setFontPreview(preview,font);
        orgFont = font;
    }

}

void NoteListOptionsDialog::setFontPreview(QLabel *preview, QFont &font)
{
    preview->setFont(font);
    preview->setText(fontDescription(font));
}

QString NoteListOptionsDialog::fontDescription(QFont font)
{
    return font.family() + " " + font.styleName() + " " + QString::number(font.pointSize()) + " pt";
}

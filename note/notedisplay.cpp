#include "notedisplay.h"
#include "ui_notedisplay.h"


NoteDisplay::NoteDisplay(Section section, NoteDisplaySettings* ds, QWidget *parent) :
    QWidget(parent),
    section(section),
    ui(new Ui::NoteDisplay)
{
    ui->setupUi(this);
    ui->splitter->setSizes(QList<int>({1,INT_MAX}));
    QPalette palette(section.tabColor);
    palette.setBrush(palette.Base, palette.dark());
    ui->tagListView->setPalette(palette);
    //qDebug() << ui->noteListView->palette();
    setupLists(ds);
    setupTags();
}

NoteDisplay::~NoteDisplay()
{
    delete ui;
}

void NoteDisplay::setupLists(NoteDisplaySettings* ds)
{
    NoteListModel * model = new NoteListModel(ui->noteListView);
    model->loadNotes(DBManager::getInstance(),section.id);
    NoteProxyModel* modelProxy= new NoteProxyModel(ui->noteListView);
    modelProxy->setSourceModel(model);
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), modelProxy, SLOT(setFilterString(QString)));
    ui->noteListView->setModel(modelProxy);
    ui->noteListView->setItemDelegate(new NoteDelegate(section.tabColor, ds, ui->noteListView));
}

void NoteDisplay::setupTags()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery q;
    q.prepare("Select name, COUNT(name) from Notes inner join Notes_Tags on Notes.id = Notes_Tags.noteid inner join Tags on Notes_Tags.tagid = Tags.id where Notes.sectionid = :id group by name");
    q.bindValue(":id", section.id);
    q.exec();
    model->setQuery(q);
    ui->tagListView->setModel(model);
    ui->tagListView->setItemDelegate(new TagDelegate(ui->tagListView));
}

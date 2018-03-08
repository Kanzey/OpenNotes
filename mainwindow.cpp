#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createSections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createSections()
{
    QList<Section> list = dbManager.getSections();
    ui->tabWidget->setTabBar(list);
    for(int i=0; i< list.size(); ++i){
        QWidget *qf = new QWidget;
        ui->tabWidget->addTab( qf,list[i].name);
        QGridLayout *l =new QGridLayout(qf);
        QListView *qw = new QListView;
        qw->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        l->setMargin(0);
        l->addWidget(qw,0,0,1,1);
        QSqlQueryModel *model = new QSqlQueryModel;
        QSqlQuery q;
        q.prepare("Select c0title, c1text, tag  From Notes  Left Join NotesData_content  ON id = docid Left join (Select noteid, group_concat(name) tag from Tags Left Join Notes_Tags  ON id = tagid group by noteid)  on noteid = id  Where sectionid = :id");
        q.bindValue(":id", list[i].id);
        q.exec();
        model->setQuery(q);
        qw->setModel(model);
        qw->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        qw->setItemDelegate(new NoteDelegate(list[i].tabColor,qw));
        //qw->show();
    }
}

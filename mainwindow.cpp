#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createOptions();
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
    for(int i=0; i< list.size(); ++i)
        ui->tabWidget->addTab(new NoteDisplay(list[i],noteDisplaySettings), list[i].name);
}

void MainWindow::createOptions()
{
    noteDisplaySettings = new NoteDisplaySettings(this);
}

void MainWindow::NoteListOptions()
{
    NoteListOptionsDialog nd;
    if(nd.exec() == QDialog::Accepted){
         nd.ds.saveConfig();
         noteDisplaySettings->loadConfig();
    }
}

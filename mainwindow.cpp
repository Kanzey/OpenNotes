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
        QWidget *qw = new QWidget;
        ui->tabWidget->addTab(qw,list[i].name);
    }
}

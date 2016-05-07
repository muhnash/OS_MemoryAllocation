#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "entity.h"
#include "memory.h"
#include <QList>
Entity h(false);
QList <Entity> mem;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_clicked()
{
   QString a = ui->address->text();
   QString s =ui->size->text();
   h.set_base_address(a.toInt());
   h.set_size(s.toInt());
   mem.push_back(h);
}

void MainWindow::on_initalize_clicked()
{
   Memory m(mem) ;
}

void MainWindow::on_bestFit_2_clicked()
{

}

void MainWindow::on_insertButton_2_clicked()
{
    int x = ui->holesize->text().toInt();
    int y = ui->holeaddress->text().toInt();
    Entity temp(false);
    temp.set_size(x);
    temp.set_base_address(y);
    temp.set_type(false);
    the_list.push_back(temp);
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QMainWindow>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include "memory.h"
#include "entity.h"
#include <QMessageBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_add_clicked();

    void on_initalize_clicked();

    void on_bestFit_2_clicked();

    void on_insertButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QList <Entity> the_list;
};

#endif // MAINWINDOW_H


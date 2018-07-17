#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap levelpix;
    levelpix.load(":/level/level.png");

    ui->levellabel->setPixmap(levelpix);

//    connect(ui->backlabel, SIGNAL(clicked()), this, SLOT(back()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//返回至登录界面
void MainWindow::back(){
    qDebug()<<"back";
}


void MainWindow::on_backButton_clicked()
{
    this->close();
}

void MainWindow::on_level1Button_clicked()
{
    this->close();
    level1 = new Level1;
    level1->show();
}

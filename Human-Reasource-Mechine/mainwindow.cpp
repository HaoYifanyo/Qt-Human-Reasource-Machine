#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include <QPixmap>
#include <QDebug>

extern int levelchoose=0;

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

//level1
void MainWindow::on_level1Button_clicked()
{
//    this->close();
    levelchoose=1;
    level1 = new Level1(0,1);
    level1->show();
}

//level2
void MainWindow::on_level2Button_clicked()
{

    levelchoose=2;
    level1 = new Level1(0,2);
    level1->show();
}

//level3
void MainWindow::on_level3Button_clicked()
{
    levelchoose=3;
    level1 = new Level1(0,3);
    level1->show();
}

//level4
void MainWindow::on_level4Button_clicked()
{
    levelchoose=4;
    level1 = new Level1(0,4);
    level1->show();
}

void MainWindow::on_level2Button_pressed()
{
//    qDebug()<<"press";
}

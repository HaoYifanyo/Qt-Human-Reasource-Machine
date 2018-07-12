#include "login.h"
#include "ui_login.h"
#include "dbutil.h"
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QDebug>
#include <QPluginLoader>
#include <QString>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    dbutil = new DBUtil;

}

Login::~Login()
{
    delete ui;
    delete dbutil;
    delete mainwindow;

}

//注册
void Login::on_pushButton_2_clicked()
{
    //获取文本框中的用户名和密码
    QString curId=ui->lineEdit->text();
    QString curPasswd=ui->lineEdit_2->text();


    //判断用户名是否为空
    if(curId==""){
        QMessageBox::information(this, tr("error"),
                                 tr("用户名不能为空"));

    }else if(curPasswd!=""){

        //如果当前id已存在
        if(judgeId(curId)){
            QMessageBox::information(this, tr("error"),
                                     tr("该用户名已存在"));
        }else{        //不存在则添加该条记录
            dbutil->addId(curId,curPasswd);
            QMessageBox::information(this, tr("注册成功"),
                                     tr("您可以登录开始游戏了"));
        }
    }else{    //判断密码是否为空
    QMessageBox::information(this, tr("error"),
                             tr("密码不能为空"));
    }

}

//登录
void Login::on_pushButton_clicked()
{
    //获取文本框中的用户名和密码
    QString curId=ui->lineEdit->text();
    QString curPasswd=ui->lineEdit_2->text();

    //判断用户名是否为空
    if(curId==""){
        QMessageBox::information(this, tr("error"),
                                 tr("用户名不能为空"));

    }else if(curPasswd==""){    //判断密码是否为空
        QMessageBox::information(this, tr("error"),
                                 tr("密码不能为空"));
    }else{

        //如果当前id已存在
        if(judgeId(curId)){

            //从数据库中获取该用户对应的密码
            QString loginPasswd=dbutil->findPasswd(curId);

            //判断密码是否正确
            if(loginPasswd==curPasswd){

                qDebug()<<"success";
                //打开主界面
                mainwindow = new MainWindow;
                mainwindow->show();
            }else{
                QMessageBox::information(this, tr("error"),
                                         tr("密码错误"));
            }

        }else{        //不存在
            QMessageBox::information(this, tr("error"),
                                     tr("用户不存在"));
        }
    }


}

 //判断当前id是否已在表中
bool Login::judgeId(QString curId){
    //获取数据库user表中的所有id
    QString* curResult=dbutil->findId();
    //用一个bool变量表示
    bool isIntable=false;

    int size=sizeof(curResult);

    //依次判断
    for(int i=0;i<size;i++){
        if(curId==curResult[i]){
            isIntable=true;
            break;
        }
    }

    return isIntable;
}

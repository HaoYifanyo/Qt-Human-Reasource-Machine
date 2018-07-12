#include "dbutil.h"
#include <QtSql>
#include <QMessageBox>
#include <QDebug>
#include <QPluginLoader>
#include <exception>

DBUtil::DBUtil()
{

}

void DBUtil::OpenConnection(){
    //    QPluginLoader loader;
    //    MySQL 驱动插件的路径
    //    loader.setFileName("D:/Qt5/5.8/mingw53_32/plugins/sqldrivers/qsqlmysqld.dll");
    //    qDebug() << loader.load();
    //    qDebug() << loader.errorString();
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setPort(3306);
    db.setHostName("127.0.0.1");

    db.setDatabaseName("qt");
    db.setUserName("root");
    db.setPassword("123456");
    bool ok = db.open();
    if(ok){
          qDebug()<<"成功连接数据库";
    }else{
          QMessageBox::warning(NULL,"警告","无法连接数据库");
    }

}

void DBUtil::CloseConnection(){
//    try{
        if(db.isOpen())
            db.close();
//    }catch(Exception e){
//        e.print();
//    }

}

void DBUtil::addId(QString id,QString passwd){
    OpenConnection();
    QString sql="INSERT INTO `qt`.`user` (`id`, `passwd`) VALUES ('"+id+"','"+passwd+"')";

    QSqlQuery query;
    query.prepare(sql);
    query.exec();
    CloseConnection();
}

//
QString* DBUtil::findId(){
    OpenConnection();
    QString sql="SELECT id FROM `qt`.`user`";
    QSqlQuery query;
    query.prepare(sql);

    bool success = query.exec();
    if(!success){
        qDebug() << "查询user失败";
    }

    QString* result ;
    int size = query.size();
    result = new QString[size];

    query.seek(-1);

    for(int i=0;query.next();i++){

        result[i]=query.value(0).toString();
        qDebug()<<result[i];
    }
        CloseConnection();
    return result;

}

QString DBUtil::findPasswd(QString loginId){
    OpenConnection();
    QString sql="SELECT passwd FROM `qt`.`user` where id='"+loginId+"'";

    QSqlQuery query;
    query.prepare(sql);
    query.exec();

    query.first();
    QString loginPasswd=query.value(0).toString();
    CloseConnection();

    return loginPasswd;
}

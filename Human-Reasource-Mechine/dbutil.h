#ifndef DBUTIL_H
#define DBUTIL_H
#include <QString>
#include <QSqlDatabase>
class DBUtil
{
    QSqlDatabase db;
public:
    DBUtil();
    void OpenConnection();
    void CloseConnection();
    void addId(QString id,QString passwd);
    QString* findId();
    QString findPasswd(QString loginId);

};

#endif // DBUTIL_H

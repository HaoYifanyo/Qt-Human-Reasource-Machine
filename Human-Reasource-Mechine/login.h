#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "dbutil.h"
#include "mainwindow.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    bool judgeId(QString curId);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    DBUtil *dbutil;
    MainWindow *mainwindow;

};

#endif // LOGIN_H

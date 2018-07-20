#include "login.h"
#include "level1.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.show();

//    QMediaPlayer *example;
//    example=new QMediaPlayer;
//    example->add(QUrl(":/level/04 The Work Begins.mp3"));
//    example->play();

    return a.exec();
}

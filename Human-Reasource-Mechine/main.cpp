#include "login.h"
#include "level1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Level1 w;
    w.show();

    return a.exec();
}

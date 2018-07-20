#ifndef LEVEL1_H
#define LEVEL1_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QStandardItem>
#include <QLineEdit>
#include "labeldelegate.h"

namespace Ui {
class Level1;
}

class Level1 : public QWidget
{
    Q_OBJECT

public:
    explicit Level1(QWidget *parent = 0,int levelchoose=1);

    ~Level1();
    void mousePressEvent(QMouseEvent *event);			//按下鼠标
    void dragEnterEvent(QDragEnterEvent *event);		//拖动进入
    void dragMoveEvent(QDragMoveEvent *event);			//拖动
    void dropEvent(QDropEvent *event);				//放下
    void draw(QLabel *child, QMouseEvent *event,QString name);             //根据坐标绘制移动的label
    void drop(QString boxstr,QDropEvent *event);
    void update();
    void update2();
    void update3();
    void update4();
    void settable();     //设置表格
    void init();         //初始化状态
    void isSuccess();    //判断结果是否正确
    void setxy(int tempx,int tempy);
    void setxy1(int tempx,int tempy);

private slots:
    void on_pushButton_clicked();

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_clearButton_clicked();

    void on_clearButton_2_clicked();

    void on_backButton_clicked();

private:
    Ui::Level1 *ui;
    int *box;

    int *inboxline;
    int *outboxline;
    int *inboxsignal;
    QTimer *timer;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;
    int x;
    int y;
    int x1;
    int y1;
    int nowbox;
    int tableindex;
    QPixmap girlpix;
    QStandardItemModel *model;
    QLabel *label[6];
    QLineEdit *lineedit[10];
    int lineeditnum;
    int nowlevel;
    int *temp;
    int hand;

};

#endif // LEVEL1_H

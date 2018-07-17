#ifndef LEVEL1_H
#define LEVEL1_H

#include <QWidget>
#include <QLabel>
#include "labeldelegate.h"

namespace Ui {
class Level1;
}

class Level1 : public QWidget
{
    Q_OBJECT

public:
    explicit Level1(QWidget *parent = 0);
    ~Level1();
    void mousePressEvent(QMouseEvent *event);			//按下鼠标
    void dragEnterEvent(QDragEnterEvent *event);		//拖动进入
    void dragMoveEvent(QDragMoveEvent *event);			//拖动
    void dropEvent(QDropEvent *event);				//放下
    void draw(QLabel *child, QMouseEvent *event,QString name);             //根据坐标绘制移动的label
    void drop(QString boxstr,QDropEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_startButton_clicked();

private:
    Ui::Level1 *ui;
    int *box;
    LabelDelegate *m_labeldelegate;
    int *inboxline;
    int *outboxline;
    int *inboxsignal;
//    QLabel *label;
//    QPixmap *inboxpix;
//    QPixmap *outboxpix;
//    QPixmap *jumppix;
//    QPixmap *copyfrompix;
//    QPixmap *copytopix;
//    QPixmap *bg1pix;
//    QPixmap *bgpix;
};

#endif // LEVEL1_H

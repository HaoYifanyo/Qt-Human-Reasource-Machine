#include "level1.h"
#include "ui_level1.h"
#include "mainwindow.h"
#include <QMouseEvent>
#include <QLabel>
#include <QPixmap>
#include <QByteArray>
#include <QDataStream>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QDebug>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QVBoxLayout>
#include <iostream>
#include <windows.h>


Level1::Level1(QWidget *parent, int levelchoose) :
    QWidget(parent),
    ui(new Ui::Level1)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    timer2 = new QTimer(this);
    timer3 = new QTimer(this);
    timer4 = new QTimer(this);
    connect(timer ,&QTimer::timeout, this, &Level1::update);
    connect(timer2 ,&QTimer::timeout, this, &Level1::update2);
    connect(timer3 ,&QTimer::timeout, this, &Level1::update3);
    connect(timer4 ,&QTimer::timeout, this, &Level1::update4);

    //设置起始坐标
    setxy(135,276);
//    //设置结束坐标
//    setxy1(135,330);

    //存放“代码”，用数字表示相应内容，0为空
    box=new int[30];

    //inbox和outbox序列
    inboxline=new int[6];

    outboxline=new int[6];

    //用于标识box的位置,0表示在inbox序列,1表示在途中,2表示在outbox序列
    inboxsignal=new int[6];
    tableindex=0;
    //当前处理的数字
    nowbox=0;

    for(int i=0;i<6;i++){
        label[i]=new QLabel(this);
        label[i]->setStyleSheet("background:rgb(163, 203, 89);font: 87 12pt \"Arial Black\"; color: rgb(75, 98, 52);");
    }

    for(int i=0;i<10;i++){
        lineedit[i]=new QLineEdit;
        lineedit[i]->setStyleSheet("background-color: rgb(143, 140, 193);");
    }
    lineeditnum=0;

    init();
    settable();


    //加载相关图片
    QPixmap bgpix;
    QPixmap bg2pix;
    QPixmap startpix;
    QPixmap lpix1;
    QPixmap lpix2;
    QPixmap lpix3;

    girlpix.load(":/level/girl.png");
    girlpix = girlpix.scaled(girlpix.width()*0.8,girlpix.height()*0.8,Qt::KeepAspectRatio);

    bgpix.load(":/level/0.png");
    bg2pix.load(":/level/bg2.png");
    startpix.load(":/level/start.jpg");
    lpix1.load(":/level/1.png");
    lpix2.load(":/level/2.png");
    lpix3.load(":/level/3.png");

    bgpix = bgpix.scaled(bgpix.width()*0.9167,bgpix.height()*0.9167,Qt::IgnoreAspectRatio);
    bg2pix = bg2pix.scaled(bg2pix.width()*20,bg2pix.height()*100,Qt::IgnoreAspectRatio);
    startpix = startpix.scaled(startpix.width()*0.75,startpix.height()*0.75,Qt::IgnoreAspectRatio);
    lpix1 = lpix1.scaled(lpix1.width()*0.9,lpix1.height()*0.9,Qt::IgnoreAspectRatio);
    lpix2 = lpix2.scaled(lpix2.width()*0.9,lpix2.height()*0.9,Qt::IgnoreAspectRatio);
    lpix3 = lpix3.scaled(lpix3.width()*0.9,lpix3.height()*0.9,Qt::IgnoreAspectRatio);

    ui->bglabel->setPixmap(bgpix);

    ui->startlabel->setPixmap(startpix);
    ui->girllabel->setPixmap(girlpix);

    if(levelchoose==1){
        ui->llabel->setPixmap(lpix1);
        for(int i=1;i<6;i++){
            label[i]->hide();
        }
    }else if(levelchoose==2){
        ui->llabel->setPixmap(lpix2);
        for(int i=3;i<6;i++){
            label[i]->hide();
        }

    }else if(levelchoose==3){
        ui->llabel->setPixmap(lpix3);
        label[0]->setText(" B");
        label[1]->setText(" U");
        label[2]->setText(" G");
        label[0]->setGeometry(272,368,27,27);
        label[1]->setGeometry(329,368,27,27);
        label[2]->setGeometry(389,368,27,27);
        for(int i=3;i<6;i++){
            label[i]->hide();
        }

    }

    nowlevel=levelchoose;

}

Level1::~Level1()
{
    delete ui;

    delete timer;
    delete timer2;
    delete timer3;
    delete timer4;
    delete model;
    delete temp;

    delete box;
    delete inboxline;
    delete outboxline;
    delete inboxsignal;

    for(int i=0;i<6;i++){
        delete label[i];
    }

    for(int i=0;i<10;i++){
        delete lineedit[i];
    }

}

void Level1::mousePressEvent(QMouseEvent *event)        //鼠标按下事件
{
    qDebug() <<event->pos();
    if(event->pos().x()>693&&event->pos().x()<811){   //在可移动标签坐标范围内
        if(event->pos().x()>128&&event->pos().y()<163){    //inbox标签
            QLabel *child = new QLabel;
            child->setGeometry(698,131,73,34);
            QPixmap inboxpix;
            inboxpix.load(":/level/inbox.png");
            inboxpix = inboxpix.scaled(inboxpix.width()*0.652,inboxpix.height()*0.652,Qt::IgnoreAspectRatio);
            child->setPixmap(inboxpix);
            draw(child,event,"inbox/jpg");
        }else if(event->pos().y()<194){                 //outbox标签
            QLabel *child = new QLabel;
            child->setGeometry(698,165,73,34);
            QPixmap outboxpix;
            outboxpix.load(":/level/outbox.png");
            outboxpix = outboxpix.scaled(outboxpix.width()*0.652,outboxpix.height()*0.652,Qt::IgnoreAspectRatio);
            child->setPixmap(outboxpix);
            draw(child,event,"outbox/jpg");
        }else if(event->pos().y()<227){                 //copyfrom标签
            QLabel *child = new QLabel;
            child->setGeometry(698,198,73,34);
            QPixmap copyfpix;
            copyfpix.load(":/level/copyfrom.png");
            copyfpix = copyfpix.scaled(copyfpix.width()*0.652,copyfpix.height()*0.652,Qt::IgnoreAspectRatio);
            child->setPixmap(copyfpix);
            draw(child,event,"copyfrom/jpg");
        }else if(event->pos().y()<261){                 //copyto标签
            QLabel *child = new QLabel;
            child->setGeometry(698,226,73,34);
            QPixmap copytpix;
            copytpix.load(":/level/copyto.jpg");
            copytpix = copytpix.scaled(copytpix.width()*0.652,copytpix.height()*0.652,Qt::IgnoreAspectRatio);
            child->setPixmap(copytpix);
            draw(child,event,"copyto/jpg");
        }else if(event->pos().y()<295){                 //jump标签
            QLabel *child = new QLabel;
            child->setGeometry(698,261,73,34);
            QPixmap jumppix;
            jumppix.load(":/level/jump.png");
            jumppix = jumppix.scaled(jumppix.width()*0.652,jumppix.height()*0.652,Qt::IgnoreAspectRatio);
            child->setPixmap(jumppix);
            draw(child,event,"jump/jpg");
        }

    }

}

void Level1::dragEnterEvent(QDragEnterEvent *event)    //拖动进入事件
{
//    if(event->mimeData()->hasFormat("myImage/jpg"))
//    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
//    }
//    else
//        event->ignore();
}

void Level1::dragMoveEvent(QDragMoveEvent *event)       //拖动事件
{
//    if(event->mimeData()->hasFormat("myImage/jpg"))
//    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
//    }
//    else
//        event->ignore();
}

void Level1::dropEvent(QDropEvent *event)       //放下事件
{
//    qDebug()<<event->pos();


        //若在可放置区域
        if(event->pos().x()>817&&event->pos().x()<1091&&event->pos().y()>425){
            //判断当前放下的label是哪种类型
//            int n=0;

//            if(event->mimeData()->hasFormat("inbox/jpg")){
//                n=1;
//            }else if(event->mimeData()->hasFormat("outbox/jpg")){
//                n=2;
//            }else if(event->mimeData()->hasFormat("copyfrom/jpg")){
//                n=3;
//            }else if(event->mimeData()->hasFormat("copyto/jpg")){
//                n=4;
//            }else if(event->mimeData()->hasFormat("jump/jpg")){
//                n=5;
//            }


            for(int i=0;i<30;i++){
                if(box[i]==0){
//                    box[i]=n;
                    if(event->mimeData()->hasFormat("inbox/jpg")){
                        drop("inbox/jpg",event);
                        box[i]=1;
                        break;
                    }else if(event->mimeData()->hasFormat("outbox/jpg")){
                        drop("outbox/jpg",event);
                        box[i]=2;
                        break;
                    }else if(event->mimeData()->hasFormat("copyfrom/jpg")){
                        drop("copyfrom/jpg",event);
                        box[i]=3;
                        break;
                    }else if(event->mimeData()->hasFormat("copyto/jpg")){
                        drop("copyto/jpg",event);
                        box[i]=4;
                        break;
                    }else if(event->mimeData()->hasFormat("jump/jpg")){
                        drop("jump/jpg",event);
                        ui->tableView->setIndexWidget(model->index(tableindex,0),
                                                      lineedit[lineeditnum]);
                        lineeditnum++;
                        tableindex++;
                        box[i]=500;

                        break;
                    }

                }
            }
        }else
        event->ignore();
}

//根据坐标绘制移动的label
void Level1::draw(QLabel *child,QMouseEvent *event,QString name){
    if(!child->inherits("QLabel"))
                return;
    QPixmap pixmap = *child->pixmap();

    //第二步，自定义MIME类型
    QByteArray itemData;
    QDataStream dataStream(&itemData,QIODevice::WriteOnly);
    //将图片信息，位置信息保存到字节数组中
    dataStream<<pixmap<<QPoint(event->pos() - child->pos());
    //第三步，将数据放入QMimeData中
    QMimeData *mimeData = new QMimeData;
    mimeData->setData(name,itemData);
    //第四步，将QMimelda中的数据放进QDrag
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - child->pos());
    //第五步，给原图加阴影
    QPixmap tempPixmap = pixmap;
    QPainter painter;               //绘图
    painter.begin(&tempPixmap);
    //添加透明淡黑色阴影
    painter.fillRect(pixmap.rect(),QColor(127,127,127,127));
    painter.end();
    child->setPixmap(tempPixmap);
    setAcceptDrops(true);
//        QLabel *label = new QLabel(this);
//        label->setPixmap(tempPixmap);
//       label->resize(tempPixmap.size());
    //第六步，执行拖动操作
    if(drag->exec(Qt::CopyAction | Qt::MoveAction,Qt::CopyAction) == Qt::MoveAction)
        child->close();
    else
    {
        child->show();
        child->setPixmap(pixmap);
    }

}



//放下label
void Level1::drop(QString boxstr, QDropEvent *event){
    QByteArray itemData = event->mimeData()->data(boxstr);
    QDataStream dataStream(&itemData,QIODevice::ReadOnly);
    QPixmap pixmap;
    QPoint offset;
    dataStream>>pixmap>>offset; //使用数据流将字节数据读到QPixmap，QPoint变量中
    //新建标签，为其添加图片，并根据图片大小设置标签大小
    QLabel *newLabel = new QLabel(this);
//                    QWidget *widget = new QWidget;
    newLabel->setPixmap(pixmap);
    newLabel->resize(pixmap.size());

//是图片移动到放下的位置，不设置会默认显示在（0，0）
    ui->tableView->setIndexWidget(model->index(tableindex,0),newLabel);

    event->setDropAction(Qt::MoveAction);
    event->accept();
    tableindex++;

}


//设置tableview
void Level1::settable()
{
//     qDebug() << QObject::sender()->objectName();
     model = new QStandardItemModel();
     model->setColumnCount(1);
     model->setRowCount(30);

     //利用setModel()方法将数据模型与QTableView绑定
     ui->tableView->setModel(model);
     //设置表头1-30
     for(int i=0;i++;i<30){
         QStandardItem *standItem1 = new QStandardItem(tr("%1").arg(i+1));

         model->setItem(i,0,standItem1);                                //表格第i行，第0列添加一项内容
         model->item(i,0)->setTextAlignment(Qt::AlignCenter);           //设置表格内容居中

     }

//     ui->tableView->horizontalHeader()->setSectionsMovable(true);
//     ui->tableView->horizontalHeader()->moveSection(1,2);

         ui->tableView->setColumnWidth(0,230);

}












//开始运行
void Level1::on_startButton_clicked()
{
    //临时储存inboxline的数据
    temp=inboxline;
    //手中是否有数字
    hand=0;

    for(int i=0;i<30;i++){
        if(box[i]==500){
           QString num=lineedit[lineeditnum-1]->text();
           box[i]+=num.toInt();
        }
    }

    if(nowlevel==1){
    //i为代码标签序号
    for(int i=0;box[i]!=0;i++){

        //inbox标签
        if(box[i]==1){

            if(inboxsignal[nowbox]==0&&hand==0){
            //将inbox中的数字移出

                inboxsignal[nowbox]=1;
                inboxline[nowbox]=31;
                hand=1;

                label[nowbox]->setGeometry(207,312,27,27);

                continue;
            }else{
            //出错
                QMessageBox::information(this, tr("error"),
                                         tr("inbox运行错误"));
                init();
                break;
            }
        }


        //outbox标签
        if(box[i]==2){
            //j为处理的数字的序号

                if(inboxsignal[nowbox]==1&&hand==1){
                //将inbox中的数字移出
                    outboxline[nowbox]=temp[nowbox];
                    hand=0;

                    setxy(ui->girllabel->x(),ui->girllabel->y());
                    setxy1(459,276);
                    timer->start(10);

                }else{
                //出错
                    QMessageBox::information(this, tr("error"),
                                             tr("outbox运行错误"));
                    init();
                    break;
                }
                continue;

        }
        //copyto标签
        if(box[i]==3){
            if(inboxsignal[nowbox]==1&&hand==1){
            //将inbox中的数字移出
                outboxline[nowbox]=temp[nowbox];
                hand=0;

                setxy1(274,368);
                timer->start(10);
//                    if(x==x1){
//                        qDebug()<<"stop";
// //                       timer->stop();
//                        label[j]->setGeometry(554,336,27,27);
//                        inboxsignal[j]=2;
//                        nowbox++;

//                    }
                nowbox++;
                break;

            }else{
            //出错
                QMessageBox::information(this, tr("error"),
                                         tr("copyto运行错误"));
                init();
                break;
            }

            //copyfrom
            if(box[i]==4){
                if(hand==0){

                }else{
                    QMessageBox::information(this, tr("error"),
                                             tr("copyfrom运行错误"));
                }
            }


        }

    }
    }

    if(nowlevel==2){
        if(box[0]==1&&box[1]==2&&box[2]==501){

            setxy(ui->girllabel->x(),ui->girllabel->y());
            setxy1(459,276);
            timer2->start(15);

        }else{
            QMessageBox::information(this, tr("error"),
                                     tr("运行错误"));
        }
    }

    if(nowlevel==3){
        if(box[0]==3&&box[1]==2&&box[2]==3&&box[3]==2&&box[4]==3&&box[5]==2){
            QMessageBox::information(this, tr("Level3"),
                                     tr("success"));
            this->close();
            Level1 level4(0,4);
            level4.show();
        }else if(box[0]==3&&box[1]==2&&box[2]==501){
            QMessageBox::information(this, tr("Level3"),
                                     tr("success"));
            this->close();
            Level1 level4(0,4);
            level4.show();
        }
        else{
            QMessageBox::information(this, tr("error"),
                                     tr("运行错误"));
            label[0]->setText(" B");
            label[1]->setText(" U");
            label[2]->setText(" G");
            label[0]->setGeometry(272,368,27,27);
            label[1]->setGeometry(329,368,27,27);
            label[2]->setGeometry(389,368,27,27);
        }
    }

    if(nowlevel==4){
        if(box[0]==1&&box[1]==3&&box[2]==1&&box[3]==2&&box[4]==3&&box[5]==2&&box[5]==501){
            QMessageBox::information(this, tr("Level4"),
                                     tr("success"));
            this->close();
        }else{
            QMessageBox::information(this, tr("error"),
                                     tr("运行错误"));
        }
    }
}

void Level1::update(){

    ui->girllabel->setGeometry(x,y,68,72);

    //令在途中的box随girl移动
    label[nowbox]->setGeometry(x+66,312,27,27);

    if(x<x1){
        x=x+1;
    }else if(x>x1){
        x=x-1;
    }else{

        label[nowbox]->setGeometry(554,336,27,27);
        inboxsignal[nowbox]=2;
        nowbox++;
        isSuccess();

        //到达指定位置后，停止计时器
        timer->stop();


    }
}

void Level1::update2(){

    ui->girllabel->setGeometry(x,y,68,72);

    //令在途中的box随girl移动
    label[nowbox]->setGeometry(x+66,312,27,27);

    if(x<x1){
        x=x+1;
    }else if(x>x1){
        x=x-1;
    }else{

        label[nowbox]->setGeometry(554,336,27,27);
        inboxsignal[nowbox]=2;
        nowbox++;
//        isSuccess();
        ui->girllabel->setGeometry(151,276,68,72);
        setxy(ui->girllabel->x(),ui->girllabel->y());
        setxy1(459,276);
        timer3->start(15);

        //到达指定位置后，停止计时器
        timer2->stop();
    }
}

void Level1::update3(){

    ui->girllabel->setGeometry(x,y,68,72);

    //令在途中的box随girl移动
    label[1]->setGeometry(x+66,312,27,27);

    if(x<x1){
        x=x+1;
    }else if(x>x1){
        x=x-1;
    }else{
        label[1]->setGeometry(554,374,27,27);
        inboxsignal[1]=2;
        nowbox++;

        ui->girllabel->setGeometry(151,276,68,72);
        setxy(ui->girllabel->x(),ui->girllabel->y());
        setxy1(459,276);

        timer4->start(15);
        //到达指定位置后，停止计时器
        timer3->stop();
    }
}

void Level1::update4(){

    ui->girllabel->setGeometry(x,y,68,72);

    //令在途中的box随girl移动
    label[2]->setGeometry(x+66,312,27,27);

    if(x<x1){
        x=x+1;
    }else if(x>x1){
        x=x-1;
    }else{
        label[2]->setGeometry(554,412,27,27);
        inboxsignal[2]=2;
        nowbox++;

        QMessageBox::information(this, tr("Level2"),
                                 tr("success"));
        this->close();
        Level1 level3(0,3);
        level3.show();


        //到达指定位置后，停止计时器
        timer4->stop();
    }
}

//初始化及出错处理
void Level1::init(){
    //恢复box为0
    for(int i=0;i<30;i++){
        box[i]=0;
    }

    //inboxline重新随机生成
    for(int i=0;i<6;i++){
        inboxline[i]=qrand()%30;
        label[i]->setText(QString::number(inboxline[i],10));

        label[i]->setGeometry(96,336+38*i,27,27);
    }

    ui->girllabel->setGeometry(151,276,68,72);

    //输出不可能为31,所以将31作为未改变的初始值
    for(int i=0;i<6;i++){
        outboxline[i]=31;
    }
    //0表示box在inbox序列
    for(int i=0;i<6;i++){
        inboxsignal[i]=0;
    }

    setxy(151,276);


}

//停止运行
void Level1::on_stopButton_clicked()
{
    timer->stop();
    init();
}
//设置起始坐标
void Level1::setxy(int tempx,int tempy){
    x=tempx;
    y=tempy;
}
//设置结束坐标
void Level1::setxy1(int tempx,int tempy){
    x1=tempx;
    y1=tempy;
}

//清空标签区域
void Level1::on_clearButton_clicked()
{
    qDebug()<<"clear";
    model->removeColumns(0,model->columnCount());
    settable();
    //标签序列清空
    for(int i=0;i<30;i++){
        box[i]=0;
    }
    tableindex=0;
    init();

}

//删除一行标签
void Level1::on_clearButton_2_clicked()
{

     int row=ui->tableView->currentIndex().row();
     model->removeRow(row);
     model->setRowCount(30);

     tableindex--;
     box[tableindex]=0;

     //该行标签不存在,之后的标签依次向前移一位
     for(int i=row;i<tableindex;i++){
         box[i]=box[i+1];
     }

     for(int i=0;i<10;i++){
         qDebug()<<box[i];
     }
     init();

}

void Level1::on_backButton_clicked()
{
    this->close();
}

//判断是否成功
void Level1::isSuccess(){

    qDebug()<<"judge";
    if(nowlevel==1){
        //表示相同的数字的个数
        int count=0;
        for(int i=0;i<6;i++){
            if(outboxline[i]==temp[i]){
                count++;
            }
            qDebug()<<count;
        }

        //成功，进入下一关
        if(count==1){
            QMessageBox::information(this, tr("Level1"),
                                     tr("success"));
            this->close();
            Level1 level2(0,2);
            level2.show();
        }
    }else if(nowlevel==2){
        //表示相同的数字的个数
        int count=0;
        for(int i=0;i++;i<6){
            if(outboxline[i]==temp[i]){
                count++;
            }
        }
        //成功，进入下一关
        if(count==6){
            QMessageBox::information(this, tr("Level2"),
                                     tr("success"));
            this->close();
            Level1 level3(0,3);
            level3.show();
        }
    }else if(nowlevel==3){
        if(outboxline[0]==temp[0]){
            QMessageBox::information(this, tr("Level3"),
                                     tr("success"));
            this->close();
            Level1 level4(0,4);
            level4.show();
        }
    }else if(nowlevel==4){
        QMessageBox::information(this, tr("Level4"),
                                 tr("success"));
        this->close();
    }

}

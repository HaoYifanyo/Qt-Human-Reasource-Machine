#include "level1.h"
#include "ui_level1.h"
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

Level1::Level1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Level1)
{
    ui->setupUi(this);
    //存放“代码”，用数字表示相应内容，0为空
    box=new int[30];
    //inbox和outbox序列
    inboxline=new int[6];
    for(int i=0;i<6;i++){
        inboxline[i]=qrand()%30;
    }

    outboxline=new int[6];
    for(int i=0;i<6;i++){
        outboxline[i]=31;
    }
    //用于标识box的位置,0表示在inbox序列,1表示在途中,2表示在outbox序列
    inboxsignal=new int[6];
    for(int i=0;i<6;i++){
        inboxsignal[i]=0;
    }

    QPixmap bgpix;
    QPixmap bg2pix;
    QPixmap startpix;

    bgpix.load(":/level/bg.jpg");
    bg2pix.load(":/level/bg2.png");
    startpix.load(":/level/start.jpg");

//    inboxpix = &(inboxpix->scaled(inboxpix->width()*0.652,inboxpix->height()*0.652,Qt::IgnoreAspectRatio));

//    bg1pix = bg1pix->scaled(bg1pix->width()*2.0,bg1pix.height()*6.5,Qt::IgnoreAspectRatio);
    bgpix = bgpix.scaled(bgpix.width()*0.9167,bgpix.height()*0.9167,Qt::IgnoreAspectRatio);
    bg2pix = bg2pix.scaled(bg2pix.width()*20,bg2pix.height()*100,Qt::IgnoreAspectRatio);
    startpix = startpix.scaled(startpix.width()*0.75,startpix.height()*0.75,Qt::IgnoreAspectRatio);
//    ui->inboxlabel->setPixmap(inboxpix);
//    ui->bg1label->setPixmap(bg1pix);
    ui->label->setPixmap(bgpix);
    ui->bg2label->setPixmap(bg2pix);
    ui->startlabel->setPixmap(startpix);


//    connect(ui->verticalScrollBar, SIGNAL(valueChanged(int)), ui->bg3label, setterSlot);
//    connect(ui->bg3label, changedSignal, ui->verticalScrollBar, SLOT(setValue(int)));



}

Level1::~Level1()
{
    delete ui;
}

void Level1::mousePressEvent(QMouseEvent *event)        //鼠标按下事件
{
//    qDebug() <<event->pos();
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
//    if(event->button() == Qt::LeftButton)
//    {
//        //第一步，获取图片。
////        QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
//        if(!child->inherits("QLabel"))
//                    return;
//        QPixmap pixmap = *child->pixmap();

//        //第二步，自定义MIME类型
//        QByteArray itemData;
//        QDataStream dataStream(&itemData,QIODevice::WriteOnly);
//        //将图片信息，位置信息保存到字节数组中
//        dataStream<<pixmap<<QPoint(event->pos() - child->pos());
//        //第三步，将数据放入QMimeData中
//        QMimeData *mimeData = new QMimeData;
//        mimeData->setData("myImage/jpg",itemData);
//        //第四步，将QMimelda中的数据放进QDrag
//        QDrag *drag = new QDrag(this);
//        drag->setMimeData(mimeData);
//        drag->setPixmap(pixmap);
//        drag->setHotSpot(event->pos() - child->pos());
//        //第五步，给原图加阴影
//        QPixmap tempPixmap = pixmap;
//        QPainter painter;               //绘图
//        painter.begin(&tempPixmap);
//        //添加透明淡黑色阴影
//        painter.fillRect(pixmap.rect(),QColor(127,127,127,127));
//        painter.end();
//        child->setPixmap(tempPixmap);
//        setAcceptDrops(true);
////        QLabel *label = new QLabel(this);
////        label->setPixmap(tempPixmap);
// //       label->resize(tempPixmap.size());
//        //第六步，执行拖动操作
//        if(drag->exec(Qt::CopyAction | Qt::MoveAction,Qt::CopyAction) == Qt::MoveAction)
//            child->close();
//        else
//        {
//            child->show();
//            child->setPixmap(pixmap);
//        }
//    }
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
    qDebug()<<event->pos();

//    if(event->mimeData()->hasFormat("myImage/jpg"))
//    {

        //若在可放置区域
        if(event->pos().x()>817&&event->pos().x()<1091&&event->pos().y()>425){
            //判断当前放下的label是哪种类型
            int n=0;
            if(event->mimeData()->hasFormat("inbox/jpg")){
                n=1;
            }else if(event->mimeData()->hasFormat("outbox/jpg")){
                n=2;
            }else if(event->mimeData()->hasFormat("copyfrom/jpg")){
                n=3;
            }else if(event->mimeData()->hasFormat("copyto/jpg")){
                n=4;
            }else if(event->mimeData()->hasFormat("jump/jpg")){
                n=5;
            }


            for(int i=0;i<30;i++){
                if(box[i]==0){
                    box[i]=n;
//                    qDebug()<<n;
                    if(event->mimeData()->hasFormat("inbox/jpg")){
                        drop("inbox/jpg",event);
                        break;
                    }else if(event->mimeData()->hasFormat("outbox/jpg")){
                        drop("outbox/jpg",event);
                        break;
                    }else if(event->mimeData()->hasFormat("copyfrom/jpg")){
                        drop("copyfrom/jpg",event);
                        break;
                    }else if(event->mimeData()->hasFormat("copyto/jpg")){
                        drop("copyto/jpg",event);
                        break;
                    }else if(event->mimeData()->hasFormat("jump/jpg")){
                        drop("jump/jpg",event);
                        break;
                    }

                }
            }
        }


//    }
//    else
//        event->ignore();
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
    newLabel->move(event->pos() - offset);
    newLabel->show();
    newLabel->setAttribute(Qt::WA_DeleteOnClose);
//                    ui->scrollArea->setWidget(widget);
//                    ui->tableView

    event->setDropAction(Qt::MoveAction);
    event->accept();

}

void Level1::on_pushButton_clicked()
{
     qDebug() << QObject::sender()->objectName();
     QStandardItemModel *model = new QStandardItemModel();
//     for(int i=0;i<30;i++)
         model->setVerticalHeaderItem(0, new QStandardItem(QObject::tr("1")));
         model->setVerticalHeaderItem(1, new QStandardItem(QObject::tr("2")));
         model->setVerticalHeaderItem(2, new QStandardItem(QObject::tr("3")));
         model->setVerticalHeaderItem(3, new QStandardItem(QObject::tr("4")));
         model->setVerticalHeaderItem(4, new QStandardItem(QObject::tr("5")));
//         model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("1")));



         //利用setModel()方法将数据模型与QTableView绑定
         ui->tableView->setModel(model);
         ui->tableView->setColumnWidth(0,100);
//     m_labeldelegate = new LabelDelegate(this);

//     ui->tableView->setItemDelegate(m_labeldelegate);
 //    ui->tableView->setItemDelegateForLine(0, m_labeldelegate);

}

//void Level1::paint(QPainter * painter,
//                           const QStyleOptionViewItem & option,
//                           const QModelIndex & index) const
//{
//    if(index.column()!=0){
//        QItemDelegate::paint(painter,option,index);
//        return;
//    }
//    const QAbstractItemModel * model=index.model();
//    QVariant var=model->data(index,Qt::CheckStateRole);
//    if(var.isNull()) var=false;
//    const QPixmap & star=var.toBool()?
//favouritePixmap:notFavouritePixmap;

//    int width=star.width();
//    int height=star.height();
//    QRect rect=option.rect;
//    int x=rect.x()+rect.width()/2-width/2;
//    int y=rect.y()+rect.height()/2-height/2;

//    painter->drawPixmap(x,y,star);
//}


//QByteArray itemData = event->mimeData()->data("inbox/jpg");
//QDataStream dataStream(&itemData,QIODevice::ReadOnly);
//QPixmap pixmap;
//QPoint offset;
//dataStream>>pixmap>>offset; //使用数据流将字节数据读到QPixmap，QPoint变量中
////新建标签，为其添加图片，并根据图片大小设置标签大小

//QLabel *newLabel = new QLabel(this);
//ui->scrollArea->setWidget(newLabel);
//newLabel->setPixmap(pixmap);
//newLabel->resize(pixmap.size());

////是图片移动到放下的位置，不设置会默认显示在（0，0）
//newLabel->move(event->pos() - offset);
//newLabel->show();
//newLabel->setAttribute(Qt::WA_DeleteOnClose);
//event->setDropAction(Qt::MoveAction);
//event->accept();

//开始运行
void Level1::on_startButton_clicked()
{
    int *temp;
    temp=inboxline;
    //手中是否有数字
    int hand=0;
    //i为代码标签序号
    for(int i=0;i!=0;i++){
        //inbox标签
        if(box[i]==1){
            //j为处理的数字的序号
            for(int j=0;j<6;j++){

                if(inboxsignal[j]==0&&hand==0){
                //将inbox中的数字移出
                    inboxsignal[j]=1;
                    inboxline[i]=31;
                    hand=1;

                }else{
                //出错
                }
            }
        }

        //outbox标签
        if(box[i]==2){
            //j为处理的数字的序号
            for(int j=0;j<6;j++){

                if(inboxsignal[j]==1&&hand==1){
                //将inbox中的数字移出
                    inboxsignal[j]=2;
                    outboxline[j]=temp[j];
                    hand=0;

                }else{
                //出错
                }
            }
        }
    }
}
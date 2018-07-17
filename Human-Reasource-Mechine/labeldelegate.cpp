#include "labeldelegate.h"
#include <QLabel>

int FILE_OPERATE_COLUMN = 0;//按键所在列

LabelDelegate::LabelDelegate(QObject *parent) :
QItemDelegate(parent)
{}

void LabelDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    QLabel* label = m_label.value(index);//在特定的索引处绘制按键，这个变量临时存储绘制的按键信息

    //如果为按键列绘制按键

    if (index.column() == FILE_OPERATE_COLUMN) {

        //非常重要！该条件最好为判断索引与需要代理的列！因为这样绘制的按键会随滑动条进行重绘！

        label = new QLabel();//绘制存button的参数的对象

//        label->rect = option.rect.adjusted(1, 1, -1, -1);//绘制尺寸



//        button->state |= QStyle::State_Enabled;

        (const_cast<LabelDelegate *>(this))->m_label.insert(index, label);//将绘制的按键放入Qmap
    }

    painter->save();

    if (option.state & QStyle::State_Selected) {

        painter->fillRect(option.rect, option.palette.highlight());
    }

    painter->restore();

//    QApplication::style()->drawControl(QStyle::CE_Label, label, painter);
}

//事件选择过滤
//bool LabelDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
//{

//    if (event->type() == QEvent::MouseButtonPress) {

//        qDebug()<<"--------";

//        QMouseEvent* e =(QMouseEvent*)event;

//        //确定鼠标点击的位置在画的按键中

//        if (option.rect.adjusted(1, 1, -1, -1).contains(e->x(), e->y()) && m_btns.contains(index)) {

//            m_btns.value(index)->state |= QStyle::State_Sunken;

//        }
//    }

//    if (event->type() == QEvent::MouseButtonRelease) {

//        qDebug()<<"++++++++";

//        QMouseEvent* e =(QMouseEvent*)event;
//// if (option.rect.adjusted(1, 1, -1, -1).contains(e->x(), e->y()) && m_btns.contains(index)) {
//// m_btns.value(index)->state &= (~QStyle::State_Sunken);

//// QDialog *d = new QDialog();
//// d->setGeometry(0, 0, 100, 100);
//// d->move(QApplication::desktop()->screenGeometry().center() - d->rect().center());
//// d->show();
//// }
//}
//}

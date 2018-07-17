#ifndef LABELDELEGATE_H
#define LABELDELEGATE_H

#include <QApplication>
#include <QMouseEvent>
#include <QDialog>
#include <QPainter>
#include <QStyleOption>
#include <QDesktopWidget>
#include <QDebug>
#include <QMap>
#include <QItemDelegate>
#include <QLabel>

class LabelDelegate: public QItemDelegate
{

    Q_OBJECT
public:

    explicit LabelDelegate(QObject *parent = 0);

    //重写绘图事件

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    //重写事件过滤

//    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

    private:
    QMap<QModelIndex, QLabel*> m_label;
};

#endif // LABELDELEGATE_H



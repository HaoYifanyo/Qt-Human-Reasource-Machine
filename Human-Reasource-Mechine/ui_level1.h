/********************************************************************************
** Form generated from reading UI file 'level1.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVEL1_H
#define UI_LEVEL1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Level1
{
public:
    QLabel *bg1label;
    QLabel *inboxlabel;
    QLabel *outboxlabel;
    QLabel *jumplabel;
    QPushButton *pushButton;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *bg2label;
    QTableView *tableView;
    QPushButton *startButton;
    QPushButton *startButton_2;
    QLabel *startlabel;

    void setupUi(QWidget *Level1)
    {
        if (Level1->objectName().isEmpty())
            Level1->setObjectName(QStringLiteral("Level1"));
        Level1->resize(1100, 697);
        bg1label = new QLabel(Level1);
        bg1label->setObjectName(QStringLiteral("bg1label"));
        bg1label->setGeometry(QRect(673, 31, 122, 461));
        inboxlabel = new QLabel(Level1);
        inboxlabel->setObjectName(QStringLiteral("inboxlabel"));
        inboxlabel->setGeometry(QRect(698, 131, 73, 34));
        outboxlabel = new QLabel(Level1);
        outboxlabel->setObjectName(QStringLiteral("outboxlabel"));
        outboxlabel->setGeometry(QRect(673, 91, 122, 51));
        jumplabel = new QLabel(Level1);
        jumplabel->setObjectName(QStringLiteral("jumplabel"));
        jumplabel->setGeometry(QRect(680, 100, 122, 51));
        pushButton = new QPushButton(Level1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 220, 75, 23));
        label = new QLabel(Level1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1100, 697));
        scrollArea = new QScrollArea(Level1);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(817, 425, 271, 270));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 269, 268));
        bg2label = new QLabel(scrollAreaWidgetContents);
        bg2label->setObjectName(QStringLiteral("bg2label"));
        bg2label->setGeometry(QRect(0, -1, 261, 1001));
        tableView = new QTableView(scrollAreaWidgetContents);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 0, 271, 271));
        tableView->setSizeIncrement(QSize(5, 1));
        scrollArea->setWidget(scrollAreaWidgetContents);
        startButton = new QPushButton(Level1);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(350, 570, 75, 101));
        startButton->setStyleSheet(QStringLiteral("background: transparent;"));
        startButton->setFlat(true);
        startButton_2 = new QPushButton(Level1);
        startButton_2->setObjectName(QStringLiteral("startButton_2"));
        startButton_2->setGeometry(QRect(10, 610, 75, 71));
        startButton_2->setStyleSheet(QStringLiteral("background: transparent;"));
        startButton_2->setFlat(true);
        startlabel = new QLabel(Level1);
        startlabel->setObjectName(QStringLiteral("startlabel"));
        startlabel->setGeometry(QRect(200, 570, 400, 150));
        startlabel->raise();
        label->raise();
        pushButton->raise();
        bg1label->raise();
        outboxlabel->raise();
        jumplabel->raise();
        inboxlabel->raise();
        scrollArea->raise();
        startButton->raise();
        startButton_2->raise();

        retranslateUi(Level1);

        QMetaObject::connectSlotsByName(Level1);
    } // setupUi

    void retranslateUi(QWidget *Level1)
    {
        Level1->setWindowTitle(QApplication::translate("Level1", "Form", Q_NULLPTR));
        bg1label->setText(QString());
        inboxlabel->setText(QString());
        outboxlabel->setText(QString());
        jumplabel->setText(QString());
        pushButton->setText(QApplication::translate("Level1", "run", Q_NULLPTR));
        label->setText(QString());
        bg2label->setText(QApplication::translate("Level1", "TextLabelfdsfdfdsfsds  dsfdfdfdfdfdcvdfd", Q_NULLPTR));
        startButton->setText(QApplication::translate("Level1", "Start", Q_NULLPTR));
        startButton_2->setText(QApplication::translate("Level1", "back", Q_NULLPTR));
        startlabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Level1: public Ui_Level1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVEL1_H

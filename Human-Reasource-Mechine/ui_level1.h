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
    QLabel *bglabel;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *bg2label;
    QTableView *tableView;
    QPushButton *startButton;
    QPushButton *backButton;
    QLabel *startlabel;
    QLabel *girllabel;
    QPushButton *stopButton;
    QLabel *label;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

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
        bglabel = new QLabel(Level1);
        bglabel->setObjectName(QStringLiteral("bglabel"));
        bglabel->setGeometry(QRect(0, 20, 1100, 697));
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
        startButton->setGeometry(QRect(363, 606, 68, 68));
        startButton->setStyleSheet(QStringLiteral("background: transparent;"));
        startButton->setFlat(true);
        backButton = new QPushButton(Level1);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(10, 610, 75, 71));
        backButton->setStyleSheet(QStringLiteral("background: transparent;"));
        backButton->setFlat(true);
        startlabel = new QLabel(Level1);
        startlabel->setObjectName(QStringLiteral("startlabel"));
        startlabel->setGeometry(QRect(200, 570, 521, 150));
        girllabel = new QLabel(Level1);
        girllabel->setObjectName(QStringLiteral("girllabel"));
        girllabel->setGeometry(QRect(180, 200, 68, 72));
        stopButton = new QPushButton(Level1);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(219, 619, 65, 65));
        stopButton->setStyleSheet(QStringLiteral("background: transparent;"));
        stopButton->setFlat(true);
        label = new QLabel(Level1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(96, 356, 27, 27));
        label->setStyleSheet(QLatin1String("background:rgb(163, 203, 89);\n"
"font: 87 12pt \"Arial Black\";\n"
"color: rgb(75, 98, 52);"));
        label_1 = new QLabel(Level1);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(96, 392, 27, 27));
        label_1->setStyleSheet(QLatin1String("background:rgb(163, 203, 89);\n"
"font: 87 12pt \"Arial Black\";\n"
"color: rgb(75, 98, 52);"));
        label_2 = new QLabel(Level1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(96, 432, 27, 27));
        label_2->setStyleSheet(QLatin1String("background:rgb(163, 203, 89);\n"
"font: 87 12pt \"Arial Black\";\n"
"color: rgb(75, 98, 52);"));
        label_3 = new QLabel(Level1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(96, 470, 27, 27));
        label_3->setStyleSheet(QLatin1String("background:rgb(163, 203, 89);\n"
"font: 87 12pt \"Arial Black\";\n"
"color: rgb(75, 98, 52);"));
        label_4 = new QLabel(Level1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(96, 510, 27, 27));
        label_4->setStyleSheet(QLatin1String("background:rgb(163, 203, 89);\n"
"font: 87 12pt \"Arial Black\";\n"
"color: rgb(75, 98, 52);"));
        label_5 = new QLabel(Level1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(96, 545, 27, 27));
        label_5->setStyleSheet(QLatin1String("background:rgb(163, 203, 89);\n"
"font: 87 12pt \"Arial Black\";\n"
"color: rgb(75, 98, 52);"));
        bglabel->raise();
        startlabel->raise();
        pushButton->raise();
        bg1label->raise();
        outboxlabel->raise();
        jumplabel->raise();
        inboxlabel->raise();
        scrollArea->raise();
        startButton->raise();
        backButton->raise();
        stopButton->raise();
        girllabel->raise();
        label->raise();
        label_1->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();

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
        bglabel->setText(QString());
        bg2label->setText(QApplication::translate("Level1", "TextLabelfdsfdfdsfsds  dsfdfdfdfdfdcvdfd", Q_NULLPTR));
        startButton->setText(QApplication::translate("Level1", "Start", Q_NULLPTR));
        backButton->setText(QApplication::translate("Level1", "back", Q_NULLPTR));
        startlabel->setText(QString());
        girllabel->setText(QString());
        stopButton->setText(QApplication::translate("Level1", "stop", Q_NULLPTR));
        label->setText(QApplication::translate("Level1", " 1", Q_NULLPTR));
        label_1->setText(QApplication::translate("Level1", " 1", Q_NULLPTR));
        label_2->setText(QApplication::translate("Level1", " 1", Q_NULLPTR));
        label_3->setText(QApplication::translate("Level1", " 1", Q_NULLPTR));
        label_4->setText(QApplication::translate("Level1", " 1", Q_NULLPTR));
        label_5->setText(QApplication::translate("Level1", " 1", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Level1: public Ui_Level1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVEL1_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *levellabel;
    QPushButton *backButton;
    QPushButton *level1Button;
    QPushButton *level2Button;
    QPushButton *level3Button;
    QPushButton *level4Button;
    QPushButton *level4Button_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1090, 570);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        levellabel = new QLabel(centralwidget);
        levellabel->setObjectName(QStringLiteral("levellabel"));
        levellabel->setGeometry(QRect(0, 0, 1090, 570));
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(0, 460, 81, 61));
        backButton->setStyleSheet(QStringLiteral("background:transparent"));
        backButton->setFlat(true);
        level1Button = new QPushButton(centralwidget);
        level1Button->setObjectName(QStringLiteral("level1Button"));
        level1Button->setGeometry(QRect(400, 440, 111, 101));
        level1Button->setStyleSheet(QStringLiteral("background:transparent"));
        level1Button->setFlat(true);
        level2Button = new QPushButton(centralwidget);
        level2Button->setObjectName(QStringLiteral("level2Button"));
        level2Button->setGeometry(QRect(400, 340, 111, 91));
        level2Button->setStyleSheet(QStringLiteral("background:transparent"));
        level2Button->setFlat(true);
        level3Button = new QPushButton(centralwidget);
        level3Button->setObjectName(QStringLiteral("level3Button"));
        level3Button->setGeometry(QRect(400, 240, 111, 91));
        level3Button->setStyleSheet(QStringLiteral("background:transparent"));
        level3Button->setFlat(true);
        level4Button = new QPushButton(centralwidget);
        level4Button->setObjectName(QStringLiteral("level4Button"));
        level4Button->setGeometry(QRect(400, 140, 111, 91));
        level4Button->setStyleSheet(QStringLiteral("background:transparent"));
        level4Button->setFlat(true);
        level4Button_2 = new QPushButton(centralwidget);
        level4Button_2->setObjectName(QStringLiteral("level4Button_2"));
        level4Button_2->setGeometry(QRect(1010, 340, 81, 61));
        level4Button_2->setStyleSheet(QStringLiteral("background:transparent"));
        level4Button_2->setFlat(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1090, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        levellabel->setText(QString());
        backButton->setText(QApplication::translate("MainWindow", "a", Q_NULLPTR));
        level1Button->setText(QApplication::translate("MainWindow", "a", Q_NULLPTR));
        level2Button->setText(QApplication::translate("MainWindow", "a", Q_NULLPTR));
        level3Button->setText(QApplication::translate("MainWindow", "a", Q_NULLPTR));
        level4Button->setText(QApplication::translate("MainWindow", "a", Q_NULLPTR));
        level4Button_2->setText(QApplication::translate("MainWindow", "a", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'level2.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVEL2_H
#define UI_LEVEL2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Level2
{
public:

    void setupUi(QWidget *Level2)
    {
        if (Level2->objectName().isEmpty())
            Level2->setObjectName(QStringLiteral("Level2"));
        Level2->resize(400, 300);

        retranslateUi(Level2);

        QMetaObject::connectSlotsByName(Level2);
    } // setupUi

    void retranslateUi(QWidget *Level2)
    {
        Level2->setWindowTitle(QApplication::translate("Level2", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Level2: public Ui_Level2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVEL2_H

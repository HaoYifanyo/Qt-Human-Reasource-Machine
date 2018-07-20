/********************************************************************************
** Form generated from reading UI file 'level.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVEL_H
#define UI_LEVEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Level
{
public:

    void setupUi(QWidget *Level)
    {
        if (Level->objectName().isEmpty())
            Level->setObjectName(QStringLiteral("Level"));
        Level->resize(400, 300);

        retranslateUi(Level);

        QMetaObject::connectSlotsByName(Level);
    } // setupUi

    void retranslateUi(QWidget *Level)
    {
        Level->setWindowTitle(QApplication::translate("Level", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Level: public Ui_Level {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVEL_H

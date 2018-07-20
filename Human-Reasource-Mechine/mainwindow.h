#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "level1.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   static Level1 *level;


private slots:
    void back();

    void on_backlabel_linkActivated(const QString &link);

    void on_backButton_clicked();

    void on_level1Button_clicked();

    void on_level2Button_clicked();

    void on_level3Button_clicked();

    void on_level4Button_clicked();

    void on_level2Button_pressed();

private:
    Ui::MainWindow *ui;
    Level1 *level1;


};

#endif // MAINWINDOW_H

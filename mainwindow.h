#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <wiringPi.h>
#include <QTimer>

#define trig_1 8
#define echo_1 9


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();
    void timerupdate();


private:
    Ui::MainWindow *ui;
    QTimer *timer1;

public:
    bool ledbool;
    long getUltrasonic(int trig, int echo);

};

#endif // MAINWINDOW_H

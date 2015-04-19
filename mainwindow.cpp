#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ledbool=true;
    digitalWrite(8, LOW);

    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(timerupdate()));
    //timer->start(100);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::timerupdate(){
    long distance = getUltrasonic(trig_1, echo_1);
    if(distance>300) distance=300;

    ui->progressBar->setValue((int)distance);


}

void MainWindow::on_pushButton_clicked()
{

    if(timer1->isActive())
    {
        timer1->stop();
    }else
    {
        timer1->start(100);
    }

}

long MainWindow::getUltrasonic(int trig, int echo)
{
    long distance;

    digitalWrite(trig, HIGH);
    delayMicroseconds(20);
    digitalWrite(trig, LOW);

    while(digitalRead(echo) == LOW);
    long startTime = micros();
    while(digitalRead(echo) == HIGH);
    long travelTime=micros()-startTime;

    distance = travelTime/58.2;
    return distance;
}

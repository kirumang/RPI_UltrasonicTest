#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    

    wiringPiSetup();
    pinMode(8,OUTPUT);
    pinMode(trig_1, OUTPUT);
    pinMode(echo_1, INPUT);

    return a.exec();
}

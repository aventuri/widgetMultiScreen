#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>
#include <QThread>
#include "mainwindow.h"

/*
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // http://doc.qt.io/qt-5/mainwindow.html
}
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w1;
    MainWindow w2;
    QDesktopWidget *widget = QApplication::desktop();
    qDebug() << "Number of screens:" << widget->screenCount();
    for (int i = 0; i < widget->screenCount(); i++) {
        qDebug() << "Geometry:" << widget->screenGeometry(i);
    }
    // Get geometry of Secondary screen
    QRect rect = widget->screenGeometry(1);
    //qDebug() << "Move to:" << rect.width() << ":" << rect.y();
    qDebug() << "Move to:" << rect.x() << ":" << rect.y();
    w1.setStyleSheet("QMainWindow {background: 'yellow';}");
    w1.show();
    QThread::msleep(3000);
    //Move w2 to Secondary Screen
    w2.move(rect.width(), rect.y());
    w2.setStyleSheet("QMainWindow {background: 'red';}");
    w2.show();
    return a.exec();

}


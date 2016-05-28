#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>
#include <QPainter>
#include <QDebug>
#define uchar unsigned char
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
     QUdpSocket *server;

     QHostAddress client;//存储客户端IP
     quint16 clientPort;//端口

     //void paintEvent(QPaintEvent *);

     int reTran(char *buf1,char *buf2,int buf1_size);



private slots:
    void processPendingDatagram();

    void on_photopushButton_clicked();

    void on_connectpushButton_clicked();

    void on_clearDatapushButton_clicked();

    void on_clearphotopushButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

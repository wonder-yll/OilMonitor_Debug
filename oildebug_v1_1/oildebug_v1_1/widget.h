#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>
#include <QTime>
#include <QDebug>


typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned short int  usint;

typedef struct Message{
    uchar buf[1200];
    uint len;
}Msg;

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    QUdpSocket *udpClient;
    QHostAddress server;    //IP
    quint16 serverPort;     //端口

    int transferr_func(uchar *from,uchar *to,int fromSize);
    int reTran(char *buf1,char *buf2,int buf1_size);
    char sen_cmd(Msg *msg,usint messgae_id,uchar para);
    uchar check_byte(uchar *buf,int size);

    void set_pre(int num,char type,char addr);
    void set_flow(int num,char type,char addr);
    void set_blo(int num,char type,char addr);

    void get_pre(int num,uchar *type,uchar *addr);
    void get_flow(int num,uchar *type,uchar *addr);
    void get_blo(int num,uchar *type,uchar *addr);


private slots:
    void on_connectpushButton_clicked();

    void readMessage();//处理服务器发送的数据

    /*处理客户端出错信息*/
    void displayError(QAbstractSocket::SocketError);

    void on_readPushButton_clicked();

    void on_modiPushButton_clicked();

    void on_confPushButton_clicked();

    void on_funComboBox_activated(const QString &arg1);


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

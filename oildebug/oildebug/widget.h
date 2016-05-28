#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>
#include <QTime>
#include <QDebug>
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

    QHostAddress server;//存储客户端IP
    quint16 serverPort;//端口


     int reTran(char *buf1,char *buf2,int buf1_size);

private slots:
    void on_connectpushButton_clicked();

    void readMessage();//处理服务器发送的数据
    //处理客户端出错信息
    void displayError(QAbstractSocket::SocketError);

    void on_readPushButton_clicked();

    void on_modiPushButton_clicked();

    void on_confPushButton_clicked();

    void on_funComboBox_activated(const QString &arg1);


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

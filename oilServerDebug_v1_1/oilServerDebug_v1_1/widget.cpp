#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*初始化,客户端IP和端口*/
   client=QHostAddress("0.0.0.0");
   clientPort=0;



    //为设置QLabel自动缩放，既：显示图像大小自动调整为Qlabel大小。
    ui->picturelabel->setScaledContents(true);
   // ui->picturelabel->setPixmap(QPixmap("3.png"));

    /*新建一个UDP socket*/
    server = new QUdpSocket(this);

    ui->clearDatapushButton->setEnabled(false);
    ui->clearphotopushButton->setEnabled(false);
    ui->photopushButton->setEnabled(false);
    ui->clientIPlineEdit->setEnabled(false);
    ui->clientComlineEdit->setEnabled(false);

}

Widget::~Widget()
{
    delete ui;
}


/*有数据到来*/
void Widget::processPendingDatagram() //处理等待的数据报
{
    QByteArray datagram; //拥于存放接收的数据报
    QByteArray recBuf;
    int realPacLen,pacNum,realPac;
    static int pacNumTemp=99;
    int i;
    static int photoLen,photoLenTemp=0;

    unsigned short int hostId;

    while( server->hasPendingDatagrams() ) //拥有等待的数据报
    {
        //让 datagram 的大小为等待处理的数据报的大小,这样才能接收到完整的数据
        datagram.resize(server->pendingDatagramSize());
        recBuf.resize(server->pendingDatagramSize());

        //读取数据
        server->readDatagram(datagram.data(),datagram.size(),&client,&clientPort);

        //qDebug()<<"data coming"<<datagram.data();
        //显示客户端IP和端口
        ui->clientIPlineEdit->setText(client.toString());
        ui->clientComlineEdit->setText(tr("%1").arg(clientPort));

        //反转义
        reTran(datagram.data(),recBuf.data(),datagram.size());

        hostId=(unsigned short int)recBuf.data()[1];
        hostId=((unsigned short int)recBuf.data()[2])|(hostId<<8);

        unsigned char datatemp,warnFlag,preNum,flowNum;
        float voltage,pressure;
        double flow;

        if(hostId == 0x0002){ //心跳包

            char datagram[] = {0x7e,/*消息ID*/0x00,0x02,/*消息体属性*/0x00,0x00,/*消息体长度*/0x00,0x00,\
                               /*设备厂商和设备ID：0004005000*/0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
                               0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0,/*流水线ID*/0x00,0x00,\
                               /*校验位*/0x02,0x7e};

            server->writeDatagram(datagram,sizeof(datagram)-1,client,clientPort);

        }else if(hostId == 0x0200){ //生产数据

            ui->textBrowser->append(tr("\n********开接收数据********"));
            /*将recBuf绑定到输入流in中*/
            QDataStream in(&recBuf,QIODevice::ReadOnly);
            for(i=0;i<26;i++){  //处理消息头
                in >> datatemp;
            }

            in>>warnFlag;//报警信息
            ui->textBrowser->append(tr("报警信息 %1").arg(warnFlag));
            //in>>voltage;//电压信息

            memcpy(&voltage,&recBuf.data()[27],4);
            ui->textBrowser->append(tr("电压值: %1").arg(voltage));

            preNum=recBuf.data()[36];//压力表个数
            ui->textBrowser->append(tr("压力表个数: %1").arg(preNum));
            for(i=0;i<preNum;i++){
                memcpy(&pressure,&recBuf.data()[38+5*i],4);
                ui->textBrowser->append(tr("压力表数据: %1").arg(pressure));
            }//for

            flowNum=recBuf.data()[38+5*preNum];//流量计个数
            ui->textBrowser->append(tr("流量计个数: %1").arg(flowNum));

            //memcpy(&pressure,&recBuf.data()[38+5*preNum+2],4);
            //pressure=pressure/1000;
            //ui->textBrowser->append(tr("压力数据: %1").arg(pressure));

            for(i=0;i<flowNum;i++){

                ui->textBrowser->append(tr("第%1个流量计:").arg(i+1));
                memcpy(&pressure,&recBuf.data()[38+5*preNum+2+25*i],4);
                pressure=pressure/1000;
                ui->textBrowser->append(tr("压力数据: %1").arg(pressure));

                memcpy(&pressure,&recBuf.data()[38+5*preNum+6+25*i],4);
                ui->textBrowser->append(tr("温度数据: %1").arg(pressure));

                memcpy(&pressure,&recBuf.data()[38+5*preNum+10+25*i],4);
                ui->textBrowser->append(tr("瞬时流量数据: %1").arg(pressure));

                memcpy(&pressure,&recBuf.data()[38+5*preNum+14+25*i],4);
                ui->textBrowser->append(tr("工况流量数据: %1").arg(pressure));

                memcpy(&flow,&recBuf.data()[38+5*preNum+18+25*i],8);
                ui->textBrowser->append(tr("总流量数据: %1").arg(flow));

            }//for


            valveNum=recBuf.data()[38+5*preNum+25*flowNum+1+1];//截断阀个数
            ui->textBrowser->append(tr("截断阀个数: %1").arg(valveNum));

            for(i=0;i<valveNum;i++){
                ui->textBrowser->append(tr("第%1个截断阀状态:%L2").arg( i+1).arg((int)recBuf.data()[38+5*preNum+25*flowNum+1+2+2*i]) );
                //ui->textBrowser->append(tr("%1").arg((int)recBuf.data()[38+5*preNum+25*flowNum+1+2+2*i]));
            }
            ui->textBrowser->append(tr("********数据接收完毕********\n"));

        }else if(hostId == 0x0805){ //拍照应答

            photoLen=(unsigned char)recBuf.data()[31] | ((unsigned char)recBuf.data()[30]<<8);

            ui->picturetextBrowser->append(tr("拍照成功,照片长度为: %1").arg(photoLen));


        }else if(hostId == 0x0801){//数据上传命令
            pacNum=(unsigned char)recBuf.data()[28]|((unsigned char)recBuf.data()[27]<<8);
            realPacLen=(unsigned char)recBuf.data()[38]|((unsigned char)recBuf.data()[37]<<8);
            realPac=(unsigned char)recBuf.data()[26]|((unsigned char)recBuf.data()[25]<<8);

            if(pacNum!=pacNumTemp || (pacNum==0 && photoLen != photoLenTemp) ){ //两次包号不同,才接受
                photoLenTemp = photoLen;//存储照片数据长度
                pacNumTemp=pacNum;
                 QFile file( "temp.jpg" );
                //QTextStream stream( &file);
                if(pacNum==0){
                    ui->picturetextBrowser->append(tr("\n*********开始接收照片********"));

                    ui->picturetextBrowser->append(tr("照片总包个数为: %1").arg(realPac));

                    if(file.open(QIODevice::WriteOnly)){ //若是第0个包,就覆盖之前的文件
                        //for(i=0;i<realPacLen;i++)
                            //stream << recBuf.data()[39+i];
                        file.write(&(recBuf.data()[39]),realPacLen);
                    }
                }else{
                    if(file.open(QIODevice::WriteOnly|QIODevice::Append)){ //追加写入方式打开
                        //for(i=0;i<realPacLen;i++)
                        //stream << recBuf.data()[39+i];
                        file.write(&(recBuf.data()[39]),realPacLen);
                    }
                }

                ui->picturetextBrowser->append(tr("开始接收第%1个包:").arg(pacNum));

                ui->picturetextBrowser->append(tr("包数据大小: %1").arg(realPacLen));
                file.close();

                if(pacNum == realPac-1){//传送完毕就显示图片
                    ui->picturetextBrowser->append(tr("*********照片接收完毕********\n"));
                    ui->picturelabel->setPixmap(QPixmap("temp.jpg"));

                }
            }//if(pacNum!=pacNumTemp || (pacNum==0 && photoLen != photoLenTemp) )

        }//if(hostId == 0x0002)

    }//while( server->hasPendingDatagrams() )


}

/*
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("3.png");
    painter.drawPixmap(0,0,100,100,pix);
}
*/

void Widget::on_photopushButton_clicked()
{
    if(clientPort != 0){
        char datagram[] = {0x7e,0x81,0x05,0x00,0x00,0x00,0x28,0x1d,0xb6,0xd0,0x4d,0x24,0xa2,0x2a,0x59,0xef,0x14,0xfb,0x96,0xed,0x6b,0xff,0xc5,0x00,0x03,0x14,0x52,0x7e};
        server->writeDatagram(datagram,sizeof(datagram)-1,client,clientPort);
        ui->picturetextBrowser->append(tr("拍照命令已发送!"));
    }else{
        ui->picturetextBrowser->append(tr("没有客户端连接,不能发送拍照命令!"));
    }

}





void Widget::on_connectpushButton_clicked()
{
    if(ui->connectpushButton->text()==tr("连接")){
        ui->connectpushButton->setText(tr("断开"));

        ui->clearDatapushButton->setEnabled(true);
        ui->clearphotopushButton->setEnabled(true);
        ui->photopushButton->setEnabled(true);
        ui->IPlineEdit->setEnabled(false);
        ui->COMlineEdit->setEnabled(false);

        /*绑定监听端口*/
        server->bind(QHostAddress(ui->IPlineEdit->text()),ui->COMlineEdit->text().toInt());
        /*绑定socket信号，有数据到来就执行槽*/
        connect(server,SIGNAL(readyRead()),this,SLOT(processPendingDatagram()));
        ui->textBrowser->append(tr("开始监听"));
    }else{
        ui->connectpushButton->setText(tr("连接"));

        ui->clearDatapushButton->setEnabled(false);
        ui->clearphotopushButton->setEnabled(false);
        ui->photopushButton->setEnabled(false);
        ui->IPlineEdit->setEnabled(true);
        ui->COMlineEdit->setEnabled(true);

        server->close(); //关闭监听
        disconnect(server,SIGNAL(readyRead()),this,SLOT(processPendingDatagram()));
        ui->textBrowser->append(tr("断开连接"));
    }
}

void Widget::on_clearDatapushButton_clicked()
{
    ui->textBrowser->setText(tr(""));
}

void Widget::on_clearphotopushButton_clicked()
{
    ui->picturetextBrowser->setText(tr(""));
    ui->picturelabel->setPixmap(QPixmap("null.jpg"));
}



/*反转义函数*/
int Widget::reTran(char *buf1,char *buf2,int buf1_size)
{
    int i;
    int j=0;
    for(i=0;i<buf1_size;i++){
        if(buf1[i]==0x7d){
            switch (buf1[i+1]){
                case 0x01 :
                    buf2[j]=0x7d;
                    j++;
                    i++;
                    break;
                case 0x02 :
                    buf2[j]=0x7e;
                    j++;
                    i++;
                    break;
                }
            }
        else{
            buf2[j]=buf1[i];
            j++;
            }
        }
    return j;
}
